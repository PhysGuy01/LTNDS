#include "EqDifferenziali.h"

#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

#include "TApplication.h"
#include "TAxis.h"
#include "TCanvas.h"
#include "TGraph.h"

using namespace std;

string convert (double h) ;

int main (int argc, char** argv ) {

    if (argc != 2) {
        cerr << "Usage: " << argv[0] << " <stepsize>" << endl;
        return -1;
    }  

    TApplication myApp("myApp",0,0);

    RungeKutta rung;

    OscillatoreArmonico osc(1.);

    double tmax = 70.;
    double h = atof(argv[1]);

    vector<double> x {0.,1.} ;

    double t = 0.; 

    TGraph myGraph ;
    int nstep = int(floor(tmax/h + 0.5));

    // evoluzione del sistema fino a 70 s  

    for (int step = 0; step < nstep; step++) {
        myGraph.SetPoint(step, t, x[0]);
        x = rung.Passo(t, x, h, osc);
        t += h;
    }

    // grafici  

    TCanvas c ;
    c.cd();
    string title = "Oscillatore armonico (Rung h = " + convert(h) + ")" ;
    myGraph.SetTitle(title.c_str());
    myGraph.GetXaxis()->SetTitle("Tempo [s]");
    myGraph.GetYaxis()->SetTitle("Posizione x [m]");
    myGraph.Draw("AL");


    // Grafico dell'errore

    TGraph err;

    for (int i = 0; i < 10; i++) {
        h = 0.1 * pow(0.5, i);
        x = {0., 1.};
        t = 0.;
        int nstep = int(floor(tmax / h + 0.5));

        for (int step = 0; step < nstep; step++) {
            x = rung.Passo(t, x , h, osc);
            t += h;
        }
    }

    

    myApp.Run();
}

string convert (double h) {

    int cifre_significative = -log10(h);

    ostringstream streamObj3;

    streamObj3 << fixed << setprecision(cifre_significative) << h;
    string strObj3 = streamObj3.str();

    return strObj3;
} 