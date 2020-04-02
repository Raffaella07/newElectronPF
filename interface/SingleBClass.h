//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Tue Mar  3 09:02:41 2020 by ROOT version 6.12/07
// from TTree Tree/A skimmed tree containing one selected nBToKEE event
// found on file: /eos/home-r/ratramon/BToKEE/1_C_0/skimmedNANO_BPark_data_23_2020Jan2016.root
//////////////////////////////////////////////////////////

#define SingleBClass_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.

class SingleBClass {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

// Fixed size dimensions of array or collections stored in the TTree if any.

   // Declaration of leaf types
   Int_t           entry;
   Int_t           event;
   Float_t         BToKEE_chi2;
   Float_t         BToKEE_cos2D;
   Float_t         BToKEE_eta;
   Float_t         BToKEE_fit_cos2D;
   Float_t         BToKEE_fit_eta;
   Float_t         BToKEE_fit_k_eta;
   Float_t         BToKEE_fit_k_phi;
   Float_t         BToKEE_fit_k_pt;
   Float_t         BToKEE_fit_l1_eta;
   Float_t         BToKEE_fit_l1_phi;
   Float_t         BToKEE_fit_l1_pt;
   Float_t         BToKEE_fit_l2_eta;
   Float_t         BToKEE_fit_l2_phi;
   Float_t         BToKEE_fit_l2_pt;
   Float_t         BToKEE_fit_mass;
   Float_t         BToKEE_fit_massErr;
   Float_t         BToKEE_fit_phi;
   Float_t         BToKEE_fit_pt;
   Float_t         BToKEE_l_xy;
   Float_t         BToKEE_l_xy_unc;
   Float_t         BToKEE_mass;
   Float_t         BToKEE_maxDR;
   Float_t         BToKEE_minDR;
   Float_t         BToKEE_mllErr_llfit;
   Float_t         BToKEE_mll_fullfit;
   Float_t         BToKEE_mll_llfit;
   Float_t         BToKEE_mll_raw;
   Float_t         BToKEE_phi;
   Float_t         BToKEE_pt;
   Float_t         BToKEE_svprob;
   Float_t         BToKEE_vtx_ex;
   Float_t         BToKEE_vtx_ey;
   Float_t         BToKEE_vtx_ez;
   Float_t         BToKEE_vtx_x;
   Float_t         BToKEE_vtx_y;
   Float_t         BToKEE_vtx_z;
   Int_t           BToKEE_charge;
   Int_t           BToKEE_kIdx;
   Float_t         BToKEE_l1pt;
   Float_t         BToKEE_l2pt;
   Float_t         BToKEE_l1eta;
   Float_t         BToKEE_l2eta;
   Float_t         BToKEE_l1phi;
   Float_t         BToKEE_l2phi;
   Float_t         BToKEE_l1pfmvaId;
   Float_t         BToKEE_l2pfmvaId;
   Int_t           BToKEE_pdgId;
   Int_t           nElectrons;

   // List of branches
   TBranch        *b_entry;   //!
   TBranch        *b_event;   //!
   TBranch        *b_BToKEE_chi2;   //!
   TBranch        *b_BToKEE_cos2D;   //!
   TBranch        *b_BToKEE_eta;   //!
   TBranch        *b_BToKEE_fit_cos2D;   //!
   TBranch        *b_BToKEE_fit_eta;   //!
   TBranch        *b_BToKEE_fit_k_eta;   //!
   TBranch        *b_BToKEE_fit_k_phi;   //!
   TBranch        *b_BToKEE_fit_k_pt;   //!
   TBranch        *b_BToKEE_fit_l1_eta;   //!
   TBranch        *b_BToKEE_fit_l1_phi;   //!
   TBranch        *b_BToKEE_fit_l1_pt;   //!
   TBranch        *b_BToKEE_fit_l2_eta;   //!
   TBranch        *b_BToKEE_fit_l2_phi;   //!
   TBranch        *b_BToKEE_fit_l2_pt;   //!
   TBranch        *b_BToKEE_fit_mass;   //!
   TBranch        *b_BToKEE_fit_massErr;   //!
   TBranch        *b_BToKEE_fit_phi;   //!
   TBranch        *b_BToKEE_fit_pt;   //!
   TBranch        *b_BToKEE_l_xy;   //!
   TBranch        *b_BToKEE_l_xy_unc;   //!
   TBranch        *b_BToKEE_mass;   //!
   TBranch        *b_BToKEE_maxDR;   //!
   TBranch        *b_BToKEE_minDR;   //!
   TBranch        *b_BToKEE_mllErr_llfit;   //!
   TBranch        *b_BToKEE_mll_fullfit;   //!
   TBranch        *b_BToKEE_mll_llfit;   //!
   TBranch        *b_BToKEE_mll_raw;   //!
   TBranch        *b_BToKEE_phi;   //!
   TBranch        *b_BToKEE_pt;   //!
   TBranch        *b_BToKEE_svprob;   //!
   TBranch        *b_BToKEE_vtx_ex;   //!
   TBranch        *b_BToKEE_vtx_ey;   //!
   TBranch        *b_BToKEE_vtx_ez;   //!
   TBranch        *b_BToKEE_vtx_x;   //!
   TBranch        *b_BToKEE_vtx_y;   //!
   TBranch        *b_BToKEE_vtx_z;   //!
   TBranch        *b_BToKEE_charge;   //!
   TBranch        *b_BToKEE_kIdx;   //!
   TBranch        *b_BToKEE_l1pt;   //!
   TBranch        *b_BToKEE_l2pt;   //!
   TBranch        *b_BToKEE_l1eta;   //!
   TBranch        *b_BToKEE_l2eta;   //!
   TBranch        *b_BToKEE_l1phi;   //!
   TBranch        *b_BToKEE_l2phi;   //!
   TBranch        *b_BToKEE_l1pfmvaId;   //!
   TBranch        *b_BToKEE_l2pfmvaId;   //!
   TBranch        *b_BToKEE_pdgId;   //!
   TBranch        *b_nElectrons;   //!

   virtual void     Init(TTree *tree);
};



