
// ============================================================================================
  
// Questo codice di test mostra un approccio alternativo all'uso di ereditarieta'+polimorfismo
// per la ricerca degli zeri di una funzione con il metodo della bisezione. L'idea e' di scrivere 
// un metodo che possa accettare in input un puntatore a funzione, un funtore o una lambda

// ============================================================================================ 

#include <math.h>
#include <iostream>

using namespace std;

double sign( double x ) { return (x==0.?0.:(x>0?1.:-1)); };

// Funzione che accetta una std::function

double BisezioneStdFun(double xmin, 
		       double xmax, 
		       std::function<double (double)> f, 
		       double prec=0.001)
{  
  unsigned int niterations = 0;
  unsigned int nmax = 100;
  double a = 0 ;
  double b = 0 ;
  if ( xmin<xmax ) { 
    a = xmin;
    b = xmax;
  } else { 
    a = xmax;
    b = xmin;
  }
  double fa = f(a);
  double fb = f(b);
  while ( fabs(b-a) > prec ) {
    double c = 0.5*(b+a);
    double fc = f(c);
    if ( niterations > nmax ) break;
    niterations++ ;    
    if ( sign(fa)*sign(fc) <= 0 ) { b=c; fb=fc;}
    else if ( sign(fb)*sign(fc)<=0 ) { a=c; fa=fc;}
    else return 0.;
  }
  return 0.5*(b+a);
}

// Funzione template 

template<typename Func>  double BisezioneTemplate(double xmin, 
						  double xmax, 
						  Func f, 
						  double prec=0.001) 
{  
  unsigned int niterations = 0;
  unsigned int nmax = 100;
  double a = 0 ;
  double b = 0 ;
  if ( xmin<xmax ) { 
    a = xmin;
    b = xmax;
  } else { 
    a = xmax;
    b = xmin;
  }
  double fa = f(a);
  double fb = f(b);
  while ( fabs(b-a) > prec ) {
    double c = 0.5*(b+a);
    double fc = f(c);
    if ( niterations > nmax ) break;
    niterations++ ;    
    if ( sign(fa)*sign(fc) <= 0 ) { b=c; fb=fc;}
    else if ( sign(fb)*sign(fc)<=0 ) { a=c; fa=fc;}
    else return 0.;
  }
  return 0.5*(b+a);

}

// Funzione che accetta un puntatore a funzione

double BisezioneFunPointer(double xmin, 
			   double xmax, 
			   double (*f) (double), 
			   double prec=0.001) 
{
  unsigned int niterations = 0;
  unsigned int nmax = 100;
  double a = 0 ;
  double b = 0 ;
  if ( xmin<xmax ) { 
    a = xmin;
    b = xmax;
  } else { 
    a = xmax;
    b = xmin;
  }
  double fa = f(a);
  double fb = f(b);
  while ( fabs(b-a) > prec ) {
    double c = 0.5*(b+a);
    double fc = f(c);
    if ( niterations > nmax ) break;
    niterations++ ;    
    if ( sign(fa)*sign(fc) <= 0 ) { b=c; fb=fc;}
    else if ( sign(fb)*sign(fc)<=0 ) { a=c; fa=fc;}
    else return 0.;
  }
  return 0.5*(b+a);
}

// Puntatore a funzione parabola

double ParaFunction( double x ) {return 3*x*x - 5*x + 2 ;};

// Funtore che rappresenta la funzione parabola

class ParaFunctor {
  
public :
  
  ParaFunctor() { m_para1 = 1. ; m_para2 = 1.; m_para3 = 1. ; } ;
  ParaFunctor( double para1, double para2, double para3 ) { 
    m_para1 = para1 ; 
    m_para2 = para2 ;
    m_para3 = para3 ;
  } ;

  void SetParams(  double para1, double para2, double para3 ) {  
    m_para1 = para1 ; 
    m_para2 = para2 ;
    m_para3 = para3 ;
  } ;
  
  double operator() ( double x ) {return m_para1 * x*x + m_para2 * x + m_para3 ;} ;   
  
private :
  
  double m_para1, m_para2 , m_para3 ;

} ;

// lambda function ( no capture )

auto lambda = [](double x)->double { return 3*x*x - 5 * x + 2 ; };

// lambda function ( with parameter capture )

auto lambdaCapture [&](double x)->double {return para1 * x*x + para2 * x + para3 ;};

int main() {

  // BisezioneFunPointer only works with function pointers

  std::cout << BisezioneFunPointer(0.8,1.2,ParaFunction) << std::endl ;

  // also with lambdas if there's no capture
  
  auto lambda = [](double x)->double { return 3*x*x - 5 * x + 2 ; };
  std:: cout << BisezioneFunPointer(0.9,1.1, lambda ) << endl;

  std:: cout << BisezioneFunPointer(0.9,1.1, [](double x)->double {  return 3*x*x - 5 * x + 2 ; } ) << endl;

  // The other two methods work with function pointers, functors and lambdas
 
  ParaFunctor myParaFunctor ( 3., -5., 2. );
  std::cout << BisezioneStdFun(0.9,1.1,myParaFunctor ) << std::endl ;

  std:: cout << BisezioneTemplate(0.9,1.1, ParaFunction ) << endl;
  std:: cout << BisezioneTemplate(0.9,1.1, myParaFunctor ) << endl;
  std:: cout << BisezioneTemplate(0.9,1.1, [&](double x)->double { return  3*x*x - 5 * x + 2 ; } ) << endl;

  std:: cout << BisezioneStdFun(0.9,1.1, ParaFunction ) << endl;
  std:: cout << BisezioneStdFun(0.9,1.1, myParaFunctor ) << endl;
  std:: cout << BisezioneStdFun(0.9,1.1, [](double x)->double {return  3*x*x - 5 * x + 2 ; }  ) << endl;

  // check here, a lambda with capture 
  
  double para1 = 3;
  double para2 = -5;
  double para3 = 2;

  std:: cout << BisezioneTemplate(0.9,1.1, [&](double x)->double {return para1 * x*x + para2 * x + para3 ;} ) << endl;
  std:: cout << BisezioneStdFun(0.9,1.1, [&](double x)->double {return para1 * x*x + para2 * x + para3 ;} ) << endl;
  
}
