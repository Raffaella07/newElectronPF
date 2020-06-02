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
#include "TGraph2D.h"
#include "TGraphErrors.h"
#include "TStyle.h"
#include "TString.h"
#include "TLorentzVector.h"



int main(int argc, char **argv){
	
	std::string input = argv[1];
	int cat = atoi(argv[2]);
	std::ifstream infile;   
	setStyle();
	std::string PNGPATH = "/eos/home-r/ratramon/www/";
	

	std::string categories[6];

	categories[0]= "PF PF";
	categories[1]= "PF LowPt";
	categories[2]= "LowPt LowPt";

	categories[3]= "ele2PF";
	categories[4]= "ele2Low IDover2";
	categories[5]= "ele2Low IDunder2";
		
//	TGraphErrors* fitted= new TGraphErrors(input.c_str(),"%lg %*s %*s %lg %lg ");
	TGraphErrors* predicted= new TGraphErrors(input.c_str(),"%lg %lg %lg %*s %*s ");
	

	TCanvas* canvas = new TCanvas("bdt opt","bdt opt",800,600);
	 
	predicted->GetHistogram()->GetXaxis()->SetTitle("BDToutput");
	predicted->GetHistogram()->GetYaxis()->SetTitle("S/#sqrt{S+B} ");
	predicted->GetHistogram()->GetYaxis()->SetRangeUser(0,1.5);
	predicted->SetMarkerStyle(8);
	//fitted->SetMarkerStyle(8);
	//fitted->SetMarkerColor(kRed-3);
	predicted->Draw("AP");
	//fitted->Draw("sameP");
	TLatex* l = new TLatex();

	l->SetTextAlign(13);
	l->SetTextSize(0.04);

	l->DrawLatex(4.1, 1.4, categories[cat].c_str());
	l->DrawLatex(4.1, 1.2, "Predicted S");
//	l->SetTextColor(kRed-3);
//	l->DrawLatex(4.1, 0.35, "Fitted S");

	CMS_lumi(canvas,5,0,10);


	canvas->SaveAs((PNGPATH+"/newElectronPF/BDT_opt_"+categories[cat]+".png").c_str());

}
