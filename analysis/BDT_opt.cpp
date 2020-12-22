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

	std::string INPUTDIR = argv[1];	
	std::string pattern= argv[2];
	int set = atoi(argv[3]);	
	std::string outfile_f = argv[4];
	double BDT_cut = atof(argv[5]);
	double TMVA_cut = atof(argv[6]);
	//	TH1D* mB_pfmvaId =new TH1D ("pfmvaId", "pfmvaId",38,-11,8);
	//	TH2D* merit =new TH2D ("S/#sqrt(S+B)", "S/#sqrt(S+B)",4,Bin1_min,Bin1_max,4,Bin2_min,Bin2_max);

	TChain* chain = new TChain("Tree");
	//TProof* p = TProof::Open("");
	//std::cout <<"Getting input files from directory" <<  INPUTDIR+"/"+pattern << std::endl;
	/*	int empty_dir= 0;
		DIR* dir = NULL;
		struct dirent *dir_entry;
		dir = opendir((INPUTDIR+"/"+pattern).c_str());
		while(dir_entry=readdir(dir)){
		empty_dir++;
		if (empty_dir == 4) break;
		}
		if (empty_dir <= 2) return 0;*/
	std::ifstream input("pattern.txt");
	if(!input) {
		std::cout << "Cannot open input file."<< std::endl;
		return 1;
	}


	while (std::getline(input, pattern)) {
		for(int j =0; j<1000; j++){
			if (j%100==0)std::cout <<"looping on files..." << std::endl;
			//	TFile * file;
			//	file  =TFile::Open((INPUTDIR+"/"+pattern+"skimmedNANO_BPark_data_"+std::to_string(j)+"_2020Jan2016.root").c_str()); 
			//	if (!file || file->IsZombie() ) continue;

			//	TTree * point_tree =(TTree*)file->Get("Tree");
			//	if (!point_tree) continue;
			//	if (point_tree->GetEntries()==0 )continue;
			//	file->Close("R");
			//	delete file;
			chain->Add((INPUTDIR+"/"+pattern+"/skimmedNANO_BPark_data_"+std::to_string(j)+"_2020Jan2016.root").c_str());
		}
	}	
	BSixCand evt; 
	evt.Init(chain);
	//std::string pattern_idx = argv[2];
	std::ofstream outf;
	/*	double Bin1_min =-4 ;
		double Bin1_max =-1.4 ;
		double Bin2_min =-4 ;
		double Bin2_max = -1.4 ;

		double step = 0.4;*/
	//int npoints = (int)(Bin1_max-Bin1_min)/step * (int)(Bin2_max-Bin2_min)/step;

	bool print=false;
	bool isMC;	
	TH1D* mB[2][3];
	for (int k =0; k <3 ;k++){

		mB[0][k] =new TH1D (("mBres"+std::to_string(k)).c_str(), ("mBres"+std::to_string(k)).c_str(),50,4.7,5.7);
		mB[1][k] =new TH1D (("mBnores"+std::to_string(k)).c_str(), ("mBnores"+std::to_string(k)).c_str(),50,4.7,5.7);
	}
	//mB[0] =new TH1D ("mBres", "mBres",50,4.7,5.7);
	//	mB[1] =new TH1D ("mBnores", "mBnores",50,4.7,5.7);
	//	TH1D* mB_pfmvaId =new TH1D ("pfmvaId", "pfmvaId",38,-11,8);
	//	TH2D* merit =new TH2D ("S/#sqrt(S+B)", "S/#sqrt(S+B)",4,Bin1_min,Bin1_max,4,Bin2_min,Bin2_max);

