#pragma once

#include "funzioni.h"

class Particella {
    protected: 
        double m_mass, m_charge;
    
    public:

        Particella() {m_mass = 0; m_charge = 0;}
        Particella(double mass, double charge) { m_mass = mass; m_charge = charge; }

        double getMass() const { return m_mass; }
        double getCharge() const { return m_charge; }

        void setMass(double mass) { m_mass = mass; }
        void setCharge(double charge) { m_charge = charge; }

        void print() const {
            cout << "Particella: " << endl <<
                    "   massa = " << m_mass << endl << 
                    "   carica = " << m_charge << endl;
        }

        ~Particella() {;}
};


class Elettrone : public Particella {
    public:
        
        Elettrone() : Particella(9.1093837139E-31, 1.60217646E-19) {};
        ~Elettrone() {;};

        void print() const {
            cout << "Elettrone: " << endl <<
                    "   massa = " << m_mass << endl << 
                    "   carica = " << m_charge << endl;
        }

};