#include "../interface/BParkTools.h"
#include "../src/BPark_fitUtils.cc"
/* ROOT::VecOps::RVec<bool> IsGood(unsigned int nB, 
				float *pT1, float *pT2, float *pTk, 
 				ROOT::VecOps::RVec<unsigned int>& nTrg,float *cos2D, float *vtxP, 
 				float *disp, float *dispU, float *pT,float*eta) { 

  ROOT::VecOps::RVec<bool> goodB(nB, false);
  for (auto ij=0; ij<nB; ++ij){
    if (pT1[ij] > 1. && pT2[ij] > 0.5 && pTk[ij] > 0.8 &&
     	nTrg[ij] > 0 && cos2D[ij] > 0.99 && vtxP[ij] > 0.1 && disp[ij] > 2 && dispU[ij] != 0 && pT[ij] > 3. && std::abs(eta[ij]) < 2.4)
      goodB[ij]  = true;
  }

  return goodB; 
}

ROOT::VecOps::RVec<int> Rankv2(ROOT::VecOps::RVec<float>& vtxP){

  
  auto sortIndices = Argsort(vtxP);
  ROOT::VecOps::RVec<int> rank;
  auto totN = vtxP.size();
  rank.resize(totN);
//  std::cout << "in Ranked v2" << totN << std::endl;

  int nRank = 0;
  for (auto ij=0; ij<totN; ++ij){
//	std::cout << "in for RankV2 " << nRank << std::endl;
    rank[sortIndices[ij]] = nRank;
    ++nRank;
  }
  return rank; 
} */


Double_t fline(Double_t *x, Double_t *par)
{
   if (x[0] > 4.5 && x[0] < 6) {
      TF1::RejectPoint();
      return 0;
   }
   return par[0]+x[0]*par[1]+par[2]*std::pow(x[0],2)+par[3]*std::pow(x[0],3);
}

void FillKinhistos(TH1D** histo, double pt, double eta, double phi, int type){
	int i;
	double kin[3];

	kin[0]=pt;
	kin[1]=eta;
	kin[2]=phi;


	for(i=0; i<3; i++){
		if(type == 0 ) histo[i]->Fill(kin[i]);
		else if(type==1) histo[i+3]->Fill(kin[i]);
		else if(type==2) histo[i+6]->Fill(kin[i]);

	}


}
double sigma_Bsig(){

	TChain * chain = new TChain("Events");
	chain->Add("/eos/cms/store/group/cmst3/group/bpark/BParkingNANO_2020Jan16/BuToKJpsi_Toee_Mufilter_SoftQCDnonD_TuneCP5_13TeV-pythia8-evtgen/crab_BuToKJpsi_Toee/200116_215618/0000/BParkNANO_mc_2020Jan16_*.root");
	TF1* fit = new TF1("gaussfit","gaus",5.2,5.4);
	TH1D* B_mass = new TH1D("B_mass","B_mass",92,0,4);
	BElectronsClassMC evt;
	evt.Init(chain);
	int i;
	std::cout << "before for, signal weight" << SignalWeight() << std::endl;
	for(i=0;i<evt.fChain->GetEntries();i++){
		evt.fChain->GetEntry(i);
		for(int j =0; j<evt.nBToKEE; j++){
		if (evt.Electron_isPF[evt.BToKEE_l1Idx[j]] && evt.Electron_isPF[evt.BToKEE_l2Idx[j]])B_mass->Fill(evt.BToKEE_mll_llfit[j],SignalWeight());
		break;
		}
	}	

	fit->SetParameter(2,3);
	fit->SetParameter(0,B_mass->GetMaximum());
	fit->SetParLimits(0,B_mass->GetMaximum()-B_mass->GetMaximum()*.4,B_mass->GetMaximum()+B_mass->GetMaximum()*.5);
	
	B_mass->Fit("gaussfit","0R");
	SavePlot("M_{B}GeV",B_mass,"newElectronPF/fit_mB",false,fit,false);	
	return fit->GetParameter(2);
}

