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

// Carica un vettore con i dati dal file e lo ritorna
template <typename T> Vettore<T> Read(int nDat, string& filename) {
    fstream f;
    f.open(filename, ios::in);

    Vettore<T> V(nDat);

    for (int i = 0; i < nDat; i++) 
        f >> V[i];

    return V;
}

// Funzioni analisi:

// Calcola la media di un set di dati in un vettore
template <typename T> T CalcMedia(const Vettore<T>& V) {
    double sum = 0;
    for (int i = 0; i < V.GetN(); i++) 
        sum += V.GetComponent(i);
    
    return sum / V.GetN();
}

// Calcola la varianza di un set di dati in un vettore
template <typename T> T calcVarianza(const Vettore<T>& v) {
    double sum = 0;
    double media = CalcMedia(v);
    for (int i = 0; i < v.GetN(); i++) 
        sum += pow(v.GetComponent(i) - media,2);
    
    return sum / (v.GetN() - 1);
}

// Riordina il vettore in ordine crescente
template <typename T> Vettore<T> sortVett(Vettore<T>& v) {
    // Bubble sort
    for (int i = 0; i < v.GetN(); i++)
        for (int j = i + 1; j < v.GetN(); j++) 
            if (v.GetComponent(j) < v.GetComponent(i))  
                v.Scambia(i, j);
            
    return v;
}

// Calcola la mediana di un set di dat in un vettore
template <typename T> T calcMediana(Vettore<T> v) {
    sortVett(v); // Riordina il vettore in ordine crescente
    int nDat = v.GetN(); 

    // Se il numero di dati e' pari, la mediana sara' data
    // dalla media dei due valori di mezzo, altrimenti
    // dall'unico valore in mezzo se e' dispari
    T medPari = (v[nDat/2] + v[nDat/2 - 1]) / 2;
    return (nDat % 2 == 0) ? medPari : v[nDat/2];
}


// Stampa i valori del vettore a video
template <typename T> void print(const Vettore<T>& v) {
    for (int i = 0; i < v.GetN(); i++) 
        cout << "v[" << i << "] = " << v.GetComponent(i) << endl;
}

// Stampa i valori del vettore su file
template <typename T> void print(const Vettore<T>& v, string fileout) {
    fstream f;
    f.open(fileout, ios::app);

    for (int i = 0; i < v.GetN(); i++) 
        f << "v[" << i << "] = " << v.GetComponent(i) << endl;

    f.close();
}