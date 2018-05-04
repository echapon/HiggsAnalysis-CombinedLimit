#include "TFile.h"
#include "TF1.h"
#include "TH1.h"
#include <iostream>

using namespace std;

void prepareInputs_axion(int imass) {
   TFile *f = TFile::Open("input_hinvmass.root","UPDATE");
   TH1F *h = new TH1F(Form("axion%d",imass),"",6,5,20);

   // arrays
   double mass[7] = {6, 9, 11, 14, 16, 30, 90};
   double acc[7] = {0.763764, 0.895896, 0.873874, 0.895896, 0.916917, 0.967968, 0.996997};

   // functions for resolution
   TF1 *fm = new TF1("fm","[0]+[1]*exp([2]*x)",5,20);
   fm->SetParameters(9.24958e-01,6.17813e-01,-3.47891e-01);
   TF1 *fr = new TF1("fr","[0]+[1]*exp([2]*x)",5,20);
   fr->SetParameters(0.0909661,-0.207283,-0.307946);


   // function for efficiency
   TF1 fe("f","[0]*(1-exp((x-[1])/[2]))",0,30);
   fe.SetParameters(3.32406e-01,4.28904e+00,-2.64850e+00);
   // binned efficiencies for syst
   double x[8],y[8];
   x[0]=5.5; y[0]=0.105285;
   x[1]=6.5; y[1]=0.203834;
   x[2]=7.5; y[2]=0.241597;
   x[3]=9; y[3]=0.271701;
   x[4]=11; y[4]=0.288428;
   x[5]=13.5; y[5]=0.317935;
   x[6]=17.5; y[6]=0.366667;
   x[7]=25; y[7]=0.309735;
   TGraph g(8,x,y);

   double xsec = 10e-3; // mub
   double lumi = 370.884;  // mub-1
   int nevts = 1e6;
   double sf = 1.12/1.09;

   TF1 *fgaus = new TF1("fgaus","gaus",0,200);
   fgaus->SetParameters(1, mass[imass]*fm->Eval(mass[imass]), mass[imass]*fr->Eval(mass[imass]));
   // h->FillRandom("fgaus",nevts);
   for (int i=0; i<nevts; i++) {
      double m = fgaus->GetRandom();
      if (m<5) m=5;
      h->Fill(m);
   }
   h->Scale(xsec*lumi*acc[imass]*fe.Eval(mass[imass])/nevts);

   cout << mass[imass] << ": " << h->Integral(1,6) << endl;;
   cout << "syst eff: " << (fe.Eval(mass[imass])-g.Eval(mass[imass]))/fe.Eval(mass[imass]) << endl;

   f->Write();
   f->Close();
}

void prepareInputs_axion() {
   for (int i=0; i<7; i++) prepareInputs_axion(i);
}
