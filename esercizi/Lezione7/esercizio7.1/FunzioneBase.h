#pragma once
#include <cmath>

class FunzioneBase {
    public:
        virtual double Eval(double x) const = 0;
};

class xsinx : public FunzioneBase {
    public:
        xsinx() {;};

        virtual double Eval(double x) const override {return x * sin(x);}; 
};
