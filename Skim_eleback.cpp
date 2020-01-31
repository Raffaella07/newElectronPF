
#include "BPark_Utils.cc" 


#define MUON_MASS 0.10565837
#define B_MASS  5.27925


int main(int argc, char **argv){

	//--grab and initialize trees
	TFile* outfile = TFile::Open(argv[1],"RECREATE");
	TChain* chain= new TChain("Events");
	std::cout << "Loading input files from: " << std::endl;
	std::cout << "/eos/cms/store/group/cmst3/group/bpark/BParkingNANO_2020Jan16/ParkingBPH1/crab_data_Run2018C_part1/200116_151112/0000/" << std::endl;
	chain->Add("/eos/cms/store/group/cmst3/group/bpark/BParkingNANO_2020Jan16/ParkingBPH1/crab_data_Run2018C_part1/200116_151112/0000/BParkNANO_data_2020Jan16_99*.root");
	
	TTree SkimBGTree("BGTree", "A skimmed tree with useful variables for electrons in 4mu events");
	//TFile* file = TFile::Open(argv[1]);
//	TTree* EvTree = (TTree*)chain->GetTree();
	//TTree* EvTree = new TTree;
	//EvTree = mergeTrees(1,"/eos/home-r/ratramon/BuToKJpsiTomumu/BuToKJpsiTomumu");
	BElectronsClass evt;
	evt.Init(chain);
	setStyle();

	std::cout << "Successfully loaded: n entries" <<  evt.fChain->GetEntries() << std::endl;
	int i,j, entry, nElectrons,nMuon;
	double  event;
	int Muon_idx[200];
	float Ele_pt[200],Ele_eta[200],Ele_phi[200],Ele_pfmvaId[200];
	bool Ele_isPF[200];


	for (i=0;i<200;i++){
	Ele_pt[i] =0;
	Ele_eta[i] =0;
	Ele_phi[i] =0;
	Ele_pfmvaId[i] =0;
	Ele_isPF[i] =0;
	Muon_idx[i]=0;

	}
	SkimBGTree.Branch("entry", &entry);
	SkimBGTree.Branch("event", &event);
	SkimBGTree.Branch("nMuon", &nMuon);
	SkimBGTree.Branch("Muon_idx", Muon_idx,"Muon_idx[nMuon]/I");
	SkimBGTree.Branch("nElectrons", &nElectrons);
	SkimBGTree.Branch("Ele_pt", Ele_pt,"Ele_pt[nElectrons]/F");
	SkimBGTree.Branch("Ele_eta", Ele_eta,"Ele_eta[nElectrons]/F");
	SkimBGTree.Branch("Ele_phi", Ele_phi,"Ele_phi[nElectrons]/F");
	SkimBGTree.Branch("Ele_pfmvaId", Ele_pfmvaId,"Ele_pfmvaId[nElectrons]/F");
	SkimBGTree.Branch("Ele_isPF", Ele_isPF,"Ele_isPF[nElectrons]/O");

	for(i=0;i<evt.fChain->GetEntries();i++){
	evt.fChain->GetEntry(i);
	if(i%1000==0)std::cout << "Looping on entry" <<i <<  std::endl;
	//std::cout << "nMuon  in event" << evt.nMuon <<  std::endl;
	if (evt.nMuon == 4){
	
	//std::cout << "event with four muons" << std::endl;
	TLorentzVector Muon[evt.nMuon];
	double m_ll;
	std::pair <int, int> di_muon1, di_muon2;
	di_muon1 = std::make_pair(-1,-1);
	di_muon2 = std::make_pair(-1,-1);
		for (j=0;j<evt.nMuon;j++){
		Muon[j].SetPtEtaPhiM(evt.Muon_pt[j],evt.Muon_eta[j],evt.Muon_phi[j],MUON_MASS);	

		}
		
		for (j=0;j<evt.nMuon;j++){
			for (int k =j+1;k<evt.nMuon;k++){
			//std::cout << "looping on muons" << std::endl;
				if (evt.Muon_charge[j]*evt.Muon_charge[k] < 0 && k != j ){
					//std::cout << "opposite charge" << std::endl;
					if (Muon[k]*Muon[j] < B_MASS && ((di_muon1.first != k && di_muon1.second !=j) || (di_muon1.first != j && di_muon1.second !=k))){
					 di_muon1= std::make_pair(k,j);
					
			//		std::cout << "muon 1 indices" << k <<"__" << j <<  std::endl;
					break;
					}
					}
				}
		
			}
		for (j=0;j<evt.nMuon;j++){
			if (j == di_muon1.second ||j == di_muon1.first) continue;
			for (int k =j+1;k<evt.nMuon;k++){
				
				if (k == di_muon1.second ||k == di_muon1.first) continue;
				if (evt.Muon_charge[j]*evt.Muon_charge[k] < 0 && k != j ){
					if (Muon[k]*Muon[j] < B_MASS && ((di_muon2.first != k && di_muon2.second !=j) || (di_muon2.first != j && di_muon2.second !=k))){

	//			std::cout << "_________________________________________________muon 2 indices aasigned " <<  std::endl;
					di_muon2= std::make_pair(k,j);
					break;
					
					//std::cout << "di muon 1 indices  " << di_muon1.first <<"___" << di_muon1.second <<  std::endl;
					}
					}
				}
		
			}
		if (di_muon1.first == -1 || di_muon2.first == -1 || di_muon1.second == -1 || di_muon2.second == -1 ) continue;
	//	std::cout << "check pairs" <<  std::endl;
	//	std::cout << "di muon 1 indices  " << di_muon1.first <<"___" << di_muon1.second <<  std::endl;
	//	std::cout << "di muon 2 indices  " << di_muon2.first <<"___" << di_muon2.second <<  std::endl;
	//	std::cout << "---------------------------------------------nElectrons " << evt.nElectron << std::endl;
/*		for(j=0; j<evt.nElectron; j++)
		if (evt.Electron_isPF[j])
		
		Electron_pt = evt.Electron_
	*/
		
		nElectrons = evt.nElectron;
		nMuon = evt.nMuon;
		entry = i;
		event = evt.event;
		Muon_idx[0]=di_muon1.first;
		Muon_idx[1]=di_muon1.second;
		Muon_idx[2]=di_muon2.first;
		Muon_idx[3]=di_muon2.second;

		for(int f=0;f<evt.nElectron; f++){
		if(nElectrons>200) break;
		std::cout << "---------------------------------------------Electronpt " << evt.Electron_pt[f] << std::endl;
		Ele_pt[f] = evt.Electron_pt[f];
		Ele_eta[f]=evt.Electron_eta[f];
		Ele_phi[f]=evt.Electron_phi[f];
		Ele_pfmvaId[f]= evt.Electron_pfmvaId[f];
		Ele_isPF[f]=evt.Electron_isPF[f];
	//	Ele_eta = evt.Electron_eta;
	//	Ele_phi = evt.Electron_phi;
	//	Ele_pfmvaId = evt.Electron_pfmvaId;
	//	Ele_isPF = evt.Electron_isPF;
		std::cout << "---------------------------------------------Electronpttrans " << Ele_pt[f] << std::endl;
		}
	//
		SkimBGTree.Fill();
		}
		}		
	
	outfile->Write();
	outfile->Close();
	
	return 0;
	}

