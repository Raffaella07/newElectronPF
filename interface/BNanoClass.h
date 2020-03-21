//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Sat Mar 21 11:22:07 2020 by ROOT version 6.12/07
// from TTree Events/Events
// found on file: /eos/cms/store/group/cmst3/group/bpark/BParkingNANO_2020Jan16/BuToKJpsi_Toee_Mufilter_SoftQCDnonD_TuneCP5_13TeV-pythia8-evtgen/crab_BuToKJpsi_Toee/200116_215618/0000/BParkNANO_mc_2020Jan16_2.root
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
   Float_t         BToKEE_b_iso03[317];   //[nBToKEE]
   Float_t         BToKEE_b_iso04[317];   //[nBToKEE]
   Float_t         BToKEE_cos2D[317];   //[nBToKEE]
   Float_t         BToKEE_eta[317];   //[nBToKEE]
   Float_t         BToKEE_fit_cos2D[317];   //[nBToKEE]
   Float_t         BToKEE_fit_eta[317];   //[nBToKEE]
   Float_t         BToKEE_fit_k_eta[317];   //[nBToKEE]
   Float_t         BToKEE_fit_k_phi[317];   //[nBToKEE]
   Float_t         BToKEE_fit_k_pt[317];   //[nBToKEE]
   Float_t         BToKEE_fit_l1_eta[317];   //[nBToKEE]
   Float_t         BToKEE_fit_l1_phi[317];   //[nBToKEE]
   Float_t         BToKEE_fit_l1_pt[317];   //[nBToKEE]
   Float_t         BToKEE_fit_l2_eta[317];   //[nBToKEE]
   Float_t         BToKEE_fit_l2_phi[317];   //[nBToKEE]
   Float_t         BToKEE_fit_l2_pt[317];   //[nBToKEE]
   Float_t         BToKEE_fit_mass[317];   //[nBToKEE]
   Float_t         BToKEE_fit_massErr[317];   //[nBToKEE]
   Float_t         BToKEE_fit_phi[317];   //[nBToKEE]
   Float_t         BToKEE_fit_pt[317];   //[nBToKEE]
   Float_t         BToKEE_k_iso03[317];   //[nBToKEE]
   Float_t         BToKEE_k_iso04[317];   //[nBToKEE]
   Float_t         BToKEE_l1_iso03[317];   //[nBToKEE]
   Float_t         BToKEE_l1_iso04[317];   //[nBToKEE]
   Float_t         BToKEE_l2_iso03[317];   //[nBToKEE]
   Float_t         BToKEE_l2_iso04[317];   //[nBToKEE]
   Float_t         BToKEE_l_xy[317];   //[nBToKEE]
   Float_t         BToKEE_l_xy_unc[317];   //[nBToKEE]
   Float_t         BToKEE_mass[317];   //[nBToKEE]
   Float_t         BToKEE_maxDR[317];   //[nBToKEE]
   Float_t         BToKEE_minDR[317];   //[nBToKEE]
   Float_t         BToKEE_mllErr_llfit[317];   //[nBToKEE]
   Float_t         BToKEE_mll_fullfit[317];   //[nBToKEE]
   Float_t         BToKEE_mll_llfit[317];   //[nBToKEE]
   Float_t         BToKEE_mll_raw[317];   //[nBToKEE]
   Float_t         BToKEE_phi[317];   //[nBToKEE]
   Float_t         BToKEE_pt[317];   //[nBToKEE]
   Float_t         BToKEE_svprob[317];   //[nBToKEE]
   Float_t         BToKEE_vtx_ex[317];   //[nBToKEE]
   Float_t         BToKEE_vtx_ey[317];   //[nBToKEE]
   Float_t         BToKEE_vtx_ez[317];   //[nBToKEE]
   Float_t         BToKEE_vtx_x[317];   //[nBToKEE]
   Float_t         BToKEE_vtx_y[317];   //[nBToKEE]
   Float_t         BToKEE_vtx_z[317];   //[nBToKEE]
   Int_t           BToKEE_charge[317];   //[nBToKEE]
   Int_t           BToKEE_kIdx[317];   //[nBToKEE]
   Int_t           BToKEE_l1Idx[317];   //[nBToKEE]
   Int_t           BToKEE_l2Idx[317];   //[nBToKEE]
   Int_t           BToKEE_n_k_used[317];   //[nBToKEE]
   Int_t           BToKEE_n_l1_used[317];   //[nBToKEE]
   Int_t           BToKEE_n_l2_used[317];   //[nBToKEE]
   Int_t           BToKEE_pdgId[317];   //[nBToKEE]
   UInt_t          nBToKMuMu;
   Float_t         BToKMuMu_b_iso03[10];   //[nBToKMuMu]
   Float_t         BToKMuMu_b_iso04[10];   //[nBToKMuMu]
   Float_t         BToKMuMu_cos2D[10];   //[nBToKMuMu]
   Float_t         BToKMuMu_eta[10];   //[nBToKMuMu]
   Float_t         BToKMuMu_fit_cos2D[10];   //[nBToKMuMu]
   Float_t         BToKMuMu_fit_eta[10];   //[nBToKMuMu]
   Float_t         BToKMuMu_fit_k_eta[10];   //[nBToKMuMu]
   Float_t         BToKMuMu_fit_k_phi[10];   //[nBToKMuMu]
   Float_t         BToKMuMu_fit_k_pt[10];   //[nBToKMuMu]
   Float_t         BToKMuMu_fit_l1_eta[10];   //[nBToKMuMu]
   Float_t         BToKMuMu_fit_l1_phi[10];   //[nBToKMuMu]
   Float_t         BToKMuMu_fit_l1_pt[10];   //[nBToKMuMu]
   Float_t         BToKMuMu_fit_l2_eta[10];   //[nBToKMuMu]
   Float_t         BToKMuMu_fit_l2_phi[10];   //[nBToKMuMu]
   Float_t         BToKMuMu_fit_l2_pt[10];   //[nBToKMuMu]
   Float_t         BToKMuMu_fit_mass[10];   //[nBToKMuMu]
   Float_t         BToKMuMu_fit_massErr[10];   //[nBToKMuMu]
   Float_t         BToKMuMu_fit_phi[10];   //[nBToKMuMu]
   Float_t         BToKMuMu_fit_pt[10];   //[nBToKMuMu]
   Float_t         BToKMuMu_k_iso03[10];   //[nBToKMuMu]
   Float_t         BToKMuMu_k_iso04[10];   //[nBToKMuMu]
   Float_t         BToKMuMu_l1_iso03[10];   //[nBToKMuMu]
   Float_t         BToKMuMu_l1_iso04[10];   //[nBToKMuMu]
   Float_t         BToKMuMu_l2_iso03[10];   //[nBToKMuMu]
   Float_t         BToKMuMu_l2_iso04[10];   //[nBToKMuMu]
   Float_t         BToKMuMu_l_xy[10];   //[nBToKMuMu]
   Float_t         BToKMuMu_l_xy_unc[10];   //[nBToKMuMu]
   Float_t         BToKMuMu_mass[10];   //[nBToKMuMu]
   Float_t         BToKMuMu_maxDR[10];   //[nBToKMuMu]
   Float_t         BToKMuMu_minDR[10];   //[nBToKMuMu]
   Float_t         BToKMuMu_mllErr_llfit[10];   //[nBToKMuMu]
   Float_t         BToKMuMu_mll_fullfit[10];   //[nBToKMuMu]
   Float_t         BToKMuMu_mll_llfit[10];   //[nBToKMuMu]
   Float_t         BToKMuMu_mll_raw[10];   //[nBToKMuMu]
   Float_t         BToKMuMu_phi[10];   //[nBToKMuMu]
   Float_t         BToKMuMu_pt[10];   //[nBToKMuMu]
   Float_t         BToKMuMu_svprob[10];   //[nBToKMuMu]
   Float_t         BToKMuMu_vtx_ex[10];   //[nBToKMuMu]
   Float_t         BToKMuMu_vtx_ey[10];   //[nBToKMuMu]
   Float_t         BToKMuMu_vtx_ez[10];   //[nBToKMuMu]
   Float_t         BToKMuMu_vtx_x[10];   //[nBToKMuMu]
   Float_t         BToKMuMu_vtx_y[10];   //[nBToKMuMu]
   Float_t         BToKMuMu_vtx_z[10];   //[nBToKMuMu]
   Int_t           BToKMuMu_charge[10];   //[nBToKMuMu]
   Int_t           BToKMuMu_kIdx[10];   //[nBToKMuMu]
   Int_t           BToKMuMu_l1Idx[10];   //[nBToKMuMu]
   Int_t           BToKMuMu_l2Idx[10];   //[nBToKMuMu]
   Int_t           BToKMuMu_n_k_used[10];   //[nBToKMuMu]
   Int_t           BToKMuMu_n_l1_used[10];   //[nBToKMuMu]
   Int_t           BToKMuMu_n_l2_used[10];   //[nBToKMuMu]
   Int_t           BToKMuMu_pdgId[10];   //[nBToKMuMu]
   UInt_t          nElectron;
   Float_t         Electron_dxy[50];   //[nElectron]
   Float_t         Electron_dxyErr[50];   //[nElectron]
   Float_t         Electron_dz[50];   //[nElectron]
   Float_t         Electron_dzErr[50];   //[nElectron]
   Float_t         Electron_eta[50];   //[nElectron]
   Float_t         Electron_fBrem[50];   //[nElectron]
   Float_t         Electron_ip3d[50];   //[nElectron]
   Float_t         Electron_mass[50];   //[nElectron]
   Float_t         Electron_mvaId[50];   //[nElectron]
   Float_t         Electron_pfRelIso[50];   //[nElectron]
   Float_t         Electron_pfmvaId[50];   //[nElectron]
   Float_t         Electron_phi[50];   //[nElectron]
   Float_t         Electron_pt[50];   //[nElectron]
   Float_t         Electron_ptBiased[50];   //[nElectron]
   Float_t         Electron_sip3d[50];   //[nElectron]
   Float_t         Electron_trkRelIso[50];   //[nElectron]
   Float_t         Electron_unBiased[50];   //[nElectron]
   Float_t         Electron_vx[50];   //[nElectron]
   Float_t         Electron_vy[50];   //[nElectron]
   Float_t         Electron_vz[50];   //[nElectron]
   Int_t           Electron_charge[50];   //[nElectron]
   Int_t           Electron_pdgId[50];   //[nElectron]
   Bool_t          Electron_convVeto[50];   //[nElectron]
   Bool_t          Electron_isLowPt[50];   //[nElectron]
   Bool_t          Electron_isPF[50];   //[nElectron]
   Bool_t          Electron_isPFoverlap[50];   //[nElectron]
   UInt_t          nGenPart;
   Float_t         GenPart_eta[103];   //[nGenPart]
   Float_t         GenPart_mass[103];   //[nGenPart]
   Float_t         GenPart_phi[103];   //[nGenPart]
   Float_t         GenPart_pt[103];   //[nGenPart]
   Float_t         GenPart_vx[103];   //[nGenPart]
   Float_t         GenPart_vy[103];   //[nGenPart]
   Float_t         GenPart_vz[103];   //[nGenPart]
   Int_t           GenPart_genPartIdxMother[103];   //[nGenPart]
   Int_t           GenPart_pdgId[103];   //[nGenPart]
   Int_t           GenPart_status[103];   //[nGenPart]
   Int_t           GenPart_statusFlags[103];   //[nGenPart]
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
   Float_t         Muon_dxy[5];   //[nMuon]
   Float_t         Muon_dxyErr[5];   //[nMuon]
   Float_t         Muon_dz[5];   //[nMuon]
   Float_t         Muon_dzErr[5];   //[nMuon]
   Float_t         Muon_eta[5];   //[nMuon]
   Float_t         Muon_ip3d[5];   //[nMuon]
   Float_t         Muon_mass[5];   //[nMuon]
   Float_t         Muon_pfRelIso03_all[5];   //[nMuon]
   Float_t         Muon_pfRelIso04_all[5];   //[nMuon]
   Float_t         Muon_phi[5];   //[nMuon]
   Float_t         Muon_pt[5];   //[nMuon]
   Float_t         Muon_ptErr[5];   //[nMuon]
   Float_t         Muon_sip3d[5];   //[nMuon]
   Float_t         Muon_vx[5];   //[nMuon]
   Float_t         Muon_vy[5];   //[nMuon]
   Float_t         Muon_vz[5];   //[nMuon]
   Int_t           Muon_charge[5];   //[nMuon]
   Int_t           Muon_isTriggering[5];   //[nMuon]
   Int_t           Muon_pdgId[5];   //[nMuon]
   Bool_t          Muon_isGlobal[5];   //[nMuon]
   Bool_t          Muon_isPFcand[5];   //[nMuon]
   Bool_t          Muon_isTracker[5];   //[nMuon]
   Bool_t          Muon_mediumId[5];   //[nMuon]
   UChar_t         Muon_pfIsoId[5];   //[nMuon]
   Bool_t          Muon_softId[5];   //[nMuon]
   Bool_t          Muon_tightId[5];   //[nMuon]
   UChar_t         Muon_tkIsoId[5];   //[nMuon]
   Bool_t          Muon_triggerIdLoose[5];   //[nMuon]
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
   Float_t         Pileup_nTrueInt;
   Float_t         Pileup_pudensity;
   Float_t         Pileup_gpudensity;
   Int_t           Pileup_nPU;
   Int_t           Pileup_sumEOOT;
   Int_t           Pileup_sumLOOT;
   Float_t         fixedGridRhoFastjetAll;
   Float_t         fixedGridRhoFastjetCentral;
   Float_t         fixedGridRhoFastjetCentralCalo;
   Float_t         fixedGridRhoFastjetCentralChargedPileUp;
   Float_t         fixedGridRhoFastjetCentralNeutral;
   UInt_t          nProbeTracks;
   Float_t         ProbeTracks_DCASig[179];   //[nProbeTracks]
   Float_t         ProbeTracks_dxy[179];   //[nProbeTracks]
   Float_t         ProbeTracks_dxyS[179];   //[nProbeTracks]
   Float_t         ProbeTracks_dz[179];   //[nProbeTracks]
   Float_t         ProbeTracks_dzS[179];   //[nProbeTracks]
   Float_t         ProbeTracks_eta[179];   //[nProbeTracks]
   Float_t         ProbeTracks_mass[179];   //[nProbeTracks]
   Float_t         ProbeTracks_phi[179];   //[nProbeTracks]
   Float_t         ProbeTracks_pt[179];   //[nProbeTracks]
   Float_t         ProbeTracks_vx[179];   //[nProbeTracks]
   Float_t         ProbeTracks_vy[179];   //[nProbeTracks]
   Float_t         ProbeTracks_vz[179];   //[nProbeTracks]
   Int_t           ProbeTracks_charge[179];   //[nProbeTracks]
   Int_t           ProbeTracks_isLostTrk[179];   //[nProbeTracks]
   Int_t           ProbeTracks_isPacked[179];   //[nProbeTracks]
   Int_t           ProbeTracks_nValidHits[179];   //[nProbeTracks]
   Int_t           ProbeTracks_pdgId[179];   //[nProbeTracks]
   Bool_t          ProbeTracks_isMatchedToEle[179];   //[nProbeTracks]
   Bool_t          ProbeTracks_isMatchedToLooseMuon[179];   //[nProbeTracks]
   Bool_t          ProbeTracks_isMatchedToMediumMuon[179];   //[nProbeTracks]
   Bool_t          ProbeTracks_isMatchedToMuon[179];   //[nProbeTracks]
   Bool_t          ProbeTracks_isMatchedToSoftMuon[179];   //[nProbeTracks]
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
   Float_t         SV_dlen[7];   //[nSV]
   Float_t         SV_dlenSig[7];   //[nSV]
   Float_t         SV_pAngle[7];   //[nSV]
   Int_t           Electron_genPartIdx[50];   //[nElectron]
   Int_t           Electron_genPartFlav[50];   //[nElectron]
   Int_t           Muon_genPartIdx[5];   //[nMuon]
   Int_t           Muon_genPartFlav[5];   //[nMuon]
   Float_t         SV_chi2[7];   //[nSV]
   Float_t         SV_eta[7];   //[nSV]
   Float_t         SV_mass[7];   //[nSV]
   Float_t         SV_ndof[7];   //[nSV]
   Float_t         SV_phi[7];   //[nSV]
   Float_t         SV_pt[7];   //[nSV]
   Float_t         SV_x[7];   //[nSV]
   Float_t         SV_y[7];   //[nSV]
   Float_t         SV_z[7];   //[nSV]
   Int_t           ProbeTracks_genPartIdx[179];   //[nProbeTracks]
   Int_t           ProbeTracks_genPartFlav[179];   //[nProbeTracks]

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
   TBranch        *b_Pileup_nTrueInt;   //!
   TBranch        *b_Pileup_pudensity;   //!
   TBranch        *b_Pileup_gpudensity;   //!
   TBranch        *b_Pileup_nPU;   //!
   TBranch        *b_Pileup_sumEOOT;   //!
   TBranch        *b_Pileup_sumLOOT;   //!
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
   TBranch        *b_ProbeTracks_genPartFlav;   //!

   virtual void     Init(TTree *tree);
   bool             isMcB(int); 
};

#endif

