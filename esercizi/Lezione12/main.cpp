#include "TApplication.h"
#include "TCanvas.h"
#include "TH1F.h"
#include "TH2F.h"
#include "TAxis.h"

#include <iostream>
#include <cmath>

#include "RandomGen.h" 
#include "EsperimentoPrisma.h"

using namespace std;


int main() {
    TApplication app("app",0,0);

    TH1F distrTh0("Distribuzione &theta 0","Distribuzione &theta 0",70,1,2);
    TH1F distrTh1("Distribuzione &theta 1","Distribuzione &theta 1",70,2,3);
    TH1F distrTh2("Distribuzione &theta 2","Distribuzione &theta 2",70,2,3);
    distrTh0.StatOverflows( kTRUE );
    TH1F distrDm1("Distribuzione &delta m1","Distribuzione &delta m1",70,0.5,1.5);
    TH1F distrDm2("Distribuzione &delta m2","Distribuzione &delta m2",70,-20,20);
    TH2F distrRhoDm("Distribuzione &rho m2","Distribuzione &rho m2",70,0.9767,0.9805,70,1.084,1.088);

    TH1F distrN1("Distribuzione n1","Distribuzione n1",70,1.5,2);
    TH1F distrN2("Distribuzione n2","Distribuzione n2",70,1.5,2);
    TH2F distrRhoN("Distribuzione &rho n","Distribuzione &rho n",70,1.6958,1.6978,70,1.75,1.752);
        distrRhoN.StatOverflows( kTRUE );


    TH1F distrA("Distribuzione A","Distribuzione A",70,2,3);
    TH1F distrB("Distribuzione B","Distribuzione B",70,50000E-18,70000E-18);
    TH2F distrRhoAB("Distribuzione &rho A,B","Distribuzione &rho A,B",70,2.6,2.8,70,-0.2,0.2);

    for (int i = 0; i < 10000; i++) {
        EsperimentoPrisma esp(i);
        esp.Esegui();
        esp.Analizza();
        distrTh0.Fill(esp.getTh0mis());
        distrTh1.Fill(esp.getTh1mis());
        distrTh2.Fill(esp.getTh2mis());

        distrDm1.Fill(esp.getDm1mis());
        distrDm2.Fill(esp.getDm2mis());
        distrRhoDm.Fill(esp.getDm1mis(), esp.getDm2mis());

        distrN1.Fill(esp.getN1mis());
        distrN2.Fill(esp.getN2mis());
        distrRhoN.Fill(esp.getN1mis(), esp.getN2mis());

        distrA.Fill(esp.getAmis());
        distrB.Fill(esp.getBmis());
        distrRhoAB.Fill(esp.getAmis(), esp.getBmis());
    }


    TCanvas *c1 = new TCanvas();
    c1->Divide(3,4); 

    c1->cd(1);
    distrTh0.GetXaxis()->SetTitle("[rad]"); /// TODO: cambia unita di misura non tutti son [rad]
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

    c1->cd(7);
    distrN1.GetXaxis()->SetTitle("[rad]");
    distrN1.GetYaxis()->SetTitle("N");
    distrN1.Draw();

    c1->cd(8);
    distrN2.GetXaxis()->SetTitle("[rad]");
    distrN2.GetYaxis()->SetTitle("N");
    distrN2.Draw();

    c1->cd(9);
    distrRhoN.GetXaxis()->SetTitle("[rad]");
    distrRhoN.GetYaxis()->SetTitle("N");
    distrRhoN.Draw();

    c1->cd(10);
    distrA.GetXaxis()->SetTitle("[rad]");
    distrA.GetYaxis()->SetTitle("N");
    distrA.Draw();

    c1->cd(11);
    distrB.GetXaxis()->SetTitle("[rad]");
    distrB.GetYaxis()->SetTitle("N");
    distrB.Draw();

    c1->cd(12);
    distrRhoAB.GetXaxis()->SetTitle("[rad]");
    distrRhoAB.GetYaxis()->SetTitle("N");
    distrRhoAB.Draw();


    app.Run();

    return 0;
}