#include "TTree.h"
#include "../interface/BParkTools.h"
//#include <ROOT/RDataFrame.hxx>
//#include <ROOT/RVec.hxx>
//#include "TStopwatch.h"
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


int main(int argc, char **argv){

	//--grab and initialize trees
	TFile* file = TFile::Open(argv[1]);
	TTree* EvTree = (TTree*)file->Get("Events");
	//TTree* EvTree = new TTree;
	//EvTree = mergeTrees(1,"/eos/home-r/ratramon/BuToKJpsiTomumu/BuToKJpsiTomumu");
	BNanoClass evt;
	evt.Init(EvTree);
	setStyle();

	
	TH1D* m_mumu = new TH1D("invariant m_mumu","invariant m_mumu",80,0,6);
//	TH1D* mB = new TH1D("invariant m_B","invariant m_B",80,3,7);
	std::cout << "Successfully loaded: n entries" <<  evt.fChain->GetEntries() << std::endl;
	int i,j, entry, nElectrons,nMuon, Ntot,Nsel;
	double  event;
	Ntot =0;
	Nsel =0;

	for(i=0;i<evt.fChain->GetEntries();i++){
	evt.fChain->GetEntry(i);
	if(i%1000==0)std::cout << "Looping on entry" <<i <<  std::endl;
	TLorentzVector Muon[evt.nMuon];
	double m_ll;
	std::pair <int, int> di_muon1, di_muon2;
	//std::cout << "nMuon  in event" << evt.nMuon <<  std::endl;
	if (evt.nMuon == 4){
	di_muon1 = std::make_pair(-1,-1);
	di_muon2 = std::make_pair(-1,-1);
	
	//std::cout << "event with four muons" << std::endl;
		for (j=0;j<evt.nMuon;j++){
		Muon[j].SetPtEtaPhiM(evt.Muon_pt[j],evt.Muon_eta[j],evt.Muon_phi[j],MUON_MASS);	

		}
		
		for (j=0;j<evt.nMuon;j++){
			for (int k =j+1;k<evt.nMuon;k++){
			//std::cout << "looping on muons" << std::endl;
				if (evt.Muon_charge[j]*evt.Muon_charge[k] < 0 && k != j  && evt.Muon_isPFcand[j] &&  evt.Muon_isPFcand[k]){
				
					//std::cout << "opposite charge" << std::endl;
					if ((Muon[k]+Muon[j]).Mag() < B_MASS && ((di_muon1.first != k && di_muon1.second !=j) || (di_muon1.first != j && di_muon1.second !=k))){
					di_muon1= std::make_pair(k,j);
			//		std::cout << "muon 1 indices" << k <<"__" << j << "invariant mass" <<  Muon[k]*Muon[j] <<  std::endl;
					break;
					}
					}
				}
		
			}
		
		for (j=0;j<evt.nMuon;j++){
			if (j == di_muon1.second ||j == di_muon1.first) continue;
			for (int k =j+1;k<evt.nMuon;k++){
				
				if (k == di_muon1.second ||k == di_muon1.first) continue;
				if (evt.Muon_charge[j]*evt.Muon_charge[k] < 0 && k != j && evt.Muon_isPFcand[j] &&  evt.Muon_isPFcand[k]){
					if ((Muon[k]+Muon[j]).Mag() < B_MASS && ((di_muon2.first != k && di_muon2.second !=j) || (di_muon2.first != j && di_muon2.second !=k))){

	//			std::cout << "_________________________________________________muon 2 indices aasigned " <<  std::endl;
					di_muon2= std::make_pair(k,j);
			//		std::cout << "muon 2 indices" << k <<"__" << j << "invariant mass" <<  Muon[k]*Muon[j] <<  std::endl;
					break;
					
					}
					}
				}
		
			}
		if (di_muon1.first == -1 || di_muon2.first == -1 || di_muon1.second == -1 || di_muon2.second == -1 ) continue;
		
		TLorentzVector Muon_sel[4];

		Muon_sel[0].SetPtEtaPhiM(evt.Muon_pt[di_muon1.first],evt.Muon_eta[di_muon1.first],evt.Muon_phi[di_muon1.first],MUON_MASS);	
		Muon_sel[1].SetPtEtaPhiM(evt.Muon_pt[di_muon1.second],evt.Muon_eta[di_muon1.second],evt.Muon_phi[di_muon1.second],MUON_MASS);	
		Muon_sel[2].SetPtEtaPhiM(evt.Muon_pt[di_muon2.first],evt.Muon_eta[di_muon2.first],evt.Muon_phi[di_muon2.first],MUON_MASS);	
		Muon_sel[3].SetPtEtaPhiM(evt.Muon_pt[di_muon2.second],evt.Muon_eta[di_muon2.second],evt.Muon_phi[di_muon2.second],MUON_MASS);	
		
		if (evt.Muon_charge[di_muon1.first]*evt.Muon_charge[di_muon2.first]<0){	
			
		if ((Muon_sel[0]+Muon_sel[1]).Mag()>(Muon_sel[0]+Muon_sel[2]).Mag()){
		m_mumu->Fill((Muon_sel[0]+Muon_sel[2]).Mag());			
		int temp;
		temp = di_muon1.second;			
		di_muon1.second = di_muon2.first;
		di_muon2.first = temp;
		}else m_mumu->Fill((Muon_sel[0]+Muon_sel[1]).Mag());		
	}	
		else if (evt.Muon_charge[di_muon1.first]*evt.Muon_charge[di_muon2.second]<0){	
		if ((Muon_sel[0]+Muon_sel[1]).Mag()>(Muon_sel[0]+Muon_sel[3]).Mag()){
		m_mumu->Fill((Muon_sel[0]+Muon_sel[3]).Mag());
		int temp;
		temp = di_muon1.second;			
		di_muon1.second = di_muon2.second;
		di_muon2.second = temp;
		}else m_mumu->Fill((Muon_sel[2]+Muon_sel[3]).Mag());
	
			

	}

	std::cout << "di lepton selected pairs " << std::endl;
	std::cout << "1 indices: " << di_muon1.first << " " << di_muon1.second << std::endl;
	std::cout << "2 indices: " << di_muon2.first << " " << di_muon2.second << std::endl;

	if (evt.Muon_genPartIdx[di_muon1.first] != -1  && evt.Muon_genPartIdx[di_muon1.second] != -1){ {
	 Ntot++;
	if (fabs(evt.GenPart_pdgId[evt.Muon_genPartIdx[di_muon1.first]]) == 13 && fabs(evt.GenPart_pdgId[evt.Muon_genPartIdx[di_muon1.second]]) == 13 && evt.GenPart_genPartIdxMother[evt.Muon_genPartIdx[di_muon1.first]] == evt.GenPart_genPartIdxMother[evt.Muon_genPartIdx[di_muon1.second]]) Nsel++;}

	if( evt.Muon_genPartIdx[di_muon2.first] != -1  && evt.Muon_genPartIdx[di_muon2.second] != -1){	
	Ntot++;
	if (fabs(evt.GenPart_pdgId[evt.Muon_genPartIdx[di_muon2.first]]) == 13 && fabs(evt.GenPart_pdgId[evt.Muon_genPartIdx[di_muon2.second]]) == 13 && evt.GenPart_genPartIdxMother[evt.Muon_genPartIdx[di_muon2.first]] == evt.GenPart_genPartIdxMother[evt.Muon_genPartIdx[di_muon2.second]]) Nsel++;
		}
	}

	
	//std::cout << "gen section " << std::endl;


	}

	}

	std::cout <<" loops ended  " << Nsel <<std::endl;
	std::cout << "di-lepton selection efficiency " << (double)Nsel/Ntot << std::endl;
	return 0;
}
