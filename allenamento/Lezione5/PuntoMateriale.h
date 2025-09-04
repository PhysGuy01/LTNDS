#pragma once

#include "Particella.h"
#include "Posizione.h"
#include "funzioni.h"


// Punto materiale = particella con posizione
class PuntoMateriale : public Particella, public Posizione {
    public:
        PuntoMateriale(double massa, double carica, double x, double y, double z) : Particella(massa, carica), Posizione(x,y,z) {}
        ~PuntoMateriale(){;};

        CampoVettoriale CampoElettrico(Posizione& b) const{
            // Calcola il campo elettrico nel punto b rispetto alla posizione del punto materiale a
            CampoVettoriale campo(b);

            double k = 8.9875517873681764E9; // costante di coulomb
            double r = b.calcDist(Posizione(getX(), getY(), getZ())); // distanza della carica

            // Calcola le componenti del campo

            double ex = k * getCharge() * (b.getX() - getX()) / pow(r, 2);
            double ey = k * getCharge() * (b.getY() - getY()) / pow(r, 2);
            double ez = k * getCharge() * (b.getZ() - getZ()) / pow(r, 2);

            campo.setFx(ex);
            campo.setFy(ey);
            campo.setFz(ez);

            return campo;
        }
};