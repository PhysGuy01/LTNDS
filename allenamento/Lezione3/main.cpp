#include "funzioni.h"

int main(int argc, char** argv) {

    if (argc < 3) {
        cout << "Uso programma: ./esercizio3.1 <n_data> <filename>" << endl;
        return 1; 
    }

    int nDat = atoi(argv[1]);
    string filename = argv[2];

    vector<double> v;

    v = loadData<double>(filename);

    cout << "Media: " << calcMedia(v) << endl <<
            "Varianza: " << calcVar(v) << endl <<
            "Mediana: " << calcMediana(v) << endl;


    // ROOT
    TApplication app("app", 0, 0);
    TH1F histo("histo", "histo", 100, -10, 100);

    histo.StatOverflows(kTRUE);
    
    for (double val : v) 
        histo.Fill(val);

    cout << "Media da ROOT: " << histo.GetMean() << endl;


    // disegno
    TCanvas canva("Histo", "Histo");
    histo.Draw();
    histo.GetXaxis()->SetTitle("measurement");


    app.Run();


    return 0;
}