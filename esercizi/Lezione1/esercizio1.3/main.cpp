#include "funzioni.h"

int main(int argc, char** argv) {
    
    if ( argc < 3 ) { 
        cout << "Uso del programma : " << argv[0] << " <n_data> <filename> " << endl;
        return 1;
    }

    int nDat = atoi(argv[1]);
    string filename = argv[2];

    nDat = catchEOF(filename, nDat);

    double* dat = new double[nDat];
    dat = loadDati(filename, dat, nDat);  

    double* newDat = new double[nDat];
    for (int i = 0; i < nDat; i++) {
        newDat[i] = dat[i];
    }

    sortNewDat(newDat, nDat); 

    cout << "Media: " << calcMedia(dat, nDat) << endl <<
            "Varianza: " << calcVar(dat, nDat) << endl << 
            "Mediana: " << calcMediana(newDat, nDat) << endl;

    // Stampa su file i dati riordinati in ordine crescente
    print("datiOrdineCresc.txt", newDat, nDat);

    delete[] dat;
    dat = nullptr;

    delete[] newDat;
    newDat = nullptr;

    return 0;
}