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

	//--grab and initialize trees
	TFile* file_sigMC = TFile::Open(argv[1]);
	TFile* file_backMC = TFile::Open(argv[2]);
	TFile* file_back = TFile::Open(argv[3]);
	TTree* EvTree = (TTree*)file_sigMC->Get("Tree");
	TTree* BG_MCTree = (TTree*)file_backMC->Get("Tree");
	TTree* BGTree = (TTree*)file_back->Get("BGTree");
	//TTree* EvTree = new TTree;
	//EvTree = mergeTrees(1,"/eos/home-r/ratramon/BuToKJpsiTomumu/BuToKJpsiTomumu");
	BSignalElectronClass evt, bkg_MC;
	BSignalElectronClass *evt_ptr, *bkg_MCptr;
	evt_ptr = &evt;
	bkg_MCptr = &bkg_MC;
	BGElectronClass bkg;
	BGElectronClass *bkg_ptr;
	bkg_ptr = &bkg;
	evt.Init(EvTree);
	bkg_MC.Init(BG_MCTree);
	bkg.Init(BGTree);
	setStyle();

	std::cout << "MC backgound entries " << bkg_MC.fChain->GetEntries() << std::endl;
	int i,n1_bin,n2_bin;
	double x1_cut, x2_cut,x1_low,x1_high,x2_low,x2_high, eff, N_Stot, N_Sel;
	const int n_selections = 2;
	Color_t sel_colors[n_selections]= {kBlack,kRed};
	std::string sel_lables[n_selections] = {"Fakes(DATA)","FAKES(MC)"};
	int npoints;
	npoints = 10;
	double eff_sig[n_selections][npoints], eff_bkg[n_selections][npoints];
	
	n1_bin = 19;
	n2_bin = 19;
	x1_low = -11;
	x1_high = 8;
	x2_low = -11;
	x2_high = 8;

	TH2D* eff_cut =new TH2D("efficiencies","",19,-11,8,19,-11,8);	
	TH2D* signal_ptId =new TH2D("pt vs mvaId sglMC","",19,-11,8,19,-11,8);	
	TH2D* signal_ptId =new TH2D("pt vs mvaId backMC","",19,-11,8,,-11,8);	
	TH2D* signal_ptId =new TH2D("pt vs mvaId back","",19,-11,8,19,-11,8);	
	TH1D* signalMC_mvaId = new TH1D("signal pfmvaid","signal pfmvaid",38,-11,8);
	TH1D* bkgMC_mvaId = new TH1D("signal pfmvaid","signal pfmvaid",38,-11,8);
	TH1D* bkg_mvaId = new TH1D("bkg pfmvaid","bkg pfmvaid",38,-11,8);
	TH1D* signalMC_pt = new TH1D("signal pt","signal pt",35,0,35);
	TH1D* bkgMC_pt = new TH1D("signal pt","signal pt",35,0,35);
	TH1D* bkg_pt = new TH1D("bkg pt","bkg pt",35,0,35);
	TH1D* signalMC_eta = new TH1D("signal eta","signal eta",30,-3,3);
	TH1D* bkgMC_eta = new TH1D("signal eta","signal eta",30,-3,3);
	TH1D* bkg_eta = new TH1D("bkg eta","bkg eta",30,-3,3);

	for (int i1=0;i1<n1_bin;i1++){
		x1_cut = x1_low + (x1_high-x1_low)/n1_bin*i1;
		for (int i2=0;i2<n2_bin;i2++){
			x2_cut = x2_low + (x2_high-x2_low)/n2_bin*i2;
			for(i=0;i<evt.fChain->GetEntries();i++){
				
		//	if (i%10000==0)std::cout << "                                               on entry" << i << std::endl;
				evt.fChain->GetEntry(i);
				if(evt.B_l1_isPF==1 && evt.B_l1_Sig==1 && evt.B_l2_isPF==1 && evt.B_l2_Sig==1){
					N_Stot++;
					if(evt.B_l1_mvaId > x1_cut && evt.B_l2_mvaId >x2_cut) N_Sel++;

				} 




			}
		
		
		eff = N_Sel/N_Stot;
	//	std::cout << "efficiency" << eff << std::endl;
		eff_cut->Fill(x2_cut,x1_cut,eff);
		N_Stot =0;
		N_Sel=0;
		}
	
	std::cout << "cuts : xLead " << x1_cut << " xSlead " << x2_cut<< std::endl;

	}
	
	Fill_MChistos(evt_ptr,signalMC_mvaId,signalMC_pt,signalMC_eta);
	Fill_MChistos(bkg_MCptr,bkgMC_mvaId,bkgMC_pt,bkgMC_eta);
	Fill_DATAhistos(bkg_ptr,bkg_mvaId,bkg_pt,bkg_eta);

	std::cout << "after filling " << bkgMC_pt->GetEntries() << std::endl;	
	superMC_DATAnorm(signalMC_mvaId,bkgMC_mvaId,bkg_mvaId,0.07,"SglVsBkg_mvaId","PFmvaId",false,false);
	superMC_DATAnorm(signalMC_pt,bkgMC_pt,bkg_pt,0.6,"SglVsBkg_pt","p_{T}(GeV)",true,true);
	superMC_DATAnorm(signalMC_eta,bkgMC_eta,bkg_eta,0.07,"SglVsBkg_eta","#eta",false,false);
	SavePlot2D("pfmvaid cut efficiencies",eff_cut,"PFmvaId_cut_eff",false,false);
	

	for (int index=0;index<n_selections;index++){
		for (i=0;i<npoints;i++){
			double x_cut = -4.+(4.-(-4.))*i/npoints;
			eff_sig[index][i] = signalMC_mvaId->Integral(signalMC_mvaId->FindBin(x_cut), signalMC_mvaId->GetXaxis()->GetXmax())/signalMC_mvaId->Integral();
			if (index==0)eff_bkg[index][i] = 1-bkg_mvaId->Integral(bkg_mvaId->FindBin(x_cut), bkg_mvaId->GetXaxis()->GetXmax())/bkg_mvaId->Integral();
			else eff_bkg[index][i] = 1-bkgMC_mvaId->Integral(bkgMC_mvaId->FindBin(x_cut), bkgMC_mvaId->GetXaxis()->GetXmax())/bkgMC_mvaId->Integral();
			std::cout << x_cut << " @ " << index  <<  " check arrays: sgl " << eff_sig[index][i] << "bkg" << eff_bkg[index][i] << std::endl;

		}
	}
	TGraph* ROC[n_selections];
	TCanvas* canv = new TCanvas("","",800,600);
	std::cout << "debug" << std::endl;
	TLatex latex;
	latex.SetTextAlign(13);
	latex.SetTextSize(0.045);

	std::cout << "debug" << std::endl;
	TH2D* ranges = new TH2D("NANOAOD pre + PF ","NANOAOD pre + PF +STD cut",10,0 ,1.1, 10,0,1.1);
	ranges->GetXaxis()->SetTitle("1-#epsilon_{bkg}");	
	ranges->GetYaxis()->SetTitle("#epsilon_{sgl}");	
	ranges->Draw();
	for(i=0;i<n_selections; i++){
		for(int j=0;j<npoints;j++){
		}
		std::cout << "debug" << std::endl;
		ROC[i] = new TGraph(npoints,eff_sig[i],eff_bkg[i]);	
		ROC[i]->SetMarkerStyle(8);
		ROC[i]->SetMarkerColor(sel_colors[i]);
		ROC[i]->SetLineColor(sel_colors[i]);
		ROC[i]->SetLineWidth(2);
	//	std::cout << "debug1 " << std::endl;
	//	std::cout << "debug2 " << std::endl;

		ROC[i]->Draw("SAMEPL");
	}

	latex.DrawLatex(0.1,0.3,sel_lables[0].c_str());
	latex.SetTextColor(kRed);
	latex.DrawLatex(0.1,0.1,sel_lables[1].c_str());
	std::string PNGPATH = "/eos/home-r/ratramon/www/";
	std::string PDFPATH = "/afs/cern.ch/user/r/ratramon/Bparking/CMSSW_10_2_15/src/macros/newElectronPF/newElectronPF/";
	std::string filename = "ROC";
	canv->SaveAs((PDFPATH+std::string(filename)+".pdf").c_str());
	canv->SaveAs((PNGPATH+std::string(filename)+".png").c_str());
	
	delete canv;
	delete signalMC_mvaId;
	delete signalMC_pt;
	delete signalMC_eta;
	delete bkgMC_mvaId;
	delete bkgMC_pt;
	delete bkgMC_eta;
	delete bkg_mvaId;
	delete bkg_pt;
	delete bkg_eta;

	return 0;	
	}
