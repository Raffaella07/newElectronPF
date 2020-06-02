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
#include "TSystem.h"
#include "TString.h"
#include "TLorentzVector.h"
#include "TMVA/Tools.h"
#include "TMVA/Reader.h"
#include "TMVA/MethodBDT.h"
#include "../../../CommonTools/StatTools.cc"

#define M_ELE 0.000510998

int main(int argc, char **argv){

	std::string INPUTDIR = argv[1] ;
	double set = atof(argv[2]);
	int category = atof(argv[3]);
	double cut = atof(argv[4]);
	TChain* chain = new TChain("Mini");	
	
	std::ofstream outf,oute,outf_nr,oute_nr;

	int i, j;
	
	
	std::ifstream input("pattern.txt");
	if(!input) {
		std::cout << "Cannot open input file."<< std::endl;
		return 1;
	}
	
	std::string pattern;
	//gSystem->cd((INPUTDIR).c_str());	
	system("pwd" );	

	while (std::getline(input, pattern)) {
	for (i=0; i< 1000;i++){
	chain->Add((INPUTDIR+"/"+pattern+"/"+std::to_string(i)+".root").c_str());
//	std::cout << INPUTDIR+"/"+pattern+"/"+std::to_string(i)+".root" << std::endl;
	}

	
	}

	BminiTree evt;
	evt.Init(chain);
        std ::cout << "successfully loaded" << evt.fChain->GetEntries() << "entries" << std::endl;
	TH1D * mB[2];
	mB[0] = new TH1D("mBres","mBres",50,4.7,5.7);	
	mB[1] = new TH1D("mBnores","mBnores",50,4.7,5.7);	


	for(i=0;i<evt.fChain->GetEntries();i++){
	if (i%1000000==0) std ::cout << "on entry" << i << std::endl;			
				evt.fChain->GetEntry(i);
				double score;
				if (set ==0 && evt.cat0 == category) {
					if (evt.BDT_0>cut){


								if (evt.ll_mass>2.45 &&  evt.ll_mass<3.25)mB[0]->Fill(evt.B_mass);
								else if (evt.ll_mass<2.45) mB[1]->Fill(evt.B_mass);
					}


				}
				else if (set ==1 && evt.cat1 == category) {
				//	std::cout << "first new  category bdt put  " << evt.BDT_1 << std::endl;
					if (evt.BDT_1>cut){


								if (evt.ll_mass>2.45 &&  evt.ll_mass<3.25)mB[0]->Fill(evt.B_mass);
								else if (evt.ll_mass<2.45) mB[1]->Fill(evt.B_mass);
					}


				}
			/*	else if (set ==1 && category != 0 && (evt.cat1== 1 || evt.cat1 == 2)){ 
					std::cout << "third and second category merged: bdt put  " << evt.BDT_1 << std::endl;
					if (evt.BDT_1>cut){


								if (evt.ll_mass>3 &&  evt.ll_mass<3.3)mB[0]->Fill(evt.B_mass);
								else if (evt.ll_mass<2.5) mB[1]->Fill(evt.B_mass);
					}


				}*/
				
	}

	double SB[6];
//	gSystem->cd("/afs/cern.ch/work/r/ratramon/Bparking/CMSSW_10_2_15/src/macros/newElectronPF/analysis");	
	fit(mB[0],0,2,true,set,category,cut,SB);
	outf.open(("BDT_scanSB_"+std::to_string(set)+"_"+std::to_string(category)+".txt").c_str(), std::ios_base::app);	 

	outf << cut  << " " << SB[0] << " "<< SB[1]<< " " << SB[2] << " " << SB[3] << std::endl;
	double merit = SB[0]/sqrt(SB[0]+SB[2]);
	double merit_err = sqrt(pow((SB[0]+2*SB[2])*SB[1]/(2*pow(SB[0]+SB[2],1.5)),2)+pow(SB[0]*.5*SB[3]/pow(SB[0]+SB[2],1.5),2));
	//StatTools stat();
//	double ZBi = stat.computeZBi(SB[0]+SB[2],SB[2],SB[3]); 
	oute.open(("BDT_scanM_"+std::to_string(set)+"_"+std::to_string(category)+".txt").c_str(), std::ios_base::app);	 
	oute << cut  << " " << merit << " "<< merit_err << std::endl;
	fit(mB[1],0,2,false,set,category,cut,SB);
	merit = SB[0]/sqrt(SB[0]+SB[2]);
	merit_err = sqrt(pow((SB[0]+2*SB[2])*SB[1]/(2*pow(SB[0]+SB[2],1.5)),2)+pow(SB[0]*.5*SB[3]/pow(SB[0]+SB[2],1.5),2));
	double merit_pred = SB[4]/sqrt(SB[4]+SB[2]);
	double merit_err_pred = sqrt(pow((SB[4]+2*SB[2])*SB[5]/(2*pow(SB[4]+SB[2],1.5)),2)+pow(SB[4]*.5*SB[3]/pow(SB[4]+SB[2],1.5),2));
//	double ZBi_pred = StatTools::computeZBi(SB[4]+SB[2],SB[2],SB[3]); 
//	double ZPL_pred = StatTools::computeZBL(SB[4]+SB[2],SB[2],SB[3]); 
	//std::cout << " _______________________Zbi " << ZBi_pred << std::endl;
	outf_nr.open(("BDT_scanSB_"+std::to_string(set)+"_"+std::to_string(category)+"_nores.txt").c_str(), std::ios_base::app);	 
	outf_nr << cut  << " " << SB[4] << " "<< SB[5]<< " " << SB[2] << " " << SB[3] << std::endl;
	oute_nr.open(("BDT_scanM_"+std::to_string(set)+"_"+std::to_string(category)+"_nores.txt").c_str(), std::ios_base::app);	 
	oute_nr << cut  << " " << merit_pred << " " << merit_err_pred << " " << merit << " "<< merit_err << std::endl;
}
