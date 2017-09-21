from HiggsAnalysis.CombinedLimit.PhysicsModel import *

class myModel(PhysicsModel):
   def doParametersOfInterest(self):
      """Our POI is the Jpsi yield"""
      poiName = ["
