#include "CMS_lumi.C"

void plotLimits_20180528() {
    double mass[7] = {6, 9, 11, 14, 16, 30, 90};
    double obs[7];
    double expm2[7];
    double expm1[7];
    double exp0[7];
    double expp1[7];
    double expp2[7];

    obs[0]   = 34.8182*10.;
    expm2[0] = 6.7124*10.;
    expm1[0] = 9.4722*10.;
    exp0[0]   = 14.5625*10.;
    expp1[0] = 23.3856*10.;
    expp2[0] = 36.9359*10.;


    obs[1]   = 3.2282*10.;
    expm2[1] = 2.7612*10.;
    expm1[1] = 3.9328*10.;
    exp0[1]   = 6.0938*10.;
    expp1[1] = 9.8830*10.;
    expp2[1] = 15.8955*10.;


    obs[2]   = 2.2265*10.;
    expm2[2] = 1.7500*10.;
    expm1[2] = 2.5234*10.;
    exp0[2]   = 4.0000*10.;
    expp1[2] = 6.7105*10.;
    expp2[2] = 11.0558*10.;


    obs[3]   = 1.8508*10.;
    expm2[3] = 1.1087*10.;
    expm1[3] = 1.6443*10.;
    exp0[3]   = 2.7031*10.;
    expp1[3] = 4.7072*10.;
    expp2[3] = 7.9728*10.;


    obs[4]   = 2.7601*10.;
    expm2[4] = 0.9276*10.;
    expm1[4] = 1.3981*10.;
    exp0[4]   = 2.3281*10.;
    expp1[4] = 4.1284*10.;
    expp2[4] = 7.0564*10.;


    obs[5]   = 1.4217*10.;
    expm2[5] = 0.6938*10.;
    expm1[5] = 1.0609*10.;
    exp0[5]   = 1.8125*10.;
    expp1[5] = 3.2574*10.;
    expp2[5] = 5.4939*10.;


    obs[6]   = 1.6305*10.;
    expm2[6] = 0.7925*10.;
    expm1[6] = 1.2118*10.;
    exp0[6]   = 2.0703*10.;
    expp1[6] = 3.7373*10.;
    expp2[6] = 6.2755*10.;

    double exph1[7], exph2[7], expl1[7], expl2[7], dm[7];
    for (int i=0; i<7; i++) {
       dm[i] = 0;
       expl2[i] = fabs(exp0[i]-expm2[i]);
       expl1[i] = fabs(exp0[i]-expm1[i]);
       exph2[i] = fabs(exp0[i]-expp2[i]);
       exph1[i] = fabs(exp0[i]-expp1[i]);
    }

    TGraph *gobs = new TGraph(7,mass,obs);
    TGraph *gexp = new TGraph(7,mass,exp0);
    TGraphAsymmErrors *g68 = new TGraphAsymmErrors(7,mass,exp0,dm,dm,expl1,exph1);
    TGraphAsymmErrors *g95 = new TGraphAsymmErrors(7,mass,exp0,dm,dm,expl2,exph2);

    g95->SetFillColor(kYellow+1);
    g68->SetFillColor(kGreen+1);
    gexp->SetLineStyle(2);

    int W = 700;
   int H = 600;

   float T = 0.08;
   float B = 0.14;
   float L = 0.14;
   float R = 0.04;


   TCanvas* c1 = new TCanvas("c1","Limits",50,50,W,H);
   c1->SetFillColor(0);
   c1->SetBorderMode(0);
   c1->SetFrameFillStyle(0);
   c1->SetFrameBorderMode(0);
   c1->SetLeftMargin( L );
   c1->SetRightMargin( R );
   c1->SetTopMargin( T );
   c1->SetBottomMargin( B );
   // c1->SetTickx(0);
   // c1->SetTicky(0);
   c1->SetLogx();
   c1->SetLogy();
   gStyle->SetOptStat(0);
   gStyle->SetOptFit(0);
   
    g95->Draw("A3");
    g68->Draw("3");
    gexp->Draw("L");
    gobs->Draw("L");

    // axes
    g95->GetHistogram()->GetXaxis()->SetTitle("m_{a} [GeV]");
    g95->GetHistogram()->GetYaxis()->SetTitle("95\% CL upp. lim. on #sigma(#gamma#gamma #rightarrow a #rightarrow #gamma#gamma) ]nb]");
    c1->RedrawAxis();

    TLegend *tleg = new TLegend(0.49,0.6,0.8,0.87);
    tleg->SetBorderSize(0);
    tleg->AddEntry(gobs,"Observed","L");
    tleg->AddEntry(gexp,"Expected","L");
    tleg->AddEntry(g68,"68\% expected","F");
    tleg->AddEntry(g95,"95\% expected","F");
    tleg->Draw();
    
    CMS_lumi( c1, 104, 33,lumi_PbPb2015 );
}
