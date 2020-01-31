//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Mon Nov 25 15:34:36 2019 by ROOT version 6.12/07
// from TTree Events/Events
// found on file: BParkNANO_data_10215.root
//////////////////////////////////////////////////////////

//#ifndef BNanoClass_h
#define BNanoClass_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.

class BNanoClass {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

// Fixed size dimensions of array or collections stored in the TTree if any.

   // Declaration of leaf types
   UInt_t          run;
   UInt_t          luminosityBlock;
   ULong64_t       event;
   UInt_t          nBToKEE;
   Float_t         BToKEE_chi2[413];   //[nBToKEE]
   Float_t         BToKEE_cos2D[413];   //[nBToKEE]
   Float_t         BToKEE_eta[413];   //[nBToKEE]
   Float_t         BToKEE_fit_cos2D[413];   //[nBToKEE]
   Float_t         BToKEE_fit_eta[413];   //[nBToKEE]
   Float_t         BToKEE_fit_k_eta[413];   //[nBToKEE]
   Float_t         BToKEE_fit_k_phi[413];   //[nBToKEE]
   Float_t         BToKEE_fit_k_pt[413];   //[nBToKEE]
   Float_t         BToKEE_fit_l1_eta[413];   //[nBToKEE]
   Float_t         BToKEE_fit_l1_phi[413];   //[nBToKEE]
   Float_t         BToKEE_fit_l1_pt[413];   //[nBToKEE]
   Float_t         BToKEE_fit_l2_eta[413];   //[nBToKEE]
   Float_t         BToKEE_fit_l2_phi[413];   //[nBToKEE]
   Float_t         BToKEE_fit_l2_pt[413];   //[nBToKEE]
   Float_t         BToKEE_fit_mass[413];   //[nBToKEE]
   Float_t         BToKEE_fit_massErr[413];   //[nBToKEE]
   Float_t         BToKEE_fit_phi[413];   //[nBToKEE]
   Float_t         BToKEE_fit_pt[413];   //[nBToKEE]
   Float_t         BToKEE_l_xy[413];   //[nBToKEE]
   Float_t         BToKEE_l_xy_unc[413];   //[nBToKEE]
   Float_t         BToKEE_mass[413];   //[nBToKEE]
   Float_t         BToKEE_maxDR[413];   //[nBToKEE]
   Float_t         BToKEE_minDR[413];   //[nBToKEE]
   Float_t         BToKEE_mllErr_llfit[413];   //[nBToKEE]
   Float_t         BToKEE_mll_fullfit[413];   //[nBToKEE]
   Float_t         BToKEE_mll_llfit[413];   //[nBToKEE]
   Float_t         BToKEE_mll_raw[413];   //[nBToKEE]
   Float_t         BToKEE_phi[413];   //[nBToKEE]
   Float_t         BToKEE_pt[413];   //[nBToKEE]
   Float_t         BToKEE_svprob[413];   //[nBToKEE]
   Float_t         BToKEE_vtx_ex[413];   //[nBToKEE]
   Float_t         BToKEE_vtx_ey[413];   //[nBToKEE]
   Float_t         BToKEE_vtx_ez[413];   //[nBToKEE]
   Float_t         BToKEE_vtx_x[413];   //[nBToKEE]
   Float_t         BToKEE_vtx_y[413];   //[nBToKEE]
   Float_t         BToKEE_vtx_z[413];   //[nBToKEE]
   Int_t           BToKEE_charge[413];   //[nBToKEE]
   Int_t           BToKEE_kIdx[413];   //[nBToKEE]
   Int_t           BToKEE_l1Idx[413];   //[nBToKEE]
   Int_t           BToKEE_l2Idx[413];   //[nBToKEE]
   Int_t           BToKEE_pdgId[413];   //[nBToKEE]
   UInt_t          nBToKMuMu;
   Float_t         BToKMuMu_chi2[7];   //[nBToKMuMu]
   Float_t         BToKMuMu_cos2D[7];   //[nBToKMuMu]
   Float_t         BToKMuMu_eta[7];   //[nBToKMuMu]
   Float_t         BToKMuMu_fit_cos2D[7];   //[nBToKMuMu]
   Float_t         BToKMuMu_fit_eta[7];   //[nBToKMuMu]
   Float_t         BToKMuMu_fit_k_eta[7];   //[nBToKMuMu]
   Float_t         BToKMuMu_fit_k_phi[7];   //[nBToKMuMu]
   Float_t         BToKMuMu_fit_k_pt[7];   //[nBToKMuMu]
   Float_t         BToKMuMu_fit_l1_eta[7];   //[nBToKMuMu]
   Float_t         BToKMuMu_fit_l1_phi[7];   //[nBToKMuMu]
   Float_t         BToKMuMu_fit_l1_pt[7];   //[nBToKMuMu]
   Float_t         BToKMuMu_fit_l2_eta[7];   //[nBToKMuMu]
   Float_t         BToKMuMu_fit_l2_phi[7];   //[nBToKMuMu]
   Float_t         BToKMuMu_fit_l2_pt[7];   //[nBToKMuMu]
   Float_t         BToKMuMu_fit_mass[7];   //[nBToKMuMu]
   Float_t         BToKMuMu_fit_massErr[7];   //[nBToKMuMu]
   Float_t         BToKMuMu_fit_phi[7];   //[nBToKMuMu]
   Float_t         BToKMuMu_fit_pt[7];   //[nBToKMuMu]
   Float_t         BToKMuMu_l_xy[7];   //[nBToKMuMu]
   Float_t         BToKMuMu_l_xy_unc[7];   //[nBToKMuMu]
   Float_t         BToKMuMu_mass[7];   //[nBToKMuMu]
   Float_t         BToKMuMu_maxDR[7];   //[nBToKMuMu]
   Float_t         BToKMuMu_minDR[7];   //[nBToKMuMu]
   Float_t         BToKMuMu_mllErr_llfit[7];   //[nBToKMuMu]
   Float_t         BToKMuMu_mll_fullfit[7];   //[nBToKMuMu]
   Float_t         BToKMuMu_mll_llfit[7];   //[nBToKMuMu]
   Float_t         BToKMuMu_mll_raw[7];   //[nBToKMuMu]
   Float_t         BToKMuMu_phi[7];   //[nBToKMuMu]
   Float_t         BToKMuMu_pt[7];   //[nBToKMuMu]
   Float_t         BToKMuMu_svprob[7];   //[nBToKMuMu]
   Float_t         BToKMuMu_vtx_ex[7];   //[nBToKMuMu]
   Float_t         BToKMuMu_vtx_ey[7];   //[nBToKMuMu]
   Float_t         BToKMuMu_vtx_ez[7];   //[nBToKMuMu]
   Float_t         BToKMuMu_vtx_x[7];   //[nBToKMuMu]
   Float_t         BToKMuMu_vtx_y[7];   //[nBToKMuMu]
   Float_t         BToKMuMu_vtx_z[7];   //[nBToKMuMu]
   Int_t           BToKMuMu_charge[7];   //[nBToKMuMu]
   Int_t           BToKMuMu_kIdx[7];   //[nBToKMuMu]
   Int_t           BToKMuMu_l1Idx[7];   //[nBToKMuMu]
   Int_t           BToKMuMu_l2Idx[7];   //[nBToKMuMu]
   Int_t           BToKMuMu_pdgId[7];   //[nBToKMuMu]
   UInt_t          nBToKsEE;
   Float_t         BToKsEE_barMass[171];   //[nBToKsEE]
   Float_t         BToKsEE_barMkstar_fullfit[171];   //[nBToKsEE]
   Float_t         BToKsEE_chi2[171];   //[nBToKsEE]
   Float_t         BToKsEE_cos2D[171];   //[nBToKsEE]
   Float_t         BToKsEE_eta[171];   //[nBToKsEE]
   Float_t         BToKsEE_etakstar_fullfit[171];   //[nBToKsEE]
   Float_t         BToKsEE_fit_cos2D[171];   //[nBToKsEE]
   Float_t         BToKsEE_fit_eta[171];   //[nBToKsEE]
   Float_t         BToKsEE_fit_mass[171];   //[nBToKsEE]
   Float_t         BToKsEE_fit_massErr[171];   //[nBToKsEE]
   Float_t         BToKsEE_fit_phi[171];   //[nBToKsEE]
   Float_t         BToKsEE_fit_pt[171];   //[nBToKsEE]
   Float_t         BToKsEE_fitted_barMass[171];   //[nBToKsEE]
   Float_t         BToKsEE_l_xy[171];   //[nBToKsEE]
   Float_t         BToKsEE_l_xy_unc[171];   //[nBToKsEE]
   Float_t         BToKsEE_lep1eta_fullfit[171];   //[nBToKsEE]
   Float_t         BToKsEE_lep1phi_fullfit[171];   //[nBToKsEE]
   Float_t         BToKsEE_lep1pt_fullfit[171];   //[nBToKsEE]
   Float_t         BToKsEE_lep2eta_fullfit[171];   //[nBToKsEE]
   Float_t         BToKsEE_lep2phi_fullfit[171];   //[nBToKsEE]
   Float_t         BToKsEE_lep2pt_fullfit[171];   //[nBToKsEE]
   Float_t         BToKsEE_mass[171];   //[nBToKsEE]
   Float_t         BToKsEE_max_dr[171];   //[nBToKsEE]
   Float_t         BToKsEE_min_dr[171];   //[nBToKsEE]
   Float_t         BToKsEE_mkstar_fullfit[171];   //[nBToKsEE]
   Float_t         BToKsEE_mll_fullfit[171];   //[nBToKsEE]
   Float_t         BToKsEE_mll_llfit[171];   //[nBToKsEE]
   Float_t         BToKsEE_mll_raw[171];   //[nBToKsEE]
   Float_t         BToKsEE_phi[171];   //[nBToKsEE]
   Float_t         BToKsEE_phikstar_fullfit[171];   //[nBToKsEE]
   Float_t         BToKsEE_pt[171];   //[nBToKsEE]
   Float_t         BToKsEE_ptkstar_fullfit[171];   //[nBToKsEE]
   Float_t         BToKsEE_svprob[171];   //[nBToKsEE]
   Float_t         BToKsEE_trk1eta_fullfit[171];   //[nBToKsEE]
   Float_t         BToKsEE_trk1phi_fullfit[171];   //[nBToKsEE]
   Float_t         BToKsEE_trk1pt_fullfit[171];   //[nBToKsEE]
   Float_t         BToKsEE_trk2eta_fullfit[171];   //[nBToKsEE]
   Float_t         BToKsEE_trk2phi_fullfit[171];   //[nBToKsEE]
   Float_t         BToKsEE_trk2pt_fullfit[171];   //[nBToKsEE]
   Int_t           BToKsEE_charge[171];   //[nBToKsEE]
   Int_t           BToKsEE_kstar_idx[171];   //[nBToKsEE]
   Int_t           BToKsEE_l1_idx[171];   //[nBToKsEE]
   Int_t           BToKsEE_l2_idx[171];   //[nBToKsEE]
   Int_t           BToKsEE_pdgId[171];   //[nBToKsEE]
   Int_t           BToKsEE_trk1_idx[171];   //[nBToKsEE]
   Int_t           BToKsEE_trk2_idx[171];   //[nBToKsEE]
   UInt_t          nBToKsMuMu;
   Float_t         BToKsMuMu_barMass[3];   //[nBToKsMuMu]
   Float_t         BToKsMuMu_barMkstar_fullfit[3];   //[nBToKsMuMu]
   Float_t         BToKsMuMu_chi2[3];   //[nBToKsMuMu]
   Float_t         BToKsMuMu_cos2D[3];   //[nBToKsMuMu]
   Float_t         BToKsMuMu_eta[3];   //[nBToKsMuMu]
   Float_t         BToKsMuMu_etakstar_fullfit[3];   //[nBToKsMuMu]
   Float_t         BToKsMuMu_fit_cos2D[3];   //[nBToKsMuMu]
   Float_t         BToKsMuMu_fit_eta[3];   //[nBToKsMuMu]
   Float_t         BToKsMuMu_fit_mass[3];   //[nBToKsMuMu]
   Float_t         BToKsMuMu_fit_massErr[3];   //[nBToKsMuMu]
   Float_t         BToKsMuMu_fit_phi[3];   //[nBToKsMuMu]
   Float_t         BToKsMuMu_fit_pt[3];   //[nBToKsMuMu]
   Float_t         BToKsMuMu_fitted_barMass[3];   //[nBToKsMuMu]
   Float_t         BToKsMuMu_l_xy[3];   //[nBToKsMuMu]
   Float_t         BToKsMuMu_l_xy_unc[3];   //[nBToKsMuMu]
   Float_t         BToKsMuMu_lep1eta_fullfit[3];   //[nBToKsMuMu]
   Float_t         BToKsMuMu_lep1phi_fullfit[3];   //[nBToKsMuMu]
   Float_t         BToKsMuMu_lep1pt_fullfit[3];   //[nBToKsMuMu]
   Float_t         BToKsMuMu_lep2eta_fullfit[3];   //[nBToKsMuMu]
   Float_t         BToKsMuMu_lep2phi_fullfit[3];   //[nBToKsMuMu]
   Float_t         BToKsMuMu_lep2pt_fullfit[3];   //[nBToKsMuMu]
   Float_t         BToKsMuMu_mass[3];   //[nBToKsMuMu]
   Float_t         BToKsMuMu_max_dr[3];   //[nBToKsMuMu]
   Float_t         BToKsMuMu_min_dr[3];   //[nBToKsMuMu]
   Float_t         BToKsMuMu_mkstar_fullfit[3];   //[nBToKsMuMu]
   Float_t         BToKsMuMu_mll_fullfit[3];   //[nBToKsMuMu]
   Float_t         BToKsMuMu_mll_llfit[3];   //[nBToKsMuMu]
   Float_t         BToKsMuMu_mll_raw[3];   //[nBToKsMuMu]
   Float_t         BToKsMuMu_phi[3];   //[nBToKsMuMu]
   Float_t         BToKsMuMu_phikstar_fullfit[3];   //[nBToKsMuMu]
   Float_t         BToKsMuMu_pt[3];   //[nBToKsMuMu]
   Float_t         BToKsMuMu_ptkstar_fullfit[3];   //[nBToKsMuMu]
   Float_t         BToKsMuMu_svprob[3];   //[nBToKsMuMu]
   Float_t         BToKsMuMu_trk1eta_fullfit[3];   //[nBToKsMuMu]
   Float_t         BToKsMuMu_trk1phi_fullfit[3];   //[nBToKsMuMu]
   Float_t         BToKsMuMu_trk1pt_fullfit[3];   //[nBToKsMuMu]
   Float_t         BToKsMuMu_trk2eta_fullfit[3];   //[nBToKsMuMu]
   Float_t         BToKsMuMu_trk2phi_fullfit[3];   //[nBToKsMuMu]
   Float_t         BToKsMuMu_trk2pt_fullfit[3];   //[nBToKsMuMu]
   Int_t           BToKsMuMu_charge[3];   //[nBToKsMuMu]
   Int_t           BToKsMuMu_kstar_idx[3];   //[nBToKsMuMu]
   Int_t           BToKsMuMu_l1_idx[3];   //[nBToKsMuMu]
   Int_t           BToKsMuMu_l2_idx[3];   //[nBToKsMuMu]
   Int_t           BToKsMuMu_pdgId[3];   //[nBToKsMuMu]
   Int_t           BToKsMuMu_trk1_idx[3];   //[nBToKsMuMu]
   Int_t           BToKsMuMu_trk2_idx[3];   //[nBToKsMuMu]
   UInt_t          nKstar;
   Float_t         Kstar_barMass[101];   //[nKstar]
   Float_t         Kstar_eta[101];   //[nKstar]
   Float_t         Kstar_fitted_barMass[101];   //[nKstar]
   Float_t         Kstar_fitted_eta[101];   //[nKstar]
   Float_t         Kstar_fitted_mass[101];   //[nKstar]
   Float_t         Kstar_fitted_phi[101];   //[nKstar]
   Float_t         Kstar_fitted_pt[101];   //[nKstar]
   Float_t         Kstar_mass[101];   //[nKstar]
   Float_t         Kstar_phi[101];   //[nKstar]
   Float_t         Kstar_pt[101];   //[nKstar]
   Float_t         Kstar_svprob[101];   //[nKstar]
   Float_t         Kstar_trk_deltaR[101];   //[nKstar]
   Int_t           Kstar_charge[101];   //[nKstar]
   Int_t           Kstar_pdgId[101];   //[nKstar]
   Int_t           Kstar_trk1_idx[101];   //[nKstar]
   Int_t           Kstar_trk2_idx[101];   //[nKstar]
   UInt_t          nElectron;
   Float_t         Electron_deltaEtaSC[81];   //[nElectron]
   Float_t         Electron_dxy[81];   //[nElectron]
   Float_t         Electron_dxyErr[81];   //[nElectron]
   Float_t         Electron_dz[81];   //[nElectron]
   Float_t         Electron_dzErr[81];   //[nElectron]
   Float_t         Electron_eta[81];   //[nElectron]
   Float_t         Electron_fBrem[81];   //[nElectron]
   Float_t         Electron_hoe[81];   //[nElectron]
   Float_t         Electron_ip3d[81];   //[nElectron]
   Float_t         Electron_mass[81];   //[nElectron]
   Float_t         Electron_mvaId[81];   //[nElectron]
   Float_t         Electron_phi[81];   //[nElectron]
   Float_t         Electron_pt[81];   //[nElectron]
   Float_t         Electron_ptBiased[81];   //[nElectron]
   Float_t         Electron_r9[81];   //[nElectron]
   Float_t         Electron_sieie[81];   //[nElectron]
   Float_t         Electron_sip3d[81];   //[nElectron]
   Float_t         Electron_unBiased[81];   //[nElectron]
   Float_t         Electron_vx[81];   //[nElectron]
   Float_t         Electron_vy[81];   //[nElectron]
   Float_t         Electron_vz[81];   //[nElectron]
   Int_t           Electron_charge[81];   //[nElectron]
   Int_t           Electron_pdgId[81];   //[nElectron]
   Int_t           Electron_tightCharge[81];   //[nElectron]
   Bool_t          Electron_convVeto[81];   //[nElectron]
   Bool_t          Electron_isLowPt[81];   //[nElectron]
   Bool_t          Electron_isPF[81];   //[nElectron]
   Bool_t          Electron_isPFoverlap[81];   //[nElectron]
   UChar_t         Electron_lostHits[81];   //[nElectron]
   UInt_t          nGenPart; 
   Float_t         GenPart_pt[50]; 
   Float_t         GenPart_eta[50]; 
   Float_t         GenPart_phi[50]; 
   Float_t         GenPart_vx[50]; 
   Float_t         GenPart_vy[50]; 
   Float_t         GenPart_vz[50]; 
   Int_t           GenPart_pdgId[50]; 
   Int_t           GenPart_genPartIdxMother[50]; 
   UInt_t          nMuon;
   Float_t         Muon_dxy[7];   //[nMuon]
   Float_t         Muon_dxyErr[7];   //[nMuon]
   Float_t         Muon_dz[7];   //[nMuon]
   Float_t         Muon_dzErr[7];   //[nMuon]
   Float_t         Muon_eta[7];   //[nMuon]
   Float_t         Muon_ip3d[7];   //[nMuon]
   Float_t         Muon_mass[7];   //[nMuon]
   Float_t         Muon_pfRelIso03_all[7];   //[nMuon]
   Float_t         Muon_pfRelIso03_chg[7];   //[nMuon]
   Float_t         Muon_pfRelIso04_all[7];   //[nMuon]
   Float_t         Muon_phi[7];   //[nMuon]
   Float_t         Muon_pt[7];   //[nMuon]
   Float_t         Muon_ptErr[7];   //[nMuon]
   Float_t         Muon_segmentComp[7];   //[nMuon]
   Float_t         Muon_sip3d[7];   //[nMuon]
   Float_t         Muon_vx[7];   //[nMuon]
   Float_t         Muon_vy[7];   //[nMuon]
   Float_t         Muon_vz[7];   //[nMuon]
   Int_t           Muon_charge[7];   //[nMuon]
   Int_t           Muon_genPartIdx[7];   //[nMuon]
   Int_t           Muon_isTriggering[7];   //[nMuon]
   Int_t           Muon_nStations[7];   //[nMuon]
   Int_t           Muon_pdgId[7];   //[nMuon]
   Int_t           Muon_tightCharge[7];   //[nMuon]
   UChar_t         Muon_highPtId[7];   //[nMuon]
   Bool_t          Muon_inTimeMuon[7];   //[nMuon]
   Bool_t          Muon_isGlobal[7];   //[nMuon]
   Bool_t          Muon_isPFcand[7];   //[nMuon]
   Bool_t          Muon_isTracker[7];   //[nMuon]
   Bool_t          Muon_mediumId[7];   //[nMuon]
   Bool_t          Muon_mediumPromptId[7];   //[nMuon]
   UChar_t         Muon_miniIsoId[7];   //[nMuon]
   UChar_t         Muon_multiIsoId[7];   //[nMuon]
   UChar_t         Muon_mvaId[7];   //[nMuon]
   UChar_t         Muon_pfIsoId[7];   //[nMuon]
   Bool_t          Muon_softId[7];   //[nMuon]
   Bool_t          Muon_softMvaId[7];   //[nMuon]
   Bool_t          Muon_tightId[7];   //[nMuon]
   UChar_t         Muon_tkIsoId[7];   //[nMuon]
   Bool_t          Muon_triggerIdLoose[7];   //[nMuon]
   UInt_t          nTriggerMuon;
   Float_t         TriggerMuon_eta[2];   //[nTriggerMuon]
   Float_t         TriggerMuon_mass[2];   //[nTriggerMuon]
   Float_t         TriggerMuon_phi[2];   //[nTriggerMuon]
   Float_t         TriggerMuon_pt[2];   //[nTriggerMuon]
   Float_t         TriggerMuon_vx[2];   //[nTriggerMuon]
   Float_t         TriggerMuon_vy[2];   //[nTriggerMuon]
   Float_t         TriggerMuon_vz[2];   //[nTriggerMuon]
   Int_t           TriggerMuon_charge[2];   //[nTriggerMuon]
   Int_t           TriggerMuon_pdgId[2];   //[nTriggerMuon]
   Int_t           TriggerMuon_trgMuonIndex[2];   //[nTriggerMuon]
   Float_t         fixedGridRhoFastjetAll;
   Float_t         fixedGridRhoFastjetCentral;
   Float_t         fixedGridRhoFastjetCentralCalo;
   Float_t         fixedGridRhoFastjetCentralChargedPileUp;
   Float_t         fixedGridRhoFastjetCentralNeutral;
   UInt_t          nProbeTracks;
   Float_t         ProbeTracks_DCASig[238];   //[nProbeTracks]
   Float_t         ProbeTracks_dxy[238];   //[nProbeTracks]
   Float_t         ProbeTracks_dxyS[238];   //[nProbeTracks]
   Float_t         ProbeTracks_dz[238];   //[nProbeTracks]
   Float_t         ProbeTracks_dzS[238];   //[nProbeTracks]
   Float_t         ProbeTracks_eta[238];   //[nProbeTracks]
   Float_t         ProbeTracks_mass[238];   //[nProbeTracks]
   Float_t         ProbeTracks_phi[238];   //[nProbeTracks]
   Float_t         ProbeTracks_pt[238];   //[nProbeTracks]
   Float_t         ProbeTracks_vx[238];   //[nProbeTracks]
   Float_t         ProbeTracks_vy[238];   //[nProbeTracks]
   Float_t         ProbeTracks_vz[238];   //[nProbeTracks]
   Int_t           ProbeTracks_charge[238];   //[nProbeTracks]
   Int_t           ProbeTracks_isLostTrk[238];   //[nProbeTracks]
   Int_t           ProbeTracks_isPacked[238];   //[nProbeTracks]
   Int_t           ProbeTracks_pdgId[238];   //[nProbeTracks]
   Bool_t          ProbeTracks_isMatchedToEle[238];   //[nProbeTracks]
   Bool_t          ProbeTracks_isMatchedToLooseMuon[238];   //[nProbeTracks]
   Bool_t          ProbeTracks_isMatchedToMediumMuon[238];   //[nProbeTracks]
   Bool_t          ProbeTracks_isMatchedToMuon[238];   //[nProbeTracks]
   Bool_t          ProbeTracks_isMatchedToSoftMuon[238];   //[nProbeTracks]
   UChar_t         HLT_Mu7_IP4;
   UChar_t         HLT_Mu8_IP6;
   UChar_t         HLT_Mu8_IP5;
   UChar_t         HLT_Mu8_IP3;
   UChar_t         HLT_Mu8p5_IP3p5;
   UChar_t         HLT_Mu9_IP6;
   UChar_t         HLT_Mu9_IP5;
   UChar_t         HLT_Mu9_IP4;
   UChar_t         HLT_Mu10p5_IP3p5;
   UChar_t         HLT_Mu12_IP6;
   UChar_t         L1_SingleMu7er1p5;
   UChar_t         L1_SingleMu8er1p5;
   UChar_t         L1_SingleMu9er1p5;
   UChar_t         L1_SingleMu10er1p5;
   UChar_t         L1_SingleMu12er1p5;
   UChar_t         L1_SingleMu22;
   UInt_t          nTrigObj;
   Float_t         TrigObj_pt[3];   //[nTrigObj]
   Float_t         TrigObj_eta[3];   //[nTrigObj]
   Float_t         TrigObj_phi[3];   //[nTrigObj]
   Float_t         TrigObj_l1pt[3];   //[nTrigObj]
   Float_t         TrigObj_l1pt_2[3];   //[nTrigObj]
   Float_t         TrigObj_l2pt[3];   //[nTrigObj]
   Int_t           TrigObj_id[3];   //[nTrigObj]
   Int_t           TrigObj_l1iso[3];   //[nTrigObj]
   Int_t           TrigObj_l1charge[3];   //[nTrigObj]
   Int_t           TrigObj_filterBits[3];   //[nTrigObj]
   UInt_t          nOtherPV;
   Float_t         OtherPV_z[3];   //[nOtherPV]
   Float_t         PV_ndof;
   Float_t         PV_x;
   Float_t         PV_y;
   Float_t         PV_z;
   Float_t         PV_chi2;
   Float_t         PV_score;
   Int_t           PV_npvs;
   Int_t           PV_npvsGood;
   UInt_t          nSV;
   Float_t         SV_dlen[8];   //[nSV]
   Float_t         SV_dlenSig[8];   //[nSV]
   Float_t         SV_pAngle[8];   //[nSV]
   Float_t         SV_chi2[8];   //[nSV]
   Float_t         SV_eta[8];   //[nSV]
   Float_t         SV_mass[8];   //[nSV]
   Float_t         SV_ndof[8];   //[nSV]
   Float_t         SV_phi[8];   //[nSV]
   Float_t         SV_pt[8];   //[nSV]
   Float_t         SV_x[8];   //[nSV]
   Float_t         SV_y[8];   //[nSV]
   Float_t         SV_z[8];   //[nSV]

