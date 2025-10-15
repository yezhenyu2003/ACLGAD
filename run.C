#include "merged_events.C"

void run() {
    gSystem->Load("merged_events.C");
    merged_events *x=new merged_events();
    x->Loop();
}
