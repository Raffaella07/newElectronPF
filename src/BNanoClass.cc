#include "../interface/BNanoClass.h"



/*BNanoClass::BNanoClass(TTree *tree) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("BParkNANO_data_10215.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("BParkNANO_data_10215.root");
      }
      f->GetObject("Events",tree);

   }
   Init(tree);
}

BNanoClass::~BNanoClass()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t BNanoClass::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t BNanoClass::LoadTree(Long64_t entry)
{
// Set the environment to read one entry
   if (!fChain) return -5;
   Long64_t centry = fChain->LoadTree(entry);
   if (centry < 0) return centry;
   if (fChain->GetTreeNumber() != fCurrent) {
      fCurrent = fChain->GetTreeNumber();
      Notify();
   }
   return centry;
}
*/
void BNanoClass::Init(TTree *tree)
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

   fChain->SetBranchAddress("run", &run, &b_run);
   fChain->SetBranchAddress("luminosityBlock", &luminosityBlock, &b_luminosityBlock);
   fChain->SetBranchAddress("event", &event, &b_event);
   fChain->SetBranchAddress("nBToKEE", &nBToKEE, &b_nBToKEE);
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
   fChain->SetBranchAddress("BToKEE_kIdx", BToKEE_kIdx, &b_BToKEE_kIdx);
   fChain->SetBranchAddress("BToKEE_l1Idx", BToKEE_l1Idx, &b_BToKEE_l1Idx);
   fChain->SetBranchAddress("BToKEE_l2Idx", BToKEE_l2Idx, &b_BToKEE_l2Idx);
   fChain->SetBranchAddress("BToKEE_pdgId", BToKEE_pdgId, &b_BToKEE_pdgId);
   fChain->SetBranchAddress("nBToKMuMu", &nBToKMuMu, &b_nBToKMuMu);
   fChain->SetBranchAddress("BToKMuMu_chi2", BToKMuMu_chi2, &b_BToKMuMu_chi2);
   fChain->SetBranchAddress("BToKMuMu_cos2D", BToKMuMu_cos2D, &b_BToKMuMu_cos2D);
   fChain->SetBranchAddress("BToKMuMu_eta", BToKMuMu_eta, &b_BToKMuMu_eta);
   fChain->SetBranchAddress("BToKMuMu_fit_cos2D", BToKMuMu_fit_cos2D, &b_BToKMuMu_fit_cos2D);
   fChain->SetBranchAddress("BToKMuMu_fit_eta", BToKMuMu_fit_eta, &b_BToKMuMu_fit_eta);
   fChain->SetBranchAddress("BToKMuMu_fit_k_eta", BToKMuMu_fit_k_eta, &b_BToKMuMu_fit_k_eta);
   fChain->SetBranchAddress("BToKMuMu_fit_k_phi", BToKMuMu_fit_k_phi, &b_BToKMuMu_fit_k_phi);
   fChain->SetBranchAddress("BToKMuMu_fit_k_pt", BToKMuMu_fit_k_pt, &b_BToKMuMu_fit_k_pt);
   fChain->SetBranchAddress("BToKMuMu_fit_l1_eta", BToKMuMu_fit_l1_eta, &b_BToKMuMu_fit_l1_eta);
   fChain->SetBranchAddress("BToKMuMu_fit_l1_phi", BToKMuMu_fit_l1_phi, &b_BToKMuMu_fit_l1_phi);
   fChain->SetBranchAddress("BToKMuMu_fit_l1_pt", BToKMuMu_fit_l1_pt, &b_BToKMuMu_fit_l1_pt);
   fChain->SetBranchAddress("BToKMuMu_fit_l2_eta", BToKMuMu_fit_l2_eta, &b_BToKMuMu_fit_l2_eta);
   fChain->SetBranchAddress("BToKMuMu_fit_l2_phi", BToKMuMu_fit_l2_phi, &b_BToKMuMu_fit_l2_phi);
   fChain->SetBranchAddress("BToKMuMu_fit_l2_pt", BToKMuMu_fit_l2_pt, &b_BToKMuMu_fit_l2_pt);
   fChain->SetBranchAddress("BToKMuMu_fit_mass", BToKMuMu_fit_mass, &b_BToKMuMu_fit_mass);
   fChain->SetBranchAddress("BToKMuMu_fit_massErr", BToKMuMu_fit_massErr, &b_BToKMuMu_fit_massErr);
   fChain->SetBranchAddress("BToKMuMu_fit_phi", BToKMuMu_fit_phi, &b_BToKMuMu_fit_phi);
   fChain->SetBranchAddress("BToKMuMu_fit_pt", BToKMuMu_fit_pt, &b_BToKMuMu_fit_pt);
   fChain->SetBranchAddress("BToKMuMu_l_xy", BToKMuMu_l_xy, &b_BToKMuMu_l_xy);
   fChain->SetBranchAddress("BToKMuMu_l_xy_unc", BToKMuMu_l_xy_unc, &b_BToKMuMu_l_xy_unc);
   fChain->SetBranchAddress("BToKMuMu_mass", BToKMuMu_mass, &b_BToKMuMu_mass);
   fChain->SetBranchAddress("BToKMuMu_maxDR", BToKMuMu_maxDR, &b_BToKMuMu_maxDR);
   fChain->SetBranchAddress("BToKMuMu_minDR", BToKMuMu_minDR, &b_BToKMuMu_minDR);
   fChain->SetBranchAddress("BToKMuMu_mllErr_llfit", BToKMuMu_mllErr_llfit, &b_BToKMuMu_mllErr_llfit);
   fChain->SetBranchAddress("BToKMuMu_mll_fullfit", BToKMuMu_mll_fullfit, &b_BToKMuMu_mll_fullfit);
   fChain->SetBranchAddress("BToKMuMu_mll_llfit", BToKMuMu_mll_llfit, &b_BToKMuMu_mll_llfit);
   fChain->SetBranchAddress("BToKMuMu_mll_raw", BToKMuMu_mll_raw, &b_BToKMuMu_mll_raw);
   fChain->SetBranchAddress("BToKMuMu_phi", BToKMuMu_phi, &b_BToKMuMu_phi);
   fChain->SetBranchAddress("BToKMuMu_pt", BToKMuMu_pt, &b_BToKMuMu_pt);
   fChain->SetBranchAddress("BToKMuMu_svprob", BToKMuMu_svprob, &b_BToKMuMu_svprob);
   fChain->SetBranchAddress("BToKMuMu_vtx_ex", BToKMuMu_vtx_ex, &b_BToKMuMu_vtx_ex);
   fChain->SetBranchAddress("BToKMuMu_vtx_ey", BToKMuMu_vtx_ey, &b_BToKMuMu_vtx_ey);
   fChain->SetBranchAddress("BToKMuMu_vtx_ez", BToKMuMu_vtx_ez, &b_BToKMuMu_vtx_ez);
   fChain->SetBranchAddress("BToKMuMu_vtx_x", BToKMuMu_vtx_x, &b_BToKMuMu_vtx_x);
   fChain->SetBranchAddress("BToKMuMu_vtx_y", BToKMuMu_vtx_y, &b_BToKMuMu_vtx_y);
   fChain->SetBranchAddress("BToKMuMu_vtx_z", BToKMuMu_vtx_z, &b_BToKMuMu_vtx_z);
   fChain->SetBranchAddress("BToKMuMu_charge", BToKMuMu_charge, &b_BToKMuMu_charge);
   fChain->SetBranchAddress("BToKMuMu_kIdx", BToKMuMu_kIdx, &b_BToKMuMu_kIdx);
   fChain->SetBranchAddress("BToKMuMu_l1Idx", BToKMuMu_l1Idx, &b_BToKMuMu_l1Idx);
   fChain->SetBranchAddress("BToKMuMu_l2Idx", BToKMuMu_l2Idx, &b_BToKMuMu_l2Idx);
   fChain->SetBranchAddress("BToKMuMu_pdgId", BToKMuMu_pdgId, &b_BToKMuMu_pdgId);
   fChain->SetBranchAddress("nBToKsEE", &nBToKsEE, &b_nBToKsEE);
   fChain->SetBranchAddress("BToKsEE_barMass", BToKsEE_barMass, &b_BToKsEE_barMass);
   fChain->SetBranchAddress("BToKsEE_barMkstar_fullfit", BToKsEE_barMkstar_fullfit, &b_BToKsEE_barMkstar_fullfit);
   fChain->SetBranchAddress("BToKsEE_chi2", BToKsEE_chi2, &b_BToKsEE_chi2);
   fChain->SetBranchAddress("BToKsEE_cos2D", BToKsEE_cos2D, &b_BToKsEE_cos2D);
   fChain->SetBranchAddress("BToKsEE_eta", BToKsEE_eta, &b_BToKsEE_eta);
   fChain->SetBranchAddress("BToKsEE_etakstar_fullfit", BToKsEE_etakstar_fullfit, &b_BToKsEE_etakstar_fullfit);
   fChain->SetBranchAddress("BToKsEE_fit_cos2D", BToKsEE_fit_cos2D, &b_BToKsEE_fit_cos2D);
   fChain->SetBranchAddress("BToKsEE_fit_eta", BToKsEE_fit_eta, &b_BToKsEE_fit_eta);
   fChain->SetBranchAddress("BToKsEE_fit_mass", BToKsEE_fit_mass, &b_BToKsEE_fit_mass);
   fChain->SetBranchAddress("BToKsEE_fit_massErr", BToKsEE_fit_massErr, &b_BToKsEE_fit_massErr);
   fChain->SetBranchAddress("BToKsEE_fit_phi", BToKsEE_fit_phi, &b_BToKsEE_fit_phi);
   fChain->SetBranchAddress("BToKsEE_fit_pt", BToKsEE_fit_pt, &b_BToKsEE_fit_pt);
   fChain->SetBranchAddress("BToKsEE_fitted_barMass", BToKsEE_fitted_barMass, &b_BToKsEE_fitted_barMass);
   fChain->SetBranchAddress("BToKsEE_l_xy", BToKsEE_l_xy, &b_BToKsEE_l_xy);
   fChain->SetBranchAddress("BToKsEE_l_xy_unc", BToKsEE_l_xy_unc, &b_BToKsEE_l_xy_unc);
   fChain->SetBranchAddress("BToKsEE_lep1eta_fullfit", BToKsEE_lep1eta_fullfit, &b_BToKsEE_lep1eta_fullfit);
   fChain->SetBranchAddress("BToKsEE_lep1phi_fullfit", BToKsEE_lep1phi_fullfit, &b_BToKsEE_lep1phi_fullfit);
   fChain->SetBranchAddress("BToKsEE_lep1pt_fullfit", BToKsEE_lep1pt_fullfit, &b_BToKsEE_lep1pt_fullfit);
   fChain->SetBranchAddress("BToKsEE_lep2eta_fullfit", BToKsEE_lep2eta_fullfit, &b_BToKsEE_lep2eta_fullfit);
   fChain->SetBranchAddress("BToKsEE_lep2phi_fullfit", BToKsEE_lep2phi_fullfit, &b_BToKsEE_lep2phi_fullfit);
   fChain->SetBranchAddress("BToKsEE_lep2pt_fullfit", BToKsEE_lep2pt_fullfit, &b_BToKsEE_lep2pt_fullfit);
   fChain->SetBranchAddress("BToKsEE_mass", BToKsEE_mass, &b_BToKsEE_mass);
   fChain->SetBranchAddress("BToKsEE_max_dr", BToKsEE_max_dr, &b_BToKsEE_max_dr);
   fChain->SetBranchAddress("BToKsEE_min_dr", BToKsEE_min_dr, &b_BToKsEE_min_dr);
   fChain->SetBranchAddress("BToKsEE_mkstar_fullfit", BToKsEE_mkstar_fullfit, &b_BToKsEE_mkstar_fullfit);
   fChain->SetBranchAddress("BToKsEE_mll_fullfit", BToKsEE_mll_fullfit, &b_BToKsEE_mll_fullfit);
   fChain->SetBranchAddress("BToKsEE_mll_llfit", BToKsEE_mll_llfit, &b_BToKsEE_mll_llfit);
   fChain->SetBranchAddress("BToKsEE_mll_raw", BToKsEE_mll_raw, &b_BToKsEE_mll_raw);
   fChain->SetBranchAddress("BToKsEE_phi", BToKsEE_phi, &b_BToKsEE_phi);
   fChain->SetBranchAddress("BToKsEE_phikstar_fullfit", BToKsEE_phikstar_fullfit, &b_BToKsEE_phikstar_fullfit);
   fChain->SetBranchAddress("BToKsEE_pt", BToKsEE_pt, &b_BToKsEE_pt);
   fChain->SetBranchAddress("BToKsEE_ptkstar_fullfit", BToKsEE_ptkstar_fullfit, &b_BToKsEE_ptkstar_fullfit);
   fChain->SetBranchAddress("BToKsEE_svprob", BToKsEE_svprob, &b_BToKsEE_svprob);
   fChain->SetBranchAddress("BToKsEE_trk1eta_fullfit", BToKsEE_trk1eta_fullfit, &b_BToKsEE_trk1eta_fullfit);
   fChain->SetBranchAddress("BToKsEE_trk1phi_fullfit", BToKsEE_trk1phi_fullfit, &b_BToKsEE_trk1phi_fullfit);
   fChain->SetBranchAddress("BToKsEE_trk1pt_fullfit", BToKsEE_trk1pt_fullfit, &b_BToKsEE_trk1pt_fullfit);
   fChain->SetBranchAddress("BToKsEE_trk2eta_fullfit", BToKsEE_trk2eta_fullfit, &b_BToKsEE_trk2eta_fullfit);
   fChain->SetBranchAddress("BToKsEE_trk2phi_fullfit", BToKsEE_trk2phi_fullfit, &b_BToKsEE_trk2phi_fullfit);
   fChain->SetBranchAddress("BToKsEE_trk2pt_fullfit", BToKsEE_trk2pt_fullfit, &b_BToKsEE_trk2pt_fullfit);
   fChain->SetBranchAddress("BToKsEE_charge", BToKsEE_charge, &b_BToKsEE_charge);
   fChain->SetBranchAddress("BToKsEE_kstar_idx", BToKsEE_kstar_idx, &b_BToKsEE_kstar_idx);
   fChain->SetBranchAddress("BToKsEE_l1_idx", BToKsEE_l1_idx, &b_BToKsEE_l1_idx);
   fChain->SetBranchAddress("BToKsEE_l2_idx", BToKsEE_l2_idx, &b_BToKsEE_l2_idx);
   fChain->SetBranchAddress("BToKsEE_pdgId", BToKsEE_pdgId, &b_BToKsEE_pdgId);
   fChain->SetBranchAddress("BToKsEE_trk1_idx", BToKsEE_trk1_idx, &b_BToKsEE_trk1_idx);
   fChain->SetBranchAddress("BToKsEE_trk2_idx", BToKsEE_trk2_idx, &b_BToKsEE_trk2_idx);
   fChain->SetBranchAddress("nBToKsMuMu", &nBToKsMuMu, &b_nBToKsMuMu);
   fChain->SetBranchAddress("BToKsMuMu_barMass", BToKsMuMu_barMass, &b_BToKsMuMu_barMass);
   fChain->SetBranchAddress("BToKsMuMu_barMkstar_fullfit", BToKsMuMu_barMkstar_fullfit, &b_BToKsMuMu_barMkstar_fullfit);
   fChain->SetBranchAddress("BToKsMuMu_chi2", BToKsMuMu_chi2, &b_BToKsMuMu_chi2);
   fChain->SetBranchAddress("BToKsMuMu_cos2D", BToKsMuMu_cos2D, &b_BToKsMuMu_cos2D);
   fChain->SetBranchAddress("BToKsMuMu_eta", BToKsMuMu_eta, &b_BToKsMuMu_eta);
   fChain->SetBranchAddress("BToKsMuMu_etakstar_fullfit", BToKsMuMu_etakstar_fullfit, &b_BToKsMuMu_etakstar_fullfit);
   fChain->SetBranchAddress("BToKsMuMu_fit_cos2D", BToKsMuMu_fit_cos2D, &b_BToKsMuMu_fit_cos2D);
   fChain->SetBranchAddress("BToKsMuMu_fit_eta", BToKsMuMu_fit_eta, &b_BToKsMuMu_fit_eta);
   fChain->SetBranchAddress("BToKsMuMu_fit_mass", BToKsMuMu_fit_mass, &b_BToKsMuMu_fit_mass);
   fChain->SetBranchAddress("BToKsMuMu_fit_massErr", BToKsMuMu_fit_massErr, &b_BToKsMuMu_fit_massErr);
   fChain->SetBranchAddress("BToKsMuMu_fit_phi", BToKsMuMu_fit_phi, &b_BToKsMuMu_fit_phi);
   fChain->SetBranchAddress("BToKsMuMu_fit_pt", BToKsMuMu_fit_pt, &b_BToKsMuMu_fit_pt);
   fChain->SetBranchAddress("BToKsMuMu_fitted_barMass", BToKsMuMu_fitted_barMass, &b_BToKsMuMu_fitted_barMass);
   fChain->SetBranchAddress("BToKsMuMu_l_xy", BToKsMuMu_l_xy, &b_BToKsMuMu_l_xy);
   fChain->SetBranchAddress("BToKsMuMu_l_xy_unc", BToKsMuMu_l_xy_unc, &b_BToKsMuMu_l_xy_unc);
   fChain->SetBranchAddress("BToKsMuMu_lep1eta_fullfit", BToKsMuMu_lep1eta_fullfit, &b_BToKsMuMu_lep1eta_fullfit);
   fChain->SetBranchAddress("BToKsMuMu_lep1phi_fullfit", BToKsMuMu_lep1phi_fullfit, &b_BToKsMuMu_lep1phi_fullfit);
   fChain->SetBranchAddress("BToKsMuMu_lep1pt_fullfit", BToKsMuMu_lep1pt_fullfit, &b_BToKsMuMu_lep1pt_fullfit);
   fChain->SetBranchAddress("BToKsMuMu_lep2eta_fullfit", BToKsMuMu_lep2eta_fullfit, &b_BToKsMuMu_lep2eta_fullfit);
   fChain->SetBranchAddress("BToKsMuMu_lep2phi_fullfit", BToKsMuMu_lep2phi_fullfit, &b_BToKsMuMu_lep2phi_fullfit);
   fChain->SetBranchAddress("BToKsMuMu_lep2pt_fullfit", BToKsMuMu_lep2pt_fullfit, &b_BToKsMuMu_lep2pt_fullfit);
   fChain->SetBranchAddress("BToKsMuMu_mass", BToKsMuMu_mass, &b_BToKsMuMu_mass);
   fChain->SetBranchAddress("BToKsMuMu_max_dr", BToKsMuMu_max_dr, &b_BToKsMuMu_max_dr);
   fChain->SetBranchAddress("BToKsMuMu_min_dr", BToKsMuMu_min_dr, &b_BToKsMuMu_min_dr);
   fChain->SetBranchAddress("BToKsMuMu_mkstar_fullfit", BToKsMuMu_mkstar_fullfit, &b_BToKsMuMu_mkstar_fullfit);
   fChain->SetBranchAddress("BToKsMuMu_mll_fullfit", BToKsMuMu_mll_fullfit, &b_BToKsMuMu_mll_fullfit);
   fChain->SetBranchAddress("BToKsMuMu_mll_llfit", BToKsMuMu_mll_llfit, &b_BToKsMuMu_mll_llfit);
   fChain->SetBranchAddress("BToKsMuMu_mll_raw", BToKsMuMu_mll_raw, &b_BToKsMuMu_mll_raw);
   fChain->SetBranchAddress("BToKsMuMu_phi", BToKsMuMu_phi, &b_BToKsMuMu_phi);
   fChain->SetBranchAddress("BToKsMuMu_phikstar_fullfit", BToKsMuMu_phikstar_fullfit, &b_BToKsMuMu_phikstar_fullfit);
   fChain->SetBranchAddress("BToKsMuMu_pt", BToKsMuMu_pt, &b_BToKsMuMu_pt);
   fChain->SetBranchAddress("BToKsMuMu_ptkstar_fullfit", BToKsMuMu_ptkstar_fullfit, &b_BToKsMuMu_ptkstar_fullfit);
   fChain->SetBranchAddress("BToKsMuMu_svprob", BToKsMuMu_svprob, &b_BToKsMuMu_svprob);
   fChain->SetBranchAddress("BToKsMuMu_trk1eta_fullfit", BToKsMuMu_trk1eta_fullfit, &b_BToKsMuMu_trk1eta_fullfit);
   fChain->SetBranchAddress("BToKsMuMu_trk1phi_fullfit", BToKsMuMu_trk1phi_fullfit, &b_BToKsMuMu_trk1phi_fullfit);
   fChain->SetBranchAddress("BToKsMuMu_trk1pt_fullfit", BToKsMuMu_trk1pt_fullfit, &b_BToKsMuMu_trk1pt_fullfit);
   fChain->SetBranchAddress("BToKsMuMu_trk2eta_fullfit", BToKsMuMu_trk2eta_fullfit, &b_BToKsMuMu_trk2eta_fullfit);
   fChain->SetBranchAddress("BToKsMuMu_trk2phi_fullfit", BToKsMuMu_trk2phi_fullfit, &b_BToKsMuMu_trk2phi_fullfit);
   fChain->SetBranchAddress("BToKsMuMu_trk2pt_fullfit", BToKsMuMu_trk2pt_fullfit, &b_BToKsMuMu_trk2pt_fullfit);
   fChain->SetBranchAddress("BToKsMuMu_charge", BToKsMuMu_charge, &b_BToKsMuMu_charge);
   fChain->SetBranchAddress("BToKsMuMu_kstar_idx", BToKsMuMu_kstar_idx, &b_BToKsMuMu_kstar_idx);
   fChain->SetBranchAddress("BToKsMuMu_l1_idx", BToKsMuMu_l1_idx, &b_BToKsMuMu_l1_idx);
   fChain->SetBranchAddress("BToKsMuMu_l2_idx", BToKsMuMu_l2_idx, &b_BToKsMuMu_l2_idx);
   fChain->SetBranchAddress("BToKsMuMu_pdgId", BToKsMuMu_pdgId, &b_BToKsMuMu_pdgId);
   fChain->SetBranchAddress("BToKsMuMu_trk1_idx", BToKsMuMu_trk1_idx, &b_BToKsMuMu_trk1_idx);
   fChain->SetBranchAddress("BToKsMuMu_trk2_idx", BToKsMuMu_trk2_idx, &b_BToKsMuMu_trk2_idx);
   fChain->SetBranchAddress("nKstar", &nKstar, &b_nKstar);
   fChain->SetBranchAddress("Kstar_barMass", Kstar_barMass, &b_Kstar_barMass);
   fChain->SetBranchAddress("Kstar_eta", Kstar_eta, &b_Kstar_eta);
   fChain->SetBranchAddress("Kstar_fitted_barMass", Kstar_fitted_barMass, &b_Kstar_fitted_barMass);
   fChain->SetBranchAddress("Kstar_fitted_eta", Kstar_fitted_eta, &b_Kstar_fitted_eta);
   fChain->SetBranchAddress("Kstar_fitted_mass", Kstar_fitted_mass, &b_Kstar_fitted_mass);
   fChain->SetBranchAddress("Kstar_fitted_phi", Kstar_fitted_phi, &b_Kstar_fitted_phi);
   fChain->SetBranchAddress("Kstar_fitted_pt", Kstar_fitted_pt, &b_Kstar_fitted_pt);
   fChain->SetBranchAddress("Kstar_mass", Kstar_mass, &b_Kstar_mass);
   fChain->SetBranchAddress("Kstar_phi", Kstar_phi, &b_Kstar_phi);
   fChain->SetBranchAddress("Kstar_pt", Kstar_pt, &b_Kstar_pt);
   fChain->SetBranchAddress("Kstar_svprob", Kstar_svprob, &b_Kstar_svprob);
   fChain->SetBranchAddress("Kstar_trk_deltaR", Kstar_trk_deltaR, &b_Kstar_trk_deltaR);
   fChain->SetBranchAddress("Kstar_charge", Kstar_charge, &b_Kstar_charge);
   fChain->SetBranchAddress("Kstar_pdgId", Kstar_pdgId, &b_Kstar_pdgId);
   fChain->SetBranchAddress("Kstar_trk1_idx", Kstar_trk1_idx, &b_Kstar_trk1_idx);
   fChain->SetBranchAddress("Kstar_trk2_idx", Kstar_trk2_idx, &b_Kstar_trk2_idx);
   fChain->SetBranchAddress("nElectron", &nElectron, &b_nElectron);
   fChain->SetBranchAddress("Electron_deltaEtaSC", Electron_deltaEtaSC, &b_Electron_deltaEtaSC);
   fChain->SetBranchAddress("Electron_dxy", Electron_dxy, &b_Electron_dxy);
   fChain->SetBranchAddress("Electron_dxyErr", Electron_dxyErr, &b_Electron_dxyErr);
   fChain->SetBranchAddress("Electron_dz", Electron_dz, &b_Electron_dz);
   fChain->SetBranchAddress("Electron_dzErr", Electron_dzErr, &b_Electron_dzErr);
   fChain->SetBranchAddress("Electron_eta", Electron_eta, &b_Electron_eta);
   fChain->SetBranchAddress("Electron_fBrem", Electron_fBrem, &b_Electron_fBrem);
   fChain->SetBranchAddress("Electron_hoe", Electron_hoe, &b_Electron_hoe);
   fChain->SetBranchAddress("Electron_ip3d", Electron_ip3d, &b_Electron_ip3d);
   fChain->SetBranchAddress("Electron_mass", Electron_mass, &b_Electron_mass);
   fChain->SetBranchAddress("Electron_mvaId", Electron_mvaId, &b_Electron_mvaId);
   fChain->SetBranchAddress("Electron_phi", Electron_phi, &b_Electron_phi);
   fChain->SetBranchAddress("Electron_pt", Electron_pt, &b_Electron_pt);
   fChain->SetBranchAddress("Electron_ptBiased", Electron_ptBiased, &b_Electron_ptBiased);
   fChain->SetBranchAddress("Electron_r9", Electron_r9, &b_Electron_r9);
   fChain->SetBranchAddress("Electron_sieie", Electron_sieie, &b_Electron_sieie);
   fChain->SetBranchAddress("Electron_sip3d", Electron_sip3d, &b_Electron_sip3d);
   fChain->SetBranchAddress("Electron_unBiased", Electron_unBiased, &b_Electron_unBiased);
   fChain->SetBranchAddress("Electron_vx", Electron_vx, &b_Electron_vx);
   fChain->SetBranchAddress("Electron_vy", Electron_vy, &b_Electron_vy);
   fChain->SetBranchAddress("Electron_vz", Electron_vz, &b_Electron_vz);
   fChain->SetBranchAddress("Electron_charge", Electron_charge, &b_Electron_charge);
   fChain->SetBranchAddress("Electron_pdgId", Electron_pdgId, &b_Electron_pdgId);
   fChain->SetBranchAddress("Electron_tightCharge", Electron_tightCharge, &b_Electron_tightCharge);
   fChain->SetBranchAddress("Electron_convVeto", Electron_convVeto, &b_Electron_convVeto);
   fChain->SetBranchAddress("Electron_isLowPt", Electron_isLowPt, &b_Electron_isLowPt);
   fChain->SetBranchAddress("Electron_isPF", Electron_isPF, &b_Electron_isPF);
   fChain->SetBranchAddress("Electron_isPFoverlap", Electron_isPFoverlap, &b_Electron_isPFoverlap);
   fChain->SetBranchAddress("Electron_lostHits", Electron_lostHits, &b_Electron_lostHits);
   fChain->SetBranchAddress("nGenPart", &nGenPart, &b_nGenPart);
   fChain->SetBranchAddress("GenPart_pt", &GenPart_pt, &b_GenPart_pt);
   fChain->SetBranchAddress("GenPart_eta", &GenPart_eta, &b_GenPart_eta);
   fChain->SetBranchAddress("GenPart_phi", &GenPart_phi, &b_GenPart_phi);
   fChain->SetBranchAddress("GenPart_vx", &GenPart_vx, &b_GenPart_vx);
   fChain->SetBranchAddress("GenPart_vy", &GenPart_vy, &b_GenPart_vy);
   fChain->SetBranchAddress("GenPart_vz", &GenPart_vz, &b_GenPart_vz);
   fChain->SetBranchAddress("GenPart_pdgId", &GenPart_pdgId, &b_GenPart_pdgId);
   fChain->SetBranchAddress("GenPart_genPartIdxMother", &GenPart_genPartIdxMother, &b_GenPart_genPartIdxMother);
   fChain->SetBranchAddress("nMuon", &nMuon, &b_nMuon);
   fChain->SetBranchAddress("Muon_dxy", Muon_dxy, &b_Muon_dxy);
   fChain->SetBranchAddress("Muon_dxyErr", Muon_dxyErr, &b_Muon_dxyErr);
   fChain->SetBranchAddress("Muon_dz", Muon_dz, &b_Muon_dz);
   fChain->SetBranchAddress("Muon_dzErr", Muon_dzErr, &b_Muon_dzErr);
   fChain->SetBranchAddress("Muon_eta", Muon_eta, &b_Muon_eta);
   fChain->SetBranchAddress("Muon_ip3d", Muon_ip3d, &b_Muon_ip3d);
   fChain->SetBranchAddress("Muon_mass", Muon_mass, &b_Muon_mass);
   fChain->SetBranchAddress("Muon_pfRelIso03_all", Muon_pfRelIso03_all, &b_Muon_pfRelIso03_all);
   fChain->SetBranchAddress("Muon_pfRelIso03_chg", Muon_pfRelIso03_chg, &b_Muon_pfRelIso03_chg);
   fChain->SetBranchAddress("Muon_pfRelIso04_all", Muon_pfRelIso04_all, &b_Muon_pfRelIso04_all);
   fChain->SetBranchAddress("Muon_phi", Muon_phi, &b_Muon_phi);
   fChain->SetBranchAddress("Muon_pt", Muon_pt, &b_Muon_pt);
   fChain->SetBranchAddress("Muon_ptErr", Muon_ptErr, &b_Muon_ptErr);
   fChain->SetBranchAddress("Muon_segmentComp", Muon_segmentComp, &b_Muon_segmentComp);
   fChain->SetBranchAddress("Muon_sip3d", Muon_sip3d, &b_Muon_sip3d);
   fChain->SetBranchAddress("Muon_vx", Muon_vx, &b_Muon_vx);
   fChain->SetBranchAddress("Muon_vy", Muon_vy, &b_Muon_vy);
   fChain->SetBranchAddress("Muon_vz", Muon_vz, &b_Muon_vz);
   fChain->SetBranchAddress("Muon_charge", Muon_charge, &b_Muon_charge);
   fChain->SetBranchAddress("Muon_genPartIdx", Muon_genPartIdx, &b_Muon_genPartIdx);
   fChain->SetBranchAddress("Muon_isTriggering", Muon_isTriggering, &b_Muon_isTriggering);
   fChain->SetBranchAddress("Muon_nStations", Muon_nStations, &b_Muon_nStations);
   fChain->SetBranchAddress("Muon_pdgId", Muon_pdgId, &b_Muon_pdgId);
   fChain->SetBranchAddress("Muon_tightCharge", Muon_tightCharge, &b_Muon_tightCharge);
   fChain->SetBranchAddress("Muon_highPtId", Muon_highPtId, &b_Muon_highPtId);
   fChain->SetBranchAddress("Muon_inTimeMuon", Muon_inTimeMuon, &b_Muon_inTimeMuon);
   fChain->SetBranchAddress("Muon_isGlobal", Muon_isGlobal, &b_Muon_isGlobal);
   fChain->SetBranchAddress("Muon_isPFcand", Muon_isPFcand, &b_Muon_isPFcand);
   fChain->SetBranchAddress("Muon_isTracker", Muon_isTracker, &b_Muon_isTracker);
   fChain->SetBranchAddress("Muon_mediumId", Muon_mediumId, &b_Muon_mediumId);
   fChain->SetBranchAddress("Muon_mediumPromptId", Muon_mediumPromptId, &b_Muon_mediumPromptId);
   fChain->SetBranchAddress("Muon_miniIsoId", Muon_miniIsoId, &b_Muon_miniIsoId);
   fChain->SetBranchAddress("Muon_multiIsoId", Muon_multiIsoId, &b_Muon_multiIsoId);
   fChain->SetBranchAddress("Muon_mvaId", Muon_mvaId, &b_Muon_mvaId);
   fChain->SetBranchAddress("Muon_pfIsoId", Muon_pfIsoId, &b_Muon_pfIsoId);
   fChain->SetBranchAddress("Muon_softId", Muon_softId, &b_Muon_softId);
   fChain->SetBranchAddress("Muon_softMvaId", Muon_softMvaId, &b_Muon_softMvaId);
   fChain->SetBranchAddress("Muon_tightId", Muon_tightId, &b_Muon_tightId);
   fChain->SetBranchAddress("Muon_tkIsoId", Muon_tkIsoId, &b_Muon_tkIsoId);
   fChain->SetBranchAddress("Muon_triggerIdLoose", Muon_triggerIdLoose, &b_Muon_triggerIdLoose);
   fChain->SetBranchAddress("nTriggerMuon", &nTriggerMuon, &b_nTriggerMuon);
   fChain->SetBranchAddress("TriggerMuon_eta", TriggerMuon_eta, &b_TriggerMuon_eta);
   fChain->SetBranchAddress("TriggerMuon_mass", TriggerMuon_mass, &b_TriggerMuon_mass);
   fChain->SetBranchAddress("TriggerMuon_phi", TriggerMuon_phi, &b_TriggerMuon_phi);
   fChain->SetBranchAddress("TriggerMuon_pt", TriggerMuon_pt, &b_TriggerMuon_pt);
   fChain->SetBranchAddress("TriggerMuon_vx", TriggerMuon_vx, &b_TriggerMuon_vx);
   fChain->SetBranchAddress("TriggerMuon_vy", TriggerMuon_vy, &b_TriggerMuon_vy);
   fChain->SetBranchAddress("TriggerMuon_vz", TriggerMuon_vz, &b_TriggerMuon_vz);
   fChain->SetBranchAddress("TriggerMuon_charge", TriggerMuon_charge, &b_TriggerMuon_charge);
   fChain->SetBranchAddress("TriggerMuon_pdgId", TriggerMuon_pdgId, &b_TriggerMuon_pdgId);
   fChain->SetBranchAddress("TriggerMuon_trgMuonIndex", TriggerMuon_trgMuonIndex, &b_TriggerMuon_trgMuonIndex);
   fChain->SetBranchAddress("fixedGridRhoFastjetAll", &fixedGridRhoFastjetAll, &b_fixedGridRhoFastjetAll);
   fChain->SetBranchAddress("fixedGridRhoFastjetCentral", &fixedGridRhoFastjetCentral, &b_fixedGridRhoFastjetCentral);
   fChain->SetBranchAddress("fixedGridRhoFastjetCentralCalo", &fixedGridRhoFastjetCentralCalo, &b_fixedGridRhoFastjetCentralCalo);
   fChain->SetBranchAddress("fixedGridRhoFastjetCentralChargedPileUp", &fixedGridRhoFastjetCentralChargedPileUp, &b_fixedGridRhoFastjetCentralChargedPileUp);
   fChain->SetBranchAddress("fixedGridRhoFastjetCentralNeutral", &fixedGridRhoFastjetCentralNeutral, &b_fixedGridRhoFastjetCentralNeutral);
   fChain->SetBranchAddress("nProbeTracks", &nProbeTracks, &b_nProbeTracks);
   fChain->SetBranchAddress("ProbeTracks_DCASig", ProbeTracks_DCASig, &b_ProbeTracks_DCASig);
   fChain->SetBranchAddress("ProbeTracks_dxy", ProbeTracks_dxy, &b_ProbeTracks_dxy);
   fChain->SetBranchAddress("ProbeTracks_dxyS", ProbeTracks_dxyS, &b_ProbeTracks_dxyS);
   fChain->SetBranchAddress("ProbeTracks_dz", ProbeTracks_dz, &b_ProbeTracks_dz);
   fChain->SetBranchAddress("ProbeTracks_dzS", ProbeTracks_dzS, &b_ProbeTracks_dzS);
   fChain->SetBranchAddress("ProbeTracks_eta", ProbeTracks_eta, &b_ProbeTracks_eta);
   fChain->SetBranchAddress("ProbeTracks_mass", ProbeTracks_mass, &b_ProbeTracks_mass);
   fChain->SetBranchAddress("ProbeTracks_phi", ProbeTracks_phi, &b_ProbeTracks_phi);
   fChain->SetBranchAddress("ProbeTracks_pt", ProbeTracks_pt, &b_ProbeTracks_pt);
   fChain->SetBranchAddress("ProbeTracks_vx", ProbeTracks_vx, &b_ProbeTracks_vx);
   fChain->SetBranchAddress("ProbeTracks_vy", ProbeTracks_vy, &b_ProbeTracks_vy);
   fChain->SetBranchAddress("ProbeTracks_vz", ProbeTracks_vz, &b_ProbeTracks_vz);
   fChain->SetBranchAddress("ProbeTracks_charge", ProbeTracks_charge, &b_ProbeTracks_charge);
   fChain->SetBranchAddress("ProbeTracks_isLostTrk", ProbeTracks_isLostTrk, &b_ProbeTracks_isLostTrk);
   fChain->SetBranchAddress("ProbeTracks_isPacked", ProbeTracks_isPacked, &b_ProbeTracks_isPacked);
   fChain->SetBranchAddress("ProbeTracks_pdgId", ProbeTracks_pdgId, &b_ProbeTracks_pdgId);
   fChain->SetBranchAddress("ProbeTracks_isMatchedToEle", ProbeTracks_isMatchedToEle, &b_ProbeTracks_isMatchedToEle);
   fChain->SetBranchAddress("ProbeTracks_isMatchedToLooseMuon", ProbeTracks_isMatchedToLooseMuon, &b_ProbeTracks_isMatchedToLooseMuon);
   fChain->SetBranchAddress("ProbeTracks_isMatchedToMediumMuon", ProbeTracks_isMatchedToMediumMuon, &b_ProbeTracks_isMatchedToMediumMuon);
   fChain->SetBranchAddress("ProbeTracks_isMatchedToMuon", ProbeTracks_isMatchedToMuon, &b_ProbeTracks_isMatchedToMuon);
   fChain->SetBranchAddress("ProbeTracks_isMatchedToSoftMuon", ProbeTracks_isMatchedToSoftMuon, &b_ProbeTracks_isMatchedToSoftMuon);
   fChain->SetBranchAddress("HLT_Mu7_IP4", &HLT_Mu7_IP4, &b_HLT_Mu7_IP4);
   fChain->SetBranchAddress("HLT_Mu8_IP6", &HLT_Mu8_IP6, &b_HLT_Mu8_IP6);
   fChain->SetBranchAddress("HLT_Mu8_IP5", &HLT_Mu8_IP5, &b_HLT_Mu8_IP5);
   fChain->SetBranchAddress("HLT_Mu8_IP3", &HLT_Mu8_IP3, &b_HLT_Mu8_IP3);
   fChain->SetBranchAddress("HLT_Mu8p5_IP3p5", &HLT_Mu8p5_IP3p5, &b_HLT_Mu8p5_IP3p5);
   fChain->SetBranchAddress("HLT_Mu9_IP6", &HLT_Mu9_IP6, &b_HLT_Mu9_IP6);
   fChain->SetBranchAddress("HLT_Mu9_IP5", &HLT_Mu9_IP5, &b_HLT_Mu9_IP5);
   fChain->SetBranchAddress("HLT_Mu9_IP4", &HLT_Mu9_IP4, &b_HLT_Mu9_IP4);
   fChain->SetBranchAddress("HLT_Mu10p5_IP3p5", &HLT_Mu10p5_IP3p5, &b_HLT_Mu10p5_IP3p5);
   fChain->SetBranchAddress("HLT_Mu12_IP6", &HLT_Mu12_IP6, &b_HLT_Mu12_IP6);
   fChain->SetBranchAddress("L1_SingleMu7er1p5", &L1_SingleMu7er1p5, &b_L1_SingleMu7er1p5);
   fChain->SetBranchAddress("L1_SingleMu8er1p5", &L1_SingleMu8er1p5, &b_L1_SingleMu8er1p5);
   fChain->SetBranchAddress("L1_SingleMu9er1p5", &L1_SingleMu9er1p5, &b_L1_SingleMu9er1p5);
   fChain->SetBranchAddress("L1_SingleMu10er1p5", &L1_SingleMu10er1p5, &b_L1_SingleMu10er1p5);
   fChain->SetBranchAddress("L1_SingleMu12er1p5", &L1_SingleMu12er1p5, &b_L1_SingleMu12er1p5);
   fChain->SetBranchAddress("L1_SingleMu22", &L1_SingleMu22, &b_L1_SingleMu22);
   fChain->SetBranchAddress("nTrigObj", &nTrigObj, &b_nTrigObj);
   fChain->SetBranchAddress("TrigObj_pt", TrigObj_pt, &b_TrigObj_pt);
   fChain->SetBranchAddress("TrigObj_eta", TrigObj_eta, &b_TrigObj_eta);
   fChain->SetBranchAddress("TrigObj_phi", TrigObj_phi, &b_TrigObj_phi);
   fChain->SetBranchAddress("TrigObj_l1pt", TrigObj_l1pt, &b_TrigObj_l1pt);
   fChain->SetBranchAddress("TrigObj_l1pt_2", TrigObj_l1pt_2, &b_TrigObj_l1pt_2);
   fChain->SetBranchAddress("TrigObj_l2pt", TrigObj_l2pt, &b_TrigObj_l2pt);
   fChain->SetBranchAddress("TrigObj_id", TrigObj_id, &b_TrigObj_id);
   fChain->SetBranchAddress("TrigObj_l1iso", TrigObj_l1iso, &b_TrigObj_l1iso);
   fChain->SetBranchAddress("TrigObj_l1charge", TrigObj_l1charge, &b_TrigObj_l1charge);
   fChain->SetBranchAddress("TrigObj_filterBits", TrigObj_filterBits, &b_TrigObj_filterBits);
   fChain->SetBranchAddress("nOtherPV", &nOtherPV, &b_nOtherPV);
   fChain->SetBranchAddress("OtherPV_z", OtherPV_z, &b_OtherPV_z);
   fChain->SetBranchAddress("PV_ndof", &PV_ndof, &b_PV_ndof);
   fChain->SetBranchAddress("PV_x", &PV_x, &b_PV_x);
   fChain->SetBranchAddress("PV_y", &PV_y, &b_PV_y);
   fChain->SetBranchAddress("PV_z", &PV_z, &b_PV_z);
   fChain->SetBranchAddress("PV_chi2", &PV_chi2, &b_PV_chi2);
   fChain->SetBranchAddress("PV_score", &PV_score, &b_PV_score);
   fChain->SetBranchAddress("PV_npvs", &PV_npvs, &b_PV_npvs);
   fChain->SetBranchAddress("PV_npvsGood", &PV_npvsGood, &b_PV_npvsGood);
   fChain->SetBranchAddress("nSV", &nSV, &b_nSV);
   fChain->SetBranchAddress("SV_dlen", SV_dlen, &b_SV_dlen);
   fChain->SetBranchAddress("SV_dlenSig", SV_dlenSig, &b_SV_dlenSig);
   fChain->SetBranchAddress("SV_pAngle", SV_pAngle, &b_SV_pAngle);
   fChain->SetBranchAddress("SV_chi2", SV_chi2, &b_SV_chi2);
   fChain->SetBranchAddress("SV_eta", SV_eta, &b_SV_eta);
   fChain->SetBranchAddress("SV_mass", SV_mass, &b_SV_mass);
   fChain->SetBranchAddress("SV_ndof", SV_ndof, &b_SV_ndof);
   fChain->SetBranchAddress("SV_phi", SV_phi, &b_SV_phi);
   fChain->SetBranchAddress("SV_pt", SV_pt, &b_SV_pt);
   fChain->SetBranchAddress("SV_x", SV_x, &b_SV_x);
   fChain->SetBranchAddress("SV_y", SV_y, &b_SV_y);
   fChain->SetBranchAddress("SV_z", SV_z, &b_SV_z);
//   Notify();
}

/*Bool_t BNanoClass::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void BNanoClass::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t BNanoClass::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}*/
