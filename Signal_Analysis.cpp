#include "BPark_Utils.cc" 

int main(int argc, char **argv){

	//--grab and initialize trees
	TFile* file_sigMC = TFile::Open(argv[1]);
	TFile* file_backMC = TFile::Open(argv[2]);
	TFile* file_back = TFile::Open(argv[3]);
	TTree* EvTree = (TTree*)file_sigMC->Get("Tree");
	TTree* BG_MCTree = (TTree*)file_backMC->Get("Tree");
	TTree* BGTree = (TTree*)file_back->Get("BGTree");
	//TTree* EvTree = new TTree;
	//EvTree = mergeTrees(1,"/eos/home-r/ratramon/BuToKJpsiTomumu/BuToKJpsiTomumu");
	BSignalElectronClass evt, bkg_MC;
	BSignalElectronClass *evt_ptr, *bkg_MCptr;
	evt_ptr = &evt;
	bkg_MCptr = &bkg_MC;
	BGElectronClass bkg;
	BGElectronClass *bkg_ptr;
	bkg_ptr = &bkg;
	evt.Init(EvTree);
	bkg_MC.Init(BG_MCTree);
	bkg.Init(BGTree);
	setStyle();

	std::cout << "MC backgound entries " << bkg_MC.fChain->GetEntries() << std::endl;
	int i,n1_bin,n2_bin;
	double x1_cut, x2_cut,x1_low,x1_high,x2_low,x2_high, eff, N_Stot, N_Sel;
	
	n1_bin = 19;
	n2_bin = 19;
	x1_low = -11;
	x1_high = 8;
	x2_low = -11;
	x2_high = 8;

	TH2D* eff_cut =new TH2D("efficiencies","",19,-11,8,19,-11,8);	
	TH1D* signalMC_mvaId = new TH1D("signal pfmvaid","signal pfmvaid",19,-11,8);
	TH1D* bkgMC_mvaId = new TH1D("signal pfmvaid","signal pfmvaid",19,-11,8);
	TH1D* bkg_mvaId = new TH1D("bkg pfmvaid","bkg pfmvaid",19,-11,8);
	TH1D* signalMC_pt = new TH1D("signal pt","signal pt",35,0,35);
	TH1D* bkgMC_pt = new TH1D("signal pt","signal pt",35,0,35);
	TH1D* bkg_pt = new TH1D("bkg pt","bkg pt",35,0,35);
	TH1D* signalMC_eta = new TH1D("signal eta","signal eta",30,-3,3);
	TH1D* bkgMC_eta = new TH1D("signal eta","signal eta",30,-3,3);
	TH1D* bkg_eta = new TH1D("bkg eta","bkg eta",30,-3,3);

	for (int i1=0;i1<n1_bin;i1++){
		x1_cut = x1_low + (x1_high-x1_low)/n1_bin*i1;
		for (int i2=0;i2<n2_bin;i2++){
			x2_cut = x2_low + (x2_high-x2_low)/n2_bin*i2;
			for(i=0;i<evt.fChain->GetEntries();i++){
				
		//	if (i%10000==0)std::cout << "                                               on entry" << i << std::endl;
				evt.fChain->GetEntry(i);
				if(evt.B_l1_isPF==1 && evt.B_l1_Sig==1 && evt.B_l2_isPF==1 && evt.B_l2_Sig==1){
					N_Stot++;
					if(evt.B_l1_mvaId > x1_cut && evt.B_l2_mvaId >x2_cut) N_Sel++;

				} 




			}
		
		
		eff = N_Sel/N_Stot;
	//	std::cout << "efficiency" << eff << std::endl;
		eff_cut->Fill(x2_cut,x1_cut,eff);
		N_Stot =0;
		N_Sel=0;
		}
	
	std::cout << "cuts : xLead " << x1_cut << " xSlead " << x2_cut<< std::endl;

	}
	
	Fill_MChistos(evt_ptr,signalMC_mvaId,signalMC_pt,signalMC_eta);
	Fill_MChistos(bkg_MCptr,bkgMC_mvaId,bkgMC_pt,bkgMC_eta);
	Fill_DATAhistos(bkg_ptr,bkg_mvaId,bkg_pt,bkg_eta);

	std::cout << "after filling " << bkgMC_pt->GetEntries() << std::endl;	
	superMC_DATAnorm(signalMC_mvaId,bkgMC_mvaId,bkg_mvaId,0.07,"newElectronPF/SglVsBkg_mvaId","PFmvaId",false);
	superMC_DATAnorm(signalMC_pt,bkgMC_pt,bkg_pt,0.6,"newElectronPF/SglVsBkg_pt","p_{T}(GeV)",true);
	superMC_DATAnorm(signalMC_eta,bkgMC_eta,bkg_eta,0.07,"newElectronPF/SglVsBkg_eta","#eta",false);
	SavePlot2D("pfmvaid cut efficiencies",eff_cut,"newElectronPF/PFmvaId_cut_eff",false,false);
	return 0;	
	}
