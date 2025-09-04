#pragma once

#include "funzioni.h"
#include "FunzioneBase.h"

#include <iostream>
using namespace std;

class Integral {
    public:
        Integral() {;}
        Integral(double a, double b) {
            m_a = a;
            m_b = b;    
        }
        virtual double Integra(FunzioneBase& f, int nstep = 100) const = 0;
    
    protected:
        double m_a, m_b;
        double m_integral;

};

class Trapezi : public Integral {
    public:
        Trapezi() {;}
        Trapezi(double a, double b) : Integral(a,b) {;}
        
        virtual double Integra(FunzioneBase& f, int nstep = 10) const override {
            cout << "metodo non implementato, usare IntegraErrore()" << endl;
            exit(1);
            return -1; 
        }


        double IntegraErrore(FunzioneBase& f, double prec = 1e-3) {
            double err, In = 0, In1 = 0, h, Sn = 0, Sn1 = 0;
            // Errore calcolato tra due iterazioni successive
            // Prima iterazione: (f(a) + f(b)) * h / 2

            h = m_b - m_a;
            Sn = (f.Eval(m_a) + f.Eval(m_b)) / 2;
            In = Sn * h;

            int n = 1;
            while (true) {
                h /= 2;
                Sn1 = Sn;
                
                for (int i = 1; i <= 2 * n - 1; i+=2) {
                    double xi = m_a + i * h;
                    Sn1 += f.Eval(xi);
                }

                In1 = Sn1 * h;

                if ((4 * fabs(In1 - In) / 3) < prec) {
                    return In1;
                } 

                In = In1;
                Sn = Sn1;
                n *= 2;
            }

        }
};

class Simpson : public Integral {
    public:

        Simpson(double a, double b) {
            m_a = a; 
            m_b = b;
        }

        virtual double Integra(FunzioneBase& f, int nstep = 10) const override {
            if (nstep % 2 != 0) 
                nstep++;
            
            double h = (m_b - m_a) / nstep;

            double sum = 0;
            double xi;
            for (int i = 0; i < nstep; i++) {
                xi = m_a + i * h;
                if (i == 0) {
                    sum += f.Eval(xi) / 3;
                } else if (i % 2 != 0) {
                    sum += f.Eval(xi) * 4/3;
                } else {
                    sum += f.Eval(xi) * 2/3;
                }
            }

            return sum * h;
        }
};
