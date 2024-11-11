#include "Integral.h"
#include "FunzioneBase.h"

#include <cmath>
#include <iostream>
#include <iomanip>

#include "TGraph.h"
#include "TCanvas.h"
#include "TF1.h"
#include "TApplication.h"
#include "TAxis.h"
#include "TLegend.h"

using namespace std;

int main(int argc, char** argv) {
        
    if (argc != 2) {
        cout << "Utilizzo: ./" << argv[0] << "<nsteps>" << endl;
        exit(1);  
    }   

    double nsteps = atof(argv[1]); 

    xsinx f;

    Simpson integ(0., M_PI/2.);

    double I = integ.Integra(nsteps, f);

    cout << "Integrale di f(x) = xsinx in [0, pi/2]: " << I << endl;


    // Grafico con ROOT

    TApplication app("app",0,0);

    TGraph trend;

    int nstep = 4;
    double Iv = 1.; // valor vero dell'integrale
    double Iw = 0, err = 0 , h = 0;

    for (int k = 0 ; k < 10; k++) {
        h = (0.-M_PI/2.)/nstep; 
        Iw = integ.Integra(nstep, f); 
        err = fabs(Iw-Iv);

        trend.SetPoint(k, nstep, h);
        nstep *= 2;
    }

    TCanvas canva("Precisione","Passi");
    canva.cd();
    canva.SetGridx();
    canva.SetGridy();
    canva.SetWindowSize(1200, 700);

    trend.SetMarkerStyle(20);
    trend.SetTitle("Precisione in funzione del numero di passi");
    trend.GetXaxis()->SetTitle("Passo");
    trend.GetYaxis()->SetTitle("Precisione");
    trend.Draw("ALP");

    canva.SaveAs("trend.png");

    app.Run();

    return 0;

}