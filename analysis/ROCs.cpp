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


int main(int argc, char **argv){

	std::string sgl_path = "/afs/cern.ch/user/r/ratramon/Bparking/CMSSW_10_2_15/src/macros/newElectronPF/skimmed_ntuples/skimmedNANO_BPark_mc_sgl_2020Jan2016.root";
	std::string bkg_path = "/afs/cern.ch/work/r/ratramon/BToKEE_fakeEle/skimmedNANO_BPark_data_EleBG_*_2020Jan2016.root";

	TChain *signal = new TChain("Tree");
	TChain *background = new TChain("BGTree");
	
	signal->Add(sgl_path);
	background->Add(bkg_path);

	BSignalElectronClass sgl
	BSignalElectronClass *sgl_ptr;
	sgl_ptr = &sgl;
	BGElectronClass bkg;
	BGElectronClass *bkg_ptr;
	bkg_ptr = &bkg;
	sgl.Init(signal);
	bkg.Init(background);
	setStyle();

	std::string PNGPATH = "/eos/home-r/ratramon/www/";
	std::string PDFPATH = "/afs/cern.ch/user/r/ratramon/Bparking/CMSSW_10_2_15/src/macros/newElectronPF/newElectronPF/";
	int i, j, k;
	int nROC, npoints, mvaId_low,mvaId_up,mvaId_nbin,pt_bin;
	double pt_low,pt_up;
	nROC = 5;
	npoints = 10;
	mvaId_low = -11;
	mvaId_up = 8;
	mvaId_nbin = 19;
	pt_bin = 50;
	pt_low = 0;
	pt_up = 50;

	TCanvas* rocs[2];
	TGraph * ROC[nROC][2];
	std::string roc_lable = {"ROC_barrel","ROC_endcaps"};
	double eff_sig[nROC][npoints], eff_bkg[nROC][npoints];
	Color_t sel_colors[nROC]= {kBlack,kRed,kGreen,kBlue,kMagenta};


	TH2D* sig_ptId[2];
	TH2D* bkg_ptId[2];
	
	sig_ptId[0]=new TH2D("pt vs mva id sgl barrel","",mvaId_nbin,mvaId_lowmvaId_up,pt_bin,pt_low,pt_up);	
	sig_ptId[1]=new TH2D("pt vs mva id sgl eta","",mvaId_nbin,mvaId_lowmvaId_up,pt_bin,pt_low,pt_up);	

	bkg_ptId[0]=new TH2D("pt vs mva id bkg barrel","",mvaId_nbin,mvaId_lowmvaId_up,pt_bin,pt_low,pt_up);	
	bkg_ptId[1]=new TH2D("pt vs mva id bkg eta","",mvaId_nbin,mvaId_lowmvaId_up,pt_bin,pt_low,pt_up);	
	for(i=0;i<sgl.fChain->GetEntries();i++){
	
	if(sgl.B_l1_isPF && sgl.B_l1_Sig){
		if (fabs(sgl.B_l1_eta)< 1.5) sig_ptId[0]->Fill(sgl.B_l1_mvaId,sgl.B_l1_pt);
		else sig_ptId[1]->Fill(sgl.B_l1_mvaId,sgl.B_l1_pt);

	}

	if(sgl.B_l2_isPF && sgl.B_l2_Sig){
		if (fabs(sgl.B_l2_eta)< 1.5) sig_ptId[0]->Fill(sgl.B_l2_mvaId,sgl.B_l2_pt);
		else sig_ptId[1]->Fill(sgl.B_l2_mvaId,sgl.B_l2_pt);

	}
	}

	for(i=0;i<bkg.fChain->GetEntries();i++){
	
	if(bkg.Ele_isPF){
		if (fabs(bkg.Ele_eta)< 1.5) bkg_ptId[0]->Fill(bkg.Ele_mvaId,bkg.Ele_pt);
		else bkg_ptId[1]->Fill(bkg.Ele_mvaId,bkg.Ele_pt);

	}
	}

	for(j=0;j<2;j++){

	rocs[j] = new TCanvas("","",800,600);

	for(i=0;i<nROC-1;i++){
	
	double pt_min = pt_low+ (pt_up-pt_low)*i/nROC;
	double pt_max = pt_low+ (pt_up-pt_low)*(i+1)/nROC;

	TH1D * sig = sig_ptId[j]->ProjectionX("proj signal",sig_ptId->GetYaxis()->FindBin(pt_min),sig_ptId->GetYaxis()->FindBin(pt_max));

	TH1D * back = bkg_ptId[j]->ProjectionX("proj signal",bkg_ptId->GetYaxis()->FindBin(pt_min),bkg_ptId->GetYaxis()->FindBin(pt_max));


	for (k=0;k<npoints;k++){
			double x_cut = -4.+(4.-(-4.))*i/npoints;
			eff_sig[i][k] = sig->Integral(sig->FindBin(x_cut), sig->GetXaxis()->GetXmax())/sig->Integral();
			eff_bkg[i][k] = 1-back->Integral(back->FindBin(x_cut), back->GetXaxis()->GetXmax())/back->Integral();
			std::cout << x_cut << " @ " << i  <<  " check arrays: sgl " << eff_sig[i][k] << "bkg" << eff_bkg[i][k] << std::endl;

		}

	
		ROC[i][j] = new TGraph(npoints,eff_sig[i],eff_bkg[i]);	
		ROC[i][j]->SetMarkerStyle(8);
		ROC[i][j]->SetMarkerColor(sel_colors[i]);
		ROC[i][j]->SetLineColor(sel_colors[i]);
		ROC[i][j]->SetLineWidth(2);
		ROC[i][j]->Draw("SAMEPL");
		
		delete sig;
		delete back;
	}

	
	rocs[j]->SaveAs((PDFPATH+roc_lable[j]+".pdf").c_str());
	rocs[j]->SaveAs((PNGPATH+roc_lable[j]+".png").c_str());
	

	}	
	return 0;

}
