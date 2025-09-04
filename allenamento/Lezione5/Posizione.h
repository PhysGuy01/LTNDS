#pragma once

#include "funzioni.h"
#include <cmath>

using namespace std;

class Posizione {
    protected:
        double m_x, m_y, m_z;
        double m_R, m_phi, m_theta;

    public:

        // Costruttore di Default (x,y,z) = 0
        Posizione(){
            m_x=0; m_y=0; m_z=0;
            m_R=0; m_phi=0; m_theta=0;
        };

        // Costruttore che assegna un valore a ogni componente cartesiana
        Posizione(double x, double y, double z) {
            m_x = x; m_y = y; m_z = z;
            m_R = sqrt(pow(m_x, 2) + pow(m_y, 2) + pow(m_z, 2));
            m_phi = atan2(m_y, m_x);
            m_theta = acos(m_z/m_R);
        } 


        // Restituisce coord cartesiane
        double getX() const {return m_x;}
        double getY() const {return m_y;}
        double getZ() const {return m_z;}

        // Restituisce il raggio (da (0,0,0))
        double getR() {return m_R;}
        // Restituisce angolo azimutale
        double getPhi() {return m_phi;}
        // Restituisce angolo polare
        double getTheta() {return m_theta;}

        // Distanza da un altro punto p(x,y,z)
        double calcDist(const Posizione& p) {
            return sqrt(pow(p.getX() - m_x, 2) + pow(p.getY() - m_y, 2) + pow(p.getZ() - m_z, 2));
        }


        // Set values to position coords and updates the others
        void setX(double x) { m_x = x; setSpheric(); }
        void setY(double y) { m_y = y; setSpheric(); }
        void setZ(double z) { m_z = z; setSpheric(); } 

        void setR(double R) { m_R = R; setCartes(); }
        void setPhi(double phi) { m_phi = phi; setCartes(); }
        void setTheta(double theta) { m_theta = theta; setCartes(); }
        

        // Aggiorna le coordinate sferiche
        void setSpheric() {
            m_R = sqrt(pow(m_x, 2) + pow(m_y, 2) + pow(m_z, 2));
            m_phi = atan2(m_y, m_x);
            m_theta = acos(m_z/m_R);
        } 

        // Aggiorna le coordiante cartesiane
        void setCartes() {
            m_x = m_R * sin(m_theta) * cos(m_phi);
            m_y = m_R * sin(m_theta) * sin(m_phi);
            m_z = m_R * cos(m_theta);
        }


        ~Posizione() {;};
};


class CampoVettoriale : public Posizione {
    private:
        double m_Fx, m_Fy, m_Fz;

    public:
        CampoVettoriale(Posizione p) { m_Fx = p.getX(); m_Fy = p.getY(); m_Fz = p.getZ(); }

        void setFx(double Fx) {m_Fx = Fx;}
        void setFy(double Fy) {m_Fy = Fy;}
        void setFz(double Fz) {m_Fz = Fz;}

        double getFx() const {return m_Fx;}
        double getFy() const {return m_Fy;}
        double getFz() const {return m_Fz;}


        CampoVettoriale& operator+= (const CampoVettoriale& v) { return (*this) = (*this) + v; };
        CampoVettoriale operator+ (const CampoVettoriale& v) const {
            if ( ( v.getX()!= getX() ) || ( v.getY()!= getY() ) || ( v.getZ()!= getZ() ) ) {
                cout << "Somma di campi vettoriali in punti diversi non ammessa" << endl;
                exit (1);
            } 

            // Nuovo campo vettoriale somma
            CampoVettoriale sum(Posizione(getX(), getY(), getZ()));
            sum.setFx(getFx() + v.getFx());
            sum.setFy(getFy() + v.getFy());
            sum.setFz(getFz() + v.getFz());

            return sum;
        }

        double Modulo() const {return sqrt(pow(m_Fx,2) + pow(m_Fy,2) + pow(m_Fz,2));};
};