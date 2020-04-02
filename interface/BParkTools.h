#include "../interface/BPark_fitUtils.h"
#include "../interface/BNanoClass.h"
#include "../interface/SingleBClass.h"
#include "../interface/SelectedBClass.h"
#include "../interface/BElectronsClass.h"
#include "../interface/BGElectronClass.h"
#include "../interface/BElectronsClassMC.h"
#include "../interface/BSignalElectronClass.h"

struct pos{

    float x;
    float y;
    float z;
    float phi;
    float eta;
    float pt;



};

/*ROOT::VecOps::RVec<bool> IsGood(unsigned int nB, 
				float *pT1, float *pT2, float *pTk, 
 				ROOT::VecOps::RVec<unsigned int>& nTrg,float *cos2D, float *vtxP, 
 				float *disp, float *dispU, float *pT,float*eta) ; 

ROOT::VecOps::RVec<int> Rankv2(ROOT::VecOps::RVec<float>& vtxP);

*/
void FillKinhistos(TH1D** histo, double pt, double eta, double phi, int type);

Double_t fline(Double_t *x, Double_t *par);

double sigma_Bsig();

TTree* mergeTrees(int n_files,std::string filename);


void lables1D(TCanvas* canv,TH1D* histo);


void SavePlot (std::string titlestring, TH1D * histo, const char * filename, bool log=false, TF1* fit= NULL, bool lable=false);


void lables(TCanvas* canv,TH2D* histo);



void superpos(std::string titlestring,TH1D * h1, TH1D* h2, const char* filename,bool log=false, bool lable= false);


void superMC_DATAnorm(TH1D* histo1,TH1D* histo2,TH1D* histo3,TH1D* histo4,double x_lable, std::string filename,std::string axis, bool order, bool log);


void Fill_MChistos(BSignalElectronClass  *tree, TH1D * PFmvaId,TH1D * pt,TH1D * eta);


void Fill_DATAhistos(BGElectronClass *tree, TH1D * PFmvaId,TH1D * pt,TH1D * eta, int sel );
void Fill_DATAhistosNano(BNanoClass *tree, TH1D * PFmvaId,TH1D * pt,TH1D * eta, int sel );


void SavePlot2D (std::string Xstring, std::string Ystring,TH2D * histo,const char*  filename, bool log=false,bool lable=false);



void Slicer(std::string PLOTPATH,int bin,float min, float max,std::string xaxis,TH2D *hist2D,std::string filename);


void AngularCorrection(struct pos* pos, TVector3* vertex,struct pos ECALpoint);


double DeltaR(double phi1, double eta1, double phi2, double eta2);


void setStyle();
