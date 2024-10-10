#include "funzioni.h"

int main(int argc, char** argv) {

    if (argc < 3) {
        cout << "Utilizzo programma: ./prog <n_data> <filename>" << endl;
        exit(99); 
    }

    int nDat = atoi(argv[1]);
    string filename = argv[2];

    // se nDat > nRighe: nDat = nRighe
    nDat = catchEOF(filename, nDat);

    vector<double> v(nDat);
    v = Read<double>(nDat, filename);

    double media = CalcMedia<double>(v);
    double varianza = calcVarianza<double>(v);
    double mediana = calcMediana<double>(v);

    cout << "Analisi dati:" << endl <<
            "Media: " << media << endl << 
            "Varianza: " << varianza << endl << 
            "Mediana: " << mediana << endl;

    cout << endl << "Valori:" << endl << endl; 

    print<double>(v);
    print<double>(v, "results.out");



    // -----------------
    //      ROOT
    // -----------------

    TApplication app("app",0,0);

    TH1F histo("Dati","Istogramma misure 1941", 100, -10, 10) ;
    histo.StatOverflows(kTRUE);

    for (int i = 0 ; i < v.size(); i++)   
        histo.Fill(v[i]);

    TCanvas mycanvas ("isto","Istogramma");
    histo.Draw();
    histo.GetXaxis()->SetTitle("Misure");

    app.Run();

    return 0;
}