TTree* mergeTrees(int n_files,std::string filename){

	TList* l = new TList();
	int i;

	for(i=0;i<n_files;i++){	
	
		
	TFile* file = TFile::Open((filename+"_"+std::to_string(i)+"_NANO.root").c_str());
	TTree* EvTree =new TTree;
	EvTree =  (TTree*)file->Get("Events");
	l->Add(EvTree);

	}
	
	TTree* tree = new TTree();
	tree->MergeTrees(l);
	return tree;

}


void lables1D(TCanvas* canv,TH1D* histo){

	TLatex l;
	l.SetTextSize(0.045);
	l.SetTextAlign(13);
	l.DrawLatex(histo->GetXaxis()->GetXmin()+(histo->GetXaxis()->GetXmax()-histo->GetXaxis()->GetXmin())*1/9, histo->GetMaximum()+histo->GetMaximum()*0.07,histo->GetName());	
	canv->Update();	


}
void SavePlot (std::string titlestring, TH1D * histo, const char * filename, bool log, TF1* fit, bool lable){

	TCanvas* canvas = new TCanvas("canva","canva",600,550);
	TFile* histos = new TFile("gausslog.root","UPDATE","",0);
	std::string PNGPATH = "/eos/home-r/ratramon/www/";
	std::string PDFPATH = "/afs/cern.ch/user/r/ratramon/Bparking/CMSSW_10_2_15/src/macros/newElectronPF/";
	//const char * temptitle = titlestring.c_str();

	if (log) canvas->SetLogy();
	histo->GetXaxis()->SetMaxDigits(2);
	histo->SetLineWidth(4);
	histo->SetLineColor(kRed-6);
	histo->GetXaxis()->SetTitle(titlestring.c_str());
	histo->GetYaxis()->SetTitle("entries");
	std::cout << "axis title" << titlestring.c_str() << std::endl;
	histo->Draw("HIST");
	if(fit != NULL) fit->Draw("same");
	if(lable)lables1D(canvas,histo);
	canvas->SaveAs((PDFPATH+std::string(filename)+".pdf").c_str());
	canvas->SaveAs((PNGPATH+std::string(filename)+".png").c_str());
	canvas->Clear();
	histos->Close();

	delete canvas;
}
void lables(TCanvas* canv,TH2D* histo){

	TLatex l;
	l.SetTextSize(0.04);
	l.SetTextAlign(13);
	l.DrawLatex(histo->GetXaxis()->GetXmin()+(histo->GetXaxis()->GetXmax()-histo->GetXaxis()->GetXmin())*8/18, histo->GetYaxis()->GetXmax()-(histo->GetYaxis()->GetXmax()-histo->GetYaxis()->GetXmin())*0.07,histo->GetTitle());	
	canv->Update();	


}

