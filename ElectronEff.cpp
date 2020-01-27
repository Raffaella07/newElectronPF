#include "BPark_Utils.cc" 




int main(int argc, char **argv){

	//--grab and initialize trees
	TFile* file = TFile::Open(argv[1]);
	TTree* EvTree = (TTree*)file->Get("Events");
	//TTree* EvTree = new TTree;
	//EvTree = mergeTrees(1,"/eos/home-r/ratramon/BuToKJpsiTomumu/BuToKJpsiTomumu");
	BElectronsClass evt;
	evt.Init(EvTree);
	setStyle();

	int i,npoints;
	npoints = 16;
	double eff_sig[npoints], eff_bkg[npoints];
	TH1D* Signal = new TH1D("NANOAOD pre + PFi+STD cut ","NANOAOD pre + pf",40, -11, 8);
	TH1D* Background = new TH1D("pfmvaId of MC_Unmatched PF  electrons reconstructed in BToKEE","",40, -11, 8);
	TH1D* pdgId = new TH1D("GenPart idx of PF  electrons reconstructed in BToKEE","",19, -5, 20);
	std::string y[5]={"","#frac{N_{PF}}{N_{matched}}",/*"#frac{N_{noPF}}{N_{matched}}",*/"#frac{N_{PF}}{N_{unmatched}}",/*"#frac{N_{noPF}}{N_{unmatched}}"*/};
	
	for(i=0;i<evt.fChain->GetEntries();i++){
		evt.fChain->GetEntry(i);	
		if (i%10000==0)std::cout << "on entry" << i << std::endl;
	//	for (int j=0;j<evt.nBToKEE;j++){
		int j=0;
			double Lxy = evt.BToKEE_l_xy[j]/sqrt(pow(evt.BToKEE_vtx_ex[j],2)+pow(evt.BToKEE_vtx_ey[j],2));
		if (evt.BToKEE_pt[j] <10 || evt.BToKEE_cos2D[j]<0.999 || evt.BToKEE_svprob[j] <0.1 || Lxy <6 || evt.BToKEE_fit_k_pt[j] < 1.5  ) continue;
		if (evt.Electron_isPF[evt.BToKEE_l1Idx[j]]==1){
			pdgId->Fill(evt.Electron_genPartIdx[evt.BToKEE_l1Idx[j]]);
		//	std::cout << "check on double counting: idx lead" << evt.BToKEE_l1Idx[[j]] << " idx sublead" <<  evt.BToKEE_l2Idx[[j]] << std::endl;
			if (fabs(evt.GenPart_pdgId[evt.Electron_genPartIdx[evt.BToKEE_l1Idx[j]]])==11 /*evt.BToKEE_fit_mass[j] < 5.27925 +3*evt.BToKEE_fit_massErr[j] && evt.BToKEE_fit_mass[j] > 5.27925 -3*evt.BToKEE_fit_massErr[j]) Signal->Fill(evt.Electron_pfmvaId[evt.BToKEE_l1Idx[j]]*/);
				
			else Background->Fill(evt.Electron_pfmvaId[evt.BToKEE_l1Idx[j]]);


		}		
		if (evt.Electron_isPF[evt.BToKEE_l2Idx[j]]==1){
			pdgId->Fill(evt.Electron_genPartIdx[evt.BToKEE_l2Idx[j]]);
			if (/*evt.BToKEE_fit_mass[j] < 5.27925 +3*evt.BToKEE_fit_massErr[j] && evt.BToKEE_fit_mass[j] > 5.27925 -3*evt.BToKEE_fit_massErr[j]*/fabs(evt.GenPart_pdgId[evt.Electron_genPartIdx[evt.BToKEE_l2Idx[j]]])==11 ) Signal->Fill(evt.Electron_pfmvaId[evt.BToKEE_l2Idx[j]]);
				
			else Background->Fill(evt.Electron_pfmvaId[evt.BToKEE_l2Idx[j]]);


			}		

	//	}
	}
	Signal->GetYaxis()->SetTitle("entries");
	Background->GetYaxis()->SetTitle("entries");
	
	SavePlot("PFmvaId",Signal,"newElectronPF/signal_pfmvaId",false, NULL,false);
	SavePlot("PFmvaId",Background,"newElectronPF/background_pfmvaId",false, NULL,false);
	SavePlot("Electron_genPartIdx",pdgId,"newElectronPF/genPart_idx",false, NULL,false);
	superpos("PFmvaId",Signal,Background,"newElectronPF/Sig_Back_pfmvaid",false,"NANOAOD pre + PF");
	std::cout << "range ROC " << Signal->GetXaxis()->GetXmin()+Background->GetXaxis()->GetXmax() << "__" << Signal->GetXaxis()->GetXmin() << std::endl;
	for (i=0;i<npoints;i++){
	double x_cut = -4+(4-(-4))*i/npoints;
	eff_sig[i] = Signal->Integral(Signal->FindBin(x_cut), Signal->GetXaxis()->GetXmax())/Signal->Integral();
	eff_bkg[i] = 1-Background->Integral(Background->FindBin(x_cut), Background->GetXaxis()->GetXmax())/Background->Integral();
	}
	TGraph* ROC = new TGraph(npoints,eff_sig,eff_bkg);	
	
	TCanvas* canv = new TCanvas("","",800,600);
	TH2D* ranges = new TH2D("NANOAOD pre + PF ","NANOAOD pre + PF +STD cut",10,0 ,1.1, 10,0,1.1);
	ROC->SetMarkerStyle(8);
	ranges->GetXaxis()->SetTitle("1-#epsilon_{bkg}");	
	ranges->GetYaxis()->SetTitle("#epsilon_{sgl}");	
	ranges->Draw();
	ROC->Draw("SAMEPL");
	lables(canv,ranges);
	
	std::string PNGPATH = "/eos/home-r/ratramon/www/";
	std::string filename = "ROC";
	canv->SaveAs((std::string(filename)+".pdf").c_str());
	canv->SaveAs((PNGPATH+std::string(filename)+".png").c_str());
//SavePlot("p_{T}(GeV)",ele[6],"newElectronPF/unmatched_pf_pt",false, NULL,false);
//	SavePlot("#eta",ele[7],"newElectronPF/unmatched_pf_eta",false, NULL,false);
	return 0;
	}
