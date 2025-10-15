#define merged_events_cxx
#include "merged_events.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>

Float_t rotxy[NDEV]={0.0455935,0.0231922};
Float_t shiftx[NDEV]={17.32,16.37};
Float_t shifty[NDEV]={5.290,5.863};

Int_t merged_events::FiducialCut(Int_t ndev)
{
    if(newx[ndev]>XMIN&&newx[ndev]<XMAX&&newy[ndev]>YMIN&&newy[ndev]<YMAX)
            return 1;
    return -1;
}
Int_t merged_events::SignalAmpCut(Int_t ndev)
{
    if(aclgad_amp[0+3*ndev]>SMIN||aclgad_amp[1+3*ndev]>SMIN||aclgad_amp[2+3*ndev]>SMIN)
        return 1;
    return -1;
}
Int_t merged_events::SignalTimeCut(Int_t ndev)
{
    if(aclgad_LP2_50[0+3*ndev]>TMIN||aclgad_LP2_50[1+3*ndev]>TMIN||aclgad_LP2_50[2+3*ndev]>TMIN)
        return 1;
    return -1;
}
Int_t merged_events::MCPPMTTimeCut()
{
    if(aclgad_amp[7]>30&&aclgad_LP2_50[7]>0&&aclgad_LP2_50[7]<5e-7)
        return 1;
    return -1;
}
Int_t merged_events::SignalSingleOrDouble(Int_t ndev)
{
    if(aclgad_amp[1+3*ndev]>SMIN&&(aclgad_amp[0+3*ndev]>SMIN||aclgad_amp[2+3*ndev]>SMIN))
        return 1;
    return -1;
}

