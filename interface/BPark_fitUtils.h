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
#include "RooWorkspace.h"
#include "RooFitResult.h"
#include "RooDataHist.h"
#include "RooPlot.h"
#include "TTree.h"
#include "TLatex.h"
#include "TLegend.h"
#include "TCanvas.h"
#include "TGraph.h"
#include "TGraphErrors.h"
#include "TStyle.h"
#include "TString.h"
#include "TLorentzVector.h"
#include "TTree.h"
	
double SignalWeight();

std::pair<double,double> fit(TH1D* , int , int, bool,double);
