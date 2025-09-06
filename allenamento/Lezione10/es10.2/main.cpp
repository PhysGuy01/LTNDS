#include "RandomGen.h"
#include "Integrale.h"
#include "FunzioneBase.h"
#include <cmath>

#include "TApplication.h"
#include "TCanvas.h"
#include "TH1F.h"
#include "TAxis.h"
#include "TGraph.h"

using namespace std;

int main() {

    TApplication app("app", 0,0);

    TH1F histo("Histogram", "histo",100, 0,2);
    TCanvas c("xsinx", "xsinx");

    c.cd();

    xSinx f;
    IntegratoreMedia integ(10);
    for (int i = 0; i < 10000; i++) {
        histo.Fill(integ.Integra(f, 0, M_PI/2, 1000));
    }

    
    c.Update();
    histo.Draw();
    c.SaveAs("graficoGIUSTO1k.png");
    app.Run();

    return 0;
}