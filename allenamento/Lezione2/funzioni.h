#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include "Vettore.h"

using namespace std;

// Conta le righe del file, se nRighe < nDat : nDat = nRighe
int catchEOF(string filename, int nDat);

// Calcolo della media degli elementi di un vettore
double calcMedia(Vettore& v);

// Calcolo varianza degli elementi di un vettore
double calcVarianza(Vettore& v);

// Calcola la mediana di un vettore ORDINATO
double calcMediana(Vettore& vNew);

// Stampa elementi del vettore a video
void print(Vettore& v);

// Stampa elementi del vettore su file
void print(Vettore& v, string filename);