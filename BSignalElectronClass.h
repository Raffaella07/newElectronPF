//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Fri Jan 31 15:09:12 2020 by ROOT version 6.18/02
// from TTree Tree/A skimmed tree with useful variables for the best BToKEE candidate
// found on file: skimmedNANO_BPark_mc_2020Jan16.root
//////////////////////////////////////////////////////////

//#ifndef BSignalElectronClass_h
#define BSignalElectronClass_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.

class BSignalElectronClass {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

// Fixed size dimensions of array or collections stored in the TTree if any.

   // Declaration of leaf types
   Double_t        entry;
   Double_t        B_mass;
   Double_t        B_charge;
   Double_t        B_pt;
   Double_t        B_eta;
   Double_t        B_phi;
   Double_t        B_cos2D;
   Double_t        B_l_xy;
   Double_t        B_l_xy_unc;
   Double_t        B_svprob;
   Double_t        B_vtx_x;
   Double_t        B_vtx_y;
   Double_t        B_vtx_z;
   Double_t        B_vtx_ex;
   Double_t        B_vtx_ey;
   Double_t        B_vtx_ez;
   Double_t        B_mll_raw;
   Double_t        B_l1_pt;
   Double_t        B_l1_eta;
   Double_t        B_l1_phi;
   Double_t        B_l1_mvaId;
   Double_t        B_l2_pt;
   Double_t        B_l2_eta;
   Double_t        B_l2_phi;
   Double_t        B_l2_mvaId;
   Double_t        B_l1_isPF;
   Double_t        B_l2_isPF;
   Double_t        B_l1_Sig;
   Double_t        B_l2_Sig;

   // List of branches
   TBranch        *b_entry;   //!
   TBranch        *b_B_mass;   //!
   TBranch        *b_B_charge;   //!
   TBranch        *b_B_pt;   //!
   TBranch        *b_B_eta;   //!
   TBranch        *b_B_phi;   //!
   TBranch        *b_B_cos2D;   //!
   TBranch        *b_B_l_xy;   //!
   TBranch        *b_B_l_xy_unc;   //!
   TBranch        *b_B_svprob;   //!
   TBranch        *b_B_vtx_x;   //!
   TBranch        *b_B_vtx_y;   //!
   TBranch        *b_B_vtx_z;   //!
   TBranch        *b_B_vtx_ex;   //!
   TBranch        *b_B_vtx_ey;   //!
   TBranch        *b_B_vtx_ez;   //!
   TBranch        *b_B_mll_raw;   //!
   TBranch        *b_B_l1_pt;   //!
   TBranch        *b_B_l1_eta;   //!
   TBranch        *b_B_l1_phi;   //!
   TBranch        *b_B_l1_mvaId;   //!
   TBranch        *b_B_l2_pt;   //!
   TBranch        *b_B_l2_eta;   //!
   TBranch        *b_B_l2_phi;   //!
   TBranch        *b_B_l2_mvaId;   //!
   TBranch        *b_B_l1_isPF;   //!
   TBranch        *b_B_l2_isPF;   //!
   TBranch        *b_B_l1_Sig;   //!
   TBranch        *b_B_l2_Sig;   //!

 //  BSignalElectronClass(TTree *tree=0);
  // virtual ~BSignalElectronClass();
//  virtual Int_t    Cut(Long64_t entry);
//  virtual Int_t    GetEntry(Long64_t entry);
//  virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
//  virtual void     Loop();
//  virtual Bool_t   Notify();
//  virtual void     Show(Long64_t entry = -1);
};

//#endif

//#ifdef BSignalElectronClass_cxx

