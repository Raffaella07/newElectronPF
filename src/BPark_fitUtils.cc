#include "../interface/BPark_fitUtils.h"


double SignalWeight(){
	double lumi,n_events;
	lumi = 5.187706291*1e15;
	n_events= 45.16919828*1e15;
	std::string MCpath;

	double crossec_mc;
	crossec_mc = 543100000*1e-12; 
	
	double weight = lumi/n_events;
	
	return weight;


}
void fit(TH1D* hist,int  sigPDF,int bkgPDF, bool res, double sig_yeld, int cat,double * resu){

	std::cout << "in fit________________________ " << std::endl;
	RooWorkspace wspace("w");
	gStyle->SetOptFit(0000);
	gROOT->SetBatch(true);
	gROOT->SetStyle("Plain");
	gStyle->SetGridStyle(3);
	gStyle->SetOptStat(000000);
	gStyle->SetOptTitle(0);
	
	
	TFile* file;
	if (cat ==1 )file  = TFile::Open("MonteC_ip.root");
	else file = TFile::Open("MonteC_ip1.root");
	TTree* tree = (TTree*)file->Get("Tree");
	BCategorizedClass evt;
	evt.Init(tree);

	double xmin, xmax;
	xmin = hist->GetXaxis()->GetXmin()/*+2*hist->GetXaxis()->GetBinWidth(1)*/;
	xmax = hist->GetXaxis()->GetXmax();//-2*hist->GetXaxis()->GetBinWidth(1);
	std::cout << "bin width " << hist->GetXaxis()->GetBinWidth(1) << std::endl;
	TH1D* mB_res = new TH1D("sig_norm","sig_norm",(int)((xmax-xmin)/hist->GetXaxis()->GetBinWidth(1)), xmin, xmax); 
	TH1D* mB_nores = new TH1D("sig_norm","sig_norm",(int)((xmax-xmin)/hist->GetXaxis()->GetBinWidth(1)), xmin, xmax); 

	std::cout << "limits" << xmin << "   " << xmax << std::endl;

	wspace.factory(("x[5.0,"+std::to_string(xmin)+","+std::to_string(xmax)+"]").c_str());


	wspace.factory("nbkg[1000,0,1000000]");
	double lumi = 10.31;
	int c =(int)sig_yeld;
	std::cout << "_____________________________________________histo index " << c << std::endl;

			for(int i =0;i<evt.fChain->GetEntries();i++){
				
				evt.fChain->GetEntry(i);
				
				int j =0;		
				if (c==0){
				for(int j=0; j< evt.nSaved; j++){
					
					if (evt.BToKEE_mll_fullfit[j] >3 &&  evt.BToKEE_mll_fullfit[j]<3.3)mB_res->Fill(evt.BToKEE_fit_mass[j],lumi/45.17);

					else if (evt.BToKEE_mll_llfit[j]<2.5) mB_nores->Fill(evt.BToKEE_fit_mass[j],lumi/45.17);

				}
				}
				else {

				for(int j=0; j< evt.nSaved; j++){
				if (evt.category ==0 && c ==1 &&  evt.BToKEE_l1_isPF[j]){
						
					if (evt.BToKEE_mll_fullfit[j] >3 &&  evt.BToKEE_mll_fullfit[j]<3.3)mB_res->Fill(evt.BToKEE_fit_mass[j],lumi/45.17);

					else if (evt.BToKEE_mll_llfit[j]<2.5) mB_nores->Fill(evt.BToKEE_fit_mass[j],lumi/45.17);


					}else if (evt.category == 0 && c == 2 &&  evt.BToKEE_l1_isLowPt[j]){
						
					if (evt.BToKEE_mll_fullfit[j] >3 &&  evt.BToKEE_mll_fullfit[j]<3.3)mB_res->Fill(evt.BToKEE_fit_mass[j],lumi/45.17);

					else if (evt.BToKEE_mll_llfit[j]<2.5) mB_nores->Fill(evt.BToKEE_fit_mass[j],lumi/45.17);


					}else if ( c >2  && evt.category==c-2){
					if (evt.BToKEE_mll_fullfit[j] >3 &&  evt.BToKEE_mll_fullfit[j]<3.3)mB_res->Fill(evt.BToKEE_fit_mass[j],lumi/45.17);

					else if (evt.BToKEE_mll_llfit[j]<2.5) mB_nores->Fill(evt.BToKEE_fit_mass[j],lumi/45.17);
					}
				}
				
				
			}
		}
	/*for (int i=0; i<hist->GetNbinsX();i++){

	  if (hist->GetXaxis()->GetBinLowEdge(i)>4.9 &&  hist->GetXaxis()->GetBinUpEdge(i)<5.5) hist->SetBinContent(i,0);

	  }*/
/*	for(int i;i<evt.fChain->GetEntries();i++){
		evt.fChain->GetEntry(i);
		if ( res && evt.BToKEE_mll_raw >3 &&  evt.BToKEE_mll_raw<3.3)mB->Fill(evt.BToKEE_mass,10.31/45.17);
				
			if(evt.BToKEE_l1pt<= 5 ){
					if( evt.BToKEE_l2pt<= 5 && fabs(evt.BToKEE_l2eta)< 1.5){
					
					if (evt.BToKEE_l1pfmvaId >= low_pfmvaId && evt.BToKEE_l2pfmvaId >= low_pfmvaId )
						{ 
								if ( res &&evt.BToKEE_mll_raw >3 &&  evt.BToKEE_mll_raw<3.3)mB->Fill(evt.BToKEE_mass,10.31/45.17);
								else if (!res && evt.BToKEE_mll_llfit<2.5) mB->Fill(evt.BToKEE_fit_mass,10.31/1.53E+04);

						}
					}else{
					if (evt.BToKEE_l1pfmvaId >= low_pfmvaId  && evt.BToKEE_l2pfmvaId >= high_pfmvaId )
						{ 
								if ( res && evt.BToKEE_mll_raw>3 &&  evt.BToKEE_mll_raw<3.3)mB->Fill(evt.BToKEE_mass,10.31/45.17);
								else if (!res && evt.BToKEE_mll_llfit<2.5) mB->Fill(evt.BToKEE_fit_mass,10.31/1.53E+04);

						}

					}

				}else{
				
					if( evt.BToKEE_l2pt< 5 && fabs(evt.BToKEE_l2eta)< 1.5){
					
					if (evt.BToKEE_l1pfmvaId > high_pfmvaId && evt.BToKEE_l2pfmvaId > low_pfmvaId )
						{ 
								if ( res && evt.BToKEE_mll_raw>3 &&  evt.BToKEE_mll_raw<3.3)mB->Fill(evt.BToKEE_mass,10.31/45.17);
								else if (!res && evt.BToKEE_mll_llfit<2.5) mB->Fill(evt.BToKEE_fit_mass,10.31/1.53E+04);

						}
					}else{
					if (evt.BToKEE_l1pfmvaId > high_pfmvaId  && evt.BToKEE_l2pfmvaId > high_pfmvaId )
						{ 
								if (res && evt.BToKEE_mll_raw>3 &&  evt.BToKEE_mll_raw<3.3)mB->Fill(evt.BToKEE_mass,10.31/45.17);
								else if (!res && evt.BToKEE_mll_llfit<2.5) mB->Fill(evt.BToKEE_fit_mass,10.31/1.53E+04);

						}

					}

				}
	}*/
	//sig_yeld= sig_yeld* 5.5*1e-7/0.0000618;
	sig_yeld = mB_res->Integral();
	std::cout << "sig yield " << sig_yeld << std::endl;
	if (((c!=1 ) && res)|| !res )wspace.factory(("nsig["+std::to_string(sig_yeld)+","+std::to_string(sig_yeld)+","+std::to_string(sig_yeld)+"]").c_str());
	else if ((c==2 ))wspace.factory(("nsig["+std::to_string(sig_yeld)+",0,200000]").c_str());
	else wspace.factory("nsig[200,0,1000000]");
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
		//wspace.factory("mean[3.0969+00, 3.06e+00, 3.10e+00]");
		wspace.factory("mean[5.27929e+00, 5.2e+00, 5.3e+00]");
		wspace.factory("sigma[7.1858e-02, 1.e-3, 7.e-2]");
		wspace.factory("Voigtian::sig(x,mean,width,sigma)");
	}
	if (sigPDF == 1){
		// Gaussian
		wspace.factory("mean[5.2418e+00, 5.20e+00, 5.35e+00]");
		//	wspace.factory("mean[3.0969+00, 3.06e+00, 3.10e+00]");
		wspace.factory("sigma[7.477e-02, 7.477e-02, 7.477e-02]");
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
		//wspace.factory("c3[-0.1, -10.0, 10.0]");
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
		wspace.factory("Chebychev::bkg(x,{c0,c1,c2,c3,c4})");
	}

	if (c == 1 || c==2 )wspace.factory("SUM::model(nsig*sig,nbkg*bkg)");
	else wspace.factory("SUM::model(nbkg*bkg)");

	RooAbsPdf* mod = wspace.pdf("model");
	RooAbsPdf* bkg = wspace.pdf("bkg");
	RooAbsPdf* sig = wspace.pdf("sig");
	//bkg = wspace.pdf("bkg");

	wspace.defineSet("obs","x");
	RooArgList list = RooArgList(*wspace.set("obs"));








	RooDataHist data = RooDataHist("data","data",list,hist);
	//RooAddPdf mod("model", "s+b",RooArgList(*wspace.obj("model")));
	RooFitResult* result = mod->fitTo(data,RooFit::Save(),RooFit::Extended(kTRUE)/*,RooFit::Range("low","high")*/);
	result->Print(); 
	std::cout << "sigma " << wspace.var("sigma")->getVal() << std::endl;
	wspace.var("x")->setRange("window",wspace.var("mean")->getVal()-1.5*wspace.var("sigma")->getVal(),wspace.var("mean")->getVal()+1.5*wspace.var("sigma")->getVal());
	RooAbsReal* fracBkgRange = bkg->createIntegral(*wspace.set("obs"),*wspace.set("obs"),"window") ;
	RooAbsReal* fracSigRange = sig->createIntegral(*wspace.set("obs"),*wspace.set("obs"),"window") ;
	double  nbkgWindow = wspace.var("nbkg")->getVal() * fracBkgRange->getVal();
	double  nSigWindow = wspace.var("nsig")->getVal() * fracSigRange->getVal();
	// 	print(nbkg.getVal(), fracBkgRange.getVal());
	std::cout << "Number of signals:" << nSigWindow << ", Number of background: " << nbkgWindow << ", S/sqrt(S+B): " << nSigWindow/sqrt(nSigWindow + nbkgWindow)<< std::endl;
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
	mB_res->SetLineColor(kOrange+8);
	mB_res->SetLineWidth(3);
	mB_res->Draw("samehist");

	TLegend* l;
	if(c == 1) l = new TLegend(0.67,0.55,0.95,0.90);
	else  l = new TLegend(0.67,0.15,0.95,0.50);
	//	l->SetTextFont(72);
	l->SetTextSize(0.04);
	l->AddEntry(xframe->findObject("data"),"Data","lpe");
	l->AddEntry(xframe->findObject("bkg"),"Background fit","l");
	l->AddEntry(xframe->findObject("sig"),"Signal fit","l");
	
	char v1[10],v2[10];
	sprintf(v1,"%.2f",nSigWindow);
	sprintf(v2,"%.2f", nbkgWindow);
	l->AddEntry("" ,("S = "+std::string(v1)).c_str(),"");
	l->AddEntry("",("B = "+std::string(v2)).c_str(),"");
	char v[10];
	sprintf(v,"%.2f",nSigWindow/sqrt(nSigWindow + nbkgWindow));
	l->AddEntry("" ,("S/#sqrt{S+B} = "+std::string(v)).c_str(),"");
	l->Draw();

	if (res)c2->SaveAs(("fit_peak"+std::to_string(c)+"_"+std::to_string(cat)+".pdf").c_str());
	else c2->SaveAs("fit_nores.pdf");
	std::cout << " S/sqrt(S+B): " << nSigWindow/sqrt(nSigWindow + nbkgWindow)<< std::endl;
	std::pair<double,double> pair = std::make_pair(nSigWindow,nbkgWindow);
	std::cout << " S " << pair.first<< std::endl;
	std::cout << " S/sqrt(S+B): " << pair.second<< std::endl;
	resu[0] = nSigWindow;
	resu[1] = wspace.var("nsig")->getError() * fracSigRange->getVal();
	resu[2] = nbkgWindow;
	resu[3] = wspace.var("nbkg")->getError() * fracBkgRange->getVal();
	delete mB_res;
	delete mB_nores;

}
