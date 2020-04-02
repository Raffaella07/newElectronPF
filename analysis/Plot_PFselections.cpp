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

	std::ifstream infile, small;   
	setStyle();
	std::vector<Double_t> pf_low,pf_high,sig_nr,bkg;
	std::string PNGPATH = "/eos/home-r/ratramon/www/";
	int num = 0; // num must start at 0
	infile.open("mc_merit.txt_res");// file containing numbers in 3 columns 
	small.open("fixed.txt");// file containing numbers in 3 columns 
	if(infile.fail()) // checks to see if file opended 
	{ 
		std::cout << "error" << std::endl; 
		return 1; // no point continuing if the file didn't open...
	} 
	while(!infile.eof()) // reads file to end of *file*, not line
	{ 	double temp,temp1,temp2,temp3;
		infile >> temp; // read first column number
		pf_low.push_back(temp);
		infile >> temp1; // read second column number
		pf_high.push_back(temp1);
		infile >> temp2; // read third column number
		sig_nr.push_back(temp2);
		infile >> temp3; // read third column number
		bkg.push_back(temp2/sqrt(temp3));
		
		
		}
	
	infile.close();
	for(int i =0; i<bkg.size();i++){
	std::cout << "check " << pf_low[i] << " " << pf_high[i] << " " << sig_nr[i]/6035.63 << std::endl; 
	}
	
	TGraph2D* plot = new TGraph2D("merit.txt");
//	TGraph2D* sig = new TGraph2D("signal.txt");
	TGraph2D* nores = new TGraph2D(bkg.size(),&pf_low[0],&pf_high[0],&bkg[0]);
//	TGraph2D* sig = new TGraph2D(bkg.size(),&pf_low[0],&pf_high[0],&sig_nr[0]);
	TGraph* sig = new TGraph("fixed.txt");
	TH2D* plotter = new TH2D("plotter","plotter",10,-11,2,10,0,1.1);
////////////////	for (int i=0;i<sig->GetN();i++) sig->GetZ()[i] /= 6035.63;
	//TH2D* plotter = new TH2D("plotter","plotter",20,-4,0,20,-4,0);

	TCanvas* canv = new TCanvas("PF MvaId selections","PF MvaId selections",600,800);

	gStyle->SetPalette(kPastel);
	gStyle->SetNumberContours(12);
	plot->GetHistogram()->GetZaxis()->SetTitle("S/#sqrt{S+B}");
	plot->GetHistogram()->GetXaxis()->SetTitle("PFMvaId^{Cut}_{P_{T}Bin 1}");
	plot->GetHistogram()->GetYaxis()->SetTitle("PFMvaId^{Cut}_{P_{T}Bin 2}");
	plot->GetHistogram()->GetZaxis()->SetTitleOffset(1.5);
	plot->GetHistogram()->GetXaxis()->SetTitleOffset(1.5);
	plot->GetHistogram()->GetYaxis()->SetTitleOffset(1.5);
	plot->GetHistogram()->Draw("surf1");
	//canv->SaveAs((std::string(filename)+".pdf").c_str());
	canv->SaveAs((PNGPATH+"/newElectronPF/PF_sel.png").c_str());

	canv->Clear();
	TCanvas* canvas = new TCanvas("PF MvaId signal efficiency","PF MvaId signal efficiency",600,800);
	gStyle->SetPalette(kPastel);
	gStyle->SetNumberContours(12);
	//sig->GetHistogram()->GetZaxis()->SetTitle("signal efficiency ");
	plotter->/*GetHistogram()->*/GetXaxis()->SetTitle("PFMvaId^{Cut}_{P_{T}Bin 1}");
	plotter->/*GetHistogram()->*/GetYaxis()->SetTitle("signal(MC) efficiency ");
	//sig->GetHistogram()->GetZaxis()->SetTitleOffset(1.5);
	plotter->/*GetHistogram()->*/GetXaxis()->SetTitleOffset(1);
	plotter->/*GetHistogram()->*/GetYaxis()->SetTitleOffset(1.5);
	sig->SetMarkerStyle(8);
	plotter->Draw();
	sig->/*GetHistogram()->*/Draw("sameP");
	//canv->SaveAs((std::string(filename)+".pdf").c_str());
	canvas->SaveAs((PNGPATH+"/newElectronPF/PF_eff.png").c_str());
	TCanvas* can_nores = new TCanvas("PFnores","PFnores",600,800);
	gStyle->SetPalette(kPastel);
	gStyle->SetNumberContours(12);
	nores->GetHistogram()->GetZaxis()->SetTitle("S/#sqrt{S+B} nores");
	nores->GetHistogram()->GetXaxis()->SetTitle("PFMvaId^{Cut}_{P_{T}Bin 1}");
	nores->GetHistogram()->GetYaxis()->SetTitle("PFMvaId^{Cut}_{P_{T}Bin 2}");
	nores->GetHistogram()->GetZaxis()->SetTitleOffset(1.5);
	nores->GetHistogram()->GetXaxis()->SetTitleOffset(1.5);
	nores->GetHistogram()->GetYaxis()->SetTitleOffset(1.5);
	nores->GetHistogram()->Draw("surf1");
	//canv->SaveAs((std::string(filename)+".pdf").c_str());
	can_nores->SaveAs((PNGPATH+"/newElectronPF/PF_nores.root").c_str());
		// you can also do it on the same line like this:
		//          // infile >> exam1[num] >> exam2[num] >> exam3[num]; ++num;
		//                } 
		//                  infile.close(); 


}
