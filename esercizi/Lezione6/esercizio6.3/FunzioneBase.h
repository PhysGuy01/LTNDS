#pragma once
#include <cmath>

class FunzioneBase {
    public:
        virtual double Eval(double x) const = 0; 
};

// Equazione trigonometricha del tipo sin(x) - x * cos(x) = 0 
class Trigonometrica : public FunzioneBase {
    public:
        Trigonometrica() {;};
        virtual double Eval(double x) {return (sin(x) - x * cos(x));};
};