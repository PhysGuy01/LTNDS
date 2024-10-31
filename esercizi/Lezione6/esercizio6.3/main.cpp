#include "Solutore.h"
#include "FunzioneBase.h"
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {

    Trigonometrica T();

    Bisezione bis;

    int n_cifre = -log10(1e-06);
    
    for (int n = 0; n < 20; n++) {
        double zero = bis.CercaZeri(n * M_PI, n * M_PI + M_PI/2, T);
        cout << "Zero della funzione in ("<< n << "*Pi, " << n << "*Pi + Pi / 2): x = " << setprecision(n_cifre)<< zero << endl; 
    }




    return 0;
}
