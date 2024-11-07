#include "Integral.h"
#include "FunzioneBase.h"

#include <cmath>
#include <iostream>
#include <iomanip>

using namespace std;

int main(int argc, char** argv) {
        
    if (argc != 2) {
        cout << "Utilizzo: ./" << argv[0] << "<prec>" << endl;
        exit(1);  
    }   

    double prec = atof(argv[1]);


    xsinx f;

    Trapezi integ(0., M_PI/2.);

    double I = integ.Integra(prec, f);

    cout << "Integrale di f(x) = xsinx in [0, pi/2]: "<< setprecision(-log10(prec)) << I << endl;


    // TODO: costruire grafico con ROOT

    return 0;

}