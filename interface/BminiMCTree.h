//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Mon May 25 23:57:15 2020 by ROOT version 6.12/07
// from TTree Mini/A skimmed tree containing only information to fit mb spectrum
// found on file: mini_mc_res.root
//////////////////////////////////////////////////////////

#ifndef BminiMCTree_h
#define BminiMCTree_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.

class BminiMCTree {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

// Fixed size dimensions of array or collections stored in the TTree if any.

   // Declaration of leaf types
   Int_t           entry;
   Int_t           HLT_Mu12_IP6;
   Int_t           HLT_Mu9_IP6;
   Int_t           cat0;
   Int_t           cat1;
   Double_t        BDT_0;
   Double_t        BDT_1;
   Double_t        B_mass;
   Double_t        ll_mass;
   Int_t          is_MC;

   // List of branches
   TBranch        *b_entry;   //!
   TBranch        *b_iHLT_Mu12_IP6;   //!
   TBranch        *b_iHLT_Mu9_IP6;   //!
   TBranch        *b_cat0;   //!
   TBranch        *b_cat1;   //!
   TBranch        *b_BDT_0;   //!
   TBranch        *b_BDT_1;   //!
   TBranch        *b_B_mass;   //!
   TBranch        *b_ll_mass;   //!
   TBranch        *b_is_MC;   //!

   virtual void     Init(TTree *tree);
};

#endif


