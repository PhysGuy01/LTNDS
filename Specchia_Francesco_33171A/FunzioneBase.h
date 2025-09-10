#pragma once
#include <cmath>

class FunzioneBase {
    public:
        virtual double Eval(double x) const = 0; 
};

// Equazione trigonometricha del tipo f(x) = exp(-0.3 * x)*cos(x) 
class Armonica : public FunzioneBase {
    public:
        virtual double Eval(double x) const override {return (exp(-0.3 * x)*cos(x));};
};