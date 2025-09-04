#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>

#include "FunzioneBase.h"
#include "Solutore.h"

using namespace std;

int main() {

    // Intervalli: (n*pi, n*pi + pi/2) n=1,...,20,...

    TanX T;
    Bisezione b(1e-6);
    int ncifre = -log10(1e-6);

    for (int n = 1; n < 21; n++) {
        cout << fixed;
        cout << setprecision(ncifre) << "n = " << n << " : x0 = " << b.CercaZeri(n * M_PI, n * M_PI + M_PI / 2, T, 1e-6) << endl;
    }


    return 0;
}