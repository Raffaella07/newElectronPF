#include "../interface/BParkTools.h"
#include <bits/stdc++.h> 
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
	int in_files = std::atoi(argv[1]);
	std::string INPUTDIR = argv[2];
	TFile* outfile = TFile::Open(argv[3],"RECREATE");

	TChain* chain= new TChain("Events");
	std::cout << "Loading input files from: " << std::endl;
	std::cout << INPUTDIR << std::endl;
	if (in_files == -1 ){
		for(int file_idx=1;file_idx < 10; file_idx++){
			chain->Add((INPUTDIR+"/BParkNANO_data_2020Jan16_"+std::to_string(file_idx)+".root").c_str());
		}
	}else  chain->Add((INPUTDIR+"/BParkNANO_data_2020Jan16_"+std::to_string(in_files)+"*.root").c_str());
	//chain->Add((INPUTDIR+"BParkNANO_mc_2020Jan16_*.root").c_str());
	TTree SkimTree("Tree", "A skimmed tree containing one selected nBToKEE event");

	//defining cuts


	BNanoClass evt;
	evt.Init(chain);
	setStyle();
	int entry, event,nElectrons, BToKEE_charge, BToKEE_kIdx, BToKEE_l1Idx, BToKEE_l2Idx,BToKEE_pdgId,Electron_charge[200],Electron_pdgId[200],Electron_tightCharge[200];

	bool Electron_convVeto[200],Electron_isLowPt[200],Electron_isPF[200],Electron_isPFoverlap[200];


	float  BToKEE_chi2,BToKEE_cos2D,BToKEE_eta   ,BToKEE_fit_cos2D,BToKEE_fit_eta   ,BToKEE_fit_k_eta,BToKEE_fit_k_phi ,BToKEE_fit_k_pt ,BToKEE_fit_l1_eta,BToKEE_fit_l1_phi,BToKEE_fit_l1_pt ,BToKEE_fit_l2_eta,BToKEE_fit_l2_phi,BToKEE_fit_l2_pt,BToKEE_fit_mass  ,BToKEE_fit_massErr,BToKEE_fit_phi  ,BToKEE_fit_pt   ,BToKEE_l_xy   ,BToKEE_l_xy_unc,BToKEE_mass   ,BToKEE_maxDR ,BToKEE_minDR  ,BToKEE_mllErr_llfit,BToKEE_mll_fullfit,BToKEE_mll_llfit  ,BToKEE_mll_raw,BToKEE_phi  ,BToKEE_pt,BToKEE_svprob,BToKEE_vtx_ex,BToKEE_vtx_ey,BToKEE_vtx_ez,BToKEE_vtx_x,BToKEE_vtx_y  ,BToKEE_vtx_z;  



	float         Electron_deltaEtaSC[200];   //[nElectron]
	float         Electron_dxy[200];   //[nElectron]
	float         Electron_dxyErr[200];   //[nElectron]
	float         Electron_dz[200];   //[nElectron]
	float         Electron_dzErr[200];   //[nElectron]
	float         Electron_eta[200];   //[nElectron]
	float         Electron_fBrem[200];   //[nElectron]
	float         Electron_hoe[200];   //[nElectron]
	float         Electron_ip3d[200];   //[nElectron]
	float         Electron_mass[200];   //[nElectron]
	float         Electron_mvaId[200];   //[nElectron]
	float         Electron_pfmvaId[200];   //[nElectron]
	float         Electron_phi[200];   //[nElectron]
	float         Electron_pt[200];   //[nElectron]
	float         Electron_ptBiased[200];   //[nElectron]
	float         Electron_r9[200];   //[nElectron]
	float         Electron_sieie[200];   //[nElectron]
	float         Electron_sip3d[200];   //[nElectron]
	float         Electron_unBiased[200];   //[nElectron]
	float         Electron_vx[200];   //[nElectron]
	float         Electron_vy[200];   //[nElectron]
	float         Electron_vz[200];   //[nElectron]

	SkimTree.Branch("entry", &entry);
	SkimTree.Branch("event", &event);
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
	SkimTree.Branch("BToKEE_kIdx", &BToKEE_kIdx);
	SkimTree.Branch("BToKEE_l1Idx", &BToKEE_l1Idx);
	SkimTree.Branch("BToKEE_l2Idx", &BToKEE_l2Idx);
	SkimTree.Branch("BToKEE_pdgId", &BToKEE_pdgId);
	SkimTree.Branch("nElectrons", &nElectrons);
	SkimTree.Branch("Electron_pt", Electron_pt,"Electron_pt[nElectrons]/F");
	SkimTree.Branch("Electron_eta", Electron_eta,"Electron_eta[nElectrons]/F");
	SkimTree.Branch("Electron_phi", Electron_phi,"Electron_phi[nElectrons]/F");
	SkimTree.Branch("Electron_pfmvaId", Electron_pfmvaId,"Electron_pfmvaId[nElectrons]/F");
	SkimTree.Branch("Electron_isPF", Electron_isPF,"Electron_isPF[nElectrons]/O");
	SkimTree.Branch("Electron_deltaEtaSC", Electron_deltaEtaSC, "Electron_deltaEtaSC[nElectrons]/F");
	SkimTree.Branch("Electron_dxy", Electron_dxy, "Electron_dxy[nElectrons]/F");
	SkimTree.Branch("Electron_dxyErr", Electron_dxyErr, "Electron_dxyErr[nElectrons]/F");
	SkimTree.Branch("Electron_dz", Electron_dz,"Electron_dz[nElectrons]/F");
	SkimTree.Branch("Electron_dzErr", Electron_dzErr, "Electron_dzErr[nElectrons]/F");
	SkimTree.Branch("Electron_fBrem", Electron_fBrem, "Electron_fBrem[nElectrons]/F");
	SkimTree.Branch("Electron_hoe", Electron_hoe, "Electron_hoe[nElectrons]/F");
	SkimTree.Branch("Electron_ip3d", Electron_ip3d, "Electron_ip3d[nElectrons]/F");
	SkimTree.Branch("Electron_mass", Electron_mass, "Electron_mass[nElectrons]/F");
	SkimTree.Branch("Electron_mvaId", Electron_mvaId, "Electron_mvaId[nElectrons]/F");
	SkimTree.Branch("Electron_ptBiased", Electron_ptBiased, "Electron_ptBiased[nElectrons]/F");
	SkimTree.Branch("Electron_r9", Electron_r9, "Electron_r9[nElectrons]/F");
	SkimTree.Branch("Electron_sieie", Electron_sieie, "Electron_sieie[nElectrons]/F");
	SkimTree.Branch("Electron_sip3d", Electron_sip3d, "Electron_sip3d[nElectrons]/F");
	SkimTree.Branch("Electron_unBiased", Electron_unBiased, "Electron_unBiased[nElectrons]/F");
	SkimTree.Branch("Electron_vx", Electron_vx, "Electron_vx[nElectrons]/F");
	SkimTree.Branch("Electron_vy", Electron_vy, "Electron_vy[nElectrons]/F");
	SkimTree.Branch("Electron_vz", Electron_vz, "Electron_vz[nElectrons]/F");
	SkimTree.Branch("Electron_charge", Electron_charge, "Electron_charge[nElectrons]/I");
	SkimTree.Branch("Electron_pdgId", Electron_pdgId, "Electron_pdgId[nElectrons]/I");
	SkimTree.Branch("Electron_tightCharge", Electron_tightCharge, "Electron_tightCharge[nElectrons]/I");
	SkimTree.Branch("Electron_convVeto", Electron_convVeto, "Electron_convVeto[nElectrons]/O");
	SkimTree.Branch("Electron_isPFoverlap", Electron_isPFoverlap, "Electron_isPFoverlap[nElectrons]/O");
	int i;

	for(i=0;i<evt.fChain->GetEntries();i++){
		evt.fChain->GetEntry(i);

		if (i%10000==0)std::cout << "On entry " << i  << std::endl; 
		int counter=0;
		std::vector<double> B_sel_Vprob;
		std::vector<int> B_sel_Idx;

		for (int j = 0; j<evt.nBToKEE;j++){
			bool ele1_convveto = evt.Electron_convVeto[evt.BToKEE_l1Idx[j]];     
			bool ele2_convveto = evt.Electron_convVeto[evt.BToKEE_l1Idx[j]];     
			bool vtxFitSel = evt.BToKEE_fit_pt[j]>3.0 && evt.BToKEE_l_xy[j]/evt.BToKEE_l_xy_unc[j]>6.0 && evt.BToKEE_svprob[j]>0.1 &&evt. BToKEE_fit_cos2D[j]>0.99;
			bool ele1Sel = ele1_convveto && evt.BToKEE_fit_l1_pt[j]>0.5 && fabs(evt.BToKEE_fit_l1_eta[j])<2.4;  
			bool ele2Sel = ele2_convveto && evt.BToKEE_fit_l2_pt[j]>0.5 && fabs(evt.BToKEE_fit_l2_eta[j])<2.4;  
			// standard cut based selection: pt>1.5
			bool kSel = evt.BToKEE_fit_k_pt[j]>0.8 && fabs(evt.BToKEE_fit_k_eta[j])<2.4; 
			//stdcut
			//cut on leptons and kaons 
			if (kSel && ele1Sel && ele2Sel){
				if (vtxFitSel){ // cutting on whole event
					counter++;
		//			std::cout << "BToKEE passing selections n " << counter << "Vtxprob " <<evt.BToKEE_svprob[j] << std::endl; 
					B_sel_Vprob.push_back(evt.BToKEE_svprob[j]);
					B_sel_Idx.push_back(j);
				}
			}	



		}

		//std::cout << "array size " << B_sel_Vprob->size() << std::endl; 
		//sorting events passing selections in terms of sv_prob
		int idx =-1;
		if(B_sel_Idx.size()>0){
			for (int j =0; j<B_sel_Idx.size();j++){
				int temp=-99; 
				if (B_sel_Vprob.at(j)>temp){
					temp = B_sel_Vprob.at(j);
					idx = j;
				}


			}
		}

		if (idx != -1){
			//std::cout << "single selected B : index  " << idx << "probV : " << B_sel_Vprob.at(idx) << std::endl; 

			nElectrons = evt.nElectron;
			entry = i;
			event = evt.event;
			BToKEE_chi2=evt.BToKEE_chi2[idx];   //[nBToKEE]
			BToKEE_cos2D=evt.BToKEE_cos2D[idx];   //[nBToKEE]
			BToKEE_eta=evt.BToKEE_eta[idx];   //[nBToKEE]
			BToKEE_cos2D=evt.BToKEE_fit_cos2D[idx];   //[nBToKEE]
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
			BToKEE_kIdx=evt.BToKEE_kIdx[idx];   //[nBToKEE]
			BToKEE_l1Idx=evt.BToKEE_l1Idx[idx];   //[nBToKEE]
			BToKEE_l2Idx=evt.BToKEE_l2Idx[idx];   //[nBToKEE]
			BToKEE_pdgId=evt.BToKEE_pdgId[idx];   //[nBToKEE]

		//	std::cout << "filled btokee for the events, n electrons  " << nElectrons  << std::endl; 
			for (int k =0; k<evt.nElectron;k++){
				if(nElectrons>200) break;



					Electron_dxy[k]=evt.Electron_dxy[k];   //[nE
				Electron_dxyErr[k]=evt.Electron_dxyErr[k];   //
				Electron_dz[k]=evt.Electron_dz[k];   //[nEl
				Electron_dzErr[k]= evt.Electron_dzErr[k];   //[
				Electron_eta[k]=evt.Electron_eta[k];   //[nE
				Electron_fBrem[k]=evt.Electron_fBrem[k];   //[
				Electron_ip3d[k]=evt.Electron_ip3d[k];   //[n
				Electron_mass[k]=evt.Electron_mass[k];   //[n
				Electron_mvaId[k]=evt.Electron_mvaId[k];   //[
				Electron_pfmvaId[k]=evt.Electron_pfmvaId[k];   
				Electron_phi[k]=evt.Electron_phi[k];   //[nE
				Electron_pt[k]=evt.Electron_pt[k];   //[nEl
				Electron_ptBiased[k]=evt.Electron_ptBiased[k];   
				Electron_sip3d[k]=evt.Electron_sip3d[k];   //[
				Electron_unBiased[k]=evt.Electron_unBiased[k];   
				Electron_vx[k]=evt.Electron_vx[k];   //[nEl
				Electron_vy[k]=evt.Electron_vy[k];   //[nEl
				Electron_vz[k]=evt.Electron_vz[k];   //[nEl
				Electron_charge[k]= evt.Electron_charge[k];   //
				Electron_pdgId[k]= evt.Electron_pdgId[k];   //[
				Electron_convVeto[k]=evt.Electron_convVeto[k];   
				Electron_isLowPt[k]=evt.Electron_isLowPt[k];   
				Electron_isPF[k]=evt.Electron_isPF[k];   //[n
				Electron_isPFoverlap[k]=evt.Electron_isPFoverlap[k];
				Electron_charge[k]=evt.Electron_charge[k];   //
				Electron_pdgId[k]= evt.Electron_pdgId[k];   //[
				Electron_tightCharge[k]=evt.Electron_tightCharge[k];
				Electron_convVeto[k]=evt.Electron_convVeto[k];   
				Electron_isLowPt[k]=evt.Electron_isLowPt[k];   
				Electron_isPF[k]=evt.Electron_isPF[k];   //[n
				Electron_isPFoverlap[k]=evt.Electron_isPFoverlap[k];
			
			}
			SkimTree.Fill();
//			std::cout << "filling tree" << std::endl;	
		}
	}
	outfile->Write();
//	std::cout << "filling file" << std::endl;	
	outfile->Close();
	return 0;

}
