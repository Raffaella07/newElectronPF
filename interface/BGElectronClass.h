//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Fri Jan 31 16:47:36 2020 by ROOT version 6.18/02
// from TTree BGTree/A skimmed tree with useful variables for electrons in 4mu events
// found on file: skimmedNANO_BPark_data_EleBG_2020Jan16.root
//////////////////////////////////////////////////////////

#ifndef BGElectronClass_h
#define BGElectronClass_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.

class BGElectronClass {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

// Fixed size dimensions of array or collections stored in the TTree if any.

   // Declaration of leaf types
   Int_t           entry;
   Double_t        event;
   Int_t           nMuon;
   Int_t           Muon_idx[4];   //[nMuon]
   Int_t           nElectrons;
   Float_t         Ele_pt[81];   //[nElectrons]
   Float_t         Ele_eta[81];   //[nElectrons]
   Float_t         Ele_phi[81];   //[nElectrons]
   Float_t         Ele_pfmvaId[81];   //[nElectrons]
   Bool_t          Ele_isPF[81];   //[nElectrons]

   // List of branches
   TBranch        *b_entry;   //!
   TBranch        *b_event;   //!
   TBranch        *b_nMuon;   //!
   TBranch        *b_Muon_idx;   //!
   TBranch        *b_nElectrons;   //!
   TBranch        *b_Ele_pt;   //!
   TBranch        *b_Ele_eta;   //!
   TBranch        *b_Ele_phi;   //!
   TBranch        *b_Ele_pfmvaId;   //!
   TBranch        *b_Ele_isPF;   //!

   virtual void     Init(TTree *tree);
};

#endif

