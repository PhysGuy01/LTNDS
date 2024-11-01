#pragma once
#include "FunzioneBase.h"
#include <math.h>
#include <iostream>

using namespace std;

// Implementa una funzione segno che ritorna +-1 a seconda del segno del valore passato
int sign(double x) {return (x > 0 ? 1 : -1);};
 

class Solutore {
    public:  
        Solutore(){;};
        Solutore(int prec) {mprec = prec;};

        void setPrecisione(double prec) {mprec = prec;};
        double getPrecisione() {return mprec;};

        void setMaxIter(unsigned int n) {nmax = n;};
        unsigned getMaxIter() {return nmax;};

        unsigned getNIter() {return niter;};

        virtual double CercaZeri(double xmin ,
                                    double xmax ,
                                    const FunzioneBase& f,
                                    double prec = 0.001,
                                    unsigned int nmax = 100) = 0;

    protected:
        double ma, mb; // estremi intervallo
        double mprec; // precisione
        unsigned int nmax; // numero max di iterazioni permesse
        unsigned int niter; // numero di iterazioni effettuate

};

class Bisezione : public Solutore {
    public:

        Bisezione(){;};
        Bisezione(double prec) {mprec = prec;};

        virtual double CercaZeri(double xmin, double xmax,
                                    const FunzioneBase& f,
                                    double prec = 0.001, // valori di default
                                    unsigned int nmax = 100)  ;
};

double Bisezione::CercaZeri(double xmin, double xmax, const FunzioneBase& f, double prec, unsigned int nmax) {
    double a = xmin; // estremo inferiore
    double b = xmax; // estremo superiore

    double zero = nan("1");
    
    if (sign(f.Eval(a)) * sign(f.Eval(b)) > 0) {
        cout << "Errore: Non e' detto che la funzione abbia zeri!" << endl;
        exit(2);
    } else {
        for (int i = 0; i < nmax; i++) {
            double xmed = (a + b) / 2;
            if (f.Eval(xmed) > 0)
                b = xmed;
            
            else if (f.Eval(xmed) < 0) 
                a = xmed;
            
            else {
                zero = xmed; 
                break;
            }
        }
    }

    if (isnan(zero)) {
        cout << "Limite di iterazioni ecceduto. Calcolata la migliore stima." << endl;
        return (a + b) / 2;
    } else {
        return zero;
    }
}

