#pragma once

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cmath>
#include <string>

using namespace std;

// Dichiarazione funzioni
int catchEOF(string filename, int nDat);
double* loadDati(string filename, double* dat, int nDat);
void print(string filename, double* dat, int nDat);
void print(double* dat, int nDat);
double calcMedia(double* dat, int nDat);
double calcVar(double* dat, int nDat);
double* sortNewDat(double* newDat, int nDat);
double calcMediana(double* newDat, int nDat);
