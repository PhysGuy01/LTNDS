#include "CampoVettoriale.h"
#include "PuntoMateriale.h"


#include "TGraph.h"
#include "TCanvas.h"
#include "TF1.h"
#include "TApplication.h"
#include "TAxis.h"
#include "TLegend.h"


#include <cmath>
#include <fstream>

#include <cstdlib>
#include <cmath>
#include <iostream>

using namespace std;

int main(int argc, char** argv) {

    if (argc != 4) {
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
    

    // ------------------------------------
    //   Grafico della funzione con ROOT
    // ------------------------------------

    TApplication app("Grafico", 0, 0);

    TGraph trend;

    int index = 0;
    for (int i = 100; i < 1000; i++) {
        double z = i * d;
        Posizione pi(0, 0 , z);
        CampoVettoriale Ei = elettrone.CampoElettrico(pi) + protone.CampoElettrico(pi);
        trend.SetPoint(index, z, Ei.getVZ()); 
        index++;
    }

    TCanvas canva("Campo dipolo","Grafico del campo elettrico");
    canva.cd();

    canva.SetGridx();
    canva.SetGridy();
    canva.SetWindowSize(1200, 700);
    
    trend.SetMarkerStyle(15);
    trend.SetTitle("Grafico del campo elettrico di un dipolo");
    trend.GetXaxis()->SetTitle("z");
    trend.GetYaxis()->SetTitle("E(z)");
    trend.Draw("ALP");
    canva.Update();

    app.Run();

    return 0;  
}