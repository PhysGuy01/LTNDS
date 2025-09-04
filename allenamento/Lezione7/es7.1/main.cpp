#include "funzioni.h"

int main (int argc, char** argv) {
    
    if (argc < 2) {
        cout << "Uso: ./esercizio7.1 <nstep>" << endl;
        return 1;
    }

    int nstep = stoi(argv[1]);

    xSinx f;
    Simpson simp(0, M_PI/2);
    cout << "Integrale di x*sin(x) su [0, pi/2]: " << simp.Integra(f, nstep) << endl;


    int list[] = {10, 100, 1000, 10000};

    cout << "Valore atteso (1) vs valore calcolato" << endl <<
            "num di iter\t|\tvalore\t\t|\tprecisione  " << endl;

    for (int i : list) {
        double integ = simp.Integra(f, i);
        double prec = 1 - integ;
        cout << "\t"<< i <<"\t|\t"<<integ<<  "\t|\t" << prec << endl;
    }


    TApplication app("app", 0, 0);
    TCanvas c("Grafico Errore", "Grafico Errore");
    c.cd();
    TGraph graf;


    /*
    int i = 10, index = 0;
    double integ = simp.Integra(f, i);
    double prec = 1 - integ;

    while (i < 10000000) {
        graf.SetPoint(index, i, prec);

        integ = simp.Integra(f, i);
        prec = 1 - integ;
        i *= 10;
        index++;
    } 
    */

    int index = 0;
    double integ, prec;

    for (int i = 10; i < 1000000; i*=3) {
        integ = simp.Integra(f, i);
        prec = 1 - integ;

        graf.SetPoint(index, i, prec);
        index++;
    }

    c.SetGridx();
    c.SetGridy();

    graf.GetXaxis()->SetTitle("numero iterazioni");
    graf.GetYaxis()->SetTitle("errore");

    c.SetLogx();
    c.SetLogy();

    graf.SetMarkerStyle(20);
    graf.Draw("ALP");
    c.Update();

    c.SaveAs("graph.png");
    app.Run();


    return 0;
}