#include "CMS_lumi.C"

void plotLimits() {
    double mass[7] = {6, 9, 11, 14, 16, 30, 90};
    double obs[7];
    double expm2[7];
    double expm1[7];
    double exp0[7];
    double expp1[7];
    double expp2[7];

    obs[0]   = 42.8837*10.;
    expm2[0] = 8.1816*10.;
    expm1[0] = 11.5455*10.;
    exp0[0]   = 17.7500*10.;
    expp1[0] = 28.5043*10.;
    expp2[0] = 45.2196*10.;


    obs[1]   =4.3850*10.;
    expm2[1] =3.5376*10.;
    expm1[1] =5.0625*10.;
    exp0[1]   =7.8750*10.;
    expp1[1] =12.8346*10.;
    expp2[1] =20.7346*10.;


    obs[2]   =3.0888*10.;
    expm2[2] =3.0198*10.;
    expm1[2] =4.3422*10.;
    exp0[2]   =6.7812*10.;
    expp1[2] =11.2142*10.;
    expp2[2] =18.2691*10.;


    obs[3]   =2.6780*10.;
    expm2[3] =1.9892*10.;
    expm1[3] =2.9114*10.;
    exp0[3]   =4.6719*10.;
    expp1[3] =7.9122*10.;
    expp2[3] =13.0755*10.;


    obs[4]   =3.3603*10.;
    expm2[4] =1.6611*10.;
    expm1[4] =2.4436*10.;
    exp0[4]   =3.9375*10.;
    expp1[4] =6.6998*10.;
    expp2[4] =11.1906*10.;


    obs[5]   =1.8959*10.;
    expm2[5] =0.9728*10.;
    expm1[5] =1.4791*10.;
    exp0[5]   =2.5156*10.;
    expp1[5] =4.5412*10.;
    expp2[5] =7.6254*10.;


    obs[6]   =1.8399*10.;
    expm2[6] =0.9426*10.;
    expm1[6] =1.4331*10.;
    exp0[6]   =2.4375*10.;
    expp1[6] =4.4001*10.;
    expp2[6] =7.3886*10.;

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
   c1->SetTickx(0);
   c1->SetTicky(0);
   gStyle->SetOptStat(0);
   gStyle->SetOptFit(0);
   
    g95->Draw("A3");
    g68->Draw("3");
    gexp->Draw("L");
    gobs->Draw("L");

    TLegend *tleg = new TLegend(0.6,0.6,0.8,0.8);
    tleg->SetBorderSize(0);
    tleg->AddEntry(gobs,"Observed","L");
    tleg->AddEntry(gexp,"Expected","L");
    tleg->AddEntry(g68,"68\% expected","F");
    tleg->AddEntry(g95,"95\% expected","F");
    tleg->Draw();
    
    CMS_lumi( c1, 104, 33,lumi_PbPb2015 );
}
