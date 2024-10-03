#pragma once

#include <iostream>
#include <string>
#include <fstream>

#include "Vettore.h"

using namespace std;

double CalcMedia(const Vettore& V);
int catchEOF(string filename, int nDat);
Vettore Read(int nDat, string& filename);