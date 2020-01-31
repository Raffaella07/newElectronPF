#include "BNanoClass.cpp"
#include "BElectronsClass.cpp"
#include "BElectronsClassMC.cpp"
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

struct pos{

    float x;
    float y;
    float z;
    float phi;
    float eta;
    float pt;



};
ROOT::VecOps::RVec<bool> IsGood(unsigned int nB, 
				float *pT1, float *pT2, float *pTk, 
 				ROOT::VecOps::RVec<unsigned int>& nTrg,float *cos2D, float *vtxP, 
 				float *disp, float *dispU, float *pT,float*eta) { 

  ROOT::VecOps::RVec<bool> goodB(nB, false);
  for (auto ij=0; ij<nB; ++ij){
    if (pT1[ij] > 1. && pT2[ij] > 0.5 && pTk[ij] > 0.8 &&
     	nTrg[ij] > 0 && cos2D[ij] > 0.99 && vtxP[ij] > 0.1 && disp[ij] > 2 && dispU[ij] != 0 && pT[ij] > 3. && std::abs(eta[ij]) < 2.4)
      goodB[ij]  = true;
  }

  return goodB; 
}

ROOT::VecOps::RVec<int> Rankv2(ROOT::VecOps::RVec<float>& vtxP){

  
  auto sortIndices = Argsort(vtxP);
  ROOT::VecOps::RVec<int> rank;
  auto totN = vtxP.size();
  rank.resize(totN);
//  std::cout << "in Ranked v2" << totN << std::endl;

  int nRank = 0;
  for (auto ij=0; ij<totN; ++ij){
//	std::cout << "in for RankV2 " << nRank << std::endl;
    rank[sortIndices[ij]] = nRank;
    ++nRank;
  }
  return rank; 
}


void FillKinhistos(TH1D** histo, double pt, double eta, double phi, int type){
	int i;
	double kin[3];

	kin[0]=pt;
	kin[1]=eta;
	kin[2]=phi;


	for(i=0; i<3; i++){
		if(type == 0 ) histo[i]->Fill(kin[i]);
		else if(type==1) histo[i+3]->Fill(kin[i]);
		else if(type==2) histo[i+6]->Fill(kin[i]);

	}


}


TTree* mergeTrees(int n_files,std::string filename){

	TList* l = new TList();
	int i;

	for(i=0;i<n_files;i++){	
	
		
	TFile* file = TFile::Open((filename+"_"+std::to_string(i)+"_NANO.root").c_str());
	TTree* EvTree =new TTree;
	EvTree =  (TTree*)file->Get("Events");
	l->Add(EvTree);

	}
	
	TTree* tree = new TTree();
	tree->MergeTrees(l);
	return tree;

}


void lables1D(TCanvas* canv,TH1D* histo){

	TLatex l;
	l.SetTextSize(0.045);
	l.SetTextAlign(13);
	l.DrawLatex(histo->GetXaxis()->GetXmin()+(histo->GetXaxis()->GetXmax()-histo->GetXaxis()->GetXmin())*1/9, histo->GetMaximum()+histo->GetMaximum()*0.07,histo->GetName());	
	canv->Update();	


}
void SavePlot (std::string titlestring, TH1D * histo, const char * filename, bool log=false, TF1* fit= NULL, bool lable=false){

	TCanvas* canvas = new TCanvas("canva","canva",600,550);
	TFile* histos = new TFile("gausslog.root","UPDATE","",0);
	std::string PNGPATH = "/eos/home-r/ratramon/www/";
	//const char * temptitle = titlestring.c_str();

	if (log) canvas->SetLogy();
	histo->GetXaxis()->SetMaxDigits(2);
	histo->SetLineWidth(4);
	histo->SetLineColor(kRed-6);
	histo->GetXaxis()->SetTitle(titlestring.c_str());
	histo->GetYaxis()->SetTitle(histo->GetTitle());
	std::cout << "axis title" << titlestring.c_str() << std::endl;
	histo->Draw(/*"hist"*/);
	if(lable)lables1D(canvas,histo);
	canvas->SaveAs((std::string(filename)+".pdf").c_str());
	canvas->SaveAs((PNGPATH+std::string(filename)+".png").c_str());
	canvas->Clear();
	histos->Close();

	delete canvas;
}
void lables(TCanvas* canv,TH2D* histo){

	TLatex l;
	l.SetTextSize(0.04);
	l.SetTextAlign(13);
	l.DrawLatex(histo->GetXaxis()->GetXmin()+(histo->GetXaxis()->GetXmax()-histo->GetXaxis()->GetXmin())*8/18, histo->GetYaxis()->GetXmax()-(histo->GetYaxis()->GetXmax()-histo->GetYaxis()->GetXmin())*0.07,histo->GetTitle());	
	canv->Update();	


}

