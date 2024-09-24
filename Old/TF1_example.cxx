// Utilizzo della classe TF1 e TCanvas

#include "TCanvas.h"
#include "TF1.h"
#include "TApplication.h"
#include <iostream>
#include <cmath>

using namespace std;

#define EPS 1.e-10

double lorentzianPeak(double x[], double par[]){

  double Den = (x[0]-par[2])*(x[0]-par[2]) + par[1]*par[1]/4.;
  if ( Den < EPS ) Den = EPS;
  return ( par[0]*par[1]/(2.*M_PI) )/ Den;

}

int main (int argc, char**argv)
{
  
  TApplication app("App",0,0);

  // =========================================================================================
  // Definizione di una funzione f1
  // =========================================================================================
  
  TF1 *f1 = new TF1("f1","sin(x)/x",0.,10.);
  cout << "Plotting function -------" << endl;
  
  // Creo un oggetto della classe TCanvas: e' la finestra grafica
  // sulla quale metto il disegno
  
  TCanvas *c1 = new TCanvas("c1","funzione",600,400);  
  
  // Disegna la funzione sul canvas
  
  f1->Draw();                           
  
  cout << "Il valore di f1 in 1 vale       -->> " << f1->Eval(1.) << endl;          // Valutarla in un punto  
  cout << "La derivata di f1 in 1 vale     -->> " << f1->Derivative(1.) << endl;    // Valutarne la derivata in un punto  
  cout << "L'integrale di f1 in [0,1] vale -->> " << f1->Integral(0.,1.) << endl;   // Calcolare l'integrale definito

  // =========================================================================================
  // Definizione una funzione con parametri
  // =========================================================================================
  
  TF1 *f3 = new TF1("f3","[0]*x*sin([1]*x)",-3.,3.);
  TCanvas *c3 = new TCanvas("c3","funzione",600,400);
  f3->SetParameter(0,10.);     // Definire il parametro [0] a 10.
  f3->SetParameters(10.,5.);   // Definire [0] -> 10. e [1] a 5.
  f3->Draw();
  
  // =========================================================================================
  // Oppure...
  // =========================================================================================
  
  TF1 *lp = new TF1("lp",lorentzianPeak,-3.,3.,3);  // L'ultimo intero definisce il numero di parametri
  TCanvas *c4 = new TCanvas("c4","Lorentzian Peak",600,400);
  lp->SetParameters(1.,1.,0.);
  lp->Draw();

  app.Run();

  return 0;
}
