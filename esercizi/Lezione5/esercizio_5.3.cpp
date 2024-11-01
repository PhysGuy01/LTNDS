#include "CampoVettoriale.h"
#include "PuntoMateriale.h"
#include "TCanvas.h"
#include "TApplication.h"
#include "TGraph.h"
#include "TF1.h"

#include <cmath>
#include <fstream>

#include <cstdlib>
#include <cmath>
#include <iostream>

using namespace std;

int main(int argc, char** argv) {

    if (argc!= 4) {
        cout << "Utilizzo: " << argv[0] << " <x> <y> <z>" << endl;
        exit(1); 
    }

    Posizione p(atof(argv[1]), atof(argv[2]), atof(argv[3]));

    const double e =1.60217653E-19;
    const double me=9.1093826E-31;
    const double mp=1.6726219E-27;  
    const double d =1.E-10;

    PuntoMateriale elettrone(me, -e, 0., 0., d/2.);
    PuntoMateriale protone(mp, e, 0., 0., -d/2.);

    // Somma i campi vettoriali dell'elettrone e del protone
    CampoVettoriale E = elettrone.CampoElettrico(p) + protone.CampoElettrico(p);

    cout << "E = (" << E.getVX() << ", " << E.getVY() << ", " << E.getVZ() << ")" << endl;

    TApplication app("Grafico", 0, 0);

    TGraph *g = new TGraph();

    for (int i = 100; i < 1000; i++) {
        double z = i * d;
        Posizione pi(0, 0 , z);
        CampoVettoriale Ei = elettrone.CampoElettrico(pi) + protone.CampoElettrico(pi);
        g->SetPoint(i, z, Ei.getVZ()); // why does it show the first dot at y =0?
    }

    TCanvas *mygraph = new TCanvas("mygraph","grafico") ;
    g->SetMarkerStyle(21);
    g->SetMarkerColor(9);
    g->Draw("ALP");

    //TF1 *f1 = new TF1("f1","Ei",0.,10.);

    //f1->SetParameter(0,10.);     // Definire il parametro [0] a 10.
    //f1->SetParameters(5.,1.,0.1);   // Definire [0] -> 10. e [1] a 5.

   //g->Fit(f1);
    //cout << "Parametro 0 del fit : " << f1->GetParameter(0) << endl;
    //cout << "Parametro 1 del fit : " << f1->GetParameter(1) << endl;
    //cout << "Parametro 2 del fit : " << f1->GetParameter(2) << endl;

    app.Run();

    return 0;  
}