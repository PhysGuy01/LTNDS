// scrivi prgoramma che esegua 1000 volte l'esperimento e tracci istogrammi

#include <iostream>
#include "EsperimentoPrisma.h"
#include "RandomGen.h"

#include "TApplication.h"
#include "TCanvas.h"
#include "TH1F.h"
#include "TH2F.h"
#include "TAxis.h"

using namespace std;

int main() {

    TApplication app("app", 0, 0);
    TCanvas* c = new TCanvas("c", "Esperimento Prisma");
    c->Divide(3,1);     // vedi se farle tutte (colxrow)


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


    EsperimentoPrisma prisma(1);

    for (int i = 0; i < 1000; i++) {
        prisma.Esegui();
        prisma.Analizza();

        distrTh0.Fill(prisma.GetTh0mis());
        distrTh1.Fill(prisma.GetTh1mis());
        distrTh2.Fill(prisma.GetTh2mis());

        distrDm1.Fill(prisma.GetDm1mis());
        distrDm2.Fill(prisma.GetDm2mis());
        distrRhoDm.Fill(prisma.GetDm1mis(), prisma.GetDm2mis());

        distrN1.Fill(prisma.GetN1mis());
        distrN2.Fill(prisma.GetN2mis());
        distrRhoN.Fill(prisma.GetN1mis(), prisma.GetN2mis());
        
        distrA.Fill(prisma.GetAmis());
        distrB.Fill(prisma.GetBmis());
        distrRhoAB.Fill(prisma.GetAmis(), prisma.GetBmis());
    }

    c->cd(1);
    distrTh0.GetXaxis()->SetTitle("[rad]"); 
    distrTh0.GetYaxis()->SetTitle("N");
    distrTh0.Draw();

    c->cd(2);
    distrTh1.GetXaxis()->SetTitle("[rad]");
    distrTh1.GetYaxis()->SetTitle("N");
    distrTh1.Draw();

    c->cd(3);
    distrTh2.GetXaxis()->SetTitle("[rad]");
    distrTh2.GetYaxis()->SetTitle("N");
    distrTh2.Draw();
    
    c->Update();
    app.Run();

    return 0;
}