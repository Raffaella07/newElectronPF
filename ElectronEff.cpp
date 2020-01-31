#include "BPark_Utils.cc" 




int main(int argc, char **argv){

	//--grab and initialize trees
	TFile* file = TFile::Open(argv[1]);
	TTree* EvTree = (TTree*)file->Get("Events");
	//TTree* EvTree = new TTree;
	//EvTree = mergeTrees(1,"/eos/home-r/ratramon/BuToKJpsiTomumu/BuToKJpsiTomumu");
	BElectronsClassMC evt;
	evt.Init(EvTree);
	setStyle();

	const int n_selections = 2;
	Color_t sel_colors[n_selections]= {kBlack,kRed};
	std::string sel_lables[n_selections] = {"NANOAOD pre + PF ","NANOAOD pre + PF+STD cut "};
	int i,j,npoints;
	npoints = 16;
	double eff_sig[n_selections][npoints], eff_bkg[n_selections][npoints];
	TH1D* Signal = new TH1D("NANOAOD pre + PF+STD cut ","NANOAOD pre + pf",40, -11, 8);
	TH1D* Background = new TH1D("pfmvaId of MC_Unmatched PF  electrons reconstructed in BToKEE","",40, -11, 8);
	TH1D* pdgId = new TH1D("GenPart idx of PF  electrons reconstructed in BToKEE","",19, -5, 20);
	std::string y[5]={"","#frac{N_{PF}}{N_{matched}}",/*"#frac{N_{noPF}}{N_{matched}}",*/"#frac{N_{PF}}{N_{unmatched}}",/*"#frac{N_{noPF}}{N_{unmatched}}"*/};


	for (int index = 0; index < n_selections ;index++ ){

		for(i=0;i<evt.fChain->GetEntries();i++){
			evt.fChain->GetEntry(i);
				
			if (i%10000==0)std::cout << "                                               on entry" << i << std::endl;
			
	//		for (int j=0;j<evt.nBToKEE;j++){
			ROOT::VecOps::RVec<bool> GoodB;
			ROOT::VecOps::RVec<unsigned int> nTrg_flat;
			float l_xy_sig[evt.nBToKEE];
			ROOT::VecOps::RVec<float> GoodB_vtxProb;
			ROOT::VecOps::RVec<int> RankedB;
			
			for (int j=0;j<evt.nBToKEE;j++){
			nTrg_flat.push_back(2);
			l_xy_sig[j]=evt.BToKEE_l_xy[j]/evt.BToKEE_l_xy_unc[j];
			
			}
			std::cout << "debug" << std::endl;
			GoodB = IsGood(evt.nBToKEE,evt.BToKEE_fit_l1_pt,evt.BToKEE_fit_l2_pt,
					evt.BToKEE_fit_k_pt,nTrg_flat,evt.BToKEE_cos2D, 
					evt.BToKEE_svprob,l_xy_sig,evt.BToKEE_l_xy_unc,
					evt.BToKEE_pt,evt.BToKEE_eta);
			
			for(j=0;j<evt.nBToKEE;j++){
			std::cout << "debug ___" << GoodB[j] << std::endl;
			/*	if (GoodB[j])*/GoodB_vtxProb.push_back(evt.BToKEE_svprob[j]);

			}
			std::cout << "debug last" <<  GoodB_vtxProb.size() <<  std::endl;
			if (GoodB_vtxProb.size()>0){RankedB = Rankv2(GoodB_vtxProb);
			
			std::cout << "debug last" <<  RankedB.size() <<  std::endl;
			j = RankedB.at(0);
			}else continue;
			double Lxy = evt.BToKEE_l_xy[j]/evt.BToKEE_l_xy_unc[j];
			
if (index ==1){	if (evt.BToKEE_pt[j] <10 || evt.BToKEE_cos2D[j]<0.999 || evt.BToKEE_svprob[j] <0.1 || Lxy <6 || evt.BToKEE_fit_k_pt[j] < 1.5 ) continue;}


			if (evt.Electron_isPF[evt.BToKEE_l1Idx[j]]==1){
				pdgId->Fill(evt.Electron_genPartIdx[evt.BToKEE_l1Idx[j]]);
				//	std::cout << "check on double counting: idx lead" << evt.BToKEE_l1Idx[[j]] << " idx sublead" <<  evt.BToKEE_l2Idx[[j]] << std::endl;
				if (fabs(evt.GenPart_pdgId[evt.Electron_genPartIdx[evt.BToKEE_l1Idx[j]]])==11 /*evt.BToKEE_fit_mass[j] < 5.27925 +3*evt.BToKEE_fit_massErr[j] && evt.BToKEE_fit_mass[j] > 5.27925 -3*evt.BToKEE_fit_massErr[j]*/) Signal->Fill(evt.Electron_pfmvaId[evt.BToKEE_l1Idx[j]]);

				else Background->Fill(evt.Electron_pfmvaId[evt.BToKEE_l1Idx[j]]);


			}		
			if (evt.Electron_isPF[evt.BToKEE_l2Idx[j]]==1 ){
				pdgId->Fill(evt.Electron_genPartIdx[evt.BToKEE_l2Idx[j]]);
				if (/*evt.BToKEE_fit_mass[j] < 5.27925 +3*evt.BToKEE_fit_massErr[j] && evt.BToKEE_fit_mass[j] > 5.27925 -3*evt.BToKEE_fit_massErr[j]*/fabs(evt.GenPart_pdgId[evt.Electron_genPartIdx[evt.BToKEE_l2Idx[j]]])==11 ) Signal->Fill(evt.Electron_pfmvaId[evt.BToKEE_l2Idx[j]]);

				else Background->Fill(evt.Electron_pfmvaId[evt.BToKEE_l2Idx[j]]);


			}		

			//	}
		}
		Signal->GetYaxis()->SetTitle("entries");
		Background->GetYaxis()->SetTitle("entries");	
		Signal->SetTitle(sel_lables[index].c_str());
		Signal->SetName(sel_lables[index].c_str());
		Background->SetTitle(sel_lables[index].c_str());
		Background->SetName(sel_lables[index].c_str());

		SavePlot("PFmvaId",Signal,("newElectronPF/signal_pfmvaId_"+std::to_string(index)).c_str(),false, NULL,false);
		SavePlot("PFmvaId",Background,("newElectronPF/background_pfmvaId"+std::to_string(index)).c_str(),false, NULL,false);
		SavePlot("Electron_genPartIdx",pdgId,("newElectronPF/genPart_idx"+std::to_string(index)).c_str(),false, NULL,false);
		//Signal->Scale(1/Signal->Integral());
		//Background->Scale(1/Background->Integral());
		superpos("PFmvaId",Signal,Background,("newElectronPF/Sig_Back_pfmvaid"+std::to_string(index)).c_str(),false,sel_lables[index].c_str());
		std::cout << "index" << index << std::endl;
		for (i=0;i<npoints;i++){
			double x_cut = -4+(4-(-4))*i/npoints;
			eff_sig[index][i] = Signal->Integral(Signal->FindBin(x_cut), Signal->GetXaxis()->GetXmax())/Signal->Integral();
			eff_bkg[index][i] = 1-Background->Integral(Background->FindBin(x_cut), Background->GetXaxis()->GetXmax())/Background->Integral();

		}
		Signal->Reset();
		Background->Reset();
	}
	TGraph* ROC[n_selections];
	TCanvas* canv = new TCanvas("","",800,600);
	std::cout << "debug" << std::endl;
	TLatex latex;
	latex.SetTextAlign(13);
	latex.SetTextSize(0.045);

	std::cout << "debug" << std::endl;
	TH2D* ranges = new TH2D("NANOAOD pre + PF ","NANOAOD pre + PF +STD cut",10,0 ,1.1, 10,0,1.1);
	ranges->GetXaxis()->SetTitle("1-#epsilon_{bkg}");	
	ranges->GetYaxis()->SetTitle("#epsilon_{sgl}");	
	ranges->Draw();
	for(i=0;i<n_selections; i++){
		for(int j=0;j<npoints;j++){
		}
		std::cout << "debug" << std::endl;
		ROC[i] = new TGraph(npoints,eff_sig[i],eff_bkg[i]);	
		ROC[i]->SetMarkerStyle(8);
		ROC[i]->SetMarkerColor(sel_colors[i]);
		ROC[i]->SetLineColor(sel_colors[i]);
		ROC[i]->SetLineWidth(2);
		std::cout << "debug1 " << std::endl;
		std::cout << "debug2 " << std::endl;

		ROC[i]->Draw("SAMEPL");
	}

	latex.DrawLatex(0.1,0.3,sel_lables[0].c_str());
	latex.SetTextColor(kRed);
	latex.DrawLatex(0.1,0.1,sel_lables[1].c_str());
	std::string PNGPATH = "/eos/home-r/ratramon/www/";
	std::string filename = "ROC";
	canv->SaveAs((std::string(filename)+".pdf").c_str());
	canv->SaveAs((PNGPATH+std::string(filename)+".png").c_str());
	//SavePlot("p_{T}(GeV)",ele[6],"newElectronPF/unmatched_pf_pt",false, NULL,false);
	//	SavePlot("#eta",ele[7],"newElectronPF/unmatched_pf_eta",false, NULL,false);
	return 0;
}
