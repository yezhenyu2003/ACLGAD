#define NDEV 2
#define NCHN 3
#define YMIN -1.1
#define YMAX 1.1

void plot(TString inputfilename="hist.root") {
    TFile *inputfile = TFile::Open(inputfilename);
    TH2D *h2XY[NDEV], *h2XYEff[NDEV], *h2XYEffSingle[NDEV], *h2XYEffDouble[NDEV], *h2FracYDouble[NCHN][NDEV];
    TH1D *h1XY_py[NDEV], *h1XYEff_py[NDEV], *h1XYEffSingle_py[NDEV], *h1XYEffDouble_py[NDEV];
    TGraphErrors* gResolutionS[NDEV];
    TGraphErrors* gResolutionD[NDEV];
    TGraphErrors* gResolutionN[NDEV];
    TGraphErrors* gResolutionP[NDEV];
    TString sDevice[NDEV]={"Sensor A","Sensor B"};
    Int_t color[NDEV]={2,4};
    
    for(Int_t ndev=0;ndev<NDEV;ndev++) {
        h2XY[ndev]=(TH2D*)inputfile->Get(Form("h2XY%d",ndev));
        h2XYEff[ndev]=(TH2D*)inputfile->Get(Form("h2XYEff%d",ndev));
        h2XYEffSingle[ndev]=(TH2D*)inputfile->Get(Form("h2XYEffSingle%d",ndev));
        h2XYEffDouble[ndev]=(TH2D*)inputfile->Get(Form("h2XYEffDouble%d",ndev));
        for(Int_t nchn=0;nchn<NCHN;nchn++) { h2FracYDouble[nchn][ndev]=(TH2D*)inputfile->Get(Form("h2FracYDouble%d%d",nchn,ndev));
            //h2FracYDouble[nchn][ndev]->RebinX(2);
        }
        h1XY_py[ndev]=h2XY[ndev]->ProjectionY(Form("h1XY%d_py",ndev),10,90);
        h1XYEff_py[ndev]=h2XYEff[ndev]->ProjectionY(Form("h1XYEff%d_py",ndev),10,90);
        h1XYEffSingle_py[ndev]=h2XYEffSingle[ndev]->ProjectionY(Form("h1XYEffSingle%d_py",ndev),10,90);
        h1XYEffDouble_py[ndev]=h2XYEffDouble[ndev]->ProjectionY(Form("h1XYEffDouble%d_py",ndev),10,90);
        h2XYEff[ndev]->Divide(h2XY[ndev]);
        h2XYEffSingle[ndev]->Divide(h2XY[ndev]);
        h2XYEffDouble[ndev]->Divide(h2XY[ndev]);
        h1XYEff_py[ndev]->Sumw2();
        h1XYEffSingle_py[ndev]->Sumw2();
        h1XYEffDouble_py[ndev]->Sumw2();
        h1XYEff_py[ndev]->Divide(h1XYEff_py[ndev],h1XY_py[ndev],1,1,"B");
        h1XYEffDouble_py[ndev]->Add(h1XYEffSingle_py[ndev]);
        h1XYEffSingle_py[ndev]->Divide(h1XYEffSingle_py[ndev],h1XY_py[ndev],1,1,"B");
        h1XYEffDouble_py[ndev]->Divide(h1XYEffDouble_py[ndev],h1XY_py[ndev],1,1,"B");
        h1XYEffSingle_py[ndev]->SetLineColor(4);
    }
    
    gStyle->SetOptFit(1);
    gStyle->SetOptStat(0);
    gStyle->SetPadTopMargin(0.02);
    gStyle->SetPadRightMargin(0.02);
    gStyle->SetTitleXSize(0.04);
    gStyle->SetTitleYSize(0.04);

    TF1* fitS[NDEV];
    TCanvas *c1=new TCanvas("c1","",1200,600);
    c1->Divide(4,2);
    for(Int_t ndev=0;ndev<NDEV;ndev++) {
        c1->cd(ndev*4+1);
        h2XYEff[ndev]->Draw();
        c1->cd(ndev*4+2);
        h2XYEffSingle[ndev]->Draw();
        c1->cd(ndev*4+3);
        h2XYEffDouble[ndev]->Draw();
        c1->cd(ndev*4+4);
        h1XYEffDouble_py[ndev]->Draw();
        h1XYEffSingle_py[ndev]->Draw("SAME");
        fitS[ndev]=new TF1(Form("fitS%d",ndev),"gaus",-0.2,0.2);
        gResolutionS[ndev]=new TGraphErrors();
        fitS[ndev]->SetParameters(0.5,0,0.1);
        h1XYEffSingle_py[ndev]->Fit(fitS[ndev],"RN");
        gResolutionS[ndev]->AddPoint(0,fitS[ndev]->GetParameter(2));
        gResolutionS[ndev]->SetPointError(0,fitS[ndev]->GetParameter(2),fitS[ndev]->GetParError(2));
    }
    c1->SaveAs(inputfilename+"_c1.pdf");

    TH1D* py1=new TH1D("py1","",200,-1.1,1.1);
    TH1D* py2=new TH1D("py2","",200,-1.1,1.1);
    TF1* fitn=new TF1("fit","[0]*exp(-(x-[1])*(x-[1])/2/[2]/[2])",YMIN,YMAX);
    fitn->SetParLimits(0,0,1e5);
    fitn->SetParLimits(1,YMIN,0);
    fitn->SetParLimits(2,0,0.1);
    TF1* fitp=new TF1("fit","[0]*exp(-(x-[1])*(x-[1])/2/[2]/[2])",YMIN,YMAX);
    fitp->SetParLimits(0,0,1e5);
    fitp->SetParLimits(1,0,YMAX);
    fitp->SetParLimits(2,0,0.1);
    
    TCanvas *c2=new TCanvas("c2","",1200,600);
    c2->Divide(2,1);
    for(Int_t ndev=0;ndev<2;ndev++) {
        gResolutionD[ndev]=new TGraphErrors();
        gResolutionD[ndev]->SetName(Form("gResolutionD%d",ndev));
        gResolutionN[ndev]=new TGraphErrors();
        gResolutionN[ndev]->SetName(Form("gResolutionN%d",ndev));
        gResolutionP[ndev]=new TGraphErrors();
        gResolutionP[ndev]->SetName(Form("gResolutionP%d",ndev));
        for(Int_t nbin=1;nbin<=h2FracYDouble[1][ndev]->GetNbinsX();nbin++) {
            for(Int_t nchn=1;nchn<NCHN;nchn++) h2FracYDouble[nchn][ndev]->ProjectionY(Form("py%d",nchn),nbin,nbin);
            c2->cd(1);
            fitn->SetParameters(100,-0.5,0.03);
            py1->Fit(fitn,"RL");
            py1->Fit(fitn,"R");
            if(fitn->GetParameter(0)>1&&fitn->GetParameter(1)<0&&fitn->GetParameter(1)>-0.45&&fitn->GetParError(1)>1e-5&&fitn->GetParError(2)>1e-5&&fitn->GetParError(1)<0.01&&fitn->GetParError(2)<0.01&&fitn->GetChisquare()/fitn->GetNDF()<3) {
                gResolutionN[ndev]->AddPoint(fitn->GetParameter(1),fabs(fitn->GetParameter(2)));
                gResolutionN[ndev]->SetPointError(gResolutionN[ndev]->GetN()-1,fitn->GetParError(1),fitn->GetParError(2));
            }
            c2->cd(2);
            fitp->SetParameters(100,0.5,0.03);
            py2->Fit(fitp,"RL");
            py2->Fit(fitp,"R");
            if(fitp->GetParameter(0)>1&&fitp->GetParameter(1)>0&&fitp->GetParameter(1)<0.45&&fitp->GetParError(1)>1e-5&&fitp->GetParError(2)>1e-5&&fitp->GetParError(1)<0.01&&fitp->GetParError(2)<0.01&&fitp->GetChisquare()/fitp->GetNDF()<3) {
                gResolutionP[ndev]->AddPoint(fitp->GetParameter(1),fabs(fitp->GetParameter(2)));
                gResolutionP[ndev]->SetPointError(gResolutionP[ndev]->GetN()-1,fitp->GetParError(1),fitp->GetParError(2));
            }
            if(nbin==1) c2->SaveAs(Form("c2_%d.pdf(",ndev));
            else if(nbin==h2FracYDouble[1][ndev]->GetNbinsX()) c2->SaveAs(Form("c2_%d.pdf)",ndev));
            else c2->SaveAs(Form("c2_%d.pdf",ndev));
        }
        for(Int_t n=0;n<gResolutionP[ndev]->GetN();n++) {
            gResolutionD[ndev]->AddPoint(gResolutionN[ndev]->GetPointX(n),gResolutionN[ndev]->GetPointY(n));
            gResolutionD[ndev]->SetPointError(gResolutionD[ndev]->GetN()-1,gResolutionN[ndev]->GetErrorX(n),gResolutionN[ndev]->GetErrorY(n));
        }
        for(Int_t n=gResolutionP[ndev]->GetN()-1;n>-1;n--) {
            gResolutionD[ndev]->AddPoint(gResolutionP[ndev]->GetPointX(n),gResolutionP[ndev]->GetPointY(n));
            gResolutionD[ndev]->SetPointError(gResolutionD[ndev]->GetN()-1,gResolutionP[ndev]->GetErrorX(n),gResolutionP[ndev]->GetErrorY(n));
        }
    }
    
    TCanvas *c3=new TCanvas("c3","",1200,600);
    c3->Divide(4,2);
    for(Int_t ndev=0;ndev<2;ndev++) {
        c3->cd(ndev*4+1);
        h2FracYDouble[1][ndev]->Draw();
        c3->cd(ndev*4+2);
        gResolutionN[ndev]->SetMinimum(0);
        gResolutionN[ndev]->SetMaximum(0.1);
        gResolutionN[ndev]->Draw();
        c3->cd(ndev*4+3);
        h2FracYDouble[2][ndev]->Draw();
        c3->cd(ndev*4+4);
        gResolutionP[ndev]->SetMinimum(0);
        gResolutionP[ndev]->SetMaximum(0.1);
        gResolutionP[ndev]->Draw();
    }
    c3->SaveAs(inputfilename+"_c3.pdf");
    
    TCanvas *c4=new TCanvas("c4","",1200,450);
    c4->Divide(2,1);
    TH1D* hEffFrame;
    TH1D* hSpaFrame;
    TLegend* lSensor=new TLegend(0.17,0.8,0.37,0.97);
    lSensor->SetBorderSize(0);
    lSensor->SetFillColor(0);
    lSensor->SetTextSize(0.04);
    for(Int_t ndev=0;ndev<2;ndev++) lSensor->AddEntry(h1XYEffDouble_py[ndev],sDevice[ndev],"l");
    TLegend* lEfficiencyS=new TLegend(0.4,0.8,0.67,0.97);
    lEfficiencyS->SetBorderSize(0);
    lEfficiencyS->SetFillColor(0);
    lEfficiencyS->SetTextSize(0.04);
    lEfficiencyS->AddEntry(h1XYEffSingle_py[0],"Single Channel","p");
    lEfficiencyS->AddEntry(h1XYEffSingle_py[1],"Single Channel","p");
    TLegend* lEfficiencyD=new TLegend(0.7,0.8,0.97,0.97);
    lEfficiencyD->SetBorderSize(0);
    lEfficiencyD->SetFillColor(0);
    lEfficiencyD->SetTextSize(0.04);
    lEfficiencyD->AddEntry(h1XYEffDouble_py[0],"Single+Double","p");
    lEfficiencyD->AddEntry(h1XYEffDouble_py[1],"Single+Double","p");
    TLegend* lResolutionS=new TLegend(0.4,0.8,0.67,0.97);
    lResolutionS->SetBorderSize(0);
    lResolutionS->SetFillColor(0);
    lResolutionS->SetTextSize(0.04);
    lResolutionS->AddEntry(gResolutionS[0],"Single Channel","pl");
    lResolutionS->AddEntry(gResolutionS[1],"Single Channel","pl");
    TLegend* lResolutionD=new TLegend(0.7,0.8,0.97,0.97);
    lResolutionD->SetBorderSize(0);
    lResolutionD->SetFillColor(0);
    lResolutionD->SetTextSize(0.04);
    lResolutionD->AddEntry(gResolutionD[0],"Double Channel","p");
    lResolutionD->AddEntry(gResolutionD[1],"Double Channel","p");
    c4->cd(1);
    hEffFrame=new TH1D("hEffFrame","",1,-0.5,0.5);
    hEffFrame->GetXaxis()->SetTitle("Y (mm)");
    hEffFrame->GetYaxis()->SetTitle("Efficiency");
    hEffFrame->SetMinimum(0);
    hEffFrame->SetMaximum(1.4);
    hEffFrame->Draw();
    for(Int_t ndev=0;ndev<2;ndev++) {
        h1XYEffDouble_py[ndev]->SetMarkerStyle(20);
        h1XYEffDouble_py[ndev]->SetMarkerSize(0.5);
        h1XYEffDouble_py[ndev]->SetMarkerColor(color[ndev]);
        h1XYEffDouble_py[ndev]->SetLineColor(color[ndev]);
        h1XYEffDouble_py[ndev]->Draw("PESAME");
        h1XYEffSingle_py[ndev]->SetMarkerStyle(24);
        h1XYEffSingle_py[ndev]->SetMarkerSize(0.5);
        h1XYEffSingle_py[ndev]->SetMarkerColor(color[ndev]);
        h1XYEffSingle_py[ndev]->SetLineColor(color[ndev]);
        h1XYEffSingle_py[ndev]->Draw("PESAME");
    }
    lSensor->Draw();
    lEfficiencyS->Draw();
    lEfficiencyD->Draw();
    c4->cd(2);
    hSpaFrame=new TH1D("hSpaFrame","",1,-0.5,0.5);
    hSpaFrame->GetXaxis()->SetTitle("Y (mm)");
    hSpaFrame->GetYaxis()->SetTitle("Spatial Resolution (mm)");
    hSpaFrame->SetMinimum(0);
    hSpaFrame->SetMaximum(0.14);
    hSpaFrame->Draw();
    for(Int_t ndev=0;ndev<2;ndev++) {
        gResolutionD[ndev]->SetMarkerStyle(20);
        gResolutionD[ndev]->SetMarkerSize(0.5);
        gResolutionD[ndev]->SetMarkerColor(color[ndev]);
        gResolutionD[ndev]->SetLineColor(color[ndev]);
        gResolutionD[ndev]->Draw("PESAME");
        gResolutionS[ndev]->SetMarkerStyle(47);
        gResolutionS[ndev]->SetMarkerSize(1);
        gResolutionS[ndev]->SetMarkerColor(color[ndev]);
        gResolutionS[ndev]->SetLineColor(color[ndev]);
        gResolutionS[ndev]->Draw("PESAME");
    }
    lSensor->Draw();
    lResolutionS->Draw();
    lResolutionD->Draw();
    c4->SaveAs(inputfilename+"_c4.pdf");
}
