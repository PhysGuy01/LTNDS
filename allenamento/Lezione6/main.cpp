#include "funzioni.h"

int main(int argc, char** argv) {
    if (argc < 4) {
        cerr << "Utilizzo ./esercizio6 <xmin> <xmax> <prec>" << endl;
        return -1;
    }

    double xmin = stod(argv[1]);
    double xmax = stod(argv[2]);
    double prec = stod(argv[3]);

    Parabola parabola(3, 5, -2);

    Bisezione bis(1e-3);

    int cifre = -log10(prec);

    cout << fixed;
    cout << setprecision(cifre) << "x0 = " << bis.CercaZeri(xmin, xmax, parabola, prec) << endl;


    return 0;
}