import ROOT
import sys
import pickle

WMODEL={}

ROOT.gStyle.SetOptStat(0)
ROOT.gStyle.SetOptTitle(0)

# set batch mode
ROOT.gROOT.SetBatch(True);

c=ROOT.TCanvas('c','c',500,500)
c.SetTopMargin(0.05)
c.SetLeftMargin(0.12)
c.SetRightMargin(0.04)
c.SetBottomMargin(0.12)

#loop over variables of interest
for var in ['mjj']:

    #reference
    refhistos={}
    refratios={}
    fIn=ROOT.TFile.Open(sys.argv[1])
    for cat,marker in [('1l4j2q',20),('1l4j1b1q',24),('1l4j2b',25)]:
        refhistos[cat]=fIn.Get('%s_mu%s'%(var,cat)).Clone('ref%s_%s'%(var,cat))
        refhistos[cat].Add(fIn.Get('%s_e%s'%(var,cat)))
        refhistos[cat].Scale(1./refhistos[cat].Integral(0,refhistos[cat].GetNbinsX()+1))
        refhistos[cat].SetTitle(cat)
        refhistos[cat].SetMarkerStyle(marker)
        refhistos[cat].SetDirectory(0)
        refratios[cat]=refhistos[cat].Clone('refratio%s_%s'%(var,cat))
        refratios[cat].SetDirectory(0)
        refratios[cat].Divide(refhistos['1l4j2q'])
        refratios[cat].Fit('pol1','MQ+')
    fIn.Close()

    #extrapolation
    histos={}
    projhistos={}
    fIn=ROOT.TFile.Open(sys.argv[2])
    for cat,marker,color in [('1l4j2q',20,1),('1l4j1b1q',24,ROOT.kAzure+4),('1l4j2b',25, ROOT.kRed+1)]:
        histos[cat]=fIn.Get('%s_mu%s'%(var,cat)).Clone('%s_%s'%(var,cat))
        histos[cat].SetTitle(cat)
        histos[cat].SetLineColor(color)
        histos[cat].SetMarkerColor(color)
        histos[cat].SetMarkerStyle(marker)
        histos[cat].SetDirectory(0)    
        projhistos[cat]=histos[cat].Clone('proj%s_%s'%(var,cat))
        projhistos[cat].SetDirectory(0)
        projhistos[cat].SetMarkerStyle(1)
        projhistos[cat].SetTitle(cat+' extrapol.')
        sf=histos[cat].Integral(0,histos[cat].GetNbinsX()+1)/histos['1l4j2q'].Integral(0,histos['1l4j2q'].GetNbinsX()+1)
        for xbin in xrange(1,histos[cat].GetNbinsX()+1):
            xcen=histos[cat].GetXaxis().GetBinCenter(xbin)
            val=histos['1l4j2q'].GetBinContent(xbin)*refratios[cat].GetFunction('pol1').Eval(xcen)*sf
            projhistos[cat].SetBinContent(xbin,val)
            projhistos[cat].SetBinError(xbin,0)
        projhistos[cat].Fit('landau','WWC+')
    fIn.Close()

    #
    # DISPLAY RESULTS
    #
    #extrapolation ratios
    c.Clear()
    c.SetLogy(False)
    refratios['1l4j2q'].SetFillStyle(1001)
    refratios['1l4j2q'].SetFillColor(ROOT.kGray)
    refratios['1l4j2q'].SetLineColor(ROOT.kGray)
    refratios['1l4j2q'].SetMarkerColor(ROOT.kGray)
    refratios['1l4j2q'].Draw('e2')
    refratios['1l4j2q'].GetYaxis().SetTitle('Ratio to 0b')
    refratios['1l4j2q'].GetYaxis().SetRangeUser(0,2)
    refratios['1l4j1b1q'].Draw('same')
    refratios['1l4j2b'].Draw('same')
    leg = c.BuildLegend(0.14,0.88,0.5,0.75)
    leg.SetBorderSize(0)
    leg.SetFillStyle(0)
    leg.SetTextFont(42)
    leg.SetTextSize(0.04)
    leg.Draw()
    label = ROOT.TLatex()
    label.SetNDC()
    label.SetTextFont(42)
    label.SetTextSize(0.04)
    label.DrawLatex(0.15,0.9,'#bf{CMS} #it{preliminary}')
    label.DrawLatex(0.58,0.96,'#scale[0.8]{180 nb^{-1} (pPb at #sqrt{s}=8.16 TeV)}')
    c.Modified()
    c.Update()
    # for ext in ['png','pdf','root']:
        # c.SaveAs('w_%s_refratios.%s'%(var,ext))

    mlfile = ROOT.TFile.Open("mlfit.root")
    fitresult_sb = mlfile.Get("fit_s")
    params_sb = fitresult_sb.floatParsFinal()
    fitresult_b = mlfile.Get("fit_b")
    params_b = fitresult_b.floatParsFinal()
    tree_sb = mlfile.Get("tree_fit_sb")
    tree_b = mlfile.Get("tree_fit_b")
    tree_sb.GetEntry(0)
    tree_b.GetEntry(0)

    #extrapolations
    for cat in projhistos:
       c.Clear()
       c.SetLogy()
       projhistos[cat].Draw('hist')
       projhistos[cat].GetYaxis().SetRangeUser(0.1,1e3)
       histos[cat].Draw('e1same')

       fitshape_sb = ROOT.TF1(("fitshape_sb_%s"%cat),"[0]*TMath::Landau(x,[1],[2],0)",0,1000)
       fitshape_sb.SetTitle("Data, S+B fit")
       # # exec("fitshape_sb.SetParameter(0,tree_sb.n_exp_bine"+cat+"_proc_wjets+tree_sb.n_exp_binmu"+cat+"_proc_wjets)")
       fitshape_sb.SetParameter(0,projhistos[cat].GetFunction('landau').GetParameter(0))
       # exec("fitshape_sb.SetParameter(1,tree_sb.mpv_wmjj_"+cat+")")
       # exec("fitshape_sb.SetParameter(2,tree_sb.width_wmjj_"+cat+")")
       fitshape_sb.SetParameter(1,params_sb[params_sb.index("mpv_wmjj_%s"%cat)].getVal()) 
       fitshape_sb.SetParameter(2,params_sb[params_sb.index("width_wmjj_%s"%cat)].getVal()) 
       fitshape_sb.SetLineColor(ROOT.kGreen+2)
       fitshape_sb.SetLineStyle(ROOT.kDashed)
       fitshape_sb.Draw("same L")
       fitshape_b = ROOT.TF1(("fitshape_b_%s"%cat),"[0]*TMath::Landau(x,[1],[2],0)",0,1000)
       fitshape_b.SetTitle("Data, B only fit")
       # # exec("fitshape_b.SetParameter(0,tree_b.n_exp_bine"+cat+"_proc_wjets+tree_b.n_exp_binmu"+cat+"_proc_wjets)")
       fitshape_b.SetParameter(0,projhistos[cat].GetFunction('landau').GetParameter(0))
       # exec("fitshape_b.SetParameter(1,tree_b.mpv_wmjj_"+cat+")")
       # exec("fitshape_b.SetParameter(2,tree_b.width_wmjj_"+cat+")")
       fitshape_b.SetParameter(1,params_b[params_b.index("mpv_wmjj_%s"%cat)].getVal()) 
       fitshape_b.SetParameter(2,params_b[params_b.index("width_wmjj_%s"%cat)].getVal()) 
       fitshape_b.SetLineColor(ROOT.kRed)
       fitshape_b.SetLineStyle(ROOT.kDashed)
       fitshape_b.Draw("same L")

       leg = c.BuildLegend(0.18,0.88,0.5,0.7)
       leg.SetBorderSize(0)
       leg.SetFillStyle(0)
       leg.SetTextFont(42)
       leg.SetTextSize(0.035)
       leg.Draw()
       label = ROOT.TLatex()
       label.SetNDC()
       label.SetTextFont(42)
       label.SetTextSize(0.04)
       label.DrawLatex(0.58,0.9,'#bf{CMS} #it{preliminary}')
       label.DrawLatex(0.58,0.96,'#scale[0.8]{180 nb^{-1} (pPb at #sqrt{s}=8.16 TeV)}')
    
       projhistos[cat].GetFunction('landau').Draw('same')

       c.Modified()
       c.Update()

       for ext in ['png','pdf','root']:
           c.SaveAs('w_%s_extrapolation_%s.%s'%(var,cat,ext))

# #dump results to a pickle file
# with open('wmodel.pck','wb') as fOut:
#     pickle.dump(WMODEL,fOut)