void superpos(std::string titlestring,TH1D * h1, TH1D* h2, const char* filename,bool log, bool lable){

	TCanvas* canvas = new TCanvas("canva","canva",600,550);
	TH1D* empty = new TH1D("empty","empty",10,h1->GetXaxis()->GetXmin(),h1->GetXaxis()->GetXmax());
	std::string PNGPATH = "/eos/home-r/ratramon/www/";
	TLatex l;

	std::cout << "compare entries " << h1->GetEntries() << "reco "  << h2->GetEntries() << std::endl;
	empty->GetXaxis()->SetMaxDigits(2);
	if (log){ canvas->SetLogy();
		empty->GetYaxis()->SetRangeUser(1,std::max(h1->GetMaximum()*2.5,h2->GetMaximum()*2.5));
	}else {
		empty->GetYaxis()->SetRangeUser(0,std::max(h1->GetMaximum()*1.1,h2->GetMaximum()*1.1));
	}
	h1->SetLineWidth(4);
	h2->SetLineWidth(4);
	h1->SetLineColor(kRed-6);
	h2->SetLineColor(kBlue-3);
	empty->GetXaxis()->SetTitle(titlestring.c_str());
	empty->GetYaxis()->SetTitle("entries");
	empty->Draw("");
	h1->Draw("HISTsame");
	h2->Draw("HISTsame");
	l.SetTextSize(0.045);
	l.SetTextAlign(13);
	l.SetTextColor(kRed-6);
	l.DrawLatex(h1->GetXaxis()->GetXmin()+0.4*(h1->GetXaxis()->GetXmax()-h1->GetXaxis()->GetXmin()),0.98*h1->GetMaximum(),(std::string("Signal ")+std::to_string((int)h1->GetEntries())).c_str());
	l.SetTextColor(kBlue-3);
	l.DrawLatex(h1->GetXaxis()->GetXmin()+0.4*(h1->GetXaxis()->GetXmax()-h1->GetXaxis()->GetXmin()),0.80*h1->GetMaximum(),(std::string("Background ")+std::to_string((int)h2->GetEntries())).c_str());
	if (lable ) lables1D(canvas,h1);
	canvas->SaveAs((std::string(filename)+".pdf").c_str());
	canvas->SaveAs((PNGPATH+std::string(filename)+".png").c_str());
	canvas->Clear();

	delete empty;
	delete canvas;
}

void superMC_DATAnorm(TH1D* histo1,TH1D* histo2,TH1D* histo3,TH1D* histo4, double x_lable, std::string filename,std::string axis, bool order, bool log){

	histo1->Scale(histo3->Integral()/histo1->Integral());
	histo2->Scale(histo3->Integral()/histo2->Integral());
	histo4->Scale(histo3->Integral()/histo4->Integral());
	TCanvas* canv = new TCanvas("c1","c1",800,600);
	TLatex l;
	std::string PNGPATH = "/eos/home-r/ratramon/www/";
	std::string PDFPATH = "/afs/cern.ch/user/r/ratramon/Bparking/CMSSW_10_2_15/src/macros/newElectronPF/newElectronPF/";

	if (log) canv->SetLogy();
	histo1->SetLineWidth(4);
	histo2->SetLineWidth(4);
	histo3->SetLineWidth(4);
	histo3->SetMarkerStyle(8);
	histo3->SetMarkerSize(1.5);
	histo4->SetMarkerStyle(8);
	histo4->SetMarkerSize(1.5);
	histo3->SetMarkerColor(8);
	histo1->SetLineColor(kRed-6);
	histo2->SetLineColor(kBlue-3);
	histo1->GetXaxis()->SetTitle(axis.c_str());
	histo1->GetYaxis()->SetTitle("entries(normalized to DATA)");
	if(!order){
	histo1->GetXaxis()->SetTitle(axis.c_str());
	histo1->GetYaxis()->SetTitle("entries(normalized to DATA)");
	histo1->Draw("HIST");
	histo2->Draw("sameHIST");
	histo3->Draw("samePE1");
	histo4->Draw("samePE1");
	}else{
	histo2->GetXaxis()->SetTitle(axis.c_str());
	histo2->GetYaxis()->SetTitle("entries(normalized to DATA)");
	histo2->Draw("HIST");
	histo1->Draw("sameHIST");
	histo3->Draw("samePE1");
	histo4->Draw("samePE1");
	}
	l.SetTextSize(0.045);
	l.SetTextAlign(13);
	l.SetTextColor(kRed-6);
	l.DrawLatex(histo1->GetXaxis()->GetXmin()+x_lable*(histo1->GetXaxis()->GetXmax()-histo1->GetXaxis()->GetXmin()),1.*histo1->GetMaximum(),"Signal(MC) ");
	l.SetTextColor(kBlue-3);
	l.DrawLatex(histo1->GetXaxis()->GetXmin()+x_lable*(histo1->GetXaxis()->GetXmax()-histo1->GetXaxis()->GetXmin()),0.9*histo1->GetMaximum(),"Fakes(MC)");
	l.SetTextColor(8);
	l.DrawLatex(histo1->GetXaxis()->GetXmin()+x_lable*(histo1->GetXaxis()->GetXmax()-histo1->GetXaxis()->GetXmin()),0.8*histo1->GetMaximum(),"Fakes(DATAext)");
	l.SetTextColor(kBlack);
	l.DrawLatex(histo1->GetXaxis()->GetXmin()+x_lable*(histo1->GetXaxis()->GetXmax()-histo1->GetXaxis()->GetXmin()),0.7*histo1->GetMaximum(),"Fakes(DATA)");
	
	canv->SaveAs((PDFPATH+filename+".pdf").c_str());
	canv->SaveAs((PNGPATH+filename+".png").c_str());
	
	delete canv;

}

