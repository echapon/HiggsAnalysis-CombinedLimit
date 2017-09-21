#!/bin/bash

# from https://indico.cern.ch/event/577649/contributions/2388797/attachments/1380376/2098158/HComb-Tutorial-Nov16-Impacts.pdf

model=wmodel0_0_20170712

combineTool.py -M Impacts -d combine_workspace_${model}_norateparams.root -m 125 --doInitialFit --preFitValue 50 --redefineSignalPOI xsec --X-rtd ADDNLL_CBNLL=0 --robustFit 1  --minimizerStrategy 2 --minimizerStrategyForMinos 2 --keepFailures --stepSize 0.15
combineTool.py -M Impacts -d combine_workspace_${model}_norateparams.root -m 125 --doFits --parallel 4 --preFitValue 50 --redefineSignalPOI xsec --X-rtd ADDNLL_CBNLL=0 --robustFit 1  --minimizerStrategy 2 --minimizerStrategyForMinos 2 --keepFailures --stepSize 0.15
combineTool.py -M Impacts -d combine_workspace_${model}_norateparams.root -m 125 -o impacts_${model}.json
plotImpacts.py -i impacts_${model}.json -o impacts_${model}
