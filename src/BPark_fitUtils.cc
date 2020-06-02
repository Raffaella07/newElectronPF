#include "../interface/BPark_fitUtils.h"
#include "../../../FitTools/RooDoubleCBShape.cxx"

#define BR_NORES  5.50E-07
#define BR_RES  0.0000618

TString cmsText     = "CMS";
float cmsTextFont   = 61;  // default is helvetic-bold

bool writeExtraText = false;
TString extraText   = "Preliminary";
float extraTextFont = 52;  // default is helvetica-italics

// text sizes and text offsets with respect to the top frame
// in unit of the top margin size
float lumiTextSize     = 0.6;
float lumiTextOffset   = 0.2;
float cmsTextSize      = 0.75;
float cmsTextOffset    = 0.1;  // only used in outOfFrame version

float relPosX    = 0.045;
float relPosY    = 0.035;
float relExtraDY = 1.2;

// ratio of "CMS" and extra text size
float extraOverCmsTextSize  = 0.76;

TString lumi_13TeV = "20.1 fb^{-1}";
TString lumi_8TeV  = "19.7 fb^{-1}";
TString lumi_7TeV  = "5.1 fb^{-1}";
TString lumi_sqrtS = "";

bool drawLogo      = false;

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

void CMS_lumi( TPad* pad, int iPeriod, int iPosX, double lumi )
{            
	bool outOfFrame    = false;
	if( iPosX/10==0 ) 
	{
		outOfFrame = true;
	}
	int alignY_=3;
	int alignX_=2;
	if( iPosX/10==0 ) alignX_=1;
	if( iPosX==0    ) alignX_=1;
	if( iPosX==0    ) alignY_=1;
	if( iPosX/10==1 ) alignX_=1;
	if( iPosX/10==2 ) alignX_=2;
	if( iPosX/10==3 ) alignX_=3;
	//if( iPosX == 0  ) relPosX = 0.12;
	int align_ = 10*alignX_ + alignY_;

	float H = pad->GetWh();
	float W = pad->GetWw();
	float l = pad->GetLeftMargin();
	float t = pad->GetTopMargin();
	float r = pad->GetRightMargin();
	float b = pad->GetBottomMargin();
	//  float e = 0.025;

	pad->cd();

	TString lumiText;
	if( iPeriod==1 )
	{
		lumiText += lumi_7TeV;
		lumiText += " (7 TeV)";
	}
	else if ( iPeriod==2 )
	{
		lumiText += lumi_8TeV;
		lumiText += " (8 TeV)";
	}
	else if( iPeriod==3 ) 
	{
		lumiText = lumi_8TeV; 
		lumiText += " (8 TeV)";
		lumiText += " + ";
		lumiText += lumi_7TeV;
		lumiText += " (7 TeV)";
	}
	else if ( iPeriod==4 )
	{
		lumiText += lumi_13TeV;
		lumiText += " (13 TeV)";
	}
	else if ( iPeriod==7 )
	{ 
		if( outOfFrame ) lumiText += "#scale[0.85]{";
		lumiText += lumi_13TeV; 
		lumiText += " (13 TeV)";
		lumiText += " + ";
		lumiText += lumi_8TeV; 
		lumiText += " (8 TeV)";
		lumiText += " + ";
		lumiText += lumi_7TeV;
		lumiText += " (7 TeV)";
		if( outOfFrame) lumiText += "}";
	}
	else if ( iPeriod==12 )
	{
		lumiText += "8 TeV";
	}
	else if ( iPeriod==0 )
	{
		lumiText += lumi_sqrtS;
	}
	else if ( iPeriod==5 )
	{
		lumiText += lumi;
		lumiText +=  " fb^{-1}";
	}

	std::cout << lumiText << std::endl;

	TLatex latex;
	latex.SetNDC();
	latex.SetTextAngle(0);
	latex.SetTextColor(kBlack);    

	float extraTextSize = extraOverCmsTextSize*cmsTextSize;

	latex.SetTextFont(42);
	latex.SetTextAlign(31); 
	latex.SetTextSize(lumiTextSize*t);    
	latex.DrawLatex(1-r,1-t+lumiTextOffset*t,lumiText);

	if( outOfFrame )
	{
		latex.SetTextFont(cmsTextFont);
		latex.SetTextAlign(11); 
		latex.SetTextSize(cmsTextSize*t);    
		latex.DrawLatex(l,1-t+lumiTextOffset*t,cmsText);
	}

	pad->cd();

	float posX_=0;
	if( iPosX%10<=1 )
	{
		posX_ =   l + relPosX*(1-l-r);
	}
	else if( iPosX%10==2 )
	{
		posX_ =  l + 0.5*(1-l-r);
	}
	else if( iPosX%10==3 )
	{
		posX_ =  1-r - relPosX*(1-l-r);
	}
	float posY_ = 1-t - relPosY*(1-t-b);
	if( !outOfFrame )
	{
		if( drawLogo )
		{
			posX_ =   l + 0.045*(1-l-r)*W/H;
			posY_ = 1-t - 0.045*(1-t-b);
			float xl_0 = posX_;
			float yl_0 = posY_ - 0.15;
			float xl_1 = posX_ + 0.15*H/W;
			float yl_1 = posY_;
			//	TASImage* CMS_logo = new TASImage("CMS-BW-label.png");
			TPad* pad_logo = new TPad("logo","logo", xl_0, yl_0, xl_1, yl_1 );
			pad_logo->Draw();
			pad_logo->cd();
			//		CMS_logo->Draw("X");
			pad_logo->Modified();
			pad->cd();
		}
		else
		{
			latex.SetTextFont(cmsTextFont);
			latex.SetTextSize(cmsTextSize*t);
			latex.SetTextAlign(align_);
			latex.DrawLatex(posX_, posY_, cmsText);
			if( writeExtraText ) 
			{
				latex.SetTextFont(extraTextFont);
				latex.SetTextAlign(align_);
				latex.SetTextSize(extraTextSize*t);
				latex.DrawLatex(posX_, posY_- relExtraDY*cmsTextSize*t, extraText);
			}
		}
	}
	else if( writeExtraText )
	{
		if( iPosX==0) 
		{
			posX_ =   l +  relPosX*(1-l-r);
			posY_ =   1-t+lumiTextOffset*t;
		}
		latex.SetTextFont(extraTextFont);
		latex.SetTextSize(extraTextSize*t);
		latex.SetTextAlign(align_);
		latex.DrawLatex(posX_, posY_, extraText);      
	}
	return;
}


