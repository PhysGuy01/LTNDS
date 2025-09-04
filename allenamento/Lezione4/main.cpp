#include "funzioni.h"

int main(int argc, char** argv) {

    // cicla in ogni file dei dati di ogni anno
    // ogni 7 giorni prende una misura e alla fine dell'anno 
    // calcola media dev std su tutti i dati

    if (argc < 2) {
        cerr << "Utilizzo codice ./prog <anno_inizio (>=1941)> <anno di fine (<=2023)>" << endl;
        return 1;
    }

    int annoInizio = stoi(argv[1]);
    int annoFine = stoi(argv[2]);

    if (annoInizio > annoFine) {
        int tmp = annoInizio;
        annoInizio = annoFine;
        annoFine = tmp;
    }


    TApplication app("app", 0, 0);
    TGraphErrors trend;

    int index = 0;

    for (int i = annoInizio; i < annoFine; i++) {
        string filename = "TemperatureMilano/" + to_string(i) + ".txt";
        ifstream f(filename);

        vector<double> anno = loadData<double>(filename);

        double mean = calcMedia(anno);
        double devStd = calcDevStd(anno);
        cout << devStd << endl;
        trend.SetPoint(index, i, mean);
        trend.SetPointError(index, 0, devStd);

        index++;
    }

    TCanvas c("Temperature trend", "Temperature trend");

    c.cd();
    c.SetGridx();
    c.SetGridy();

    //trend.SetMarkerSize(1.0);
    //trend.SetMarkerStyle(20);
    //trend.SetFillColor(5);

    trend.GetXaxis()->SetTitle("Anno");
    trend.GetYaxis()->SetRangeUser(-10, 10);
    trend.GetYaxis()->SetTitle("#Delta(#circ C)");

    ///trend.Draw("ap13");
    trend.Draw();
    
    c.SaveAs("trend.jpg");
    app.Run();

    return 0;
}