#include "TFile.h"
#include "TF1.h"
#include "TH1.h"
#include <iostream>

using namespace std;

void prepareInputs_axion(int imass) {
   TFile *f = TFile::Open("input_hinvmass.root","UPDATE");
   TH1F *h = new TH1F(Form("axion%d",imass),"",8,0,20);

   // arrays
   double mass[6] = {6, 11, 14, 16, 30, 90};
   double eff[6] = {0.146523, 0.306750, 0.334480, 0.343131, 0.353650, 0.353818};
   double acc[6] = {0.763764, 0.873874, 0.895896, 0.916917, 0.967968, 0.996997};
   double resm[6] = {0.9893, 0.9575, 0.9372, 0.9286, 0.9442, 0.9269};
   double ress[6] = {0.06092, 0.07542, 0.0891, 0.0846, 0.08925, 0.09091};

   double xsec = 10e-3; // mub
   double lumi = 370.884;  // mub-1
   int nevts = 1e6;
   double sf = 1.12/1.09;

   TF1 *fgaus = new TF1("fgaus","gaus",0,200);
   fgaus->SetParameters(1,mass[imass]*resm[imass],mass[imass]*ress[imass]);
   // h->FillRandom("fgaus",nevts);
   for (int i=0; i<nevts; i++) {
      double m = fgaus->GetRandom();
      if (m<5) m=5;
      h->Fill(m);
   }
   h->Scale(xsec*lumi*acc[imass]*eff[imass]/nevts);
   for (int i=0; i<3; i++) {h->SetBinContent(i,0); h->SetBinError(i,0);}

   cout << mass[imass] << ": " << h->Integral(1,8) << endl;;

   f->Write();
   f->Close();
}

void prepareInputs_axion() {
   for (int i=0; i<6; i++) prepareInputs_axion(i);
}
