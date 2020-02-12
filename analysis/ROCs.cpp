#include "../interface/BParkTools.h"
#include "TTree.h"
//#include <ROOT/RDataFrame.hxx>
//#include <ROOT/RVec.hxx>
//#include "TStopwatch.h"
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
	std::string bkg_path = "/afs/cern.ch/work/r/ratramon/BToKEE_fakeEle/skimmedNANO_BPark_data_EleBG_*.root";

	TChain *signal = new TChain("Tree");
	TChain *background = new TChain("BGTree");
	
	signal->Add(sgl_path.c_str());
	background->Add(bkg_path.c_str());

	std::cout << "Loaded " << signal->GetEntries() << " entries for signal" << std::endl;
	std::cout << "Loaded " << background->GetEntries() << " entries for background" << std::endl;
	BSignalElectronClass sgl;
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
//	std::cout << "debug" << std::endl;
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
	std::string roc_lable[2] = {"ROC_barrel","ROC_endcaps"};
	double eff_sig[nROC][npoints], eff_bkg[nROC][npoints];
	Color_t sel_colors[nROC]= {kBlack,kRed,kGreen,kBlue,kMagenta};


	TH2D* sig_ptId[2];
	TH2D* bkg_ptId[2];
	
	sig_ptId[0]=new TH2D("pt vs mva id sgl barrel","",mvaId_nbin,mvaId_low,mvaId_up,pt_bin,pt_low,pt_up);	
	sig_ptId[1]=new TH2D("pt vs mva id sgl eta","",mvaId_nbin,mvaId_low,mvaId_up,pt_bin,pt_low,pt_up);	

	bkg_ptId[0]=new TH2D("pt vs mva id bkg barrel","",mvaId_nbin,mvaId_low,mvaId_up,pt_bin,pt_low,pt_up);	
	bkg_ptId[1]=new TH2D("pt vs mva id bkg eta","",mvaId_nbin,mvaId_low,mvaId_up,pt_bin,pt_low,pt_up);	


	for(i=0;i<sgl.fChain->GetEntries();i++){

	sgl.fChain->GetEntry(i);	

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
	bkg.fChain->GetEntry(i);	
		for(int idx=0;idx<bkg.nElectrons;idx++ ){		
			if(bkg.Ele_isPF[idx]){
			if (fabs(bkg.Ele_eta[idx])< 1.5) bkg_ptId[0]->Fill(bkg.Ele_pfmvaId[idx],bkg.Ele_pt[idx]);
			else bkg_ptId[1]->Fill(bkg.Ele_pfmvaId[idx],bkg.Ele_pt[idx]);
			}
		}
	}

	SavePlot("PFmvaId",sig_ptId[0]->ProjectionX(),("newElectronPF/sig"+roc_lable[j]).c_str(),false, NULL,false);
	TH1D *sig, *back;
	for(j=0;j<2;j++){
	std::cout << "looping for " << roc_lable[j] <<std::endl;
	rocs[j] = new TCanvas("","",800,600);
	TLatex latex;
	latex.SetTextAlign(13);
	latex.SetTextSize(0.045);

	TH2D* ranges = new TH2D("plot ","plot",10,0 ,1.1, 10,0,1.1);
	ranges->GetXaxis()->SetTitle("1-#epsilon_{bkg}");	
	ranges->GetYaxis()->SetTitle("#epsilon_{sgl}");	
	ranges->Draw();
	for(i=0;i<nROC-1;i++){
	
	double pt_min = pt_low+ (pt_up-pt_low)*i/nROC;
	double pt_max = pt_low+ (pt_up-pt_low)*(i+1)/nROC;

	std::cout  << "___________________________n ROC " << i  <<  " pt min " << pt_min << "pt min " << pt_max << std::endl;
	sig = sig_ptId[j]->ProjectionX("proj signal",sig_ptId[j]->GetYaxis()->FindBin(pt_min),sig_ptId[j]->GetYaxis()->FindBin(pt_max));

	back = bkg_ptId[j]->ProjectionX("proj back",bkg_ptId[j]->GetYaxis()->FindBin(pt_min),bkg_ptId[j]->GetYaxis()->FindBin(pt_max));	
	
	
	SavePlot("PFmvaId",sig,("newElectronPF/Mva_profile/sig_"+std::to_string(i)+"_"+roc_lable[j]).c_str(),false, NULL,false);
	SavePlot("PFmvaId",back,("newElectronPF/Mva_profile/back_"+std::to_string(i)+"_"+roc_lable[j]).c_str(),false, NULL,false);

	for (k=0;k<npoints;k++){
			double x_cut = -3.+(4-(-3.))*k/npoints;
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
		latex.SetTextColor(sel_colors[i]);
		latex.DrawLatex(0.1,0.4-i/10., (std::to_string((int)pt_min)+" GeV < P_{T} < "+ std::to_string((int)pt_max)+" GeV").c_str());
		
	//	delete sig;
	//	delete back;
	}

	
	std::cout << "debug" << std::endl;
	rocs[j]->SaveAs((PDFPATH+roc_lable[j]+".pdf").c_str());
	rocs[j]->SaveAs((PNGPATH+roc_lable[j]+".png").c_str());
	

	}	
	return 0;

}
