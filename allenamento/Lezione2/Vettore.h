#pragma once

#include <iostream>

using namespace std;

class Vettore {

    public:
        // costruttore
        Vettore() {
            m_N = 0;
            m_v = NULL;
        };

        // costruttore con le dimensioni del vettore
        Vettore(unsigned int N) {
            m_N = N;
            m_v = new double[N];
            for (int i = 0; i < N; i++) m_v[i] = 0; // inizializza tutti gli elem a 0
        }

        ~Vettore(); // distruttore


        // Metodi di accesso ai dati
        int getN() const {return m_N;}; // Restituisce il numero di elementi, ma non può modificarlo (const)
        void setComponent(unsigned int, double); // Modifica la i-esima componente
        double getComponent(unsigned int) const; // Restituisce la i-esima componente, ma non può modificarla (const)

        // Riordina elementi del vettore in ordine crescente
        void sortVett(); 

        // Definisco operatore []
        double& operator[](int);

    private:
        unsigned int m_N;
        double* m_v;
};