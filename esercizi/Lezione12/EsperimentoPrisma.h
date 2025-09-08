#pragma once

#include "RandomGen.h"

class EsperimentoPrisma {

    public :

    EsperimentoPrisma( unsigned int seed );
    ~EsperimentoPrisma() {;} ;

    void Esegui() ;
    void Analizza() ;

    double getAmis() { return m_A_misurato ; } ;
    double getBmis() {return m_B_misurato;};

    double getN1mis() {return m_n1_misurato;};
    double getN2mis() {return m_n2_misurato;};

    double getDm1mis() {return m_dm1_misurato;};
    double getDm2mis() {return m_dm2_misurato;};

    double getTh0mis() {return m_th0_misurato;};
    double getTh1mis() {return m_th1_misurato;};
    double getTh2mis() {return m_th2_misurato;};


    private:

    RandomGen myGen;

    // parametri dell'apparato sperimentale
    double m_lambda1, m_lambda2, m_alpha, m_sigmat;

    // valori delle quantita' misurabili :
    // input    : valori assunti come ipotesi nella simulazione
    // misurato : valore dopo la simulazione di misura 

    double m_A_input, m_A_misurato;
    double m_B_input, m_B_misurato;
    double m_n1_input, m_n1_misurato;
    double m_n2_input, m_n2_misurato;
    double m_dm1_input, m_dm1_misurato;
    double m_dm2_input, m_dm2_misurato;
    double m_th0_input, m_th0_misurato;
    double m_th1_input, m_th1_misurato;
    double m_th2_input, m_th2_misurato;

};


EsperimentoPrisma::EsperimentoPrisma( unsigned int seed ) :
    myGen( seed ),
    m_lambda1(579.1E-9),
    m_lambda2(404.7E-9),
    m_alpha(60.*M_PI/180.),
    m_sigmat(0.3E-3),
    m_A_input(2.7),
    m_B_input(60000E-18)
{
    myGen.SetA(1664525);
    myGen.SetC(1013904223);
    myGen.SetM(pow(2,31));
    
    // calcolo degli indici di rifrazione attesi
    m_n1_input = sqrt( m_A_input + m_B_input / (m_lambda1*m_lambda1) ) ;
    m_n2_input = sqrt( m_A_input + m_B_input / (m_lambda2*m_lambda2) ) ;

    // theta0 e' arbitrario, scelgo M_PI/2.
    m_th0_input = M_PI/2. ;

    // determino theta1 e theta2 
    m_dm1_input = 2.*asin( m_n1_input * sin (0.5 * m_alpha) ) - m_alpha ;
    m_th1_input = m_th0_input + m_dm1_input ;
    m_dm2_input = 2.*asin( m_n2_input * sin (0.5 * m_alpha) ) - m_alpha ;
    m_th2_input = m_th0_input + m_dm2_input ;

}



void EsperimentoPrisma::Esegui() {
    m_th0_misurato = myGen.Gaus(m_th0_input, m_sigmat);
    m_th1_misurato = myGen.Gaus(m_th1_input, m_sigmat);
    m_th2_misurato = myGen.Gaus(m_th2_input, m_sigmat);
}

void EsperimentoPrisma::Analizza() {
    m_dm1_misurato = m_th1_misurato - m_th0_misurato;
    m_dm2_misurato = m_th2_misurato - m_th0_misurato;

    m_n1_misurato = sin((m_dm1_misurato + m_alpha)/2)/sin(m_alpha/2);
    m_n2_misurato = sin((m_dm2_misurato + m_alpha)/2)/sin(m_alpha/2);

    m_A_misurato = (pow(m_lambda2,2)*pow(m_n2_misurato,2) - pow(m_lambda1,2)*pow(m_n1_misurato,2)) / (pow(m_lambda2,2) - pow(m_lambda1,2));
    m_B_misurato = (pow(m_n2_misurato,2) - pow(m_n1_misurato,2)) / (1/pow(m_lambda2,2) - 1/pow(m_lambda1,2));

}