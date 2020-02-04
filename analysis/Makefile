CC = g++
CFLAGS = -Wall -c -g -fpermissive 

#ROOFIT_INCLUDE := $(shell cd $(CMSSW_BASE); scram tool info roofitcore | grep INCLUDE= | sed 's|INCLUDE=||')
#ROOFIT_LIBDIR := $(shell cd $(CMSSW_BASE); scram tool info roofitcore | grep LIBDIR= | sed 's|LIBDIR=||')

INCLUDES = -I. -I.. -I$(ROOTSYS)/include  -I../interface/  # -I../../CommonTools/ -I../../CommonTools/interface/ -I$(ROOFIT_INCLUDE)/ C-I$(CMSSW_BASE)/src -I$(CMSSW_BASE)/src/NanoUVCommonTools  

ROOTSYS ?= ERROR_RootSysIsNotDefined

ROOTFLAG = `${ROOTSYS}/bin/root-config --cflags --libs`

EXTRALIBS := -L$(ROOTSYS)/lib -lHtml -lMathCore -lGenVector -lMinuit -lTreePlayer -lRooFitCore -lRooFit #-L$(ROOFIT_LIBDIR)/ 


SglBkgAnalysis: Signal_Analysis.cpp BParkTools.o BElectronsClass.o BElectronsClassMC.o BGElectronClass.o BSignalElectronClass.o BNanoClass.o
	$(CC) -Wall $(INCLUDES) -o SglBkgAnalysis Signal_Analysis.cpp BParkTools.o  BElectronsClass.o BElectronsClassMC.o BGElectronClass.o BSignalElectronClass.o BNanoClass.o $(ROOTFLAG) $(EXTRALIBS)

ElectronEff: ElectronEff.cpp BParkTools.o BParkTools.o BElectronsClass.o BElectronsClassMC.o BGElectronClass.o BSignalElectronClass.o BNanoClass.o
	$(CC) -Wall $(INCLUDES) -o ElectronEff ElectronEff.cpp BParkTools.o BElectronsClass.o BElectronsClassMC.o BGElectronClass.o BSignalElectronClass.o BNanoClass.o $(ROOTFLAG) $(EXTRALIBS)

ElectronEff_old: newElectronPFefficiency.cpp BParkTools.o BElectronsClass.o BElectronsClassMC.o BGElectronClass.o BSignalElectronClass.o BNanoClass.o
	$(CC) -Wall $(INCLUDES) -o ElectronEff_old newElectronPFefficiency.cpp BParkTools.o BElectronsClass.o BElectronsClassMC.o BGElectronClass.o BSignalElectronClass.o BNanoClass.o $(ROOTFLAG) $(EXTRALIBS)

ElectronBkg: Electron_background.cpp BParkTools.o BElectronsClass.o BElectronsClassMC.o BGElectronClass.o BSignalElectronClass.o BNanoClass.o
	$(CC) -Wall $(INCLUDES) -o ElectronBkg Electron_background.cpp BParkTools.o BElectronsClass.o BElectronsClassMC.o BGElectronClass.o BSignalElectronClass.o BNanoClass.o $(ROOTFLAG) $(EXTRALIBS)

SkimMC: skimmed_ntuples.cpp BParkTools.o BElectronsClass.o BElectronsClassMC.o BGElectronClass.o BSignalElectronClass.o BNanoClass.o
	$(CC) -Wall $(INCLUDES) -o SkimMC skimmed_ntuples.cpp BParkTools.o BElectronsClass.o BElectronsClassMC.o BGElectronClass.o BSignalElectronClass.o BNanoClass.o $(ROOTFLAG) $(EXTRALIBS)

SkimData_bkg: Skim_eleback.cpp BParkTools.o BElectronsClass.o BElectronsClassMC.o BGElectronClass.o BSignalElectronClass.o BNanoClass.o
	$(CC) -Wall $(INCLUDES) -o SkimData_bkg: Skim_eleback.cpp BParkTools.o BElectronsClass.o BElectronsClassMC.o BGElectronClass.o BSignalElectronClass.o BNanoClass.o $(ROOTFLAG) $(EXTRALIBS)

BkgAnalysis: Background_analysis.cpp BParkTools.o BElectronsClass.o BElectronsClassMC.o BGElectronClass.o BSignalElectronClass.o BNanoClass.o
	$(CC) -Wall $(INCLUDES) -o BkgAnalysis: Background_analysis.cpp BParkTools.o BElectronsClass.o BElectronsClassMC.o BGElectronClass.o BSignalElectronClass.o BNanoClass.o $(ROOTFLAG) $(EXTRALIBS)



BParkTools.o: ../../newElectronPF/src/BParkTools.cc BElectronsClass.o BElectronsClassMC.o BGElectronClass.o BSignalElectronClass.o BNanoClass.o
	$(CC) -Wall $(INCLUDES) -c  ../../newElectronPF/src/BParkTools.cc BElectronsClass.o BElectronsClassMC.o BGElectronClass.o BSignalElectronClass.o BNanoClass.o $(ROOTFLAG) $(EXTRALIBS)

BElectronsClass.o: ../../newElectronPF/src/BElectronsClass.cc
	$(CC) -Wall $(INCLUDES) -c ../../newElectronPF/src/BElectronsClass.cc $(ROOTFLAG) $(EXTRALIBS)

BElectronsClassMC.o: ../../newElectronPF/src/BElectronsClassMC.cc
	$(CC) -Wall $(INCLUDES) -c  ../../newElectronPF/src/BElectronsClassMC.cc $(ROOTFLAG) $(EXTRALIBS)

BGElectronClass.o: ../../newElectronPF/src/BGElectronClass.cc
	$(CC) -Wall $(INCLUDES) -c ../../newElectronPF/src/BGElectronClass.cc $(ROOTFLAG) $(EXTRALIBS)

BSignalElectronClass.o: ../../newElectronPF/src/BSignalElectronClass.cc
	$(CC) -Wall $(INCLUDES) -c  ../../newElectronPF/src/BSignalElectronClass.cc $(ROOTFLAG) $(EXTRALIBS)

BNanoClass.o: ../../newElectronPF/src/BNanoClass.cc
	$(CC) -Wall $(INCLUDES) -c ../../newElectronPF/src/BNanoClass.cc $(ROOTFLAG) $(EXTRALIBS)
clean:
	rm *.o BParkTools.o
