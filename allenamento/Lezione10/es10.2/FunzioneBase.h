#pragma once

#include <cmath>

using namespace std;

class FunzioneBase {
    public:

        virtual double Eval(double x) const =0;
        virtual ~FunzioneBase(){;};
};


class Parabola : public FunzioneBase {
    public:
        Parabola() {m_a = 0; m_b = 0; m_c = 0;}
        Parabola(double a, double b, double c) {m_a = a; m_b = b; m_c = c;}

        double getA() const { return m_a; }
        double getB() const { return m_b; }
        double getC() const { return m_c; }

        void setA(double a) { m_a = a; }
        void setB(double b) { m_b = b; }
        void setC(double c) { m_c = c; }

        virtual double Eval(double x) const override {
            return ((m_a * pow(x,2)) + (m_b * x) + m_c);
        }

        double getVertex() const { return (-getB() / (2 * getA())); }


        ~Parabola() {;};
    private:
        double m_a, m_b, m_c;
};

class TanX : public FunzioneBase {
    public:
        TanX() {;};

        virtual double Eval(double x) const override {
            return sin(x) - x * cos(x);
        }
};

class xSinx : public FunzioneBase {
    public:
        xSinx() {;}

        virtual double Eval(double x) const override {
            return x*sin(x);
        }
};

