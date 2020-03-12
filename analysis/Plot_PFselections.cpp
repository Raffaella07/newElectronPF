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

	std::ifstream infile;   
	setStyle();
	std::vector<Double_t> pf_low,pf_high,merit;
	std::string PNGPATH = "/eos/home-r/ratramon/www/";
	int num = 0; // num must start at 0
	infile.open("points.txt");// file containing numbers in 3 columns 
	if(infile.fail()) // checks to see if file opended 
	{ 
		std::cout << "error" << std::endl; 
		return 1; // no point continuing if the file didn't open...
	} 
	while(!infile.eof()) // reads file to end of *file*, not line
	{ 	double temp,temp1,temp2;
		infile >> temp; // read first column number
		pf_low.push_back(temp);
		infile >> temp1; // read second column number
		pf_high.push_back(temp1);
		infile >> temp2; // read third column number
		merit.push_back(temp2);

		}
	
	infile.close();
	std::cout << "check " << pf_low[0] << " " << pf_high[0] << " " << merit[0] << std::endl; 
	
	TGraph2D* plot = new TGraph2D("points.txt");
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
		// you can also do it on the same line like this:
		//          // infile >> exam1[num] >> exam2[num] >> exam3[num]; ++num;
		//                } 
		//                  infile.close(); 


}
