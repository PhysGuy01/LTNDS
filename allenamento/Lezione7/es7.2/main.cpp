#include "funzioni.h"

int main(int argc, char** argv) {
    if (argc < 2) {
        cout << "Uso: ./esercizio7.2 <precisione>" << endl;
        return 1;
    }
    double prec = stod(argv[1]);

    xSinx f;
    Trapezi T(0, M_PI / 2);

    cout << fixed;
    cout << setprecision(-log10(prec)) << "Integrale di xsinx: " << T.IntegraErrore(f, prec) << endl;




    return 0;
}