void superpos(std::string titlestring,TH1D * h1, TH1D* h2, const char* filename,bool log=false, bool lable= false){

	TCanvas* canvas = new TCanvas("canva","canva",600,550);
	TH1D* empty = new TH1D("empty","empty",10,h1->GetXaxis()->GetXmin(),h1->GetXaxis()->GetXmax());
	std::string PNGPATH = "/eos/home-r/ratramon/www/";
	TLatex l;

	std::cout << "compare entries " << h1->GetEntries() << "reco "  << h2->GetEntries() << std::endl;
	empty->GetXaxis()->SetMaxDigits(2);
	if (log){ canvas->SetLogy();
		empty->GetYaxis()->SetRangeUser(1,std::max(h1->GetMaximum()*2.5,h2->GetMaximum()*2.5));
	}else {
		empty->GetYaxis()->SetRangeUser(0,std::max(h1->GetMaximum()*1.1,h2->GetMaximum()*1.1));
	}
	h1->SetLineWidth(4);
	h2->SetLineWidth(4);
	h1->SetLineColor(kRed-6);
	h2->SetLineColor(kBlue-3);
	empty->GetXaxis()->SetTitle(titlestring.c_str());
	empty->GetYaxis()->SetTitle("entries");
	empty->Draw("");
	h1->Draw("HISTsame");
	h2->Draw("HISTsame");
	l.SetTextSize(0.045);
	l.SetTextAlign(13);
	l.SetTextColor(kRed-6);
	l.DrawLatex(h1->GetXaxis()->GetXmin()+0.1*(h1->GetXaxis()->GetXmax()-h1->GetXaxis()->GetXmin()),0.98*h1->GetMaximum(),(std::string("Signal ")+std::to_string((int)h1->GetEntries())).c_str());
	l.SetTextColor(kBlue-3);
	l.DrawLatex(h1->GetXaxis()->GetXmin()+0.1*(h1->GetXaxis()->GetXmax()-h1->GetXaxis()->GetXmin()),0.80*h1->GetMaximum(),(std::string("Background ")+std::to_string((int)h2->GetEntries())).c_str());
	if (lable ) lables1D(canvas,h1);
	canvas->SaveAs((std::string(filename)+".pdf").c_str());
	canvas->SaveAs((PNGPATH+std::string(filename)+".png").c_str());
	canvas->Clear();

	delete empty;
	delete canvas;
}


void SavePlot2D (std::string titlestring, TH2D * histo,const char*  filename, bool log=false,bool lable=false){

	TCanvas* canvas = new TCanvas(titlestring.c_str(),titlestring.c_str(),600,550);
	std::string PNGPATH = "/eos/home-r/ratramon/www/";
	//TH2D * plotter =new TH2D("-","",20,-20,20,20,0.0,0.4);
	if (log) canvas->SetLogy();
//	plotter->Draw();
	histo->Draw("sameCOLZ");
	
	histo->GetXaxis()->SetTitle("PFmvaID sublead e");
	histo->GetYaxis()->SetTitle("PFmvaID lead e");
	if (lable)lables(canvas,histo);
	canvas->SaveAs((std::string(filename)+".pdf").c_str());
	canvas->SaveAs((PNGPATH+std::string(filename)+".png").c_str());

	canvas->Clear();
}

void Slicer(std::string PLOTPATH,int bin,float min, float max,std::string xaxis,TH2D *hist2D,std::string filename){

	int i;
	float x[bin],mean[bin],RMS[bin], *v=0;
	TH1D * proj[bin];
	for(i=0; i<bin;i++){
		x[i]=min +(max-min)/bin*i;
		char range[15]="";
		int n;
		n=sprintf(range,"%.3f;%.3f",x[i],x[i]+(max-min)/bin);
		proj[i]=hist2D->ProjectionX(("nhits in"+std::to_string(i)+"range").c_str(),i,i+1);
		proj[i]->GetXaxis()->SetTitle(xaxis.c_str());
		proj[i]->GetYaxis()->SetTitle("entries");
		mean[i]=proj[i]->GetMean();
		RMS[i]=proj[i]->GetMeanError();

	
	SavePlot (xaxis, proj[i],(PLOTPATH+filename+std::string(range)).c_str() ,false);


	}
	/*TGraphErrors* graph = new TGraphErrors(bin,x,mean,v,RMS);
	TCanvas* canvas = new TCanvas("","",600,550);
	canvas->Clear();
	graph->GetXaxis()->SetTitle("pt(Gev/c)");
	graph->GetYaxis()->SetTitle("mean dr");
	graph->SetMarkerStyle(8);
	graph->GetYaxis()->SetRangeUser(0,1);
	graph->Draw("AP");
	canvas->SaveAs((PLOTPATH+"/"+filename+".pdf").c_str());
	delete canvas;
	delete graph;
*/	for(i=0;i<bin;i++){
		delete proj[i];
	}
}