   // List of branches
   TBranch        *b_run;   //!
   TBranch        *b_luminosityBlock;   //!
   TBranch        *b_event;   //!
   TBranch        *b_nBToKEE;   //!
   TBranch        *b_BToKEE_chi2;   //!
   TBranch        *b_BToKEE_cos2D;   //!
   TBranch        *b_BToKEE_eta;   //!
   TBranch        *b_BToKEE_fit_cos2D;   //!
   TBranch        *b_BToKEE_fit_eta;   //!
   TBranch        *b_BToKEE_fit_k_eta;   //!
   TBranch        *b_BToKEE_fit_k_phi;   //!
   TBranch        *b_BToKEE_fit_k_pt;   //!
   TBranch        *b_BToKEE_fit_l1_eta;   //!
   TBranch        *b_BToKEE_fit_l1_phi;   //!
   TBranch        *b_BToKEE_fit_l1_pt;   //!
   TBranch        *b_BToKEE_fit_l2_eta;   //!
   TBranch        *b_BToKEE_fit_l2_phi;   //!
   TBranch        *b_BToKEE_fit_l2_pt;   //!
   TBranch        *b_BToKEE_fit_mass;   //!
   TBranch        *b_BToKEE_fit_massErr;   //!
   TBranch        *b_BToKEE_fit_phi;   //!
   TBranch        *b_BToKEE_fit_pt;   //!
   TBranch        *b_BToKEE_l_xy;   //!
   TBranch        *b_BToKEE_l_xy_unc;   //!
   TBranch        *b_BToKEE_mass;   //!
   TBranch        *b_BToKEE_maxDR;   //!
   TBranch        *b_BToKEE_minDR;   //!
   TBranch        *b_BToKEE_mllErr_llfit;   //!
   TBranch        *b_BToKEE_mll_fullfit;   //!
   TBranch        *b_BToKEE_mll_llfit;   //!
   TBranch        *b_BToKEE_mll_raw;   //!
   TBranch        *b_BToKEE_phi;   //!
   TBranch        *b_BToKEE_pt;   //!
   TBranch        *b_BToKEE_svprob;   //!
   TBranch        *b_BToKEE_vtx_ex;   //!
   TBranch        *b_BToKEE_vtx_ey;   //!
   TBranch        *b_BToKEE_vtx_ez;   //!
   TBranch        *b_BToKEE_vtx_x;   //!
   TBranch        *b_BToKEE_vtx_y;   //!
   TBranch        *b_BToKEE_vtx_z;   //!
   TBranch        *b_BToKEE_charge;   //!
   TBranch        *b_BToKEE_kIdx;   //!
   TBranch        *b_BToKEE_l1Idx;   //!
   TBranch        *b_BToKEE_l2Idx;   //!
   TBranch        *b_BToKEE_pdgId;   //!
   TBranch        *b_nBToKMuMu;   //!
   TBranch        *b_BToKMuMu_chi2;   //!
   TBranch        *b_BToKMuMu_cos2D;   //!
   TBranch        *b_BToKMuMu_eta;   //!
   TBranch        *b_BToKMuMu_fit_cos2D;   //!
   TBranch        *b_BToKMuMu_fit_eta;   //!
   TBranch        *b_BToKMuMu_fit_k_eta;   //!
   TBranch        *b_BToKMuMu_fit_k_phi;   //!
   TBranch        *b_BToKMuMu_fit_k_pt;   //!
   TBranch        *b_BToKMuMu_fit_l1_eta;   //!
   TBranch        *b_BToKMuMu_fit_l1_phi;   //!
   TBranch        *b_BToKMuMu_fit_l1_pt;   //!
   TBranch        *b_BToKMuMu_fit_l2_eta;   //!
   TBranch        *b_BToKMuMu_fit_l2_phi;   //!
   TBranch        *b_BToKMuMu_fit_l2_pt;   //!
   TBranch        *b_BToKMuMu_fit_mass;   //!
   TBranch        *b_BToKMuMu_fit_massErr;   //!
   TBranch        *b_BToKMuMu_fit_phi;   //!
   TBranch        *b_BToKMuMu_fit_pt;   //!
   TBranch        *b_BToKMuMu_l_xy;   //!
   TBranch        *b_BToKMuMu_l_xy_unc;   //!
   TBranch        *b_BToKMuMu_mass;   //!
   TBranch        *b_BToKMuMu_maxDR;   //!
   TBranch        *b_BToKMuMu_minDR;   //!
   TBranch        *b_BToKMuMu_mllErr_llfit;   //!
   TBranch        *b_BToKMuMu_mll_fullfit;   //!
   TBranch        *b_BToKMuMu_mll_llfit;   //!
   TBranch        *b_BToKMuMu_mll_raw;   //!
   TBranch        *b_BToKMuMu_phi;   //!
   TBranch        *b_BToKMuMu_pt;   //!
   TBranch        *b_BToKMuMu_svprob;   //!
   TBranch        *b_BToKMuMu_vtx_ex;   //!
   TBranch        *b_BToKMuMu_vtx_ey;   //!
   TBranch        *b_BToKMuMu_vtx_ez;   //!
   TBranch        *b_BToKMuMu_vtx_x;   //!
   TBranch        *b_BToKMuMu_vtx_y;   //!
   TBranch        *b_BToKMuMu_vtx_z;   //!
   TBranch        *b_BToKMuMu_charge;   //!
   TBranch        *b_BToKMuMu_kIdx;   //!
   TBranch        *b_BToKMuMu_l1Idx;   //!
   TBranch        *b_BToKMuMu_l2Idx;   //!
   TBranch        *b_BToKMuMu_pdgId;   //!
   TBranch        *b_nBToKsEE;   //!
   TBranch        *b_BToKsEE_barMass;   //!
   TBranch        *b_BToKsEE_barMkstar_fullfit;   //!
   TBranch        *b_BToKsEE_chi2;   //!
   TBranch        *b_BToKsEE_cos2D;   //!
   TBranch        *b_BToKsEE_eta;   //!
   TBranch        *b_BToKsEE_etakstar_fullfit;   //!
   TBranch        *b_BToKsEE_fit_cos2D;   //!
   TBranch        *b_BToKsEE_fit_eta;   //!
   TBranch        *b_BToKsEE_fit_mass;   //!
   TBranch        *b_BToKsEE_fit_massErr;   //!
   TBranch        *b_BToKsEE_fit_phi;   //!
   TBranch        *b_BToKsEE_fit_pt;   //!
   TBranch        *b_BToKsEE_fitted_barMass;   //!
   TBranch        *b_BToKsEE_l_xy;   //!
   TBranch        *b_BToKsEE_l_xy_unc;   //!
   TBranch        *b_BToKsEE_lep1eta_fullfit;   //!
   TBranch        *b_BToKsEE_lep1phi_fullfit;   //!
   TBranch        *b_BToKsEE_lep1pt_fullfit;   //!
   TBranch        *b_BToKsEE_lep2eta_fullfit;   //!
   TBranch        *b_BToKsEE_lep2phi_fullfit;   //!
   TBranch        *b_BToKsEE_lep2pt_fullfit;   //!
   TBranch        *b_BToKsEE_mass;   //!
   TBranch        *b_BToKsEE_max_dr;   //!
   TBranch        *b_BToKsEE_min_dr;   //!
   TBranch        *b_BToKsEE_mkstar_fullfit;   //!
   TBranch        *b_BToKsEE_mll_fullfit;   //!
   TBranch        *b_BToKsEE_mll_llfit;   //!
   TBranch        *b_BToKsEE_mll_raw;   //!
   TBranch        *b_BToKsEE_phi;   //!
   TBranch        *b_BToKsEE_phikstar_fullfit;   //!
   TBranch        *b_BToKsEE_pt;   //!
   TBranch        *b_BToKsEE_ptkstar_fullfit;   //!
   TBranch        *b_BToKsEE_svprob;   //!
   TBranch        *b_BToKsEE_trk1eta_fullfit;   //!
   TBranch        *b_BToKsEE_trk1phi_fullfit;   //!
   TBranch        *b_BToKsEE_trk1pt_fullfit;   //!
   TBranch        *b_BToKsEE_trk2eta_fullfit;   //!
   TBranch        *b_BToKsEE_trk2phi_fullfit;   //!
   TBranch        *b_BToKsEE_trk2pt_fullfit;   //!
   TBranch        *b_BToKsEE_charge;   //!
   TBranch        *b_BToKsEE_kstar_idx;   //!
   TBranch        *b_BToKsEE_l1_idx;   //!
   TBranch        *b_BToKsEE_l2_idx;   //!
   TBranch        *b_BToKsEE_pdgId;   //!
   TBranch        *b_BToKsEE_trk1_idx;   //!
   TBranch        *b_BToKsEE_trk2_idx;   //!
   TBranch        *b_nBToKsMuMu;   //!
   TBranch        *b_BToKsMuMu_barMass;   //!
   TBranch        *b_BToKsMuMu_barMkstar_fullfit;   //!
   TBranch        *b_BToKsMuMu_chi2;   //!
   TBranch        *b_BToKsMuMu_cos2D;   //!
   TBranch        *b_BToKsMuMu_eta;   //!
   TBranch        *b_BToKsMuMu_etakstar_fullfit;   //!
   TBranch        *b_BToKsMuMu_fit_cos2D;   //!
   TBranch        *b_BToKsMuMu_fit_eta;   //!
   TBranch        *b_BToKsMuMu_fit_mass;   //!
   TBranch        *b_BToKsMuMu_fit_massErr;   //!
   TBranch        *b_BToKsMuMu_fit_phi;   //!
   TBranch        *b_BToKsMuMu_fit_pt;   //!
   TBranch        *b_BToKsMuMu_fitted_barMass;   //!
   TBranch        *b_BToKsMuMu_l_xy;   //!
   TBranch        *b_BToKsMuMu_l_xy_unc;   //!
   TBranch        *b_BToKsMuMu_lep1eta_fullfit;   //!
   TBranch        *b_BToKsMuMu_lep1phi_fullfit;   //!
   TBranch        *b_BToKsMuMu_lep1pt_fullfit;   //!
   TBranch        *b_BToKsMuMu_lep2eta_fullfit;   //!
   TBranch        *b_BToKsMuMu_lep2phi_fullfit;   //!
   TBranch        *b_BToKsMuMu_lep2pt_fullfit;   //!
   TBranch        *b_BToKsMuMu_mass;   //!
   TBranch        *b_BToKsMuMu_max_dr;   //!
   TBranch        *b_BToKsMuMu_min_dr;   //!
   TBranch        *b_BToKsMuMu_mkstar_fullfit;   //!
   TBranch        *b_BToKsMuMu_mll_fullfit;   //!
   TBranch        *b_BToKsMuMu_mll_llfit;   //!
   TBranch        *b_BToKsMuMu_mll_raw;   //!
   TBranch        *b_BToKsMuMu_phi;   //!
   TBranch        *b_BToKsMuMu_phikstar_fullfit;   //!
   TBranch        *b_BToKsMuMu_pt;   //!
   TBranch        *b_BToKsMuMu_ptkstar_fullfit;   //!
   TBranch        *b_BToKsMuMu_svprob;   //!
   TBranch        *b_BToKsMuMu_trk1eta_fullfit;   //!
   TBranch        *b_BToKsMuMu_trk1phi_fullfit;   //!
   TBranch        *b_BToKsMuMu_trk1pt_fullfit;   //!
   TBranch        *b_BToKsMuMu_trk2eta_fullfit;   //!
   TBranch        *b_BToKsMuMu_trk2phi_fullfit;   //!
   TBranch        *b_BToKsMuMu_trk2pt_fullfit;   //!
   TBranch        *b_BToKsMuMu_charge;   //!
   TBranch        *b_BToKsMuMu_kstar_idx;   //!
   TBranch        *b_BToKsMuMu_l1_idx;   //!
   TBranch        *b_BToKsMuMu_l2_idx;   //!
   TBranch        *b_BToKsMuMu_pdgId;   //!
   TBranch        *b_BToKsMuMu_trk1_idx;   //!
   TBranch        *b_BToKsMuMu_trk2_idx;   //!
   TBranch        *b_nKstar;   //!
   TBranch        *b_Kstar_barMass;   //!
   TBranch        *b_Kstar_eta;   //!
   TBranch        *b_Kstar_fitted_barMass;   //!
   TBranch        *b_Kstar_fitted_eta;   //!
   TBranch        *b_Kstar_fitted_mass;   //!
   TBranch        *b_Kstar_fitted_phi;   //!
   TBranch        *b_Kstar_fitted_pt;   //!
   TBranch        *b_Kstar_mass;   //!
   TBranch        *b_Kstar_phi;   //!
   TBranch        *b_Kstar_pt;   //!
   TBranch        *b_Kstar_svprob;   //!
   TBranch        *b_Kstar_trk_deltaR;   //!
   TBranch        *b_Kstar_charge;   //!
   TBranch        *b_Kstar_pdgId;   //!
   TBranch        *b_Kstar_trk1_idx;   //!
   TBranch        *b_Kstar_trk2_idx;   //!
   TBranch        *b_nElectron;   //!
   TBranch        *b_Electron_deltaEtaSC;   //!
   TBranch        *b_Electron_dxy;   //!
   TBranch        *b_Electron_dxyErr;   //!
   TBranch        *b_Electron_dz;   //!
   TBranch        *b_Electron_dzErr;   //!
   TBranch        *b_Electron_eta;   //!
   TBranch        *b_Electron_fBrem;   //!
   TBranch        *b_Electron_hoe;   //!
   TBranch        *b_Electron_ip3d;   //!
   TBranch        *b_Electron_mass;   //!
   TBranch        *b_Electron_mvaId;   //!
   TBranch        *b_Electron_phi;   //!
   TBranch        *b_Electron_pt;   //!
   TBranch        *b_Electron_ptBiased;   //!
   TBranch        *b_Electron_r9;   //!
   TBranch        *b_Electron_sieie;   //!
   TBranch        *b_Electron_sip3d;   //!
   TBranch        *b_Electron_unBiased;   //!
   TBranch        *b_Electron_vx;   //!
   TBranch        *b_Electron_vy;   //!
   TBranch        *b_Electron_vz;   //!
   TBranch        *b_Electron_charge;   //!
   TBranch        *b_Electron_pdgId;   //!
   TBranch        *b_Electron_tightCharge;   //!
   TBranch        *b_Electron_convVeto;   //!
   TBranch        *b_Electron_isLowPt;   //!
   TBranch        *b_Electron_isPF;   //!
   TBranch        *b_Electron_isPFoverlap;   //!
   TBranch        *b_Electron_lostHits;   //!
   TBranch        *b_nMuon;   //!
   TBranch        *b_nGenPart;   //!
   TBranch        *b_GenPart_pt;   //!
   TBranch        *b_GenPart_eta;   //!
   TBranch        *b_GenPart_phi;   //!
   TBranch        *b_GenPart_vx;   //!
   TBranch        *b_GenPart_vy;   //!
   TBranch        *b_GenPart_vz;   //!
   TBranch        *b_GenPart_pdgId;   //!
   TBranch        *b_GenPart_genPartIdxMother;   //!
   TBranch        *b_Muon_dxy;   //!
   TBranch        *b_Muon_dxyErr;   //!
   TBranch        *b_Muon_dz;   //!
   TBranch        *b_Muon_dzErr;   //!
   TBranch        *b_Muon_eta;   //!
   TBranch        *b_Muon_ip3d;   //!
   TBranch        *b_Muon_mass;   //!
   TBranch        *b_Muon_pfRelIso03_all;   //!
   TBranch        *b_Muon_pfRelIso03_chg;   //!
   TBranch        *b_Muon_pfRelIso04_all;   //!
   TBranch        *b_Muon_phi;   //!
   TBranch        *b_Muon_pt;   //!
   TBranch        *b_Muon_ptErr;   //!
   TBranch        *b_Muon_segmentComp;   //!
   TBranch        *b_Muon_sip3d;   //!
   TBranch        *b_Muon_vx;   //!
   TBranch        *b_Muon_vy;   //!
   TBranch        *b_Muon_vz;   //!
   TBranch        *b_Muon_charge;   //!
   TBranch        *b_Muon_genPartIdx;   //!
   TBranch        *b_Muon_isTriggering;   //!
   TBranch        *b_Muon_nStations;   //!
   TBranch        *b_Muon_pdgId;   //!
   TBranch        *b_Muon_tightCharge;   //!
   TBranch        *b_Muon_highPtId;   //!
   TBranch        *b_Muon_inTimeMuon;   //!
   TBranch        *b_Muon_isGlobal;   //!
   TBranch        *b_Muon_isPFcand;   //!
   TBranch        *b_Muon_isTracker;   //!
   TBranch        *b_Muon_mediumId;   //!
   TBranch        *b_Muon_mediumPromptId;   //!
   TBranch        *b_Muon_miniIsoId;   //!
   TBranch        *b_Muon_multiIsoId;   //!
   TBranch        *b_Muon_mvaId;   //!
   TBranch        *b_Muon_pfIsoId;   //!
   TBranch        *b_Muon_softId;   //!
   TBranch        *b_Muon_softMvaId;   //!
   TBranch        *b_Muon_tightId;   //!
   TBranch        *b_Muon_tkIsoId;   //!
   TBranch        *b_Muon_triggerIdLoose;   //!
   TBranch        *b_nTriggerMuon;   //!
   TBranch        *b_TriggerMuon_eta;   //!
   TBranch        *b_TriggerMuon_mass;   //!
   TBranch        *b_TriggerMuon_phi;   //!
   TBranch        *b_TriggerMuon_pt;   //!
   TBranch        *b_TriggerMuon_vx;   //!
   TBranch        *b_TriggerMuon_vy;   //!
   TBranch        *b_TriggerMuon_vz;   //!
   TBranch        *b_TriggerMuon_charge;   //!
   TBranch        *b_TriggerMuon_pdgId;   //!
   TBranch        *b_TriggerMuon_trgMuonIndex;   //!
   TBranch        *b_fixedGridRhoFastjetAll;   //!
   TBranch        *b_fixedGridRhoFastjetCentral;   //!
   TBranch        *b_fixedGridRhoFastjetCentralCalo;   //!
   TBranch        *b_fixedGridRhoFastjetCentralChargedPileUp;   //!
   TBranch        *b_fixedGridRhoFastjetCentralNeutral;   //!
   TBranch        *b_nProbeTracks;   //!
   TBranch        *b_ProbeTracks_DCASig;   //!
   TBranch        *b_ProbeTracks_dxy;   //!
   TBranch        *b_ProbeTracks_dxyS;   //!
   TBranch        *b_ProbeTracks_dz;   //!
   TBranch        *b_ProbeTracks_dzS;   //!
   TBranch        *b_ProbeTracks_eta;   //!
   TBranch        *b_ProbeTracks_mass;   //!
   TBranch        *b_ProbeTracks_phi;   //!
   TBranch        *b_ProbeTracks_pt;   //!
   TBranch        *b_ProbeTracks_vx;   //!
   TBranch        *b_ProbeTracks_vy;   //!
   TBranch        *b_ProbeTracks_vz;   //!
   TBranch        *b_ProbeTracks_charge;   //!
   TBranch        *b_ProbeTracks_isLostTrk;   //!
   TBranch        *b_ProbeTracks_isPacked;   //!
   TBranch        *b_ProbeTracks_pdgId;   //!
   TBranch        *b_ProbeTracks_isMatchedToEle;   //!
   TBranch        *b_ProbeTracks_isMatchedToLooseMuon;   //!
   TBranch        *b_ProbeTracks_isMatchedToMediumMuon;   //!
   TBranch        *b_ProbeTracks_isMatchedToMuon;   //!
   TBranch        *b_ProbeTracks_isMatchedToSoftMuon;   //!
   TBranch        *b_HLT_Mu7_IP4;   //!
   TBranch        *b_HLT_Mu8_IP6;   //!
   TBranch        *b_HLT_Mu8_IP5;   //!
   TBranch        *b_HLT_Mu8_IP3;   //!
   TBranch        *b_HLT_Mu8p5_IP3p5;   //!
   TBranch        *b_HLT_Mu9_IP6;   //!
   TBranch        *b_HLT_Mu9_IP5;   //!
   TBranch        *b_HLT_Mu9_IP4;   //!
   TBranch        *b_HLT_Mu10p5_IP3p5;   //!
   TBranch        *b_HLT_Mu12_IP6;   //!
   TBranch        *b_L1_SingleMu7er1p5;   //!
   TBranch        *b_L1_SingleMu8er1p5;   //!
   TBranch        *b_L1_SingleMu9er1p5;   //!
   TBranch        *b_L1_SingleMu10er1p5;   //!
   TBranch        *b_L1_SingleMu12er1p5;   //!
   TBranch        *b_L1_SingleMu22;   //!
   TBranch        *b_nTrigObj;   //!
   TBranch        *b_TrigObj_pt;   //!
   TBranch        *b_TrigObj_eta;   //!
   TBranch        *b_TrigObj_phi;   //!
   TBranch        *b_TrigObj_l1pt;   //!
   TBranch        *b_TrigObj_l1pt_2;   //!
   TBranch        *b_TrigObj_l2pt;   //!
   TBranch        *b_TrigObj_id;   //!
   TBranch        *b_TrigObj_l1iso;   //!
   TBranch        *b_TrigObj_l1charge;   //!
   TBranch        *b_TrigObj_filterBits;   //!
   TBranch        *b_nOtherPV;   //!
   TBranch        *b_OtherPV_z;   //!
   TBranch        *b_PV_ndof;   //!
   TBranch        *b_PV_x;   //!
   TBranch        *b_PV_y;   //!
   TBranch        *b_PV_z;   //!
   TBranch        *b_PV_chi2;   //!
   TBranch        *b_PV_score;   //!
   TBranch        *b_PV_npvs;   //!
   TBranch        *b_PV_npvsGood;   //!
   TBranch        *b_nSV;   //!
   TBranch        *b_SV_dlen;   //!
   TBranch        *b_SV_dlenSig;   //!
   TBranch        *b_SV_pAngle;   //!
   TBranch        *b_SV_chi2;   //!
   TBranch        *b_SV_eta;   //!
   TBranch        *b_SV_mass;   //!
   TBranch        *b_SV_ndof;   //!
   TBranch        *b_SV_phi;   //!
   TBranch        *b_SV_pt;   //!
   TBranch        *b_SV_x;   //!
   TBranch        *b_SV_y;   //!
   TBranch        *b_SV_z;   //!

//   BNanoClass(TTree *tree=0);
  // virtual ~BNanoClass();
  // virtual Int_t    Cut(Long64_t entry);
 //  virtual Int_t    GetEntry(Long64_t entry);
  // virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
  // virtual void     Loop();
   //virtual Bool_t   Notify();
//   virtual void     Show(Long64_t entry = -1);
};

//#endif

//#ifdef BNanoClass_cxx
//#endif // #ifdef BNanoClass_cxx
