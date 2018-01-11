void makeRooMultiPdfWorkspace(){

   // Load the combine Library 
   gSystem->Load("libHiggsAnalysisCombinedLimit.so");

   // Open the workspace
   TFile *f_upsi = TFile::Open("fitresult_pp.root");
   RooWorkspace *w_upsi = (RooWorkspace*)f_upsi->Get("ws");

   // The observable
   RooRealVar *mass =  w_upsi->var("invariantMass");

   // Get the nominal pdf
   RooAbsPdf *pdf_nom = w_upsi->pdf("bkgPdf");
   // create the alternative one
   w_upsi->factory("Chebychev::bkgPdf_pol3(invariantMass,{a30[0.5,0,1],a31[-0.2,0,1],a32[0.01,0,1]})");
   RooAbsPdf *pdf_pol3 = w_upsi->pdf("bkgPdf_pol3");
   w_upsi->factory("Chebychev::bkgPdf_pol4(invariantMass,{a40[0.5,0,1],a41[-0.2,0,1],a42[0.01,0,1],a43[0.001,0,1]})");
   RooAbsPdf *pdf_pol4 = w_upsi->pdf("bkgPdf_pol4");
   w_upsi->factory("Chebychev::bkgPdf_pol5(invariantMass,{a50[0.5,0,1],a51[-0.2,0,1],a52[0.01,0,1],a53[0.001,0,1],a54[0.001,0,1]})");
   RooAbsPdf *pdf_pol5 = w_upsi->pdf("bkgPdf_pol5");


   // Fit the functions to the data to set the "prefit" state (note this can and should be redone with combine when doing 
   // bias studies as one typically throws toys from the "best-fit"
   RooDataSet *data = (RooDataSet*)w_upsi->data("data");
   pdf_nom->fitTo(*data);  // index 0
   pdf_pol3->fitTo(*data); // index 1 
   pdf_pol4->fitTo(*data); // index 2 
   pdf_pol5->fitTo(*data); // index 3 

   // Make a plot (data is a toy dataset)
   RooPlot *plot = mass->frame();   data->plotOn(plot);
   pdf_nom->plotOn(plot,RooFit::LineColor(kGreen));
   pdf_pol3->plotOn(plot,RooFit::LineColor(kBlue));
   pdf_pol4->plotOn(plot,RooFit::LineColor(kRed));
   pdf_pol5->plotOn(plot,RooFit::LineColor(kCyan));
   plot->SetTitle("PDF fits to toy data");
   plot->Draw();

   // Make a RooCategory object. This will control which of the pdfs is "active"
   RooCategory cat("pdf_index","Index of Pdf which is active");

   // Make a RooMultiPdf object. The order of the pdfs will be the order of their index, ie for below 
   // 0 == exponential
   // 1 == linear function
   // 2 == powerlaw
   RooArgList mypdfs;
   mypdfs.add(*pdf_nom);
   mypdfs.add(*pdf_pol3);
   mypdfs.add(*pdf_pol4);
   mypdfs.add(*pdf_pol5);
   
   RooMultiPdf multipdf("roomultipdf","All Pdfs",cat,mypdfs);
   
   // As usual make an extended term for the background with _norm for freely floating yield
   RooRealVar norm("roomultipdf_norm","Number of background events",0,100000);
   norm.setVal(10640);
   
   // Save to a new workspace
   TFile *fout = new TFile("background_pdfs.root","RECREATE");
   RooWorkspace wout("backgrounds","backgrounds");
   wout.import(cat);
   wout.import(norm);
   wout.import(multipdf);
   wout.Print();
   wout.Write();

}
