#pragma once
#include <cmath>

class FunzioneBase {
    public:
        virtual double Eval(double x) const = 0; 
};

// Equazione trigonometricha del tipo f(x) = sin(x) - x * cos(x) 
class Trigonometrica : public FunzioneBase {
    public:
        virtual double Eval(double x) const override {return (sin(x) - x * cos(x));};
};