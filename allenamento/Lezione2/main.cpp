#include "funzioni.h"

int main(int argc, char** argv) {
    if (argc < 3) {
        cerr << "Utilizzo del programma: ./esercizio2.2 <n_data> <filename>" << endl;
        return 1;
    }
        
    int nDat = atoi(argv[1]);
    string filename = argv[2];

    ifstream fin(filename);
    if (!fin) {
        cerr << "Errore apertura file!" << endl;
        return 1;
    }

    nDat = catchEOF(filename, nDat);


    // Costruzione del vettore e apertura file
    Vettore v(nDat);

    // Caricamento dati da file nel vettore v
    for (int i = 0; i < nDat; i++) {
        fin >> v[i];
    }

    
    // Analisi dei dati sul vettore
    v.sortVett();
    cout << "Analisi..." << endl 
        << "    - Media: " << calcMedia(v) << endl
        << "    - Varianza: " << calcVarianza(v) << endl
        << "    - Mediana: " << calcMediana(v) << endl;
    
    print(v, "output.out");

    return 0;   
}