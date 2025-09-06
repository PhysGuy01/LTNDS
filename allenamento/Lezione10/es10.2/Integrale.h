#pragma once

#include "FunzioneBase.h"
#include "RandomGen.h"

class IntegraleMC {

    public:

        IntegraleMC(unsigned int seed) : 
            m_gen(seed)
        {
            m_errore = 0;
            m_punti  = 0;
        }

        virtual double Integra( const FunzioneBase& f, double inf , double sup , unsigned int punti, double fmax = 0) = 0 ;

        double GetErrore() const {return m_errore;}
        unsigned int GetN() const {return m_punti;}

    protected:

        RandomGen m_gen;
        double m_errore;
        unsigned int m_punti;

};

class IntegratoreMedia : public IntegraleMC {

    public:

        IntegratoreMedia(unsigned int seed) : IntegraleMC(seed) { ; };

        virtual double Integra ( const FunzioneBase& f, double inf , double sup , unsigned int punti, double fmax = 0 ) override {
            double sum = 0;
            for (int i = 0; i < punti; i++) {
                double xi = m_gen.Unif(inf, sup);
                sum += f.Eval(xi);
            }

            return sum * (sup - inf)/punti;

        };

};