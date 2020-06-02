#!/bin/bash
export SCRAM_ARCH=slc7_amd64_gcc700
cd /afs/cern.ch/work/r/ratramon/Bparking/CMSSW_10_2_15/src/
eval `scramv1 runtime -sh`
echo $PWD
cd macros/newElectronPF/condor
python /afs/cern.ch/work/r/ratramon/Bparking/CMSSW_10_2_15/src/macros/newElectronPF/condor/AllData_batch.py

declare -a part1=( 1 2 3 4 5 6 )
declare -a part2=( 1 2 3 4 5 )
declare -a set=( A B C  )
declare -a cat1=( 0 1 )
declare -a cat2=( 0 1 2 3 4 5 )
	for i in "${set[@]}"

		do
			if [ $i == "A" ] || [ $i == "B" ] 
			then
		 		for k in "${part1[@]}"
					do
					for j in "${cat1[@]}"
	
						do
		 				condor_submit skim_part."$k"_"$i"_"$j".condor

						done 
					done
				
			elif [ $i == "C" ]
			then
		 		for k in "${part2[@]}"
					do
					for j in "${cat1[@]}"
	
						do
		 				condor_submit skim_part."$k"_"$i"_"$j".condor

						done 
					done
			else
		 		for k in "${part2[@]}"
					do
					for j in "${cat2[@]}"
	
						do
		 				condor_submit skim_part."$k"_"$i"_"$j".condor

						done 
					done
			fi	
	done
#condor_submit skim_part.[1-4]_[A,B]_[0,1].condor

#rm skim_part.*.condor

