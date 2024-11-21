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

    // 70 secondi
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
    c1->Divide(1,2); // 1 column 2 rows
    c1->cd(1); // (1);
    c1->SetWindowSize(600, 1400);
    //c1->SetWindowSize(900,700);
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
    for (int i = 0; i < 200; i++) {
        
        omega = 9. + 0.01 * (i+1); //* i;
        double v = 0.;
        t = 0.; 
        x = {0. , v};
        
        OscillatoreArmonicoForzato osc1(10., omega, alfa);
        for (int step = 0; step < nstep; step++) {
            //myGraph.SetPoint(step, t, x[0]);
            x = rung.Passo(t, x, h, osc1);
            t += h;
        }

        // cout << x[0] << endl;
        lorentz.SetPoint(i, omega, x[0]); // x[0] = ampiezza. e' giusto??
                                            // NO! DEVI FARE UN CONTROLLO SULLO STEP SUCCESSIVO E POI VERIFICARE PRODOTTO DELLE VELOCITA' E' NEGATIVO, SE E' NEGATIVO HO TROVATO IL MAX (? NON SO SE HAI DAVERO TROVATO IL MAX IN REALTA' NON E' STATO MOLTO CHIARO MI DISPPPPP)
    }
    lorentz.SetMarkerStyle(20);
    lorentz.SetTitle("Periodo di oscillazione");
    lorentz.GetXaxis()->SetTitle("Ampiezza [m]");
    lorentz.GetYaxis()->SetTitle("Periodo [s]");
    lorentz.Draw("ALP");
    gPad->SetGridy(1);
    gPad->SetGridx(1);

    // // Grafico dell'errore

    // TGraph err;
    //    c1->cd(3);

    // for (int i = 1; i < 10; i++) {
    //     h = 0.1 * pow(0.5, i);
    //     x = {0., 1.};
    //     t = 0.;
    //     int nstep = int(floor(tmax / h + 0.5));

    //     for (int step = 0; step < nstep; step++) {
    //         x = rung.Passo(t, x , h, osc);
    //         t += h;
    //     }
    //     double e = fabs(x[0] - sin(t));
    //     err.SetPoint((i -1), h, e);
    // }

    // err.GetXaxis()->SetTitle("Errore [m]");
    // err.GetYaxis()->SetTitle("Passi di integrazione h [s]");
    // err.SetMarkerStyle(20);
    // err.Draw("APL");
    // gPad -> SetLogy();
    // gPad -> SetLogx();
    // gPad->SetGridy(1);
    // gPad->SetGridx(1);
    
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