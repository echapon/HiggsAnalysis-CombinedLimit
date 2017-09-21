#include "RooWorkspace.h"
#include "RooGaussian.h"
#include "RooAbsPdf.h"
#include "RooProdPdf.h"
#include "RooDataSet.h"
#include "RooRealVar.h"
#include "TFile.h"
#include "RooStats/ProfileLikelihoodCalculator.h"
#include "RooStats/HypoTestResult.h"

#include <iostream>

using namespace RooFit;
using namespace RooStats;
using namespace std;

int nCPU = 4;
double initialGuess = 47.;

// systs
double ebval = 0.595;
double eberr = 0.0595;
double jsferr = 0.034;
double f_smjj_err = 0.02;
double acc_e_val = 0.056;
double acc_e_err = 0.0014;
double acc_mu_val = 0.06;
double acc_mu_err = 0.0016;
double eff_e_val = 0.623;
double eff_e_err = 0.0249;
double eff_mu_val = 0.915;
double eff_mu_err = 0.0366;
double lumi_val = 174.5;
double lumi_err = 8.725;

void computeSignificance_PFLHC(const char *filename="combine_workspace_wmodel0_0_20170706_norateparams.root") {
   TFile *f = TFile::Open(filename);
   RooWorkspace *w = (RooWorkspace*) f->Get("w");

   w->factory("PROD::pdf_bine1l4j2b_constr(pdf_bine1l4j2b, eb_Pdf, jsf_Pdf, acc_e_Pdf, acc_mu_Pdf, eff_e_Pdf, eff_mu_Pdf, lumi_Pdf, Nqcd_e1l4j2b_Pdf, Nqcd_e1l4j2q_Pdf, Nqcd_e1l4j1b1q_Pdf, Nqcd_mu1l4j2b_Pdf, Nqcd_mu1l4j2q_Pdf, Nqcd_mu1l4j1b1q_Pdf)");
   w->factory("PROD::pdf_bine1l4j1b1q_constr(pdf_bine1l4j1b1q, eb_Pdf, jsf_Pdf, acc_e_Pdf, acc_mu_Pdf, eff_e_Pdf, eff_mu_Pdf, lumi_Pdf, Nqcd_e1l4j2b_Pdf, Nqcd_e1l4j2q_Pdf, Nqcd_e1l4j1b1q_Pdf, Nqcd_mu1l4j2b_Pdf, Nqcd_mu1l4j2q_Pdf, Nqcd_mu1l4j1b1q_Pdf)");
   w->factory("PROD::pdf_bine1l4j2q_constr(pdf_bine1l4j2q, eb_Pdf, jsf_Pdf, acc_e_Pdf, acc_mu_Pdf, eff_e_Pdf, eff_mu_Pdf, lumi_Pdf, Nqcd_e1l4j2b_Pdf, Nqcd_e1l4j2q_Pdf, Nqcd_e1l4j1b1q_Pdf, Nqcd_mu1l4j2b_Pdf, Nqcd_mu1l4j2q_Pdf, Nqcd_mu1l4j1b1q_Pdf)");
   w->factory("PROD::pdf_binmu1l4j2b_constr(pdf_binmu1l4j2b, eb_Pdf, jsf_Pdf, acc_e_Pdf, acc_mu_Pdf, eff_e_Pdf, eff_mu_Pdf, lumi_Pdf, Nqcd_e1l4j2b_Pdf, Nqcd_e1l4j2q_Pdf, Nqcd_e1l4j1b1q_Pdf, Nqcd_mu1l4j2b_Pdf, Nqcd_mu1l4j2q_Pdf, Nqcd_mu1l4j1b1q_Pdf)");
   w->factory("PROD::pdf_binmu1l4j1b1q_constr(pdf_binmu1l4j1b1q, eb_Pdf, jsf_Pdf, acc_e_Pdf, acc_mu_Pdf, eff_e_Pdf, eff_mu_Pdf, lumi_Pdf, Nqcd_e1l4j2b_Pdf, Nqcd_e1l4j2q_Pdf, Nqcd_e1l4j1b1q_Pdf, Nqcd_mu1l4j2b_Pdf, Nqcd_mu1l4j2q_Pdf, Nqcd_mu1l4j1b1q_Pdf)");
   w->factory("PROD::pdf_binmu1l4j2q_constr(pdf_binmu1l4j2q, eb_Pdf, jsf_Pdf, acc_e_Pdf, acc_mu_Pdf, eff_e_Pdf, eff_mu_Pdf, lumi_Pdf, Nqcd_e1l4j2b_Pdf, Nqcd_e1l4j2q_Pdf, Nqcd_e1l4j1b1q_Pdf, Nqcd_mu1l4j2b_Pdf, Nqcd_mu1l4j2q_Pdf, Nqcd_mu1l4j1b1q_Pdf)");
   w->factory("PROD::model_combined_mjj_constr2(model_combined_mjj, eb_Pdf, jsf_Pdf, acc_e_Pdf, acc_mu_Pdf, eff_e_Pdf, eff_mu_Pdf, lumi_Pdf, Nqcd_e1l4j2b_Pdf, Nqcd_e1l4j2q_Pdf, Nqcd_e1l4j1b1q_Pdf, Nqcd_mu1l4j2b_Pdf, Nqcd_mu1l4j2q_Pdf, Nqcd_mu1l4j1b1q_Pdf)");
   w->factory("SIMUL::model_combined_mjj_constr(sample, e1l4j2b=pdf_bine1l4j2b_constr, e1l4j1b1q=pdf_bine1l4j1b1q_constr, e1l4j2q=pdf_bine1l4j2q_constr, mu1l4j2b=pdf_binmu1l4j2b_constr, mu1l4j1b1q=pdf_binmu1l4j1b1q_constr, mu1l4j2q=pdf_binmu1l4j2q_constr)");
   
   // RooAbsPdf *modelc = w->pdf("model_s");
   RooAbsPdf *modelc = w->pdf("model_combined_mjj_constr");

   RooDataSet *data = (RooDataSet*) w->data("data_obs");
   RooRealVar *thePoi = (RooRealVar*) w->var("xsec");

   RooFitResult *rr = modelc->fitTo(*data,NumCPU(nCPU),Minos(RooArgSet(*thePoi)),Extended(kTRUE),Strategy(2),Save()); // add minos

   // now to the profile likelihood calculator
   ProfileLikelihoodCalculator pl2(*data,*modelc,RooArgSet(*thePoi));
   RooArgSet nuis("nuisance");
   nuis.add(*w->var("Nbkg_e1l4j1b1q"));
   nuis.add(*w->var("Nbkg_e1l4j2b"));
   nuis.add(*w->var("Nbkg_e1l4j2q"));
   nuis.add(*w->var("Nbkg_mu1l4j1b1q"));
   nuis.add(*w->var("Nbkg_mu1l4j2b"));
   nuis.add(*w->var("Nbkg_mu1l4j2q"));
   if (w->var("acc_e")) {
      nuis.add(*w->var("acc_e"));
      nuis.add(*w->var("acc_mu"));
   } else {
      nuis.add(*w->var("acc"));
   }
   nuis.add(*w->var("eb"));
   nuis.add(*w->var("eff_e"));
   nuis.add(*w->var("eff_mu"));
   nuis.add(*w->var("fqcd_e1l4j1b1q"));
   nuis.add(*w->var("fqcd_e1l4j2b"));
   nuis.add(*w->var("fqcd_e1l4j2q"));
   nuis.add(*w->var("fqcd_mu1l4j1b1q"));
   nuis.add(*w->var("fqcd_mu1l4j2b"));
   nuis.add(*w->var("fqcd_mu1l4j2q"));
   nuis.add(*w->var("jsf"));
   nuis.add(*w->var("lumi"));
   nuis.add(*w->var("mpv_wmjj_1l4j1b1q"));
   nuis.add(*w->var("mpv_wmjj_1l4j2b"));
   nuis.add(*w->var("mpv_wmjj_1l4j2q"));
   nuis.add(*w->var("width_wmjj_1l4j1b1q"));
   nuis.add(*w->var("width_wmjj_1l4j2b"));
   nuis.add(*w->var("width_wmjj_1l4j2q"));
   pl2.SetNuisanceParameters(nuis);

   RooArgSet *nullpars = new RooArgSet(*thePoi);
   nullpars->setRealValue("xsec",0);
   pl2.SetNullParameters(*nullpars);
   RooArgSet *altpars = new RooArgSet(*thePoi);
   pl2.SetAlternateParameters(*altpars);

   HypoTestResult *r = pl2.GetHypoTest();
   r->Print();

   cout << "Nsig for electrons:" << w->function("Nsig_e")->getVal() << " and for muons: " << w->function("Nsig_mu")->getVal() << endl;

   cout << "Best fit results:" << endl;
   rr->Print("v");

   //  //Get the interval
   // w->loadSnapshot("altpars");

   // // this doesn't work... gives a weird shape with a second minimum at ~64
   // LikelihoodInterval* plInt = pl2.GetInterval();
   // plInt->SetConfidenceLevel(0.682);
   // cout << "PLC interval is [" << plInt->LowerLimit(*thePoi) << ", " << 
   //    plInt->UpperLimit(*thePoi) << "]" << endl;

   // TCanvas dataCanvas("dataCanvas");

   // LikelihoodIntervalPlot plotInt((LikelihoodInterval*)plInt);
   // plotInt.SetTitle("Profile Likelihood Ratio");
   // plotInt.SetRange(0,100);
   // plotInt.SetMaximum(3.);
   // w->loadSnapshot("altpars");
   // plotInt.Draw();
   // dataCanvas.SaveAs("interval.pdf");
   // dataCanvas.SaveAs("interval.root");

   // // do the scan by hand
   // RooAbsReal *nll = modelc->createNLL(*data,Extended(kTRUE),NumCPU(nCPU));

   // double x[20],nllval[20];
   // for (int i=0; i<20; i++) {
   //    x[i] = 50+i;
   //    thePoi->setVal(x[i]);
   //    thePoi->setConstant(kTRUE);
   //    RooMinuit *minuit = new RooMinuit(*nll);
   //    minuit->migrad();
   //    minuit->minos(*thePoi);
   //    nllval[i] = nll->getVal();
   // }
   // thePoi->setConstant(kFALSE);

   // for (int i=0; i<20; i++) {
   //    cout << x[i] << " " << nllval[i] << endl;
   // }
}
