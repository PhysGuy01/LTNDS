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
    dat = loadData(filename, dat, nDat);


    // Calcolo valori statistici
    double media = calcMean(dat, nDat);
    double varianza = calcVar(dat, nDat);

    double* newDat = new double[nDat];
    // copio tutti gli elementi di dat in newDat
    for (int i = 0; i < nDat; i++) {
        newDat[i] = dat[i];
    }
    // li riordino 
    newDat = sortDat(newDat, nDat);

    double mediana = calcMediana(dat, nDat);


    // Stampa i risultati
    cout << "Media: " << media << endl <<
            "Varianza: " << varianza << endl << 
            "Mediana: " << mediana << endl;

    // Stampa su file i dati riordinati
    print("results.txt", newDat, nDat);
    
    delete[] dat;
    dat = nullptr;

    delete[] newDat;
    newDat = nullptr;

    return 0;
}