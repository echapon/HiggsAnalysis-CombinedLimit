#!/bin/bash

model=wmodel0_0_20170706

## this variable should be empty by default, make it _2bonly for computing for 2b category only
bonly=
# bonly="_2bonly"
# bonly="_eonly"
# bonly="_muonly"

modelfull=${model}${bonly}

if [ -n "$bonly" ]; then
   echo "ha"
   if [ $bonly = "_2bonly" ]; then
      combineCards.py --xc=e1l4j2q --xc=e1l4j1b1q --xc=mu1l4j2q --xc=mu1l4j1b1q datacard_${model}.txt > datacard_${modelfull}.txt
   elif [ $bonly = "_eonly" ]; then
      combineCards.py --xc=mu1l4j2b--xc=mu1l4j2q --xc=mu1l4j1b1q datacard_${model}.txt > datacard_${modelfull}.txt
   elif [ $bonly = "_muonly" ]; then
      combineCards.py --xc=e1l4j2b--xc=e1l4j2q --xc=e1l4j1b1q datacard_${model}.txt > datacard_${modelfull}.txt
   fi
fi

# make the workspace for combine
text2workspace.py -m 125 -P HiggsAnalysis.CombinedLimit.HIN17002:TTbarModel_${model} datacard_${modelfull}.txt -o combine_workspace_${modelfull}_norateparams.root -v 99
# run the fit
combine --plots -M MaxLikelihoodFit combine_workspace_${modelfull}_norateparams.root --preFitValue 50 --redefineSignalPOI xsec -m 125 --X-rtd ADDNLL_CBNLL=0 --robustFit 1 --saveWorkspace --minimizerStrategy 2 --saveShapes
# compute the expected significance
combine -n SignifObs -M ProfileLikelihood --signif -t -1 --setPhysicsModelParameters xsec=59 --toysFreq -m 125 combine_workspace_${modelfull}_norateparams.root --pvalue --X-rtd ADDNLL_CBNLL=0
# compute the observed significance
combine -n SignifObs -M ProfileLikelihood --signif -m 125 combine_workspace_${modelfull}_norateparams.root --pvalue --X-rtd ADDNLL_CBNLL=0 
