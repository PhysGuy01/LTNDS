#include "funzioni.h"

int catchEOF(string filename, int nDat) {
    ifstream fin(filename);

    // Conta le righe nel file
    string line;
    int nRighe = 0;
    while (getline(fin, line))
        nRighe++;

    return (nRighe < nDat) ? nRighe : nDat; // se i dati passati sono piu del numero di righe, nDat = nRighe
}
// Calcolo della media degli elementi di un vettore
double calcMedia(Vettore& v) {
    double sum = 0;

    for (int i = 0; i < v.getN(); i++) 
        sum += v.getComponent(i);
    
    return (sum / v.getN());
}

// Calcolo varianza degli el...
double calcVarianza(Vettore& v) {
    double sum = 0;
    double mean = calcMedia(v);

    for (int i = 0; i < v.getN(); i++) {
        sum += pow(v.getComponent(i) - mean, 2);
    }

    return (sum / v.getN());
}

// Calcola la mediana di un vettore ORDINATO
double calcMediana(Vettore& vNew) {
    double medPari = vNew.getComponent(vNew.getN()/2 + 1) - vNew.getComponent(vNew.getN()/2);
    return (vNew.getN() % 2 == 0) ? medPari : vNew.getComponent(vNew.getN() / 2);
}

// Stampa elementi del vettore a video
void print(Vettore& v) {
    for (int i = 0; i < v.getN(); i++) 
        cout << "v[" << i << "] = " << v.getComponent(i) << endl;
}

// Stampa elementi del vettore su file
void print(Vettore& v, string filename) {
    ofstream f(filename);

    for (int i = 0; i < v.getN(); i++) 
        f << "v[" << i << "] = " << v.getComponent(i) << endl; 

    f.close();
}