double mc_templEff(BminiMCTree* evt, TH1D* hist,TTree* tree, bool res,int set,int cat, double cut ){
	//this function fill the histogram of mass spectum with MC data passing the same selection of data and returns as double the efficiency for each BDT cut

	int i,n=0,n_tot=0;	
	bool mass_sel;
	double mass;

	if (tree != NULL)tree->Branch("x",&mass);
	//std::cout << "here!! " << std::endl;
	for(int i =0;i<evt->fChain->GetEntries();i++){

		evt->fChain->GetEntry(i);
		if (res) mass_sel = evt->ll_mass<3.25 && evt->ll_mass>2.45;
		else mass_sel = evt->ll_mass<2.45;
		if (set==0 && evt->cat1 == cat && evt->is_MC &&  mass_sel){
			if (evt->BDT_1>cut ){
				n++;
			std::cout <<"n" << n << std::endl;
				mass = evt->B_mass;
				if (tree !=NULL) tree->Fill();
				if (hist != NULL )hist ->Fill(evt->B_mass);
			}
			n_tot++;
			std::cout <<"ntot" << n_tot << std::endl;



		}else if (set==1 && evt->is_MC && evt->cat0 == cat && mass_sel){
			if (evt->BDT_0>cut){
				mass = evt->B_mass;
				n++;
				if(hist != NULL)hist ->Fill(evt->B_mass);
				if (tree != NULL) tree->Fill();
			}
			n_tot++;


		}
	}

	std::cout << n_tot << std::endl;
	return (double)n/n_tot;


}




