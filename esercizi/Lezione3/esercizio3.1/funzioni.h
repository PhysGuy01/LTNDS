#ifndef __funzioni_h__
#define __funzioni_h__

#include <iostream>
#include <string>
#include <fstream>
#include <cmath>

#include <vector>
#include <algorithm>

using namespace std;


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
template <typename T> vector<T> Read(int nDat, string& filename){
    fstream f;
    f.open(filename, ios::in);

    vector<T> V;

    for (int i = 0; i < nDat; i++)  {
        T val;
        f >> val;
        V.push_back(val);
    }

    return V;
}

// Calcola la media di un set di dati in un vettore
template <typename T> double CalcMedia(const vector<T>& V){
    double sum = 0;
    for (int i = 0; i < V.size(); i++) 
        sum += V[i];
    
    return sum / V.size();
}

// Calcola la varianza di un set di dati in un vettore
template <typename T> double calcVarianza(const vector<T>& v){
    double sum = 0;
    double media = CalcMedia(v);
    for (int i = 0; i < v.size(); i++) 
        sum += pow(v[i] - media,2);
    
    return sum / (v.size() - 1);
}

// Riordina il vettore in ordine crescente
template <typename T> double calcMediana(vector<T> v){
    sort(v.begin(), v.end()); // Riordina il vettore in ordine crescente
    int nDat = v.size(); 

    // Se il numero di dati e' pari, la mediana sara' data
    // dalla media dei due valori di mezzo, altrimenti
    // dall'unico valore in mezzo se e' dispari
    T medPari = (v[nDat/2] + v[nDat/2 - 1]) / 2;
    return (nDat % 2 == 0) ? medPari : v[nDat/2];
}


// Stampa i valori del vettore a video
template <typename T> void print(const vector<T>& v){
    for (int i = 0; i < v.size(); i++) 
        cout << "v[" << i << "] = " << v[i] << endl;
}

// Stampa i valori del vettore su file
template <typename T> void print(const vector<T>& v, string fileout) {
    fstream f;
    f.open(fileout, ios::app);

    for (int i = 0; i < v.size(); i++) 
        f << "v[" << i << "] = " << v[i] << endl;

    f.close();
}

#endif