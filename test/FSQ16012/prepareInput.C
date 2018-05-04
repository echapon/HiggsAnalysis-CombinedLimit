#include "TFile.h"
#include "TH1D.h"

void prepareInput(const char* filename, const char* varname) {
   TFile *fin = TFile::Open(filename);

   TH1D *hdata = (TH1D*) fin->Get(Form("%s_data",varname))->Clone("data_obs");
   TH1D *hlbyl = (TH1D*) fin->Get(Form("%s_lbyl",varname))->Clone("lbyl");
   TH1D *hcep = (TH1D*) fin->Get(Form("%s_cep",varname))->Clone("cep");
   TH1D *hqed = (TH1D*) fin->Get(Form("%s_qed",varname))->Clone("qed");
   double factor = 370.884/391.; // correct the lumi
   double factorx = 1.12/1.09; // 138./123.; // correct the xsec // but now the correct xsec is used already, but need to account for trigger SF
   hlbyl->Scale(factor*factorx);
   hcep->Scale(factor);
   hqed->Scale(factor);
   TFile *fout = new TFile(Form("input_%s.root",varname),"RECREATE");
   hdata->Write();
   hlbyl->Write();
   hcep->Write();
   hqed->Write();

   cout << "data: " << hdata->Integral(1,hdata->GetNbinsX()) << endl;
   cout << "lbyl: " << hlbyl->Integral(1,hlbyl->GetNbinsX()) << endl;
   cout << "cep: " << hcep->Integral(1,hcep->GetNbinsX()) << endl;
   cout << "qed: " << hqed->Integral(1,hqed->GetNbinsX()) << endl;

   // // let's implement Barlow-Beeston by hand
   // double norm_lbl = hlbyl->Integral()/hlbyl->GetEntries();
   // double norm_cep = hcep->Integral()/hcep->GetEntries();
   // double norm_qed = hqed->Integral()/hqed->GetEntries();

   // const double alpha = 1 - 0.6827;;
   // for (int i=1; i<=hlbyl->GetNbinsX(); i++) {
   //    double ntot=0, etot=0;
   //    
   //    int binc = hlbyl->GetBinContent(i)/norm_lbl;
   //    ntot += binc;
   //    double bincup = ROOT::Math::gamma_quantile_c(alpha/2,binc+1,1.);
   //    double bincdown = (binc==0) ? 0  : (ROOT::Math::gamma_quantile(alpha/2,binc,1.));
   //    etot += (bincup-bincdown)/2.;
   //    if (ntot>0) cout << "mcsigstats_bin" << i << "  lnN  " << 1.+etot/ntot << "    -     -   signal MC stats bin " << i << endl;

   //    ntot=0;
   //    etot=0;

   //    binc = hcep->GetBinContent(i)/norm_cep;
   //    ntot += binc;
   //    bincup = ROOT::Math::gamma_quantile_c(alpha/2,binc+1,1.);
   //    bincdown = (binc==0) ? 0  : (ROOT::Math::gamma_quantile(alpha/2,binc,1.));
   //    etot += (bincup-bincdown)/2.;

   //    binc = hqed->GetBinContent(i)/norm_qed;
   //    ntot += binc;
   //    bincup = ROOT::Math::gamma_quantile_c(alpha/2,binc+1,1.);
   //    bincdown = (binc==0) ? 0  : (ROOT::Math::gamma_quantile(alpha/2,binc,1.));
   //    etot += (bincup-bincdown)/2.;
   //    cout << "mcstats_bin" << i << "  lnN  -    " << 1.+etot/ntot << "   " << 1.+etot/ntot << "   bkg MC stats bin " << i << endl;
   // }

   fout->Close();
   fin->Close();
}
