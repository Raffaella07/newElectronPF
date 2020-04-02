#include "../interface/BParkTools.h"
#include "TTree.h"
//#include <ROOT/RDataFrame.hxx>
//#include <ROOT/RVec.hxx>
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
	
	std::string INPUTDIR = argv[1];
	std::string outfile_f = argv[2];
	std::string outfile_e = argv[3];
	double low_pfmvaId = atof(argv[4]);
	double high_pfmvaId = atof(argv[5]);
	//std::string pattern_idx = argv[2];
	std::ofstream outf,oute;
/*	double Bin1_min =-4 ;
	double Bin1_max =-1.4 ;
	double Bin2_min =-4 ;
	double Bin2_max = -1.4 ;

	double step = 0.4;*/
	//int npoints = (int)(Bin1_max-Bin1_min)/step * (int)(Bin2_max-Bin2_min)/step;

	bool print=false;
	bool isMC;	
	TH1D* mB[2];
	mB[0] =new TH1D ("mBres", "mBres",50,4.7,5.7);
	mB[1] =new TH1D ("mBnores", "mBnores",50,4.7,5.7);
//	TH1D* mB_pfmvaId =new TH1D ("pfmvaId", "pfmvaId",38,-11,8);
//	TH2D* merit =new TH2D ("S/#sqrt(S+B)", "S/#sqrt(S+B)",4,Bin1_min,Bin1_max,4,Bin2_min,Bin2_max);
		
	TChain* chain = new TChain("Tree");
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
	
	std::string pattern;
	
	while (std::getline(input, pattern)) {
	
	/*for(int j =0; j<1000; j++){
	if (j%100==0)std::cout <<"looping on files..." << std::endl;
//	TFile * file;
//	file  =TFile::Open((INPUTDIR+"/"+pattern+"skimmedNANO_BPark_data_"+std::to_string(j)+"_2020Jan2016.root").c_str()); 
//	if (!file || file->IsZombie() ) continue;
	
//	TTree * point_tree =(TTree*)file->Get("Tree");
//	if (!point_tree) continue;
//	if (point_tree->GetEntries()==0 )continue;
//	file->Close("R");
//	delete file;
	chain->Add((INPUTDIR+"/"+pattern+"/BPark_mc_"+std::to_string(j)+"_2020Jan2016.root").c_str());
	
	}*/
	}	
	chain->Add("~/Bparking/CMSSW_10_2_15/src/macros/newElectronPF/analysis/mc.root");
	SelectedBClass evt;
	evt.Init(chain);
	
	
	std::cout << "succesfully loaded "  <<  evt.fChain->GetEntries()   <<  std::endl;
	int i;	

