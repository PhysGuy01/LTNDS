#include "PuntoMateriale.h"
#include <cmath>
using namespace std;

/*
// PuntoMateriale::PuntoMateriale(double massa, double carica, const Posizione&) : Particella(massa,carica), Posizione(x,y,z) {}
PuntoMateriale::PuntoMateriale(double massa, double carica, double x, double y, double z) : Particella(massa,carica), Posizione(x,y,z) {}
CampoVettoriale PuntoMateriale::CampoElettrico(const Posizione& p) const {
    
    double epsilon_zero = 8.854187817E-12;

    CampoVettoriale campo(p);

    double ex = m_carica * p.getX()/(pow(p.getR(), 3) * 4 * M_PI * epsilon_zero);
    double ey = m_carica * p.getY()/(pow(p.getR(), 3) * 4 * M_PI * epsilon_zero);
    double ez = m_carica * p.getZ()/(pow(p.getR(), 3) * 4 * M_PI * epsilon_zero);

    campo.setVX(ex);
    campo.setVY(ey);
    campo.setVZ(ez);

    return campo;
}
*/
PuntoMateriale::PuntoMateriale(double massa, double carica, double x, double y, double z) : Particella(massa,carica), Posizione(x,y,z) {}

CampoVettoriale PuntoMateriale::CampoElettrico(const Posizione& p) const {
    double k = 8.9875517873681764E9; // costante di coulomb
    double r = p.calcDist(Posizione(getX(), getY(), getZ())); // distanza della carica
    
    // Calcola le componenti del campo
    double ex = k * getCarica() * (p.getX() - getX()) / pow(r,3); 
    double ey = k * getCarica() * (p.getY() - getY()) / pow(r,3);
    double ez = k * getCarica() * (p.getZ() - getZ()) / pow(r,3);
    
    CampoVettoriale campo(p);
    campo.setVX(ex);
    campo.setVY(ey);
    campo.setVZ(ez);

    return campo;
}
