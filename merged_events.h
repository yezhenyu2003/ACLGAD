#define NDEV 2
#define NCHN 3
#define SMAX 150
#define XMIN -5.5
#define XMAX 5.5
#define YMIN -1.1
#define YMAX 1.1
#define TMIN 0
#define TMAX 1e-9
#define SGFMIN 0
#define SGFMAX 1

//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Fri Oct  3 20:47:29 2025 by ROOT version 6.32.12
// from TTree merged_events/Merged BabyMOSS + ACLGAD
// found on file: Run8130XXXX.root_filtered.root
//////////////////////////////////////////////////////////

#ifndef merged_events_h
#define merged_events_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.

class merged_events {
public :
    TTree          *fChain;   //!pointer to the analyzed TTree or TChain
    Int_t           fCurrent; //!current Tree number in a TChain

    Float_t         SMIN=10;
    Float_t         newx[NDEV];
    Float_t         newy[NDEV];
    Float_t         newt[NDEV];
    TH2D            *h2XY[NDEV];
    TH2D            *h2XYEff[NDEV];
    TH2D            *h2XYEffSingle[NDEV];
    TH2D            *h2XYEffDouble[NDEV];
    TH2D            *h2FracYDouble[NCHN][NDEV];
    TH3D            *h3XYDeltaTime[NDEV];
    TH3D            *h3XYDeltaT;

    // Fixed size dimensions of array or collections stored in the TTree if any.
    static constexpr Int_t kMaxbabymoss = 188;

