
#include "BPark_Utils.cc"


int main(int argc,char **argv){

	//--grab and initialize trees
	TFile* file = TFile::Open(argv[1]);
	TFile* outfile = TFile::Open(argv[2],"RECREATE");
	TTree* EvTree = (TTree*)file->Get("Events");
	TTree SkimTree("Tree", "A skimmed tree with useful variables for the best BToKEE candidate");
	//TTree* EvTree = new TTree;
	//EvTree = mergeTrees(1,"/eos/home-r/ratramon/BuToKJpsiTomumu/BuToKJpsiTomumu");
	BElectronsClassMC evt;
	evt.Init(EvTree);

	double temp[29];
	SkimTree.Branch("entry", &temp[24]);
	SkimTree.Branch("B_mass", &temp[0]);
	SkimTree.Branch("B_charge", &temp[1]);
	SkimTree.Branch("B_pt", &temp[15]);
	SkimTree.Branch("B_eta", &temp[2]);
	SkimTree.Branch("B_phi", &temp[3]);
	SkimTree.Branch("B_cos2D", &temp[4]);
	SkimTree.Branch("B_l_xy", &temp[12]);
	SkimTree.Branch("B_l_xy_unc", &temp[13]);
	SkimTree.Branch("B_svprob", &temp[5]);
	SkimTree.Branch("B_vtx_x", &temp[6]);
	SkimTree.Branch("B_vtx_y", &temp[7]);
	SkimTree.Branch("B_vtx_z", &temp[8]);
	SkimTree.Branch("B_vtx_ex", &temp[9]);
	SkimTree.Branch("B_vtx_ey", &temp[10]);
	SkimTree.Branch("B_vtx_ez", &temp[11]);
	SkimTree.Branch("B_mll_raw", &temp[14]);
	SkimTree.Branch("B_l1_pt", &temp[16]);
	SkimTree.Branch("B_l1_eta", &temp[17]);
	SkimTree.Branch("B_l1_phi", &temp[18]);
	SkimTree.Branch("B_l1_mvaId", &temp[19]);
	SkimTree.Branch("B_l2_pt", &temp[20]);
	SkimTree.Branch("B_l2_eta", &temp[21]);
	SkimTree.Branch("B_l2_phi", &temp[22]);
	SkimTree.Branch("B_l2_mvaId", &temp[23]);
	SkimTree.Branch("B_l1_isPF", &temp[25]);
	SkimTree.Branch("B_l2_isPF", &temp[26]);
	SkimTree.Branch("B_l1_Sig", &temp[27]);
	SkimTree.Branch("B_l2_Sig", &temp[28]);

	int i,j;


	for(i=0;i<evt.fChain->GetEntries();i++){
		evt.fChain->GetEntry(i);
	

		if (i%10000==0)std::cout << "_____________________________on entry" << i << std::endl;
		//read all BToKEE vectors through IsGood and Rank to identify the best candidate			
		ROOT::VecOps::RVec<bool> GoodB;
		ROOT::VecOps::RVec<unsigned int> nTrg_flat;
		float l_xy_sig[evt.nBToKEE];
		ROOT::VecOps::RVec<float> GoodB_vtxProb;
		ROOT::VecOps::RVec<int> RankedB;
		int n_matched;
		n_matched =0;
		for (int index=0;index<evt.nBToKEE;index++){
			if (fabs(evt.GenPart_pdgId[evt.Electron_genPartIdx[evt.BToKEE_l1Idx[index]]])==11 && fabs(evt.GenPart_pdgId[evt.Electron_genPartIdx[evt.BToKEE_l2Idx[index]]])==11){
				 j = index;
				
			//	std::cout << "pt ele matched: index 1 " << evt.Electron_genPartIdx[evt.BToKEE_l1Idx[index]] <<  " index 2 " <<  evt.Electron_genPartIdx[evt.BToKEE_l2Idx[index]] << std::endl;
			//	n_matched++;

				
			}
		}
		std::cout << "N matched" << n_matched << std::endl;
	/*	for (int j=0;j<evt.nBToKEE;j++){
			nTrg_flat.push_back(1);
			l_xy_sig[j]=evt.BToKEE_l_xy[j]/evt.BToKEE_l_xy_unc[j];

		}
	//	std::cout << "debug" << std::endl;
		GoodB = IsGood(evt.nBToKEE,evt.BToKEE_fit_l1_pt,evt.BToKEE_fit_l2_pt,
				evt.BToKEE_fit_k_pt,nTrg_flat,evt.BToKEE_cos2D, 
				evt.BToKEE_svprob,l_xy_sig,evt.BToKEE_l_xy_unc,
				evt.BToKEE_pt,evt.BToKEE_eta);

		for(j=0;j<evt.nBToKEE;j++){
		//	std::cout << "debug ___" << GoodB[j] << std::endl;
			if (GoodB[j])GoodB_vtxProb.push_back(evt.BToKEE_svprob[j]);

		}
	//	std::cout << "debug last" <<  GoodB_vtxProb.size() <<  std::endl;
		j=-1;
		if (GoodB_vtxProb.size()>0){RankedB = Rankv2(GoodB_vtxProb);

	//		std::cout << "debug last" <<  RankedB.size() <<  std::endl;
			j = RankedB.at(0); // j index of the best candidate in the BToKEE collection
		}else continue;*/
		 // If no suitable candidate is found, continue to next event
		if(j!=-1 ) {//Define the variables to be saved in the skimmed tree
		temp[0] = evt.BToKEE_mass[j];
		temp[1] = evt.BToKEE_charge[j];
		temp[2] = evt.BToKEE_eta[j];
		temp[3] = evt.BToKEE_phi[j];
		temp[4] = evt.BToKEE_cos2D[j];
		temp[5] = evt.BToKEE_svprob[j];
		temp[6] = evt.BToKEE_vtx_x[j];
		temp[7] =  evt.BToKEE_vtx_y[j];
		temp[8] =  evt.BToKEE_vtx_z[j];
		temp[9] =  evt.BToKEE_vtx_ex[j];
		temp[10] =  evt.BToKEE_vtx_ey[j];
		temp[11] =  evt.BToKEE_vtx_ez[j];
		temp[12] =  evt.BToKEE_l_xy[j];
		temp[13] = evt.BToKEE_l_xy_unc[j];
		temp[14] = evt.BToKEE_mll_raw[j];
		temp[15] = evt.BToKEE_pt[j];
		temp[16] = evt.Electron_pt[evt.BToKEE_l1Idx[j]];
		temp[17] = evt.Electron_eta[evt.BToKEE_l1Idx[j]];
		temp[18] = evt.Electron_phi[evt.BToKEE_l1Idx[j]];
		temp[19] = evt.Electron_pfmvaId[evt.BToKEE_l1Idx[j]];
		temp[20] = evt.Electron_pt[evt.BToKEE_l2Idx[j]];
		temp[21] = evt.Electron_eta[evt.BToKEE_l2Idx[j]];
		temp[22] = evt.Electron_phi[evt.BToKEE_l2Idx[j]];
		temp[23] = evt.Electron_pfmvaId[evt.BToKEE_l2Idx[j]];
		temp[24] = i;
		temp[25] = evt.Electron_isPF[evt.BToKEE_l1Idx[j]];
		temp[26] = evt.Electron_isPF[evt.BToKEE_l2Idx[j]];
		if(fabs(evt.GenPart_pdgId[evt.Electron_genPartIdx[evt.BToKEE_l1Idx[j]]])==11 ) temp[27] = 1;
		else temp[27]=0;
		if(fabs(evt.GenPart_pdgId[evt.Electron_genPartIdx[evt.BToKEE_l2Idx[j]]])==11 ) temp[28] = 1;
		else temp[28]=0;
 		SkimTree.Fill();
		}

	}

	outfile->Write();

	outfile->Close();	





	return 0;
} 
