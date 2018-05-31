#!/bin/bash

pwd_=$PWD

basedir=/afs/cern.ch/user/e/echapon/workspace/private/higgs_combine/CMSSW_8_1_0/src/HiggsAnalysis/CombinedLimit/test/FSQ16012

cd $basedir
cmsenv
cd $pwd_

pwd
# cp $basedir/datacard .
ls

if [ $1 -eq 0 ]; then 
   command="combine -M HybridNew --rRelAcc=0.01 --rule CLs --cl=0.95 --LHCmode LHC-limits ${2}"  
   text="Observed"
elif [ $1 -eq 1 ]; then 
   command="combine -M HybridNew --rRelAcc=0.01 --rule CLs --cl=0.95 --LHCmode LHC-limits --expectedFromGrid=0.025 ${2}"   
   text="Expected 0.025"
elif [ $1 -eq 2 ]; then 
   command="combine -M HybridNew --rRelAcc=0.01 --rule CLs --cl=0.95 --LHCmode LHC-limits --expectedFromGrid=0.16 ${2}"   
   text="Expected 0.16"
elif [ $1 -eq 3 ]; then
   command="combine -M HybridNew --rRelAcc=0.01 --rule CLs --cl=0.95 --LHCmode LHC-limits --expectedFromGrid=0.5 ${2}"
   text="Expected 0.5"
elif [ $1 -eq 4 ]; then 
   command="combine -M HybridNew --rRelAcc=0.01 --rule CLs --cl=0.95 --LHCmode LHC-limits --expectedFromGrid=0.84 ${2}"
   text="Expected 0.84"
elif [ $1 -eq 5 ]; then
   command="combine -M HybridNew --rRelAcc=0.01 --rule CLs --cl=0.95 --LHCmode LHC-limits --expectedFromGrid=0.975 ${2}"
   text="Expected 0.975"
fi

echo $command
$command
echo "FINISHED!"
echo "We just computed: " $text " using file: " $2