void Fill_MChistos(BSignalElectronClass  *tree, TH1D * PFmvaId,TH1D * pt,TH1D * eta){

	int i;	
	for(i=0;i<tree->fChain->GetEntries();i++){
		tree->fChain->GetEntry(i);
		if (tree->B_l1_isPF==1 ){
			 PFmvaId->Fill(tree->B_l1_mvaId);
			 pt->Fill(tree->B_l1_pt);
			 eta->Fill(tree->B_l1_eta);
		}
		if (tree->B_l2_isPF){
			PFmvaId->Fill(tree->B_l2_mvaId);
			pt->Fill(tree->B_l2_pt);
			eta->Fill(tree->B_l2_eta);
		}
		}


}

void Fill_DATAhistos(BGElectronClass *tree, TH1D * PFmvaId,TH1D * pt,TH1D * eta, int sel){

	int i;
	bool selection;

	for(i=0;i<tree->fChain->GetEntries();i++){
	//std::cout << "In filling " << tree->fChain->GetEntries() << std::endl;	
		tree->fChain->GetEntry(i);
	if (sel==0) selection = true;
	if(sel ==1 ) selection = (tree->DiMuon_mass[0]<3.15 && tree->DiMuon_mass[0]>3 && tree->DiMuon_ToP[0]==1)||(tree->DiMuon_mass[1]<3.15 && tree->DiMuon_mass[1]>3 && tree->DiMuon_ToP[1]==1);
	if(sel ==2 ) selection = (tree->DiMuon_mass[0]<3.15 && tree->DiMuon_mass[0]>3 && tree->DiMuon_ToP[0]==0)||(tree->DiMuon_mass[1]<3.15 && tree->DiMuon_mass[1]>3 && tree->DiMuon_ToP[1]==0);
	if(sel==3)   selection = tree->DiMuon_mass[0]<3.15 && tree->DiMuon_mass[0]>3 && tree->DiMuon_mass[1]<3.15 && tree->DiMuon_mass[1]>3;
		if (!selection) continue;
		for(int j=0; j<tree->nElectrons;j++){
//	if(j%1000==0)std::cout << "histo filling " <<  tree->Ele_isPF[j] << std::endl;	
			if(tree->Ele_isPF[j]){
		
			 PFmvaId->Fill(tree->Ele_pfmvaId[j]);
			 pt->Fill(tree->Ele_pt[j]);
			 eta->Fill(tree->Ele_eta[j]);
		}
		}
		}


}
void Fill_DATAhistosNano(BNanoClass *tree, TH1D * PFmvaId,TH1D * pt,TH1D * eta, int sel){

	int i;
	bool selection;

	for(i=0;i<tree->fChain->GetEntries();i++){
	//std::cout << "In filling " << tree->fChain->GetEntries() << std::endl;	
		tree->fChain->GetEntry(i);
	if (sel==0) selection = true;
//	if(sel ==1 ) selection = (tree->DiMuon_mass[0]<3.15 && tree->DiMuon_mass[0]>3 && tree->DiMuon_ToP[0]==1)||(tree->DiMuon_mass[1]<3.15 && tree->DiMuon_mass[1]>3 && tree->DiMuon_ToP[1]==1);
//	if(sel ==2 ) selection = (tree->DiMuon_mass[0]<3.15 && tree->DiMuon_mass[0]>3 && tree->DiMuon_ToP[0]==0)||(tree->DiMuon_mass[1]<3.15 && tree->DiMuon_mass[1]>3 && tree->DiMuon_ToP[1]==0);
//	if(sel==3)   selection = tree->DiMuon_mass[0]<3.15 && tree->DiMuon_mass[0]>3 && tree->DiMuon_mass[1]<3.15 && tree->DiMuon_mass[1]>3;
		if (!selection) continue;
		for(int j=0; j<tree->nElectron;j++){
//	if(j%1000==0)std::cout << "histo filling " <<  tree->Ele_isPF[j] << std::endl;	
			if(tree->Electron_isPF[j]){
		
			 PFmvaId->Fill(tree->Electron_pfmvaId[j]);
			 pt->Fill(tree->Electron_pt[j]);
			 eta->Fill(tree->Electron_eta[j]);
		}
		}
		}


}
void SavePlot2D (std::string Xstring, std::string Ystring,TH2D * histo,const char*  filename, bool log,bool lable){

	TCanvas* canvas = new TCanvas(Xstring.c_str(),Xstring.c_str(),600,550);
	std::string PNGPATH = "/eos/home-r/ratramon/www/";
//	TH2D * plotter =new TH2D("-","",20,-2.2,0.2,20,-2.2,0.2);
	if (log) canvas->SetLogy();
//	plotter->Draw();
	histo->Draw("COLZtext");
	
	histo->GetXaxis()->SetTitle(Xstring.c_str());
	histo->GetYaxis()->SetTitle(Ystring.c_str());
	if (lable)lables(canvas,histo);
	canvas->SaveAs((std::string(filename)+".pdf").c_str());
	canvas->SaveAs((PNGPATH+std::string(filename)+".png").c_str());

	canvas->Clear();
}

