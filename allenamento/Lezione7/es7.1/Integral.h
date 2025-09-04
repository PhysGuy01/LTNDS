#pragma once

#include "funzioni.h"
#include "FunzioneBase.h"

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