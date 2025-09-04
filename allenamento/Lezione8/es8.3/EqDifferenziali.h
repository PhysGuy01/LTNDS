#pragma once

#include "VectorOperations.h"


class FunzioneVettoriale {
    public:
        FunzioneVettoriale() {;}

        virtual vector<double> Eval(double t,const vector<double>& x) const = 0;        
};

class OscillatoreArmonico : public FunzioneVettoriale {
    public:
        OscillatoreArmonico() {m_omega = 1;}
        OscillatoreArmonico(double omega) {m_omega = omega;}



        virtual vector<double> Eval(double t, const vector<double>& x) const override {

            vector<double> y;
            y.push_back(x[1]);
            y.push_back(-m_omega * m_omega * x[0]);

            return y;
        }

    protected:
        double m_omega;
};

class Pendolo : public FunzioneVettoriale {
    public: 
        Pendolo() {m_L = 1.;}
        Pendolo(double lunghezza) {m_L = lunghezza; m_omega = sqrt(m_L / m_g); };

        virtual vector<double> Eval(double t, const vector<double>& x) const override {
            vector<double> y;
            y.push_back(x[1]);
            y.push_back(-m_omega*sin(x[0]));
            return y;
        }
    
    protected: 
        double m_g = 9.81;
        double m_L;
        double m_omega;
};
class EquazioneDifferenzialeBase {
    public:
        virtual vector<double> Passo(double t, 
                                    const vector<double>& x, 
                                    double h, 
                                    const FunzioneVettoriale &f) const =0;
};


// metodo di Eulero
class Eulero : public EquazioneDifferenzialeBase {

    public:

        virtual vector<double> Passo(double t, 
                                    const vector<double> & x, 
                                    double h, 
                                    const FunzioneVettoriale &f) const override {
            return x + (f.Eval(t, x)) * h;
        };

};


// metodo di Runge-Kutta
class RungeKutta : public EquazioneDifferenzialeBase {

 public:

  virtual vector<double> Passo(double t, 
                               const vector<double> & x, 
                               double h, 
                               const FunzioneVettoriale &f) const override {
    vector<double> x1 = x;

    vector<double> k1 = f.Eval(t, x1);
    vector<double> k2 = f.Eval(t + h / 2., x1 + k1 * h * (1 / 2.));
    vector<double> k3 = f.Eval(t + h / 2., x1 + k2 * h * (1 / 2.));
    vector<double> k4 = f.Eval(t + h, (k3 * h) + x1);


    return x + (k1 + (k2 * 2.) + (k3 * 2.) + k4) * h / 6.;
  };

};

