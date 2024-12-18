#include "IntegraleMC.h"
#include "FunzioneBase.h"

#include <fstream>
#include <string>

using namespace std;

void printIntegral(int nPunti, FunzioneBase& f) {
    fstream file;
    file.open("datiN" + to_string(nPunti) + ".dat", ios::app);

    for (int i = 0; i < nPunti; i++) {
        IntegratoreMedia integ(i);
        double valInteg = integ.Integra(f, 0, M_PI/2, 500);
        
        file << valInteg << endl;

        //sumSigma += valInteg;
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