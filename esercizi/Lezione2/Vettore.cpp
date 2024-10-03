#include "Vettore.h"

Vettore::Vettore() {
    m_N = 0;
    m_v = NULL;
}

Vettore::Vettore(int N)  {
    if (N < 0) {
        cout << "Numero di elementi negativo!" << endl;
        exit(1);
    } else {
        m_N = N;
        m_v = new double[m_N];
        for (int i = 0; i < m_N; i++) 
            m_v = 0; // inizializzo gli elementi a zero
    }
}

Vettore::~Vettore() {
    delete[] m_v;
    m_v = nullptr;
}

void Vettore::SetComponent(int i, double d) {
    if (i < m_N) {
        m_v[i] = d; 
    } else {
        cout << "Errore nell'indicizzazione in SetComponent" << endl;
        exit(2);
    }
}

double Vettore::GetComponent(int i) const {
    if ( i < m_N ) {
        cout << "in vettore.cpp " << m_N;
        cout << " " << m_v[0] << endl;
        return m_v[i];
    } else {
        cout << "Errore: indice " << i << ", dimensione " << m_N << endl;
        exit(2);
    }
}

void Vettore::Scambia(int primo, int sec) const {
    double tmp = m_v[primo];
    m_v[primo] = m_v[sec];
    m_v[sec] = tmp;
}

Vettore& Vettore::operator=(const Vettore& V) {
    m_N = V.GetN();
    m_v = new double[m_N];

    for (int i = 0; i < m_N; i++) {
        m_v[i] = V.GetComponent(i);
    }
    return *this;
}

double& Vettore::operator[](int i) {
    if ( i < m_N ) {
        return m_v[i];
    } else {
        cout << "Errore: indice " << i << ", dimensione " << m_N << endl;
        exit(2);
    }
}