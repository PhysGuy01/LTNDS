#include "TCanvas.h"
#include "TApplication.h"
#include "TH1F.h"
#include "TF1.h"
#include "TRandom.h"

#include <iostream>
#include <fstream>
 
using namespace std;
 
int main (int argc, char**argv)
{
   
  TApplication app("App",0,0);

  // Definizione di un istogramma monodimensionale da riempire con float

  TH1F *h1 = new TH1F("h1","Istogramma 1D",100,-5.,5.);
  h1->StatOverflows( kTRUE ); // utilizza underflow e overflow per calcoli statistici
  
  TRandom gen;
  for ( int k = 0 ; k < 10000 ; k++ ) h1->Fill( gen.Gaus(0,1) ) ;

  // creazione del canvas

  TCanvas *c1 = new TCanvas("c1","Istogramma 1D",600,400);
  
  // disegno.

  h1->Draw();
  h1->GetXaxis()->SetTitle("Titolo sull'asse X");
  h1->GetYaxis()->SetTitle("Titolo sull'asse Y");
  h1->Draw();
  
  // Puoi prendere le informazioni che ti interessano
  
  cout << "La media dell'istrogramma h1 vale -->>  " << h1->GetMean() << endl;
  cout << "L'RMS dell'istogramma h1 vale     -->>  " << h1->GetRMS() << endl;
  
  // Puoi fittare l'istogramma con una funzione gaussiana (e' gia' predefinita in ROOT)

  h1->Fit("gaus");
  
  // e recuperare i risultati
  
  TF1 *FitFun = h1->GetFunction("gaus");
  cout << "Ecco i parametri del fit " << endl;
  cout << "Media della gaussiana --->>> " << FitFun->GetParameter(1) << endl;
  cout << "Sigma della gaussiana --->>> " << FitFun->GetParameter(2) << endl;
  cout << "Chi2 del fit          --->>> " << FitFun->GetChisquare() << endl;
  
  c1->Print("HistoFit.pdf");
  
  app.Run();
  return 0;
  
}