void fit(TH1D* hist,int  sigPDF,int bkgPDF, bool res, int set, int cat, double cut, double * resu){

	std::cout << "in fit________________________ " << std::endl;
	RooWorkspace wspace("w");
	gStyle->SetOptFit(0000);
	gROOT->SetBatch(true);
	gROOT->SetStyle("Plain");
	gStyle->SetGridStyle(3);
	gStyle->SetOptStat(000000);
	gStyle->SetOptTitle(0);

	double eff_ratio[2][3];	
	eff_ratio[0][0]=179014./445406;
	eff_ratio[0][1]=282107./694615;
	eff_ratio[0][2]=107921./238498;
	eff_ratio[1][0]=204670./507489;
	eff_ratio[1][1]=251268./593246;
	eff_ratio[1][2]=112934./277784;

	std::string PNGPATH = "/eos/home-r/ratramon/www/fit/";
	TFile* f_res;
	TFile*f_nores;
	TFile*f_misreco;

	f_res  = TFile::Open("mini_mc_res.root");
	f_nores = TFile::Open("mini_mc_nores.root");
	f_misreco = TFile::Open("misreco_mini.root");
	//f_hist = TFile::Open("/afs/cern.ch/work/r/ratramon/Bparking/CMSSW_10_2_15/src/FitTools/histotree.root");
	 
	TTree histotree("hist","misreconstructed events distribution from K*");
	TTree* tree_res = (TTree*)f_res->Get("Mini");
	TTree* tree_nores = (TTree*)f_nores->Get("Mini");
	TTree* tree_misreco = (TTree*)f_misreco->Get("Mini");
	std::cout << "in fit________1_______________ " << std::endl;
	BminiMCTree evt_res, evt_nores,evt_misreco;

	std::cout << "in fit________2_______________ " << std::endl;
	evt_res.Init(tree_res);
	evt_nores.Init(tree_nores);
	evt_misreco.Init(tree_misreco);

	TH1D* templ = new TH1D("templ","templ",50,4.7,5.7);
	TH1D* templ_misreco = new TH1D("templ_misreco","templ_misreco",50,4.5,6);
	TH1D* templ_nores = new TH1D("templ_misreco","templ_misreco",50,4.5,6);

	std::cout << "in fit________3_______________ " << std::endl;
	int n_res, n_nores, n_totR, n_totNR;
	n_res =0;
	n_nores =0;
	n_totR=0;
	n_totNR=0;
	double eff_res, eff_nores,eff_misreco;
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
	int c =set;
	std::cout << "_____________________________________________histo index " << c << std::endl;
	/*		for(int i =0;i<evt_res.fChain->GetEntries();i++){

			evt_res.fChain->GetEntry(i);
			if (set==0 && evt_res.cat1 == cat && evt_res.is_MC && evt_res.ll_mass<3.25 && evt_res.ll_mass>2.45){
			if (evt_res.BDT_1>cut ){
			n_res++;
			templ ->Fill(evt_res.B_mass);
			}
			n_totR++;



			}else if (set==1 && evt_res.is_MC && evt_res.cat0 == cat && evt_res.ll_mass<3.25 && evt_res.ll_mass>2.5){
			if (evt_res.BDT_0>cut){
			templ ->Fill(evt_res.B_mass);
			n_res++;
			}
			n_totR++;


			}
			}

			std::cout << "eff_res" << (double)n_res/n_totR << std::endl;
			eff_res = (double)n_res/n_totR;
			for(int i =0;i<evt_nores.fChain->GetEntries();i++){

			evt_nores.fChain->GetEntry(i);
			if (set==0 && evt_nores.cat1 == cat && evt_nores.ll_mass<2.5 ){
	//templ ->Fill(evt_nores.B_mass);
	if (evt_nores.BDT_1>cut ) n_nores++;
	n_totNR++;



	}else if (set==1 && evt_nores.cat0 == cat && evt_nores.ll_mass<2.5 ){
	//templ ->Fill(evt_nores.B_mass);
	if (evt_nores.BDT_0>cut) n_nores++;
	n_totNR++;


	}
	}
	std::cout << "eff_nores" << (double)n_nores/n_totNR << std::endl;*/

	//eff_res = mc_templEff(&evt_res, templ,NULL,1,set,cat,cut);
	//eff_misreco = mc_templEff(&evt_misreco,NULL,&histotree,1,set,cat,cut);
	eff_nores = mc_templEff(&evt_nores, templ_nores,NULL,0,set,cat,cut);

	std::cout << eff_res << " " << eff_nores << " " << eff_misreco << std::endl;	

	std::cout << templ->GetEntries() << std::endl;
	wspace.factory("nsig[100,0,1000000]");
	wspace.factory("pippo[10,0,1000000]");
	wspace.factory("x1[5.2,4.5,6]");
	wspace.factory("mario[10,0,1000000]");
	wspace.factory("nmisreco[1000,0,1000000]");
	wspace.var("x");
	wspace.var("x1");
	wspace.var("mean");
	wspace.var("sigma");
	wspace.var("nsig");
	wspace.var("nbkg");
	wspace.var("pippo");
	wspace.var("mario");
	wspace.var("nmisreco");
	wspace.var("alpha1");
	wspace.var("alpha2");
	wspace.var("n1");
	wspace.var("n2");
	//RooDoubleCBShape DoubleCB("DoubleCBShape","DoubleCBShape",*wspace.var("x"),*wspace.var("mean"),*wspace.var("sigma"),*wspace.var("alpha1"),*wspace.var("n1"),*wspace.var("alpha2"),*wspace.var("n2"));
	//	wspace.import(DoubleCB);		
	//wspace.var("npred");

	//wspace.var("x")->setRange("low",xmin,4.9);
	//wspace.var("x")->setRange("high",5.5,xmax);

	std::cout << "histo stdev" << templ->GetStdDev() << std::endl; 
	if (sigPDF == 0){
		// Voigtian
		wspace.factory("width[1.000e-02, 1.000e-04, 1.000e-01]");
		//wspace.factory("mean[3.0969+00, 3.06e+00, 3.10e+00]");
	//	wspace.factory("mean[5.279e+00, 5.26e+00, 5.29e+00]");
			wspace.factory(("mean["+std::to_string(templ->GetXaxis()->GetBinCenter(templ->GetMaximumBin()))+","+std::to_string(templ->GetXaxis()->GetBinCenter(templ->GetMaximumBin())-3*templ->GetStdDev())+", "+std::to_string(templ->GetXaxis()->GetBinCenter(templ->GetMaximumBin())+3*templ->GetStdDev())+"]").c_str());
		wspace.factory(("sigma["+std::to_string(0.1*templ->GetStdDev())+", 1.e-3, 7.e-2]").c_str());
		wspace.factory("Voigtian::Voigt(x,mean,width,sigma)");
	}
	if (sigPDF == 1){
		// Gaussian
		wspace.factory("mean[5.2418e+00, 5.20e+00, 5.35e+00]");
		//	wspace.factory("mean[3.0969+00, 3.06e+00, 3.10e+00]");
		wspace.factory("sigma[7.477e-02, 7.477e-02, 7.477e-02]");
		//	wspace.factory("Gaussian::sig(x,mean,sigma)");
	}
	if (sigPDF == 0){
		// Crystal-ball
		//	wspace.factory("mean[5.279e+00, 5.26e+00, 5.29e+00]");
		//	wspace.factory("mean[3.0969+00, 3.06e+00, 3.10e+00]");
		//	wspace.factory("sigma[3.1858e-02, 1.e-3, 7.e-2]");
		//		wspace.factory("sA[0, -1.e-3, 5.e-2]");
		wspace.factory("alpha1[0.5,0 ,100]");
		wspace.factory("alpha2[-1,-100 ,0]");
		//	wspace.factory("alpha2[-0.5,-1 , 1.0e+2]");
		wspace.factory("n1[1, -2, 10]");
		wspace.factory("n2[1, -2, 10]");
		//	wspace.factory("n2[1, 0, 10]");
		wspace.factory("CBShape::CB1(x,mean,sigma,alpha1,n1)");
		wspace.factory("CBShape::CB2(x,mean,sigma,alpha2,n2)");
	}
	if (bkgPDF == 0){
		// Polynomial
		wspace.factory("c0[1.0, -10.0, 10.0]");
		wspace.factory("c1[-0.1, -10.0, 10.0]");
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

	wspace.defineSet("obs","x");
	//wspace.defineSet("obs1","x1");
	RooArgList list = RooArgList(*wspace.set("obs"));

	RooDataSet d("d","d",&histotree,*wspace.set("obs"),"","");
	RooKeysPdf misreco2("misr","misr", *wspace.var("x"),d,RooKeysPdf::MirrorBoth,1);
	wspace.import(misreco2);

	if (res)
	{
		wspace.factory("SUM::sig(pippo*CB1,mario*CB2)");
		wspace.factory("SUM::model(nsig*sig,nbkg*bkg, nmisreco*misr)");
		wspace.factory("SUM::signal(nsig*sig)");
	}
	else{ 
		wspace.factory("SUM::sig(pippo*CB1,mario*CB2)");
		wspace.factory("SUM::model(nbkg*bkg, nmisreco*misr)");
		wspace.factory("SUM::signal(nsig*sig)");
	}
	RooAbsPdf* signal= wspace.pdf("signal");
	RooAbsPdf* mod = wspace.pdf("model");
	RooAbsPdf* bkg = wspace.pdf("bkg");
	RooAbsPdf* sig = wspace.pdf("sig");
	//bkg = wspace.pdf("bkg");
	std::cout << "sigma " << wspace.var("sigma")->getVal() << std::endl;

	RooKeysPdf misreco1("mis","mis", *wspace.var("x"),d,RooKeysPdf::MirrorBoth,1.5);
	//	RooKeysPdf misreco2("misNo","misNo", *wspace.var("x1"),d,RooKeysPdf::NoMirror);
	TCanvas* c3 =new TCanvas("template misreco", "template misreco", 800, 600);
	RooPlot* misframe = wspace.var("x")->frame();
	RooBinning b(50,4.5,6);
	d.plotOn(misframe,RooFit::Binning(b));
	misreco1.plotOn(misframe);
	//    	misreco2.plotOn(misframe, RooFit::LineStyle(kDashed), RooFit::LineColor(kRed));
	misframe->Draw();
	c3->SaveAs((PNGPATH+"fit_misrecoMC"+std::to_string((int)set)+"_"+std::to_string(cat)+"_"+std::to_string(cut)+".png").c_str());
	RooDataHist mc_template = RooDataHist("template fit","template fit",list,templ);
	std::cout << " _____________________________________________________________________________________________________DEBUG "  << std::endl;
	RooFitResult* template_par = signal->fitTo(mc_template,RooFit::Save()/*,RooFit::Extended(kTRUE)*/);

	TCanvas* c1 =new TCanvas("MC_Fit", "fit", 800, 600);
	RooPlot* xmcframe = wspace.var("x")->frame();
	mc_template.plotOn(xmcframe, RooFit::Name("template fit"));
	if(res){	wspace.var("n2")->setConstant(kTRUE);
		wspace.var("pippo")->setConstant(kTRUE);
		wspace.var("mario")->setConstant(kTRUE);
		wspace.var("alpha1")->setConstant(kTRUE);
		wspace.var("alpha2")->setConstant(kTRUE);
		wspace.var("mean")->setConstant(kTRUE);
		wspace.var("n1")->setConstant(kTRUE);
	}
	wspace.var("sigma")->setConstant(kTRUE);
	wspace.var("mean")->setConstant(kTRUE);
	//	wspace.var("n2")->setConstant(kTRUE);

	sig->plotOn(xmcframe,RooFit::Name("sig"),RooFit::Normalization(wspace.var("nsig")->getVal(),RooAbsReal::NumEvent),RooFit::LineColor(2),RooFit::MoveToBack()); // this will show fit overlay on canvas
	xmcframe->Draw();
	c1->SaveAs((PNGPATH+"fit_MC"+std::to_string((int)set)+"_"+std::to_string(cat)+"_"+std::to_string(cut)+".png").c_str());

	double nores;
	if (!res){

		nores = resu[0]*BR_NORES/BR_RES*eff_ratio[set][cat]*eff_nores/eff_res ;
		std::cout << " resonant fitted signal " << resu[0] << std::endl;
		std::cout << "non resonant predicted signal " << nores << std::endl;
		wspace.var("nsig")->setVal(nores);
//		wspace.factory(("nsig["+std::to_string(nores)+","+std::to_string(nores*0.0)+","+std::to_string(nores*10)+"]").c_str());
		//wspace.factory(("nores["+std::to_string(nores)+","+std::to_string(nores)+","+std::to_string(nores)+"]").c_str());
	}

	wspace.var("nsig")->setVal(20);


	std::cout << "sigma " << wspace.var("sigma")->getVal() << std::endl;

	RooDataHist data = RooDataHist("data","data",list,hist);
	std::cout << hist->GetEntries() << std::endl;
	//RooAddPdf mod("model", "s+b",RooArgList(*wspace.obj("model")));
	if (!res){
		wspace.var("nsig")->setVal(nores);
		wspace.var("nsig")->setConstant(kTRUE);
	}
	RooFitResult* result = mod->fitTo(data,RooFit::Save(),RooFit::Extended(kTRUE) /*,RooFit::Range("low","high")*/);
	//result->NormalizedErrors();
	result->Print(); 
	std::cout << "sigma " << wspace.var("sigma")->getVal() << std::endl;
	wspace.var("x")->setRange("window",wspace.var("mean")->getVal()-3*wspace.var("sigma")->getVal(),wspace.var("mean")->getVal()+3*wspace.var("sigma")->getVal());
	RooAbsReal* fracBkgRange = bkg->createIntegral(*wspace.set("obs"),*wspace.set("obs"),"window") ;
	RooAbsReal* fracMisRange = misreco2.createIntegral(*wspace.set("obs"),*wspace.set("obs"),"window") ;
	std::cout << "____________________________________________________________________________________________________debug"  << fracBkgRange<< std::endl;
	RooAbsReal* fracSigRange = sig->createIntegral(*wspace.set("obs"),*wspace.set("obs"),"window") ;
	std::cout << "____________________________________________________________________________________________________debug" << fracSigRange << std::endl;
	double  nbkgWindow = wspace.var("nbkg")->getVal() * fracBkgRange->getVal()+wspace.var("nmisreco")->getVal() * fracMisRange->getVal();
	double  nSigWindow = wspace.var("nsig")->getVal() * fracSigRange->getVal();
	// 	print(nbkg.getVal(), fracBkgRange.getVal());
	std::cout << "Number of signals:" << nSigWindow << ", Number of background: " << nbkgWindow << ", S/sqrt(S+B): " << nSigWindow/sqrt(nSigWindow + nbkgWindow)<< std::endl;
	TCanvas* c2 =new TCanvas("fig_binnedFit", "fit", 800, 600);
	c2->SetGrid();
	c2->cd();
	gPad->SetLeftMargin(0.10);
	gPad->SetRightMargin(0.05);
	RooPlot* xframe = wspace.var("x")->frame();
	gStyle->SetPalette(kPastel);
	if (!res){
		for (int i =0; i<hist->GetXaxis()->GetNbins(); i++){	
			if (hist->GetXaxis()->GetBinLowEdge(i) >5.16 && hist->GetXaxis()->GetBinUpEdge(i) < 5.42 ){
				hist->SetBinContent(i, 0);
				hist->SetBinError(i, 0);
			}

		}

		RooDataHist data_blind = RooDataHist("data_blind","data_blind",list,hist);
		data_blind.plotOn(xframe, RooFit::Name("data_blind"));
		mod->plotOn(xframe,RooFit::Name("combinatorial"),RooFit::Components("bkg"),RooFit::Normalization(wspace.var("nbkg")->getVal(),RooAbsReal::NumEvent),RooFit::DrawOption("FL"),RooFit::LineStyle(kDashed),RooFit::LineColor(kAzure+7));
		mod->plotOn(xframe,RooFit::Name("misreco"),RooFit::Components("misr"),RooFit::Normalization(wspace.var("nmisreco")->getVal(),RooAbsReal::NumEvent),RooFit::DrawOption("FL"),RooFit::AddTo("combinatorial",1,1),RooFit::LineStyle(kDashed),RooFit::LineColor(kOrange-3),RooFit::FillColor(kOrange-3),RooFit::FillStyle(3001));
		mod->plotOn(xframe,RooFit::Name("comb"),RooFit::Components("bkg"),RooFit::Normalization(wspace.var("nbkg")->getVal(),RooAbsReal::NumEvent),RooFit::DrawOption("FL"),RooFit::LineStyle(kDashed),RooFit::LineColor(kAzure+7),RooFit::FillColor(kAzure-3),RooFit::FillStyle(3001));
		signal->plotOn(xframe,RooFit::Name("Sig"),RooFit::Normalization(nores,RooAbsReal::NumEvent),RooFit::DrawOption("FL"),RooFit::FillColor(kRed-3),RooFit::FillStyle(3004),RooFit::LineStyle(6),RooFit::LineColor(kRed-3)) ;
	}else{

		data.plotOn(xframe, RooFit::Name("data"));
		mod->plotOn(xframe,RooFit::Name("model"),RooFit::LineColor(2)); // this will show fit overlay on canvas
		//mod ->plotOn(xframe,RooFit::Name("model"),RooFit::Components("sig"),RooFit::DrawOption("FL"),RooFit::FillColor(9),RooFit::FillStyle(3004),RooFit::LineStyle(6),RooFit::LineColor(9)) ;
		mod->plotOn(xframe,RooFit::Name("combinatorial"),RooFit::Components("bkg"),RooFit::DrawOption("L"),RooFit::FillColor(kMagenta),RooFit::FillStyle(3001),RooFit::LineStyle(kDashed),RooFit::LineColor(kMagenta));
		mod->plotOn(xframe,RooFit::Name("misreco"),RooFit::Components("misr"),RooFit::DrawOption("FL"),RooFit::AddTo("combinatorial",1,1),RooFit::LineStyle(kDashed),RooFit::LineColor(kOrange-3),RooFit::FillColor(kOrange-3),RooFit::FillStyle(3001));
		mod->plotOn(xframe,RooFit::Name("comb"),RooFit::Components("bkg"),RooFit::DrawOption("FL"),RooFit::FillColor(kAzure+7),RooFit::FillStyle(3001),RooFit::LineStyle(kDashed),RooFit::LineColor(kAzure+7));
		mod ->plotOn(xframe,RooFit::Name("Sig"),RooFit::Components("sig"),RooFit::DrawOption("FL"),RooFit::FillColor(kRed-3),RooFit::FillStyle(3004),RooFit::LineColor(kRed-3)) ;
		std::cout << "________________________________________________________" << wspace.var("nsig")->getVal() << std::endl;
	}
	//	mod->plotOn(xframe,RooFit::VisualizeError(result), RooFit::FillColor(kOrange), RooFit::MoveToBack())// # this will show fit overlay on canvas
	//pdf->plotOn(frame,Normalization(0.5,RooAbsReal::Relative)) ;
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
	l = new TLegend(0.67,0.55,0.95,0.90);
	//else  l = new TLegend(0.67,0.15,0.95,0.50);
	//	l->SetTextFont(72);
	l->SetTextSize(0.03);
	l->AddEntry(xframe->findObject("data"),"Data","lpe");
	l->AddEntry(xframe->findObject("comb"),"Combinatorial bkg","l");
	l->AddEntry(xframe->findObject("misreco"),"Misreco bkg ","l");
	l->AddEntry(xframe->findObject("Sig"),"Signal","l");

	char v1[10],v2[10],v3[10];
	sprintf(v1,"%.2f",nSigWindow);
	sprintf(v2,"%.2f", nbkgWindow);
	sprintf(v3,"%.2f", nores);
	if (res) l->AddEntry("" ,("S = "+std::string(v1)).c_str(),"");
	else {
		l->AddEntry("" ,("S_pred = "+std::string(v3)).c_str(),"");
		//	l->AddEntry("" ,("S_fit = "+std::string(v1)).c_str(),"");


	}
	l->AddEntry("",("B = "+std::string(v2)).c_str(),"");
	char v[10];
	if(!res)sprintf(v,"%.2f",nores/sqrt(nores + nbkgWindow));
	if(res)sprintf(v,"%.2f",nSigWindow/sqrt(nSigWindow + nbkgWindow));
	l->AddEntry("" ,("S/#sqrt{S+B} = "+std::string(v)).c_str(),"");
	l->Draw();
	CMS_lumi(c2,5,0,10);
	if (res)c2->SaveAs((PNGPATH+"fit_peak"+std::to_string((int)set)+"_"+std::to_string(cat)+"_"+std::to_string(cut)+".png").c_str());
	else c2->SaveAs((PNGPATH+"fit_nores"+std::to_string((int)set)+"_"+std::to_string(cat)+"_"+std::to_string(cut)+".png").c_str());
	std::cout << " S/sqrt(S+B): " << nSigWindow/sqrt(nSigWindow + nbkgWindow)<< std::endl;
	std::pair<double,double> pair = std::make_pair(nSigWindow,nbkgWindow);
	std::cout << " S " << pair.first<< std::endl;
	std::cout << " S/sqrt(S+B): " << pair.second<< std::endl;
	resu[4] = nores;
	resu[5] = resu[1]*BR_NORES/BR_RES*eff_ratio[set][cat]*eff_nores/eff_res ;
	resu[0] = nSigWindow;
	resu[1] = wspace.var("nsig")->getError() * fracSigRange->getVal();
	resu[2] = nbkgWindow;
	resu[3] = wspace.var("nbkg")->getError() * fracBkgRange->getVal();
	delete mB_res;
	delete mB_nores;
	delete templ;

}





