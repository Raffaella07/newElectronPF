#include "TTree.h"
#include "../interface/BParkTools.h"
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


#define MUON_MASS 0.10565837
#define B_MASS  5.27925


int main(int argc, char** argv){

	//--grab and initialize trees
	TFile* file = TFile::Open(argv[1]);
	TTree* EvTree = (TTree*)file->Get("BGTree");
	std::cout << "Loading input files from: " << std::endl;
	
	//TFile* file = TFile::Open(argv[1]);
//	TTree* EvTree = (TTree*)chain->GetTree();
	//TTree* EvTree = new TTree;
	//EvTree = mergeTrees(1,"/eos/home-r/ratramon/BuToKJpsiTomumu/BuToKJpsiTomumu");
	BGElectronClass evt;
	evt.Init(EvtTree);
	setStyle();

	std::cout << "Successfully loaded: n entries" <<  evt.fChain->GetEntries() << std::endl;
	int i,j;
	TH1D* misEle_pt = new TH1D("pt misid electrons","pt misid electrons",50,0,50);
	TH1D* misEle_eta = new TH1D("eta misid electrons","eta misid electrons",50,-2.5,2.5);
	TH1D* misEle_pfmvaId = new TH1D("pfmvaid misid electrons","pfmvaid misid electrons",30,-11,8);

	

	for(i=0;i<evt.fChain->GetEntries();i++){
	evt.fChain->GetEntry(i);
	if(i%1000==0)std::cout << "Looping on entry" <<i <<  std::endl;
	//std::cout << "nMuon  in event" << evt.nMuon <<  std::endl;
/*	if (evt.nMuon == 4){
	
	//std::cout << "event with four muons" << std::endl;
	TLorentzVector Muon[evt.nMuon];
	double m_ll;
	std::pair <int, int> di_muon1, di_muon2;
	di_muon1 = std::make_pair(-1,-1);
	di_muon2 = std::make_pair(-1,-1);
		for (j=0;j<evt.nMuon;j++){
		Muon[j].SetPtEtaPhiM(evt.Muon_pt[j],evt.Muon_eta[j],evt.Muon_phi[j],MUON_MASS);	

		}
		
		for (j=0;j<evt.nMuon;j++){
			for (int k =j+1;k<evt.nMuon;k++){
			//std::cout << "looping on muons" << std::endl;
				if (evt.Muon_charge[j]*evt.Muon_charge[k] < 0 && k != j ){
					//std::cout << "opposite charge" << std::endl;
					if (Muon[k]*Muon[j] < B_MASS && ((di_muon1.first != k && di_muon1.second !=j) || (di_muon1.first != j && di_muon1.second !=k))){
					 di_muon1= std::make_pair(k,j);
					
			//		std::cout << "muon 1 indices" << k <<"__" << j <<  std::endl;
					break;
					}
					}
				}
		
			}
		for (j=0;j<evt.nMuon;j++){
			if (j == di_muon1.second ||j == di_muon1.first) continue;
			for (int k =j+1;k<evt.nMuon;k++){
				
				if (k == di_muon1.second ||k == di_muon1.first) continue;
				if (evt.Muon_charge[j]*evt.Muon_charge[k] < 0 && k != j ){
					if (Muon[k]*Muon[j] < B_MASS && ((di_muon2.first != k && di_muon2.second !=j) || (di_muon2.first != j && di_muon2.second !=k))){

	//			std::cout << "_________________________________________________muon 2 indices aasigned " <<  std::endl;
					di_muon2= std::make_pair(k,j);
					break;
					
					//std::cout << "di muon 1 indices  " << di_muon1.first <<"___" << di_muon1.second <<  std::endl;
					}
					}
				}
		
			}
		if (di_muon1.first == -1 || di_muon2.first == -1 || di_muon1.second == -1 || di_muon2.second == -1 ) continue;
		std::cout << "check pairs" << std::endl;
		std::cout << "di muon 1 indices  " << di_muon1.first <<"___" << di_muon1.second <<  std::endl;
		std::cout << "di muon 2 indices  " << di_muon2.first <<"___" << di_muon2.second <<  std::endl;
		std::cout << "---------------------------------------------nElectrons " << evt.nElectron << std::endl;*/
		for(j=0; j<evt.nElectrons; j++){
		if (evt.Ele_isPF[j]){
		misEle_pt->Fill(evt.Ele_pt[j]);	
		misEle_eta->Fill(evt.Ele_eta[j]);	
		misEle_pfmvaId->Fill(evt.Ele_pfmvaId[j]);	
		}
		}
	//	}
		
	}
	std::cout << "histo entries " << misEle_pt->GetEntries() << std::endl;
	SavePlot("p_{T}^{misEle}",misEle_pt,"newElectronPF/4Mu_Ele_pt",false, NULL,false);
	SavePlot("#eta^{misEle}",misEle_eta,"newElectronPF/4Mu_Ele_eta",false, NULL,false);
	SavePlot("PFmvaId",misEle_pfmvaId,"newElectronPF/4Mu_Ele_pfmvaId",false, NULL,false);
	
	
	return 0;
	}

