#include "../interface/BGElectronClass.h"


void BGElectronClass::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("entry", &entry, &b_entry);
   fChain->SetBranchAddress("event", &event, &b_event);
   fChain->SetBranchAddress("nMuon", &nMuon, &b_nMuon);
   fChain->SetBranchAddress("Muon_idx", Muon_idx, &b_Muon_idx);
   fChain->SetBranchAddress("nElectrons", &nElectrons, &b_nElectrons);
   fChain->SetBranchAddress("Ele_pt", Ele_pt, &b_Ele_pt);
   fChain->SetBranchAddress("Ele_eta", Ele_eta, &b_Ele_eta);
   fChain->SetBranchAddress("Ele_phi", Ele_phi, &b_Ele_phi);
   fChain->SetBranchAddress("Ele_pfmvaId", Ele_pfmvaId, &b_Ele_pfmvaId);
   fChain->SetBranchAddress("Ele_isPF", Ele_isPF, &b_Ele_isPF);
}