    // Declaration of leaf types
    //Event           *event;
    Int_t           runID;
    ULong_t         eventID;
    Int_t           babymoss_;
    Int_t           babymoss_layer[kMaxbabymoss];   //[babymoss_]
    Int_t           babymoss_half[kMaxbabymoss];   //[babymoss_]
    Int_t           babymoss_region[kMaxbabymoss];   //[babymoss_]
    Int_t           babymoss_col[kMaxbabymoss];   //[babymoss_]
    Int_t           babymoss_row[kMaxbabymoss];   //[babymoss_]
    Float_t         babymoss_x_mm[kMaxbabymoss];   //[babymoss_]
    Float_t         babymoss_y_mm[kMaxbabymoss];   //[babymoss_]
    Float_t         babymoss_z_mm[kMaxbabymoss];   //[babymoss_]
    Float_t         babymoss_aligned_x_mm[kMaxbabymoss];   //[babymoss_]
    Float_t         babymoss_aligned_y_mm[kMaxbabymoss];   //[babymoss_]
    Float_t         babymoss_aligned_z_mm[kMaxbabymoss];   //[babymoss_]
    Float_t         babymoss_residual_x_mm[kMaxbabymoss];   //[babymoss_]
    Float_t         babymoss_residual_y_mm[kMaxbabymoss];   //[babymoss_]
    Bool_t          babymoss_is_hot_pixel[kMaxbabymoss];   //[babymoss_]
    Bool_t          babymoss_project_has_projection;
    Float_t         babymoss_project_proj_x;
    Float_t         babymoss_project_proj_y;
    Float_t         babymoss_project_proj_z;
    Float_t         babymoss_project_xfit_k;
    Float_t         babymoss_project_xfit_c;
    Float_t         babymoss_project_yfit_k;
    Float_t         babymoss_project_yfit_c;
    Int_t           babymoss_project_layers_used;
    Float_t         babymoss_project_chi2_norm;
    Float_t         aclgad_channel[18][1024];
    Float_t         aclgad_time[18][1024];
    Float_t         aclgad_baseline[18];
    Float_t         aclgad_baseline_RMS[18];
    Float_t         aclgad_noise[18];
    Float_t         aclgad_amp[18];
    Float_t         aclgad_t_peak[18];
    Float_t         aclgad_integral[18];
    Float_t         aclgad_intfull[18];
    Float_t         aclgad_risetime[18];
    Float_t         aclgad_decaytime[18];
    Float_t         aclgad_LP2_15[18];
    Float_t         aclgad_LP2_20[18];
    Float_t         aclgad_LP2_30[18];
    Float_t         aclgad_LP2_35[18];
    Float_t         aclgad_LP2_40[18];
    Float_t         aclgad_LP2_45[18];
    Float_t         aclgad_LP2_50[18];
    Float_t         aclgad_LP2_4mV[18];
    Float_t         aclgad_LP2_6mV[18];
    Float_t         aclgad_LP2_8mV[18];
    Float_t         aclgad_LP2_10mV[18];
    Float_t         aclgad_LP2_12mV[18];
    Float_t         aclgad_LP2_14mV[18];
    Float_t         aclgad_LP2_16mV[18];
    Float_t         aclgad_LP2_18mV[18];
    Float_t         aclgad_LP2_20mV[18];
    Float_t         aclgad_LP2_22mV[18];
    Float_t         aclgad_LP2_24mV[18];
    Float_t         aclgad_LP2_26mV[18];
    Float_t         aclgad_LP2_28mV[18];
    Float_t         aclgad_LP2_30mV[18];
    Float_t         aclgad_gaus_mean[18];
    Float_t         aclgad_gaus_sigma[18];
    Float_t         aclgad_gaus_chi2[18];
    Float_t         aclgad_linear_RE_15[18];
    Float_t         aclgad_linear_RE_20[18];
    Float_t         aclgad_linear_RE_30[18];
    Float_t         aclgad_linear_RE_35[18];
    Float_t         aclgad_linear_RE_40[18];
    Float_t         aclgad_linear_RE_45[18];
    Float_t         aclgad_linear_RE_50[18];
    Float_t         aclgad_linear_RE__4mV[18];
    Float_t         aclgad_linear_RE__6mV[18];
    Float_t         aclgad_linear_RE__8mV[18];
    Float_t         aclgad_linear_RE__10mV[18];
    Float_t         aclgad_linear_RE__12mV[18];
    Float_t         aclgad_linear_RE__14mV[18];
    Float_t         aclgad_linear_RE__16mV[18];
    Float_t         aclgad_linear_RE__18mV[18];
    Float_t         aclgad_linear_RE__20mV[18];
    Float_t         aclgad_linear_RE__22mV[18];
    Float_t         aclgad_linear_RE__24mV[18];
    Float_t         aclgad_linear_RE__26mV[18];
    Float_t         aclgad_linear_RE__28mV[18];
    Float_t         aclgad_linear_RE__30mV[18];
    Float_t         aclgad_timeoffsets[18];
    UInt_t          aclgad_trigger_cell[18];

