#ifndef __PuntoMateriale_h__
#define __PuntoMateriale_h__

#include "Particella.h"
#include "Posizione.h"
#include "CampoVettoriale.h"

using namespace std;

class PuntoMateriale : public Posizione, public Particella {
    public:
        PuntoMateriale(double massa, double carica, const Posizione&);
        PuntoMateriale(double massa, double carica, double x, double y, double z);

        CampoVettoriale CampoElettrico(const Posizione&) const;
};

#endif