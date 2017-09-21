from HiggsAnalysis.CombinedLimit.PhysicsModel import *

class myModel(PhysicsModel):
   def doParametersOfInterest(self):
      """Our POI is the ups(1S) yield"""
      poiName = ["N_{#Upsilon(1S)}"]
      self.modelBuilder.doSet("POI",",".join(poiNames))
