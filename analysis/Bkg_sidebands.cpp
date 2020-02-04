#include "../interface/BParkTools.h"
#include "TTree.h"
#include <ROOT/RDataFrame.hxx>
#include <ROOT/RVec.hxx>
#include "TStopwatch.h"
#include <iostream>
#include <utility>
#include <vector>
#include <math.h>
#include <string>
#include "TH1.h"
#include "TH2.h"
#include "TMath.h"
#include "TFile.h"
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

	//--grab and initialize trees
//	TFile* file_sigMC = TFile::Open(argv[1]);
//	TFile* file_backMC = TFile::Open(argv[2]);
//	TFile* file_back = TFile::Open(argv[3]);
	TTree* EvTree = (TTree*)file_sigMC->Get("Tree");
	TTree* BG_MCTree = (TTree*)file_backMC->Get("Tree");
	TTree* BGTree = (TTree*)file_back->Get("BGTree");
	TChain* chain= new TChain("Events");
	std::cout << "Loading input files from: " << std::endl;
	std::cout << "/eos/cms/store/group/cmst3/group/bpark/BParkingNANO_2020Jan16/ParkingBPH1/crab_data_Run2018C_part1/200116_151112/0000/" << std::endl;
	if (in_files == 0 ){
	for(int file_idx=1;file_idx < 10; file_idx++){
	chain->Add(("/eos/cms/store/group/cmst3/group/bpark/BParkingNANO_2020Jan16/ParkingBPH1/crab_data_Run2018C_part1/200116_151112/0000/BParkNANO_data_2020Jan16_"+std::to_string(file_idx)+".root").c_str());
	}
	}else chain->Add(("/eos/cms/store/group/cmst3/group/bpark/BParkingNANO_2020Jan16/ParkingBPH1/crab_data_Run2018C_part1/200116_151112/0000/BParkNANO_data_2020Jan16_"+std::to_string(in_files)+"*.root").c_str());
	//TTree* EvTree = new TTree;
	//EvTree = mergeTrees(1,"/eos/home-r/ratramon/BuToKJpsiTomumu/BuToKJpsiTomumu");
	BElectronClass evt
	evt.Init(chain);
	setStyle();
	
	int i;


	for(i=0;i<evt.fChain->GetEntries();i++){
	fChain->GetEntry(i);
	


	}
}