void Slicer(std::string PLOTPATH,int bin,float min, float max,std::string xaxis,TH2D *hist2D,std::string filename){

	int i;
	float x[bin],mean[bin],RMS[bin], *v=0;
	TH1D * proj[bin];
	for(i=0; i<bin;i++){
		x[i]=min +(max-min)/bin*i;
		char range[15]="";
		int n;
		n=sprintf(range,"%.3f;%.3f",x[i],x[i]+(max-min)/bin);
		proj[i]=hist2D->ProjectionX(("nhits in"+std::to_string(i)+"range").c_str(),i,i+1);
		proj[i]->GetXaxis()->SetTitle(xaxis.c_str());
		proj[i]->GetYaxis()->SetTitle("entries");
		mean[i]=proj[i]->GetMean();
		RMS[i]=proj[i]->GetMeanError();

	
	SavePlot (xaxis, proj[i],(PLOTPATH+filename+std::string(range)).c_str() ,false);


	}
	/*TGraphErrors* graph = new TGraphErrors(bin,x,mean,v,RMS);
	TCanvas* canvas = new TCanvas("","",600,550);
	canvas->Clear();
	graph->GetXaxis()->SetTitle("pt(Gev/c)");
	graph->GetYaxis()->SetTitle("mean dr");
	graph->SetMarkerStyle(8);
	graph->GetYaxis()->SetRangeUser(0,1);
	graph->Draw("AP");
	canvas->SaveAs((PLOTPATH+"/"+filename+".pdf").c_str());
	delete canvas;
	delete graph;
*/	for(i=0;i<bin;i++){
		delete proj[i];
	}
}

void AngularCorrection(struct pos* pos, TVector3* vertex,struct pos ECALpoint){
	
	TVector3 clus,vert,diff;
	double radius =400 ;
	clus.SetPtEtaPhi(radius,ECALpoint.eta,ECALpoint.phi);
	vert.SetPtEtaPhi(vertex->Perp(),vertex->Eta(),vertex->Phi());
	diff = clus-vert;
	
	(*pos).x= ECALpoint.x;
	(*pos).y= ECALpoint.y;
	(*pos).z= ECALpoint.z;
	if (diff.Phi() < M_PI)(*pos).phi= diff.Phi();
	else (*pos).phi= diff.Phi()-2*M_PI;

	(*pos).eta= diff.PseudoRapidity();
}

