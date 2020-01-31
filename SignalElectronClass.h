//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Wed Jan 22 11:26:09 2020 by ROOT version 6.12/07
// from TTree Events/Events
// found on file: ../PhysicsTools/BParkingNano/test/BParkNANO_mc_2020Jan16.root
//////////////////////////////////////////////////////////

//#ifndef BElectronsClass_h
#define BElectronsClass_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.

class BElectronsClass {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

// Fixed size dimensions of array or collections stored in the TTree if any.

   // Declaration of leaf types
   UInt_t          run;
   UInt_t          luminosityBlock;
   ULong64_t       event;
   UInt_t          nBToKEE;
   Float_t         BToKEE_b_iso03[550];   //[nBToKEE]
   Float_t         BToKEE_b_iso04[550];   //[nBToKEE]
   Float_t         BToKEE_cos2D[550];   //[nBToKEE]
   Float_t         BToKEE_eta[550];   //[nBToKEE]
   Float_t         BToKEE_fit_cos2D[550];   //[nBToKEE]
   Float_t         BToKEE_fit_eta[550];   //[nBToKEE]
   Float_t         BToKEE_fit_k_eta[550];   //[nBToKEE]
   Float_t         BToKEE_fit_k_phi[550];   //[nBToKEE]
   Float_t         BToKEE_fit_k_pt[550];   //[nBToKEE]
   Float_t         BToKEE_fit_l1_eta[550];   //[nBToKEE]
   Float_t         BToKEE_fit_l1_phi[550];   //[nBToKEE]
   Float_t         BToKEE_fit_l1_pt[550];   //[nBToKEE]
   Float_t         BToKEE_fit_l2_eta[550];   //[nBToKEE]
   Float_t         BToKEE_fit_l2_phi[550];   //[nBToKEE]
   Float_t         BToKEE_fit_l2_pt[550];   //[nBToKEE]
   Float_t         BToKEE_fit_mass[550];   //[nBToKEE]
   Float_t         BToKEE_fit_massErr[550];   //[nBToKEE]
   Float_t         BToKEE_fit_phi[550];   //[nBToKEE]
   Float_t         BToKEE_fit_pt[550];   //[nBToKEE]
   Float_t         BToKEE_k_iso03[550];   //[nBToKEE]
   Float_t         BToKEE_k_iso04[550];   //[nBToKEE]
   Float_t         BToKEE_l1_iso03[550];   //[nBToKEE]
   Float_t         BToKEE_l1_iso04[550];   //[nBToKEE]
   Float_t         BToKEE_l2_iso03[550];   //[nBToKEE]
   Float_t         BToKEE_l2_iso04[550];   //[nBToKEE]
   Float_t         BToKEE_l_xy[550];   //[nBToKEE]
   Float_t         BToKEE_l_xy_unc[550];   //[nBToKEE]
   Float_t         BToKEE_mass[550];   //[nBToKEE]
   Float_t         BToKEE_maxDR[550];   //[nBToKEE]
   Float_t         BToKEE_minDR[550];   //[nBToKEE]
   Float_t         BToKEE_mllErr_llfit[550];   //[nBToKEE]
   Float_t         BToKEE_mll_fullfit[550];   //[nBToKEE]
   Float_t         BToKEE_mll_llfit[550];   //[nBToKEE]
   Float_t         BToKEE_mll_raw[550];   //[nBToKEE]
   Float_t         BToKEE_phi[550];   //[nBToKEE]
   Float_t         BToKEE_pt[550];   //[nBToKEE]
   Float_t         BToKEE_svprob[550];   //[nBToKEE]
   Float_t         BToKEE_vtx_ex[550];   //[nBToKEE]
   Float_t         BToKEE_vtx_ey[550];   //[nBToKEE]
   Float_t         BToKEE_vtx_ez[550];   //[nBToKEE]
   Float_t         BToKEE_vtx_x[550];   //[nBToKEE]
   Float_t         BToKEE_vtx_y[550];   //[nBToKEE]
   Float_t         BToKEE_vtx_z[550];   //[nBToKEE]
   Int_t           BToKEE_charge[550];   //[nBToKEE]
   Int_t           BToKEE_kIdx[550];   //[nBToKEE]
   Int_t           BToKEE_l1Idx[550];   //[nBToKEE]
   Int_t           BToKEE_l2Idx[550];   //[nBToKEE]
   Int_t           BToKEE_n_k_used[550];   //[nBToKEE]
   Int_t           BToKEE_n_l1_used[550];   //[nBToKEE]
   Int_t           BToKEE_n_l2_used[550];   //[nBToKEE]
   Int_t           BToKEE_pdgId[550];   //[nBToKEE]
   UInt_t          nElectron;
   Float_t         Electron_dxy[69];   //[nElectron]
   Float_t         Electron_dxyErr[69];   //[nElectron]
   Float_t         Electron_dz[69];   //[nElectron]
   Float_t         Electron_dzErr[69];   //[nElectron]
   Float_t         Electron_eta[69];   //[nElectron]
   Float_t         Electron_fBrem[69];   //[nElectron]
   Float_t         Electron_ip3d[69];   //[nElectron]
   Float_t         Electron_mass[69];   //[nElectron]
   Float_t         Electron_mvaId[69];   //[nElectron]
   Float_t         Electron_pfRelIso[69];   //[nElectron]
   Float_t         Electron_pfmvaId[69];   //[nElectron]
   Float_t         Electron_phi[69];   //[nElectron]
   Float_t         Electron_pt[69];   //[nElectron]
   Float_t         Electron_ptBiased[69];   //[nElectron]
   Float_t         Electron_sip3d[69];   //[nElectron]
   Float_t         Electron_trkRelIso[69];   //[nElectron]
   Float_t         Electron_unBiased[69];   //[nElectron]
   Float_t         Electron_vx[69];   //[nElectron]
   Float_t         Electron_vy[69];   //[nElectron]
   Float_t         Electron_vz[69];   //[nElectron]
   Int_t           Electron_charge[69];   //[nElectron]
   Int_t           Electron_pdgId[69];   //[nElectron]
   Bool_t          Electron_convVeto[69];   //[nElectron]
   Bool_t          Electron_isLowPt[69];   //[nElectron]
   Bool_t          Electron_isPF[69];   //[nElectron]
   Bool_t          Electron_isPFoverlap[69];   //[nElectron]
   UInt_t          nGenPart;
   Float_t         GenPart_eta[136];   //[nGenPart]
   Float_t         GenPart_mass[136];   //[nGenPart]
   Float_t         GenPart_phi[136];   //[nGenPart]
   Float_t         GenPart_pt[136];   //[nGenPart]
   Float_t         GenPart_vx[136];   //[nGenPart]
   Float_t         GenPart_vy[136];   //[nGenPart]
   Float_t         GenPart_vz[136];   //[nGenPart]
   Int_t           GenPart_genPartIdxMother[136];   //[nGenPart]
   Int_t           GenPart_pdgId[136];   //[nGenPart]
   Int_t           GenPart_status[136];   //[nGenPart]
   Int_t           GenPart_statusFlags[136];   //[nGenPart]
   Float_t         Generator_binvar;
   Float_t         Generator_scalePDF;
   Float_t         Generator_weight;
   Float_t         Generator_x1;
   Float_t         Generator_x2;
   Float_t         Generator_xpdf1;
   Float_t         Generator_xpdf2;
   Int_t           Generator_id1;
   Int_t           Generator_id2;
   Float_t         genWeight;
   UInt_t          nPSWeight;
   Float_t         PSWeight[1];   //[nPSWeight]
   Int_t           Electron_genPartIdx[69];   //[nElectron]
   Int_t           Electron_genPartFlav[69];   //[nElectron]

