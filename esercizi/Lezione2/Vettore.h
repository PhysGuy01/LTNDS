#pragma once

#include <iostream>

using namespace std;

class Vettore {
    public:
        Vettore();
        Vettore(int N);


        Vettore(const Vettore& V) {
            m_N = V.GetN();
            m_v = new double[m_N];
            for (int i=0; i<m_N; i++) m_v[i]=V.GetComponent(i);
        }

        Vettore& operator=(const Vettore&);
        double& operator[](int i);

        // distruttore
        ~Vettore();

        int GetN() const {return m_N;}
        void SetComponent(int, double);
        double GetComponent(int) const; // Accede alla componente i-esima

        // metodi interni

        void Scambia(int primo, int sec) const;

    private:

        int m_N;          // dimensione del vettore
        double* m_v;      // vettore di dati 

};

