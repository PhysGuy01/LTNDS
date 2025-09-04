#include "RandomGen.h"

#include <iostream>

#include "TApplication.h"
#include "TCanvas.h"
#include "TH1F.h"
#include "TAxis.h"

using namespace std;

int main(int argc, char** argv) {

    if (argc < 2) {
        cout << "Uso: ./esercizio10.0 <seed>" << endl;
        return -1;
    }
    int seed = stoi(argv[1]);

    TApplication app("app", 0, 0);
    TCanvas c("Distribuzioni", "histo");

    TH1F histo("histo", "histo", 100, 0, 1);

    RandomGen RG(seed);
    for (int i = 0; i < 10000; i++) {
        histo.Fill(RG.Gaus(.5,.1));
    }

    c.cd();
    histo.Draw();
    histo.GetXaxis()->SetTitle("measurement");

    app.Run();

    return 0;
}