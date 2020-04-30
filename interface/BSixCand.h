//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Mon Apr 27 10:09:38 2020 by ROOT version 6.12/07
// from TTree Tree/A skimmed tree containing one selected nBToKEE event
// found on file: /eos/home-r/ratramon/BToKEE_6cand/1_D_1/skimmedNANO_BPark_data_23_2020Jan2016.root
//////////////////////////////////////////////////////////

#ifndef BSixCand_h
#define BSixCand_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.

class BSixCand {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

// Fixed size dimensions of array or collections stored in the TTree if any.

   // Declaration of leaf types
   Int_t           entry;
   Int_t           event;
   Int_t           category;
   Int_t           nSaved;
   Int_t           HLT_Mu12_IP6;
   Int_t           HLT_Mu9_IP6;
   Float_t         BToKEE_chi2[6];   //[nSaved]
   Float_t         BToKEE_cos2D[6];   //[nSaved]
   Float_t         BToKEE_eta[6];   //[nSaved]
   Float_t         BToKEE_BDT[6];   //[nSaved]
   Float_t         BToKEE_fit_cos2D[6];   //[nSaved]
   Float_t         BToKEE_fit_eta[6];   //[nSaved]
   Float_t         BToKEE_fit_k_eta[6];   //[nSaved]
   Float_t         BToKEE_fit_k_phi[6];   //[nSaved]
   Float_t         BToKEE_fit_k_pt[6];   //[nSaved]
   Float_t         BToKEE_fit_l1_eta[6];   //[nSaved]
   Float_t         BToKEE_fit_l1_phi[6];   //[nSaved]
   Float_t         BToKEE_fit_l1_pt[6];   //[nSaved]
   Float_t         BToKEE_fit_l2_eta[6];   //[nSaved]
   Float_t         BToKEE_fit_l2_phi[6];   //[nSaved]
   Float_t         BToKEE_fit_l2_pt[6];   //[nSaved]
   Float_t         BToKEE_fit_mass[6];   //[nSaved]
   Float_t         BToKEE_fit_massErr[6];   //[nSaved]
   Float_t         BToKEE_fit_phi[6];   //[nSaved]
   Float_t         BToKEE_fit_pt[6];   //[nSaved]
   Float_t         BToKEE_l_xy[6];   //[nSaved]
   Float_t         BToKEE_l_xy_unc[6];   //[nSaved]
   Float_t         BToKEE_l_xy_sig[6];   //[nSaved]
   Float_t         BToKEE_iso04[6];   //[nSaved]
   Float_t         BToKEE_mass[6];   //[nSaved]
   Float_t         BToKEE_maxDR[6];   //[nSaved]
   Float_t         BToKEE_minDR[6];   //[nSaved]
   Float_t         BToKEE_mllErr_llfit[6];   //[nSaved]
   Float_t         BToKEE_mll_fullfit[6];   //[nSaved]
   Float_t         BToKEE_mll_llfit[6];   //[nSaved]
   Float_t         BToKEE_mll_raw[6];   //[nSaved]
   Float_t         BToKEE_phi[6];   //[nSaved]
   Float_t         BToKEE_pt[6];   //[nSaved]
   Float_t         BToKEE_ptImb[6];   //[nSaved]
   Float_t         BToKEE_ptN[6];   //[nSaved]
   Float_t         BToKEE_svprob[6];   //[nSaved]
   Float_t         BToKEE_vtx_ex[6];   //[nSaved]
   Float_t         BToKEE_vtx_ey[6];   //[nSaved]
   Float_t         BToKEE_vtx_ez[6];   //[nSaved]
   Float_t         BToKEE_vtx_x[6];   //[nSaved]
   Float_t         BToKEE_vtx_y[6];   //[nSaved]
   Float_t         BToKEE_vtx_z[6];   //[nSaved]
   Int_t           BToKEE_charge[6];   //[nSaved]
   Float_t         BToKEE_l1_pt[6];   //[nSaved]
   Float_t         BToKEE_l2_pt[6];   //[nSaved]
   Float_t         BToKEE_l1_ptN[6];   //[nSaved]
   Float_t         BToKEE_l2_ptN[6];   //[nSaved]
   Float_t         BToKEE_l1_eta[6];   //[nSaved]
   Float_t         BToKEE_l2_eta[6];   //[nSaved]
   Float_t         BToKEE_l1_phi[6];   //[nSaved]
   Float_t         BToKEE_l2_phi[6];   //[nSaved]
   Bool_t          BToKEE_l1_isPF[6];   //[nSaved]
   Bool_t          BToKEE_l2_isPF[6];   //[nSaved]
   Float_t         BToKEE_l1_pfmvaId[6];   //[nSaved]
   Float_t         BToKEE_l2_pfmvaId[6];   //[nSaved]
   Bool_t          BToKEE_l1_isLowPt[6];   //[nSaved]
   Bool_t          BToKEE_l2_isLowPt[6];   //[nSaved]
   Float_t         BToKEE_l1_mvaId[6];   //[nSaved]
   Float_t         BToKEE_l2_mvaId[6];   //[nSaved]
   Float_t         BToKEE_l1_iso04[6];   //[nSaved]
   Float_t         BToKEE_l2_iso04[6];   //[nSaved]
   Float_t         BToKEE_l1_dxySig[6];   //[nSaved]
   Float_t         BToKEE_l2_dxySig[6];   //[nSaved]
   Bool_t          BToKEE_l1_isPFoverlap[6];   //[nSaved]
   Bool_t          BToKEE_l2_isPfoverlap[6];   //[nSaved]
   Float_t         BToKEE_k_pt[6];   //[nSaved]
   Float_t         BToKEE_k_ptN[6];   //[nSaved]
   Float_t         BToKEE_k_eta[6];   //[nSaved]
   Float_t         BToKEE_k_phi[6];   //[nSaved]
   Float_t         BToKEE_k_iso04[6];   //[nSaved]
   Float_t         BToKEE_k_dxySig[6];   //[nSaved]
   Float_t         BToKEE_DeltaZ[6];   //[nSaved]
   Int_t           BToKEE_pdgId[6];   //[nSaved]
   Bool_t          BToKEE_isMC[6];   //[nSaved]

