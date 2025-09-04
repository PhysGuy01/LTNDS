#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "TApplication.h"
#include "TCanvas.h"
#include "TGraphErrors.h"
#include "TAxis.h"
#include "TLegend.h"

using namespace std;

// Legge i dati in un file filename e li carica linea per linea in un vector
template <typename T> vector<T> loadData(string filename) {
    ifstream f(filename);
    if(!f) {
        cerr << "Errore nell'apertura del file " << filename << endl;
        exit(1);
    }

    string line;
    vector<T> v;
    while (getline(f, line))
        v.push_back(stod(line));

    f.close();
    
    return v;
}

// Calcola la media di un vector di double
double calcMedia(vector<double> v) {
    double sum = 0;

    for (int i : v)
        sum += i;

    return (sum / v.size());
}

// Calcola la dev std di un vector di double
double calcDevStd(vector<double> v) {
    double sum = 0;
    double mean = calcMedia(v);

    int n = 0;
    for (int i = 0; i < v.size(); i += 7)
        sum += pow(mean - v[i], 2);
    

    return (sum / v.size());
}