void merged_events::Loop(Float_t rot0,Float_t rot1)
{
    if (fChain == 0) return;
    
    rotxy[0]=rot0;
    rotxy[1]=rot1;
    
    for(Int_t ndev=0;ndev<NDEV;ndev++) {
        h2XY[ndev]=new TH2D(Form("h2XY%d",ndev),"",200,XMIN,XMAX,200,YMIN,YMAX);
        h2XYEff[ndev]=new TH2D(Form("h2XYEff%d",ndev),"",200,XMIN,XMAX,200,YMIN,YMAX);
        h2XYEffSingle[ndev]=new TH2D(Form("h2XYEffSingle%d",ndev),"",200,XMIN,XMAX,200,YMIN,YMAX);
        h2XYEffDouble[ndev]=new TH2D(Form("h2XYEffDouble%d",ndev),"",200,XMIN,XMAX,200,YMIN,YMAX);
        for(Int_t nchn=0;nchn<NCHN;nchn++) {
            h2FracYDouble[nchn][ndev]=new TH2D(Form("h2FracYDouble%d%d",nchn,ndev),"",200,0,1,200,YMIN,YMAX);
        }
        h3XYDeltaTime[ndev]=new TH3D(Form("h3XYDeltaTime%d",ndev),"",200,XMIN,XMAX,200,YMIN,YMAX,200,-1*TMAX,TMAX);
    }
    h3XYDeltaT=new TH3D("h3XYDeltaTime2","",200,XMIN,XMAX,200,YMIN,YMAX,200,-1*TMAX,TMAX);

    for (Long64_t jentry=0; jentry<fChain->GetEntries();jentry++) {
        fChain->GetEntry(jentry);
        for(Int_t ndev=0;ndev<NDEV;ndev++) {
            newx[ndev]=babymoss_project_proj_x*sqrt(1-rotxy[ndev]*rotxy[ndev])-babymoss_project_proj_y*rotxy[ndev]-shiftx[ndev];
            newy[ndev]=-babymoss_project_proj_x*rotxy[ndev]+babymoss_project_proj_y*sqrt(1-rotxy[ndev]*rotxy[ndev])-shifty[ndev];
            newt[ndev]=-1;
            if(FiducialCut(ndev)<0) continue;
            h2XY[ndev]->Fill(newx[ndev],newy[ndev]);
            if(SignalAmpCut(ndev)<0) continue;
            if(SignalTimeCut(ndev)<0) continue;
            h2XYEff[ndev]->Fill(newx[ndev],newy[ndev]);
            if(SignalSingleOrDouble(ndev)<0) {
                h2XYEffSingle[ndev]->Fill(newx[ndev],newy[ndev]);
                if(aclgad_amp[1+3*ndev]>SMIN) newt[ndev]=aclgad_LP2_50[1+3*ndev];
                else if(aclgad_amp[0+3*ndev]>SMIN) newt[ndev]=aclgad_LP2_50[0+3*ndev];
                else if(aclgad_amp[2+3*ndev]>SMIN) newt[ndev]=aclgad_LP2_50[2+3*ndev];
            } else {
                h2XYEffDouble[ndev]->Fill(newx[ndev],newy[ndev]);
                Float_t f=0, t=0;
                if(aclgad_amp[0+3*ndev]>aclgad_amp[2+3*ndev]) {
                    f=aclgad_amp[1+3*ndev]/(aclgad_amp[0+3*ndev]+aclgad_amp[1+3*ndev]);
                    newt[ndev]=(aclgad_amp[0+3*ndev]*aclgad_amp[0+3*ndev]*aclgad_LP2_50[0+3*ndev]+aclgad_amp[1+3*ndev]*aclgad_amp[1+3*ndev]*aclgad_LP2_50[1+3*ndev])/(aclgad_amp[0+3*ndev]*aclgad_amp[0+3*ndev]+aclgad_amp[1+3*ndev]*aclgad_amp[1+3*ndev]);
                } else {
                    f=aclgad_amp[1+3*ndev]/(aclgad_amp[2+3*ndev]+aclgad_amp[1+3*ndev]);
                    newt[ndev]=(aclgad_amp[2+3*ndev]*aclgad_amp[2+3*ndev]*aclgad_LP2_50[2+3*ndev]+aclgad_amp[1+3*ndev]*aclgad_amp[1+3*ndev]*aclgad_LP2_50[1+3*ndev])/(aclgad_amp[2+3*ndev]*aclgad_amp[2+3*ndev]+aclgad_amp[1+3*ndev]*aclgad_amp[1+3*ndev]);
                }
                h2FracYDouble[0][ndev]->Fill(f,newy[ndev]);
                if(aclgad_amp[0+3*ndev]>aclgad_amp[2+3*ndev]) {
                    h2FracYDouble[1][ndev]->Fill(f,newy[ndev]);
                } else {
                    h2FracYDouble[2][ndev]->Fill(f,newy[ndev]);
                }
            }
        }
        if(FiducialCut(0)>0&&SignalAmpCut(0)>0&&SignalTimeCut(0)>0&&FiducialCut(1)>0&&SignalAmpCut(1)>0&&SignalTimeCut(1)>0&&MCPPMTTimeCut()>0&&newt[0]>0&&newt[1]>0) {
            if(fabs(0.5*(newx[0]+newx[1]))<XMAX&&fabs(0.5*(newy[0]+newy[1]))<YMAX&&fabs(newt[0]-newt[1])<TMAX&&fabs(newt[0]-aclgad_LP2_50[7]+15.6e-9)<TMAX&&fabs(newt[1]-aclgad_LP2_50[7]+15.6e-9)<TMAX) {
                h3XYDeltaT->Fill(0.5*(newx[0]+newx[1]),0.5*(newy[0]+newy[1]),newt[0]-newt[1]);
                for(Int_t ndev=0;ndev<NDEV;ndev++) h3XYDeltaTime[ndev]->Fill(0.5*(newx[0]+newx[1]),0.5*(newy[0]+newy[1]),newt[ndev]-aclgad_LP2_50[7]+15.6e-9);
            }
        }
    }
    
    TFile* histroot=new TFile("hist.root","recreate");
    histroot->cd();
    for(Int_t ndev=0;ndev<NDEV;ndev++) {
        h2XY[ndev]->Write();
        h2XYEff[ndev]->Write();
        h2XYEffSingle[ndev]->Write();
        h2XYEffDouble[ndev]->Write();
        for(Int_t nchn=0;nchn<NCHN;nchn++) {
            h2FracYDouble[nchn][ndev]->Write();
        }
        h3XYDeltaTime[ndev]->Write();
    }
    h3XYDeltaT->Write();
    histroot->Write();
    histroot->Close();
}
