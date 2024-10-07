#pragma once

#include <iostream>

using namespace std;

class Vettore {
    public:
        Vettore();
        Vettore(int N);
        Vettore(const Vettore& );

        // Ridefinisce gli operatori = e [] per i vettori
        Vettore& operator=(const Vettore&);
        double& operator[](int i);

        // Distruttore
        ~Vettore();

        int GetN() const {return m_N;}
        void SetComponent(int i, double d);
        double GetComponent(int i) const; 

        const void Scambia(int primo, int secondo);

    private:
        int m_N;    // Dimensione vettore
        double* m_v;    // Array di double
};

