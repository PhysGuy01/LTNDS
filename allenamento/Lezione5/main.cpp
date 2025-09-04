#include "funzioni.h"

int main(int argc, char** argv) {

    if (argc < 4) {
        cerr << "Uso programma: ./esercizio5 <x> <y> <z>" << endl;
        return 1;
    }


    // Costruiamo un dipolo protone - elettrone a distanza di 10e-10 m
    double massProt = 1.67262192595e-27;
    double e = 1.602176634e-19;
    double massElet = 9.1093837139E-31;
    double d = 1e-10;

    PuntoMateriale protone(massProt, e, 0,0,0);
    PuntoMateriale elettrone(massElet, -e, 0,0,d);


    Posizione p(stod(argv[1]), stod(argv[2]), stod(argv[3]));
    
    CampoVettoriale dipolo = elettrone.CampoElettrico(p) + protone.CampoElettrico(p);

    cout <<  "Modulo: " << dipolo.Modulo() << endl;

    
    // Plotting root

    TApplication app("app", 0,0);
    
    TCanvas c("Campo dipolo", "Grafico del campo di un dipolo");
    c.cd();

    TGraph trend;

    int index{0};
    for (int i = 100 ; i < 1000; i++) {
        double z = i * d;
        Posizione Pi(0, 0, z);
        CampoVettoriale Ei = elettrone.CampoElettrico(Pi) + protone.CampoElettrico(Pi);
        trend.SetPoint(index, z, Ei.getFz());
        index++;
    }

    c.SetGridx();
    c.SetGridy();

    trend.GetXaxis()->SetTitle("z");
    trend.GetYaxis()->SetTitle("Campo Elettrico");
    trend.Draw();
    c.Update();

    app.Run();

    return 0;
}