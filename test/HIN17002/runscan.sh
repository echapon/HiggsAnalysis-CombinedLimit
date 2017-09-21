#!/bin/bash

# cf https://indico.cern.ch/event/577649/contributions/2388797/attachments/1380376/2098158/HComb-Tutorial-Nov16-Impacts.pdf

MODEL=wmodel0_0_20170712_muonly

# first stat+syst
combine -M MultiDimFit --algo grid --points 50 --rMin 30 --rMax 70 combine_workspace_${MODEL}_norateparams.root -m 125 -n nominal --X-rtd ADDNLL_CBNLL=0 --minimizerStrategy 2
plot1DScan.py -m higgsCombinenominal.MultiDimFit.mH125.root --POI xsec -o total

# now split stat and syst
combine -M MultiDimFit --algo none --rMin 30 --rMax 70 combine_workspace_${MODEL}_norateparams.root -m 125 -n bestfit --X-rtd ADDNLL_CBNLL=0 --saveWorkspace --minimizerStrategy 2
combine -M MultiDimFit --algo grid --points 50 --rMin 30 --rMax 70 higgsCombinebestfit.MultiDimFit.mH125.root --snapshotName MultiDimFit --freezeNuisances all -m 125 -n stat --X-rtd ADDNLL_CBNLL=0 --minimizerStrategy 2
plot1DScan.py -m higgsCombinenominal.MultiDimFit.mH125.root --POI xsec -o statsyst --others 'higgsCombinestat.MultiDimFit.mH125.root:Freeze all:2' --breakdown syst,stat

# paper style
# ./plot1DScan.py -m plots_wmodel0_0_20170712/higgsCombinenominal.MultiDimFit.mH125.root --POI xsec -o total --y-max 7 --box-frac 0.7
