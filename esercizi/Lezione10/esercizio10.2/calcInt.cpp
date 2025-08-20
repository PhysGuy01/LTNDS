#include "IntegraleMC.h"
#include "FunzioneBase.h"

#include <fstream>
#include <string>

using namespace std;

void printIntegral(int nPunti, FunzioneBase& f) {
    fstream file;
    file.open("datiN" + to_string(nPunti) + ".dat", ios::app);
    cout << "ok" << endl;

    for (int i = 0; i < 10000; i++) {
        IntegratoreMedia integ(i);
        double valInteg = integ.Integra(f, 0, M_PI/2, nPunti);
        
        file << valInteg << endl;
    }
}


int main() {

    xsinx f;

    double sumSigma = 0;

    printIntegral(500, f);
    printIntegral(1000, f);
    printIntegral(5000, f);
    printIntegral(10000, f);
    printIntegral(50000, f);
    printIntegral(100000, f);
    

    return 0;
}