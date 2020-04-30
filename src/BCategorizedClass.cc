#include "../interface/BCategorizedClass.h"

void BCategorizedClass::Init(TTree *tree)
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
   fChain->SetBranchAddress("category", &category, &b_category);
   fChain->SetBranchAddress("nSaved", &nSaved, &b_nSaved);
   fChain->SetBranchAddress("HLT_Mu12_IP6", &HLT_Mu12_IP6, &b_iHLT_Mu12_IP6);
   fChain->SetBranchAddress("HLT_Mu9_IP6", &HLT_Mu9_IP6, &b_iHLT_Mu9_IP6);
   fChain->SetBranchAddress("BToKEE_chi2", BToKEE_chi2, &b_BToKEE_chi2);
   fChain->SetBranchAddress("BToKEE_cos2D", BToKEE_cos2D, &b_BToKEE_cos2D);
   fChain->SetBranchAddress("BToKEE_eta", BToKEE_eta, &b_BToKEE_eta);
   fChain->SetBranchAddress("BToKEE_fit_cos2D", BToKEE_fit_cos2D, &b_BToKEE_fit_cos2D);
   fChain->SetBranchAddress("BToKEE_fit_eta", BToKEE_fit_eta, &b_BToKEE_fit_eta);
   fChain->SetBranchAddress("BToKEE_fit_k_eta", BToKEE_fit_k_eta, &b_BToKEE_fit_k_eta);
   fChain->SetBranchAddress("BToKEE_fit_k_phi", BToKEE_fit_k_phi, &b_BToKEE_fit_k_phi);
   fChain->SetBranchAddress("BToKEE_fit_k_pt", BToKEE_fit_k_pt, &b_BToKEE_fit_k_pt);
   fChain->SetBranchAddress("BToKEE_fit_l1_eta", BToKEE_fit_l1_eta, &b_BToKEE_fit_l1_eta);
   fChain->SetBranchAddress("BToKEE_fit_l1_phi", BToKEE_fit_l1_phi, &b_BToKEE_fit_l1_phi);
   fChain->SetBranchAddress("BToKEE_fit_l1_pt", BToKEE_fit_l1_pt, &b_BToKEE_fit_l1_pt);
   fChain->SetBranchAddress("BToKEE_fit_l2_eta", BToKEE_fit_l2_eta, &b_BToKEE_fit_l2_eta);
   fChain->SetBranchAddress("BToKEE_fit_l2_phi", BToKEE_fit_l2_phi, &b_BToKEE_fit_l2_phi);
   fChain->SetBranchAddress("BToKEE_fit_l2_pt", BToKEE_fit_l2_pt, &b_BToKEE_fit_l2_pt);
   fChain->SetBranchAddress("BToKEE_fit_mass", BToKEE_fit_mass, &b_BToKEE_fit_mass);
   fChain->SetBranchAddress("BToKEE_fit_massErr", BToKEE_fit_massErr, &b_BToKEE_fit_massErr);
   fChain->SetBranchAddress("BToKEE_fit_phi", BToKEE_fit_phi, &b_BToKEE_fit_phi);
   fChain->SetBranchAddress("BToKEE_fit_pt", BToKEE_fit_pt, &b_BToKEE_fit_pt);
   fChain->SetBranchAddress("BToKEE_l_xy", BToKEE_l_xy, &b_BToKEE_l_xy);
   fChain->SetBranchAddress("BToKEE_l_xy_unc", BToKEE_l_xy_unc, &b_BToKEE_l_xy_unc);
   fChain->SetBranchAddress("BToKEE_mass", BToKEE_mass, &b_BToKEE_mass);
   fChain->SetBranchAddress("BToKEE_maxDR", BToKEE_maxDR, &b_BToKEE_maxDR);
   fChain->SetBranchAddress("BToKEE_minDR", BToKEE_minDR, &b_BToKEE_minDR);
   fChain->SetBranchAddress("BToKEE_mllErr_llfit", BToKEE_mllErr_llfit, &b_BToKEE_mllErr_llfit);
   fChain->SetBranchAddress("BToKEE_mll_fullfit", BToKEE_mll_fullfit, &b_BToKEE_mll_fullfit);
   fChain->SetBranchAddress("BToKEE_mll_llfit", BToKEE_mll_llfit, &b_BToKEE_mll_llfit);
   fChain->SetBranchAddress("BToKEE_mll_raw", BToKEE_mll_raw, &b_BToKEE_mll_raw);
   fChain->SetBranchAddress("BToKEE_phi", BToKEE_phi, &b_BToKEE_phi);
   fChain->SetBranchAddress("BToKEE_pt", BToKEE_pt, &b_BToKEE_pt);
   fChain->SetBranchAddress("BToKEE_svprob", BToKEE_svprob, &b_BToKEE_svprob);
   fChain->SetBranchAddress("BToKEE_vtx_ex", BToKEE_vtx_ex, &b_BToKEE_vtx_ex);
   fChain->SetBranchAddress("BToKEE_vtx_ey", BToKEE_vtx_ey, &b_BToKEE_vtx_ey);
   fChain->SetBranchAddress("BToKEE_vtx_ez", BToKEE_vtx_ez, &b_BToKEE_vtx_ez);
   fChain->SetBranchAddress("BToKEE_vtx_x", BToKEE_vtx_x, &b_BToKEE_vtx_x);
   fChain->SetBranchAddress("BToKEE_vtx_y", BToKEE_vtx_y, &b_BToKEE_vtx_y);
   fChain->SetBranchAddress("BToKEE_vtx_z", BToKEE_vtx_z, &b_BToKEE_vtx_z);
   fChain->SetBranchAddress("BToKEE_charge", BToKEE_charge, &b_BToKEE_charge);
   fChain->SetBranchAddress("BToKEE_l1_pt", BToKEE_l1_pt, &b_BToKEE_l1_pt);
   fChain->SetBranchAddress("BToKEE_l2_pt", BToKEE_l2_pt, &b_BToKEE_l2_pt);
   fChain->SetBranchAddress("BToKEE_l1_eta", BToKEE_l1_eta, &b_BToKEE_l1_eta);
   fChain->SetBranchAddress("BToKEE_l2_eta", BToKEE_l2_eta, &b_BToKEE_l2_eta);
   fChain->SetBranchAddress("BToKEE_l1_phi", BToKEE_l1_phi, &b_BToKEE_l1_phi);
   fChain->SetBranchAddress("BToKEE_l2_phi", BToKEE_l2_phi, &b_BToKEE_l2_phi);
   fChain->SetBranchAddress("BToKEE_l1_isPF", BToKEE_l1_isPF, &b_BToKEE_l1_isPF);
   fChain->SetBranchAddress("BToKEE_l2_isPF", BToKEE_l2_isPF, &b_BToKEE_l2_isPF);
   fChain->SetBranchAddress("BToKEE_l1_pfmvaId", BToKEE_l1_pfmvaId, &b_BToKEE_l1_pfmvaId);
   fChain->SetBranchAddress("BToKEE_l2_pfmvaId", BToKEE_l2_pfmvaId, &b_BToKEE_l2_pfmvaId);
   fChain->SetBranchAddress("BToKEE_l1_isLowPt", BToKEE_l1_isLowPt, &b_BToKEE_l1_isLowPt);
   fChain->SetBranchAddress("BToKEE_l2_isLowPt", BToKEE_l2_isLowPt, &b_BToKEE_l2_isLowPt);
   fChain->SetBranchAddress("BToKEE_l1_mvaId", BToKEE_l1_mvaId, &b_BToKEE_l1_mvaId);
   fChain->SetBranchAddress("BToKEE_l2_mvaId", BToKEE_l2_mvaId, &b_BToKEE_l2_mvaId);
   fChain->SetBranchAddress("BToKEE_l1_isPFoverlap", BToKEE_l1_isPFoverlap, &b_BToKEE_l1_isPFoverlap);
   fChain->SetBranchAddress("BToKEE_l2_isPfoverlap", BToKEE_l2_isPfoverlap, &b_BToKEE_l2_isPfoverlap);
   fChain->SetBranchAddress("BToKEE_k_pt", BToKEE_k_pt, &b_BToKEE_k_pt);
   fChain->SetBranchAddress("BToKEE_k_eta", BToKEE_k_eta, &b_BToKEE_k_eta);
   fChain->SetBranchAddress("BToKEE_k_phi", BToKEE_k_phi, &b_BToKEE_k_phi);
   fChain->SetBranchAddress("BToKEE_pdgId", BToKEE_pdgId, &b_BToKEE_pdgId);
   fChain->SetBranchAddress("BToKEE_isMC", BToKEE_isMC, &b_BToKEE_isMC);
}

