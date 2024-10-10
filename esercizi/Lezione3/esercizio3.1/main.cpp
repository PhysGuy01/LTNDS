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

    return  0;
}