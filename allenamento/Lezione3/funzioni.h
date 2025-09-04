#include <algorithm>   
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "TApplication.h"
#include "TCanvas.h"
#include "TH1F.h"


using namespace std;

// Carica i dati da file in un vector
template <typename T> vector<T> loadData (string filename) {
    ifstream f(filename);
    if (!f) {
        cerr << "Errore apertura file " << filename << endl;
        exit(2);
    }

    vector<double> v;

    string line;
    while (getline(f, line)) 
        v.push_back(stod(line));

    return v;
}  

// calcola la media degli elementi di un vettore di tipo double
double calcMedia(vector<double> v) {
    double sum = 0;
    for (double val : v)
        sum += val;

    return (sum / v.size());
} 

// Calcola la varianza 
double calcVar(vector<double> v) {
    double sum = 0;
    double mean = calcMedia(v);

    for (double val : v) 
        sum += pow(mean - val, 2);

        return (sum / v.size());
}

// calcola la mediana di un vector di double 
double calcMediana(vector<double> v) {
    sort(v.begin(), v.end());
    int n = v.size();
    double medPari = (v[(n + 1)/ 2] + v[n / 2]) / 2;
    return (n % 2 == 0) ? medPari : v[n / 2];
}