/*	for (int i2=0; i2 <(int)((Bin2_max-Bin2_min)/step);i2++){
	
	high_pfmvaId = Bin2_min + step *i2;

	std::cout << "high pfmvaid"   << high_pfmvaId << std::endl;
	
	for (int i1=0; i1 <(int)((Bin1_max-Bin1_min)/step);i1++){
	
	low_pfmvaId = Bin1_min + step *i1;
	std::cout << "low pfmvaid"   << low_pfmvaId << std::endl;*/
	
			for(i=0;i<evt.fChain->GetEntries();i++){
				
				evt.fChain->GetEntry(i);
//				if (i%10000 ==0)std::cout << "Looping on entry" <<i <<  std::endl;


				bool ele1LowPtBarrel =   evt.BToKEE_l1_pt< 5 && fabs(evt.BToKEE_l1_eta)< 1.5/* && evt.BToKEE_l1isPF*/;
				bool ele2LowPtBarrel =   evt.BToKEE_l2_pt< 5 && fabs(evt.BToKEE_l2_eta)< 1.5/* && evt.BToKEE_l2isPF*/;
				bool CutLowPt1 = evt.BToKEE_l1_pfmvaId > low_pfmvaId;
				bool CutLowPt2 = evt.BToKEE_l2_pfmvaId > low_pfmvaId;
				
				bool CutPt1 = evt.BToKEE_l1_pfmvaId > high_pfmvaId;
				bool CutPt2 = evt.BToKEE_l2_pfmvaId > high_pfmvaId;
				//mB_pfmvaId->Fill(evt.BToKEE_l1pfmvaId);
			//	mB_pfmvaId->Fill(evt.BToKEE_l2pfmvaId);
				
//				if (evt.BToKEE_pt >3.5/* && fabs(evt.BToKEE_l1eta)< 1.5 && fabs(evt.BToKEE_l2eta)< 1.5*/){
				if(evt.BToKEE_l1_pt<= 5 ){
					if( evt.BToKEE_l2_pt<= 5/* && fabs(evt.BToKEE_l2eta)< 1.5*/){
					
					if (evt.BToKEE_l1_pfmvaId > low_pfmvaId && evt.BToKEE_l2_pfmvaId > low_pfmvaId )
						{ 
								if (evt.BToKEE_mll_fullfit >3 &&  evt.BToKEE_mll_fullfit<3.3)mB[0]->Fill(evt.BToKEE_fit_mass,1.454);
								else if (evt.BToKEE_mll_llfit<2.5) mB[1]->Fill(evt.BToKEE_fit_mass,1.454);

						}
					}else{
					if (evt.BToKEE_l1_pfmvaId > low_pfmvaId  && evt.BToKEE_l2_pfmvaId > high_pfmvaId )
						{ 
								if (evt.BToKEE_mll_fullfit>3 &&  evt.BToKEE_mll_fullfit<3.3)mB[0]->Fill(evt.BToKEE_fit_mass,1.454);
								else if (evt.BToKEE_mll_llfit<2.5) mB[1]->Fill(evt.BToKEE_fit_mass,1.454);

						}

					}

				}else{
				
					if( evt.BToKEE_l2_pt< 5 /*&& fabs(evt.BToKEE_l2eta)< 1.5*/){
					
					if (evt.BToKEE_l1_pfmvaId > high_pfmvaId && evt.BToKEE_l2_pfmvaId > low_pfmvaId )
						{ 
								if (evt.BToKEE_mll_fullfit>3 &&  evt.BToKEE_mll_fullfit<3.3)mB[0]->Fill(evt.BToKEE_fit_mass,1.454);
								else if (evt.BToKEE_mll_fullfit<2.5) mB[1]->Fill(evt.BToKEE_fit_mass,1.454);

						}
					}else{
					if (evt.BToKEE_l1_pfmvaId > high_pfmvaId  && evt.BToKEE_l2_pfmvaId > high_pfmvaId )
						{ 
								if (evt.BToKEE_mll_fullfit>3 &&  evt.BToKEE_mll_raw<3.3)mB[0]->Fill(evt.BToKEE_fit_mass,1.454);
								else if (evt.BToKEE_mll_fullfit<2.5) mB[1]->Fill(evt.BToKEE_fit_mass,1.454);

						}

					}

				}
	
	}
	std::cout << "out of loop on entries" << std::endl;
	std::pair<double,double> SBres,SBnores;
	SBres = fit(mB[0],0,2,true,0);
	SBnores = fit(mB[1],1,1,false,SBres.first);
	std::cout << "low "<< low_pfmvaId << "high " << high_pfmvaId << "merit" << SBres.first << std::endl;
	std::cout << "low "<< low_pfmvaId << "high " << high_pfmvaId << "merit" << SBnores.first << std::endl;
//	merit->SetBinContent(merit->GetXaxis()->FindBin(low_pfmvaId+step/2),merit->GetYaxis()->FindBin(high_pfmvaId+step/2),fmerit);	

	outf.open((outfile_f+"_res").c_str(), std::ios_base::app);	 
	oute.open((outfile_f+"_nores").c_str(), std::ios_base::app);	 
	outf << low_pfmvaId << " " << high_pfmvaId << " " << SBres.first << " " << SBres.second << std::endl;
	oute << low_pfmvaId << " " << high_pfmvaId << " " << SBnores.first << " " << SBnores.second << std::endl;
//	outf << low_pfmvaId << " " << high_pfmvaId << " " <<  << std::endl;
	outf.close();
	oute.close();
	
	if(print){
	char select[30];
	sprintf(select,"_%.2f_%.2f",low_pfmvaId,high_pfmvaId);
	std::string lable = std::string(select);	
//	TFile * file  =TFile::Open(("histos_"+lable+".root").c_str(),"RECREATE"); 
	mB[0]->SaveAs(("histos_"+lable+"mBres.root").c_str());
	mB[1]->SaveAs(("histos_"+lable+"mBnores.root").c_str());
	}
//	mB_pfmvaId->SaveAs(("histos_"+lable+"pfmvaId.root").c_str());
//	SavePlot("M_{B}(GeV)",mB[0],"newElectronPF/mB_cut_res",false, NULL,false);
//	SavePlot("M_{B}(GeV)",mB[1],"newElectronPF/mB_cut_nores",false, NULL,false);
//	SavePlot("PFmvaId",mB_pfmvaId,"newElectronPF/mB_pfmvaId",false, NULL,false);
//	file->Close();
//	delete file;
	mB[0]->Reset();
	mB[1]->Reset();
//	}
//	}
//	SavePlot2D("PFMvaId^{cut}_{(2<p_{T}<5)GeV}","PFMvaId^{cut}_{(p_{T}>5GeV}",merit,"newElectronPF/merit_PF",false, false);
	return 0;
}
