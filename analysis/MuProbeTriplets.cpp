#include "../interface/BParkTools.h"
//#include <ROOT/RDataFrame.hxx>
//#include <ROOT/RVec.hxx>
//#include "TStopwatch.h"
#include <iostream>
#include <fstream>
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
	//--grab and initialize trees
	std::string inputfile = argv[1];
	int input_idx= std::atoi(argv[2]);
	std::cout << "input idx " << input_idx <<  std::endl;
	//initialize input chain
	TChain* chain= new TChain("Events");
	std::ifstream infile;
	infile.open(inputfile.c_str());	
	bool isMC;
	if(infile.fail()) // checks to see if file opended 
	{ 
		std::cout << "error" << std::endl; 
		return 1; // no point continuing if the file didn't open...
	}
	std::cout << "Loading input from /eos/cms/store/group/cmst3/group/bpark/BParkingNANO_2020Jan16/" << std::endl;
	int counter =0; 
	std::string line;
	while(std::getline(infile, line)) // reads file to end of *file*, not line
	{ 	bool temp;
		if (counter ==0)
		{
			//	infile >> temp; // read first column number
			isMC = atoi(line.c_str()); //first line of file contains flag for mc/data 
			std::cout << isMC << std::endl;
		}

		else{
			//	infile >> file; // read first column number
			if (counter == input_idx+1){
				chain->Add(line.c_str());
				std::cout << line << std::endl;
				break;
			}
		}
		counter++;


	}
	if (isMC)std::cout <<" analyzing Montecarlo dataset: " << inputfile << std::endl;
	else std::cout <<"analyzing dataset: " << inputfile << std::endl;
	std::cout << "loaded file number " << counter << " as input:  " << line  << std::endl;
	//chain->Add((INPUTDIR+"BParkNANO_mc_2020Jan16_*.root").c_str());
	TFile* outfile = new TFile(argv[3],"RECREATE");
	TTree SkimBGTree("Tree", "A skimmed tree with useful variables for electrons in 4mu events");
	int i;

	BNanoClass evt;
	evt.Init(chain);
	setStyle();
	TH1D* mB = new TH1D("invariant m_B","invariant m_B",80,4,7);
	
	int j, entry, nElectrons,nMuon;
	double  event;
	int Muon_idx[200],Muon_isTriggering[200],Muon_pt[200];
	float Ele_pt[200],Ele_eta[200],Ele_phi[200],Ele_pfmvaId[200],DiMuon_mass[2],DiMuon_dVtx[2],DiMuon_ToP[2],B_mass[2];
	bool Ele_isPF[200];


	for (i=0;i<200;i++){
		Ele_pt[i] =0;
		Ele_eta[i] =0;
		Ele_phi[i] =0;
		Ele_pfmvaId[i] =0;
		Ele_isPF[i] =0;
		Muon_idx[i]=0;

	}
	SkimBGTree.Branch("entry", &entry);
	SkimBGTree.Branch("event", &event);
	SkimBGTree.Branch("nMuon", &nMuon);
	//SkimBGTree.Branch("nMatchedBToKMuMu", &nMatchedBToKMuMu);
	SkimBGTree.Branch("Muon_idx", Muon_idx,"Muon_idx[nMuon]/I");
	SkimBGTree.Branch("Muon_isTriggering", Muon_isTriggering,"Muon_isTriggering[nMuon]/I");
	SkimBGTree.Branch("Muon_pt", Muon_pt,"Muon_pt[nMuon]/I");
	SkimBGTree.Branch("DiMuon_mass", DiMuon_mass,"DiMuon_mass[2]/F");
	SkimBGTree.Branch("DiMuon_ToP", DiMuon_ToP,"DiMuon_ToP[2]/F");
	SkimBGTree.Branch("DiMuon_dVtx", DiMuon_dVtx,"DiMuon_dVtx[2]/F");
	SkimBGTree.Branch("B_mass", B_mass,"B_mass[2]/F");
	SkimBGTree.Branch("nElectrons", &nElectrons);
	SkimBGTree.Branch("Ele_pt", Ele_pt,"Ele_pt[nElectrons]/F");
	SkimBGTree.Branch("Ele_eta", Ele_eta,"Ele_eta[nElectrons]/F");
	SkimBGTree.Branch("Ele_phi", Ele_phi,"Ele_phi[nElectrons]/F");
	SkimBGTree.Branch("Ele_pfmvaId", Ele_pfmvaId,"Ele_pfmvaId[nElectrons]/F");
	SkimBGTree.Branch("Ele_isPF", Ele_isPF,"Ele_isPF[nElectrons]/O");
	
	int ncand;	
	for(i=0;i<evt.fChain->GetEntries();i++){

		evt.fChain->GetEntry(i);
		if (i%10000 ==0)std::cout << "Looping on entry" <<i <<  std::endl;
		//std::cout << "nMuon  in event" << evt.nMuon <<  std::endl;
		if (evt.nMuon == 4  ){
		if (evt.Muon_isPFcand[0]==1 && evt.Muon_isPFcand[1]==1 && evt.Muon_isPFcand[2]==1 && evt.Muon_isPFcand[3]==1  ) ncand++;
		std::vector<int> combinations;
		//std::cout << "nBToKMuMu" << evt.nBToKMuMu<<  std::endl;
		for(int k=0; k<evt.nBToKMuMu;k++){
			if (evt.Muon_isPFcand[evt.BToKMuMu_l1Idx[k]]==0  || evt.Muon_isPFcand[evt.BToKMuMu_l2Idx[k]]==0 /* evt.Muon_pt[evt.BToKMuMu_l1Idx[k]]<1 || evt.Muon_pt[evt.BToKMuMu_l2Idx[k]]<1 || evt.BToKMuMu_fit_k_pt[k]<1 ||*/ ) continue;
			if (evt.Muon_isTriggering[evt.BToKMuMu_l1Idx[k]]+evt.Muon_isTriggering[evt.BToKMuMu_l2Idx[k]]==0 && (evt.BToKMuMu_fit_pt[k]<3 ||  evt.BToKMuMu_fit_mass[k]>6 || evt.BToKMuMu_fit_mass[k]<4.7 || evt.BToKMuMu_l_xy[k]/evt.BToKMuMu_l_xy_unc[k]<1 || evt.BToKMuMu_cos2D[k]<0.99 || evt.BToKMuMu_svprob[k]<0.001|| evt.Muon_pt[evt.BToKMuMu_l2Idx[k]]<1 || evt.Muon_pt[evt.BToKMuMu_l1Idx[k]]<1))continue;
			std::cout << "index c " << k << "first lepton " << evt.BToKMuMu_l1Idx[k] << "second lepton " << evt.BToKMuMu_l2Idx[k]  << std::endl;
			bool matched =false;
			for (int c =0; c<combinations.size();c++){
				if ((evt.BToKMuMu_l1Idx[k]==evt.BToKMuMu_l1Idx[combinations[c]]) || evt.BToKMuMu_l2Idx[k]==evt.BToKMuMu_l2Idx[combinations[c]] || evt.BToKMuMu_l1Idx[k]==evt.BToKMuMu_l2Idx[combinations[c]] || evt.BToKMuMu_l2Idx[k]==evt.BToKMuMu_l1Idx[combinations[c]]) matched = true;
				
				}
			if (matched) continue;
			
			std::pair <int,int> ll;
			ll.first = evt.BToKMuMu_l1Idx[k];
			ll.second = evt.BToKMuMu_l2Idx[k];
			double min = evt.BToKMuMu_svprob[k]; 
			int best = k;
			for( j=k+1; j<evt.nBToKMuMu;j++){
			if (evt.Muon_isPFcand[evt.BToKMuMu_l1Idx[j]]==0 || evt.Muon_isPFcand[evt.BToKMuMu_l2Idx[j]]==0 /*|| evt.Muon_pt[evt.BToKMuMu_l1Idx[j]]<1 || evt.Muon_pt[evt.BToKMuMu_l2Idx[j]]<1 || evt.BToKMuMu_fit_k_pt[j]<1 */|| evt.BToKMuMu_fit_pt[j]<3/* ||  evt.BToKMuMu_fit_mass[j]>6 || evt.BToKMuMu_fit_mass[j]<4.7 || evt.BToKMuMu_l_xy[j]/evt.BToKMuMu_l_xy_unc[j]<0.5 || evt.BToKMuMu_cos2D[j]<0.99*/ || evt.BToKMuMu_svprob[j]<0.001) continue;
			if (evt.Muon_isTriggering[evt.BToKMuMu_l1Idx[j]]+evt.Muon_isTriggering[evt.BToKMuMu_l2Idx[j]]==0 && (evt.BToKMuMu_fit_pt[k]<3 ||  evt.BToKMuMu_fit_mass[k]>6 || evt.BToKMuMu_fit_mass[k]<4.7 || evt.BToKMuMu_l_xy[k]/evt.BToKMuMu_l_xy_unc[k]<1 || evt.BToKMuMu_cos2D[k]<0.99 || evt.BToKMuMu_svprob[k]<0.001 && evt.Muon_pt[evt.BToKMuMu_l2Idx[j]]<1 || evt.Muon_pt[evt.BToKMuMu_l1Idx[j]]<1))continue;
				if ( (ll.first == evt.BToKMuMu_l1Idx[j] &&  ll.second == evt.BToKMuMu_l2Idx[j]) || (ll.second == evt.BToKMuMu_l1Idx[j] &&  ll.first == evt.BToKMuMu_l2Idx[j])){
					if (evt.BToKMuMu_svprob[j]>min){
					best = j;
					min= evt.BToKMuMu_svprob[j];
					std::cout << "cand svprob" << min  <<  std::endl;

					}

				}
			

		}
		std::cout << "best " << best << std::endl;	
		combinations.push_back(best);
		}
		
			if(combinations.size()>1){
			for (int c =0; c<combinations.size();c++){
			if(evt.BToKMuMu_mll_fullfit[combinations[c]]>3 && evt.BToKMuMu_mll_fullfit[combinations[c]]<3.15 && evt.Muon_isTriggering[evt.BToKMuMu_l1Idx[combinations[c]]]==0 &&evt.Muon_isTriggering[evt.BToKMuMu_l2Idx[combinations[c]]]==0 )mB->Fill(evt.BToKMuMu_fit_mass[combinations[c]]);
			std::cout << "_________________________________________index c " << i << "first lepton " << evt.BToKMuMu_l1Idx[combinations[c]] << "second lepton " << evt.BToKMuMu_l2Idx[combinations[c]] << " sv prob " << evt.BToKMuMu_fit_mass[combinations[c]] <<"triggers " <<  evt.Muon_isPFcand[evt.BToKMuMu_l1Idx[combinations[c]]] << " " << evt.Muon_isPFcand[evt.BToKMuMu_l2Idx[combinations[c]]] << std::endl;

			}
		
	
			std::pair<int, int> di_muon1,di_muon2;
			
			di_muon1 = std::make_pair(evt.BToKMuMu_l1Idx[combinations[0]],evt.BToKMuMu_l2Idx[combinations[0]]);
			di_muon2 = std::make_pair(evt.BToKMuMu_l1Idx[combinations[1]],evt.BToKMuMu_l2Idx[combinations[1]]);
		
			TLorentzVector Muon_sel[4];
		
			Muon_sel[0].SetPtEtaPhiM(evt.Muon_pt[di_muon1.first],evt.Muon_eta[di_muon1.first],evt.Muon_phi[di_muon1.first],MUON_MASS);	
			Muon_sel[1].SetPtEtaPhiM(evt.Muon_pt[di_muon1.second],evt.Muon_eta[di_muon1.second],evt.Muon_phi[di_muon1.second],MUON_MASS);	
			Muon_sel[2].SetPtEtaPhiM(evt.Muon_pt[di_muon2.first],evt.Muon_eta[di_muon2.first],evt.Muon_phi[di_muon2.first],MUON_MASS);	
			Muon_sel[3].SetPtEtaPhiM(evt.Muon_pt[di_muon2.second],evt.Muon_eta[di_muon2.second],evt.Muon_phi[di_muon2.second],MUON_MASS);	
			nElectrons = evt.nElectron;
			nMuon = evt.nMuon;
			entry = i;
			event = evt.event;
	//		nMatchedBToKMuMu = counter;
			DiMuon_mass[0]=(Muon_sel[0]+Muon_sel[1]).Mag();
			DiMuon_mass[1]=(Muon_sel[2]+Muon_sel[3]).Mag();
			DiMuon_ToP[0]=evt.Muon_isTriggering[di_muon1.first]+evt.Muon_isTriggering[di_muon1.second];
			DiMuon_ToP[1]=evt.Muon_isTriggering[di_muon2.first]+evt.Muon_isTriggering[di_muon2.second];
			B_mass[0]=evt.BToKMuMu_fit_mass[combinations[0]];
			B_mass[1]=evt.BToKMuMu_fit_mass[combinations[1]];;
			DiMuon_dVtx[0]= sqrt(pow((evt.Muon_vx[di_muon1.first]-evt.Muon_vx[di_muon1.second]),2)+pow((evt.Muon_vy[di_muon1.first]-evt.Muon_vy[di_muon1.second]),2)+pow((evt.Muon_vz[di_muon1.first]-evt.Muon_vz[di_muon1.second]),2));

			DiMuon_dVtx[1]= sqrt(pow((evt.Muon_vx[di_muon2.first]-evt.Muon_vx[di_muon2.second]),2)+pow((evt.Muon_vy[di_muon2.first]-evt.Muon_vy[di_muon2.second]),2)+pow((evt.Muon_vz[di_muon2.first]-evt.Muon_vz[di_muon2.second]),2));
			Muon_idx[0]=di_muon1.first;
			Muon_idx[1]=di_muon1.second;
			Muon_idx[2]=di_muon2.first;
			Muon_idx[3]=di_muon2.second;
			Muon_isTriggering[0]=evt.Muon_isTriggering[di_muon1.first];
			Muon_isTriggering[1]=evt.Muon_isTriggering[di_muon1.second];
			Muon_isTriggering[2]=evt.Muon_isTriggering[di_muon2.first];
			Muon_isTriggering[3]=evt.Muon_isTriggering[di_muon2.second];
			Muon_pt[0]=evt.Muon_pt[di_muon1.first];
			Muon_pt[1]=evt.Muon_pt[di_muon1.second];
			Muon_pt[2]=evt.Muon_pt[di_muon2.first];
			Muon_pt[3]=evt.Muon_pt[di_muon2.second];

			for(int f=0;f<evt.nElectron; f++){
				if(nElectrons>200) break;
				//		std::cout << "---------------------------------------------Electronpt " << evt.Electron_pt[f] << std::endl;
				if(evt.Electron_isPF[f]){
				Ele_pt[f] = evt.Electron_pt[f];
				Ele_eta[f]=evt.Electron_eta[f];
				Ele_phi[f]=evt.Electron_phi[f];
				Ele_pfmvaId[f]= evt.Electron_pfmvaId[f];
				Ele_isPF[f]=evt.Electron_isPF[f];
				//	Ele_eta = evt.Electron_eta;
				//	Ele_phi = evt.Electron_phi;
				//	Ele_pfmvaId = evt.Electron_pfmvaId;
				//	Ele_isPF = evt.Electron_isPF;
				//		std::cout << "---------------------------------------------Electronpttrans " << Ele_pt[f] << std::endl;
			}
			}
			//
			SkimBGTree.Fill();

		}
		}
	}
	std::cout << "denominator " << ncand << std::endl;
	SavePlot("M_{B}(GeV)",mB,"newElectronPF/m_Btrip",false, NULL,false);
	std::cout << "mB entries " << mB->GetEntries() << std::endl;
	outfile->Write();
	outfile->Close();	
	}
