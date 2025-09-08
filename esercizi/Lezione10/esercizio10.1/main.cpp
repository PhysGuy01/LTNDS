#include "TApplication.h"
#include "TCanvas.h"
#include "TH1F.h"
#include "TGraph.h"
#include "TAxis.h"

#include <iostream>
#include <cmath>
#include <string>

#include "RandomGen.h" 

using namespace std;

int main(int argc, char** argv) {
    
    if (argc != 2) {
        cout << "Utilizzo: " << argv[0] << " <n_somme>" << endl;
        return -1;
    }

    TApplication app("app",0,0);

    RandomGen myGen(1);
    myGen.SetA(1664525);
    myGen.SetC(1013904223);
    myGen.SetM(pow(2,31));


    // Grafici

    TCanvas *c1 = new TCanvas("Teorema del limite centrale", "Teorema del limite centrale");
    c1->Divide(3,4); 

    int n_sums = atoi(argv[1]);; 

    TH1F* sommeDistr[11];
    TGraph grafStdDev;

    for (int j = 0; j <= 11; j++) { 
        string title = "Somme di " + to_string(j) + " elementi";

        sommeDistr[j] = new TH1F(title.c_str(), title.c_str(), 100, 0, j + 1);

        for (int i = 0; i < n_sums; i++) {
            double sum = 0;
            for (int k = 0; k <= j; k++) {
                double val = myGen.Rand();
                sum += val;
            }
            sommeDistr[j]->Fill(sum);
        }

        c1->cd(j+1); 
        sommeDistr[j]->GetXaxis()->SetTitle("Somma");
        sommeDistr[j]->GetYaxis()->SetTitle("N");
        sommeDistr[j]->GetYaxis()->SetRangeUser(0, n_sums*0.05);
        sommeDistr[j]->Draw();

        if (j != 0) {
            double stdDev = pow(sommeDistr[j]->GetRMS(),2);
            grafStdDev.SetPoint(j - 1, j, stdDev);
        }
    }

    c1->cd(12);
    grafStdDev.SetMarkerStyle(20);
    grafStdDev.SetTitle("Varianza per numero di elementi sommati");
    grafStdDev.GetXaxis()->SetTitle("N");
    grafStdDev.GetYaxis()->SetTitle("#sigma^{2}");
    grafStdDev.Draw("ALP");
    gPad->SetGridx();
    gPad->SetGridy();


    c1->Update();
    c1->SetWindowSize(2000,2500);
    c1->SaveAs("grafici.png");

    app.Run();

    return 0;
}