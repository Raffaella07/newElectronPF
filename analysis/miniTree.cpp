
//#include "/interface/GBRForestTools.h"
#include "../interface/BParkTools.h"
#include "TTree.h"
//#include <ROOT/RDataFrame.hxx>
//#include <ROOT/RVec.hxx>
#include "../../../XGBoost-FastForest/include/fastforest.h"
#include <stdint.h>
//#include "TStopwatch.h"
#include <iostream>
#include <fstream>
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
#include "TAxis.h"
#include "TTree.h"
#include "TLatex.h"
#include "TCanvas.h"
#include "TGraph.h"
#include "TGraphErrors.h"
#include "TStyle.h"
#include "TString.h"
#include "TLorentzVector.h"
#include "TMVA/Tools.h"
#include "TMVA/Reader.h"
#include "TMVA/MethodBDT.h"

#define M_ELE 0.000510998

int main(int argc, char **argv){

	std::string INPUTDIR = argv[1] ;
	std::string pattern =argv[2];
	int ind = atoi(argv[3]);
	TChain* chain = new TChain("Tree");	
	//chain->Add((INPUTDIR+"/"+pattern+"/skimmedNANO_BPark_data_"+std::to_string(ind)+"_2020Jan2016.root").c_str());
	chain->Add("nores.root");

	BSixCand evt; 
	evt.Init(chain);

	int i,j,k,ncat;
	ncat = 3;	
	TFile* outfile = TFile::Open(argv[4],"RECREATE");
	std::cout <<  outfile << std::endl;
	TTree mini("Mini", "A skimmed tree containing only information to fit mb spectrum");



	double B_mass,ll_mass, BDT_set0,BDT_set1;
	int cat0, cat1,entry;
	
	int iHLT_Mu12_IP6, iHLT_Mu9_IP6, is_MC;

	mini.Branch("entry", &entry);
	mini.Branch("HLT_Mu12_IP6", &iHLT_Mu12_IP6, "iHLT_Mu12_IP6/I");
	mini.Branch("HLT_Mu9_IP6", &iHLT_Mu9_IP6, "iHLT_Mu9_IP6/I");

	mini.Branch("cat0", &cat0);
	mini.Branch("cat1", &cat1);
	mini.Branch("BDT_0", &BDT_set0);
	mini.Branch("BDT_1", &BDT_set1);
	mini.Branch("B_mass", &B_mass);
	mini.Branch("ll_mass" ,  &ll_mass);
	mini.Branch("is_MC" ,  &is_MC);



	std::string categories[3][2];

	categories[0][0] = "_newPF_2Bkg";
	categories[1][0] = "_PF_LowPt";
	categories[2][0] = "_LowPt_LowPt";

	categories[0][1] = "_ele2PF";
	categories[1][1] = "_ele2Low_IDover2";
	categories[2][1] = "_ele2Low_IDunder2";


	Float_t normPt_l1,normPt_l2, normPt_k,normPt_B,B_iso,l1_iso,l2_iso,k_iso,l1_pfmvaId,l2_pfmvaId,l1_mvaId,l2_mvaId,cos2D,deltaZ,ptImb,Vtxprob,dxy, l1_sig, l2_sig,k_sig,maxDR,minDR,B_pt;
	std::vector<std::string> feat = {"f0","f1", "f2","f3","f4","f5","f6","f7","f8","f9","f10","f11","f12","f13","f14","f15","f16",  "f17", "f18","f19","f20","f21"};
	std::string weights[ncat][2];
	std::vector<FastForest> fast[2];
	for (int k=0; k< 2;k++){
		for(int i =0; i<3;i++){
		//	if (i==0 && k ==0) weights[i][k] = "/afs/cern.ch/work/r/ratramon/Bparking/CMSSW_10_2_15/src/macros/LowPtElectrons/LowPtElectrons/macros/models/2020Apr/bdt_cmssw_mva_id/xgb_model.txt";	
			weights[i][k] = "/afs/cern.ch/work/r/ratramon/Bparking/CMSSW_10_2_15/src/LowPtElectrons/LowPtElectrons/macros/models/2020Apr"+categories[i][k]+"/bdt_cmssw_mva_id/xgb_model.txt";	
			FastForest initializator((weights[i][k]).c_str(), feat);
			fast[k].push_back(initializator);
		}
	}

	for(i=0;i<evt.fChain->GetEntries();i++){


	//std::cout <<  "debug" << std::endl;
		evt.fChain->GetEntry(i);
		for ( j =0; j <evt.nSaved;j++){
			int theB = j;

			normPt_l1=evt.BToKEE_l1_pt[theB]/evt.BToKEE_mass[theB];   //[nBToKEE]
			normPt_l2=evt.BToKEE_l2_pt[theB]/evt.BToKEE_mass[theB];   //[nBToKEE]
			normPt_k=evt.BToKEE_k_pt[theB]/evt.BToKEE_mass[theB];   //[nBToKEE]
			normPt_B=evt.BToKEE_pt[theB]/evt.BToKEE_mass[theB];   //[nBToKEE]
			B_iso = evt.BToKEE_iso04[theB];
			k_iso = evt.BToKEE_k_iso04[theB];
			l1_iso = evt.BToKEE_l1_iso04[theB];
			l2_iso = evt.BToKEE_l2_iso04[theB];
			l1_pfmvaId = evt.BToKEE_l1_pfmvaId[theB];
			l2_pfmvaId = evt.BToKEE_l2_pfmvaId[theB];
			l1_mvaId = evt.BToKEE_l1_mvaId[theB];
			l2_mvaId = evt.BToKEE_l2_mvaId[theB];
			cos2D = evt.BToKEE_cos2D[theB];
			deltaZ = evt.BToKEE_DeltaZ[theB];
			ptImb = evt.BToKEE_ptImb[theB];
			Vtxprob = evt.BToKEE_svprob[theB];
			dxy = evt.BToKEE_l_xy[theB]/evt.BToKEE_l_xy_unc[theB];
			l1_sig = evt.BToKEE_l1_dxySig[theB];
			l2_sig = evt.BToKEE_l2_dxySig[theB];
			k_sig = evt.BToKEE_k_dxySig[theB];
			maxDR = evt.BToKEE_maxDR[theB];
			minDR = evt.BToKEE_minDR[theB];

			std::vector<float> vec = {normPt_l1,normPt_l2, normPt_k,normPt_B,B_iso,l1_iso,l2_iso,k_iso,l1_pfmvaId,l2_pfmvaId,l1_mvaId,l2_mvaId,cos2D,deltaZ,ptImb,Vtxprob,dxy, l1_sig, l2_sig,k_sig,maxDR,minDR};
			bool cat[3][2];

			cat[0][0] = evt.BToKEE_l1_isPF[j] && evt.BToKEE_l2_isPF[j];
			cat[1][0] = (evt.BToKEE_l1_isPF[j] && evt.BToKEE_l2_isLowPt[j]) || (evt.BToKEE_l2_isPF[j] && evt.BToKEE_l1_isLowPt[j]);
			cat[2][0] = evt.BToKEE_l1_isLowPt[j] && evt.BToKEE_l2_isLowPt[j];

			cat[0][1] = evt.BToKEE_l2_isPF[j];
			cat[1][1] = evt.BToKEE_l2_isLowPt[j] && evt.BToKEE_l2_mvaId[j]>2;
			cat[2][1] = evt.BToKEE_l2_isLowPt[j] && evt.BToKEE_l2_mvaId[j]<2;	

			for (k =0; k<3;k++){

				if(cat[k][0]) {
					BDT_set0 = fast[0].at(k)(vec.data());
					cat0 = k;

				//	std::cout << evt.BToKEE_fit_mass[j] << std::endl;
				//if (k ==0) std::cout << "BDT score PF PF " << BDT_set0 << std::endl;
				}
				if(cat[k][1]){
					BDT_set1 = fast[1].at(k)(vec.data());
					cat1 =k;
				}


			}
			if (BDT_set0 >0 || BDT_set1>0){
				entry = i;
				iHLT_Mu12_IP6 = evt.HLT_Mu12_IP6;
				iHLT_Mu9_IP6 = evt.HLT_Mu9_IP6;
				B_mass = evt.BToKEE_fit_mass[j];
				ll_mass = evt.BToKEE_mll_fullfit[j];
				is_MC = evt.BToKEE_isMC[j];
				//if (BDT_set0>5 && ll_mass >3.0 && ll_mass<3.3 )std::cout << "__________________"<< B_mass << std::endl;


				mini.Fill();
			}

		}			


	}

	outfile->Write();
	outfile->Close();
}

