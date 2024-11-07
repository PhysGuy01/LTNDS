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

        void checkInterval( double a, double b ) {
            m_a = min(a,b);
            m_b = max(a,b);
            if ( a > b ) m_sign = -1;
            else m_sign = 1;
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


// Classe per metodo dei trapezi

class Trapezi : public Integral {
    public:
        Trapezi (double a, double b) : Integral (a,b) {;};

        virtual double Integra(unsigned int nstep, const FunzioneBase &);

        double Integra(double prec , const FunzioneBase &);  
};

double Trapezi::Integra(unsigned int nstep, const FunzioneBase& f) {
    cout << "Metodo non implementato, utilizzare Integra(double,const FunzioneBase&)." << endl;
    exit(3);
}

double Trapezi::Integra(double prec, const FunzioneBase &f) {    
    int i = 1;
    double xi;
    double err = pow(m_b - m_a, 2);
    double K;

    while (err >= prec) {
        m_h = (m_b - m_a) / i;
        err = i * pow(m_h, 2);
        
        cout << setprecision(10) << xi << endl;

        xi = m_a + i * m_h;

        if (i == 0 || err == prec) {
            K = 1. / 2.;
        } else {
            K = 1.;
        } 
        
        m_sum +=  K * f.Eval(xi);
        cout << i << " " << m_h << endl;
        i++; 
    }

    m_integral = m_sign * m_sum * m_h;

    return m_integral;

}