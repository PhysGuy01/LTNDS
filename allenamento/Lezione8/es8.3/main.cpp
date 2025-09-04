#include <iostream>
#include <vector>

#include "EqDifferenziali.h"

#include "TApplication.h"
#include "TCanvas.h"
#include "TAxis.h"
#include "TGraph.h"

using namespace std;


int main(int argc, char** argv) {
    if (argc < 2) {
        cout << "Uso: ./esercizio8.3 <stepsize>" << endl;
        return -1;
    }

    double h = stod(argv[1]);
    double tmax = 300.;
    int nsteps = int(tmax / h);

    TApplication app("app", 0,0);
    TCanvas c("Pendolo", "Pendolo");

    TGraph graf;
    int index = 0;


    c.cd();
    graf.GetXaxis()->SetTitle("Tempo");
    graf.GetYaxis()->SetTitle("Ampiezza");
    c.SetGridx();
    c.SetGridy();
    graf.SetMarkerStyle(20);
    

    Pendolo pend(1.);
    RungeKutta RG;
    vector<double> x{.1,0};
    
    double t = 0;
    for (int step = 0; step < nsteps; step++) {
        graf.SetPoint(step, t, x[0]);
        RG.Passo(t, x, h, pend);
        t += h;
    }


    c.Update();
    graf.Draw("ALP");

    app.Run();


    return 0;
}