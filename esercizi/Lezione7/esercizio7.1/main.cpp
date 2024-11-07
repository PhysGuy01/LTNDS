#include "Integral.h"
#include "FunzioneBase.h"

#include <cmath>
#include <iostream>

using namespace std;

int main(int argc, char** argv) {
        
    if (argc != 2) {
        cout << "Utilizzo: ./" << argv[0] << "<nsteps>" << endl;
        exit(1);  
    }   

    double nsteps = atof(argv[1]);


    xsinx f;

    Simpson integ(0., M_PI/2.);

    double I = integ.Integra(nsteps, f);

    cout << "Integrale di f(x) = xsinx in [0, pi/2]: " << I << endl;


    // TODO: costruire grafico con ROOT

    return 0;

}