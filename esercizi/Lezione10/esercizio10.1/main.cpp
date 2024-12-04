#include "TApplication.h"
#include "TCanvas.h"
#include "TH1F.h"
#include "TAxis.h"

#include <iostream>
#include <cmath>

#include "RandomGen.h" 

using namespace std;

int main(int argc, char** argv) {
    
    if (argc != 2) {
        cout << "Utilizzo: ./" << argv[0] << "<n_elementi>" << endl;
        exit(1);  
    }

    int n_elem = atoi(argv[1]);

    TApplication app("app",0,0);

    RandomGen myGen(1);
    myGen.SetA(1664525);
    myGen.SetC(1013904223);
    myGen.SetM(pow(2,31));

    TH1F distrVal("Distribuzione Valori","Distribuzione Valori",70,0,1);
    TH1F distrSomm("Distribuzione Somme","Distribuzione Somme",100 ,n_elem/2 - 50, n_elem/2 + 50); 

    int n_sums = n_elem;
    for (int i = 0; i < n_sums; i++) {
        double sum = 0;
        for (int k = 0; k < n_elem; k++) {
            double val = myGen.Rand();
            sum += val;
            distrVal.Fill(val);
        }
        distrSomm.Fill(sum);
    }



    TCanvas *c1 = new TCanvas();
    c1->Divide(2,1); 
    c1->cd(1);

    distrVal.GetXaxis()->SetTitle("x [AU]");
    distrVal.GetYaxis()->SetTitle("N");
    distrVal.Draw();


    c1->cd(2);

    distrSomm.GetXaxis()->SetTitle("Somma");
    distrSomm.GetYaxis()->SetTitle("N");
    distrSomm.Draw();


    c1->SetWindowSize(2000,2500);
    c1->SaveAs("grafici.png");

    app.Run();

}