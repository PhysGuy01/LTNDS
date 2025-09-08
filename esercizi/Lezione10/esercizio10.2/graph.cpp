#include "TApplication.h"
#include "TCanvas.h"
#include "TH1F.h"
#include "TAxis.h"
#include "TGraph.h"


#include <fstream>
#include <string>
#include <iostream>

using namespace std;


void loadHist(TH1F &dat, string filename) {
    fstream file;
    file.open(filename, ios::in);

    string riga;
    while(getline(file, riga)) {
        double integ;
        file >> integ;
        dat.Fill(integ);
    }
}

int main() {

    TApplication app("app",0,0);

    TH1F dat500("N = 500","N = 500",100,0.9,1.1);
    TH1F dat1000("N = 1000","N = 1000",100,0.9,1.1);
    TH1F dat5000("N = 5000","N = 5000",100,0.9,1.1);
    TH1F dat10000("N = 10000","N = 10000",100,0.9,1.1);
    TH1F dat50000("N = 50000","N = 50000",100,0.9,1.1);
    TH1F dat100000("N = 1000000","N = 1000000",100,0.9,1.1);

    loadHist(dat500, "datiN500.dat");
    loadHist(dat1000, "datiN1000.dat");
    loadHist(dat5000, "datiN5000.dat");
    loadHist(dat10000, "datiN10000.dat");
    loadHist(dat50000, "datiN50000.dat");
    loadHist(dat100000, "datiN100000.dat");

    TCanvas *c1 = new TCanvas();
    c1->Divide(3,2); 
    c1->SetTitle("Distribuzioni integrali");

    c1 -> cd(1);
    dat500.GetXaxis()->SetTitle("Integrali");
    dat500.GetYaxis()->SetTitle("N");
    dat500.Draw();

    c1 -> cd(2);
    dat1000.GetXaxis()->SetTitle("Integrali");
    dat1000.GetYaxis()->SetTitle("N");
    dat1000.Draw();

    c1 -> cd(3);
    dat5000.GetXaxis()->SetTitle("Integrali");
    dat5000.GetYaxis()->SetTitle("N");
    dat5000.Draw();

    c1 -> cd(4);
    dat10000.GetXaxis()->SetTitle("Integrali");
    dat10000.GetYaxis()->SetTitle("N");
    dat10000.Draw();

    c1 -> cd(5);
    dat50000.GetXaxis()->SetTitle("Integrali");
    dat50000.GetYaxis()->SetTitle("N");
    dat50000.Draw();

    c1 -> cd(6);
    dat100000.GetXaxis()->SetTitle("Integrali");
    dat100000.GetYaxis()->SetTitle("N");
    dat100000.Draw();

    
    c1->SetWindowSize(2000,2500);
    c1->SaveAs("distribuzioni.png");

    c1->Update();


    // Grafico dell'errore

    TCanvas *c2 = new TCanvas();
    c2->SetTitle("Errore");
    c2->cd();
    
    TGraph err;
    err.SetPoint(0, 500, dat500.GetRMS());
    err.SetPoint(1, 1000, dat1000.GetRMS());
    err.SetPoint(2, 5000, dat5000.GetRMS());
    err.SetPoint(3, 10000, dat10000.GetRMS());
    err.SetPoint(4, 50000, dat50000.GetRMS());
    err.SetPoint(5, 100000, dat100000.GetRMS());

    err.GetYaxis()->SetTitle("Errore");
    err.GetXaxis()->SetTitle("Numero di punti");
    err.SetMarkerStyle(20);
    err.Draw("APL");

    gPad->SetLogy();
    gPad->SetLogx();
    gPad->SetGridy(1);
    gPad->SetGridx(1);

    c2->Update();
    c2->SaveAs("errore.png");

    app.Run();

    return 0;
}