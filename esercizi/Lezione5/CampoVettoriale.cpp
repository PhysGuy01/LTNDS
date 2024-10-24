#include "CampoVettoriale.h"
#include <iostream>
#include <cmath>

CampoVettoriale::CampoVettoriale(const Posizione& p) {
    vx = p.getX();
    vy = p.getY();
    vz = p.getZ();
}


double CampoVettoriale::getVX() const {
    return vx;
}

double CampoVettoriale::getVY() const {
    return vy;
}

double CampoVettoriale::getVZ() const {
    return vz;
}


void CampoVettoriale::setVX(double x) {
    vx = x;
}

void CampoVettoriale::setVY(double y) {
    vy = y;
}

void CampoVettoriale::setVZ(double z) {
    vz = z;
}


double CampoVettoriale::Modulo() const {
    return sqrt(pow(vx,2) + pow(vy,2) + pow(vz,2));
}

CampoVettoriale CampoVettoriale::operator+(const CampoVettoriale &v) const {  
    cout << "Aspe: vx " << v.getX() << "; vy " << v.getY() << "; vz " << v.getZ() << endl;
    if (( v.getX()!= getX()) || (v.getY()!= getY()) || (v.getZ()!= getZ())) {
        cout << "Attenzione! Somma di campi in coordinate diverse" << endl;
        exit(1);
    } 

    // Nuovo campo vettoriale somma (somma delle coord dei vettori in un punto)
    CampoVettoriale somma(Posizione(getX(),getY(), getZ()));
    somma.setVX(getVX() + v.getVX());  
    somma.setVY(getVY() + v.getVY());  
    somma.setVZ(getVZ() + v.getVZ());  
    return somma;
}

CampoVettoriale &CampoVettoriale::operator+=(const CampoVettoriale &v) {
    return (*this) = (*this)+v;
}