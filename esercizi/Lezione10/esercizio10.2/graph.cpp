#include "TApplication.h"
#include "TCanvas.h"
#include "TH1F.h"
#include "TAxis.h"

#include <fstream>
#include <string>
#include <iostream>

using namespace std;

int main(int argc, char** argv) {
        
    if (argc != 2) {
        cout << "Utilizzo: ./" << argv[0] << "<file_dati>" << endl;
        exit(1);  
    }   

    string filename = argv[1];

    cout << filename;
    fstream file;
    file.open(filename, ios::in);

    // TODO: Implementare un modo per verificare il numero di elementi nel file (spoiler: saranno 10k)
    int nDat = 10000;

    TApplication app("app",0,0);


    // per distribuire bene i grafici nel range... boh non sio in realta
    TH1F gaus("Distribuzione Integrali","Distribuzione Integrali",100,0.5,1.5);

    string linea;
    // while(getline(file, linea)) {
    for (int i = 0; i < 10000; i++) {    
        double integ;
        file >> integ;
        // cout << integ;
        gaus.Fill(integ);
    }


    TCanvas *c1 = new TCanvas();
    c1 -> cd();
    gaus.GetXaxis()->SetTitle("Integrali");
    gaus.GetYaxis()->SetTitle("N");
    gaus.Draw();

    c1->SetWindowSize(2000,2500);
    c1->SaveAs("grafici.png");

    app.Run();



    return 0;
}