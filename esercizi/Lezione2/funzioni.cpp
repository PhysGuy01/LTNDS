#include "funzioni.h"


// funzioni analisi
double CalcMedia(const Vettore& V) {
    double sum = 0;
    for (int i = 0; i < V.GetN(); i++) 
        sum += V.GetComponent(i);
    
    return sum / V.GetN();
}


// Se viene inserito un numero maggiore del numero di dati totale
// il numero di dati considerati diventa il numero massimo
int catchEOF(string filename, int nDat) {
    fstream f;
    f.open(filename, ios::in);

    string riga;
    int count = 0;
    while(getline(f, riga))
        count++;

    f.close();

    return (nDat > count) ? count : nDat;
}

Vettore Read(int nDat, string& filename) {
    fstream f;
    f.open(filename, ios::in);
    Vettore V(nDat);

    double dat;

    for (int i = 0; i < nDat; i++) {
        cout << V.GetComponent(i) << endl;
        f >> dat;
        cout << dat << " for component " << i << endl;
    //    V[i]=dat;
    }

    return V;
}