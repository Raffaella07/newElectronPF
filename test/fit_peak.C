//#include "../interface/BParkTools.h"
#include "RooWorkspace.h"
#include "../src/BSignalElectronClass.cc"



int fit(TH1F* hist,int  sigPDF,int bkgPDF, std::string mc){

	RooWorkspace wspace("w");
	gStyle->SetOptFit(0000);
	gROOT->SetBatch(true);
	gROOT->SetStyle("Plain");
	gStyle->SetGridStyle(3);
	gStyle->SetOptStat(000000);
	gStyle->SetOptTitle(0);
	
	TFile* file = TFile::Open(mc.c_str());
	TTree* tree = (TTree*)file->Get("Tree");
	BSignalElectronClass evt;
	evt.Init(tree);
	
	double xmin, xmax;
	xmin = 2; //hist->GetXaxis()->GetXmin()+2*hist->GetXaxis()->GetBinWidth(1);
	xmax = 3.8;//hist->GetXaxis()->GetXmax();//-2*hist->GetXaxis()->GetBinWidth(1);
	TH1D* sig_norm = new TH1D("sig_norm","sig_norm",(int)((xmax-xmin)/hist->GetXaxis()->GetBinWidth(1)), xmin, xmax); 

	cout << "limits" << xmin << "   " << xmax << endl;
	
	wspace.factory(("x[3.0,"+std::to_string(xmin)+","+std::to_string(xmax)+"]").c_str());

	wspace.factory("nsig[200,0,100000]");
	wspace.factory("nbkg[1000,0,1000000]");
		
	/*for (int i=0; i<hist->GetNbinsX();i++){

	if (hist->GetXaxis()->GetBinLowEdge(i)>4.9 &&  hist->GetXaxis()->GetBinUpEdge(i)<5.5) hist->SetBinContent(i,0);

	}*/
	
	for(int i;i<evt.fChain->GetEntries();i++){
	evt.fChain->GetEntry(i);
	sig_norm->Fill(evt.B_mll_raw,5.18/45.17);
	}

	wspace.var("x");
	wspace.var("mean");
	wspace.var("sigma");
	wspace.var("nsig");
	wspace.var("nbkg");

	//wspace.var("x")->setRange("low",xmin,4.9);
	//wspace.var("x")->setRange("high",5.5,xmax);

	if (sigPDF == 0){
		// Voigtian
		wspace.factory("width[1.000e-02, 1.000e-04, 1.000e-01]");
		wspace.factory("mean[3.0969+00, 3.06e+00, 3.10e+00]");
		//wspace.factory("mean[5.27929e+00, 5.2e+00, 5.3e+00]");
		wspace.factory("sigma[7.1858e-02, 1.e-3, 7.e-2]");
		wspace.factory("Voigtian::sig(x,mean,width,sigma)");
	}
	if (sigPDF == 1){
		// Gaussian
	//	wspace.factory("mean[5.2418e+00, 5.20e+00, 5.35e+00]");
		wspace.factory("mean[3.0969+00, 3.06e+00, 3.10e+00]");
		wspace.factory("sigma[7.1858e-02, 1.e-3, 7.e-2]");
		wspace.factory("Gaussian::sig(x,mean,sigma)");
	}
	if (sigPDF == 2){
		// Crystal-ball
		//wspace.factory("mean[5.2418e+00, 5.20e+00, 5.35e+00]");
		wspace.factory("mean[3.0969+00, 3.06e+00, 3.10e+00]");
		wspace.factory("sigma[7.1858e-02, 1.e-3, 5.e-2]");
		wspace.factory("alpha[-0.5, -1.0e+2, 1.0e+2]");
		wspace.factory("n[10, 0, 100]");
		wspace.factory("CBShape::sig(x,mean,sigma,alpha,n)");
	}
	if (bkgPDF == 0){
		// Polynomial
		wspace.factory("c0[1.0, -1.0, 10.0]");
		wspace.factory("c1[-0.1, -1.0, 10.0]");
		wspace.factory("c2[-0.1, -10.0, 10.0]");
	//	wspace.factory("c3[-0.1, -10.0, 10.0]");
	//	wspace.factory("c4[-0.1, -10.0, 10.0]");
		wspace.factory("Chebychev::bkg(x,{c0,c1,c2})");
	}
	if (bkgPDF == 1){
		wspace.factory("c1[0.0, -100.0, 100.0]");
		wspace.factory("Polynomial::bkg(x,{c1})");
	}
	if (bkgPDF == 2){
		// Exponential
		wspace.factory("exp_alpha[-10.0, -100.0, -1]");
		wspace.factory("Exponential::bkg(x,exp_alpha)");
	}
	if (bkgPDF == 3){
		// Polynomial
		wspace.factory("c0[1.0, -1.0, 10.0]");
		wspace.factory("c1[0, -1.0, 1.0]");
		wspace.factory("c2[0, -1.0, 1.0]");
		wspace.factory("c3[0, -1, 1]");
		wspace.factory("c4[0, -1, 1]");
		wspace.factory("Chebychev::bkg(x,{c0,c1,c2,c3})");
	}

	wspace.factory("SUM::model(nsig*sig,nbkg*bkg)");

	RooAbsPdf* mod = wspace.pdf("model");
	RooAbsPdf* bkg = wspace.pdf("bkg");
	RooAbsPdf* sig = wspace.pdf("sig");
	//bkg = wspace.pdf("bkg");

	wspace.defineSet("obs","x");
	RooArgList l = RooArgList(*wspace.set("obs"));

	RooDataHist data = RooDataHist("data","data",l,hist);
	//RooAddPdf mod("model", "s+b",RooArgList(*wspace.obj("model")));
	RooFitResult* result = mod->fitTo(data,RooFit::Save(),RooFit::Extended(kTRUE)/*,RooFit::Range("low","high")*/);
	result->Print(); 

	 TCanvas* c2 =new TCanvas("fig_binnedFit", "fit", 800, 600);
		c2->SetGrid();
		c2->cd();
		gPad->SetLeftMargin(0.10);
		gPad->SetRightMargin(0.05);

		RooPlot* xframe = wspace.var("x")->frame();
		data.plotOn(xframe, RooFit::Name("data"));
		mod->plotOn(xframe,RooFit::Name("model"),RooFit::LineColor(2),RooFit::MoveToBack()); // this will show fit overlay on canvas
		mod->plotOn(xframe,RooFit::Name("model"),RooFit::Components("bkg"),RooFit::LineStyle(kDashed),RooFit::LineColor(kMagenta));
	mod->plotOn(xframe,RooFit::Name("sig"),RooFit::Components("sig"),RooFit::DrawOption("FL"),RooFit::FillColor(9),RooFit::FillStyle(3004),RooFit::LineStyle(6),RooFit::LineColor(9)) ;
//	mod->plotOn(xframe,RooFit::VisualizeError(result), RooFit::FillColor(kOrange), RooFit::MoveToBack())// # this will show fit overlay on canvas

		xframe->GetYaxis()->SetTitleOffset(0.9);
		xframe->GetYaxis()->SetTitleFont(42);
		xframe->GetYaxis()->SetTitleSize(0.05);
		xframe->GetYaxis()->SetLabelSize(0.065);
		xframe->GetYaxis()->SetLabelSize(0.04);
		xframe->GetYaxis()->SetLabelFont(42);
		xframe->GetXaxis()->SetTitleOffset(0.9);
		xframe->GetXaxis()->SetTitleFont(42);
		xframe->GetXaxis()->SetTitleSize(0.05);
		xframe->GetXaxis()->SetLabelSize(0.065);
		xframe->GetXaxis()->SetLabelSize(0.04);
		xframe->GetXaxis()->SetLabelFont(42);

		xframe->GetYaxis()->SetTitle("Events");
		xframe->GetXaxis()->SetTitle("m(K^{+}e^{+}e^{-}) [GeV/c^{2}]");
//xframe.GetXaxis().SetTitle("m(e^{+}e^{-}) [GeV/c^{2}]")
		xframe->SetStats(0);
		xframe->SetMinimum(0);
		xframe->Draw();
		sig_norm->SetLineColor(kOrange+8);
		sig_norm->SetLineWidth(3);
		sig_norm->Draw("samehist");
		
		
		c2->SaveAs("fit_peak.pdf");
		return 1;

}

