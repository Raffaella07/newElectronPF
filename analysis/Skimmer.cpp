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


void rankedIdxes(std::vector<float>* unsorted, std::vector<float>* sorted, std::vector<int>* all_idx, std::vector<int>* indx ){

	int d, j;

	std::sort(sorted->begin(), sorted->end(),std::greater<float>());
	for (int d=0; d < sorted->size(); d++){
		for (int j =0; j<all_idx->size();j++){

			if (unsorted->at(j)==sorted->at(d)){
				indx->push_back(all_idx->at(j));

			}
		}

	}





}

int main(int argc, char **argv){

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

	/*	int in_part = std::atoi(argv[1]); // Part of dataset analyzed(1,2,3,4)
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
	}*/
	chdir(" /afs/cern.ch/user/r/ratramon/Bparking/CMSSW_10_2_15/src/macros/newElectronPF/analysis");
	TFile* outfile = TFile::Open(argv[3],"RECREATE");
	std::cout <<  outfile << std::endl;
	TTree SkimTree("Tree", "A skimmed tree containing one selected nBToKEE event");


	BNanoClass evt;
	evt.Init(chain);

	//Event variables
	int entry, event,category;
	int iHLT_Mu12_IP6, iHLT_Mu9_IP6;

	//BToKEE fitted variables 
	bool BToKEE_isMC[10];

	float  BToKEE_charge[10],BToKEE_pdgId[10], BToKEE_chi2[10],BToKEE_cos2D[10],BToKEE_eta[10]   ,BToKEE_fit_cos2D[10],BToKEE_fit_eta[10]   ,BToKEE_fit_k_eta[10],BToKEE_fit_k_phi[10],
	       BToKEE_fit_k_pt[10] ,BToKEE_fit_l1_eta[10],BToKEE_fit_l1_phi[10],BToKEE_fit_l1_pt[10] ,BToKEE_fit_l2_eta[10],BToKEE_fit_l2_phi[10],BToKEE_fit_l2_pt[10],BToKEE_fit_mass[10]  ,BToKEE_fit_massErr[10],BToKEE_fit_phi[10]  ,BToKEE_fit_pt[10],
	       BToKEE_l_xy[10]   ,BToKEE_l_xy_unc[10],BToKEE_mass[10]   ,BToKEE_maxDR[10] ,BToKEE_minDR[10]  ,BToKEE_mllErr_llfit[10],BToKEE_mll_fullfit[10],BToKEE_mll_llfit[10]  ,BToKEE_mll_raw[10],BToKEE_phi[10]  ,BToKEE_pt[10],BToKEE_svprob[10],
	       BToKEE_vtx_ex[10],BToKEE_vtx_ey[10],BToKEE_vtx_ez[10],BToKEE_vtx_x[10],BToKEE_vtx_y[10]  ,BToKEE_vtx_z[10];  

	//Reco collections variables:
	//Kinematics
	float BToKEE_l1_pt[10],BToKEE_l2_pt[10],BToKEE_l1_eta[10],BToKEE_l2_eta[10],BToKEE_l1_phi[10],BToKEE_l2_phi[10], BToKEE_k_pt[10], BToKEE_k_eta[10], BToKEE_k_phi[10];

	//electrons categories flags & Ids
	bool  BToKEE_l1_isPF[10], BToKEE_l2_isPF[10],BToKEE_l1_isLowPt[10], BToKEE_l2_isLowPt[10], BToKEE_l1_isPFoverlap[10], BToKEE_l2_isPFoverlap[10];
	float BToKEE_l2_pfmvaId[10],BToKEE_l1_pfmvaId[10],BToKEE_l1_mvaId[10], BToKEE_l2_mvaId[10];

	//Gen level decay products
	float GenPart_l1_pt[10], GenPart_l1_eta[10], GenPart_l1_phi[10], GenPart_l1_charge[10], GenPart_l2_pt[10], GenPart_l2_eta[10], GenPart_l2_phi[10], GenPart_l2_charge[10], GenPart_k_pt[10], GenPart_k_eta[10], GenPart_k_phi[10], GenPart_k_charge[10];


	int nSaved = 3;
	//variables per event

	SkimTree.Branch("entry", &entry);
	SkimTree.Branch("event", &event);
	SkimTree.Branch("category", &category);
	SkimTree.Branch("nSaved", &nSaved);
	SkimTree.Branch("HLT_Mu12_IP6", &iHLT_Mu12_IP6, "iHLT_Mu12_IP6/I");
	SkimTree.Branch("HLT_Mu9_IP6", &iHLT_Mu9_IP6, "iHLT_Mu9_IP6/I");

	//BToKEE variables

	SkimTree.Branch("BToKEE_chi2", &BToKEE_chi2,"BToKEE_chi2[nSaved]/F");
	SkimTree.Branch("BToKEE_cos2D",  &BToKEE_cos2D,"BToKEE_cos2D[nSaved]/F");
	SkimTree.Branch("BToKEE_eta", &BToKEE_eta,"BToKEE_eta[nSaved]/F");
	SkimTree.Branch("BToKEE_fit_cos2D", &BToKEE_fit_cos2D,"BToKEE_fit_cos2D[nSaved]/F");
	SkimTree.Branch("BToKEE_fit_eta",  &BToKEE_fit_eta,"BToKEE_fit_eta[nSaved]/F");
	SkimTree.Branch("BToKEE_fit_k_eta", &BToKEE_fit_k_eta,"BToKEE_fit_k_eta[nSaved]/F");
	SkimTree.Branch("BToKEE_fit_k_phi",  &BToKEE_fit_k_phi,"BToKEE_fit_k_phi[nSaved]/F");
	SkimTree.Branch("BToKEE_fit_k_pt",  &BToKEE_fit_k_pt,"BToKEE_fit_k_pt[nSaved]/F");
	SkimTree.Branch("BToKEE_fit_l1_eta", &BToKEE_fit_l1_eta,"BToKEE_fit_l1_eta[nSaved]/F");
	SkimTree.Branch("BToKEE_fit_l1_phi", &BToKEE_fit_l1_phi,"BToKEE_fit_l1_phi[nSaved]/F");
	SkimTree.Branch("BToKEE_fit_l1_pt", &BToKEE_fit_l1_pt,"BToKEE_fit_l1_pt[nSaved]/F");
	SkimTree.Branch("BToKEE_fit_l2_eta", &BToKEE_fit_l2_eta,"BToKEE_fit_l2_eta[nSaved]/F");
	SkimTree.Branch("BToKEE_fit_l2_phi", &BToKEE_fit_l2_phi,"BToKEE_fit_l2_phi[nSaved]/F");
	SkimTree.Branch("BToKEE_fit_l2_pt", &BToKEE_fit_l2_pt,"BToKEE_fit_l2_pt[nSaved]/F");
	SkimTree.Branch("BToKEE_fit_mass", &BToKEE_fit_mass,"BToKEE_fit_massi[nSaved]/F");
	SkimTree.Branch("BToKEE_fit_massErr", &BToKEE_fit_massErr,"BToKEE_fit_massErr[nSaved]/F");
	SkimTree.Branch("BToKEE_fit_phi", &BToKEE_fit_phi,"BToKEE_fit_phi[nSaved]/F");
	SkimTree.Branch("BToKEE_fit_pt", &BToKEE_fit_pt,"BToKEE_fit_pt[nSaved]/F");
	SkimTree.Branch("BToKEE_l_xy", &BToKEE_l_xy, "BToKEE_l_xy[nSaved]/F");
	SkimTree.Branch("BToKEE_l_xy_unc", &BToKEE_l_xy_unc,"BToKEE_l_xy_unc[nSaved]/F");
	SkimTree.Branch("BToKEE_mass", &BToKEE_mass,"BToKEE_mass[nSaved]/F");
	SkimTree.Branch("BToKEE_maxDR" , &BToKEE_maxDR , "BToKEE_maxDR[nSaved]/F");
	SkimTree.Branch("BToKEE_minDR" , &BToKEE_minDR , "BToKEE_minDR[nSaved]/F");
	SkimTree.Branch("BToKEE_mllErr_llfit" , &BToKEE_mllErr_llfit , "BToKEE_mllErr_llfit[nSaved]/F");
	SkimTree.Branch("BToKEE_mll_fullfit" ,  &BToKEE_mll_fullfit , "BToKEE_mll_fullfit[nSaved]/F");
	SkimTree.Branch("BToKEE_mll_llfit" , &BToKEE_mll_llfit , "BToKEE_mll_llfit[nSaved]/F");
	SkimTree.Branch("BToKEE_mll_raw" , &BToKEE_mll_raw , "BToKEE_mll_raw[nSaved]/F");
	SkimTree.Branch("BToKEE_phi" , &BToKEE_phi , "BToKEE_phi[nSaved]/F");
	SkimTree.Branch("BToKEE_pt" , &BToKEE_pt , "BToKEE_pt[nSaved]/F");
	SkimTree.Branch("BToKEE_svprob" , &BToKEE_svprob , "BToKEE_svprob[nSaved]/F");
	SkimTree.Branch("BToKEE_vtx_ex" , &BToKEE_vtx_ex , "BToKEE_vtx_ex[nSaved]/F");
	SkimTree.Branch("BToKEE_vtx_ey" ,  &BToKEE_vtx_ey , "BToKEE_vtx_ey[nSaved]/F");
	SkimTree.Branch("BToKEE_vtx_ez" , &BToKEE_vtx_ez , "BToKEE_vtx_ez[nSaved]/F");
	SkimTree.Branch("BToKEE_vtx_x" , &BToKEE_vtx_x , "BToKEE_vtx_x[nSaved]/F");
	SkimTree.Branch("BToKEE_vtx_y" , &BToKEE_vtx_y , "BToKEE_vtx_y[nSaved]/F");
	SkimTree.Branch("BToKEE_vtx_z" , &BToKEE_vtx_z , "BToKEE_vtx_z[nSaved]/F");
	SkimTree.Branch("BToKEE_charge" ,  &BToKEE_charge , "BToKEE_charge[nSaved]/I");
	SkimTree.Branch("BToKEE_l1_pt" , &BToKEE_l1_pt , "BToKEE_l1_pt[nSaved]/F");
	SkimTree.Branch("BToKEE_l2_pt" , &BToKEE_l2_pt , "BToKEE_l2_pt[nSaved]/F");
	SkimTree.Branch("BToKEE_l1_eta" , &BToKEE_l1_eta , "BToKEE_l1_eta[nSaved]/F");
	SkimTree.Branch("BToKEE_l2_eta" , &BToKEE_l2_eta , "BToKEE_l2_eta[nSaved]/F");
	SkimTree.Branch("BToKEE_l1_phi" , &BToKEE_l1_phi , "BToKEE_l1_phi[nSaved]/F");
	SkimTree.Branch("BToKEE_l2_phi" , &BToKEE_l2_phi , "BToKEE_l2_phi[nSaved]/F");
	SkimTree.Branch("BToKEE_l1_isPF" , &BToKEE_l1_isPF , "BToKEE_l1_isPF[nSaved]/O");
	SkimTree.Branch("BToKEE_l2_isPF" , &BToKEE_l2_isPF , "BToKEE_l2_isPF[nSaved]/O");
	SkimTree.Branch("BToKEE_l1_pfmvaId" , &BToKEE_l1_pfmvaId , "BToKEE_l1_pfmvaId[nSaved]/F");
	SkimTree.Branch("BToKEE_l2_pfmvaId" , &BToKEE_l2_pfmvaId , "BToKEE_l2_pfmvaId[nSaved]/F");
	SkimTree.Branch("BToKEE_l1_isLowPt" , &BToKEE_l1_isLowPt , "BToKEE_l1_isLowPt[nSaved]/O");
	SkimTree.Branch("BToKEE_l2_isLowPt" , &BToKEE_l2_isLowPt , "BToKEE_l2_isLowPt[nSaved]/O");
	SkimTree.Branch("BToKEE_l1_mvaId" , &BToKEE_l1_mvaId , "BToKEE_l1_mvaId[nSaved]/F");
	SkimTree.Branch("BToKEE_l2_mvaId" , &BToKEE_l2_mvaId , "BToKEE_l2_mvaId[nSaved]/F");
	SkimTree.Branch("BToKEE_l1_isPFoverlap" , &BToKEE_l1_isPFoverlap , "BToKEE_l1_isPFoverlap[nSaved]/O");
	SkimTree.Branch("BToKEE_l2_isPfoverlap" , &BToKEE_l2_isPFoverlap , "BToKEE_l2_isPfoverlap[nSaved]/O");
	SkimTree.Branch("BToKEE_k_pt" , &BToKEE_k_pt , "BToKEE_k_pt[nSaved]/F");
	SkimTree.Branch("BToKEE_k_eta" , &BToKEE_k_eta , "BToKEE_k_eta[nSaved]/F");
	SkimTree.Branch("BToKEE_k_phi" , &BToKEE_k_phi , "BToKEE_k_phi[nSaved]/F");
	SkimTree.Branch("BToKEE_pdgId" , &BToKEE_pdgId , "BToKEE_pdgId[nSaved]/I");
	SkimTree.Branch("BToKEE_isMC" , &BToKEE_isMC , "BToKEE_isMC[nSaved]/O");

	if (isMC){ // decay products @ gen level

		SkimTree.Branch("GenPart_l1_pt" , &GenPart_l1_pt , "GenPart_l1_pt[nSaved]/F");
		SkimTree.Branch("GenPart_l1_eta" , &GenPart_l1_eta , "GenPart_l1_eta[nSaved]/F");
		SkimTree.Branch("GenPart_l1_phi" , &GenPart_l1_phi , "GenPart_l1_phi[nSaved]/F");
		SkimTree.Branch("GenPart_l1_charge" , &GenPart_l1_charge , "GenPart_l1_charge[nSaved]/I");
		SkimTree.Branch("GenPart_l2_pt" , &GenPart_l2_pt , "GenPart_l2_pt[nSaved]/F");
		SkimTree.Branch("GenPart_l2_eta" , &GenPart_l2_eta , "GenPart_l2_eta[nSaved]/F");
		SkimTree.Branch("GenPart_l2_phi" , &GenPart_l2_phi , "GenPart_l2_phi[nSaved]/F");
		SkimTree.Branch("GenPart_l2_charge" , &GenPart_l2_charge , "GenPart_l2_charge[nSaved]/I");
		SkimTree.Branch("GenPart_k_pt" , &GenPart_k_pt , "GenPart_k_pt[nSaved]/F");
		SkimTree.Branch("GenPart_k_eta" , &GenPart_k_eta , "GenPart_k_eta[nSaved]/F");
		SkimTree.Branch("GenPart_k_phi" , &GenPart_k_phi , "GenPart_k_phi[nSaved]/F");
		SkimTree.Branch("GenPart_k_charge" , &GenPart_k_charge , "GenPart_k_charge[nSaved]/I");

	}


	int i;

	std::cout <<"N entries " << evt.fChain->GetEntries() << std::endl;  // input check

	for(i=0;i<evt.fChain->GetEntries();i++){

		if (i%10000==0)std::cout << "On entry " << i  << std::endl;  // loop proceeding ok
		if (i<135)std::cout << "----------------------------------------------------------------------______________________________________--------------------------On entry " << i  << std::endl;  // loop proceeding ok

		evt.fChain->GetEntry(i);


		if (!evt.HLT_Mu12_IP6 && !evt.HLT_Mu9_IP6) continue; // Trigger paths to be satisfied


		std::vector<float> B_sel_disc;
		std::vector<int> B_sel_Idx;
		std::vector<int> B_sel_cat;

		if (evt.nBToKEE>600) continue;
		for (int cat =0; cat < 3;cat++){// looping onto event categories 


			for (int j = 0; j<evt.nBToKEE;j++){

				if (cat ==0 && (!evt.Electron_isPF[evt.BToKEE_l1Idx[j]] || !evt.Electron_isPF[evt.BToKEE_l2Idx[j]]) )continue; // PF-PF

				else if (cat ==1 && !((evt.Electron_isPF[evt.BToKEE_l1Idx[j]] && evt.Electron_isLowPt[evt.BToKEE_l2Idx[j]]) || (evt.Electron_isLowPt[evt.BToKEE_l1Idx[j]] && evt.Electron_isPF[evt.BToKEE_l2Idx[j]])))continue; // PF-lowPt
				if (cat ==2 && (!evt.Electron_isLowPt[evt.BToKEE_l1Idx[j]] || !evt.Electron_isLowPt[evt.BToKEE_l2Idx[j]]) )continue; // lowPt-lowPt



				//defining selections 

				bool ele1_convveto = evt.Electron_convVeto[evt.BToKEE_l1Idx[j]];     
				bool ele2_convveto = evt.Electron_convVeto[evt.BToKEE_l2Idx[j]];     
				bool vtxFitSel = evt.BToKEE_mass[j] <6 && evt.BToKEE_mass[j]>4.7 && evt.BToKEE_fit_pt[j]>3 && evt.BToKEE_l_xy[j]/evt.BToKEE_l_xy_unc[j]>6 && evt.BToKEE_svprob[j]>0.1 &&evt. BToKEE_fit_cos2D[j]>0.99;
				bool ele1Sel = ele1_convveto && evt.BToKEE_fit_l1_pt[j]>0.5 && fabs(evt.BToKEE_fit_l1_eta[j])<2.4;  
				bool ele2Sel = ele2_convveto && evt.BToKEE_fit_l2_pt[j]>0.5 && fabs(evt.BToKEE_fit_l2_eta[j])<2.4;  
				bool kSel = evt.BToKEE_fit_k_pt[j]>0.8 && fabs(evt.BToKEE_fit_k_eta[j])<2.4; 

				//makes sure that analyzed lowpt electrons haven't been already treated as PF

				if ((evt.Electron_isLowPt[evt.BToKEE_l1Idx[j]] && evt.Electron_isPFoverlap[evt.BToKEE_l1Idx[j]]) || (evt.Electron_isLowPt[evt.BToKEE_l2Idx[j]] && evt.Electron_isPFoverlap[evt.BToKEE_l2Idx[j]])) continue;	


				//perform selection
				if ( kSel && ele1Sel && ele2Sel){ // decay products selection

					if (vtxFitSel){ // whole event selection
						counter++;
						B_sel_disc.push_back(evt.BToKEE_l_xy[j]/evt.BToKEE_l_xy_unc[j]); // pushing back whichever variable to perform ranking of B candidates and choose the best candidate to be saved
						B_sel_Idx.push_back(j); // pushing back the reco B  index 
						B_sel_cat.push_back(cat);//pushing back the event category

					}
				}	
			}
		}

		//std::cout << "array size " << B_sel_disc.size() << std::endl; 
		std::vector<int> idx;
		if(B_sel_Idx.size()>0){ // this loop can be changed to fit the selection criteria needed for skimming

			double temp=-99; 
			std::vector<float> categories[3];
			for (int j =0; j<B_sel_Idx.size();j++){
				std::cout << "category " << B_sel_cat.at(j) << std::endl; 

				//Diving the events passing selection in categories
				std::cout << "Pf Pf? " << evt.Electron_isLowPt[evt.BToKEE_l1Idx[B_sel_Idx.at(j)]] << "  " << evt.Electron_isLowPt[evt.BToKEE_l2Idx[B_sel_Idx.at(j)]] << std::endl;
				std::cout << "Pf Pf? " << evt.Electron_isPF[evt.BToKEE_l1Idx[B_sel_Idx.at(j)]] << "  " << evt.Electron_isPF[evt.BToKEE_l2Idx[B_sel_Idx.at(j)]] << std::endl;
				std::cout << "__________single selected B : index  " << B_sel_Idx.at(j) << "probV : " << evt.BToKEE_l_xy[B_sel_Idx.at(j)]/evt.BToKEE_l_xy_unc[B_sel_Idx.at(j)] << std::endl; 

				if (B_sel_cat.at(j)==0) categories[0].push_back(B_sel_disc.at(j));
				else if (B_sel_cat.at(j)==1) categories[1].push_back(B_sel_disc.at(j));
				else if (B_sel_cat.at(j)==2) categories[2].push_back(B_sel_disc.at(j));

			}
			category =0;
			rankedIdxes(&B_sel_disc, &categories[0], &B_sel_Idx,  &idx ); // fills idx vector with the indexes from the reco B in the first category ranked with the choosen criterium


			if (categories[0].size()==0 && categories[1].size()>0){ // if the first category is empty, does the same in the second

				category = 1;
				rankedIdxes(&B_sel_disc, &categories[1], &B_sel_Idx,  &idx );
			}
			if(categories[0].size()+categories[1].size()==0 && categories[2].size()>0){ // if the first and second categories are empty, does the same on the third
			category =2;
			rankedIdxes(&B_sel_disc, &categories[2], &B_sel_Idx,  &idx );

			}



		}

		if(idx.size()!=0){
			int size;
			if (idx.size() < 3 ) size = idx.size(); // set the size of the saved array of B candidates to the actual number of reco B in the highest category found not empty
			else size =3; // if more than 3 reco B are found, saves the first three
			std::cout << "array size " << size << std::endl;

			//save variables x event
			nSaved = size;
			entry = i;
			event = evt.event;
			iHLT_Mu12_IP6 = evt.HLT_Mu12_IP6;
			iHLT_Mu9_IP6 = evt.HLT_Mu9_IP6;


			//save arrays of reco B selected
			for(int index =0; index < size ; index++){

				std::cout << "__________________________________________________________________________single selected B : index  " << idx.at(index) << "probV : " << evt.BToKEE_l_xy[idx.at(index)]/evt.BToKEE_l_xy_unc[idx.at(index)] << std::endl; 	

				BToKEE_cos2D[index]=evt.BToKEE_cos2D[idx.at(index)];   //[nBToKEE]
				BToKEE_eta[index]=evt.BToKEE_eta[idx.at(index)];   //[nBToKEE]
				BToKEE_fit_eta[index]=evt.BToKEE_fit_eta[idx.at(index)];   //[nBToKEE]
				BToKEE_fit_k_eta[index]=evt.BToKEE_fit_k_eta[idx.at(index)];   //[nBToKEE]
				BToKEE_fit_k_phi[index]=evt.BToKEE_fit_k_phi[idx.at(index)];   //[nBToKEE]
				BToKEE_fit_k_pt[index]=evt.BToKEE_fit_k_pt[idx.at(index)];   //[nBToKEE]
				BToKEE_fit_l1_eta[index]=evt.BToKEE_fit_l1_eta[idx.at(index)];   //[nBToKEE]
				BToKEE_fit_l1_phi[index]=evt.BToKEE_fit_l1_phi[idx.at(index)];   //[nBToKEE]
				BToKEE_fit_l1_pt[index]=evt.BToKEE_fit_l1_pt[idx.at(index)];   //[nBToKEE]
				BToKEE_fit_l2_eta[index]=evt.BToKEE_fit_l2_eta[idx.at(index)];   //[nBToKEE]
				BToKEE_fit_l2_phi[index]=evt.BToKEE_fit_l2_phi[idx.at(index)];   //[nBToKEE]
				BToKEE_fit_l2_pt[index]=evt.BToKEE_fit_l2_pt[idx.at(index)];   //[nBToKEE]
				BToKEE_fit_mass[index]=evt.BToKEE_fit_mass[idx.at(index)];   //[nBToKEE]
				BToKEE_fit_massErr[index]=evt.BToKEE_fit_massErr[idx.at(index)];   //[nBToKEE]
				BToKEE_fit_phi[index]=evt.BToKEE_fit_phi[idx.at(index)];   //[nBToKEE]
				BToKEE_fit_pt[index]=evt.BToKEE_fit_pt[idx.at(index)];   //[nBToKEE]
				BToKEE_l_xy[index]=evt.BToKEE_l_xy[idx.at(index)];   //[nBToKEE]
				BToKEE_l_xy_unc[index]=evt.BToKEE_l_xy_unc[idx.at(index)];   //[nBToKEE]
				BToKEE_mass[index]=evt.BToKEE_mass[idx.at(index)];   //[nBToKEE]
				BToKEE_maxDR[index]=evt.BToKEE_maxDR[idx.at(index)];   //[nBToKEE]
				BToKEE_minDR[index]=evt.BToKEE_minDR[idx.at(index)];   //[nBToKEE]
				BToKEE_mllErr_llfit[index]=evt.BToKEE_mllErr_llfit[idx.at(index)];   //[nBToKEE]
				BToKEE_mll_fullfit[index]=evt.BToKEE_mll_fullfit[idx.at(index)];   //[nBToKEE]
				BToKEE_mll_llfit[index]=evt.BToKEE_mll_llfit[idx.at(index)];   //[nBToKEE]
				BToKEE_mll_raw[index]=evt.BToKEE_mll_raw[idx.at(index)];   //[nBToKEE]
				BToKEE_phi[index]=evt.BToKEE_phi[idx.at(index)];   //[nBToKEE]
				BToKEE_pt[index]=evt.BToKEE_pt[idx.at(index)];   //[nBToKEE]
				BToKEE_svprob[index]=evt.BToKEE_svprob[idx.at(index)];   //[nBToKEE]
				BToKEE_vtx_ex[index]=evt.BToKEE_vtx_ex[idx.at(index)];   //[nBToKEE]
				BToKEE_vtx_ey[index]=evt.BToKEE_vtx_ey[idx.at(index)];   //[nBToKEE]
				BToKEE_vtx_ez[index]=evt.BToKEE_vtx_ez[idx.at(index)];   //[nBToKEE]
				BToKEE_vtx_x[index]=evt.BToKEE_vtx_x[idx.at(index)];   //[nBToKEE]
				BToKEE_vtx_y[index]=evt.BToKEE_vtx_y[idx.at(index)];   //[nBToKEE]
				BToKEE_vtx_z[index]=evt.BToKEE_vtx_z[idx.at(index)];   //[nBToKEE]
				BToKEE_charge[index]=evt.BToKEE_charge[idx.at(index)];   //[nBToKEE]

				BToKEE_k_pt[index]=evt.ProbeTracks_pt[evt.BToKEE_l1Idx[idx.at(index)]];   //[nBToKEE]
				BToKEE_k_eta[index]=evt.ProbeTracks_eta[evt.BToKEE_l1Idx[idx.at(index)]];   //[nBToKEE]
				BToKEE_k_phi[index]=evt.ProbeTracks_phi[evt.BToKEE_l1Idx[idx.at(index)]];   //[nBToKEE]

				BToKEE_l1_pt[index]=evt.Electron_pt[evt.BToKEE_l1Idx[idx.at(index)]];   //[nBToKEE]
				BToKEE_l2_pt[index]=evt.Electron_pt[evt.BToKEE_l1Idx[idx.at(index)]];   //[nBToKEE]
				BToKEE_l1_eta[index]=evt.Electron_eta[evt.BToKEE_l1Idx[idx.at(index)]];   //[nBToKEE]
				BToKEE_l2_eta[index]=evt.Electron_eta[evt.BToKEE_l2Idx[idx.at(index)]];   //[nBToKEE]
				BToKEE_l1_phi[index]=evt.Electron_phi[evt.BToKEE_l1Idx[idx.at(index)]];   //[nBToKEE]
				BToKEE_l2_phi[index]=evt.Electron_phi[evt.BToKEE_l2Idx[idx.at(index)]];   //[nBToKEE]
				BToKEE_l1_pfmvaId[index]=evt.Electron_pfmvaId[evt.BToKEE_l1Idx[idx.at(index)]];   //[nBToKEE]
				BToKEE_l2_pfmvaId[index]=evt.Electron_pfmvaId[evt.BToKEE_l2Idx[idx.at(index)]];   //[nBToKEE]
				BToKEE_l1_isPF[index]=evt.Electron_isPF[evt.BToKEE_l1Idx[idx.at(index)]];   //[nBToKEE]
				BToKEE_l2_isPF[index]=evt.Electron_isPF[evt.BToKEE_l2Idx[idx.at(index)]];   //[nBToKEE]
				BToKEE_l1_isLowPt[index]=evt.Electron_isLowPt[evt.BToKEE_l1Idx[idx.at(index)]];   //[nBToKEE]
				BToKEE_l2_isLowPt[index]=evt.Electron_isLowPt[evt.BToKEE_l2Idx[idx.at(index)]];   //[nBToKEE]
				BToKEE_l1_mvaId[index]=evt.Electron_mvaId[evt.BToKEE_l1Idx[idx.at(index)]];   //[nBToKEE]
				BToKEE_l2_mvaId[index]=evt.Electron_mvaId[evt.BToKEE_l2Idx[idx.at(index)]];   //[nBToKEE]
				BToKEE_l1_isPFoverlap[index]=evt.Electron_isPFoverlap[evt.BToKEE_l1Idx[idx.at(index)]];   //[nBToKEE]  flag checking if the LowPt electron is reconstructed also as PF
				BToKEE_l2_isPFoverlap[index]=evt.Electron_isPFoverlap[evt.BToKEE_l2Idx[idx.at(index)]];   //[nBToKEE] flag checking if the LowPt electron is reconstructed also as PF
				BToKEE_pdgId[index]=evt.BToKEE_pdgId[idx.at(index)];   //[nBToKEE]

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
										GenPart_l1_pt[index] = evt.GenPart_pt[k];							
										GenPart_l1_eta[index] = evt.GenPart_eta[k];
										GenPart_l1_phi[index] = evt.GenPart_phi[k];

										GenPart_l2_pt[index] = evt.GenPart_pt[h];
										GenPart_l2_eta[index] = evt.GenPart_eta[h];
										GenPart_l2_phi[index] = evt.GenPart_phi[h];

										GenPart_k_pt[index] = evt.GenPart_pt[x];
										GenPart_k_eta[index] = evt.GenPart_eta[x];
										GenPart_k_phi[index] = evt.GenPart_phi[x];

									}

								}
							}


						}
					}
					BToKEE_isMC[index] = evt.isMcB(idx.at(index));

				}
				else BToKEE_isMC[index] = false;


			}
			SkimTree.Fill();
		}
	}

	outfile->Write();
	outfile->Close();
	return 0;

}



