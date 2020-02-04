#include "TTree.h"
#include "../interface/BParkTools.h"
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
	TFile* file = TFile::Open(argv[1]);
	TTree* EvTree = (TTree*)file->Get("BGTree");
	//TTree* EvTree = new TTree;
	//EvTree = mergeTrees(1,"/eos/home-r/ratramon/BuToKJpsiTomumu/BuToKJpsiTomumu");
	BGElectronClass evt;
	evt.Init(EvTree);
	setStyle();
	
	int i,j;
	
	TH1D* misEle_pt = new TH1D("pt misid electrons","pt misid electrons",50,0,50);
	TH1D* misEle_eta = new TH1D("eta misid electrons","eta misid electrons",50,-2.5,2.5);
	TH1D* misEle_pfmvaId = new TH1D("pfmvaid misid electrons","pfmvaid misid electrons",30,-11,8);

	for(i=0;i<evt.fChain->GetEntries();i++){
		evt.fChain->GetEntry(i);
		for(j=0;j<evt.nElectrons;j++){
		if(evt.Ele_isPF[j]){
			misEle_pt->Fill(evt.Ele_pt[j]);	
			misEle_eta->Fill(evt.Ele_eta[j]);	
			misEle_pfmvaId->Fill(evt.Ele_pfmvaId[j]);	

		}


		}


	}	
	SavePlot("p_{T}^{misEle}",misEle_pt,"newElectronPF/4Mu_Ele_pt",false, NULL,false);
	SavePlot("#eta^{misEle}",misEle_eta,"newElectronPF/4Mu_Ele_eta",false, NULL,false);
	SavePlot("PFmvaId",misEle_pfmvaId,"newElectronPF/4Mu_Ele_pfmvaId",false, NULL,false);
	return 0;
}
