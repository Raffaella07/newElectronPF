#include "../interface/BSignalElectronClass.h"

void BSignalElectronClass::Init(TTree *tree)
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
   fChain->SetBranchAddress("B_mass", &B_mass, &b_B_mass);
   fChain->SetBranchAddress("B_charge", &B_charge, &b_B_charge);
   fChain->SetBranchAddress("B_pt", &B_pt, &b_B_pt);
   fChain->SetBranchAddress("B_eta", &B_eta, &b_B_eta);
   fChain->SetBranchAddress("B_phi", &B_phi, &b_B_phi);
   fChain->SetBranchAddress("B_cos2D", &B_cos2D, &b_B_cos2D);
   fChain->SetBranchAddress("B_l_xy", &B_l_xy, &b_B_l_xy);
   fChain->SetBranchAddress("B_l_xy_unc", &B_l_xy_unc, &b_B_l_xy_unc);
   fChain->SetBranchAddress("B_svprob", &B_svprob, &b_B_svprob);
   fChain->SetBranchAddress("B_vtx_x", &B_vtx_x, &b_B_vtx_x);
   fChain->SetBranchAddress("B_vtx_y", &B_vtx_y, &b_B_vtx_y);
   fChain->SetBranchAddress("B_vtx_z", &B_vtx_z, &b_B_vtx_z);
   fChain->SetBranchAddress("B_vtx_ex", &B_vtx_ex, &b_B_vtx_ex);
   fChain->SetBranchAddress("B_vtx_ey", &B_vtx_ey, &b_B_vtx_ey);
   fChain->SetBranchAddress("B_vtx_ez", &B_vtx_ez, &b_B_vtx_ez);
   fChain->SetBranchAddress("B_mll_raw", &B_mll_raw, &b_B_mll_raw);
   fChain->SetBranchAddress("B_l1_pt", &B_l1_pt, &b_B_l1_pt);
   fChain->SetBranchAddress("B_l1_eta", &B_l1_eta, &b_B_l1_eta);
   fChain->SetBranchAddress("B_l1_phi", &B_l1_phi, &b_B_l1_phi);
   fChain->SetBranchAddress("B_l1_mvaId", &B_l1_mvaId, &b_B_l1_mvaId);
   fChain->SetBranchAddress("B_l2_pt", &B_l2_pt, &b_B_l2_pt);
   fChain->SetBranchAddress("B_l2_eta", &B_l2_eta, &b_B_l2_eta);
   fChain->SetBranchAddress("B_l2_phi", &B_l2_phi, &b_B_l2_phi);
   fChain->SetBranchAddress("B_l2_mvaId", &B_l2_mvaId, &b_B_l2_mvaId);
   fChain->SetBranchAddress("B_l1_isPF", &B_l1_isPF, &b_B_l1_isPF);
   fChain->SetBranchAddress("B_l2_isPF", &B_l2_isPF, &b_B_l2_isPF);
   fChain->SetBranchAddress("B_l1_Sig", &B_l1_Sig, &b_B_l1_Sig);
   fChain->SetBranchAddress("B_l2_Sig", &B_l2_Sig, &b_B_l2_Sig);
//   Notify();
}
