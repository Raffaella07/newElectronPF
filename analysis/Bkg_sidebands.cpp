#include "../interface/BParkTools.h"
#include "TTree.h"
#include <ROOT/RDataFrame.hxx>
#include <ROOT/RVec.hxx>
#include "TStopwatch.h"
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
//	TFile* file_sigMC = TFile::Open(argv[1]);
//	TFile* file_backMC = TFile::Open(argv[2]);
//	TFile* file_back = TFile::Open(argv[3]);
//	TTree* EvTree = (TTree*)file_sigMC->Get("Tree");
//	TTree* BG_MCTree = (TTree*)file_backMC->Get("Tree");
//	TTree* BGTree = (TTree*)file_back->Get("BGTree");
	int in_files = std::atoi(argv[1]);
	TChain* chain= new TChain("Events");
	std::cout << "Loading input files from: " << std::endl;
	std::cout << "/eos/cms/store/group/cmst3/group/bpark/BParkingNANO_2020Jan16/ParkingBPH1/crab_data_Run2018C_part1/200116_151112/0000/" << std::endl;
	if (in_files == 0 ){
	for(int file_idx=1;file_idx < 10; file_idx++){
	chain->Add(("/eos/cms/store/group/cmst3/group/bpark/BParkingNANO_2020Jan16/ParkingBPH1/crab_data_Run2018C_part1/200116_151112/0000/BParkNANO_data_2020Jan16_"+std::to_string(file_idx)+".root").c_str());
	}
	}else chain->Add(("/eos/cms/store/group/cmst3/group/bpark/BParkingNANO_2020Jan16/ParkingBPH1/crab_data_Run2018C_part1/200116_151112/0000/BParkNANO_data_2020Jan16_"+std::to_string(in_files)+"*.root").c_str());
	//TTree* EvTree = new TTree;
	//EvTree = mergeTrees(1,"/eos/home-r/ratramon/BuToKJpsiTomumu/BuToKJpsiTomumu");
	BElectronsClass evt;
	evt.Init(chain);
	setStyle();
	
	int i,j;
	TH1D* Bkg_sides = new TH1D("bkg sidebands","bkg sidebands",80,3, 7.5);
	TH1D* BkgLead_mvaId = new TH1D("lead mvaId","lead mvaId",38,-11, 8);
	TH1D* BkgLead_pt = new TH1D("lead pt","lead pt",40, 0, 50);
	TH1D* BkgLead_eta = new TH1D("lead eta","lead eta",40, -2.5,2.5);
	TH1D* BkgSub_mvaId = new TH1D("sublead mvaId","sublead mvaId",38, -11, 8);
	TH1D* BkgSub_pt = new TH1D("sublead pt","sublead pt",40, 0, 50);
	TH1D* BkgSub_eta = new TH1D("sublead eta","sublead eta",40, -2.5, 2.5);

	TF1* bkg_fit = new TF1("fline","pol4(0)",4,7);	

	double sigma = sigma_Bsig();	
	std::cout << "sigma" << sigma << std::endl;	
	for(i=0;i<100000/*evt.fChain->GetEntries()*/;i++){
	evt.fChain->GetEntry(i);
	if (i%100000==0)std::cout << "on entry" << i << std::endl;	
		for(j=0;j<evt.nBToKEE;j++){
			if (evt.Electron_isPF[evt.BToKEE_l1Idx[j]] && evt.Electron_isPF[evt.BToKEE_l2Idx[j]]/* && evt.BToKEE_svprob[j]>0.1 && evt.BToKEE_l_xy[j]/evt.BToKEE_l_xy_unc[j] >6*/){
			if (evt.BToKEE_mass[j]<B_MASS-5*sigma || evt.BToKEE_mass[j]>B_MASS+3*sigma){
				Bkg_sides->Fill(evt.BToKEE_mass[j]);
				BkgLead_mvaId->Fill(evt.Electron_pfmvaId[evt.BToKEE_l1Idx[j]]);
				BkgLead_pt->Fill(evt.Electron_pt[evt.BToKEE_l1Idx[j]]);
				BkgLead_eta->Fill(evt.Electron_eta[evt.BToKEE_l1Idx[j]]);	
				BkgSub_mvaId->Fill(evt.Electron_pfmvaId[evt.BToKEE_l2Idx[j]]);
				BkgSub_pt->Fill(evt.Electron_pt[evt.BToKEE_l2Idx[j]]);
				BkgSub_eta->Fill(evt.Electron_eta[evt.BToKEE_l2Idx[j]]);	
				
				}
			}

		}		
		
	}	
		std::vector<float> x_sides,y_sides,err_sides, errx_sides;
		float *x_s,*y_s,*x_es,*y_es;
		for(i=0;i<80;i++){
			float x =(7.5-3)*i/80; 
			if(x<4.5 || x< 5.6){
			std::cout << "debug" << std::endl;
			x_sides.push_back(x);
			std::cout << "debu1" << x << std::endl;
			y_sides.push_back(Bkg_sides->GetBinContent(Bkg_sides->GetXaxis()->FindBin(x)));
			std::cout << "debug2" <<  Bkg_sides->GetBinContent(Bkg_sides->GetXaxis()->FindBin(x)) <<std::endl;
			err_sides.push_back(sqrt(Bkg_sides->GetBinContent(Bkg_sides->GetXaxis()->FindBin(x))));


			}

		}
		x_s = x_sides.data();
		y_s = y_sides.data();
		x_es =errx_sides.data();
		y_es =err_sides.data();
		TGraphErrors* sides = new TGraphErrors(x_sides.size(),x_s,y_s,x_es,y_es);
	
		bkg_fit->SetParameter(0,50);
		bkg_fit->SetParLimits(0,0,Bkg_sides->GetMaximum());
		bkg_fit->SetParameter(2,-1);
		bkg_fit->SetParLimits(2,-10,0);
		bkg_fit->SetParameter(3,10);
		bkg_fit->SetParameter(4,10);
		bkg_fit->SetParLimits(2,-10,0);
		sides->Fit("fline","0R");
		
		SavePlot("M_{B}(GeV)",Bkg_sides,"newElectronPF/bkg_window",false, bkg_fit,false);
		SavePlot("PFmvaId",BkgLead_mvaId,"newElectronPF/sidebands_lead_pfmvaId",false, NULL,false);
		SavePlot("p_{T}(GeV)",BkgLead_pt,"newElectronPF/sidebands_lead_pt",false, NULL,false);
		SavePlot("#eta",BkgLead_eta,"newElectronPF/sidebands_lead_eta",false, NULL,false);
		SavePlot("PFmvaId",BkgSub_mvaId,"newElectronPF/sidebands_sub_pfmvaId",false, NULL,false);
		SavePlot("p_{T}(GeV)",BkgSub_pt,"newElectronPF/sidebands_sub_pt",false, NULL,false);
		SavePlot("#eta",BkgSub_eta,"newElectronPF/sidebands_sub_eta",false, NULL,false);
	return 0;
}