//	}	
	//	chain->Add("~/Bparking/CMSSW_10_2_15/src/macros/newElectronPF/analysis/mc.root");
	std::cout << "succesfully loaded "  <<  evt.fChain->GetEntries()   <<  std::endl;

	std::string filename = "/afs/cern.ch/user/r/ratramon/Bparking/CMSSW_10_2_15/src/macros/LowPtElectrons/LowPtElectrons/macros/models/2020Apr/bdt_cmssw_mva_id/xgb_model.txt";	

	//std::vector<std::string> feat = {"normPt_l1","normPt_l2", "normPt_k","normPt_B","B_iso","l1_iso","l2_iso","k_iso","l1_pfmvaId","l2_pfmvaId","l1_mvaId","l2_mvaId","cos2D","deltaZ","ptImb","Vtxprob","dxy",  "l1_sig", "l2_sig","k_sig","maxDR","minDR"};
	std::vector<std::string> feat = {"f0","f1", "f2","f3","f4","f5","f6","f7","f8","f9","f10","f11","f12","f13","f14","f15","f16",  "f17", "f18","f19","f20","f21"};
	FastForest fastForest(filename.c_str(), feat);
	//	int y = XGBoosterLoadModel(booster,filename.c_str());
	//	g_learner = std::make_unique<Learner>(Learner::Create({}));
	//std::unique_ptr<dmlc::Stream> fi(
	//    dmlc::Stream::Create(filename.c_str(), "r"));
	// g_learner->Load(fi.get());	
	std::cout << "model loaded "   <<  std::endl;
	int i;	
	TMVA::Reader* reader = new TMVA::Reader();
	Float_t normPt_l1,normPt_l2, normPt_k,normPt_B,B_iso,l1_iso,l2_iso,k_iso,l1_pfmvaId,l2_pfmvaId,l1_mvaId,l2_mvaId,cos2D,deltaZ,ptImb,Vtxprob,dxy, l1_sig, l2_sig,k_sig,maxDR,minDR,B_pt;
	// reader->AddVariable(" BToKEE_l1_pt/BToKEE_mass", &normPt_l1 );
	reader->AddVariable( "BToKEE_l2_pt/BToKEE_mass",  &normPt_l2 );
	reader->AddVariable( "BToKEE_fit_k_pt/BToKEE_mass",  &normPt_k );
	reader->AddVariable( "BToKEE_l1_pfmvaId",                &l1_pfmvaId );
	reader->AddVariable( "BToKEE_l2_pfmvaId",                &l2_pfmvaId );
	reader->AddVariable( "BToKEE_l_xy/BToKEE_l_xy_unc",                &dxy );
	reader->AddVariable( "BToKEE_svprob",                &Vtxprob );
	reader->AddVariable( "BToKEE_pt",                &B_pt );
	reader->AddVariable( "BToKEE_cos2D",                &cos2D );
	reader->AddVariable( "BToKEE_maxDR",                &maxDR );
	reader->AddVariable( "BToKEE_minDR",                &minDR );

	reader->BookMVA("BDT::BDT","Test_tmvaBDT.weights.xml");

	for(i=0;i<evt.fChain->GetEntries();i++){

		evt.fChain->GetEntry(i);
		if (i%10000 ==0)std::cout << "Looping on entry" <<i <<  std::endl;

		for(int j=0; j< evt.nSaved; j++){
	//		bool ele1_convveto = evt.Electron_convVeto[evt.BToKEE_l1Idx[j]];     
	//		bool ele2_convveto = evt.Electron_convVeto[evt.BToKEE_l1Idx[j]];     
			bool vtxFitSel = evt.BToKEE_fit_pt[j]>3.0 && evt.BToKEE_l_xy_sig[j]>6.0 && evt.BToKEE_svprob[j]>0.1 &&evt. BToKEE_cos2D[j]>0.99;
			bool ele1Sel = evt.BToKEE_fit_l1_pt[j]>0.5 && fabs(evt.BToKEE_fit_l1_eta[j])<2.4;  
			bool ele2Sel = evt.BToKEE_fit_l2_pt[j]>0.5 && fabs(evt.BToKEE_fit_l2_eta[j])<2.4;  
			// standard cut based selection: pt>1.5
			bool kSel = evt.BToKEE_fit_k_pt[j]>0.8 && fabs(evt.BToKEE_fit_k_eta[j])<2.4; 
			bool stdCut = kSel && ele1Sel && ele2Sel && vtxFitSel;
			if (evt.BToKEE_l1_isPF[j] && evt.BToKEE_l2_isPF[j] ){
				int theB = j;
				//				std::cout << "___________________________________________BDT variables "  << dxy << " " << minDR <<  " " << maxDR << " "  << cos2D << " "  << B_pt << " "  << Vtxprob << std::endl; 
				//normPt_l1 = evt.BToKEE_l1_pt[j]/evt.BToKEE_mass[j];
				normPt_l2 = evt.BToKEE_fit_l2_pt[j]/evt.BToKEE_mass[j];
				normPt_k = evt.BToKEE_fit_k_pt[j]/evt.BToKEE_mass[j];
				l1_pfmvaId = evt.BToKEE_l1_pfmvaId[theB];
				l2_pfmvaId = evt.BToKEE_l2_pfmvaId[theB];
				dxy = evt.BToKEE_l_xy[j]/evt.BToKEE_l_xy_unc[j];
				Vtxprob = evt.BToKEE_svprob[j];
				B_pt = evt.BToKEE_pt[j];
				cos2D = evt.BToKEE_cos2D[j];
				maxDR = evt.BToKEE_maxDR[j];
				minDR = evt.BToKEE_minDR[j];
			/*	TVector3 l1_p,l2_p,r,k_p, pair_proj,k_proj;

				l1_p.SetPtEtaPhi(evt.BToKEE_l1_pt[theB],evt.BToKEE_l1_eta[theB],evt.BToKEE_l1_phi[theB]);
				l2_p.SetPtEtaPhi(evt.BToKEE_l2_pt[theB],evt.BToKEE_l2_eta[theB],evt.BToKEE_l2_phi[theB]);
				k_p.SetPtEtaPhi(evt.BToKEE_k_pt[theB],evt.BToKEE_k_eta[theB],evt.BToKEE_k_phi[theB]);
				r.SetXYZ(evt.BToKEE_vtx_x[theB]-evt.PV_x,evt.BToKEE_vtx_y[theB]-evt.PV_y,evt.BToKEE_vtx_z[theB]-evt.PV_z);

				pair_proj = r.Cross(l1_p+l2_p);
				k_proj = r.Cross(k_p);*/
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
				//	std::cout <<"check" << normPt_l1 << "  "  << "  " << normPt_l2 << "  " << normPt_k<< "  " << normPt_B << "  " <<B_iso << "  " <<k_iso << "  " <<l1_iso << "  " <<l2_iso << "  " << l1_pfmvaId << "  " <<l2_pfmvaId << "  " <<l1_mvaId << "  " <<l2_mvaId << "  " << cos2D << "  " << deltaZ <<  std::endl;

				//	std::cout <<"check" << ptImb << "  " << Vtxprob << "  " << dxy << "  " << k_sig<< "  " << l1_sig << "  " <<l2_sig << "  " << maxDR << "  " <<minDR <<  std::endl;

				std::vector<float> vec = {normPt_l1,normPt_l2, normPt_k,normPt_B,B_iso,l1_iso,l2_iso,k_iso,l1_pfmvaId,l2_pfmvaId,l1_mvaId,l2_mvaId,cos2D,deltaZ,ptImb,Vtxprob,dxy, l1_sig, l2_sig,k_sig,maxDR,minDR};
				float var_xgb= fastForest(vec.data());
				float var_tmva= reader->EvaluateMVA("BDT::BDT");
				//				float var = evt.BDT_score(j);
				if(var_xgb > BDT_cut){

					std::cout << "BDT score " <<vec.at(3) << " " <<  var_xgb << std::endl;

					if (evt.BToKEE_mll_fullfit[j] >3 &&  evt.BToKEE_mll_fullfit[j]<3.3)mB[0][0]->Fill(evt.BToKEE_fit_mass[j]);
					else if (evt.BToKEE_mll_llfit[j]<2.5) mB[1][0]->Fill(evt.BToKEE_fit_mass[j]);

				}
				if(var_tmva > TMVA_cut){


					if (evt.BToKEE_mll_fullfit[j] >3 &&  evt.BToKEE_mll_fullfit[j]<3.3)mB[0][1]->Fill(evt.BToKEE_fit_mass[j]);
					else if (evt.BToKEE_mll_llfit[j]<2.5) mB[1][1]->Fill(evt.BToKEE_fit_mass[j]);

				}
				if(stdCut){


					if (evt.BToKEE_mll_fullfit[j] >3 &&  evt.BToKEE_mll_fullfit[j]<3.3)mB[0][2]->Fill(evt.BToKEE_fit_mass[j]);
					else if (evt.BToKEE_mll_llfit[j]<2.5) mB[1][2]->Fill(evt.BToKEE_fit_mass[j]);

				}
			}


		}
	}
	double SB[3][5];
	std::cout << "out of loop on entries" << std::endl;
	std::pair<double,double> SBres,SBnores;
	fit(mB[0][0],0,2,true,1,0,SB[0]);
	fit(mB[0][1],0,2,true,1,1,SB[1]);
	fit(mB[0][2],0,2,true,1,2,SB[2]);
	//fit(mB[1],1,1,false,0,1,SB[1]);
	//std::cout << "low "<< low_pfmvaId << "high " << high_pfmvaId << "merit" << SBres.first << std::endl;
	//std::cout << "low "<< low_pfmvaId << "high " << high_pfmvaId << "merit" << SBnores.first << std::endl;
	//	merit->SetBinContent(merit->GetXaxis()->FindBin(low_pfmvaId+step/2),merit->GetYaxis()->FindBin(high_pfmvaId+step/2),fmerit);	

	outf.open((outfile_f+"_res").c_str(), std::ios_base::app);	 
	//oute.open((outfile_f+"_nores").c_str(), std::ios_base::app);	 
	outf << BDT_cut  << " " << SB[0][0] << " " << SB[0][2] << std::endl;
	//oute << low_pfmvaId << " " << high_pfmvaId << " " << SBnores.first << " " << SBnores.second << std::endl;
	//	outf << low_pfmvaId << " " << high_pfmvaId << " " <<  << std::endl;
	outf.close();

	if(print){
		char select[30];
		sprintf(select,"_%.2f_",BDT_cut);
		std::string lable = std::string(select);	
		//	TFile * file  =TFile::Open(("histos_"+lable+".root").c_str(),"RECREATE"); 
	//	mB[0]->SaveAs(("histos_"+lable+"mBres.root").c_str());
	//	mB[1]->SaveAs(("histos_"+lable+"mBnores.root").c_str());
	}
	//	mB_pfmvaId->SaveAs(("histos_"+lable+"pfmvaId.root").c_str());
	//	SavePlot("M_{B}(GeV)",mB[0],"newElectronPF/mB_cut_res",false, NULL,false);
	//	SavePlot("M_{B}(GeV)",mB[1],"newElectronPF/mB_cut_nores",false, NULL,false);
	//	SavePlot("PFmvaId",mB_pfmvaId,"newElectronPF/mB_pfmvaId",false, NULL,false);
	//	file->Close();
	//	delete file;
	mB[0][0]->Reset();
	//mB[1][0]->Reset();
	mB[0][1]->Reset();
//	mB[1][1]->Reset();
	mB[0][2]->Reset();
//	mB[1][2]->Reset();
	//	}
	//	}
	//	SavePlot2D("PFMvaId^{cut}_{(2<p_{T}<5)GeV}","PFMvaId^{cut}_{(p_{T}>5GeV}",merit,"newElectronPF/merit_PF",false, false);
	return 0;
	}