    // List of branches
    TBranch        *b_event_runID;   //!
    TBranch        *b_event_eventID;   //!
    TBranch        *b_event_babymoss_;   //!
    TBranch        *b_babymoss_layer;   //!
    TBranch        *b_babymoss_half;   //!
    TBranch        *b_babymoss_region;   //!
    TBranch        *b_babymoss_col;   //!
    TBranch        *b_babymoss_row;   //!
    TBranch        *b_babymoss_x_mm;   //!
    TBranch        *b_babymoss_y_mm;   //!
    TBranch        *b_babymoss_z_mm;   //!
    TBranch        *b_babymoss_aligned_x_mm;   //!
    TBranch        *b_babymoss_aligned_y_mm;   //!
    TBranch        *b_babymoss_aligned_z_mm;   //!
    TBranch        *b_babymoss_residual_x_mm;   //!
    TBranch        *b_babymoss_residual_y_mm;   //!
    TBranch        *b_babymoss_is_hot_pixel;   //!
    TBranch        *b_event_babymoss_project_has_projection;   //!
    TBranch        *b_event_babymoss_project_proj_x;   //!
    TBranch        *b_event_babymoss_project_proj_y;   //!
    TBranch        *b_event_babymoss_project_proj_z;   //!
    TBranch        *b_event_babymoss_project_xfit_k;   //!
    TBranch        *b_event_babymoss_project_xfit_c;   //!
    TBranch        *b_event_babymoss_project_yfit_k;   //!
    TBranch        *b_event_babymoss_project_yfit_c;   //!
    TBranch        *b_event_babymoss_project_layers_used;   //!
    TBranch        *b_event_babymoss_project_chi2_norm;   //!
    TBranch        *b_event_aclgad_channel;   //!
    TBranch        *b_event_aclgad_time;   //!
    TBranch        *b_event_aclgad_baseline;   //!
    TBranch        *b_event_aclgad_baseline_RMS;   //!
    TBranch        *b_event_aclgad_noise;   //!
    TBranch        *b_event_aclgad_amp;   //!
    TBranch        *b_event_aclgad_t_peak;   //!
    TBranch        *b_event_aclgad_integral;   //!
    TBranch        *b_event_aclgad_intfull;   //!
    TBranch        *b_event_aclgad_risetime;   //!
    TBranch        *b_event_aclgad_decaytime;   //!
    TBranch        *b_event_aclgad_LP2_15;   //!
    TBranch        *b_event_aclgad_LP2_20;   //!
    TBranch        *b_event_aclgad_LP2_30;   //!
    TBranch        *b_event_aclgad_LP2_35;   //!
    TBranch        *b_event_aclgad_LP2_40;   //!
    TBranch        *b_event_aclgad_LP2_45;   //!
    TBranch        *b_event_aclgad_LP2_50;   //!
    TBranch        *b_event_aclgad_LP2_4mV;   //!
    TBranch        *b_event_aclgad_LP2_6mV;   //!
    TBranch        *b_event_aclgad_LP2_8mV;   //!
    TBranch        *b_event_aclgad_LP2_10mV;   //!
    TBranch        *b_event_aclgad_LP2_12mV;   //!
    TBranch        *b_event_aclgad_LP2_14mV;   //!
    TBranch        *b_event_aclgad_LP2_16mV;   //!
    TBranch        *b_event_aclgad_LP2_18mV;   //!
    TBranch        *b_event_aclgad_LP2_20mV;   //!
    TBranch        *b_event_aclgad_LP2_22mV;   //!
    TBranch        *b_event_aclgad_LP2_24mV;   //!
    TBranch        *b_event_aclgad_LP2_26mV;   //!
    TBranch        *b_event_aclgad_LP2_28mV;   //!
    TBranch        *b_event_aclgad_LP2_30mV;   //!
    TBranch        *b_event_aclgad_gaus_mean;   //!
    TBranch        *b_event_aclgad_gaus_sigma;   //!
    TBranch        *b_event_aclgad_gaus_chi2;   //!
    TBranch        *b_event_aclgad_linear_RE_15;   //!
    TBranch        *b_event_aclgad_linear_RE_20;   //!
    TBranch        *b_event_aclgad_linear_RE_30;   //!
    TBranch        *b_event_aclgad_linear_RE_35;   //!
    TBranch        *b_event_aclgad_linear_RE_40;   //!
    TBranch        *b_event_aclgad_linear_RE_45;   //!
    TBranch        *b_event_aclgad_linear_RE_50;   //!
    TBranch        *b_event_aclgad_linear_RE__4mV;   //!
    TBranch        *b_event_aclgad_linear_RE__6mV;   //!
    TBranch        *b_event_aclgad_linear_RE__8mV;   //!
    TBranch        *b_event_aclgad_linear_RE__10mV;   //!
    TBranch        *b_event_aclgad_linear_RE__12mV;   //!
    TBranch        *b_event_aclgad_linear_RE__14mV;   //!
    TBranch        *b_event_aclgad_linear_RE__16mV;   //!
    TBranch        *b_event_aclgad_linear_RE__18mV;   //!
    TBranch        *b_event_aclgad_linear_RE__20mV;   //!
    TBranch        *b_event_aclgad_linear_RE__22mV;   //!
    TBranch        *b_event_aclgad_linear_RE__24mV;   //!
    TBranch        *b_event_aclgad_linear_RE__26mV;   //!
    TBranch        *b_event_aclgad_linear_RE__28mV;   //!
    TBranch        *b_event_aclgad_linear_RE__30mV;   //!
    TBranch        *b_event_aclgad_timeoffsets;   //!
    TBranch        *b_event_aclgad_trigger_cell;   //!

