#pragma once

#include <iostream>
#include <cmath>

#include "FunzioneBase.h"

using namespace std;                                                        


class Integral {

    public:
        Integral (double a, double b) {
            checkInterval (a,b);
            m_nstep = 0;
            m_h = 0 ;
            m_sum = 0 ;
            m_integral = 0 ;
        } ;

        virtual double Integra(unsigned int nstep, const FunzioneBase &) = 0 ;

        double getIntegral() {return m_integral;};

    protected:

        void checkInterval(double a, double b) {
            m_a = min(a,b);
            m_b = max(a,b);
            m_sign = (a > b) ? -1 : 1;
        }

        unsigned int m_nstep;
        double m_a, m_b;
        double m_sum, m_integral, m_h;
        int m_sign;

};


// Classe per metodo di Simpson

class Simpson : public Integral {
    public:    
        Simpson (double a, double b) : Integral(a,b) {;};

        virtual double Integra(unsigned int nstep, const FunzioneBase &);
};

double Simpson::Integra(unsigned int nstep, const FunzioneBase& f) {
    if (nstep % 2 != 0) {
        cout << "Il numero di passi deve essere pari!" << endl;
        exit(1);
    }

    m_h = (m_b - m_a) / nstep;
    double K;   // coefficiente moltiplicatore della funzione
    double xi;

    for (int i = 0; i <= nstep; i++) {
        xi = m_a + i * m_h;
        
        if (i == 0 || i == nstep) {
            K = 1. / 3.;
        } else if (i % 2 == 0) {
            K = 4. / 3.;
        } else {
            K = 2. / 3.;
        }

        m_sum += K * f.Eval(xi);
    }

    m_integral = m_sign * m_sum * m_h;

    return m_integral;
}