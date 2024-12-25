#include "TApplication.h"
#include "TCanvas.h"
#include "TH1F.h"
#include "TH2F.h"
#include "TAxis.h"
#include "TPaveStats.h"
#include "TLatex.h"
#include <TStyle.h>




#include <iostream>
#include <cmath>

#include "RandomGen.h" 
#include "EsperimentoPrisma.h"

using namespace std;


int main() {
    TApplication app("app",0,0);

    TH1F distrTh0("Distribuzione #theta_{0}","Distribuzione #theta_{0}",70,1.5697,1.572);
    TH1F distrTh1("Distribuzione #theta_{1}","Distribuzione #theta_{1}",70,2.5481,2.5507);
    TH1F distrTh2("Distribuzione #theta_{2}","Distribuzione #theta_{2}",70,2.655,2.588);
    distrTh0.StatOverflows( kTRUE );

    TH1F distrDm1("Distribuzione #delta_{m1}","Distribuzione #delta_{m1}",70,0.977,0.9801);
    TH1F distrDm2("Distribuzione #delta_{m2}","Distribuzione #delta_{m2}",70,1.0848,1.0872);
    TH2F distrRhoDm("Distribuzione #rho_{#delta_{m1},#delta_{m2}}","Distribuzione #rho_{#delta_{m1},#delta_{m2}}",70,0.9767,0.9805,70,1.084,1.088);

    TH1F distrN1("Distribuzione n_{1}","Distribuzione n_{1}",70,1.696,1.69742);
    TH1F distrN2("Distribuzione n_{2}","Distribuzione n_{2}",70,1.7505,1.75169);
    TH2F distrRhoN("Distribuzione #rho_{n}","Distribuzione #rho_{n}",70,1.6958,1.6978,70,1.75,1.752);
    distrRhoN.StatOverflows( kTRUE );


    TH1F distrA("Distribuzione A","Distribuzione A",70,2.6958,2.703879);
    TH1F distrB("Distribuzione B","Distribuzione B",70,58.8E-15,61.1E-15);
    TH2F distrRhoAB("Distribuzione #rho_{A,B}","Distribuzione #rho_{A,B}",70,2.695,2.706,100,58.8E-15,61.1E-15);

    // TODO: CALCOLA RHO!!
    double sumDm1mis = 0, sumDm2mis = 0, sumN1mis = 0, sumN2mis = 0, sumAmis = 0, sumBmis = 0, sumDm12mis = 0, sumN12mis = 0, sumABmis = 0;
    int nEntries = 10000;
    for (int i = 0; i < nEntries; i++) {
        EsperimentoPrisma esp(i);
        esp.Esegui();
        esp.Analizza();
        distrTh0.Fill(esp.getTh0mis());
        distrTh1.Fill(esp.getTh1mis());
        distrTh2.Fill(esp.getTh2mis());
        
        double Dm1mis = esp.getDm1mis();
        double Dm2mis = esp.getDm2mis();
        distrDm1.Fill(Dm1mis);
        distrDm2.Fill(Dm2mis);
        distrRhoDm.Fill(Dm1mis, Dm2mis);
        sumDm1mis += Dm1mis;
        sumDm2mis += Dm2mis;
        sumDm12mis += Dm1mis * Dm2mis;

        double N1Mis = esp.getN1mis();
        double N2Mis = esp.getN2mis();
        distrN1.Fill(N1Mis);
        distrN2.Fill(N2Mis);
        distrRhoN.Fill(N1Mis, N2Mis);
        sumN1mis += N1Mis;
        sumN2mis += N2Mis;
        sumN12mis += N1Mis * N2Mis;

        double Amis = esp.getAmis();
        double Bmis = esp.getBmis();
        distrA.Fill(Amis);
        distrB.Fill(Bmis);
        distrRhoAB.Fill(Amis, Bmis);
        sumAmis += Amis;
        sumBmis += Bmis;
        sumABmis += Amis * Bmis;
    }


    TCanvas *c1 = new TCanvas("c", "Esperimento Prisma", 10000, 10000);
    c1->Divide(3,4); 

    c1->cd(1);
    distrTh0.GetXaxis()->SetTitle("[rad]"); 
    distrTh0.GetYaxis()->SetTitle("N");
    distrTh0.Draw();

    c1->cd(2);
    distrTh1.GetXaxis()->SetTitle("[rad]");
    distrTh1.GetYaxis()->SetTitle("N");
    distrTh1.Draw();

    c1->cd(3);
    distrTh2.GetXaxis()->SetTitle("[rad]");
    distrTh2.GetYaxis()->SetTitle("N");
    distrTh2.Draw();


    c1->cd(4);
    distrDm1.GetXaxis()->SetTitle("[rad]");
    distrDm1.GetYaxis()->SetTitle("N");
    distrDm1.Draw();

    c1->cd(5);
    distrDm2.GetXaxis()->SetTitle("[rad]");
    distrDm2.GetYaxis()->SetTitle("N");
    distrDm2.Draw();

    c1->cd(6);
    distrRhoDm.GetXaxis()->SetTitle("[rad]");
    distrRhoDm.GetYaxis()->SetTitle("N");
    distrRhoDm.Draw();

    gStyle->SetOptStat();
    distrRhoDm.Draw();
    c1->Update();
    TPaveStats *stDm=(TPaveStats*)distrRhoDm.GetListOfFunctions()->FindObject("stats"); 

    string rhotxt = "#rho_{#delta_{m1},#delta_{m2}} = " + to_string(100 * ((sumDm12mis/nEntries - (sumDm1mis/nEntries) * (sumDm2mis/nEntries))/(distrRhoDm.GetStdDev(1)*distrRhoDm.GetStdDev(2)))) + "%";
    stDm->AddText(rhotxt.c_str());
    stDm->DrawClone();
    c1->Modified();

    c1->cd(7);
    distrN1.GetYaxis()->SetTitle("N");
    distrN1.Draw();

    c1->cd(8);
    distrN2.GetYaxis()->SetTitle("N");
    distrN2.Draw();

    c1->cd(9);
    distrRhoN.GetXaxis()->SetTitle("n(#lambda_{1})");
    distrRhoN.GetYaxis()->SetTitle("n(#lambda_{2})");
    distrRhoN.Draw();
    gStyle->SetOptStat();
    c1->Update();
    TPaveStats *stN=(TPaveStats*)distrRhoN.GetListOfFunctions()->FindObject("stats"); 

    rhotxt = "#rho_{n_{1},n_{2}} = " + to_string(100 * ((sumN12mis/nEntries - (sumN1mis/nEntries) * (sumN2mis/nEntries))/(distrRhoN.GetStdDev(1)*distrRhoN.GetStdDev(2)))) + "%";
    stN->AddText(rhotxt.c_str());
    stN->DrawClone();
    c1->Modified();


    c1->cd(10);
    distrA.GetYaxis()->SetTitle("N");
    distrA.Draw();

    c1->cd(11);
    distrB.GetXaxis()->SetTitle("[m^{2]}");
    distrB.GetYaxis()->SetTitle("N");
    distrB.Draw();

    c1->cd(12);
    distrRhoAB.GetXaxis()->SetTitle("A");
    distrRhoAB.GetYaxis()->SetTitle("B [m^{2}]");
    distrRhoAB.Draw();
    gStyle->SetOptStat();
    c1->Update();
    TPaveStats *stAB=(TPaveStats*)distrRhoAB.GetListOfFunctions()->FindObject("stats"); 

    rhotxt = "#rho_{n_{1},n_{2}} = " + to_string(100 * ((sumABmis/nEntries - (sumAmis/nEntries) * (sumBmis/nEntries))/(distrRhoAB.GetStdDev(1)*distrRhoAB.GetStdDev(2)))) + "%";
    stAB->AddText(rhotxt.c_str());
    stAB->DrawClone();
    c1->Modified();

    c1->Update(); 

    c1->SaveAs("grafici.png");

    app.Run();

    return 0;
}