void create_reduced_datasets(const char* input, const char* output) {
   TFile *fin = new TFile(input);

   const char* catnames[6] = {"e1l4j2q","e1l4j1b1q","e1l4j2b","mu1l4j2q","mu1l4j1b1q","mu1l4j2b"};
   RooWorkspace *win = (RooWorkspace*) fin->Get("w");
   RooAbsData *data = win->data("data");
   RooWorkspace *wout = new RooWorkspace("w","reduced datasets");

   for (int i=0; i<6; i++) {
      RooAbsData *datar = data->reduce(Form("sample==sample::%s",catnames[i]));
      datar->SetName(Form("data_%s",catnames[i]));
      wout->import(*datar);
   }

   // let's also create the variables for normalisation
   RooArgSet allPdfs = win->allPdfs();
   TIterator *it = allPdfs.createIterator();
   RooAbsPdf *thePdf = (RooAbsPdf*) it->Next();
   while (thePdf) {
      wout->import(*thePdf,RooFit::RecycleConflictNodes());
      wout->factory(Form("%s_norm[100,0,100000]",thePdf->GetName()));
      thePdf = (RooAbsPdf*) it->Next();
   }

   wout->writeToFile(output);
}
