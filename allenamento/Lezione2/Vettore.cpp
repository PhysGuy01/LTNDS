#include "Vettore.h"

// Distruttore
Vettore::~Vettore() {
    delete[] m_v;
}

// Modifica la i-esima componente
void Vettore::setComponent(unsigned int i, double d) {
    if (i < m_N) {
        m_v[i] = d;
    } else {
        cerr << "Errore nella scrittura della " << i << "-esima componente del vettore." << endl;
        exit(2);
    }
}

// Restituisce la i-esima componente se i < m_N
double Vettore::getComponent(unsigned int i) const {
    if (i < m_N) {
        return m_v[i];
    } else {
        cerr << "Errore nell'accesso alla " << i << "-esima componente del vettore." << endl;
        exit(2);
    }
} 

// Sorta vettore in ordine crescente
void Vettore::sortVett() {
    for (int i = 0; i < m_N; i++)
        for (int j = i + 1; j < m_N; j++)
            if (m_v[j] < m_v[i]) {
                double tmp = m_v[i];
                m_v[i] = m_v[j];
                m_v[j] = tmp;
            }
}


// Operatore []
double& Vettore::operator[](int i) {
    if (i < m_N) {
        return m_v[i];
    } else {
        cerr << "Errore nell'accesso alla componente " << i << ". Dimensione: " << m_N << endl;
        exit(3);
    }
}