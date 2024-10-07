#include "funzioni.h"

int main(int argc, char** argv) {
    
    // Controlla se gli argomenti passati sono almeno 2
    if ( argc < 3 ) { 
        cout << "Uso del programma : " << argv[0] << " <n_data> <filename> " << endl;
        return 1;
    }

    int nDat = atoi(argv[1]);
    string filename = argv[2];

    nDat = catchEOF(filename, nDat);

    double* dat = new double[nDat];
    dat = loadDati(filename, dat, nDat);  

    // Crea nuovo array ordinato
    double* newDat = new double[nDat];
    // copia l'array
    for (int i = 0; i < nDat; i++) {
        newDat[i] = dat[i];
    }

    sortNewDat(newDat, nDat); // ordina il nuovo array

    cout << "Media: " << calcMedia(dat, nDat) << endl <<
            "Varianza: " << calcVar(dat, nDat) << endl << 
            "Mediana: " << calcMediana(newDat, nDat) << endl;

    // Stampa su file i dati riordinati
    print("results.txt", newDat, nDat);

    delete[] dat;
    dat = nullptr;

    delete[] newDat;
    newDat = nullptr;

    return 0;
}