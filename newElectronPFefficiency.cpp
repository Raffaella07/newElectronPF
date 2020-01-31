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

	TH1D* pt_l1 = new TH1D("leading electron pt","leading electron pt",80,0,50);
	TH1D* mvaId_l1 = new TH1D("NANOAOD \n pre-selection + PF","NANOAOD \n pre-selection + PF",80,-10,8);
	TH1D* mvaId_l2 = new TH1D("NANOAOD \n pre-selection + PF","NANOAOD \n pre-selection + PF",80,-10,8);
	TH1D* pt_l2 = new TH1D("subleading electron pt","subleading electron pt",80,0,50);
	TH1D* mll = new TH1D("NANOAOD \n pre-selection + PF","NANOAOD \n producer pre-selection ",80,1.5,5);
	TH2D* mva_id = new TH2D("NANOAOD \n pre-selection +PF ","NANOAOD \n producer pre-selection",35,-10,8,35,-10,8);
	TH2D* pt1_mvaId = new TH2D("NANOAOD \n  pre-selection +PF ","NANOAOD \n producer pre-selection",35,-10,8,35,0,50);
	TH2D* pt2_mvaId = new TH2D("NANOAOD \n pre-selection +PF ","NANOAOD \n producer pre-selection",35,-10,8,35,0,50);
	int i;

	for(i=0;i<evt.fChain->GetEntries();i++){
		evt.fChain->GetEntry(i);
			if (i%10000==0) std::cout << "On entry" << i << std::endl;
			if(evt.Electron_isPF[evt.BToKEE_l1Idx[0]]==1 && evt.Electron_genPartIdx[evt.BToKEE_l1Idx[0]] != -1){ 
			pt_l1->Fill(evt.Electron_pt[evt.BToKEE_l1Idx[0]]);
			mvaId_l1->Fill(evt.Electron_pfmvaId[evt.BToKEE_l1Idx[0]]);
			pt1_mvaId->Fill(evt.Electron_pfmvaId[evt.BToKEE_l1Idx[0]],evt.Electron_pt[evt.BToKEE_l1Idx[0]]);
			}
			if(evt.Electron_isPF[evt.BToKEE_l2Idx[0]]==1 && evt.Electron_genPartIdx[evt.BToKEE_l2Idx[0]] != -1){ 
			pt_l2->Fill(evt.Electron_pt[evt.BToKEE_l2Idx[0]]);
			mvaId_l2->Fill(evt.Electron_pfmvaId[evt.BToKEE_l2Idx[0]]);
			pt2_mvaId->Fill(evt.Electron_pfmvaId[evt.BToKEE_l2Idx[0]],evt.Electron_pt[evt.BToKEE_l2Idx[0]]);
			}
			if(evt.Electron_isPF[evt.BToKEE_l1Idx[0]] && evt.Electron_isPF[evt.BToKEE_l2Idx[0]] && evt.Electron_genPartIdx[evt.BToKEE_l1Idx[0]] != -1 && evt.Electron_genPartIdx[evt.BToKEE_l2Idx[0]] != -1){
			mva_id->Fill(evt.Electron_pfmvaId[evt.BToKEE_l2Idx[0]],evt.Electron_pfmvaId[evt.BToKEE_l1Idx[0]]);
			mll->Fill(evt.BToKEE_mll_raw[0]);
			}
			//if (evt.BToKEE_l1Idx[j] !=l1_idx.at(k) )
			//std::cout << "adding new entry" << std::endl;

			//temp = evt.BToKEE_l1Idx[j];//pt_l1->Fill(evt.Electron_pt[evt.BToKEE_l1Idx[j]]);
			//std::cout << "pushing back " << evt.BToKEE_l1Idx[j] << std::endl;
		//	l1_idx.push_back(evt.BToKEE_l1Idx[j]);
	
			
			//std::cout << "entry " << i << "sublead electron idx  " << evt.BToKEE_l2Idx[j] << std::endl;

		
	}
	Slicer("newElectronPF/l1/",10,0,40,"PFmvaId e_{leading}",pt1_mvaId,"mvaId");
	Slicer("newElectronPF/l2/",10,0,40,"PFmvaId e_{subleading}",pt2_mvaId,"mvaId");
	SavePlot("p_{T}(GeV)",pt_l1,"newElectronPF/l1_pt",false, NULL,false);
	SavePlot("p_{T}(GeV)",pt_l2,"newElectronPF/l2_pt",false, NULL,false);
	SavePlot("PFmvaID e_{leading}",mvaId_l1,"newElectronPF/l1_ranking",false, NULL,true);
	SavePlot("M_{e^{+}e^{-}}(GeV)",mll,"newElectronPF/mll",false, NULL,true);
	SavePlot("PFmvaID e_{subleading}",mvaId_l2,"newElectronPF/l2_ranking",false, NULL,true);
	SavePlot2D("e1 vs e2 rankings",mva_id,"newElectronPF/e1_e2pfId",false,true);
	
	return 0;


}
