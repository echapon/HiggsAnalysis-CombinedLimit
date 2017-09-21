from HiggsAnalysis.CombinedLimit.PhysicsModel import *
from ROOT import TFile, RooWorkspace
import ROOT

class ttbarmodel(PhysicsModel):
   "simple model builder for HIN-17-002"
   def __init__(self, filename):
      PhysicsModel.__init__(self)
      self.baseROOTfile = TFile(filename)
      self.baseWS = RooWorkspace(self.baseROOTfile.Get("w"))

   def doParametersOfInterest(self):
      "the POI is xsec"
      self.modelBuilder.doVar("xsec[50,0,200]")
      self.modelBuilder.doSet("POI","xsec")
      # self.MB = ModelBuilder(self.modelBuilder)
      # self.setup()

   def getYieldScale(self,bin,process):
      "Return the name of a RooAbsReal to scale this yield by or the two special values 1 and 0"
      if process=="ttbar":
         if "e1l4j2q" in bin:
            self.modelBuilder.out._import(self.baseWS.arg("Nsig_e1l4j2q"),ROOT.RooFit.RecycleConflictNodes())
            return "Nsig_e1l4j2q"
         if "e1l4j1b1q" in bin:
            self.modelBuilder.out._import(self.baseWS.arg("Nsig_e1l4j1b1q"),ROOT.RooFit.RecycleConflictNodes())
            return "Nsig_e1l4j1b1q"
         if "e1l4j2b" in bin:
            self.modelBuilder.out._import(self.baseWS.arg("Nsig_e1l4j2b"),ROOT.RooFit.RecycleConflictNodes())
            return "Nsig_e1l4j2b"
         if "mu1l4j2q" in bin:
            self.modelBuilder.out._import(self.baseWS.arg("Nsig_mu1l4j2q"),ROOT.RooFit.RecycleConflictNodes())
            return "Nsig_mu1l4j2q"
         if "mu1l4j1b1q" in bin:
            self.modelBuilder.out._import(self.baseWS.arg("Nsig_mu1l4j1b1q"),ROOT.RooFit.RecycleConflictNodes())
            return "Nsig_mu1l4j1b1q"
         if "mu1l4j2b" in bin:
            self.modelBuilder.out._import(self.baseWS.arg("Nsig_mu1l4j2b"),ROOT.RooFit.RecycleConflictNodes())
            return "Nsig_mu1l4j2b"
      elif process=="wjets":
         if "e1l4j2q" in bin:
            self.modelBuilder.out._import(self.baseWS.arg("Nw_e1l4j2q"),ROOT.RooFit.RecycleConflictNodes())
            return "Nw_e1l4j2q"
         if "e1l4j1b1q" in bin:
            self.modelBuilder.out._import(self.baseWS.arg("Nw_e1l4j1b1q"),ROOT.RooFit.RecycleConflictNodes())
            return "Nw_e1l4j1b1q"
         if "e1l4j2b" in bin:
            self.modelBuilder.out._import(self.baseWS.arg("Nw_e1l4j2b"),ROOT.RooFit.RecycleConflictNodes())
            return "Nw_e1l4j2b"
         if "mu1l4j2q" in bin:
            self.modelBuilder.out._import(self.baseWS.arg("Nw_mu1l4j2q"),ROOT.RooFit.RecycleConflictNodes())
            return "Nw_mu1l4j2q"
         if "mu1l4j1b1q" in bin:
            self.modelBuilder.out._import(self.baseWS.arg("Nw_mu1l4j1b1q"),ROOT.RooFit.RecycleConflictNodes())
            return "Nw_mu1l4j1b1q"
         if "mu1l4j2b" in bin:
            self.modelBuilder.out._import(self.baseWS.arg("Nw_mu1l4j2b"),ROOT.RooFit.RecycleConflictNodes())
            return "Nw_mu1l4j2b"
      elif process=="qcd":
         if "e1l4j2q" in bin:
            self.modelBuilder.out._import(self.baseWS.arg("Nqcd_e1l4j2q"),ROOT.RooFit.RecycleConflictNodes())
            return "Nqcd_e1l4j2q"
         if "e1l4j1b1q" in bin:
            self.modelBuilder.out._import(self.baseWS.arg("Nqcd_e1l4j1b1q"),ROOT.RooFit.RecycleConflictNodes())
            return "Nqcd_e1l4j1b1q"
         if "e1l4j2b" in bin:
            self.modelBuilder.out._import(self.baseWS.arg("Nqcd_e1l4j2b"),ROOT.RooFit.RecycleConflictNodes())
            return "Nqcd_e1l4j2b"
         if "mu1l4j2q" in bin:
            self.modelBuilder.out._import(self.baseWS.arg("Nqcd_mu1l4j2q"),ROOT.RooFit.RecycleConflictNodes())
            return "Nqcd_mu1l4j2q"
         if "mu1l4j1b1q" in bin:
            self.modelBuilder.out._import(self.baseWS.arg("Nqcd_mu1l4j1b1q"),ROOT.RooFit.RecycleConflictNodes())
            return "Nqcd_mu1l4j1b1q"
         if "mu1l4j2b" in bin:
            self.modelBuilder.out._import(self.baseWS.arg("Nqcd_mu1l4j2b"),ROOT.RooFit.RecycleConflictNodes())
            return "Nqcd_mu1l4j2b"
      
      "default"
      return 1

TTbarModel_wmodel0_0_20170706 = ttbarmodel("/afs/cern.ch/user/e/echapon/workspace/private/higgs_combine/CMSSW_7_4_7/src/HiggsAnalysis/CombinedLimit/test/HIN17002/fit_finalworkspace_wmodel0_0_20170706.root")
TTbarModel_wmodel2_0_20170706 = ttbarmodel("/afs/cern.ch/user/e/echapon/workspace/private/higgs_combine/CMSSW_7_4_7/src/HiggsAnalysis/CombinedLimit/test/HIN17002/fit_finalworkspace_wmodel2_0_20170706.root")
TTbarModel_wmodel0_0_20170712 = ttbarmodel("/afs/cern.ch/user/e/echapon/workspace/private/higgs_combine/CMSSW_7_4_7/src/HiggsAnalysis/CombinedLimit/test/HIN17002/fit_finalworkspace_wmodel0_0_20170712.root")
