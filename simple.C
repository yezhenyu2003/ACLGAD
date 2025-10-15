void simple(TString inputfilename="test.root") {
    TString CUTS="babymoss_project.proj_x>15&&babymoss_project.proj_x<20&&babymoss_project.proj_y>5.3&&babymoss_project.proj_y<6.5";
    TString CUTS2="&&aclgad.LP2_50[0]>0&&aclgad.LP2_50[1]>0&&aclgad.LP2_50[3]>0&&aclgad.LP2_50[4]>0&&aclgad.LP2_50[0]<5e-8&&aclgad.LP2_50[1]<5e-8&&aclgad.LP2_50[3]<5e-8&&aclgad.LP2_50[4]<5e-8&&aclgad.LP2_50[7]>0&&aclgad.LP2_50[7]<1e-7";

    Float_t rotxy1=0.0455935;
    Float_t rotyz1=1;
    Float_t rotxy2=0.0231922;
    Float_t rotyz2=1;
    TString newx1=Form("(babymoss_project.proj_x*sqrt(1-%f*%f)-babymoss_project.proj_y*%f)",rotxy1,rotxy1,rotxy1);
    TString newy1=Form("(-babymoss_project.proj_x*%f+babymoss_project.proj_y*sqrt(1-%f*%f))*%f",rotxy1,rotxy1,rotxy1,rotyz1);
    TString newx2=Form("(babymoss_project.proj_x*sqrt(1-%f*%f)-babymoss_project.proj_y*%f)",rotxy2,rotxy2,rotxy2);
    TString newy2=Form("(-babymoss_project.proj_x*%f+babymoss_project.proj_y*sqrt(1-%f*%f))*%f",rotxy2,rotxy2,rotxy2,rotyz1);
    
    Int_t AMP_MIN=10;
    Int_t AMP_MAX=150;
    
    TFile *file = TFile::Open(inputfilename);
    TTree* merged_events=(TTree*)file->Get("merged_events");
    TH2D* hFrame=new TH2D("hFrame","",100,30,100,100,4,6.5);
    hFrame->SetMinimum(1);
    hFrame->SetMaximum(100);

    TCanvas *c0=new TCanvas("c0","",1200,600);
    c0->cd();
    merged_events->Draw("aclgad.amp[0]+aclgad.amp[1]",Form("%s&&aclgad.amp[0]>%d&&aclgad.amp[0]<%d&&aclgad.amp[1]>%d&&aclgad.amp[1]<%d",CUTS.Data(),AMP_MIN,AMP_MAX,AMP_MIN,AMP_MAX));
    merged_events->Draw("aclgad.amp[3]+aclgad.amp[4]",Form("%s&&aclgad.amp[3]>%d&&aclgad.amp[3]<%d&&aclgad.amp[4]>%d&&aclgad.amp[4]<%d",CUTS.Data(),AMP_MIN,AMP_MAX,AMP_MIN,AMP_MAX),"PESAME");

    TCanvas *c1=new TCanvas("c1","",1200,600);
    c1->Divide(4,2);
    c1->cd(1);
    merged_events->Draw(newy1,Form("%s&&aclgad.amp[0]>%d&&aclgad.amp[0]<%d",CUTS.Data(),AMP_MIN,AMP_MAX));
    merged_events->Draw(newy1,Form("%s&&aclgad.amp[1]>%d&&aclgad.amp[1]<%d",CUTS.Data(),AMP_MIN,AMP_MAX),"SAME");
    c1->cd(5);
    merged_events->Draw(newy2,Form("%s&&aclgad.amp[3]>%d&&aclgad.amp[3]<%d",CUTS.Data(),AMP_MIN,AMP_MAX));
    merged_events->Draw(newy2,Form("%s&&aclgad.amp[4]>%d&&aclgad.amp[4]<%d",CUTS.Data(),AMP_MIN,AMP_MAX),"SAME");
    c1->cd(2);
    merged_events->Draw(newy1,Form("%s&&aclgad.amp[0]>%d&&aclgad.amp[0]<%d&&aclgad.amp[1]>%d&&aclgad.amp[1]<%d",CUTS.Data(),AMP_MIN,AMP_MAX,AMP_MIN,AMP_MAX));
    c1->cd(6);
    merged_events->Draw(newy2,Form("%s&&aclgad.amp[3]>%d&&aclgad.amp[3]<%d&&aclgad.amp[4]>%d&&aclgad.amp[4]<%d",CUTS.Data(),AMP_MIN,AMP_MAX,AMP_MIN,AMP_MAX));
    c1->cd(3);
    merged_events->Draw(Form("%s:aclgad.amp[1]/(aclgad.amp[0]+aclgad.amp[1])>>h1",newy1.Data()),Form("%s&&aclgad.amp[0]>%d&&aclgad.amp[0]<%d&&aclgad.amp[1]>%d&&aclgad.amp[1]<%d",CUTS.Data(),AMP_MIN,AMP_MAX,AMP_MIN,AMP_MAX),"COLZ");
    c1->cd(7);
    merged_events->Draw(Form("%s:aclgad.amp[4]/(aclgad.amp[3]+aclgad.amp[4])>>h2",newy2.Data()),Form("%s&&aclgad.amp[3]>%d&&aclgad.amp[3]<%d&&aclgad.amp[4]>%d&&aclgad.amp[4]<%d",CUTS.Data(),AMP_MIN,AMP_MAX,AMP_MIN,AMP_MAX),"COLZ");
    c1->cd(4);
    merged_events->Draw(Form("%s>>h3",newy1.Data()),Form("%s&&aclgad.amp[0]>%d&&aclgad.amp[0]<%d&&aclgad.amp[1]>%d&&aclgad.amp[1]<%d&&abs(aclgad.amp[1]/(aclgad.amp[0]+aclgad.amp[1])-0.8)<0.005",CUTS.Data(),AMP_MIN,AMP_MAX,AMP_MIN,AMP_MAX));
    c1->cd(8);
    merged_events->Draw(Form("%s>>h4",newy2.Data()),Form("%s&&aclgad.amp[3]>%d&&aclgad.amp[3]<%d&&aclgad.amp[4]>%d&&aclgad.amp[4]<%d&&abs(aclgad.amp[4]/(aclgad.amp[3]+aclgad.amp[4])-0.8)<0.005",CUTS.Data(),AMP_MIN,AMP_MAX,AMP_MIN,AMP_MAX));
    
    TCanvas *c2=new TCanvas("c2","",1200,600);
    c2->cd();
    merged_events->Draw("aclgad.amp[0]+aclgad.amp[1]",Form("%s&&aclgad.amp[0]>%d&&aclgad.amp[0]<%d&&aclgad.amp[1]>%d&&aclgad.amp[1]<%d",CUTS.Data(),AMP_MIN,AMP_MAX,AMP_MIN,AMP_MAX));
    merged_events->Draw("aclgad.amp[3]+aclgad.amp[4]",Form("%s&&aclgad.amp[3]>%d&&aclgad.amp[3]<%d&&aclgad.amp[4]>%d&&aclgad.amp[4]<%d",CUTS.Data(),AMP_MIN,AMP_MAX,AMP_MIN,AMP_MAX),"PESAME");

    TCanvas *c3=new TCanvas("c3","",1200,600);
    c3->Divide(4,2);
    c3->cd(1);
    merged_events->Draw("aclgad.LP2_50[0]",Form("%s&&aclgad.amp[0]>%d&&aclgad.amp[0]<%d&&aclgad.amp[1]>%d&&aclgad.amp[1]<%d",(CUTS+CUTS2).Data(),AMP_MIN,AMP_MAX,AMP_MIN,AMP_MAX));
    merged_events->Draw("aclgad.LP2_50[3]",Form("%s&&aclgad.amp[3]>%d&&aclgad.amp[3]<%d&&aclgad.amp[4]>%d&&aclgad.amp[4]<%d",(CUTS+CUTS2).Data(),AMP_MIN,AMP_MAX,AMP_MIN,AMP_MAX),"PESAME");
    c3->cd(2);
    merged_events->Draw("aclgad.LP2_50[1]",Form("%s&&aclgad.amp[0]>%d&&aclgad.amp[0]<%d&&aclgad.amp[1]>%d&&aclgad.amp[1]<%d",(CUTS+CUTS2).Data(),AMP_MIN,AMP_MAX,AMP_MIN,AMP_MAX));
    merged_events->Draw("aclgad.LP2_50[4]",Form("%s&&aclgad.amp[3]>%d&&aclgad.amp[3]<%d&&aclgad.amp[4]>%d&&aclgad.amp[4]<%d",(CUTS+CUTS2).Data(),AMP_MIN,AMP_MAX,AMP_MIN,AMP_MAX),"PESAME");
    c3->cd(3);
    merged_events->Draw("aclgad.LP2_50[7]",Form("%s&&aclgad.amp[0]>%d&&aclgad.amp[0]<%d&&aclgad.amp[1]>%d&&aclgad.amp[1]<%d",(CUTS+CUTS2).Data(),AMP_MIN,AMP_MAX,AMP_MIN,AMP_MAX));
    c3->cd(4);
    merged_events->Draw("(aclgad.amp[0]*aclgad.amp[0]*aclgad.LP2_50[0]+aclgad.amp[1]*aclgad.amp[1]*aclgad.LP2_50[1])/(aclgad.amp[0]*aclgad.amp[0]+aclgad.amp[1]*aclgad.amp[1])-aclgad.LP2_50[7]",Form("%s&&aclgad.amp[0]>%d&&aclgad.amp[0]<%d&&aclgad.amp[1]>%d&&aclgad.amp[1]<%d",(CUTS+CUTS2).Data(),AMP_MIN,AMP_MAX,AMP_MIN,AMP_MAX));
    merged_events->Draw("(aclgad.amp[3]*aclgad.amp[3]*aclgad.LP2_50[3]+aclgad.amp[4]*aclgad.amp[4]*aclgad.LP2_50[4])/(aclgad.amp[3]*aclgad.amp[3]+aclgad.amp[4]*aclgad.amp[4])-aclgad.LP2_50[7]",Form("%s&&aclgad.amp[3]>%d&&aclgad.amp[3]<%d&&aclgad.amp[4]>%d&&aclgad.amp[4]<%d",(CUTS+CUTS2).Data(),AMP_MIN,AMP_MAX,AMP_MIN,AMP_MAX),"PESAME");
    c3->cd(5);
    merged_events->Draw(Form("%s:%s>>hxy1",newx1.Data(),newy1.Data()),Form("%s&&aclgad.amp[0]>%d&&aclgad.amp[0]<%d&&aclgad.amp[1]>%d&&aclgad.amp[1]<%d",(CUTS+CUTS2).Data(),AMP_MIN,AMP_MAX,AMP_MIN,AMP_MAX),"COLZ");
    c3->cd(6);
    merged_events->Draw(Form("%s:%s>>hxy2",newx2.Data(),newy2.Data()),Form("%s&&aclgad.amp[3]>%d&&aclgad.amp[3]<%d&&aclgad.amp[4]>%d&&aclgad.amp[4]<%d",(CUTS+CUTS2).Data(),AMP_MIN,AMP_MAX,AMP_MIN,AMP_MAX),"COLZ");
    c3->cd(7);
    merged_events->Draw("(aclgad.amp[3]*aclgad.amp[3]*aclgad.LP2_50[3]+aclgad.amp[4]*aclgad.amp[4]*aclgad.LP2_50[4])/(aclgad.amp[3]*aclgad.amp[3]+aclgad.amp[4]*aclgad.amp[4])-aclgad.LP2_50[7]:babymoss_project.proj_x",Form("%s&&aclgad.amp[3]>%d&&aclgad.amp[3]<%d&&aclgad.amp[4]>%d&&aclgad.amp[4]<%d",(CUTS+CUTS2).Data(),AMP_MIN,AMP_MAX,AMP_MIN,AMP_MAX),"COLZ");
    c3->cd(8);
    merged_events->Draw("(aclgad.amp[0]*aclgad.amp[0]*aclgad.LP2_50[0]+aclgad.amp[1]*aclgad.amp[1]*aclgad.LP2_50[1])/(aclgad.amp[0]*aclgad.amp[0]+aclgad.amp[1]*aclgad.amp[1])-aclgad.LP2_50[7]",Form("%s&&babymoss_project.proj_x>17.45&&babymoss_project.proj_x<17.65&&babymoss_project.proj_y>5.89&&babymoss_project.proj_y<5.91&&aclgad.amp[0]>%d&&aclgad.amp[0]<%d&&aclgad.amp[1]>%d&&aclgad.amp[1]<%d",(CUTS+CUTS2).Data(),AMP_MIN,AMP_MAX,AMP_MIN,AMP_MAX));
    merged_events->Draw("(aclgad.amp[3]*aclgad.amp[3]*aclgad.LP2_50[3]+aclgad.amp[4]*aclgad.amp[4]*aclgad.LP2_50[4])/(aclgad.amp[3]*aclgad.amp[3]+aclgad.amp[4]*aclgad.amp[4])-aclgad.LP2_50[7]",Form("%s&&babymoss_project.proj_x>17.45&&babymoss_project.proj_x<17.65&&babymoss_project.proj_y>5.89&&babymoss_project.proj_y<5.91&&aclgad.amp[3]>%d&&aclgad.amp[3]<%d&&aclgad.amp[4]>%d&&aclgad.amp[4]<%d",(CUTS+CUTS2).Data(),AMP_MIN,AMP_MAX,AMP_MIN,AMP_MAX),"PESAME");

}

