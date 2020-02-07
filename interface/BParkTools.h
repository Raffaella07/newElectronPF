#include "../interface/BNanoClass.h"
#include "../interface/BElectronsClass.h"
#include "../interface/BGElectronClass.h"
#include "../interface/BElectronsClassMC.h"
#include "../interface/BSignalElectronClass.h"
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
#include "TTree.h"
#include <ROOT/RDataFrame.hxx>
#include <ROOT/RVec.hxx>
#include "TStopwatch.h"
#include <iostream>
#include <utility>
#include <vector>
#include <math.h>
#include <string>
#include "TF1.h"
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
 				float *disp, float *dispU, float *pT,float*eta) ; 

ROOT::VecOps::RVec<int> Rankv2(ROOT::VecOps::RVec<float>& vtxP);


void FillKinhistos(TH1D** histo, double pt, double eta, double phi, int type);

Double_t fline(Double_t *x, Double_t *par);

double sigma_Bsig();

TTree* mergeTrees(int n_files,std::string filename);


void lables1D(TCanvas* canv,TH1D* histo);


void SavePlot (std::string titlestring, TH1D * histo, const char * filename, bool log=false, TF1* fit= NULL, bool lable=false);


void lables(TCanvas* canv,TH2D* histo);



void superpos(std::string titlestring,TH1D * h1, TH1D* h2, const char* filename,bool log=false, bool lable= false);


void superMC_DATAnorm(TH1D* histo1,TH1D* histo2,TH1D* histo3,double x_lable, std::string filename,std::string axis, bool order, bool log);


void Fill_MChistos(BSignalElectronClass  *tree, TH1D * PFmvaId,TH1D * pt,TH1D * eta);


void Fill_DATAhistos(BGElectronClass *tree, TH1D * PFmvaId,TH1D * pt,TH1D * eta);


void SavePlot2D (std::string titlestring, TH2D * histo,const char*  filename, bool log=false,bool lable=false);



void Slicer(std::string PLOTPATH,int bin,float min, float max,std::string xaxis,TH2D *hist2D,std::string filename);


void AngularCorrection(struct pos* pos, TVector3* vertex,struct pos ECALpoint);


double DeltaR(double phi1, double eta1, double phi2, double eta2);


void setStyle();
