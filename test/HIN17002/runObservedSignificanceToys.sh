#!/bin/bash

# run the toys
combineTool.py -M HybridNew -n SignifObs --signif -m 125 combine_workspace_wmodel0_0_20170712_norateparams.root --pvalue --X-rtd ADDNLL_CBNLL=0 --frequentist -T 10000 --saveHybridResult -s 1:1000:1 --job-mode lxbatch --task-name signif_toys_wmodel0_0_20170712 --sub-opts='-q 1nd' --redefineSignalPOI xsec
# wait for the jobs to finish...
# hadd the results
hadd higgsCombineSignifObs.HybridNew.all.root higgsCombineSignifObs.HybridNew.mH125.*root
# read the result
combine -M HybridNew --frequentist combine_workspace_wmodel0_0_20170712_norateparams.root --significance --pvalue --readHybridResult --toysFile=higgsCombineSignifObs.HybridNew.all.root  --redefineSignalPOI xsec -v 99 -m 125
# alternatively can also run hadd_hypotestresult.C on the hadd'ed output to get the combined HypoTestResult
