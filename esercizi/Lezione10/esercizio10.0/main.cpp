#include "TApplication.h"
#include "TCanvas.h"
#include "TH1F.h"
#include "TAxis.h"

#include <iostream>
#include <cmath>

#include "RandomGen.h" 

int main() {

    TApplication app("app",0,0);

    RandomGen myGen(1);
    myGen.SetA(1664525);
    myGen.SetC(1013904223);
    myGen.SetM(pow(2,31));

    int nmax = 10000;

    TH1F unif("Uniforme","Uniforme",70,4,11);
    TH1F exp("Esponenziale","Esponenziale",70,0,5);
    TH1F gau("Gaussiana","Gaussiana",70,0,20);
    TH1F gauAR("Gaussiana AR","Gaussiana AR",70,0,20);

    for ( int k = 0 ; k < nmax ; k++ ) {
        unif.Fill(myGen.Unif(5,10));  
        exp.Fill(myGen.Exp(1));
        gau.Fill(myGen.Gaus(10, 2));
        gauAR.Fill(myGen.GausAR(10, 2, 0, 20, 100));
    }

    TCanvas *c1 = new TCanvas("Generatori di numeri casuali", "Generatori di numeri casuali");
    c1->Divide(1,4); // 1 column 4 rows
    c1->cd(1);
    unif.GetXaxis()->SetTitle("x [AU]");
    unif.GetYaxis()->SetTitle("N");
    unif.Draw();

    c1->cd(2);
    exp.GetXaxis()->SetTitle("x [AU]");
    exp.GetYaxis()->SetTitle("N");
    exp.Draw();

    c1->cd(3);
    gau.GetXaxis()->SetTitle("x [AU]");
    gau.GetYaxis()->SetTitle("N");
    gau.Draw();
    
    c1->cd(4);
    gauAR.GetXaxis()->SetTitle("x [AU]");
    gauAR.GetYaxis()->SetTitle("N");
    gauAR.Draw();
    
    c1->SetWindowSize(1000,1000);
    c1->SaveAs("grafici.png");

    app.Run();

}