double DeltaR(double phi1, double eta1, double phi2, double eta2){

	double deta = eta1-eta2;
	double dphi = TVector2::Phi_mpi_pi(phi1-phi2);
	return sqrt(deta*deta+dphi*dphi);


}

void setStyle() {


	// set the TStyle
	TStyle* style = new TStyle("DrawBaseStyle", "");
	style->SetCanvasColor(0);
	style->SetPadColor(0);
	style->SetFrameFillColor(0);
	style->SetStatColor(0);
	style->SetOptStat(0);
	style->SetOptFit(0);
	style->SetTitleFillColor(0);
	style->SetCanvasBorderMode(0);
	style->SetPadBorderMode(0);
	style->SetFrameBorderMode(0);
	style->SetPadBottomMargin(0.12);
	style->SetPadLeftMargin(0.12);
	style->cd();
	// For the canvas:
	style->SetCanvasBorderMode(0);
	style->SetCanvasColor(kWhite);
	style->SetCanvasDefH(600); //Height of canvas
	style->SetCanvasDefW(600); //Width of canvas
	style->SetCanvasDefX(0); //POsition on screen
	style->SetCanvasDefY(0);
	// For the Pad:
	style->SetPadBorderMode(0);
	style->SetPadColor(kWhite);
	style->SetPadGridX(false);
	style->SetPadGridY(false);
	style->SetGridColor(0);
	style->SetGridStyle(3);
	style->SetGridWidth(1);
	// For the frame:
	style->SetFrameBorderMode(0);
	style->SetFrameBorderSize(1);
	style->SetFrameFillColor(0);
	style->SetFrameFillStyle(0);
	style->SetFrameLineColor(1);
	style->SetFrameLineStyle(1);
	style->SetFrameLineWidth(1);
	// Margins:
	style->SetPadTopMargin(0.10);
	style->SetPadBottomMargin(0.14);//0.13);
	style->SetPadLeftMargin(0.16);//0.16);
	style->SetPadRightMargin(0.1);//0.02);
	// For the Global title:
	style->SetOptTitle(0);
	style->SetTitleFont(42);
	style->SetTitleColor(1);
	style->SetTitleTextColor(1);
	style->SetTitleFillColor(10);
	style->SetTitleFontSize(0.05);
	// For the axis titles:
	style->SetTitleColor(1, "XYZ");
	style->SetTitleFont(42, "XYZ");
	style->SetTitleSize(0.05, "XYZ");
	style->SetTitleXOffset(1.15);//0.9);
	style->SetTitleYOffset(1.5); // => 1.15 if exponents
	// For the axis labels:
	style->SetLabelColor(1, "XYZ");
	style->SetLabelFont(42, "XYZ");
	style->SetLabelOffset(0.007, "XYZ");
	style->SetLabelSize(0.045, "XYZ");
	// For the axis:
	style->SetAxisColor(1, "XYZ");
	style->SetStripDecimals(kTRUE);
	style->SetTickLength(0.03, "XYZ");
	style->SetNdivisions(510, "XYZ");
	style->SetPadTickX(1); // To get tick marks on the opposite side of the frame
	style->SetPadTickY(1);
	// for histograms:
	style->SetHistLineColor(1);
	// for the pallete
	Double_t stops[5] = { 0.00, 0.34, 0.61, 0.84, 1.00 };
	Double_t red  [5] = { 0.00, 0.00, 0.87, 1.00, 0.51 };
	Double_t green[5] = { 0.00, 0.81, 1.00, 0.20, 0.00 };
	Double_t blue [5] = { 0.51, 1.00, 0.12, 0.00, 0.00 };
	TColor::CreateGradientColorTable(5, stops, red, green, blue, 100);
	style->SetNumberContours(100);

	style->cd();

}

