#include "../interface/BParkTools.h"
#include "TTree.h"
//#include <ROOT/RDataFrame.hxx>
//#include <ROOT/RVec.hxx>
//#include "TStopwatch.h"
#include <iostream>
#include <utility>
#include <vector>
#include <math.h>
#include <dirent.h>
#include <string>
#include <fstream>
#include "TH1.h"
#include "TH2.h"
#include "TMath.h"
#include "TFile.h"
#include "TList.h"
#include "TAxis.h"
#include "TTree.h"
#include "TLatex.h"
#include "TCanvas.h"
#include "TGraph.h"
#include "TGraphErrors.h"
#include "TStyle.h"
#include "TString.h"
#include "TLorentzVector.h"

int main(int argc, char **argv){
	
	int i, Nprocess;
	Nprocess = atoi(argv[1]);
	TH1D* mBres=0,*mBnores=0,*PfMvaId=0;
	TFile* fres[Nprocess], *fnores[Nprocess],*fPF[Nprocess];
	TList *res=0, *nores=0, *PF=0;
	for (i=0;i<Nprocess;i++){
		std::ifstream f1(("/afs/cern.ch/user/r/ratramon/Bparking/CMSSW_10_2_15/src/macros/newElectronPF/analysis/histos_"+std::to_string(i)+"mBres.root").c_str());
		std::ifstream f2(("/afs/cern.ch/user/r/ratramon/Bparking/CMSSW_10_2_15/src/macros/newElectronPF/analysis/histos_"+std::to_string(i)+"mBnores.root").c_str());
		std::ifstream f3(("/afs/cern.ch/user/r/ratramon/Bparking/CMSSW_10_2_15/src/macros/newElectronPF/analysis/histos_"+std::to_string(i)+"pfmvaId.root").c_str());
		if (!f1.good()) continue;
		std::cout  << "/afs/cern.ch/user/r/ratramon/Bparking/CMSSW_10_2_15/src/macros/newElectronPF/analysis/histos_"+std::to_string(i)+"mBres.root" << std::endl;
		fres[i] =TFile::Open(("/afs/cern.ch/user/r/ratramon/Bparking/CMSSW_10_2_15/src/macros/newElectronPF/analysis/histos_"+std::to_string(i)+"mBres.root").c_str());
		fnores[i] =TFile::Open(("/afs/cern.ch/user/r/ratramon/Bparking/CMSSW_10_2_15/src/macros/newElectronPF/analysis/histos_"+std::to_string(i)+"mBnores.root").c_str());
		fPF[i] =TFile::Open(("/afs/cern.ch/user/r/ratramon/Bparking/CMSSW_10_2_15/src/macros/newElectronPF/analysis/histos_"+std::to_string(i)+"pfmvaId.root").c_str());
		std::cout << "file pointer " << fres << std::endl;
		TH1D* temp = (TH1D*)fres[i]->Get("mBres");
		std::cout << "file pointer " << temp->GetEntries() << std::endl;
		res->Add(temp);
		nores->Add((TH1D*)fnores[i]->Get("mBnores"));
		PF->Add((TH1D*)fPF[i]->Get("pfmvaId"));
		

	fres[i]->Close();
	fnores[i]->Close();
	fPF[i]->Close();
	
	}

	delete fres;
	delete fnores;
	delete fPF;
	mBres->Merge(res);	
	mBnores->Merge(nores);	
	PfMvaId->Merge(PF);	
	SavePlot("M_{B}(GeV)",mBres,"newElectronPF/mB_cut_res",false, NULL,false);
	SavePlot("M_{B}(GeV)",mBnores,"newElectronPF/mB_cut_nores",false, NULL,false);
	SavePlot("PFmvaId",PfMvaId,"newElectronPF/mB_pfmvaId",false, NULL,false);
}
	
