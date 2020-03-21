#include "../interface/BParkTools.h"
#include <bits/stdc++.h> 
#include <iostream>
#include <sys/types.h>
#include <sys/stat.h>

#include <utility>
#include <stdio.h>
#include <vector>
#include <math.h>
#include <string>
#include <unistd.h>
#include <dirent.h>
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

	int in_part = std::atoi(argv[1]); // Part of dataset analyzed(1,2,3,4)
	int in_dir = std::atoi(argv[3]); // lable of analysed subdirectory in Part_Letter dataset 0,1,2,3,4,5
	std::string in_letter= argv[2]; // Letter label for dataset analyzed A,B,C,D
	int in_files = std::atoi(argv[4]);// file index
	
	bool isMC=false;
	
	std::string INPUTDIR;
	std::cout << "Loading input files from: " << std::endl;
	//initializes path of input directory 
	INPUTDIR = "/eos/cms/store/group/cmst3/group/bpark/BParkingNANO_2020Jan16/ParkingBPH"+std::to_string(in_part)+"/crab_data_Run2018"+std::string(in_letter)+"_part"+std::to_string(in_part);

	//searches for input directory complete path
	DIR* Dir=NULL;
	std::string d_name;;
	struct dirent *dir_entry;
	Dir = opendir(INPUTDIR.c_str());
	while(dir_entry=readdir(Dir))
	{
		std::cout << dir_entry->d_name << std::endl;
		d_name = dir_entry->d_name;
	}

	INPUTDIR = "/eos/cms/store/group/cmst3/group/bpark/BParkingNANO_2020Jan16/ParkingBPH"+std::to_string(in_part)+"/crab_data_Run2018"+std::string(in_letter)+"_part"+std::to_string(in_part)+"/"+d_name+"/000"+std::to_string(in_dir);

	std::cout <<  INPUTDIR << std::endl;
	int file_exists;
	//initialize input chain
	TChain* chain= new TChain("Events");

	//adds file to the chain 
	//file index for each in_dir goes from (in_dir)000 to (in_dir)999 i.e in_dir == 1 : file index in [1000;1999]
	if (in_dir ==0)file_exists = chain->Add((INPUTDIR+"/BParkNANO_data_2020Jan16_"+std::to_string(in_files)+".root").c_str());
