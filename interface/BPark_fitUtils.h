#include <iostream>
#include <utility>
#include <vector>
#include <math.h>
#include <string>
#include "TH1.h"
#include "TF1.h"
#include "TH2.h"
#include "TMath.h"
#include "TFile.h"
#include "TAxis.h"
#include "RooRealVar.h"
#include "RooAbsPdf.h"
#include "RooBinning.h"
#include "RooWorkspace.h"
#include "RooFitResult.h"
#include "RooDataHist.h"
#include "RooDataSet.h"
#include "RooKeysPdf.h"
#include "RooPlot.h"
#include "TLegend.h"
#include "TCanvas.h"
#include "TPad.h"
#include "TLatex.h"
#include "TLine.h"
#include "TBox.h"
//#include "TASImage.h"
#include "TGraph.h"
#include "TGraphErrors.h"
#include "TStyle.h"
#include "TString.h"
#include "TLorentzVector.h"
#include "TTree.h"
#include "../interface/BCategorizedClass.h"
#include "../interface/BSixCand.h"
#include "../interface/BminiTree.h"
#include "../interface/BminiMCTree.h"


// Global variables
//


void CMS_lumi( TPad* pad, int iPeriod, int iPosX, double lumi);

double SignalWeight();

double mc_templEff(BminiMCTree*, TH1D* ,TTree*, bool ,int,int, int,double);//this function fill the histogram of mass spectum with MC data passing the same selection of data and returns as double the efficiency for each BDT cut

void fit(TH1D* , int , int, bool,int,int,double, double*);
