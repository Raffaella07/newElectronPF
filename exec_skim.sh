
#!/bin/bash
export i=$1
eval `scram runtime -sh`
. /cvmfs/sft.cern.ch/lcg/app/releases/ROOT/6.18.02/x86_64-centos7-gcc48-opt/bin/thisroot.sh
g++  Skim_eleback.cpp -o  skim_eleback.exe `root-config --cflags --glibs`
./skim_eleback.exe "$i" skimmed_ntuples/skimmedNANO_BPark_data_EleBG_"$i"_2020Jan16.root