//	if (in_dir ==0)file_exists = chain->Add("/eos/cms/store/group/cmst3/group/bpark/BParkingNANO_2020Jan16/BuToKJpsi_Toee_Mufilter_SoftQCDnonD_TuneCP5_13TeV-pythia8-evtgen/crab_BuToKJpsi_Toee/200116_215618/0000/BParkNANO_mc_2020Jan16_2.root");

	else if (in_dir ==1)file_exists = chain->Add((INPUTDIR+"/BParkNANO_data_2020Jan16_"+std::to_string(1000+in_files)+".root").c_str());
	else if (in_dir ==2)file_exists = chain->Add((INPUTDIR+"/BParkNANO_data_2020Jan16_"+std::to_string(2000+in_files)+".root").c_str());

	else if (in_dir ==3)file_exists = chain->Add((INPUTDIR+"/BParkNANO_data_2020Jan16_"+std::to_string(3000+in_files)+".root").c_str());

	else if (in_dir ==4)file_exists = chain->Add((INPUTDIR+"/BParkNANO_data_2020Jan16_"+std::to_string(4000+in_files)+".root").c_str());

	else if (in_dir ==5)file_exists = chain->Add((INPUTDIR+"/BParkNANO_data_2020Jan16_"+std::to_string(5000+in_files)+".root").c_str());

	if (file_exists ==0 ){ //file does not exist- exit

		std::cout << "The file  " <<  INPUTDIR << "/BParkNANO_data_2020Jan16_"  << std::to_string(in_files) <<".root" <<"does not exist" << std::endl;
		return 0;
	}
	chdir(" /afs/cern.ch/user/r/ratramon/Bparking/CMSSW_10_2_15/src/macros/newElectronPF/analysis");
	TFile* outfile = TFile::Open(argv[5],"RECREATE");
	std::cout <<  outfile << std::endl;
	TTree SkimTree("Tree", "A skimmed tree containing one selected nBToKEE event");


	BNanoClass evt;
	evt.Init(chain);

	//Event variables
	int entry, event;
	int iHLT_Mu12_IP6, iHLT_Mu9_IP6;

	//BToKEE fitted variables 
	bool BToKEE_isMC;

	float  BToKEE_charge,BToKEE_pdgId, BToKEE_chi2,BToKEE_cos2D,BToKEE_eta   ,BToKEE_fit_cos2D,BToKEE_fit_eta   ,BToKEE_fit_k_eta,BToKEE_fit_k_phi,
	BToKEE_fit_k_pt ,BToKEE_fit_l1_eta,BToKEE_fit_l1_phi,BToKEE_fit_l1_pt ,BToKEE_fit_l2_eta,BToKEE_fit_l2_phi,BToKEE_fit_l2_pt,BToKEE_fit_mass  ,BToKEE_fit_massErr,BToKEE_fit_phi  ,BToKEE_fit_pt,
	BToKEE_l_xy   ,BToKEE_l_xy_unc,BToKEE_mass   ,BToKEE_maxDR ,BToKEE_minDR  ,BToKEE_mllErr_llfit,BToKEE_mll_fullfit,BToKEE_mll_llfit  ,BToKEE_mll_raw,BToKEE_phi  ,BToKEE_pt,BToKEE_svprob,
	BToKEE_vtx_ex,BToKEE_vtx_ey,BToKEE_vtx_ez,BToKEE_vtx_x,BToKEE_vtx_y  ,BToKEE_vtx_z;  

	//Reco collections variables:
	//Kinematics
	float BToKEE_l1_pt,BToKEE_l2_pt,BToKEE_l1_eta,BToKEE_l2_eta,BToKEE_l1_phi,BToKEE_l2_phi, BToKEE_k_pt, BToKEE_k_eta, BToKEE_k_phi;

	//electrons categories flags & Ids
	bool  BToKEE_l1_isPF, BToKEE_l2_isPF,BToKEE_l1_isLowPt, BToKEE_l2_isLowPt, BToKEE_l1_isPFoverlap, BToKEE_l2_isPFoverlap;
	float BToKEE_l2_pfmvaId,BToKEE_l1_pfmvaId,BToKEE_l1_mvaId, BToKEE_l2_mvaId;

	//Gen level decay products
	float GenPart_l1_pt, GenPart_l1_eta, GenPart_l1_phi, GenPart_l1_charge, GenPart_l2_pt, GenPart_l2_eta, GenPart_l2_phi, GenPart_l2_charge, GenPart_k_pt, GenPart_k_eta, GenPart_k_phi, GenPart_k_charge;

	//variables per event

	SkimTree.Branch("entry", &entry);
	SkimTree.Branch("event", &event);
	SkimTree.Branch("HLT_Mu12_IP6", &iHLT_Mu12_IP6, "iHLT_Mu12_IP6/I");
	SkimTree.Branch("HLT_Mu9_IP6", &iHLT_Mu9_IP6, "iHLT_Mu9_IP6/I");

	//BToKEE variables

	SkimTree.Branch("BToKEE_chi2", &BToKEE_chi2);
	SkimTree.Branch("BToKEE_cos2D",  &BToKEE_cos2D);
	SkimTree.Branch("BToKEE_eta", &BToKEE_eta);
	SkimTree.Branch("BToKEE_fit_cos2D", &BToKEE_fit_cos2D);
	SkimTree.Branch("BToKEE_fit_eta",  &BToKEE_fit_eta);
	SkimTree.Branch("BToKEE_fit_k_eta", &BToKEE_fit_k_eta);
	SkimTree.Branch("BToKEE_fit_k_phi",  &BToKEE_fit_k_phi);
	SkimTree.Branch("BToKEE_fit_k_pt",  &BToKEE_fit_k_pt);
	SkimTree.Branch("BToKEE_fit_l1_eta", &BToKEE_fit_l1_eta);
	SkimTree.Branch("BToKEE_fit_l1_phi", &BToKEE_fit_l1_phi);
	SkimTree.Branch("BToKEE_fit_l1_pt", &BToKEE_fit_l1_pt);
	SkimTree.Branch("BToKEE_fit_l2_eta", &BToKEE_fit_l2_eta);
	SkimTree.Branch("BToKEE_fit_l2_phi", &BToKEE_fit_l2_phi);
	SkimTree.Branch("BToKEE_fit_l2_pt", &BToKEE_fit_l2_pt);
	SkimTree.Branch("BToKEE_fit_mass", &BToKEE_fit_mass);
	SkimTree.Branch("BToKEE_fit_massErr", &BToKEE_fit_massErr);
	SkimTree.Branch("BToKEE_fit_phi", &BToKEE_fit_phi);
	SkimTree.Branch("BToKEE_fit_pt", &BToKEE_fit_pt);
	SkimTree.Branch("BToKEE_l_xy", &BToKEE_l_xy);
	SkimTree.Branch("BToKEE_l_xy_unc", &BToKEE_l_xy_unc);
	SkimTree.Branch("BToKEE_mass", &BToKEE_mass);
	SkimTree.Branch("BToKEE_maxDR", &BToKEE_maxDR);
	SkimTree.Branch("BToKEE_minDR", &BToKEE_minDR);
	SkimTree.Branch("BToKEE_mllErr_llfit", &BToKEE_mllErr_llfit);
	SkimTree.Branch("BToKEE_mll_fullfit",  &BToKEE_mll_fullfit);
	SkimTree.Branch("BToKEE_mll_llfit", &BToKEE_mll_llfit);
	SkimTree.Branch("BToKEE_mll_raw", &BToKEE_mll_raw);
	SkimTree.Branch("BToKEE_phi", &BToKEE_phi);
	SkimTree.Branch("BToKEE_pt", &BToKEE_pt);
	SkimTree.Branch("BToKEE_svprob", &BToKEE_svprob);
	SkimTree.Branch("BToKEE_vtx_ex", &BToKEE_vtx_ex);
	SkimTree.Branch("BToKEE_vtx_ey",  &BToKEE_vtx_ey);
	SkimTree.Branch("BToKEE_vtx_ez", &BToKEE_vtx_ez);
	SkimTree.Branch("BToKEE_vtx_x", &BToKEE_vtx_x);
	SkimTree.Branch("BToKEE_vtx_y", &BToKEE_vtx_y);
	SkimTree.Branch("BToKEE_vtx_z", &BToKEE_vtx_z);
	SkimTree.Branch("BToKEE_charge",  &BToKEE_charge);
	SkimTree.Branch("BToKEE_l1_pt", &BToKEE_l1_pt);
	SkimTree.Branch("BToKEE_l2_pt", &BToKEE_l2_pt);
	SkimTree.Branch("BToKEE_l1_eta", &BToKEE_l1_eta);
	SkimTree.Branch("BToKEE_l2_eta", &BToKEE_l2_eta);
	SkimTree.Branch("BToKEE_l1_phi", &BToKEE_l1_phi);
	SkimTree.Branch("BToKEE_l2_phi", &BToKEE_l2_phi);
	SkimTree.Branch("BToKEE_l1_isPF", &BToKEE_l1_isPF);
	SkimTree.Branch("BToKEE_l2_isPF", &BToKEE_l2_isPF);
	SkimTree.Branch("BToKEE_l1_pfmvaId", &BToKEE_l1_pfmvaId);
	SkimTree.Branch("BToKEE_l2_pfmvaId", &BToKEE_l2_pfmvaId);
	SkimTree.Branch("BToKEE_l1_isLowPt", &BToKEE_l1_isLowPt);
	SkimTree.Branch("BToKEE_l2_isLowPt", &BToKEE_l2_isLowPt);
	SkimTree.Branch("BToKEE_l1_mvaId", &BToKEE_l1_mvaId);
	SkimTree.Branch("BToKEE_l2_mvaId", &BToKEE_l2_mvaId);
	SkimTree.Branch("BToKEE_l1_isPFoverlap", &BToKEE_l1_isPFoverlap);
	SkimTree.Branch("BToKEE_l2_isPfoverlap", &BToKEE_l2_isPFoverlap);
	SkimTree.Branch("BToKEE_k_pt", &BToKEE_k_pt);
	SkimTree.Branch("BToKEE_k_eta", &BToKEE_k_eta);
	SkimTree.Branch("BToKEE_k_phi", &BToKEE_k_phi);
	SkimTree.Branch("BToKEE_pdgId", &BToKEE_pdgId);
	SkimTree.Branch("BToKEE_isMC", &BToKEE_isMC);

	if (isMC){ // decay products @ gen level

		SkimTree.Branch("GenPart_l1_pt", &GenPart_l1_pt);
		SkimTree.Branch("GenPart_l1_eta", &GenPart_l1_eta);
		SkimTree.Branch("GenPart_l1_phi", &GenPart_l1_phi);
		SkimTree.Branch("GenPart_l1_charge", &GenPart_l1_charge);
		SkimTree.Branch("GenPart_l2_pt", &GenPart_l2_pt);
		SkimTree.Branch("GenPart_l2_eta", &GenPart_l2_eta);
		SkimTree.Branch("GenPart_l2_phi", &GenPart_l2_phi);
		SkimTree.Branch("GenPart_l2_charge", &GenPart_l2_charge);
		SkimTree.Branch("GenPart_k_pt", &GenPart_k_pt);
		SkimTree.Branch("GenPart_k_eta", &GenPart_k_eta);
		SkimTree.Branch("GenPart_k_phi", &GenPart_k_phi);
		SkimTree.Branch("GenPart_k_charge", &GenPart_k_charge);

	}


	int i;
	int counter=0;

	std::cout <<"N entries " << evt.fChain->GetEntries() << std::endl;  // input check

	for(i=0;i<evt.fChain->GetEntries();i++){

	if (i%10000==0)std::cout << "On entry " << i  << std::endl;  // loop proceeding ok

		evt.fChain->GetEntry(i);


		if (!evt.HLT_Mu12_IP6 && !evt.HLT_Mu9_IP6) continue; // Trigger paths to be satisfied


		std::vector<float> B_sel_disc;
		std::vector<int> B_sel_Idx;
		
			if (evt.nBToKEE>600) continue;
			counter =0;
			for (int j = 0; j<evt.nBToKEE;j++){

			//defining cuts
			bool ele1_convveto = evt.Electron_convVeto[evt.BToKEE_l1Idx[j]];     
			bool ele2_convveto = evt.Electron_convVeto[evt.BToKEE_l2Idx[j]];     
			bool vtxFitSel = evt.BToKEE_mass[j] <6 && evt.BToKEE_mass[j]>4.7 && evt.BToKEE_fit_pt[j]>3 && evt.BToKEE_l_xy[j]/evt.BToKEE_l_xy_unc[j]>6 && evt.BToKEE_svprob[j]>0.1 &&evt. BToKEE_fit_cos2D[j]>0.99;
			bool ele1Sel = ele1_convveto && evt.BToKEE_fit_l1_pt[j]>1 && fabs(evt.BToKEE_fit_l1_eta[j])<2.4;  
			bool ele2Sel = ele2_convveto && evt.BToKEE_fit_l2_pt[j]>1 && fabs(evt.BToKEE_fit_l2_eta[j])<2.4;  
			bool kSel = evt.BToKEE_fit_k_pt[j]>1.5 && fabs(evt.BToKEE_fit_k_eta[j])<2.4; 

			
			//perform selection
			if ( kSel && ele1Sel && ele2Sel){ // decay products selection

				if (vtxFitSel){ // whole event selection
					counter++;
					B_sel_disc.push_back(evt.BToKEE_svprob[j]); // pushing back whichever variable to perform ranking of B candidates and choose the best candidate to be saved
					B_sel_Idx.push_back(j);

				}
			}	
		}


		//std::cout << "array size " << B_sel_Vprob->size() << std::endl; 
		//sorting events passing selections in terms of sv_prob
		int idx =-1;
		if(B_sel_Idx.size()>0){ // this loop can be changed to fit the selection criteria needed for skimming
			double temp=-99; 
			for (int j =0; j<B_sel_Idx.size();j++){

				if (B_sel_disc.at(j)>temp){
					temp = B_sel_disc.at(j);
					idx =B_sel_Idx.at(j);
				}


			}
		}

		if (idx != -1){
			std::cout << "__________________________________________________________________________single selected B : index  " << idx << "probV : " << evt.BToKEE_svprob[idx] << std::endl; 

			entry = i;
			event = evt.event;
			iHLT_Mu12_IP6 = evt.HLT_Mu12_IP6;
			iHLT_Mu9_IP6 = evt.HLT_Mu9_IP6;

			BToKEE_cos2D=evt.BToKEE_cos2D[idx];   //[nBToKEE]
			BToKEE_eta=evt.BToKEE_eta[idx];   //[nBToKEE]
			BToKEE_fit_eta=evt.BToKEE_fit_eta[idx];   //[nBToKEE]
			BToKEE_fit_k_eta=evt.BToKEE_fit_k_eta[idx];   //[nBToKEE]
			BToKEE_fit_k_phi=evt.BToKEE_fit_k_phi[idx];   //[nBToKEE]
			BToKEE_fit_k_pt=evt.BToKEE_fit_k_pt[idx];   //[nBToKEE]
			BToKEE_fit_l1_eta=evt.BToKEE_fit_l1_eta[idx];   //[nBToKEE]
			BToKEE_fit_l1_phi=evt.BToKEE_fit_l1_phi[idx];   //[nBToKEE]
			BToKEE_fit_l1_pt=evt.BToKEE_fit_l1_pt[idx];   //[nBToKEE]
			BToKEE_fit_l2_eta=evt.BToKEE_fit_l2_eta[idx];   //[nBToKEE]
			BToKEE_fit_l2_phi=evt.BToKEE_fit_l2_phi[idx];   //[nBToKEE]
			BToKEE_fit_l2_pt=evt.BToKEE_fit_l2_pt[idx];   //[nBToKEE]
			BToKEE_fit_mass=evt.BToKEE_fit_mass[idx];   //[nBToKEE]
			BToKEE_fit_massErr=evt.BToKEE_fit_massErr[idx];   //[nBToKEE]
			BToKEE_fit_phi=evt.BToKEE_fit_phi[idx];   //[nBToKEE]
			BToKEE_fit_pt=evt.BToKEE_fit_pt[idx];   //[nBToKEE]
			BToKEE_l_xy=evt.BToKEE_l_xy[idx];   //[nBToKEE]
			BToKEE_l_xy_unc=evt.BToKEE_l_xy_unc[idx];   //[nBToKEE]
			BToKEE_mass=evt.BToKEE_mass[idx];   //[nBToKEE]
			BToKEE_maxDR=evt.BToKEE_maxDR[idx];   //[nBToKEE]
			BToKEE_minDR=evt.BToKEE_minDR[idx];   //[nBToKEE]
			BToKEE_mllErr_llfit=evt.BToKEE_mllErr_llfit[idx];   //[nBToKEE]
			BToKEE_mll_fullfit=evt.BToKEE_mll_fullfit[idx];   //[nBToKEE]
			BToKEE_mll_llfit=evt.BToKEE_mll_llfit[idx];   //[nBToKEE]
			BToKEE_mll_raw=evt.BToKEE_mll_raw[idx];   //[nBToKEE]
			BToKEE_phi=evt.BToKEE_phi[idx];   //[nBToKEE]
			BToKEE_pt=evt.BToKEE_pt[idx];   //[nBToKEE]
			BToKEE_svprob=evt.BToKEE_svprob[idx];   //[nBToKEE]
			BToKEE_vtx_ex=evt.BToKEE_vtx_ex[idx];   //[nBToKEE]
			BToKEE_vtx_ey=evt.BToKEE_vtx_ey[idx];   //[nBToKEE]
			BToKEE_vtx_ez=evt.BToKEE_vtx_ez[idx];   //[nBToKEE]
			BToKEE_vtx_x=evt.BToKEE_vtx_x[idx];   //[nBToKEE]
			BToKEE_vtx_y=evt.BToKEE_vtx_y[idx];   //[nBToKEE]
			BToKEE_vtx_z=evt.BToKEE_vtx_z[idx];   //[nBToKEE]
			BToKEE_charge=evt.BToKEE_charge[idx];   //[nBToKEE]
			BToKEE_k_pt=evt.ProbeTracks_pt[evt.BToKEE_kIdx[idx]];   //[nBToKEE]
			BToKEE_k_eta=evt.ProbeTracks_eta[evt.BToKEE_kIdx[idx]];   //[nBToKEE]
			BToKEE_k_phi=evt.ProbeTracks_phi[evt.BToKEE_kIdx[idx]];   //[nBToKEE]
			BToKEE_l1_pt=evt.Electron_pt[evt.BToKEE_l1Idx[idx]];   //[nBToKEE]
			BToKEE_l2_pt=evt.Electron_pt[evt.BToKEE_l2Idx[idx]];   //[nBToKEE]
			BToKEE_l1_eta=evt.Electron_eta[evt.BToKEE_l1Idx[idx]];   //[nBToKEE]
			BToKEE_l2_eta=evt.Electron_eta[evt.BToKEE_l2Idx[idx]];   //[nBToKEE]
			BToKEE_l1_phi=evt.Electron_phi[evt.BToKEE_l1Idx[idx]];   //[nBToKEE]
			BToKEE_l2_phi=evt.Electron_phi[evt.BToKEE_l2Idx[idx]];   //[nBToKEE]
			BToKEE_l1_pfmvaId=evt.Electron_pfmvaId[evt.BToKEE_l1Idx[idx]];   //[nBToKEE]
			BToKEE_l2_pfmvaId=evt.Electron_pfmvaId[evt.BToKEE_l2Idx[idx]];   //[nBToKEE]
			BToKEE_l1_isPF=evt.Electron_isPF[evt.BToKEE_l1Idx[idx]];   //[nBToKEE]
			BToKEE_l2_isPF=evt.Electron_isPF[evt.BToKEE_l2Idx[idx]];   //[nBToKEE]
			BToKEE_l1_isLowPt=evt.Electron_isLowPt[evt.BToKEE_l1Idx[idx]];   //[nBToKEE]
			BToKEE_l2_isLowPt=evt.Electron_isLowPt[evt.BToKEE_l2Idx[idx]];   //[nBToKEE]
			BToKEE_l1_mvaId=evt.Electron_mvaId[evt.BToKEE_l1Idx[idx]];   //[nBToKEE]
			BToKEE_l2_mvaId=evt.Electron_mvaId[evt.BToKEE_l2Idx[idx]];   //[nBToKEE]
			BToKEE_l1_isPFoverlap=evt.Electron_mvaId[evt.BToKEE_l1Idx[idx]];   //[nBToKEE]  flag checking if the LowPt electron is reconstructed also as PF
			BToKEE_l2_isPFoverlap=evt.Electron_mvaId[evt.BToKEE_l2Idx[idx]];   //[nBToKEE] flag checking if the LowPt electron is reconstructed also as PF
			BToKEE_pdgId=evt.BToKEE_pdgId[idx];   //[nBToKEE]

			if (isMC){
				//loop to select a gen electron
				for(int k =0; k<evt.nGenPart;k++){ // loop to select a second gen electron
					for(int h =0; h<evt.nGenPart;h++){
						bool ePair =fabs(evt.GenPart_pdgId[k]) == 11 && fabs(evt.GenPart_pdgId[h]) == 11 && evt.GenPart_pdgId[h]*evt.GenPart_pdgId[k] < 0 && evt.GenPart_genPartIdxMother[h]==evt.GenPart_genPartIdxMother[k];
						if (ePair){ // checks if the two electrons form a gen lepton pair 
							for(int x=0; x<evt.nGenPart; x++){ //loop to select a K 

								bool BToKJpsi = evt.GenPart_pdgId[evt.GenPart_genPartIdxMother[h]]==443 && fabs(evt.GenPart_pdgId[x])== 321 && evt.GenPart_genPartIdxMother[evt.GenPart_genPartIdxMother[h]]==evt.GenPart_genPartIdxMother[x];

								bool BToKee =fabs( evt.GenPart_pdgId[evt.GenPart_genPartIdxMother[h]])==521 && fabs(evt.GenPart_pdgId[x])== 321 && evt.GenPart_genPartIdxMother[h]==evt.GenPart_genPartIdxMother[x];

								if(BToKJpsi || BToKee){ //checks if K has same parent as lepton pair (non res) or lepton pair parent (res)
									GenPart_l1_pt = evt.GenPart_pt[k];							
								        GenPart_l1_eta = evt.GenPart_eta[k];
									GenPart_l1_phi = evt.GenPart_phi[k];

									GenPart_l2_pt = evt.GenPart_pt[h];
									GenPart_l2_eta = evt.GenPart_eta[h];
									GenPart_l2_phi = evt.GenPart_phi[h];

									GenPart_k_pt = evt.GenPart_pt[x];
									GenPart_k_eta = evt.GenPart_eta[x];
									GenPart_k_phi = evt.GenPart_phi[x];

								}

							}
						}


					}
				}
				 BToKEE_isMC = evt.isMcB(idx);

			}
			else BToKEE_isMC = false;
			SkimTree.Fill();


		}
	}

	outfile->Write();
	std::cout << "n tot passing std cut"  << counter << std::endl;	
	outfile->Close();
	return 0;

}



