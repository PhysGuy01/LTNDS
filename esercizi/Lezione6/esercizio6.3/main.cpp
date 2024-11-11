#include "Solutore.h"
#include "FunzioneBase.h"
#include <iostream>
#include <cmath>
#include <iomanip>


#include "TGraph.h"
#include "TCanvas.h"
#include "TF1.h"
#include "TApplication.h"
#include "TAxis.h"
#include "TLegend.h"

using namespace std;

int main() {

    Trigonometrica T;

    Bisezione bis;

    int n_cifre = -log10(1e-06);
    
    for (int n = 0; n < 20; n++) {
        double inf = n * M_PI, sup = n * M_PI + M_PI/2;
        double zero = bis.CercaZeri(inf, sup, T);

        cout << "Zero della funzione nell'intervallo [a,b] = ["<< inf << ", " << sup << "]: x = " << fixed << setprecision(n_cifre)<< zero << endl; 
    }


    // ------------------------------------
    //   Grafico della funzione con ROOT
    // ------------------------------------

    TApplication app("app",0,0);

    TGraph trend;

    for (int k = 0 ; k < 10000; k++) {
        trend.SetPoint(k, k/200., T.Eval(k/200.));
    }

    TCanvas canva("f(x)","Grafico di funzione");
    canva.cd();
    canva.SetGridx();
    canva.SetGridy();
    canva.SetWindowSize(1200, 700);

    trend.SetMarkerStyle(15);
    trend.SetTitle("f(x) = sinx - x*cosx");
    trend.GetXaxis()->SetTitle("x");
    trend.GetYaxis()->SetTitle("f(x)");
    trend.Draw("ALP");

    canva.SaveAs("grafico.png");

    app.Run();


    return 0;
}
