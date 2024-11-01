#pragma once
#include <cmath>

class FunzioneBase {
    public:
        virtual double Eval(double x) const = 0;
};


class Parabola : public FunzioneBase {
    public:
        Parabola() {ma = 0.; mb = 0.; mc = 1.;};
        Parabola(double a, double b, double c) {ma = a; mb = b; mc = c;};

        virtual double Eval(double x) const override {return ma * pow(x,2) + mb * x + mc;};

        void setA(double a) {ma = a;};
        void setB(double b) {mb = b;};
        void setC(double c) {mc = c;};

        double getA() {return  ma;};
        double getB() {return  mb;};
        double getC() {return  mc;};
    
    private:
        double ma, mb, mc;
};