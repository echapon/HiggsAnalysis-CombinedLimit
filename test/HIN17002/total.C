void total()
{
//=========Macro generated from canvas: total/total
//=========  (Thu Sep  7 22:21:06 2017) by ROOT version6.02/05
   TCanvas *total = new TCanvas("total", "total",0,0,700,600);
   gStyle->SetOptFit(1);
   gStyle->SetOptStat(0);
   gStyle->SetOptTitle(0);
   total->SetHighLightColor(2);
   total->Range(0,0,1,1);
   total->SetFillColor(0);
   total->SetBorderMode(0);
   total->SetBorderSize(0);
   total->SetLeftMargin(0.1114286);
   total->SetRightMargin(0.03428571);
   total->SetTopMargin(0.06);
   total->SetBottomMargin(0.12);
   total->SetFrameFillStyle(0);
   total->SetFrameBorderMode(0);
  
// ------------>Primitives in pad: pad
   TPad *pad = new TPad("pad", "pad",0,0,1,1);
   pad->Draw();
   pad->cd();
   pad->Range(20.54956,-1.170732,74.48937,8.585366);
   pad->SetFillColor(0);
   pad->SetBorderMode(0);
   pad->SetBorderSize(0);
   pad->SetLeftMargin(0.1114286);
   pad->SetRightMargin(0.03428571);
   pad->SetTopMargin(0.06);
   pad->SetBottomMargin(0.12);
   pad->SetFrameFillStyle(0);
   pad->SetFrameBorderMode(0);
   pad->SetFrameFillStyle(0);
   pad->SetFrameBorderMode(0);
   
   Double_t total_fx1[50] = {
   30.4,
   31.2,
   32,
   32.8,
   33.6,
   34.4,
   35.2,
   36,
   36.8,
   37.6,
   38.4,
   39.2,
   40,
   40.8,
   41.6,
   42.4,
   43.2,
   44,
   44.8,
   45.27517,
   45.6,
   46.4,
   47.2,
   48,
   48.8,
   49.6,
   50.4,
   51.2,
   52,
   52.8,
   53.6,
   54.4,
   55.2,
   56,
   56.8,
   57.6,
   58.4,
   59.2,
   60,
   60.8,
   61.6,
   62.4,
   63.2,
   64,
   64.8,
   65.6,
   66.4,
   67.2,
   68,
   68.8};
   Double_t total_fy1[50] = {
   4.935491,
   4.40535,
   3.905356,
   3.436429,
   2.99615,
   2.585262,
   2.202837,
   1.848512,
   1.521291,
   1.224859,
   0.9653591,
   0.740239,
   0.5483523,
   0.3878802,
   0.2570296,
   0.1545826,
   0.07901739,
   0.02910855,
   0.003817996,
   0,
   0.00197147,
   0.02269009,
   0.06447594,
   0.1269612,
   0.2091303,
   0.3102615,
   0.4292446,
   0.5658069,
   0.7186598,
   0.8879853,
   1.072373,
   1.27197,
   1.485874,
   1.713763,
   1.954772,
   2.208867,
   2.475128,
   2.753629,
   3.043539,
   3.344205,
   3.65629,
   3.978506,
   4.308592,
   4.650569,
   5.002406,
   5.363531,
   5.733358,
   6.112096,
   6.498969,
   6.894057};
   TGraph *graph = new TGraph(50,total_fx1,total_fy1);
   graph->SetName("total");
   graph->SetTitle("Graph");
   graph->SetFillColor(1);
   graph->SetMarkerColor(0);
   graph->SetMarkerStyle(20);
   graph->SetMarkerSize(0.7);
   
   TH1F *Graph_total1 = new TH1F("Graph_total1","Graph",100,26.56,72.64);
   Graph_total1->SetMinimum(0);
   Graph_total1->SetMaximum(8);
   Graph_total1->SetDirectory(0);
   Graph_total1->SetStats(0);
   Graph_total1->SetLineStyle(0);
   Graph_total1->SetMarkerStyle(20);
   Graph_total1->SetMarkerSize(0.7);
   Graph_total1->GetXaxis()->SetTitle("#sigma [nb]");
   Graph_total1->GetXaxis()->SetLabelFont(42);
   Graph_total1->GetXaxis()->SetTitleSize(0.05);
   Graph_total1->GetXaxis()->SetTickLength(0.02);
   Graph_total1->GetXaxis()->SetTitleOffset(1.08);
   Graph_total1->GetXaxis()->SetTitleFont(42);
   Graph_total1->GetYaxis()->SetTitle("#minus2 ln #Lambda (#sigma)");
   Graph_total1->GetYaxis()->SetLabelFont(42);
   Graph_total1->GetYaxis()->SetLabelOffset(0.007);
   Graph_total1->GetYaxis()->SetTitleSize(0.05);
   Graph_total1->GetYaxis()->SetTickLength(0.02);
   Graph_total1->GetYaxis()->SetTitleOffset(1.028571);
   Graph_total1->GetYaxis()->SetTitleFont(42);
   Graph_total1->GetZaxis()->SetLabelFont(42);
   Graph_total1->GetZaxis()->SetLabelOffset(0.007);
   Graph_total1->GetZaxis()->SetTitleSize(0.05);
   Graph_total1->GetZaxis()->SetTickLength(0.02);
   Graph_total1->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_total1);
   
   graph->Draw("ap");
   TLine *line = new TLine(26.56,1,72.64,1);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#ff0000");
   line->SetLineColor(ci);
   line->Draw();
   line = new TLine(38.28651,0,38.28651,1);

   ci = TColor::GetColor("#ff0000");
   line->SetLineColor(ci);
   line->Draw();
   line = new TLine(53.29373,0,53.29373,1);

   ci = TColor::GetColor("#ff0000");
   line->SetLineColor(ci);
   line->Draw();
   line = new TLine(26.56,3.87,72.64,3.87);

   ci = TColor::GetColor("#ff0000");
   line->SetLineColor(ci);
   line->Draw();
   line = new TLine(32.05855,0,32.05855,3.87);

   ci = TColor::GetColor("#ff0000");
   line->SetLineColor(ci);
   line->Draw();
   line = new TLine(62.13278,0,62.13278,3.87);

   ci = TColor::GetColor("#ff0000");
   line->SetLineColor(ci);
   line->Draw();
   
   TF1 *splinefn01 = new TF1("*splinefn0",30.4,68.8,1);
    //The original function :  had originally been created by:
    //TF1 *splinefn0 = new TF1("splinefn0",,30.4,68.8,1);
   splinefn01->SetRange(30.4,68.8);
   splinefn01->SetName("splinefn0");
   splinefn01->SetTitle("");
   splinefn01->SetNpx(200);
   splinefn01->SetSavedPoint(0,4.935491);
   splinefn01->SetSavedPoint(1,4.80562);
   splinefn01->SetSavedPoint(2,4.677393);
   splinefn01->SetSavedPoint(3,4.550841);
   splinefn01->SetSavedPoint(4,4.425992);
   splinefn01->SetSavedPoint(5,4.302874);
   splinefn01->SetSavedPoint(6,4.181516);
   splinefn01->SetSavedPoint(7,4.061948);
   splinefn01->SetSavedPoint(8,3.944198);
   splinefn01->SetSavedPoint(9,3.828289);
   splinefn01->SetSavedPoint(10,3.714191);
   splinefn01->SetSavedPoint(11,3.601837);
   splinefn01->SetSavedPoint(12,3.49116);
   splinefn01->SetSavedPoint(13,3.382094);
   splinefn01->SetSavedPoint(14,3.274626);
   splinefn01->SetSavedPoint(15,3.168793);
   splinefn01->SetSavedPoint(16,3.064636);
   splinefn01->SetSavedPoint(17,2.962195);
   splinefn01->SetSavedPoint(18,2.861483);
   splinefn01->SetSavedPoint(19,2.762472);
   splinefn01->SetSavedPoint(20,2.665129);
   splinefn01->SetSavedPoint(21,2.569424);
   splinefn01->SetSavedPoint(22,2.475336);
   splinefn01->SetSavedPoint(23,2.382868);
   splinefn01->SetSavedPoint(24,2.292033);
   splinefn01->SetSavedPoint(25,2.202837);
   splinefn01->SetSavedPoint(26,2.115285);
   splinefn01->SetSavedPoint(27,2.029346);
   splinefn01->SetSavedPoint(28,1.944986);
   splinefn01->SetSavedPoint(29,1.862168);
   splinefn01->SetSavedPoint(30,1.780865);
   splinefn01->SetSavedPoint(31,1.701106);
   splinefn01->SetSavedPoint(32,1.622941);
   splinefn01->SetSavedPoint(33,1.546422);
   splinefn01->SetSavedPoint(34,1.471604);
   splinefn01->SetSavedPoint(35,1.398592);
   splinefn01->SetSavedPoint(36,1.327522);
   splinefn01->SetSavedPoint(37,1.258531);
   splinefn01->SetSavedPoint(38,1.191751);
   splinefn01->SetSavedPoint(39,1.127206);
   splinefn01->SetSavedPoint(40,1.064812);
   splinefn01->SetSavedPoint(41,1.004479);
   splinefn01->SetSavedPoint(42,0.9461207);
   splinefn01->SetSavedPoint(43,0.8896827);
   splinefn01->SetSavedPoint(44,0.8351675);
   splinefn01->SetSavedPoint(45,0.7825818);
   splinefn01->SetSavedPoint(46,0.7319322);
   splinefn01->SetSavedPoint(47,0.6832151);
   splinefn01->SetSavedPoint(48,0.6364014);
   splinefn01->SetSavedPoint(49,0.5914581);
   splinefn01->SetSavedPoint(50,0.5483522);
   splinefn01->SetSavedPoint(51,0.507052);
   splinefn01->SetSavedPoint(52,0.4675306);
   splinefn01->SetSavedPoint(53,0.429762);
   splinefn01->SetSavedPoint(54,0.3937207);
   splinefn01->SetSavedPoint(55,0.3593821);
   splinefn01->SetSavedPoint(56,0.32673);
   splinefn01->SetSavedPoint(57,0.2957517);
   splinefn01->SetSavedPoint(58,0.2664347);
   splinefn01->SetSavedPoint(59,0.2387656);
   splinefn01->SetSavedPoint(60,0.2127243);
   splinefn01->SetSavedPoint(61,0.1882865);
   splinefn01->SetSavedPoint(62,0.1654277);
   splinefn01->SetSavedPoint(63,0.1441235);
   splinefn01->SetSavedPoint(64,0.1243539);
   splinefn01->SetSavedPoint(65,0.1061031);
   splinefn01->SetSavedPoint(66,0.08935529);
   splinefn01->SetSavedPoint(67,0.07409489);
   splinefn01->SetSavedPoint(68,0.06030667);
   splinefn01->SetSavedPoint(69,0.04797618);
   splinefn01->SetSavedPoint(70,0.03708901);
   splinefn01->SetSavedPoint(71,0.02763076);
   splinefn01->SetSavedPoint(72,0.01958744);
   splinefn01->SetSavedPoint(73,0.01294608);
   splinefn01->SetSavedPoint(74,0.007693862);
   splinefn01->SetSavedPoint(75,0.003817968);
   splinefn01->SetSavedPoint(76,0.001301522);
   splinefn01->SetSavedPoint(77,0.0001114182);
   splinefn01->SetSavedPoint(78,0.0002124564);
   splinefn01->SetSavedPoint(79,0.001609659);
   splinefn01->SetSavedPoint(80,0.004337615);
   splinefn01->SetSavedPoint(81,0.008378544);
   splinefn01->SetSavedPoint(82,0.01369271);
   splinefn01->SetSavedPoint(83,0.02024032);
   splinefn01->SetSavedPoint(84,0.02798391);
   splinefn01->SetSavedPoint(85,0.03691342);
   splinefn01->SetSavedPoint(86,0.04703643);
   splinefn01->SetSavedPoint(87,0.0583608);
   splinefn01->SetSavedPoint(88,0.07089379);
   splinefn01->SetSavedPoint(89,0.08462823);
   splinefn01->SetSavedPoint(90,0.09954254);
   splinefn01->SetSavedPoint(91,0.1156145);
   splinefn01->SetSavedPoint(92,0.1328221);
   splinefn01->SetSavedPoint(93,0.1511501);
   splinefn01->SetSavedPoint(94,0.1705944);
   splinefn01->SetSavedPoint(95,0.1911516);
   splinefn01->SetSavedPoint(96,0.2128186);
   splinefn01->SetSavedPoint(97,0.2355863);
   splinefn01->SetSavedPoint(98,0.2594325);
   splinefn01->SetSavedPoint(99,0.2843325);
   splinefn01->SetSavedPoint(100,0.3102619);
   splinefn01->SetSavedPoint(101,0.3372017);
   splinefn01->SetSavedPoint(102,0.3651556);
   splinefn01->SetSavedPoint(103,0.3941327);
   splinefn01->SetSavedPoint(104,0.424142);
   splinefn01->SetSavedPoint(105,0.4551886);
   splinefn01->SetSavedPoint(106,0.4872493);
   splinefn01->SetSavedPoint(107,0.5202895);
   splinefn01->SetSavedPoint(108,0.5542746);
   splinefn01->SetSavedPoint(109,0.5891729);
   splinefn01->SetSavedPoint(110,0.6249852);
   splinefn01->SetSavedPoint(111,0.6617336);
   splinefn01->SetSavedPoint(112,0.6994403);
   splinefn01->SetSavedPoint(113,0.7381265);
   splinefn01->SetSavedPoint(114,0.7777833);
   splinefn01->SetSavedPoint(115,0.8183726);
   splinefn01->SetSavedPoint(116,0.8598547);
   splinefn01->SetSavedPoint(117,0.9021903);
   splinefn01->SetSavedPoint(118,0.945362);
   splinefn01->SetSavedPoint(119,0.989386);
   splinefn01->SetSavedPoint(120,1.034281);
   splinefn01->SetSavedPoint(121,1.080067);
   splinefn01->SetSavedPoint(122,1.126751);
   splinefn01->SetSavedPoint(123,1.174313);
   splinefn01->SetSavedPoint(124,1.222727);
   splinefn01->SetSavedPoint(125,1.27197);
   splinefn01->SetSavedPoint(126,1.322021);
   splinefn01->SetSavedPoint(127,1.372881);
   splinefn01->SetSavedPoint(128,1.424555);
   splinefn01->SetSavedPoint(129,1.477046);
   splinefn01->SetSavedPoint(130,1.530359);
   splinefn01->SetSavedPoint(131,1.584477);
   splinefn01->SetSavedPoint(132,1.639379);
   splinefn01->SetSavedPoint(133,1.695043);
   splinefn01->SetSavedPoint(134,1.751449);
   splinefn01->SetSavedPoint(135,1.808596);
   splinefn01->SetSavedPoint(136,1.866494);
   splinefn01->SetSavedPoint(137,1.925153);
   splinefn01->SetSavedPoint(138,1.984586);
   splinefn01->SetSavedPoint(139,2.044783);
   splinefn01->SetSavedPoint(140,2.105723);
   splinefn01->SetSavedPoint(141,2.167378);
   splinefn01->SetSavedPoint(142,2.229726);
   splinefn01->SetSavedPoint(143,2.292755);
   splinefn01->SetSavedPoint(144,2.356474);
   splinefn01->SetSavedPoint(145,2.420897);
   splinefn01->SetSavedPoint(146,2.486035);
   splinefn01->SetSavedPoint(147,2.551892);
   splinefn01->SetSavedPoint(148,2.618454);
   splinefn01->SetSavedPoint(149,2.685706);
   splinefn01->SetSavedPoint(150,2.75363);
   splinefn01->SetSavedPoint(151,2.82221);
   splinefn01->SetSavedPoint(152,2.891431);
   splinefn01->SetSavedPoint(153,2.961279);
   splinefn01->SetSavedPoint(154,3.031738);
   splinefn01->SetSavedPoint(155,3.102799);
   splinefn01->SetSavedPoint(156,3.174472);
   splinefn01->SetSavedPoint(157,3.246777);
   splinefn01->SetSavedPoint(158,3.319737);
   splinefn01->SetSavedPoint(159,3.39337);
   splinefn01->SetSavedPoint(160,3.467675);
   splinefn01->SetSavedPoint(161,3.54264);
   splinefn01->SetSavedPoint(162,3.618249);
   splinefn01->SetSavedPoint(163,3.69449);
   splinefn01->SetSavedPoint(164,3.771317);
   splinefn01->SetSavedPoint(165,3.848659);
   splinefn01->SetSavedPoint(166,3.926442);
   splinefn01->SetSavedPoint(167,4.004594);
   splinefn01->SetSavedPoint(168,4.083115);
   splinefn01->SetSavedPoint(169,4.162115);
   splinefn01->SetSavedPoint(170,4.241715);
   splinefn01->SetSavedPoint(171,4.322035);
   splinefn01->SetSavedPoint(172,4.403144);
   splinefn01->SetSavedPoint(173,4.484987);
   splinefn01->SetSavedPoint(174,4.567488);
   splinefn01->SetSavedPoint(175,4.650571);
   splinefn01->SetSavedPoint(176,4.734175);
   splinefn01->SetSavedPoint(177,4.8183);
   splinefn01->SetSavedPoint(178,4.902955);
   splinefn01->SetSavedPoint(179,4.988152);
   splinefn01->SetSavedPoint(180,5.073902);
   splinefn01->SetSavedPoint(181,5.160192);
   splinefn01->SetSavedPoint(182,5.247004);
   splinefn01->SetSavedPoint(183,5.334319);
   splinefn01->SetSavedPoint(184,5.42212);
   splinefn01->SetSavedPoint(185,5.510409);
   splinefn01->SetSavedPoint(186,5.599199);
   splinefn01->SetSavedPoint(187,5.688507);
   splinefn01->SetSavedPoint(188,5.778344);
   splinefn01->SetSavedPoint(189,5.868709);
   splinefn01->SetSavedPoint(190,5.95958);
   splinefn01->SetSavedPoint(191,6.050936);
   splinefn01->SetSavedPoint(192,6.142756);
   splinefn01->SetSavedPoint(193,6.235029);
   splinefn01->SetSavedPoint(194,6.327759);
   splinefn01->SetSavedPoint(195,6.420952);
   splinefn01->SetSavedPoint(196,6.514614);
   splinefn01->SetSavedPoint(197,6.608749);
   splinefn01->SetSavedPoint(198,6.703364);
   splinefn01->SetSavedPoint(199,6.798465);
   splinefn01->SetSavedPoint(200,6.894057);
   splinefn01->SetSavedPoint(201,30.4);
   splinefn01->SetSavedPoint(202,68.8);
   splinefn01->SetFillStyle(0);
   splinefn01->SetMarkerStyle(20);
   splinefn01->SetMarkerSize(0.7);
   splinefn01->SetLineWidth(3);
   splinefn01->GetXaxis()->SetLabelFont(42);
   splinefn01->GetXaxis()->SetTitleSize(0.05);
   splinefn01->GetXaxis()->SetTickLength(0.02);
   splinefn01->GetXaxis()->SetTitleOffset(1.08);
   splinefn01->GetXaxis()->SetTitleFont(42);
   splinefn01->GetYaxis()->SetLabelFont(42);
   splinefn01->GetYaxis()->SetLabelOffset(0.007);
   splinefn01->GetYaxis()->SetTitleSize(0.05);
   splinefn01->GetYaxis()->SetTickLength(0.02);
   splinefn01->GetYaxis()->SetTitleOffset(1.028571);
   splinefn01->GetYaxis()->SetTitleFont(42);
   splinefn01->SetParameter(0,0);
   splinefn01->SetParError(0,0);
   splinefn01->SetParLimits(0,0,0);
   splinefn01->Draw("same");
   TBox *box = new TBox(26.56,5,72.64,8);
   box->Draw();
   
   TH1F *total_copy1 = new TH1F("total_copy1","Graph",100,26.56,72.64);
   total_copy1->SetMinimum(0);
   total_copy1->SetMaximum(8);
   total_copy1->SetDirectory(0);
   total_copy1->SetStats(0);
   total_copy1->SetLineStyle(0);
   total_copy1->SetMarkerStyle(20);
   total_copy1->SetMarkerSize(0.7);
   total_copy1->GetXaxis()->SetTitle("#sigma [nb]");
   total_copy1->GetXaxis()->SetLabelFont(42);
   total_copy1->GetXaxis()->SetTitleSize(0.05);
   total_copy1->GetXaxis()->SetTickLength(0.02);
   total_copy1->GetXaxis()->SetTitleOffset(1.08);
   total_copy1->GetXaxis()->SetTitleFont(42);
   total_copy1->GetYaxis()->SetTitle("#minus2 ln #Lambda (#sigma)");
   total_copy1->GetYaxis()->SetLabelFont(42);
   total_copy1->GetYaxis()->SetLabelOffset(0.007);
   total_copy1->GetYaxis()->SetTitleSize(0.05);
   total_copy1->GetYaxis()->SetTickLength(0.02);
   total_copy1->GetYaxis()->SetTitleOffset(1.028571);
   total_copy1->GetYaxis()->SetTitleFont(42);
   total_copy1->GetZaxis()->SetLabelFont(42);
   total_copy1->GetZaxis()->SetLabelOffset(0.007);
   total_copy1->GetZaxis()->SetTitleSize(0.05);
   total_copy1->GetZaxis()->SetTickLength(0.02);
   total_copy1->GetZaxis()->SetTitleFont(42);
   total_copy1->Draw("sameaxis");
   
   TPaveText *pt = new TPaveText(0.59,0.82,0.95,0.91,"NDCNB");
   pt->SetFillColor(0);
   pt->SetTextAlign(11);
   pt->SetTextFont(42);
   pt->SetTextSize(0.06);
   TText *AText = pt->AddText("#sigma = 45{}^{#plus 8}_{#minus 7} nb");
   pt->Draw();
      tex = new TLatex(0.1498714,0.9113,"CMS");
tex->SetNDC();
   tex->SetTextAlign(13);
   tex->SetTextSize(0.048);
   tex->SetLineWidth(2);
   tex->Draw();
      tex = new TLatex(0.1498714,0.8537,"#it{Unpublished}");
tex->SetNDC();
   tex->SetTextAlign(13);
   tex->SetTextFont(52);
   tex->SetTextSize(0.03648);
   tex->SetLineWidth(2);
   tex->Draw();
      tex = new TLatex(0.9657143,0.952,"#lower[-0.1]{174 nb^{-1} (pPb, #sqrt{s_{NN}} = 8.16 TeV)}");
tex->SetNDC();
   tex->SetTextAlign(31);
   tex->SetTextFont(42);
   tex->SetTextSize(0.036);
   tex->SetLineWidth(2);
   tex->Draw();
   pad->Modified();
   total->cd();
   total->Modified();
   total->cd();
   total->SetSelected(total);
}
