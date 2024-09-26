#include "funzioni.h"

// Esercizio 1.1 main omnicomprensivo
// Esercizio 1.2 file separati
// Esercizio 1.3 aggiungi funzione print (<-- consegna questo)

// bubble sort?
// sort array orginale o per forza copia

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