void AngularCorrection(struct pos* pos, TVector3* vertex,struct pos ECALpoint){
	
	TVector3 clus,vert,diff;
	double radius =400 ;
	clus.SetPtEtaPhi(radius,ECALpoint.eta,ECALpoint.phi);
	vert.SetPtEtaPhi(vertex->Perp(),vertex->Eta(),vertex->Phi());
	diff = clus-vert;
	
	(*pos).x= ECALpoint.x;
	(*pos).y= ECALpoint.y;
	(*pos).z= ECALpoint.z;
	if (diff.Phi() < M_PI)(*pos).phi= diff.Phi();
	else (*pos).phi= diff.Phi()-2*M_PI;

	(*pos).eta= diff.PseudoRapidity();
}

double DeltaR(double phi1, double eta1, double phi2, double eta2){

	double deta = eta1-eta2;
	double dphi = TVector2::Phi_mpi_pi(phi1-phi2);
	return sqrt(deta*deta+dphi*dphi);


}

void setStyle() {


	// set the TStyle
	TStyle* style = new TStyle("DrawBaseStyle", "");
	style->SetCanvasColor(0);
	style->SetPadColor(0);
	style->SetFrameFillColor(0);
	style->SetStatColor(0);
	style->SetOptStat(0);
	style->SetOptFit(0);
	style->SetTitleFillColor(0);
	style->SetCanvasBorderMode(0);
	style->SetPadBorderMode(0);
	style->SetFrameBorderMode(0);
	style->SetPadBottomMargin(0.12);
	style->SetPadLeftMargin(0.12);
	style->cd();
	// For the canvas:
	style->SetCanvasBorderMode(0);
	style->SetCanvasColor(kWhite);
	style->SetCanvasDefH(600); //Height of canvas
	style->SetCanvasDefW(600); //Width of canvas
	style->SetCanvasDefX(0); //POsition on screen
	style->SetCanvasDefY(0);
	// For the Pad:
	style->SetPadBorderMode(0);
	style->SetPadColor(kWhite);
	style->SetPadGridX(false);
	style->SetPadGridY(false);
	style->SetGridColor(0);
	style->SetGridStyle(3);
	style->SetGridWidth(1);
	// For the frame:
	style->SetFrameBorderMode(0);
	style->SetFrameBorderSize(1);
	style->SetFrameFillColor(0);
	style->SetFrameFillStyle(0);
	style->SetFrameLineColor(1);
	style->SetFrameLineStyle(1);
	style->SetFrameLineWidth(1);
	// Margins:
	style->SetPadTopMargin(0.10);
	style->SetPadBottomMargin(0.14);//0.13);
	style->SetPadLeftMargin(0.16);//0.16);
	style->SetPadRightMargin(0.1);//0.02);
	// For the Global title:
	style->SetOptTitle(0);
	style->SetTitleFont(42);
	style->SetTitleColor(1);
	style->SetTitleTextColor(1);
	style->SetTitleFillColor(10);
	style->SetTitleFontSize(0.05);
	// For the axis titles:
	style->SetTitleColor(1, "XYZ");
	style->SetTitleFont(42, "XYZ");
	style->SetTitleSize(0.05, "XYZ");
	style->SetTitleXOffset(1.15);//0.9);
	style->SetTitleYOffset(1.5); // => 1.15 if exponents
	// For the axis labels:
	style->SetLabelColor(1, "XYZ");
	style->SetLabelFont(42, "XYZ");
	style->SetLabelOffset(0.007, "XYZ");
	style->SetLabelSize(0.045, "XYZ");
	// For the axis:
	style->SetAxisColor(1, "XYZ");
	style->SetStripDecimals(kTRUE);
	style->SetTickLength(0.03, "XYZ");
	style->SetNdivisions(510, "XYZ");
	style->SetPadTickX(1); // To get tick marks on the opposite side of the frame
	style->SetPadTickY(1);
	// for histograms:
	style->SetHistLineColor(1);
	// for the pallete
	Double_t stops[5] = { 0.00, 0.34, 0.61, 0.84, 1.00 };
	Double_t red  [5] = { 0.00, 0.00, 0.87, 1.00, 0.51 };
	Double_t green[5] = { 0.00, 0.81, 1.00, 0.20, 0.00 };
	Double_t blue [5] = { 0.51, 1.00, 0.12, 0.00, 0.00 };
	TColor::CreateGradientColorTable(5, stops, red, green, blue, 100);
	style->SetNumberContours(100);

	style->cd();

}

