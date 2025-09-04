#pragma once

#include "funzioni.h"
#include "FunzioneBase.h"

using namespace std;

int sign(double x) { return ((x > 0) ? 1 : -1); }

class Solutore {
    public:
        Solutore() {m_prec = 1e-3;};
        Solutore(double prec) {m_prec = prec;};

        virtual double CercaZeri(double xmin, double xmax, FunzioneBase& f, double prec = 0.001, int nmax = 100) = 0;

        void setPrecision(double prec) {m_prec = prec;}
        double getPrecision() const {return m_prec;}

        // TODO: implementa metodi di accesso a altri valori protetti

        double getXmin() const { return m_xmin; }
        double getXmax() const { return m_xmax; }

        void setXmin(double x) { m_xmin = x; }
        void setXmax(double x) { m_xmax = x; }

        void setNmax(int nMax) { m_nmax = nMax; }
        int getNmax() const { return m_nmax; }

    protected:
        double m_prec;
        double m_xmin, m_xmax;
        int m_nmax;
};

class Bisezione : public Solutore {
    public:
        Bisezione() {};
        Bisezione(double prec) {m_prec = prec;}

        ~Bisezione() {;};

        virtual double CercaZeri(double xmin, double xmax, 
                                    FunzioneBase& f, double prec = 0.001, int nmax = 100) override {

            double a = xmin;
            double b = xmax;
            double xmed;

            if (a < b) {
                double tmp = a;
                a = b;
                b = tmp;
            }

            if (f.Eval(a) * f.Eval(b) > 0) {
                cout << "La funzione potrebbe non avere zeri in questo intervallo." << endl;
                exit(1);
            }

            if (f.Eval(a) == 0) {return a;}
            if (f.Eval(b) == 0) {return b;}
            
            for (int i = 0; i < nmax; i++) {
                xmed = (b + a) / 2;
                if (f.Eval(xmed) == 0) {
                    return xmed;
                } else if (sign(f.Eval(xmed)) == sign(f.Eval(a))) {
                    a = xmed;
                } else {
                    b = xmed;
                }
            }
            return xmed;
        }
};
