
#include "../interface/BElectronsClassMC.h"
/*BElectronsClass::BElectronsClass(TTree *tree) : fChain(0) 
  {
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
if (tree == 0) {
TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("../PhysicsTools/BParkingNano/test/BParkNANO_mc_2020Jan16.root");
if (!f || !f->IsOpen()) {
f = new TFile("../PhysicsTools/BParkingNano/test/BParkNANO_mc_2020Jan16.root");
}
f->GetObject("Events",tree);

}
Init(tree);
}

BElectronsClass::~BElectronsClass()
{
if (!fChain) return;
delete fChain->GetCurrentFile();
}

Int_t BElectronsClass::GetEntry(Long64_t entry)
{
// Read contents of entry.
if (!fChain) return 0;
return fChain->GetEntry(entry);
}
Long64_t BElectronsClass::LoadTree(Long64_t entry)
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
void BElectronsClassMC::Init(TTree *tree)
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
	fChain->SetBranchAddress("BToKEE_b_iso03", BToKEE_b_iso03, &b_BToKEE_b_iso03);
	fChain->SetBranchAddress("BToKEE_b_iso04", BToKEE_b_iso04, &b_BToKEE_b_iso04);
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
	fChain->SetBranchAddress("BToKEE_k_iso03", BToKEE_k_iso03, &b_BToKEE_k_iso03);
	fChain->SetBranchAddress("BToKEE_k_iso04", BToKEE_k_iso04, &b_BToKEE_k_iso04);
	fChain->SetBranchAddress("BToKEE_l1_iso03", BToKEE_l1_iso03, &b_BToKEE_l1_iso03);
	fChain->SetBranchAddress("BToKEE_l1_iso04", BToKEE_l1_iso04, &b_BToKEE_l1_iso04);
	fChain->SetBranchAddress("BToKEE_l2_iso03", BToKEE_l2_iso03, &b_BToKEE_l2_iso03);
	fChain->SetBranchAddress("BToKEE_l2_iso04", BToKEE_l2_iso04, &b_BToKEE_l2_iso04);
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
	fChain->SetBranchAddress("BToKEE_n_k_used", BToKEE_n_k_used, &b_BToKEE_n_k_used);
	fChain->SetBranchAddress("BToKEE_n_l1_used", BToKEE_n_l1_used, &b_BToKEE_n_l1_used);
	fChain->SetBranchAddress("BToKEE_n_l2_used", BToKEE_n_l2_used, &b_BToKEE_n_l2_used);
	fChain->SetBranchAddress("BToKEE_pdgId", BToKEE_pdgId, &b_BToKEE_pdgId);
	fChain->SetBranchAddress("nBToKMuMu", &nBToKMuMu, &b_nBToKMuMu);
	fChain->SetBranchAddress("BToKMuMu_b_iso03", BToKMuMu_b_iso03, &b_BToKMuMu_b_iso03);
	fChain->SetBranchAddress("BToKMuMu_b_iso04", BToKMuMu_b_iso04, &b_BToKMuMu_b_iso04);
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
	fChain->SetBranchAddress("BToKMuMu_k_iso03", BToKMuMu_k_iso03, &b_BToKMuMu_k_iso03);
	fChain->SetBranchAddress("BToKMuMu_k_iso04", BToKMuMu_k_iso04, &b_BToKMuMu_k_iso04);
	fChain->SetBranchAddress("BToKMuMu_l1_iso03", BToKMuMu_l1_iso03, &b_BToKMuMu_l1_iso03);
	fChain->SetBranchAddress("BToKMuMu_l1_iso04", BToKMuMu_l1_iso04, &b_BToKMuMu_l1_iso04);
	fChain->SetBranchAddress("BToKMuMu_l2_iso03", BToKMuMu_l2_iso03, &b_BToKMuMu_l2_iso03);
	fChain->SetBranchAddress("BToKMuMu_l2_iso04", BToKMuMu_l2_iso04, &b_BToKMuMu_l2_iso04);
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
	fChain->SetBranchAddress("BToKMuMu_n_k_used", BToKMuMu_n_k_used, &b_BToKMuMu_n_k_used);
	fChain->SetBranchAddress("BToKMuMu_n_l1_used", BToKMuMu_n_l1_used, &b_BToKMuMu_n_l1_used);
	fChain->SetBranchAddress("BToKMuMu_n_l2_used", BToKMuMu_n_l2_used, &b_BToKMuMu_n_l2_used);
	fChain->SetBranchAddress("BToKMuMu_pdgId", BToKMuMu_pdgId, &b_BToKMuMu_pdgId);
	fChain->SetBranchAddress("nElectron", &nElectron, &b_nElectron);
	fChain->SetBranchAddress("Electron_dxy", Electron_dxy, &b_Electron_dxy);
	fChain->SetBranchAddress("Electron_dxyErr", Electron_dxyErr, &b_Electron_dxyErr);
	fChain->SetBranchAddress("Electron_dz", Electron_dz, &b_Electron_dz);
	fChain->SetBranchAddress("Electron_dzErr", Electron_dzErr, &b_Electron_dzErr);
	fChain->SetBranchAddress("Electron_eta", Electron_eta, &b_Electron_eta);
	fChain->SetBranchAddress("Electron_fBrem", Electron_fBrem, &b_Electron_fBrem);
	fChain->SetBranchAddress("Electron_ip3d", Electron_ip3d, &b_Electron_ip3d);
	fChain->SetBranchAddress("Electron_mass", Electron_mass, &b_Electron_mass);
	fChain->SetBranchAddress("Electron_mvaId", Electron_mvaId, &b_Electron_mvaId);
	fChain->SetBranchAddress("Electron_pfRelIso", Electron_pfRelIso, &b_Electron_pfRelIso);
	fChain->SetBranchAddress("Electron_pfmvaId", Electron_pfmvaId, &b_Electron_pfmvaId);
	fChain->SetBranchAddress("Electron_phi", Electron_phi, &b_Electron_phi);
	fChain->SetBranchAddress("Electron_pt", Electron_pt, &b_Electron_pt);
	fChain->SetBranchAddress("Electron_ptBiased", Electron_ptBiased, &b_Electron_ptBiased);
	fChain->SetBranchAddress("Electron_sip3d", Electron_sip3d, &b_Electron_sip3d);
	fChain->SetBranchAddress("Electron_trkRelIso", Electron_trkRelIso, &b_Electron_trkRelIso);
	fChain->SetBranchAddress("Electron_unBiased", Electron_unBiased, &b_Electron_unBiased);
	fChain->SetBranchAddress("Electron_vx", Electron_vx, &b_Electron_vx);
	fChain->SetBranchAddress("Electron_vy", Electron_vy, &b_Electron_vy);
	fChain->SetBranchAddress("Electron_vz", Electron_vz, &b_Electron_vz);
	fChain->SetBranchAddress("Electron_charge", Electron_charge, &b_Electron_charge);
	fChain->SetBranchAddress("Electron_pdgId", Electron_pdgId, &b_Electron_pdgId);
	fChain->SetBranchAddress("Electron_convVeto", Electron_convVeto, &b_Electron_convVeto);
	fChain->SetBranchAddress("Electron_isLowPt", Electron_isLowPt, &b_Electron_isLowPt);
	fChain->SetBranchAddress("Electron_isPF", Electron_isPF, &b_Electron_isPF);
	fChain->SetBranchAddress("Electron_isPFoverlap", Electron_isPFoverlap, &b_Electron_isPFoverlap);
	fChain->SetBranchAddress("nGenPart", &nGenPart, &b_nGenPart);
	fChain->SetBranchAddress("GenPart_eta", GenPart_eta, &b_GenPart_eta);
	fChain->SetBranchAddress("GenPart_mass", GenPart_mass, &b_GenPart_mass);
	fChain->SetBranchAddress("GenPart_phi", GenPart_phi, &b_GenPart_phi);
	fChain->SetBranchAddress("GenPart_pt", GenPart_pt, &b_GenPart_pt);
	fChain->SetBranchAddress("GenPart_vx", GenPart_vx, &b_GenPart_vx);
	fChain->SetBranchAddress("GenPart_vy", GenPart_vy, &b_GenPart_vy);
	fChain->SetBranchAddress("GenPart_vz", GenPart_vz, &b_GenPart_vz);
	fChain->SetBranchAddress("GenPart_genPartIdxMother", GenPart_genPartIdxMother, &b_GenPart_genPartIdxMother);
	fChain->SetBranchAddress("GenPart_pdgId", GenPart_pdgId, &b_GenPart_pdgId);
	fChain->SetBranchAddress("GenPart_status", GenPart_status, &b_GenPart_status);
	fChain->SetBranchAddress("GenPart_statusFlags", GenPart_statusFlags, &b_GenPart_statusFlags);
	fChain->SetBranchAddress("Generator_binvar", &Generator_binvar, &b_Generator_binvar);
	fChain->SetBranchAddress("Generator_scalePDF", &Generator_scalePDF, &b_Generator_scalePDF);
	fChain->SetBranchAddress("Generator_weight", &Generator_weight, &b_Generator_weight);
	fChain->SetBranchAddress("Generator_x1", &Generator_x1, &b_Generator_x1);
	fChain->SetBranchAddress("Generator_x2", &Generator_x2, &b_Generator_x2);
	fChain->SetBranchAddress("Generator_xpdf1", &Generator_xpdf1, &b_Generator_xpdf1);
	fChain->SetBranchAddress("Generator_xpdf2", &Generator_xpdf2, &b_Generator_xpdf2);
	fChain->SetBranchAddress("Generator_id1", &Generator_id1, &b_Generator_id1);
	fChain->SetBranchAddress("Generator_id2", &Generator_id2, &b_Generator_id2);
	fChain->SetBranchAddress("genWeight", &genWeight, &b_genWeight);
	fChain->SetBranchAddress("nPSWeight", &nPSWeight, &b_nPSWeight);
	fChain->SetBranchAddress("PSWeight", PSWeight, &b_PSWeight);
	fChain->SetBranchAddress("nMuon", &nMuon, &b_nMuon);
	fChain->SetBranchAddress("Muon_dxy", Muon_dxy, &b_Muon_dxy);
	fChain->SetBranchAddress("Muon_dxyErr", Muon_dxyErr, &b_Muon_dxyErr);
	fChain->SetBranchAddress("Muon_dz", Muon_dz, &b_Muon_dz);
	fChain->SetBranchAddress("Muon_dzErr", Muon_dzErr, &b_Muon_dzErr);
	fChain->SetBranchAddress("Muon_eta", Muon_eta, &b_Muon_eta);
	fChain->SetBranchAddress("Muon_ip3d", Muon_ip3d, &b_Muon_ip3d);
	fChain->SetBranchAddress("Muon_mass", Muon_mass, &b_Muon_mass);
	fChain->SetBranchAddress("Muon_pfRelIso03_all", Muon_pfRelIso03_all, &b_Muon_pfRelIso03_all);
	fChain->SetBranchAddress("Muon_pfRelIso04_all", Muon_pfRelIso04_all, &b_Muon_pfRelIso04_all);
	fChain->SetBranchAddress("Muon_phi", Muon_phi, &b_Muon_phi);
	fChain->SetBranchAddress("Muon_pt", Muon_pt, &b_Muon_pt);
	fChain->SetBranchAddress("Muon_ptErr", Muon_ptErr, &b_Muon_ptErr);
	fChain->SetBranchAddress("Muon_sip3d", Muon_sip3d, &b_Muon_sip3d);
	fChain->SetBranchAddress("Muon_vx", Muon_vx, &b_Muon_vx);
	fChain->SetBranchAddress("Muon_vy", Muon_vy, &b_Muon_vy);
	fChain->SetBranchAddress("Muon_vz", Muon_vz, &b_Muon_vz);
	fChain->SetBranchAddress("Muon_charge", Muon_charge, &b_Muon_charge);
	fChain->SetBranchAddress("Muon_isTriggering", Muon_isTriggering, &b_Muon_isTriggering);
	fChain->SetBranchAddress("Muon_pdgId", Muon_pdgId, &b_Muon_pdgId);
	fChain->SetBranchAddress("Muon_isGlobal", Muon_isGlobal, &b_Muon_isGlobal);
	fChain->SetBranchAddress("Muon_isPFcand", Muon_isPFcand, &b_Muon_isPFcand);
	fChain->SetBranchAddress("Muon_isTracker", Muon_isTracker, &b_Muon_isTracker);
	fChain->SetBranchAddress("Muon_mediumId", Muon_mediumId, &b_Muon_mediumId);
	fChain->SetBranchAddress("Muon_pfIsoId", Muon_pfIsoId, &b_Muon_pfIsoId);
	fChain->SetBranchAddress("Muon_softId", Muon_softId, &b_Muon_softId);
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
	fChain->SetBranchAddress("Pileup_nTrueInt", &Pileup_nTrueInt, &b_Pileup_nTrueInt);
	fChain->SetBranchAddress("Pileup_pudensity", &Pileup_pudensity, &b_Pileup_pudensity);
	fChain->SetBranchAddress("Pileup_gpudensity", &Pileup_gpudensity, &b_Pileup_gpudensity);
	fChain->SetBranchAddress("Pileup_nPU", &Pileup_nPU, &b_Pileup_nPU);
	fChain->SetBranchAddress("Pileup_sumEOOT", &Pileup_sumEOOT, &b_Pileup_sumEOOT);
	fChain->SetBranchAddress("Pileup_sumLOOT", &Pileup_sumLOOT, &b_Pileup_sumLOOT);
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
	fChain->SetBranchAddress("ProbeTracks_nValidHits", ProbeTracks_nValidHits, &b_ProbeTracks_nValidHits);
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
	fChain->SetBranchAddress("Electron_genPartIdx", Electron_genPartIdx, &b_Electron_genPartIdx);
	fChain->SetBranchAddress("Electron_genPartFlav", Electron_genPartFlav, &b_Electron_genPartFlav);
	fChain->SetBranchAddress("Muon_genPartIdx", Muon_genPartIdx, &b_Muon_genPartIdx);
	fChain->SetBranchAddress("Muon_genPartFlav", Muon_genPartFlav, &b_Muon_genPartFlav);
	fChain->SetBranchAddress("SV_chi2", SV_chi2, &b_SV_chi2);
	fChain->SetBranchAddress("SV_eta", SV_eta, &b_SV_eta);
	fChain->SetBranchAddress("SV_mass", SV_mass, &b_SV_mass);
	fChain->SetBranchAddress("SV_ndof", SV_ndof, &b_SV_ndof);
	fChain->SetBranchAddress("SV_phi", SV_phi, &b_SV_phi);
	fChain->SetBranchAddress("SV_pt", SV_pt, &b_SV_pt);
	fChain->SetBranchAddress("SV_x", SV_x, &b_SV_x);
	fChain->SetBranchAddress("SV_y", SV_y, &b_SV_y);
	fChain->SetBranchAddress("SV_z", SV_z, &b_SV_z);
	fChain->SetBranchAddress("ProbeTracks_genPartIdx", ProbeTracks_genPartIdx, &b_ProbeTracks_genPartIdx);
	fChain->SetBranchAddress("ProbeTracks_genPartFlav", ProbeTracks_genPartFlav, &b_ProbeTracks_genPartFlav);
//	Notify();
}

/*Bool_t BElectronsClass::Notify()
  {
// The Notify() function is called when a new file is opened. This
// can be either for a new TTree in a TChain or when when a new TTree
// is started when using PROOF. It is normally not necessary to make changes
// to the generated code, but the routine can be extended by the
// user if needed. The return value is currently not used.

return kTRUE;
}

void BElectronsClass::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
if (!fChain) return;
fChain->Show(entry);
}
Int_t BElectronsClass::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
return 1;
}
#endif // #ifdef BElectronsClass_cxx*/