   // List of branches
   TBranch        *b_entry;   //!
   TBranch        *b_event;   //!
   TBranch        *b_category;   //!
   TBranch        *b_nSaved;   //!
   TBranch        *b_iHLT_Mu12_IP6;   //!
   TBranch        *b_iHLT_Mu9_IP6;   //!
   TBranch        *b_BToKEE_chi2;   //!
   TBranch        *b_BToKEE_cos2D;   //!
   TBranch        *b_BToKEE_eta;   //!
   TBranch        *b_BToKEE_BDT;   //!
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
   TBranch        *b_BToKEE_l_xy_sig;   //!
   TBranch        *b_BToKEE_iso04;   //!
   TBranch        *b_BToKEE_mass;   //!
   TBranch        *b_BToKEE_maxDR;   //!
   TBranch        *b_BToKEE_minDR;   //!
   TBranch        *b_BToKEE_mllErr_llfit;   //!
   TBranch        *b_BToKEE_mll_fullfit;   //!
   TBranch        *b_BToKEE_mll_llfit;   //!
   TBranch        *b_BToKEE_mll_raw;   //!
   TBranch        *b_BToKEE_phi;   //!
   TBranch        *b_BToKEE_pt;   //!
   TBranch        *b_BToKEE_ptImb;   //!
   TBranch        *b_BToKEE_ptN;   //!
   TBranch        *b_BToKEE_svprob;   //!
   TBranch        *b_BToKEE_vtx_ex;   //!
   TBranch        *b_BToKEE_vtx_ey;   //!
   TBranch        *b_BToKEE_vtx_ez;   //!
   TBranch        *b_BToKEE_vtx_x;   //!
   TBranch        *b_BToKEE_vtx_y;   //!
   TBranch        *b_BToKEE_vtx_z;   //!
   TBranch        *b_BToKEE_charge;   //!
   TBranch        *b_BToKEE_l1_pt;   //!
   TBranch        *b_BToKEE_l2_pt;   //!
   TBranch        *b_BToKEE_l1_ptN;   //!
   TBranch        *b_BToKEE_l2_ptN;   //!
   TBranch        *b_BToKEE_l1_eta;   //!
   TBranch        *b_BToKEE_l2_eta;   //!
   TBranch        *b_BToKEE_l1_phi;   //!
   TBranch        *b_BToKEE_l2_phi;   //!
   TBranch        *b_BToKEE_l1_isPF;   //!
   TBranch        *b_BToKEE_l2_isPF;   //!
   TBranch        *b_BToKEE_l1_pfmvaId;   //!
   TBranch        *b_BToKEE_l2_pfmvaId;   //!
   TBranch        *b_BToKEE_l1_isLowPt;   //!
   TBranch        *b_BToKEE_l2_isLowPt;   //!
   TBranch        *b_BToKEE_l1_mvaId;   //!
   TBranch        *b_BToKEE_l2_mvaId;   //!
   TBranch        *b_BToKEE_l1_iso04;   //!
   TBranch        *b_BToKEE_l2_iso04;   //!
   TBranch        *b_BToKEE_l1_dxySig;   //!
   TBranch        *b_BToKEE_l2_dxySig;   //!
   TBranch        *b_BToKEE_l1_isPFoverlap;   //!
   TBranch        *b_BToKEE_l2_isPfoverlap;   //!
   TBranch        *b_BToKEE_k_pt;   //!
   TBranch        *b_BToKEE_k_ptN;   //!
   TBranch        *b_BToKEE_k_eta;   //!
   TBranch        *b_BToKEE_k_phi;   //!
   TBranch        *b_BToKEE_k_iso04;   //!
   TBranch        *b_BToKEE_k_dxySig;   //!
   TBranch        *b_BToKEE_DeltaZ;   //!
   TBranch        *b_BToKEE_pdgId;   //!
   TBranch        *b_BToKEE_isMC;   //!

   virtual void     Init(TTree *tree);
};

#endif



