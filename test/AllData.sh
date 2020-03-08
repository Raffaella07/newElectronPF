#!/bin/bash
export SCRAM_ARCH=slc7_amd64_gcc700
cd /afs/cern.ch/user/r/ratramon/Bparking/CMSSW_10_2_15/src/
eval `scramv1 runtime -sh`
echo $PWD
cd macros/newElectronPF/analysis
echo $PWD

declare -a pattern=("1_A_0/" "1_B_0/" "2_A_0/" "2_B_0/" "3_A_0/" "3_B_0/" "4_A_0/" "4_B_0/" "5_A_0/" "5_B_0/" "6_A_0/" "6_B_0/" "1_A_1/" "1_B_1/" "2_A_1/" "2_B_1/" "3_A_1/" "3_B_1/" "4_A_1/" "4_B_1/" "6_A_1/" "6_B_1/")

for i in "${!pattern[@]}"
	
	do
	temp=$((40+i)) 
       ./../analysis/PFMvaId_mB /eos/home-r/ratramon/BToKEE "$temp" "${pattern[$i]}" -10 -10
	done 

./../analysis/Sum_data ${#pattern[@]}
