#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <cmath>

#include "Vettore.h"

using namespace std;

int catchEOF(string filename, int nDat);
Vettore Read(int nDat, string& filename);
double CalcMedia(const Vettore& V);
double calcVarianza(const Vettore& v);
double calcMediana(Vettore v);
Vettore sortVett(Vettore& v);
void print(const Vettore& v);
void print(const Vettore& v, string fileout);