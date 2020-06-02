//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Fri Apr  3 15:48:08 2020 by ROOT version 6.12/07
// from TTree Events/Events
// found on file: /eos/cms/store/group/cmst3/group/bpark/BParkingNANO_2020Jan16/ParkingBPH1/crab_data_Run2018D_part1/200116_151214/0000/BParkNANO_data_2020Jan16_100.root
//////////////////////////////////////////////////////////

#ifndef BNanoClass_h
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
   Float_t         BToKEE_b_iso03[1910];   //[nBToKEE]
   Float_t         BToKEE_b_iso04[1910];   //[nBToKEE]
   Float_t         BToKEE_cos2D[1910];   //[nBToKEE]
   Float_t         BToKEE_eta[1910];   //[nBToKEE]
   Float_t         BToKEE_fit_cos2D[1910];   //[nBToKEE]
   Float_t         BToKEE_fit_eta[1910];   //[nBToKEE]
   Float_t         BToKEE_fit_k_eta[1910];   //[nBToKEE]
   Float_t         BToKEE_fit_k_phi[1910];   //[nBToKEE]
   Float_t         BToKEE_fit_k_pt[1910];   //[nBToKEE]
   Float_t         BToKEE_fit_l1_eta[1910];   //[nBToKEE]
   Float_t         BToKEE_fit_l1_phi[1910];   //[nBToKEE]
   Float_t         BToKEE_fit_l1_pt[1910];   //[nBToKEE]
   Float_t         BToKEE_fit_l2_eta[1910];   //[nBToKEE]
   Float_t         BToKEE_fit_l2_phi[1910];   //[nBToKEE]
   Float_t         BToKEE_fit_l2_pt[1910];   //[nBToKEE]
   Float_t         BToKEE_fit_mass[1910];   //[nBToKEE]
   Float_t         BToKEE_fit_massErr[1910];   //[nBToKEE]
   Float_t         BToKEE_fit_phi[1910];   //[nBToKEE]
   Float_t         BToKEE_fit_pt[1910];   //[nBToKEE]
   Float_t         BToKEE_k_iso03[1910];   //[nBToKEE]
   Float_t         BToKEE_k_iso04[1910];   //[nBToKEE]
   Float_t         BToKEE_l1_iso03[1910];   //[nBToKEE]
   Float_t         BToKEE_l1_iso04[1910];   //[nBToKEE]
   Float_t         BToKEE_l2_iso03[1910];   //[nBToKEE]
   Float_t         BToKEE_l2_iso04[1910];   //[nBToKEE]
   Float_t         BToKEE_l_xy[1910];   //[nBToKEE]
   Float_t         BToKEE_l_xy_unc[1910];   //[nBToKEE]
   Float_t         BToKEE_mass[1910];   //[nBToKEE]
   Float_t         BToKEE_maxDR[1910];   //[nBToKEE]
   Float_t         BToKEE_minDR[1910];   //[nBToKEE]
   Float_t         BToKEE_mllErr_llfit[1910];   //[nBToKEE]
   Float_t         BToKEE_mll_fullfit[1910];   //[nBToKEE]
   Float_t         BToKEE_mll_llfit[1910];   //[nBToKEE]
   Float_t         BToKEE_mll_raw[1910];   //[nBToKEE]
   Float_t         BToKEE_phi[1910];   //[nBToKEE]
   Float_t         BToKEE_pt[1910];   //[nBToKEE]
   Float_t         BToKEE_svprob[1910];   //[nBToKEE]
   Float_t         BToKEE_vtx_ex[1910];   //[nBToKEE]
   Float_t         BToKEE_vtx_ey[1910];   //[nBToKEE]
   Float_t         BToKEE_vtx_ez[1910];   //[nBToKEE]
   Float_t         BToKEE_vtx_x[1910];   //[nBToKEE]
   Float_t         BToKEE_vtx_y[1910];   //[nBToKEE]
   Float_t         BToKEE_vtx_z[1910];   //[nBToKEE]
   Int_t           BToKEE_charge[1910];   //[nBToKEE]
   Int_t           BToKEE_kIdx[1910];   //[nBToKEE]
   Int_t           BToKEE_l1Idx[1910];   //[nBToKEE]
   Int_t           BToKEE_l2Idx[1910];   //[nBToKEE]
   Int_t           BToKEE_n_k_used[1910];   //[nBToKEE]
   Int_t           BToKEE_n_l1_used[1910];   //[nBToKEE]
   Int_t           BToKEE_n_l2_used[1910];   //[nBToKEE]
   Int_t           BToKEE_pdgId[1910];   //[nBToKEE]
   UInt_t          nBToKMuMu;
   Float_t         BToKMuMu_b_iso03[45];   //[nBToKMuMu]
   Float_t         BToKMuMu_b_iso04[45];   //[nBToKMuMu]
   Float_t         BToKMuMu_cos2D[45];   //[nBToKMuMu]
   Float_t         BToKMuMu_eta[45];   //[nBToKMuMu]
   Float_t         BToKMuMu_fit_cos2D[45];   //[nBToKMuMu]
   Float_t         BToKMuMu_fit_eta[45];   //[nBToKMuMu]
   Float_t         BToKMuMu_fit_k_eta[45];   //[nBToKMuMu]
   Float_t         BToKMuMu_fit_k_phi[45];   //[nBToKMuMu]
   Float_t         BToKMuMu_fit_k_pt[45];   //[nBToKMuMu]
   Float_t         BToKMuMu_fit_l1_eta[45];   //[nBToKMuMu]
   Float_t         BToKMuMu_fit_l1_phi[45];   //[nBToKMuMu]
   Float_t         BToKMuMu_fit_l1_pt[45];   //[nBToKMuMu]
   Float_t         BToKMuMu_fit_l2_eta[45];   //[nBToKMuMu]
   Float_t         BToKMuMu_fit_l2_phi[45];   //[nBToKMuMu]
   Float_t         BToKMuMu_fit_l2_pt[45];   //[nBToKMuMu]
   Float_t         BToKMuMu_fit_mass[45];   //[nBToKMuMu]
   Float_t         BToKMuMu_fit_massErr[45];   //[nBToKMuMu]
   Float_t         BToKMuMu_fit_phi[45];   //[nBToKMuMu]
   Float_t         BToKMuMu_fit_pt[45];   //[nBToKMuMu]
   Float_t         BToKMuMu_k_iso03[45];   //[nBToKMuMu]
   Float_t         BToKMuMu_k_iso04[45];   //[nBToKMuMu]
   Float_t         BToKMuMu_l1_iso03[45];   //[nBToKMuMu]
   Float_t         BToKMuMu_l1_iso04[45];   //[nBToKMuMu]
   Float_t         BToKMuMu_l2_iso03[45];   //[nBToKMuMu]
   Float_t         BToKMuMu_l2_iso04[45];   //[nBToKMuMu]
   Float_t         BToKMuMu_l_xy[45];   //[nBToKMuMu]
   Float_t         BToKMuMu_l_xy_unc[45];   //[nBToKMuMu]
   Float_t         BToKMuMu_mass[45];   //[nBToKMuMu]
   Float_t         BToKMuMu_maxDR[45];   //[nBToKMuMu]
   Float_t         BToKMuMu_minDR[45];   //[nBToKMuMu]
   Float_t         BToKMuMu_mllErr_llfit[45];   //[nBToKMuMu]
   Float_t         BToKMuMu_mll_fullfit[45];   //[nBToKMuMu]
   Float_t         BToKMuMu_mll_llfit[45];   //[nBToKMuMu]
   Float_t         BToKMuMu_mll_raw[45];   //[nBToKMuMu]
   Float_t         BToKMuMu_phi[45];   //[nBToKMuMu]
   Float_t         BToKMuMu_pt[45];   //[nBToKMuMu]
   Float_t         BToKMuMu_svprob[45];   //[nBToKMuMu]
   Float_t         BToKMuMu_vtx_ex[45];   //[nBToKMuMu]
   Float_t         BToKMuMu_vtx_ey[45];   //[nBToKMuMu]
   Float_t         BToKMuMu_vtx_ez[45];   //[nBToKMuMu]
   Float_t         BToKMuMu_vtx_x[45];   //[nBToKMuMu]
   Float_t         BToKMuMu_vtx_y[45];   //[nBToKMuMu]
   Float_t         BToKMuMu_vtx_z[45];   //[nBToKMuMu]
   Int_t           BToKMuMu_charge[45];   //[nBToKMuMu]
   Int_t           BToKMuMu_kIdx[45];   //[nBToKMuMu]
   Int_t           BToKMuMu_l1Idx[45];   //[nBToKMuMu]
   Int_t           BToKMuMu_l2Idx[45];   //[nBToKMuMu]
   Int_t           BToKMuMu_n_k_used[45];   //[nBToKMuMu]
   Int_t           BToKMuMu_n_l1_used[45];   //[nBToKMuMu]
   Int_t           BToKMuMu_n_l2_used[45];   //[nBToKMuMu]
   Int_t           BToKMuMu_pdgId[45];   //[nBToKMuMu]
   UInt_t          nElectron;
   Float_t         Electron_dxy[500];   //[nElectron]
   Float_t         Electron_dxyErr[500];   //[nElectron]
   Float_t         Electron_dz[500];   //[nElectron]
   Float_t         Electron_dzErr[500];   //[nElectron]
   Float_t         Electron_eta[500];   //[nElectron]
   Float_t         Electron_fBrem[500];   //[nElectron]
   Float_t         Electron_ip3d[500];   //[nElectron]
   Float_t         Electron_mass[500];   //[nElectron]
   Float_t         Electron_mvaId[500];   //[nElectron]
   Float_t         Electron_pfRelIso[500];   //[nElectron]
   Float_t         Electron_pfmvaId[500];   //[nElectron]
   Float_t         Electron_phi[500];   //[nElectron]
   Float_t         Electron_pt[500];   //[nElectron]
   Float_t         Electron_ptBiased[500];   //[nElectron]
   Float_t         Electron_sip3d[500];   //[nElectron]
   Float_t         Electron_trkRelIso[500];   //[nElectron]
   Float_t         Electron_unBiased[500];   //[nElectron]
   Float_t         Electron_vx[500];   //[nElectron]
   Float_t         Electron_vy[500];   //[nElectron]
   Float_t         Electron_vz[500];   //[nElectron]
   Int_t           Electron_charge[500];   //[nElectron]
   Int_t           Electron_pdgId[500];   //[nElectron]
   Bool_t          Electron_convVeto[500];   //[nElectron]
   Bool_t          Electron_isLowPt[500];   //[nElectron]
   Bool_t          Electron_isPF[500];   //[nElectron]
   Bool_t          Electron_isPFoverlap[500];   //[nElectron]
   UInt_t          nGenPart;
   Float_t         GenPart_eta[500];   //[nGenPart]
   Float_t         GenPart_mass[500];   //[nGenPart]
   Float_t         GenPart_phi[500];   //[nGenPart]
   Float_t         GenPart_pt[500];   //[nGenPart]
   Float_t         GenPart_vx[500];   //[nGenPart]
   Float_t         GenPart_vy[500];   //[nGenPart]
   Float_t         GenPart_vz[500];   //[nGenPart]
   Int_t           GenPart_genPartIdxMother[500];   //[nGenPart]
   Int_t           GenPart_pdgId[500];   //[nGenPart]
   Int_t           GenPart_status[500];   //[nGenPart]
   Int_t           GenPart_statusFlags[500];   //[nGenPart]
   Float_t         Generator_binvar;
   Float_t         Generator_scalePDF;
   Float_t         Generator_weight;
   Float_t         Generator_x1;
   Float_t         Generator_x2;
   Float_t         Generator_xpdf1;
   Float_t         Generator_xpdf2;
   Int_t           Generator_id1;
   Int_t           Generator_id2;
   Float_t         genWeight;
   UInt_t          nPSWeight;
   Float_t         PSWeight[1];   //[nPSWeight]
   UInt_t          nMuon;
   Float_t         Muon_dxy[11];   //[nMuon]
   Float_t         Muon_dxyErr[11];   //[nMuon]
   Float_t         Muon_dz[11];   //[nMuon]
   Float_t         Muon_dzErr[11];   //[nMuon]
   Float_t         Muon_eta[11];   //[nMuon]
   Float_t         Muon_ip3d[11];   //[nMuon]
   Float_t         Muon_mass[11];   //[nMuon]
   Float_t         Muon_pfRelIso03_all[11];   //[nMuon]
   Float_t         Muon_pfRelIso04_all[11];   //[nMuon]
   Float_t         Muon_phi[11];   //[nMuon]
   Float_t         Muon_pt[11];   //[nMuon]
   Float_t         Muon_ptErr[11];   //[nMuon]
   Float_t         Muon_sip3d[11];   //[nMuon]
   Float_t         Muon_vx[11];   //[nMuon]
   Float_t         Muon_vy[11];   //[nMuon]
   Float_t         Muon_vz[11];   //[nMuon]
   Int_t           Muon_charge[11];   //[nMuon]
   Int_t           Muon_isTriggering[11];   //[nMuon]
   Int_t           Muon_pdgId[11];   //[nMuon]
   Bool_t          Muon_isGlobal[11];   //[nMuon]
   Bool_t          Muon_isPFcand[11];   //[nMuon]
   Bool_t          Muon_isTracker[11];   //[nMuon]
   Bool_t          Muon_mediumId[11];   //[nMuon]
   UChar_t         Muon_pfIsoId[11];   //[nMuon]
   Bool_t          Muon_softId[11];   //[nMuon]
   Bool_t          Muon_tightId[11];   //[nMuon]
   UChar_t         Muon_tkIsoId[11];   //[nMuon]
   Bool_t          Muon_triggerIdLoose[11];   //[nMuon]
   UInt_t          nTriggerMuon;
   Float_t         TriggerMuon_eta[3];   //[nTriggerMuon]
   Float_t         TriggerMuon_mass[3];   //[nTriggerMuon]
   Float_t         TriggerMuon_phi[3];   //[nTriggerMuon]
   Float_t         TriggerMuon_pt[3];   //[nTriggerMuon]
   Float_t         TriggerMuon_vx[3];   //[nTriggerMuon]
   Float_t         TriggerMuon_vy[3];   //[nTriggerMuon]
   Float_t         TriggerMuon_vz[3];   //[nTriggerMuon]
   Int_t           TriggerMuon_charge[3];   //[nTriggerMuon]
   Int_t           TriggerMuon_pdgId[3];   //[nTriggerMuon]
   Int_t           TriggerMuon_trgMuonIndex[3];   //[nTriggerMuon]
   Float_t         fixedGridRhoFastjetAll;
   Float_t         fixedGridRhoFastjetCentral;
   Float_t         fixedGridRhoFastjetCentralCalo;
   Float_t         fixedGridRhoFastjetCentralChargedPileUp;
   Float_t         fixedGridRhoFastjetCentralNeutral;
   UInt_t          nProbeTracks;
   Float_t         ProbeTracks_DCASig[318];   //[nProbeTracks]
   Float_t         ProbeTracks_dxy[318];   //[nProbeTracks]
   Float_t         ProbeTracks_dxyS[318];   //[nProbeTracks]
   Float_t         ProbeTracks_dz[318];   //[nProbeTracks]
   Float_t         ProbeTracks_dzS[318];   //[nProbeTracks]
   Float_t         ProbeTracks_eta[318];   //[nProbeTracks]
   Float_t         ProbeTracks_mass[318];   //[nProbeTracks]
   Float_t         ProbeTracks_phi[318];   //[nProbeTracks]
   Float_t         ProbeTracks_pt[318];   //[nProbeTracks]
   Float_t         ProbeTracks_vx[318];   //[nProbeTracks]
   Float_t         ProbeTracks_vy[318];   //[nProbeTracks]
   Float_t         ProbeTracks_vz[318];   //[nProbeTracks]
   Int_t           ProbeTracks_charge[318];   //[nProbeTracks]
   Int_t           ProbeTracks_isLostTrk[318];   //[nProbeTracks]
   Int_t           ProbeTracks_isPacked[318];   //[nProbeTracks]
   Int_t           ProbeTracks_nValidHits[318];   //[nProbeTracks]
   Int_t           ProbeTracks_pdgId[318];   //[nProbeTracks]
   Bool_t          ProbeTracks_isMatchedToEle[318];   //[nProbeTracks]
   Bool_t          ProbeTracks_isMatchedToLooseMuon[318];   //[nProbeTracks]
   Bool_t          ProbeTracks_isMatchedToMediumMuon[318];   //[nProbeTracks]
   Bool_t          ProbeTracks_isMatchedToMuon[318];   //[nProbeTracks]
   Bool_t          ProbeTracks_isMatchedToSoftMuon[318];   //[nProbeTracks]
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
   Float_t         TrigObj_pt[4];   //[nTrigObj]
   Float_t         TrigObj_eta[4];   //[nTrigObj]
   Float_t         TrigObj_phi[4];   //[nTrigObj]
   Float_t         TrigObj_l1pt[4];   //[nTrigObj]
   Float_t         TrigObj_l1pt_2[4];   //[nTrigObj]
   Float_t         TrigObj_l2pt[4];   //[nTrigObj]
   Int_t           TrigObj_id[4];   //[nTrigObj]
   Int_t           TrigObj_l1iso[4];   //[nTrigObj]
   Int_t           TrigObj_l1charge[4];   //[nTrigObj]
   Int_t           TrigObj_filterBits[4];   //[nTrigObj]
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
   Float_t         SV_dlen[13];   //[nSV]
   Float_t         SV_dlenSig[13];   //[nSV]
   Float_t         SV_pAngle[13];   //[nSV]
   Int_t           Electron_genPartIdx[500];   //[nElectron]
   Int_t           Electron_genPartFlav[500];   //[nElectron]
   Int_t           Muon_genPartIdx[5];   //[nMuon]
   Int_t           Muon_genPartFlav[5];   //[nMuon]
   Float_t         SV_chi2[13];   //[nSV]
   Float_t         SV_eta[13];   //[nSV]
   Float_t         SV_mass[13];   //[nSV]
   Float_t         SV_ndof[13];   //[nSV]
   Float_t         SV_phi[13];   //[nSV]
   Float_t         SV_pt[13];   //[nSV]
   Float_t         SV_x[13];   //[nSV]
   Float_t         SV_y[13];   //[nSV]
   Float_t         SV_z[13];   //[nSV]
   Int_t           ProbeTracks_genPartIdx[168];   //[nProbeTracks]

   // List of branches
   TBranch        *b_run;   //!
   TBranch        *b_luminosityBlock;   //!
   TBranch        *b_event;   //!
   TBranch        *b_nBToKEE;   //!
   TBranch        *b_BToKEE_b_iso03;   //!
   TBranch        *b_BToKEE_b_iso04;   //!
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
   TBranch        *b_BToKEE_k_iso03;   //!
   TBranch        *b_BToKEE_k_iso04;   //!
   TBranch        *b_BToKEE_l1_iso03;   //!
   TBranch        *b_BToKEE_l1_iso04;   //!
   TBranch        *b_BToKEE_l2_iso03;   //!
   TBranch        *b_BToKEE_l2_iso04;   //!
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
   TBranch        *b_BToKEE_n_k_used;   //!
   TBranch        *b_BToKEE_n_l1_used;   //!
   TBranch        *b_BToKEE_n_l2_used;   //!
   TBranch        *b_BToKEE_pdgId;   //!
   TBranch        *b_nBToKMuMu;   //!
   TBranch        *b_BToKMuMu_b_iso03;   //!
   TBranch        *b_BToKMuMu_b_iso04;   //!
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
   TBranch        *b_BToKMuMu_k_iso03;   //!
   TBranch        *b_BToKMuMu_k_iso04;   //!
   TBranch        *b_BToKMuMu_l1_iso03;   //!
   TBranch        *b_BToKMuMu_l1_iso04;   //!
   TBranch        *b_BToKMuMu_l2_iso03;   //!
   TBranch        *b_BToKMuMu_l2_iso04;   //!
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
   TBranch        *b_BToKMuMu_n_k_used;   //!
   TBranch        *b_BToKMuMu_n_l1_used;   //!
   TBranch        *b_BToKMuMu_n_l2_used;   //!
   TBranch        *b_BToKMuMu_pdgId;   //!
   TBranch        *b_nElectron;   //!
   TBranch        *b_Electron_dxy;   //!
   TBranch        *b_Electron_dxyErr;   //!
   TBranch        *b_Electron_dz;   //!
   TBranch        *b_Electron_dzErr;   //!
   TBranch        *b_Electron_eta;   //!
   TBranch        *b_Electron_fBrem;   //!
   TBranch        *b_Electron_ip3d;   //!
   TBranch        *b_Electron_mass;   //!
   TBranch        *b_Electron_mvaId;   //!
   TBranch        *b_Electron_pfRelIso;   //!
   TBranch        *b_Electron_pfmvaId;   //!
   TBranch        *b_Electron_phi;   //!
   TBranch        *b_Electron_pt;   //!
   TBranch        *b_Electron_ptBiased;   //!
   TBranch        *b_Electron_sip3d;   //!
   TBranch        *b_Electron_trkRelIso;   //!
   TBranch        *b_Electron_unBiased;   //!
   TBranch        *b_Electron_vx;   //!
   TBranch        *b_Electron_vy;   //!
   TBranch        *b_Electron_vz;   //!
   TBranch        *b_Electron_charge;   //!
   TBranch        *b_Electron_pdgId;   //!
   TBranch        *b_Electron_convVeto;   //!
   TBranch        *b_Electron_isLowPt;   //!
   TBranch        *b_Electron_isPF;   //!
   TBranch        *b_Electron_isPFoverlap;   //!
   TBranch        *b_nGenPart;   //!
   TBranch        *b_GenPart_eta;   //!
   TBranch        *b_GenPart_mass;   //!
   TBranch        *b_GenPart_phi;   //!
   TBranch        *b_GenPart_pt;   //!
   TBranch        *b_GenPart_vx;   //!
   TBranch        *b_GenPart_vy;   //!
   TBranch        *b_GenPart_vz;   //!
   TBranch        *b_GenPart_genPartIdxMother;   //!
   TBranch        *b_GenPart_pdgId;   //!
   TBranch        *b_GenPart_status;   //!
   TBranch        *b_GenPart_statusFlags;   //!
   TBranch        *b_Generator_binvar;   //!
   TBranch        *b_Generator_scalePDF;   //!
   TBranch        *b_Generator_weight;   //!
   TBranch        *b_Generator_x1;   //!
   TBranch        *b_Generator_x2;   //!
   TBranch        *b_Generator_xpdf1;   //!
   TBranch        *b_Generator_xpdf2;   //!
   TBranch        *b_Generator_id1;   //!
   TBranch        *b_Generator_id2;   //!
   TBranch        *b_genWeight;   //!
   TBranch        *b_nPSWeight;   //!
   TBranch        *b_PSWeight;   //!
   TBranch        *b_nMuon;   //!
   TBranch        *b_Muon_dxy;   //!
   TBranch        *b_Muon_dxyErr;   //!
   TBranch        *b_Muon_dz;   //!
   TBranch        *b_Muon_dzErr;   //!
   TBranch        *b_Muon_eta;   //!
   TBranch        *b_Muon_ip3d;   //!
   TBranch        *b_Muon_mass;   //!
   TBranch        *b_Muon_pfRelIso03_all;   //!
   TBranch        *b_Muon_pfRelIso04_all;   //!
   TBranch        *b_Muon_phi;   //!
   TBranch        *b_Muon_pt;   //!
   TBranch        *b_Muon_ptErr;   //!
   TBranch        *b_Muon_sip3d;   //!
   TBranch        *b_Muon_vx;   //!
   TBranch        *b_Muon_vy;   //!
   TBranch        *b_Muon_vz;   //!
   TBranch        *b_Muon_charge;   //!
   TBranch        *b_Muon_isTriggering;   //!
   TBranch        *b_Muon_pdgId;   //!
   TBranch        *b_Muon_isGlobal;   //!
   TBranch        *b_Muon_isPFcand;   //!
   TBranch        *b_Muon_isTracker;   //!
   TBranch        *b_Muon_mediumId;   //!
   TBranch        *b_Muon_pfIsoId;   //!
   TBranch        *b_Muon_softId;   //!
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
   TBranch        *b_ProbeTracks_nValidHits;   //!
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
   TBranch        *b_Electron_genPartIdx;   //!
   TBranch        *b_Electron_genPartFlav;   //!
   TBranch        *b_Muon_genPartIdx;   //!
   TBranch        *b_Muon_genPartFlav;   //!
   TBranch        *b_SV_chi2;   //!
   TBranch        *b_SV_eta;   //!
   TBranch        *b_SV_mass;   //!
   TBranch        *b_SV_ndof;   //!
   TBranch        *b_SV_phi;   //!
   TBranch        *b_SV_pt;   //!
   TBranch        *b_SV_x;   //!
   TBranch        *b_SV_y;   //!
   TBranch        *b_SV_z;   //!
   TBranch        *b_ProbeTracks_genPartIdx;   //!

   virtual void     Init(TTree *tree);
   bool             isMcB(int); 
   //float            BDT_score(int); 
};

#endif

