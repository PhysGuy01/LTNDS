#include "RandomGen.h"
#include <cmath>

using namespace std;

class EsperimentoPrisma {
    private:
        double A_v, A_mis, B_v, B_mis;
        double alfa_v, alfa_mis;
        double theta0_v, theta0_mis;
        double theta1_v, theta1_mis;
        double theta2_v, theta2_mis;
        double dm1_v, dm1_mis;
        double dm2_v, dm2_mis;
        double n1_v, n1_mis;
        double n2_v, n2_mis;


        double lambda1, lambda2;

        double sigma_theta;

        RandomGen rg; 
    
    public:

        double GetAv() const {return A_v;}
        double GetBv() const {return B_v;}
        double GetTh0v() const {return theta0_v;}
        double GetTh1v() const {return theta1_v;}
        double GetTh2v() const {return theta2_v;}
        double GetN1v() const {return n1_v;}
        double GetN2v() const {return n2_v;}
        double GetDm1v() const {return dm1_v;}
        double GetDm2v() const {return dm2_v;}
        double GetAlfav() const {return alfa_v;}

        double GetAmis() const {return A_mis;}
        double GetBmis() const {return B_mis;}
        double GetTh0mis() const {return theta0_mis;}
        double GetTh1mis() const {return theta1_mis;}
        double GetTh2mis() const {return theta2_mis;}
        double GetN1mis() const {return n1_mis;}
        double GetN2mis() const {return n2_mis;}
        double GetDm1mis() const {return dm1_mis;}
        double GetDm2mis() const {return dm2_mis;}
        double GetAlfamis() const {return alfa_mis;}


        EsperimentoPrisma(int seed): rg(seed), A_v(2.7), B_v(60000E-18), alfa_v(60.*M_PI/180.), lambda1(579.1E-9), lambda2(404.7E-9), sigma_theta(0.3E-3) {
            theta0_v = M_PI / 2;

            n1_v = sqrt( A_v + B_v / (lambda1 * lambda1) ) ;
            n2_v = sqrt( A_v + B_v / (lambda2 * lambda2) ) ;

            dm1_v = 2.*asin( n1_v * sin (0.5 * alfa_v) ) - alfa_v ;
            theta1_v = theta0_v + dm1_v ;
            dm2_v = 2.*asin( n2_v * sin (0.5 * alfa_v) ) - alfa_v ;
            theta2_v = theta0_v + dm2_v ;
        }

        void Esegui() {
            theta0_mis = rg.Gaus(theta0_v, sigma_theta);
            theta1_mis = rg.Gaus(theta1_v, sigma_theta);
            theta2_mis = rg.Gaus(theta2_v, sigma_theta);
        }

        void Analizza() {
            A_mis = (pow(lambda2,2) * pow(n2_mis, 2)  -  pow(lambda1,2)*pow(n1_mis,2))/(pow(lambda2,2) - pow(lambda1,2));
            B_mis = (pow(n2_mis,2) - pow(n1_mis,2))/(1/pow(lambda2,2) - 1/pow(lambda1,2));
        }


};