#pragma once
#include "VectorOperations.h" 
#include <cmath> 

using namespace std;


class FunzioneVettorialeBase {
    public:
        virtual vector<double> Eval(double t, const vector<double> & x) const = 0;
};


class OscillatoreArmonico : public FunzioneVettorialeBase {
    public:
        OscillatoreArmonico(double omega0) {m_omega0 = omega0;};

        virtual vector<double> Eval(double t, const vector<double> & x) const {

            vector<double> y;
            y.push_back(x[1]); // v
            y.push_back(- m_omega0 * m_omega0 * x[0]); // F/m

            return y;

        };

    private:
        double m_omega0;  
};


class OscillatoreArmonicoForzato : public FunzioneVettorialeBase {
    public:
        OscillatoreArmonicoForzato(double omega0, double omega, double alfa) {m_omega0 = omega0; m_omega = omega; m_alfa = alfa;};

        virtual vector<double> Eval(double t, const vector<double> & x) const {

            vector<double> y;
            y.push_back(x[1]); // v
            y.push_back(- m_omega0 * m_omega0 * x[0] - m_alfa * x[1] + sin(m_omega * t)); // F/m

            return y;

        };

    private:
        double m_omega0, m_omega, m_alfa;  
};


class Pendolo : public FunzioneVettorialeBase {
    public:
        Pendolo(double l) {m_l = l; m_omega = g / l;}; 

        virtual vector<double> Eval(double t, const vector<double> & x) const {
            vector<double>  y;
            y.push_back(x[1]); // velocita' iniziale
            y.push_back(-m_omega*sin(x[0])); // d theta / dt

            return y;
        }

    private:
        double g = 9.806;
        double m_l;
        double m_omega;
};


// --------------------------
//      Eq Differenziali
// --------------------------

class EquazioneDifferenzialeBase {
    public:
        virtual vector<double> Passo(double t, 
                                    const vector<double>& x, 
                                    double h, 
                                    const FunzioneVettorialeBase &f) const = 0;
};


// metodo di Eulero
class Eulero : public EquazioneDifferenzialeBase {

    public:

        virtual vector<double> Passo(double t, 
                                    const vector<double> & x, 
                                    double h, 
                                    const FunzioneVettorialeBase &f) const override {
            return x + (f.Eval(t, x)) * h;
        };

};


// metodo di Runge-Kutta
class RungeKutta : public EquazioneDifferenzialeBase {

 public:

  virtual vector<double> Passo(double t, 
                               const vector<double> & x, 
                               double h, 
                               const FunzioneVettorialeBase &f) const override {
    vector<double> x1 = x;

    vector<double> k1 = f.Eval(t, x1);
    vector<double> k2 = f.Eval(t + h / 2., x1 + k1 * h * (1 / 2.));
    vector<double> k3 = f.Eval(t + h / 2., x1 + k2 * h * (1 / 2.));
    vector<double> k4 = f.Eval(t + h, (k3 * h) + x1);


    return x + (k1 + (k2 * 2.) + (k3 * 2.) + k4) * h / 6.;
  };

};

