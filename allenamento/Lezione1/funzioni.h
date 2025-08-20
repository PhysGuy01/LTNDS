#pragma once

#include <fstream>
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

// Se nDat > nRighe, l'array sara' lungo solo nRighe.
int catchEOF(string filename, int nDat);

// Carica i dati da un file su un array di double lungo nDat.
double* loadData(string filename, double* dat, int nDat);

// Calcolo media di un array di double
double calcMean(double* dat, int nDat);

// Calcolo varianza
double calcVar(double* dat, int nDat);

// Calcolo mediana di un array di double ORDINATO
double calcMediana(double*dat, int nDat);

// Ordina array di double in ordine crescente
double* sortDat(double* newDat, int nDat);

// Stampa su un file .out i dati in ordine crescente
void print(string filename, double* newDat, int nDat);

// Stampa a video gli elementi di un array di double
void print(double* newDat, int nDat);