    merged_events(Float_t mini=15,TTree *tree=0);
    virtual ~merged_events();
    virtual Int_t    FiducialCut(Int_t ndev);
    virtual Int_t    SignalAmpCut(Int_t ndev);
    virtual Int_t    SignalSingleOrDouble(Int_t ndev);
    virtual Int_t    SignalTimeCut(Int_t ndev);
    virtual Int_t    MCPPMTTimeCut();
    virtual Int_t    GetEntry(Long64_t entry);
    virtual Long64_t LoadTree(Long64_t entry);
    virtual void     Init(TTree *tree);
    virtual void     Loop(Float_t rot1=0.0455935,Float_t rot2=0.0231922);
    virtual bool     Notify();
    virtual void     Show(Long64_t entry = -1);
};

#endif

#ifdef merged_events_cxx
merged_events::merged_events(Float_t mini,TTree *tree) : fChain(0)
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
    if (tree == 0) {
       TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("Run811XXXX.root_filtered.root");
       if (!f || !f->IsOpen()) {
          f = new TFile("Run811XXXX.root_filtered.root");
       }
       f->GetObject("merged_events",tree);

    }
    Init(tree);
    SMIN=mini;
}

merged_events::~merged_events()
{
    if (!fChain) return;
    delete fChain->GetCurrentFile();
}

Int_t merged_events::GetEntry(Long64_t entry)
{
// Read contents of entry.
    if (!fChain) return 0;
    return fChain->GetEntry(entry);
}
Long64_t merged_events::LoadTree(Long64_t entry)
{
// Set the environment to read one entry
    if (!fChain) return -5;
    Long64_t centry = fChain->LoadTree(entry);
    if (centry < 0) return centry;
    if (fChain->GetTreeNumber() != fCurrent) {
       fCurrent = fChain->GetTreeNumber();
       Notify();
    }
    return centry;
}