   // List of branches
   TBranch        *b_run;   //!
   TBranch        *b_luminosityBlock;   //!
   TBranch        *b_event;   //!
   TBranch        *b_nBToKEE;   //!
   TBranch        *b_BToKEE_b_iso03;   //!
   TBranch        *b_BToKEE_b_iso04;   //!
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
   TBranch        *b_BToKEE_k_iso03;   //!
   TBranch        *b_BToKEE_k_iso04;   //!
   TBranch        *b_BToKEE_l1_iso03;   //!
   TBranch        *b_BToKEE_l1_iso04;   //!
   TBranch        *b_BToKEE_l2_iso03;   //!
   TBranch        *b_BToKEE_l2_iso04;   //!
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
   TBranch        *b_BToKEE_l1Idx;   //!
   TBranch        *b_BToKEE_l2Idx;   //!
   TBranch        *b_BToKEE_n_k_used;   //!
   TBranch        *b_BToKEE_n_l1_used;   //!
   TBranch        *b_BToKEE_n_l2_used;   //!
   TBranch        *b_BToKEE_pdgId;   //!
   TBranch        *b_nElectron;   //!
   TBranch        *b_Electron_dxy;   //!
   TBranch        *b_Electron_dxyErr;   //!
   TBranch        *b_Electron_dz;   //!
   TBranch        *b_Electron_dzErr;   //!
   TBranch        *b_Electron_eta;   //!
   TBranch        *b_Electron_fBrem;   //!
   TBranch        *b_Electron_ip3d;   //!
   TBranch        *b_Electron_mass;   //!
   TBranch        *b_Electron_mvaId;   //!
   TBranch        *b_Electron_pfRelIso;   //!
   TBranch        *b_Electron_pfmvaId;   //!
   TBranch        *b_Electron_phi;   //!
   TBranch        *b_Electron_pt;   //!
   TBranch        *b_Electron_ptBiased;   //!
   TBranch        *b_Electron_sip3d;   //!
   TBranch        *b_Electron_trkRelIso;   //!
   TBranch        *b_Electron_unBiased;   //!
   TBranch        *b_Electron_vx;   //!
   TBranch        *b_Electron_vy;   //!
   TBranch        *b_Electron_vz;   //!
   TBranch        *b_Electron_charge;   //!
   TBranch        *b_Electron_pdgId;   //!
   TBranch        *b_Electron_convVeto;   //!
   TBranch        *b_Electron_isLowPt;   //!
   TBranch        *b_Electron_isPF;   //!
   TBranch        *b_Electron_isPFoverlap;   //!
   TBranch        *b_nGenPart;   //!
   TBranch        *b_GenPart_eta;   //!
   TBranch        *b_GenPart_mass;   //!
   TBranch        *b_GenPart_phi;   //!
   TBranch        *b_GenPart_pt;   //!
   TBranch        *b_GenPart_vx;   //!
   TBranch        *b_GenPart_vy;   //!
   TBranch        *b_GenPart_vz;   //!
   TBranch        *b_GenPart_genPartIdxMother;   //!
   TBranch        *b_GenPart_pdgId;   //!
   TBranch        *b_GenPart_status;   //!
   TBranch        *b_GenPart_statusFlags;   //!
   TBranch        *b_Generator_binvar;   //!
   TBranch        *b_Generator_scalePDF;   //!
   TBranch        *b_Generator_weight;   //!
   TBranch        *b_Generator_x1;   //!
   TBranch        *b_Generator_x2;   //!
   TBranch        *b_Generator_xpdf1;   //!
   TBranch        *b_Generator_xpdf2;   //!
   TBranch        *b_Generator_id1;   //!
   TBranch        *b_Generator_id2;   //!
   TBranch        *b_genWeight;   //!
   TBranch        *b_nPSWeight;   //!
   TBranch        *b_PSWeight;   //!
   TBranch        *b_Electron_genPartIdx;   //!
   TBranch        *b_Electron_genPartFlav;   //!
   TBranch        *b_Muon_genPartIdx;   //!

  // BElectronsClass(TTree *tree=0);
  // virtual ~BElectronsClass();
  // virtual Int_t    Cut(Long64_t entry);
  // virtual Int_t    GetEntry(Long64_t entry);
  // virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
  // virtual void     Loop();
  // virtual Bool_t   Notify();
  // virtual void     Show(Long64_t entry = -1);
};

//#endif

//#ifdef BElectronsClass_cxx
