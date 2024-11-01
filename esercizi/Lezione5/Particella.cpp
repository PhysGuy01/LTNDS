#include "Particella.h"
#include <iostream>
using namespace std;

Particella::Particella(double massa, double carica) {
    m_massa = massa;
    m_carica = carica;
}

double Particella::getMassa() const {
    return m_massa;
}

double Particella::getCarica() const {
    return m_carica;
}

void Particella::Print() const {
    cout << "Massa: " << m_massa << endl <<
            "Carica: " << m_carica << endl;
}

Elettrone::Elettrone() : Particella(9.1093826E-31,-1.60217653E-19) {}

void Elettrone::Print() const {
    cout << "Elettrone: " << endl << 
            "\tMassa: " << m_massa << endl <<
            "\tCarica: " << m_carica << endl;
}