void merged_events::Init(TTree *tree)
{
    // The Init() function is called when the selector needs to initialize
    // a new tree or chain. Typically here the branch addresses and branch
    // pointers of the tree will be set.
    // It is normally not necessary to make changes to the generated
    // code, but the routine can be extended by the user if needed.
    // Init() will be called many times when running on PROOF
    // (once per file to be processed).

    // Set branch addresses and branch pointers
    if (!tree) return;
    fChain = tree;
    fCurrent = -1;
    fChain->SetMakeClass(1);

    fChain->SetBranchAddress("runID", &runID, &b_event_runID);
    fChain->SetBranchAddress("eventID", &eventID, &b_event_eventID);
    fChain->SetBranchAddress("babymoss", &babymoss_, &b_event_babymoss_);
    fChain->SetBranchAddress("babymoss.layer", babymoss_layer, &b_babymoss_layer);
    fChain->SetBranchAddress("babymoss.half", babymoss_half, &b_babymoss_half);
    fChain->SetBranchAddress("babymoss.region", babymoss_region, &b_babymoss_region);
    fChain->SetBranchAddress("babymoss.col", babymoss_col, &b_babymoss_col);
    fChain->SetBranchAddress("babymoss.row", babymoss_row, &b_babymoss_row);
    fChain->SetBranchAddress("babymoss.x_mm", babymoss_x_mm, &b_babymoss_x_mm);
    fChain->SetBranchAddress("babymoss.y_mm", babymoss_y_mm, &b_babymoss_y_mm);
    fChain->SetBranchAddress("babymoss.z_mm", babymoss_z_mm, &b_babymoss_z_mm);
    fChain->SetBranchAddress("babymoss.aligned_x_mm", babymoss_aligned_x_mm, &b_babymoss_aligned_x_mm);
    fChain->SetBranchAddress("babymoss.aligned_y_mm", babymoss_aligned_y_mm, &b_babymoss_aligned_y_mm);
    fChain->SetBranchAddress("babymoss.aligned_z_mm", babymoss_aligned_z_mm, &b_babymoss_aligned_z_mm);
    fChain->SetBranchAddress("babymoss.residual_x_mm", babymoss_residual_x_mm, &b_babymoss_residual_x_mm);
    fChain->SetBranchAddress("babymoss.residual_y_mm", babymoss_residual_y_mm, &b_babymoss_residual_y_mm);
    fChain->SetBranchAddress("babymoss.is_hot_pixel", babymoss_is_hot_pixel, &b_babymoss_is_hot_pixel);
    fChain->SetBranchAddress("babymoss_project.has_projection", &babymoss_project_has_projection, &b_event_babymoss_project_has_projection);
    fChain->SetBranchAddress("babymoss_project.proj_x", &babymoss_project_proj_x, &b_event_babymoss_project_proj_x);
    fChain->SetBranchAddress("babymoss_project.proj_y", &babymoss_project_proj_y, &b_event_babymoss_project_proj_y);
    fChain->SetBranchAddress("babymoss_project.proj_z", &babymoss_project_proj_z, &b_event_babymoss_project_proj_z);
    fChain->SetBranchAddress("babymoss_project.xfit_k", &babymoss_project_xfit_k, &b_event_babymoss_project_xfit_k);
    fChain->SetBranchAddress("babymoss_project.xfit_c", &babymoss_project_xfit_c, &b_event_babymoss_project_xfit_c);
    fChain->SetBranchAddress("babymoss_project.yfit_k", &babymoss_project_yfit_k, &b_event_babymoss_project_yfit_k);
    fChain->SetBranchAddress("babymoss_project.yfit_c", &babymoss_project_yfit_c, &b_event_babymoss_project_yfit_c);
    fChain->SetBranchAddress("babymoss_project.layers_used", &babymoss_project_layers_used, &b_event_babymoss_project_layers_used);
    fChain->SetBranchAddress("babymoss_project.chi2_norm", &babymoss_project_chi2_norm, &b_event_babymoss_project_chi2_norm);
    fChain->SetBranchAddress("aclgad.channel[18][1024]", aclgad_channel, &b_event_aclgad_channel);
    fChain->SetBranchAddress("aclgad.time[18][1024]", aclgad_time, &b_event_aclgad_time);
    fChain->SetBranchAddress("aclgad.baseline[18]", aclgad_baseline, &b_event_aclgad_baseline);
    fChain->SetBranchAddress("aclgad.baseline_RMS[18]", aclgad_baseline_RMS, &b_event_aclgad_baseline_RMS);
    fChain->SetBranchAddress("aclgad.noise[18]", aclgad_noise, &b_event_aclgad_noise);
    fChain->SetBranchAddress("aclgad.amp[18]", aclgad_amp, &b_event_aclgad_amp);
    fChain->SetBranchAddress("aclgad.t_peak[18]", aclgad_t_peak, &b_event_aclgad_t_peak);
    fChain->SetBranchAddress("aclgad.integral[18]", aclgad_integral, &b_event_aclgad_integral);
    fChain->SetBranchAddress("aclgad.intfull[18]", aclgad_intfull, &b_event_aclgad_intfull);
    fChain->SetBranchAddress("aclgad.risetime[18]", aclgad_risetime, &b_event_aclgad_risetime);
    fChain->SetBranchAddress("aclgad.decaytime[18]", aclgad_decaytime, &b_event_aclgad_decaytime);
    fChain->SetBranchAddress("aclgad.LP2_15[18]", aclgad_LP2_15, &b_event_aclgad_LP2_15);
    fChain->SetBranchAddress("aclgad.LP2_20[18]", aclgad_LP2_20, &b_event_aclgad_LP2_20);
    fChain->SetBranchAddress("aclgad.LP2_30[18]", aclgad_LP2_30, &b_event_aclgad_LP2_30);
    fChain->SetBranchAddress("aclgad.LP2_35[18]", aclgad_LP2_35, &b_event_aclgad_LP2_35);
    fChain->SetBranchAddress("aclgad.LP2_40[18]", aclgad_LP2_40, &b_event_aclgad_LP2_40);
    fChain->SetBranchAddress("aclgad.LP2_45[18]", aclgad_LP2_45, &b_event_aclgad_LP2_45);
    fChain->SetBranchAddress("aclgad.LP2_50[18]", aclgad_LP2_50, &b_event_aclgad_LP2_50);
    fChain->SetBranchAddress("aclgad.LP2_4mV[18]", aclgad_LP2_4mV, &b_event_aclgad_LP2_4mV);
    fChain->SetBranchAddress("aclgad.LP2_6mV[18]", aclgad_LP2_6mV, &b_event_aclgad_LP2_6mV);
    fChain->SetBranchAddress("aclgad.LP2_8mV[18]", aclgad_LP2_8mV, &b_event_aclgad_LP2_8mV);
    fChain->SetBranchAddress("aclgad.LP2_10mV[18]", aclgad_LP2_10mV, &b_event_aclgad_LP2_10mV);
    fChain->SetBranchAddress("aclgad.LP2_12mV[18]", aclgad_LP2_12mV, &b_event_aclgad_LP2_12mV);
    fChain->SetBranchAddress("aclgad.LP2_14mV[18]", aclgad_LP2_14mV, &b_event_aclgad_LP2_14mV);
    fChain->SetBranchAddress("aclgad.LP2_16mV[18]", aclgad_LP2_16mV, &b_event_aclgad_LP2_16mV);
    fChain->SetBranchAddress("aclgad.LP2_18mV[18]", aclgad_LP2_18mV, &b_event_aclgad_LP2_18mV);
    fChain->SetBranchAddress("aclgad.LP2_20mV[18]", aclgad_LP2_20mV, &b_event_aclgad_LP2_20mV);
    fChain->SetBranchAddress("aclgad.LP2_22mV[18]", aclgad_LP2_22mV, &b_event_aclgad_LP2_22mV);
    fChain->SetBranchAddress("aclgad.LP2_24mV[18]", aclgad_LP2_24mV, &b_event_aclgad_LP2_24mV);
    fChain->SetBranchAddress("aclgad.LP2_26mV[18]", aclgad_LP2_26mV, &b_event_aclgad_LP2_26mV);
    fChain->SetBranchAddress("aclgad.LP2_28mV[18]", aclgad_LP2_28mV, &b_event_aclgad_LP2_28mV);
    fChain->SetBranchAddress("aclgad.LP2_30mV[18]", aclgad_LP2_30mV, &b_event_aclgad_LP2_30mV);
    fChain->SetBranchAddress("aclgad.gaus_mean[18]", aclgad_gaus_mean, &b_event_aclgad_gaus_mean);
    fChain->SetBranchAddress("aclgad.gaus_sigma[18]", aclgad_gaus_sigma, &b_event_aclgad_gaus_sigma);
    fChain->SetBranchAddress("aclgad.gaus_chi2[18]", aclgad_gaus_chi2, &b_event_aclgad_gaus_chi2);
    fChain->SetBranchAddress("aclgad.linear_RE_15[18]", aclgad_linear_RE_15, &b_event_aclgad_linear_RE_15);
    fChain->SetBranchAddress("aclgad.linear_RE_20[18]", aclgad_linear_RE_20, &b_event_aclgad_linear_RE_20);
    fChain->SetBranchAddress("aclgad.linear_RE_30[18]", aclgad_linear_RE_30, &b_event_aclgad_linear_RE_30);
    fChain->SetBranchAddress("aclgad.linear_RE_35[18]", aclgad_linear_RE_35, &b_event_aclgad_linear_RE_35);
    fChain->SetBranchAddress("aclgad.linear_RE_40[18]", aclgad_linear_RE_40, &b_event_aclgad_linear_RE_40);
    fChain->SetBranchAddress("aclgad.linear_RE_45[18]", aclgad_linear_RE_45, &b_event_aclgad_linear_RE_45);
    fChain->SetBranchAddress("aclgad.linear_RE_50[18]", aclgad_linear_RE_50, &b_event_aclgad_linear_RE_50);
    fChain->SetBranchAddress("aclgad.linear_RE__4mV[18]", aclgad_linear_RE__4mV, &b_event_aclgad_linear_RE__4mV);
    fChain->SetBranchAddress("aclgad.linear_RE__6mV[18]", aclgad_linear_RE__6mV, &b_event_aclgad_linear_RE__6mV);
    fChain->SetBranchAddress("aclgad.linear_RE__8mV[18]", aclgad_linear_RE__8mV, &b_event_aclgad_linear_RE__8mV);
    fChain->SetBranchAddress("aclgad.linear_RE__10mV[18]", aclgad_linear_RE__10mV, &b_event_aclgad_linear_RE__10mV);
    fChain->SetBranchAddress("aclgad.linear_RE__12mV[18]", aclgad_linear_RE__12mV, &b_event_aclgad_linear_RE__12mV);
    fChain->SetBranchAddress("aclgad.linear_RE__14mV[18]", aclgad_linear_RE__14mV, &b_event_aclgad_linear_RE__14mV);
    fChain->SetBranchAddress("aclgad.linear_RE__16mV[18]", aclgad_linear_RE__16mV, &b_event_aclgad_linear_RE__16mV);
    fChain->SetBranchAddress("aclgad.linear_RE__18mV[18]", aclgad_linear_RE__18mV, &b_event_aclgad_linear_RE__18mV);
    fChain->SetBranchAddress("aclgad.linear_RE__20mV[18]", aclgad_linear_RE__20mV, &b_event_aclgad_linear_RE__20mV);
    fChain->SetBranchAddress("aclgad.linear_RE__22mV[18]", aclgad_linear_RE__22mV, &b_event_aclgad_linear_RE__22mV);
    fChain->SetBranchAddress("aclgad.linear_RE__24mV[18]", aclgad_linear_RE__24mV, &b_event_aclgad_linear_RE__24mV);
    fChain->SetBranchAddress("aclgad.linear_RE__26mV[18]", aclgad_linear_RE__26mV, &b_event_aclgad_linear_RE__26mV);
    fChain->SetBranchAddress("aclgad.linear_RE__28mV[18]", aclgad_linear_RE__28mV, &b_event_aclgad_linear_RE__28mV);
    fChain->SetBranchAddress("aclgad.linear_RE__30mV[18]", aclgad_linear_RE__30mV, &b_event_aclgad_linear_RE__30mV);
    fChain->SetBranchAddress("aclgad.timeoffsets[18]", aclgad_timeoffsets, &b_event_aclgad_timeoffsets);
    fChain->SetBranchAddress("aclgad.trigger_cell[18]", aclgad_trigger_cell, &b_event_aclgad_trigger_cell);
    Notify();
}

bool merged_events::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return true;
}

void merged_events::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
#endif // #ifdef merged_events_cxx
