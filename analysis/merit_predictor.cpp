
#include "../interface/BParkTools.h"
#include <iostream>
#include <fstream>
#include <utility>
#include <vector>
#include <math.h>
#include <string>
#include <fstream>
#include <ostream>
#include "TH1.h"
#include "TH2.h"
#include "TMath.h"
#include "TFile.h"
#include "TAxis.h"
#include "TTree.h"
#include "TLatex.h"
#include "TCanvas.h"
#include "TGraph.h"


int main(){

	std::ifstream infile;   
	int signal=423;
	int background=562;

	double eff_sig,eff_bkg;
	eff_sig = 0.987;
	eff_bkg = 1-0.004;

	std::string PNGPATH = "/eos/home-r/ratramon/www/";
	setStyle();
	std::vector<double> wp,eff_s,eff_b,sig,bkg,merit;	
	infile.open("../../../LowPtElectrons/macros/ROC.txt");// file containing numbers in 3 columns 

	std::cout  <<"here" << std::endl;
	if(infile.fail()) // checks to see if file opended 
	{ 
		std::cout << "error" << std::endl; 
		return 1; // no point continuing if the file didn't open...
	} 
	std::cout  << "here1" << std::endl;
	while(!infile.eof()) // reads file to end of *file*, not line
	{ 	double temp,temp1,temp2,temp3,temp4;
		infile >> temp; // read first column number
		wp.push_back(temp);
		std::cout  <<" in while "<< temp <<  std::endl;
		infile >> temp1; // read second column number
		eff_s.push_back(temp1);
		infile >> temp2; // read third column number
		eff_b.push_back(temp2);
		//sig.push_back(temp3);
	//	bkg.push_back(temp4);
		
		
		}
	
	std::cout  <<" here2 "<< std::endl;
	infile.close();
//	TGraph* roc = new TGraph(eff_s.size(),eff_s.data(),eff_b.data());
//	TGraph*  e= new TGraph(eff_s.size(),eff_s.data(),wp);
	for (int i=0; i<eff_s.size();i++){

	std::cout  << eff_s.at(i) << " " << eff_b.at(i) << wp.at(i) << std::endl;
	sig.push_back(eff_s.at(i)/eff_sig*signal);	
	bkg.push_back((1-eff_b.at(i))/eff_bkg*background);	
	merit.push_back(sig.at(i)/sqrt(sig.at(i)+bkg.at(i)));


	}
	
	TGraph* merit_data = new TGraph(wp.size(),wp.data(),merit.data());
	TH2D* plotter =new TH2D ("plotter", "plotter",10,-17,12,10,10,15);
	TCanvas * c = new TCanvas("name","name",600,800);
	merit_data->SetMarkerStyle(8);
	merit_data->SetMarkerSize(1);
	
	gStyle->SetPalette(kPastel);
	gStyle->SetNumberContours(12);
	//merit_data->GetHistogram()->GetZaxis()->SetTitle("S/#sqrt{S+B} nores");
	plotter->GetXaxis()->SetTitle("BDT_output");
	plotter->GetYaxis()->SetTitle("S/#sqrt{S+B} #; #varepsilon(S)");
	//merit_data->GetHistogram()->GetYaxis()->SetLimits(0,55);
	merit_data->GetHistogram()->GetXaxis()->SetTitleOffset(1.5);
	merit_data->GetHistogram()->GetYaxis()->SetTitleOffset(1.5);
	plotter->Draw("");
	merit_data->Draw("sameP");
//	mierit_data->GetHistogram()->Draw("surf1");
	//canv->SaveAs((std::string(filename)+".pdf").c_str());
	c->SaveAs((PNGPATH+"/newElectronPF/meritVsoutput.png").c_str());
	}
