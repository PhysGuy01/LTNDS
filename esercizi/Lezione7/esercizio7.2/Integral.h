#pragma once

#include <iostream>
#include <cmath>
#include <iomanip>

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


// Classe per metodo dei trapezi

class Trapezi : public Integral {
    public:
        Trapezi (double a, double b) : Integral (a,b) {;};

        virtual double Integra(unsigned int nstep, const FunzioneBase &);

        double Integra(double prec , const FunzioneBase &);  

        double Int_passo(const FunzioneBase&, double N);
};

double Trapezi::Integra(unsigned int nstep, const FunzioneBase& f) {
    cout << "Metodo non implementato, utilizzare Integra(double, const FunzioneBase&)." << endl;
    exit(3);
}

// Approssima l'integrale della funzione f con passo N attraverso il metodo dei trapezi
double Trapezi::Int_passo(const FunzioneBase& f, double N) {
    double xi, K, h;
    double Sum = 0.;

    h = (m_b - m_a) / N;
    for (int i = 0; i <= N; i++) {
        xi = m_a + i * h;
        
        if (i == 0 || i == N) {
            K = 1. / 2.;
        } else {
            K = 1.;
        }

        Sum += K * f.Eval(xi);
    }
    return Sum * h;
}

double Trapezi::Integra(double prec, const FunzioneBase &f) {    
    double err = pow(m_b - m_a, 2);
    double In, I2n; // Integrale a passo N e a passo 2N

    int N = 1;
    while (err >= prec) {
        In = Int_passo(f, N);
        I2n = Int_passo(f, 2*N);

        err = (4./3) * fabs(I2n - In);
        N++;
    }

    m_integral = m_sign * I2n;

    return m_integral;
}