//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Mon Mar 30 18:23:50 2020 by ROOT version 6.12/07
// from TTree Tree/A skimmed tree with useful variables for electrons in 4mu events
// found on file: /eos/home-r/ratramon/Fake_electrons_trip/1_D_2/skimmedNANO_BPark_data_23_2020Jan2016.root
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
   Int_t           Muon_isTriggering[4];   //[nMuon]
   Int_t           Muon_pt[4];   //[nMuon]
   Float_t         DiMuon_mass[2];
   Float_t         DiMuon_ToP[2];
   Float_t         DiMuon_dVtx[2];
   Float_t         B_mass[2];
   Int_t           nElectrons;
   Float_t         Ele_pt[100];   //[nElectrons]
   Float_t         Ele_eta[100];   //[nElectrons]
   Float_t         Ele_phi[100];   //[nElectrons]
   Float_t         Ele_pfmvaId[100];   //[nElectrons]
   Bool_t          Ele_isPF[100];   //[nElectrons]

   // List of branches
   TBranch        *b_entry;   //!
   TBranch        *b_event;   //!
   TBranch        *b_nMuon;   //!
   TBranch        *b_Muon_idx;   //!
   TBranch        *b_Muon_isTriggering;   //!
   TBranch        *b_Muon_pt;   //!
   TBranch        *b_DiMuon_mass;   //!
   TBranch        *b_DiMuon_ToP;   //!
   TBranch        *b_DiMuon_dVtx;   //!
   TBranch        *b_B_mass;   //!
   TBranch        *b_nElectrons;   //!
   TBranch        *b_Ele_pt;   //!
   TBranch        *b_Ele_eta;   //!
   TBranch        *b_Ele_phi;   //!
   TBranch        *b_Ele_pfmvaId;   //!
   TBranch        *b_Ele_isPF;   //!

   virtual void     Init(TTree *tree);
   
   
   
};

#endif
