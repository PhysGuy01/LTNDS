#pragma once
#include "RandomGen.h"
#include "FunzioneBase.h"
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;


class IntegraleMC {

    public:

    IntegraleMC(unsigned int seed) : 
        m_gen(seed)
    {
        m_errore = 0;
        m_punti  = 0;
    }

    virtual double Integra( const FunzioneBase& f, double inf , double sup , unsigned int punti ) = 0 ;

    double GetErrore() const {return m_errore;}
    unsigned int GetN() const {return m_punti;}

    protected:

        RandomGen m_gen;
        double m_errore;
        unsigned int m_punti;

};

class IntegratoreMedia : public IntegraleMC {

public:

    IntegratoreMedia(unsigned int seed) : IntegraleMC(seed) { 
        m_gen.SetA(1664525);
        m_gen.SetC(1013904223);
        m_gen.SetM(pow(2,31)); 
    };


    virtual double Integra (const FunzioneBase& f, double inf , double sup , unsigned int punti) {
    
        double sumf = 0; // somma di valori delle funzioni 
        vector<double> vecFi; // Array di valori di f(xi) per calcolare l'errore

        for (int i = 0; i < punti; i++) {
            
            double fi = f.Eval(m_gen.Unif(inf,sup));
            sumf += fi;
            vecFi.push_back(fi);

        }

        double varianza = 0;
        for (double fi : vecFi) 
            varianza += pow(fi - sumf/punti, 2);
        
        varianza /= punti - 1;
        
        // L'errore sull'integrale e' ora:
        m_errore = sqrt(varianza) * (sup - inf) / sqrt(punti);

        return sumf * (sup - inf) / punti;

    };


    // calcola il numero di estraziioni necessarie per avere una precisione data sull'integrale
    void calcNpunti (const FunzioneBase& f, double inf , double sup, double prec) {
        int n = 3;
        do {
            Integra(f, inf, sup, n);
            n++;
        } while (m_errore >= prec);

        m_punti = n;
    }

};