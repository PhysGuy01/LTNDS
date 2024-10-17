#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <sstream>

#include <vector>
#include <algorithm>

#include "TGraphErrors.h"
#include "TCanvas.h"
#include "TF1.h"
#include "TApplication.h"
#include "TAxis.h"
#include "TLegend.h"

using namespace std;

// Carica un vettore con i dati dal file e lo ritorna
template <typename T> vector<T> Read(string& filename){
    fstream f;
    f.open(filename, ios::in);

    vector<T> V;

    string line;
    while(getline(f, line)) {
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
template <typename T> double CalcDevStd(const vector<T>& v){
    double sum = 0;
    double media = CalcMedia(v);
    for (int i = 0; i < v.size(); i += 7) // cicla su ogni 7 giorni per avere
        sum += pow(v[i] - media,2);       // dati indipendenti per la dev std
    
    return sum / (v.size() - 1);
}


// Stampa i valori del vettore su file e a video
void print(stringstream &ss, string fileout) {
    fstream f;
    f.open(fileout, ios::app);

    f << ss.str();
    cout << ss.str();

    ss.str("");
    ss.clear();

    f.close();
}