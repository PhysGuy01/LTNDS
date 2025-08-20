#include "funzioni.h"

// Se nDat > nRighe, l'array sara' lungo solo nRighe.
int catchEOF(string filename, int nDat) {
    ifstream file(filename);
    if (!file) {
        cerr << "Errore nel caricare il file di dati." << endl;
    }

    int nRighe = 0;
    string riga;
    while(getline(file, riga))
        nRighe++;
    
    file.close();

    return (nDat > nRighe) ? nRighe : nDat;
}

// Carica i dati da un file su un array di double lungo nDat.
double* loadData(string filename, double* dat, int nDat) {
    ifstream file(filename);
    if (!file) {
        cerr << "Errore nel caricare il file di dati." << endl;
    }

    for (int i = 0; i < nDat; i++)
        file >> dat[i];

    file.close();

    return dat;
}

// Calcolo media di un array di double
double calcMean(double* dat, int nDat) {
    double sum = 0;
    for (int i = 0; i < nDat; i++)
        sum += dat[i];
    
    double mean = sum / nDat;
    return mean;
}

// Calcolo varianza
double calcVar(double* dat, int nDat) { 
    double sum = 0;
    double mu = calcMean(dat, nDat);

    for (int i = 0; i < nDat; i++) 
        sum += pow(dat[i] - mu, 2);
    
    return sum / nDat;
}

// Calcolo mediana di un array di double ORDINATO
double calcMediana(double* dat, int nDat) {

    // calcola la media tra i due valori centrali se nDat e' pari
    double medPari = (dat[nDat/2] + dat[nDat/2 - 1]) / 2;
    return (nDat % 2 == 0) ? medPari : dat[nDat/2];
}

// Ordina array di double in ordine crescente
double* sortDat(double* newDat, int nDat) {
    for (int i = 0; i < nDat; i++)
        for (int j = i + 1; j < nDat; j++) 
            if (newDat[j] < newDat[i]) {
                double tmp = newDat[i];
                newDat[i] = newDat[j];
                newDat[j] = tmp;
            }
    
    return newDat;
}

// Stampa su un file .out i dati in ordine crescente
void print(string filename, double* newDat, int nDat) {
    ofstream of(filename);

    for (int i = 0; i < nDat; i++) 
        of << newDat[i] << endl;
    
    of.close();
}

// Stampa a video gli elementi di un array di double
void print(double* newDat, int nDat) {
    for (int i = 0; i < nDat; i++) 
        cout << "dat[" << i << "] = " <<  newDat[i] << endl;
}