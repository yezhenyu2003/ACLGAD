void filter(TString oldfilename="Run81305XX.root")
{
    TFile* oldfile=new TFile(oldfilename, "read");
    TTree* oldtree=(TTree*)oldfile->Get("merged_events");

    Int_t layers_used=-1;
    oldtree->SetBranchAddress("babymoss_project.layers_used", &layers_used);
    
    TFile newfile(oldfilename+"_filtered.root", "recreate");
    auto newtree = oldtree->CloneTree(0);

    for (Long64_t jentry=0; jentry<oldtree->GetEntries();jentry++) {
        oldtree->GetEntry(jentry);
        if(layers_used<5) continue;
        newtree->Fill();
    }
    newfile.Write();
}
