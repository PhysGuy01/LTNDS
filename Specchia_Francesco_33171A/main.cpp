#include <iostream>
#include <cmath>
#include <string>
#include <vector>

#include "Integral.h"
#include "FunzioneBase.h"
#include "RandomGen.h"
#include "IntegraleMC.h"
#include "Solutore.h"

using namespace std;

double errIntegDistr(const FunzioneBase& f, double inf, double sup);

int main() {

    Armonica f;

    Bisezione bis;

    int n_cifre = -log10(1e-02);
    

    // Ricerca degli zeri 

    double x11 = 4, x12 = 5;
    double x21 = 7, x22 = 9; 

    int bisezioni = 0;

    double zero1 = bis.CercaZeri(x11, x12, f, bisezioni);
    double zero2 = bis.CercaZeri(x21, x22, f, bisezioni);

    cout << fixed << setprecision(n_cifre) << "Zero della funzione nell'intervallo [a,b] = ["<< x11 << ", " << x12 << "]: x = " << zero1 << " trovato in " << bisezioni << " bisezioni" << endl <<
            "Zero della funzione nell'intervallo [a,b] = ["<< x21 << ", " << x22 << "]: x = " << zero2  << " trovato in " << bisezioni << " bisezioni" << endl << endl; 
    

    // Calcolo integrale con metodo dei trapezi

    Trapezi trap(zero1, zero2);
    double trapezi10Punti = trap.Int_passo(f, 10);
    double errTrap = 4*fabs(trap.Int_passo(f, 20) - trapezi10Punti) /3;
    cout << setprecision(4) << "Integrale della funzione con metodo trapezi in ["<< zero1 << ", " << zero2 << "] con 10 punti: " << trapezi10Punti << endl;
    cout << "L'errore stimato e': " << errTrap << endl << endl;  


    // Calcolo integrale con metodo della media

    IntegratoreMedia intMedia(1);
    cout << "Integrale della funzione con metodo della media in ["<< zero1 << ", " << zero2 << "] con 10 punti: " << intMedia.Integra(f, zero1, zero2, 10) << endl;
    cout << "L'errore stimato e': " << intMedia.GetErrore() << endl << endl;  
    
    intMedia.calcNpunti(f, zero1, zero2, errTrap);
    cout << "Per avere lo stessa errore del metodo dei trapezi con 10 punti ("<< errTrap << "), bisogna compiere: " << intMedia.GetN() << " estrazioni" << endl;

    
    // Stima errore integrale da gaussiane sugli estremi
    cout << "La deviazione standard dell'integrale tra gli estremi di integrazione con distribuzione gaussiana di sigma 1e-2 e': " << errIntegDistr(f, zero1, zero2) << endl;

    return 0;
}



// Stima l'errore del calcolo sull'integrale attraverso una distribuzione degli integrali calcolati in un intervallo cui estremi sono ricavati da una gaussiana
double errIntegDistr(const FunzioneBase& f, double inf, double sup) {
    RandomGen rg(1);

    vector<double> vecInteg;
    double media = 0;
    int niteraz = 10;
    for (int i = 0; i < niteraz; i++) {
        double inf_mis = rg.Gaus(inf, 1);
        double sup_mis = rg.Gaus(sup, 1);

        Trapezi trap(inf_mis, sup_mis);
        double integ = trap.Int_passo(f, 10);

        media += integ;
        vecInteg.push_back(integ);
    }

    media /= niteraz;
    double sigma = 0;
    
    for (double integ : vecInteg) 
        sigma += pow(integ - media, 2);

    sigma /= niteraz - 1;

    return sqrt(sigma);
}