#pragma once

#include <cmath>

using namespace std;

class RandomGen {

    public:
        RandomGen() {m_seed = 1; m_a = 1664525; m_c = 1013904223; m_m = pow(2,31);}
        RandomGen(unsigned int seed) {m_seed = seed; m_a = 1664525; m_c = 1013904223; m_m = pow(2,31);};

        void SetA(unsigned int a) {m_a = a;}
        void SetC(unsigned int c) {m_c = c;}
        void SetM(unsigned int m) {m_m = m;}

        void SetSeed(double seed) {m_seed = seed;}

        double Rand();                                   // distribuzione uniforme tra 0 e 1
        double Unif(double xmin, double xmax);           // distribuzione uniforme tra xmin e xmax
        double Exp(double lambda);                       // distribuzione esponenziale con costante lambda
        double Gaus(double mean, double sigma);          // distribuzione gaussiana (Box-Muller)
        double GausAR(double mean, double sigma);        // distribuzione gaussiana (Accept-Reject)

        int Generatore() {
            m_seed = m_seed * m_a + m_c;
            return m_seed;
        }
    private:

        unsigned int m_a, m_c, m_m;
        unsigned int m_seed;

};

double RandomGen::Rand() {
    int ni = m_seed; 
    for (int i = 0; i < 1000; i++) 
        ni = RandomGen::Generatore() % m_m;
    
    return static_cast<double>(ni) / m_m;
}

double RandomGen::Unif(double xmin, double xmax) {
    return (xmax - xmin) * Rand() + xmin;
}

double RandomGen::Exp(double lambda) {
    return -(1/lambda) * log(1 - Rand());
}

double RandomGen::Gaus(double mean, double sigma) {
    double s=Rand();
    double t=Rand();
    double x=sqrt(-2.*log(1.-s))*cos(2.*M_PI*t);
    return mean+x*sigma; 
}
