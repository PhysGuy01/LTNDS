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

    double alfa = 1./30.;
    double omega = 10.;
    OscillatoreArmonicoForzato osc(10., omega, alfa);

    double tmax = 30.;
    double h = atof(argv[1]);

    // condizioni iniziali
    vector<double> x {0.,0.} ;

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
    c1->Divide(1,2); 
    c1->cd(1);
    c1->SetWindowSize(600, 1400);
    string title = "Oscillatore armonico forzato (h = " + convert(h) + ")" ;
    myGraph.SetTitle(title.c_str());
    myGraph.GetXaxis()->SetTitle("Tempo [s]");
    myGraph.GetYaxis()->SetTitle("Posizione x [m]");
    myGraph.Draw("AL");
    gPad->SetGridy(1);
    gPad->SetGridx(1);

    TGraph lorentz;
    c1->cd(2);
    nstep = int(floor(10 * alfa/h + 0.5));


    for (int i = 0; i < 15; i++) {
        omega = 9.6 + 0.05 * (i+1);
        OscillatoreArmonicoForzato osc1(10., omega, alfa);
        x = {0., 0.};
        t = 0.;
        double tmax = 100.; 
        double max_x = 0.;
        for (int step = 0; t < tmax; step++) {
            x = rung.Passo(t, x, h, osc1);
            t += h;
            if (t > tmax - 10.) { 
                if (fabs(x[0]) > max_x) max_x = fabs(x[0]);
            }
        }
        lorentz.SetPoint(i, omega, max_x);
    }

    lorentz.SetMarkerStyle(20);
    lorentz.SetTitle("Periodo di oscillazione");
    lorentz.GetXaxis()->SetTitle("Pulsazione [rad/s]");
    lorentz.GetYaxis()->SetTitle("Ampiezza [m]");
    lorentz.Draw("ALP");
    gPad->SetGridy(1);
    gPad->SetGridx(1);

    c1->Update();

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