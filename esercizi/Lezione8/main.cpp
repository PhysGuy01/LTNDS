#include "EqDifferenziali.h"

#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <cmath>

#include "TApplication.h"
#include "TAxis.h"
#include "TCanvas.h"
#include "TGraph.h"

using namespace std;

string convert (double h);

int main (int argc, char** argv ) {

    if (argc != 2) {
        cerr << "Usage: " << argv[0] << " <stepsize>" << endl;
        return -1;
    }  

    TApplication myApp("myApp",0,0);

    RungeKutta rung;

    OscillatoreArmonico osc(1.);

    // 70 secondi
    double tmax = 70.;
    double h = atof(argv[1]);

    // condizioni iniziali
    vector<double> x {0.,1.} ;

    double t = 0.; 

    TGraph myGraph ;
    int nstep = int(floor(tmax/h + 0.5));


    for (int step = 0; step < nstep; step++) {
        myGraph.SetPoint(step, t, x[0]);
        x = rung.Passo(t, x, h, osc);
        t += h;
    }

    // grafico  
    TCanvas *c1 = new TCanvas();
    c1->Divide(1,2); // 1 column 2 rows
    c1->cd(1);
    c1->SetWindowSize(1200, 700);
    string title = "Oscillatore armonico (h = " + convert(h) + ")" ;
    myGraph.SetTitle(title.c_str());
    myGraph.GetXaxis()->SetTitle("Tempo [s]");
    myGraph.GetYaxis()->SetTitle("Posizione x [m]");
    myGraph.Draw("AL");
    gPad->SetGridy(1);
    gPad->SetGridx(1);


    // Grafico dell'errore

    TGraph err;

    for (int i = 1; i < 10; i++) {
        h = 0.1 * pow(0.5, i);
        x = {0., 1.};
        t = 0.;
        int nstep = int(floor(tmax / h + 0.5));

        for (int step = 0; step < nstep; step++) {
            x = rung.Passo(t, x , h, osc);
            t += h;
        }
        double e = fabs(x[0] - sin(t));
        err.SetPoint((i -1), h, e);
    }

    err.GetXaxis()->SetTitle("Errore [m]");
    err.GetYaxis()->SetTitle("Passi di integrazione h [s]");
    err.SetMarkerStyle(20);
    c1->cd(2);
    err.Draw("APL");
    gPad -> SetLogy();
    gPad -> SetLogx();
    gPad->SetGridy(1);
    gPad->SetGridx(1);
    
    c1->Update(); // Forza l'update della canvas

    c1->SaveAs("grafici.png");


    myApp.Run();
}

string convert (double h) {

    int cifre_significative = -log10(h);

    ostringstream streamObj3;

    streamObj3 << fixed << setprecision(cifre_significative) << h;
    string strObj3 = streamObj3.str();

    return strObj3;
} 