#include "funzioni.h"

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


// Carica i dati dal file passati in un array di double dichiarato nel main
double* loadDati(string filename, double* dat, int nDat) {
    fstream f;
    f.open(filename, ios::in);

    for (int i = 0; i < nDat; i++)
        f >> dat[i];

    f.close();

    return dat;
}


// Stampa su file i dati di un array
void print(string filename, double* dat, int nDat) {
    fstream f;
    f.open(filename, ios::out);

    for (int i = 0; i < nDat; i++) 
        f << "dat[" << i << "] = " << dat[i] << endl;

    f.close();
}


// Calcola la media
double calcMedia(double* dat, int nDat) {
    double sum = 0;
    for (int i = 0; i < nDat; i++) 
        sum += dat[i];

    return sum / nDat;
}


// Calcola la varianza (sigma^2)
double calcVar(double* dat, int nDat) {
    double S = 0;
    double mu = calcMedia(dat, nDat);

    for (int i = 0; i < nDat; i++) 
        S += pow(dat[i] - mu, 2);
    
    return S / nDat;
}


// Ordina un array di double (newDat e' il nuovo array di dati copiato)
double* sortNewDat(double* newDat, int nDat) {
    for (int i = 0; i < nDat; i++)
        for (int j = i + 1; j < nDat; j++) {
            if (newDat[j] < newDat[i])  {
                double tmp = newDat[i];
                newDat[i] = newDat[j];
                newDat[j] = tmp;
            }
        }

    return newDat;
}


// Calcola la mediana di un set di double 
double calcMediana(double *newDat, int nDat) {

    // NB: nDat/2 ritorna sempre un int quindi se nDat e' dispari 
    // ritorna l'intero senza numeri dopo la virgola
    double medPari = (newDat[nDat/2] + newDat[nDat/2 - 1]) / 2;
    return (nDat % 2 == 0) ? medPari : newDat[nDat/2];
}


// Stampa a video gli elementi di un array di double
void print(double* dat, int nDat) {
    for (int i = 0; i < nDat; i++) 
        cout << "dat[" << i << "] =\t" << dat[i] << endl;
}