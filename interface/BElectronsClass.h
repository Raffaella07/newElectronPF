//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Wed Jan 22 11:26:09 2020 by ROOT version 6.12/07
// from TTree Events/Events
// found on file: ../PhysicsTools/BParkingNano/test/BParkNANO_mc_2020Jan16.root
//////////////////////////////////////////////////////////

//#ifndef BElectronsClass_h
#define BElectronsClass_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.

class BElectronsClass {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

// Fixed size dimensions of array or collections stored in the TTree if any.

   // Declaration of leaf types
   UInt_t          run;
   UInt_t          luminosityBlock;
   ULong64_t       event;
   UInt_t          nBToKEE;
   Float_t         BToKEE_b_iso03[550];   //[nBToKEE]
   Float_t         BToKEE_b_iso04[550];   //[nBToKEE]
   Float_t         BToKEE_cos2D[550];   //[nBToKEE]
   Float_t         BToKEE_eta[550];   //[nBToKEE]
   Float_t         BToKEE_fit_cos2D[550];   //[nBToKEE]
   Float_t         BToKEE_fit_eta[550];   //[nBToKEE]
   Float_t         BToKEE_fit_k_eta[550];   //[nBToKEE]
   Float_t         BToKEE_fit_k_phi[550];   //[nBToKEE]
   Float_t         BToKEE_fit_k_pt[550];   //[nBToKEE]
   Float_t         BToKEE_fit_l1_eta[550];   //[nBToKEE]
   Float_t         BToKEE_fit_l1_phi[550];   //[nBToKEE]
   Float_t         BToKEE_fit_l1_pt[550];   //[nBToKEE]
   Float_t         BToKEE_fit_l2_eta[550];   //[nBToKEE]
   Float_t         BToKEE_fit_l2_phi[550];   //[nBToKEE]
   Float_t         BToKEE_fit_l2_pt[550];   //[nBToKEE]
   Float_t         BToKEE_fit_mass[550];   //[nBToKEE]
   Float_t         BToKEE_fit_massErr[550];   //[nBToKEE]
   Float_t         BToKEE_fit_phi[550];   //[nBToKEE]
   Float_t         BToKEE_fit_pt[550];   //[nBToKEE]
   Float_t         BToKEE_k_iso03[550];   //[nBToKEE]
   Float_t         BToKEE_k_iso04[550];   //[nBToKEE]
   Float_t         BToKEE_l1_iso03[550];   //[nBToKEE]
   Float_t         BToKEE_l1_iso04[550];   //[nBToKEE]
   Float_t         BToKEE_l2_iso03[550];   //[nBToKEE]
   Float_t         BToKEE_l2_iso04[550];   //[nBToKEE]
   Float_t         BToKEE_l_xy[550];   //[nBToKEE]
   Float_t         BToKEE_l_xy_unc[550];   //[nBToKEE]
   Float_t         BToKEE_mass[550];   //[nBToKEE]
   Float_t         BToKEE_maxDR[550];   //[nBToKEE]
   Float_t         BToKEE_minDR[550];   //[nBToKEE]
   Float_t         BToKEE_mllErr_llfit[550];   //[nBToKEE]
   Float_t         BToKEE_mll_fullfit[550];   //[nBToKEE]
   Float_t         BToKEE_mll_llfit[550];   //[nBToKEE]
   Float_t         BToKEE_mll_raw[550];   //[nBToKEE]
   Float_t         BToKEE_phi[550];   //[nBToKEE]
   Float_t         BToKEE_pt[550];   //[nBToKEE]
   Float_t         BToKEE_svprob[550];   //[nBToKEE]
   Float_t         BToKEE_vtx_ex[550];   //[nBToKEE]
   Float_t         BToKEE_vtx_ey[550];   //[nBToKEE]
   Float_t         BToKEE_vtx_ez[550];   //[nBToKEE]
   Float_t         BToKEE_vtx_x[550];   //[nBToKEE]
   Float_t         BToKEE_vtx_y[550];   //[nBToKEE]
   Float_t         BToKEE_vtx_z[550];   //[nBToKEE]
   Int_t           BToKEE_charge[550];   //[nBToKEE]
   Int_t           BToKEE_kIdx[550];   //[nBToKEE]
   Int_t           BToKEE_l1Idx[550];   //[nBToKEE]
   Int_t           BToKEE_l2Idx[550];   //[nBToKEE]
   Int_t           BToKEE_n_k_used[550];   //[nBToKEE]
   Int_t           BToKEE_n_l1_used[550];   //[nBToKEE]
   Int_t           BToKEE_n_l2_used[550];   //[nBToKEE]
   Int_t           BToKEE_pdgId[550];   //[nBToKEE]
   UInt_t          nBToKMuMu;
   Float_t         BToKMuMu_b_iso03[58];   //[nBToKMuMu]
   Float_t         BToKMuMu_b_iso04[58];   //[nBToKMuMu]
   Float_t         BToKMuMu_cos2D[58];   //[nBToKMuMu]
   Float_t         BToKMuMu_eta[58];   //[nBToKMuMu]
   Float_t         BToKMuMu_fit_cos2D[58];   //[nBToKMuMu]
   Float_t         BToKMuMu_fit_eta[58];   //[nBToKMuMu]
   Float_t         BToKMuMu_fit_k_eta[58];   //[nBToKMuMu]
   Float_t         BToKMuMu_fit_k_phi[58];   //[nBToKMuMu]
   Float_t         BToKMuMu_fit_k_pt[58];   //[nBToKMuMu]
   Float_t         BToKMuMu_fit_l1_eta[58];   //[nBToKMuMu]
   Float_t         BToKMuMu_fit_l1_phi[58];   //[nBToKMuMu]
   Float_t         BToKMuMu_fit_l1_pt[58];   //[nBToKMuMu]
   Float_t         BToKMuMu_fit_l2_eta[58];   //[nBToKMuMu]
   Float_t         BToKMuMu_fit_l2_phi[58];   //[nBToKMuMu]
   Float_t         BToKMuMu_fit_l2_pt[58];   //[nBToKMuMu]
   Float_t         BToKMuMu_fit_mass[58];   //[nBToKMuMu]
   Float_t         BToKMuMu_fit_massErr[58];   //[nBToKMuMu]
   Float_t         BToKMuMu_fit_phi[58];   //[nBToKMuMu]
   Float_t         BToKMuMu_fit_pt[58];   //[nBToKMuMu]
   Float_t         BToKMuMu_k_iso03[58];   //[nBToKMuMu]
   Float_t         BToKMuMu_k_iso04[58];   //[nBToKMuMu]
   Float_t         BToKMuMu_l1_iso03[58];   //[nBToKMuMu]
   Float_t         BToKMuMu_l1_iso04[58];   //[nBToKMuMu]
   Float_t         BToKMuMu_l2_iso03[58];   //[nBToKMuMu]
   Float_t         BToKMuMu_l2_iso04[58];   //[nBToKMuMu]
   Float_t         BToKMuMu_l_xy[58];   //[nBToKMuMu]
   Float_t         BToKMuMu_l_xy_unc[58];   //[nBToKMuMu]
   Float_t         BToKMuMu_mass[58];   //[nBToKMuMu]
   Float_t         BToKMuMu_maxDR[58];   //[nBToKMuMu]
   Float_t         BToKMuMu_minDR[58];   //[nBToKMuMu]
   Float_t         BToKMuMu_mllErr_llfit[58];   //[nBToKMuMu]
   Float_t         BToKMuMu_mll_fullfit[58];   //[nBToKMuMu]
   Float_t         BToKMuMu_mll_llfit[58];   //[nBToKMuMu]
   Float_t         BToKMuMu_mll_raw[58];   //[nBToKMuMu]
   Float_t         BToKMuMu_phi[58];   //[nBToKMuMu]
   Float_t         BToKMuMu_pt[58];   //[nBToKMuMu]
   Float_t         BToKMuMu_svprob[58];   //[nBToKMuMu]
   Float_t         BToKMuMu_vtx_ex[58];   //[nBToKMuMu]
   Float_t         BToKMuMu_vtx_ey[58];   //[nBToKMuMu]
   Float_t         BToKMuMu_vtx_ez[58];   //[nBToKMuMu]
   Float_t         BToKMuMu_vtx_x[58];   //[nBToKMuMu]
   Float_t         BToKMuMu_vtx_y[58];   //[nBToKMuMu]
   Float_t         BToKMuMu_vtx_z[58];   //[nBToKMuMu]
   Int_t           BToKMuMu_charge[58];   //[nBToKMuMu]
   Int_t           BToKMuMu_kIdx[58];   //[nBToKMuMu]
   Int_t           BToKMuMu_l1Idx[58];   //[nBToKMuMu]
   Int_t           BToKMuMu_l2Idx[58];   //[nBToKMuMu]
   Int_t           BToKMuMu_n_k_used[58];   //[nBToKMuMu]
   Int_t           BToKMuMu_n_l1_used[58];   //[nBToKMuMu]
   Int_t           BToKMuMu_n_l2_used[58];   //[nBToKMuMu]
   Int_t           BToKMuMu_pdgId[58];   //[nBToKMuMu]
   UInt_t          nElectron;
   Float_t         Electron_dxy[69];   //[nElectron]
   Float_t         Electron_dxyErr[69];   //[nElectron]
   Float_t         Electron_dz[69];   //[nElectron]
   Float_t         Electron_dzErr[69];   //[nElectron]
   Float_t         Electron_eta[69];   //[nElectron]
   Float_t         Electron_fBrem[69];   //[nElectron]
   Float_t         Electron_ip3d[69];   //[nElectron]
   Float_t         Electron_mass[69];   //[nElectron]
   Float_t         Electron_mvaId[69];   //[nElectron]
   Float_t         Electron_pfRelIso[69];   //[nElectron]
   Float_t         Electron_pfmvaId[69];   //[nElectron]
   Float_t         Electron_phi[69];   //[nElectron]
   Float_t         Electron_pt[69];   //[nElectron]
   Float_t         Electron_ptBiased[69];   //[nElectron]
   Float_t         Electron_sip3d[69];   //[nElectron]
   Float_t         Electron_trkRelIso[69];   //[nElectron]
   Float_t         Electron_unBiased[69];   //[nElectron]
   Float_t         Electron_vx[69];   //[nElectron]
   Float_t         Electron_vy[69];   //[nElectron]
   Float_t         Electron_vz[69];   //[nElectron]
   Int_t           Electron_charge[69];   //[nElectron]
   Int_t           Electron_pdgId[69];   //[nElectron]
   Bool_t          Electron_convVeto[69];   //[nElectron]
   Bool_t          Electron_isLowPt[69];   //[nElectron]
   Bool_t          Electron_isPF[69];   //[nElectron]
   Bool_t          Electron_isPFoverlap[69];   //[nElectron]
 // UInt_t          nGenPart;
 // Float_t         GenPart_eta[136];   //[nGenPart]
 // Float_t         GenPart_mass[136];   //[nGenPart]
 // Float_t         GenPart_phi[136];   //[nGenPart]
 // Float_t         GenPart_pt[136];   //[nGenPart]
 // Float_t         GenPart_vx[136];   //[nGenPart]
 // Float_t         GenPart_vy[136];   //[nGenPart]
 // Float_t         GenPart_vz[136];   //[nGenPart]
 // Int_t           GenPart_genPartIdxMother[136];   //[nGenPart]
 // Int_t           GenPart_pdgId[136];   //[nGenPart]
 // Int_t           GenPart_status[136];   //[nGenPart]
 // Int_t           GenPart_statusFlags[136];   //[nGenPart]
 // Float_t         Generator_binvar;
 // Float_t         Generator_scalePDF;
 // Float_t         Generator_weight;
 // Float_t         Generator_x1;
 // Float_t         Generator_x2;
 // Float_t         Generator_xpdf1;
 // Float_t         Generator_xpdf2;
 // Int_t           Generator_id1;
 // Int_t           Generator_id2;
 // Float_t         genWeight;
 // UInt_t          nPSWeight;
 // Float_t         PSWeight[1];   //[nPSWeight]
   UInt_t          nMuon;
   Float_t         Muon_dxy[8];   //[nMuon]
   Float_t         Muon_dxyErr[8];   //[nMuon]
   Float_t         Muon_dz[8];   //[nMuon]
   Float_t         Muon_dzErr[8];   //[nMuon]
   Float_t         Muon_eta[8];   //[nMuon]
   Float_t         Muon_ip3d[8];   //[nMuon]
   Float_t         Muon_mass[8];   //[nMuon]
   Float_t         Muon_pfRelIso03_all[8];   //[nMuon]
   Float_t         Muon_pfRelIso04_all[8];   //[nMuon]
   Float_t         Muon_phi[8];   //[nMuon]
   Float_t         Muon_pt[8];   //[nMuon]
   Float_t         Muon_ptErr[8];   //[nMuon]
   Float_t         Muon_sip3d[8];   //[nMuon]
   Float_t         Muon_vx[8];   //[nMuon]
   Float_t         Muon_vy[8];   //[nMuon]
   Float_t         Muon_vz[8];   //[nMuon]
   Int_t           Muon_charge[8];   //[nMuon]
   Int_t           Muon_isTriggering[8];   //[nMuon]
   Int_t           Muon_pdgId[8];   //[nMuon]
   Bool_t          Muon_isGlobal[8];   //[nMuon]
   Bool_t          Muon_isPFcand[8];   //[nMuon]
   Bool_t          Muon_isTracker[8];   //[nMuon]
   Bool_t          Muon_mediumId[8];   //[nMuon]
   UChar_t         Muon_pfIsoId[8];   //[nMuon]
   Bool_t          Muon_softId[8];   //[nMuon]
   Bool_t          Muon_tightId[8];   //[nMuon]
   UChar_t         Muon_tkIsoId[8];   //[nMuon]
   Bool_t          Muon_triggerIdLoose[8];   //[nMuon]
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
 //  Float_t         Pileup_nTrueInt;
 //   Float_t         Pileup_pudensity;
 //   Float_t         Pileup_gpudensity;
 //   Int_t           Pileup_nPU;
 //  Int_t           Pileup_sumEOOT;
 //  Int_t           Pileup_sumLOOT;
    Float_t         fixedGridRhoFastjetAll;
    Float_t         fixedGridRhoFastjetCentral;
    Float_t         fixedGridRhoFastjetCentralCalo;
    Float_t         fixedGridRhoFastjetCentralChargedPileUp;
    Float_t         fixedGridRhoFastjetCentralNeutral;
    UInt_t          nProbeTracks;
    Float_t         ProbeTracks_DCASig[246];   //[nProbeTracks]
    Float_t         ProbeTracks_dxy[246];   //[nProbeTracks]
    Float_t         ProbeTracks_dxyS[246];   //[nProbeTracks]
    Float_t         ProbeTracks_dz[246];   //[nProbeTracks]
    Float_t         ProbeTracks_dzS[246];   //[nProbeTracks]
    Float_t         ProbeTracks_eta[246];   //[nProbeTracks]
    Float_t         ProbeTracks_mass[246];   //[nProbeTracks]
    Float_t         ProbeTracks_phi[246];   //[nProbeTracks]
    Float_t         ProbeTracks_pt[246];   //[nProbeTracks]
    Float_t         ProbeTracks_vx[246];   //[nProbeTracks]
    Float_t         ProbeTracks_vy[246];   //[nProbeTracks]
   Float_t         ProbeTracks_vz[246];   //[nProbeTracks]
   Int_t           ProbeTracks_charge[246];   //[nProbeTracks]
   Int_t           ProbeTracks_isLostTrk[246];   //[nProbeTracks]
   Int_t           ProbeTracks_isPacked[246];   //[nProbeTracks]
   Int_t           ProbeTracks_nValidHits[246];   //[nProbeTracks]
   Int_t           ProbeTracks_pdgId[246];   //[nProbeTracks]
   Bool_t          ProbeTracks_isMatchedToEle[246];   //[nProbeTracks]
   Bool_t          ProbeTracks_isMatchedToLooseMuon[246];   //[nProbeTracks]
   Bool_t          ProbeTracks_isMatchedToMediumMuon[246];   //[nProbeTracks]
   Bool_t          ProbeTracks_isMatchedToMuon[246];   //[nProbeTracks]
   Bool_t          ProbeTracks_isMatchedToSoftMuon[246];   //[nProbeTracks]
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
   Float_t         SV_dlen[9];   //[nSV]
   Float_t         SV_dlenSig[9];   //[nSV]
   Float_t         SV_pAngle[9];   //[nSV]
 //  Int_t           Electron_genPartIdx[69];   //[nElectron]
 //  Int_t           Electron_genPartFlav[69];   //[nElectron]
 //  Int_t           Muon_genPartIdx[8];   //[nMuon]
 //  Int_t           Muon_genPartFlav[8];   //[nMuon]
   Float_t         SV_chi2[9];   //[nSV]
   Float_t         SV_eta[9];   //[nSV]
   Float_t         SV_mass[9];   //[nSV]
   Float_t         SV_ndof[9];   //[nSV]
   Float_t         SV_phi[9];   //[nSV]
   Float_t         SV_pt[9];   //[nSV]
   Float_t         SV_x[9];   //[nSV]
   Float_t         SV_y[9];   //[nSV]
   Float_t         SV_z[9];   //[nSV]
 //  Int_t           ProbeTracks_genPartIdx[246];   //[nProbeTracks]
 //  Int_t           ProbeTracks_genPartFlav[246];   //[nProbeTracks]

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
 // TBranch        *b_nGenPart;   //!
 // TBranch        *b_GenPart_eta;   //!
 // TBranch        *b_GenPart_mass;   //!
 // TBranch        *b_GenPart_phi;   //!
 // TBranch        *b_GenPart_pt;   //!
 // TBranch        *b_GenPart_vx;   //!
 // TBranch        *b_GenPart_vy;   //!
 // TBranch        *b_GenPart_vz;   //!
 // TBranch        *b_GenPart_genPartIdxMother;   //!
 // TBranch        *b_GenPart_pdgId;   //!
 // TBranch        *b_GenPart_status;   //!
 // TBranch        *b_GenPart_statusFlags;   //!
 // TBranch        *b_Generator_binvar;   //!
 // TBranch        *b_Generator_scalePDF;   //!
 // TBranch        *b_Generator_weight;   //!
 // TBranch        *b_Generator_x1;   //!
 // TBranch        *b_Generator_x2;   //!
 // TBranch        *b_Generator_xpdf1;   //!
 // TBranch        *b_Generator_xpdf2;   //!
 // TBranch        *b_Generator_id1;   //!
 // TBranch        *b_Generator_id2;   //!
 // TBranch        *b_genWeight;   //!
 // TBranch        *b_nPSWeight;   //!
 // TBranch        *b_PSWeight;   //!
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
 //  TBranch        *b_Pileup_nTrueInt;   //!
 // TBranch        *b_Pileup_pudensity;   //!
 // TBranch        *b_Pileup_gpudensity;   //!
 // TBranch        *b_Pileup_nPU;   //!
 // TBranch        *b_Pileup_sumEOOT;   //!
 // TBranch        *b_Pileup_sumLOOT;   //!
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
 //  TBranch        *b_Electron_genPartIdx;   //!
 //  TBranch        *b_Electron_genPartFlav;   //!
  // TBranch        *b_Muon_genPartIdx;   //!
 //  TBranch        *b_Muon_genPartFlav;   //!
   TBranch        *b_SV_chi2;   //!
   TBranch        *b_SV_eta;   //!
   TBranch        *b_SV_mass;   //!
   TBranch        *b_SV_ndof;   //!
   TBranch        *b_SV_phi;   //!
   TBranch        *b_SV_pt;   //!
   TBranch        *b_SV_x;   //!
   TBranch        *b_SV_y;   //!
   TBranch        *b_SV_z;   //!
 //  TBranch        *b_ProbeTracks_genPartIdx;   //!
//   TBranch        *b_ProbeTracks_genPartFlav;   //!

  // BElectronsClass(TTree *tree=0);
  // virtual ~BElectronsClass();
  // virtual Int_t    Cut(Long64_t entry);
  // virtual Int_t    GetEntry(Long64_t entry);
  // virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
  // virtual void     Loop();
  // virtual Bool_t   Notify();
  // virtual void     Show(Long64_t entry = -1);
};

//#endif

//#ifdef BElectronsClass_cxx
