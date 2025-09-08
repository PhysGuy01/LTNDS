#include "IntegraleMC.h"
#include "FunzioneBase.h"

#include <fstream>
#include <string>
#include <chrono>

using namespace std::chrono;

void printIntegral(int nPunti, FunzioneBase& f) {
    fstream file;
    string fileTitle = "datiN" + to_string(nPunti) + ".dat";
    file.open(fileTitle, ios::app);

    auto start = high_resolution_clock::now();
    for (int i = 0; i < 10000; i++) {
        IntegratoreMedia integ(i);
        double valInteg = integ.Integra(f, 0, M_PI/2, nPunti);
        
        file << valInteg << endl;
    }
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);

    cout << "Scritto " << fileTitle << " in " << duration.count() / 1000. << "s"<< endl;
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