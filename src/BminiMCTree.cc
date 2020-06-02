#include "../interface/BminiMCTree.h" 
void BminiMCTree::Init(TTree *tree)
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
   fChain->SetBranchAddress("HLT_Mu12_IP6", &HLT_Mu12_IP6, &b_iHLT_Mu12_IP6);
   fChain->SetBranchAddress("HLT_Mu9_IP6", &HLT_Mu9_IP6, &b_iHLT_Mu9_IP6);
   fChain->SetBranchAddress("cat0", &cat0, &b_cat0);
   fChain->SetBranchAddress("cat1", &cat1, &b_cat1);
   fChain->SetBranchAddress("BDT_0", &BDT_0, &b_BDT_0);
   fChain->SetBranchAddress("BDT_1", &BDT_1, &b_BDT_1);
   fChain->SetBranchAddress("B_mass", &B_mass, &b_B_mass);
   fChain->SetBranchAddress("ll_mass", &ll_mass, &b_ll_mass);
   fChain->SetBranchAddress("is_MC", &is_MC, &b_is_MC);
}

