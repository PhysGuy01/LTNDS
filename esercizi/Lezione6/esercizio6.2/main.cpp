#include "Solutore.h"
#include "FunzioneBase.h"
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <iomanip>

using namespace std;

int main(int argc, char** argv) {
    
    if (argc < 4) {
        cout << "Utilizzo: " << argv[0] << " <estremo_a> <estremo_b> <precisione>" << endl;
        exit(1);  
    }

    double a = atof(argv[1]);
    double b = atof(argv[2]);
    double prec = atof(argv[3]);
    
    Parabola f(3, 5, -2);

    Bisezione bis;
    
    int n_cifre = -log10(prec);
    double xzero = bis.CercaZeri(a, b, f, prec, 50);
    cout << "Zero della funzione nell'intervallo [" << a << ", " << b << "]: x = " << fixed << setprecision(n_cifre) << xzero << endl;

    return 0;
}
