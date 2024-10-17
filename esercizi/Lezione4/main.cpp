#include "funzioni.h"

int main() {

    TApplication app("app",0,0);
    TGraphErrors trend;


    int index{0};

    for (int i = 1941; i < 2024; i++) {
        string nome_file = "temps/" + to_string(i) + ".txt";
        
        fstream f;
        f.open(nome_file, ios::in);

        // Raccolta dati
        vector<double> v = Read<double>(nome_file);

        // Analisi dati
        double media = CalcMedia<double>(v);
        double devStd = CalcDevStd<double>(v);

        stringstream sout;
        sout << "Anno " << i << ": Delta medio = " << media << " +/- " << devStd << endl;
        print(sout, "output.txt");

        fstream media_dat;
        fstream err_dat;
        media_dat.open("medie.dat", ios::app);
        err_dat.open("errori.dat", ios::app);

        media_dat << media << endl;
        err_dat << devStd << endl;

        f.close(); 

        // Rappresentazione
        trend.SetPoint(index, i, media);
        trend.SetPointError(index , 0 , devStd);

        index++;

    }

    TCanvas canva("Temperatura","Temperatura");
    canva.cd();
    canva.SetGridx();
    canva.SetGridy();
    canva.SetWindowSize(1200, 700);

    trend.SetMarkerStyle(20);
    trend.SetTitle("Andamento temperatura anno per anno");
    trend.GetXaxis()->SetTitle("Anno");
    trend.GetYaxis()->SetTitle("#Delta (#circ C)");
    trend.Draw("apl3");
    trend.Draw("ALP");

    canva.SaveAs("trend.png");

    app.Run();

    return 0;
}