#include "funzioni.h"

int main(int argc, char** argv) {

    if (argc < 3) {
        cout << "Utilizzo programma: ./prog <n_data> <filename>" << endl;
        exit(99);
    }

    int nDat = atoi(argv[1]);
    string filename = argv[2];

    nDat = catchEOF(filename, nDat);
    cout << "ndat: " << nDat << endl;
    cout << "file: " << filename << endl;

    Vettore v(nDat);
    v = Read(nDat, filename);

    double media = CalcMedia(v);

    cout << "media: " << media << endl;

    return 0;
}