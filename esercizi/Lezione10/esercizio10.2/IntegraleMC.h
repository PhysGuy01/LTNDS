#pragma once
#include "RandomGen.h"
#include "FunzioneBase.h"
#include <iostream>
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
        for (int i = 0; i < punti; i++) {
            
            sumf += f.Eval(m_gen.Unif(inf,sup));
        }

        return sumf * (sup - inf) / punti;

    };

};