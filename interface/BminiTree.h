//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Tue May  5 19:13:43 2020 by ROOT version 6.12/07
// from TTree Mini/A skimmed tree containing only information to fit mb spectrum
// found on file: /eos/home-r/ratramon/BToKEE_mini/1_D_0/3.root
//////////////////////////////////////////////////////////

#ifndef BminiTree_h
#define BminiTree_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.

class BminiTree {
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

   virtual void     Init(TTree *tree);
};

#endif

