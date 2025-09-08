#pragma once

#include <cmath>

class RandomGen {

    public:

        RandomGen(unsigned int seed){m_seed = seed;};

        void SetA(unsigned int a) {m_a = a;}
        void SetC(unsigned int c) {m_c = c;}
        void SetM(unsigned int m) {m_m = m;}

        double Rand( );                                  // distribuzione uniforme tra 0 e 1
        double Unif(double xmin, double xmax);           // distribuzione uniforme tra xmin e xmax
        double Exp(double lambda);                       // distribuzione esponenziale con costante lambda
        double Gaus(double mean, double sigma);          // distribuzione gaussiana (Box-Muller)
        double GausAR(double mean, double sigma, double xmin, double xmax, double ymax);  // distribuzione gaussiana (Accept-Reject)

        double Generatore() {
            m_seed = m_a * m_seed + m_c;
            return static_cast<double>(m_seed % m_m);
        };

    private:

        unsigned int m_a, m_c, m_m;
        unsigned int m_seed;

};

double RandomGen::Unif(double xmin, double xmax) {
    double xi = Generatore();
    double ri = xi / m_m;
    double t = xmin + (xmax - xmin) * ri;
    return t;
}

double RandomGen::Rand(){
    return Unif(0,1);
}

double RandomGen::Exp(double lambda) {
    return -(1/lambda)*log(1-Rand());
}

double RandomGen::Gaus(double mean, double sigma) {
    double s=Rand();
    double t=Rand();
    double x=sqrt(-2.*log(1.-s))*cos(2.*M_PI*t);
    return mean+x*sigma; 
}

double RandomGen::GausAR(double mean, double sigma, double xmin, double xmax, double ymax) {
    double s = Rand();
    double t = Rand();
    double x = xmin + (xmax - xmin) * s;
    double y = ymax * t;
    double fx = exp(-.5 * pow((x - mean)/sigma, 2)/(sigma * sqrt(2 * M_PI)));
    
     if (y <= fx) 
        return x;
     else 
        return GausAR(mean, sigma, xmin, xmax, ymax);
    return 0;
}