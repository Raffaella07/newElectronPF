
//#include "/interface/GBRForestTools.h"
#include "../interface/BNanoClass.h"
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
#define M_ELE 0.000510998

int main(int argc, char **argv){

	std::string inputfile = argv[1] ; //file containing list of input paths
	int input_idx = atoi(argv[2]); // file index
	TChain* chain= new TChain("Events");
	std::ifstream infile,file;
	int  line_count ;
	infile.open(inputfile.c_str());	
	std::string linec;
	bool isMC;
	if(infile.fail()) // checks to see if file opended 
	{ 
		std::cout << "error" << std::endl; 
		return 1; // no point continuing if the file didn't open...
	}else{while(std::getline(infile, linec)){
		line_count++;	
	}	
	}
	std::string line;
	file.open(inputfile.c_str());	
	std::cout << " n lines " << line_count << std::endl;
	std::cout << "Loading input from /eos/cms/store/group/cmst3/group/bpark/BParkingNANO_2020Jan16/" << std::endl;
	int counter =0;
	while(std::getline(file, line)) // reads file to end of *file*, not line
	{ 	bool temp;
		if (counter ==0)
		{
			//	infile >> temp; // read first column number
			isMC = atoi(line.c_str()); //first line of file contains flag for mc/data 
			std::cout << isMC << std::endl;
		}	else{
			//	infile >> file; // read first column number
			if (counter ==input_idx+1){
			std::ifstream file(line.c_str());
			bool good=false;	
			int tries;
			if (counter < line_count){	do{
				good = file.good();
	//			std::cout << "in while " << std::endl;	

				}while(!good);
				if(good){
				 chain->Add(line.c_str());
				std::cout << line << std::endl;
				break;
				}
			}
		}


	}
		counter++;
	}
	if (isMC)std::cout <<" analyzing Montecarlo dataset: " << inputfile << std::endl;
	else std::cout <<"analyzing dataset: " << inputfile << std::endl;
	std::cout << "loaded file number " << counter << " as input:  " << line  << std::endl;

	BNanoClass evt; 
	evt.Init(chain);

	int i,j,k,ncat;
	ncat = 3;	
	TFile* outfile = TFile::Open(argv[3],"RECREATE");
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
//	mini.Branch("is_MC" ,  &is_MC);



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
		for ( j =0; j <evt.nBToKEE;j++){
			int theB = j;

			normPt_l1=evt.Electron_pt[evt.BToKEE_l1Idx[theB]]/evt.BToKEE_mass[theB];   //[nBToKEE]
			normPt_l2=evt.Electron_pt[evt.BToKEE_l2Idx[theB]]/evt.BToKEE_mass[theB];   //[nBToKEE]
			normPt_k=evt.ProbeTracks_pt[evt.BToKEE_kIdx[theB]]/evt.BToKEE_mass[theB];   //[nBToKEE]
			normPt_B=evt.BToKEE_pt[theB]/evt.BToKEE_mass[theB];   //[nBToKEE]
			B_iso = evt.BToKEE_b_iso04[theB];
			k_iso = evt.BToKEE_k_iso04[theB];
			l1_iso =evt.BToKEE_l1_iso04[theB];
			l2_iso = evt.BToKEE_l2_iso04[theB];
			l1_pfmvaId = evt.Electron_pfmvaId[evt.BToKEE_l1Idx[theB]];
			l2_pfmvaId = evt.Electron_pfmvaId[evt.BToKEE_l2Idx[theB]];
			l1_mvaId = evt.Electron_mvaId[evt.BToKEE_l1Idx[theB]];
			l2_mvaId = evt.Electron_mvaId[evt.BToKEE_l2Idx[theB]];
			cos2D = evt.BToKEE_cos2D[theB];
			deltaZ = evt.BToKEE_vtx_z[theB]-evt.PV_z;
			Vtxprob = evt.BToKEE_svprob[theB];
			dxy = evt.BToKEE_l_xy[theB]/evt.BToKEE_l_xy_unc[theB];
			l1_sig = evt.Electron_dxy[evt.BToKEE_l1Idx[theB]]/evt.Electron_dxyErr[evt.BToKEE_l1Idx[theB]];
			l2_sig = evt.Electron_dxy[evt.BToKEE_l2Idx[theB]]/evt.Electron_dxyErr[evt.BToKEE_l2Idx[theB]];
			k_sig = evt.ProbeTracks_dxyS[evt.BToKEE_kIdx[theB]];
			maxDR = evt.BToKEE_maxDR[theB];
			minDR = evt.BToKEE_minDR[theB];

			//compute pt imbalance from scratch
				TVector3 l1_p,l2_p,r,k_p, pair_proj,k_proj;
				l1_p.SetPtEtaPhi(evt.Electron_pt[evt.BToKEE_l1Idx[theB]],evt.Electron_eta[evt.BToKEE_l1Idx[theB]],evt.Electron_phi[evt.BToKEE_l1Idx[theB]]);
				l2_p.SetPtEtaPhi(evt.Electron_pt[evt.BToKEE_l2Idx[theB]],evt.Electron_eta[evt.BToKEE_l2Idx[theB]],evt.Electron_phi[evt.BToKEE_l2Idx[theB]]);
				l2_p.SetPtEtaPhi(evt.ProbeTracks_pt[evt.BToKEE_kIdx[theB]],evt.ProbeTracks_eta[evt.BToKEE_kIdx[theB]],evt.ProbeTracks_phi[evt.BToKEE_kIdx[theB]]);
				r.SetXYZ(evt.BToKEE_vtx_x[theB]-evt.PV_x,evt.BToKEE_vtx_y[theB]-evt.PV_y,evt.BToKEE_vtx_z[theB]-evt.PV_z);

				pair_proj = r.Cross(l1_p+l2_p);
				k_proj = r.Cross(k_p);

				ptImb = pair_proj.Mag()/k_proj.Mag();

			std::vector<float> vec = {normPt_l1,normPt_l2, normPt_k,normPt_B,B_iso,l1_iso,l2_iso,k_iso,l1_pfmvaId,l2_pfmvaId,l1_mvaId,l2_mvaId,cos2D,deltaZ,ptImb,Vtxprob,dxy, l1_sig, l2_sig,k_sig,maxDR,minDR};
			bool cat[3][2];

			cat[0][0] = evt.Electron_isPF[evt.BToKEE_l1Idx[theB]] && evt.Electron_isPF[evt.BToKEE_l2Idx[theB]];
			cat[1][0] = (evt.Electron_isPF[evt.BToKEE_l1Idx[theB]] && evt.Electron_isLowPt[evt.BToKEE_l2Idx[theB]]) || (evt.Electron_isPF[evt.BToKEE_l2Idx[theB]] && evt.Electron_isLowPt[evt.BToKEE_l1Idx[theB]]);
			cat[2][0] = evt.Electron_isLowPt[evt.BToKEE_l1Idx[theB]] && evt.Electron_isLowPt[evt.BToKEE_l2Idx[theB]];

			cat[0][1] = evt.Electron_isPF[evt.BToKEE_l2Idx[theB]];
			cat[1][1] = evt.Electron_isLowPt[evt.BToKEE_l2Idx[theB]] &&  evt.Electron_mvaId[evt.BToKEE_l2Idx[theB]]>2;
			cat[2][1] = evt.Electron_isLowPt[evt.BToKEE_l2Idx[theB]] &&  evt.Electron_mvaId[evt.BToKEE_l2Idx[theB]]<2;	

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
				//is_MC = evt.BToKEE_isMC[j];
				//if (BDT_set0>5 && ll_mass >3.0 && ll_mass<3.3 )std::cout << "__________________"<< B_mass << std::endl;


				mini.Fill();
			}

		}			


	}

	outfile->Write();
	outfile->Close();
}

