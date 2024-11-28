#include "TApplication.h"
#include "TCanvas.h"
#include "TH1F.h"
#include "TAxis.h"

#include <iostream>

#include "RandomGen.h" 

int main() {

  TApplication app("app",0,0);

  RandomGen myGen(1);

  int nmax = 10000;

  TH1F unif("Uniforme","Uniforme",70,4,11) ;

  for ( int k = 0 ; k < nmax ; k++ ) {

    unif.Fill( myGen.Unif(5,10)  ) ;  

    

  }

  TCanvas can2("Uniforme","Uniforme") ;
  can2.cd();
  unif.GetXaxis()->SetTitle("x [AU]");
  unif.GetYaxis()->SetTitle("N");
  unif.Draw();

  app.Run();

}