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

    Vettore v(nDat);
    v = Read(nDat, filename);

    double media = CalcMedia(v);
    double varianza = calcVarianza(v);
    double mediana = calcMediana(v);

    cout << "Analisi dati:" << endl <<
            "Media: " << media << endl << 
            "Varianza: " << varianza << endl << 
            "Mediana: " << mediana << endl;

    cout << endl << "Valori:" << endl << endl; 

    print(v);
    print(v, "results.out");

    return 0;
}