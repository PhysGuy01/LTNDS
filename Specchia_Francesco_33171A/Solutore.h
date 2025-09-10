#pragma once
#include "FunzioneBase.h"
#include <math.h>
#include <iostream>

using namespace std;

// Implementa una funzione segno che ritorna +1 o -1 a seconda del segno del valore passato
int sign(double x) {return (x > 0 ? 1 : -1);};
 

class Solutore {
    public:  
        Solutore(){;};
        Solutore(int prec) {mprec = prec;};

        void setPrecisione(double prec) {mprec = prec;};
        double getPrecisione() {return mprec;};

        void setMaxIter(unsigned int n) {nmax = n;};
        unsigned getMaxIter() {return nmax;};

        virtual double CercaZeri(double xmin ,
                                    double xmax ,
                                    const FunzioneBase& f,
                                    int& bisezioni,
                                    double prec = 0.01,
                                    unsigned int nmax = 100) = 0;

    protected:
        double ma, mb; // estremi intervallo
        double mprec; // precisione
        unsigned int nmax; // numero max di iterazioni permesse

};

class Bisezione : public Solutore {
    public:

        Bisezione(){;};
        Bisezione(double prec) {mprec = prec;};

        virtual double CercaZeri(double xmin, double xmax,
                                    const FunzioneBase& f,
                                    int& bisezioni,
                                    double prec = 0.01, // valori di default
                                    unsigned int nmax = 100)  ;
};

double Bisezione::CercaZeri(double xmin, double xmax, const FunzioneBase& f, int& bisezioni, double prec, unsigned int nmax) {
    double a = xmin; // estremo inferiore
    double b = xmax; // estremo superiore

    double xmed;
    
    // Controlla che la funzione cambi di segno tra gli estremi per applicare Weierstrass
    if (sign(f.Eval(a)) * sign(f.Eval(b)) > 0) {
        cout << "Errore: Non e' detto che la funzione abbia zeri!" << endl;
        exit(2);
    }

    // Controlla se la funzione ha zeri agli estremi
    if (f.Eval(a) == 0) return a;
    if (f.Eval(b) == 0) return b;

    for (unsigned int i = 0; i < nmax; i++) {
        xmed = (a + b) / 2.;
        double fmed = f.Eval(xmed);
        bisezioni++;

        if (fmed == 0) {
            return xmed; // Trovato lo zero!
        } else if (sign(f.Eval(a)) == sign(fmed)) {
            a = xmed; // Sposta gli estremi
        } else {
            b = xmed; 
        }
    }

    // Returna una stima se non e' riuscito a trovare lo zero
    return xmed;
}

