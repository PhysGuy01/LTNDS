#ifndef __CampoVettoriale_h__
#define __CampoVettoriale_h__

#include "Posizione.h"

using namespace std;

class CampoVettoriale : public Posizione {

    public:
        CampoVettoriale(const Posizione&);
        
        ~CampoVettoriale(){;};

        double getVX() const;
        double getVY() const;
        double getVZ() const;

        void setVX(double x);
        void setVY(double y);
        void setVZ(double z);

        double Modulo() const;

        CampoVettoriale &operator+=(const CampoVettoriale&);
        CampoVettoriale operator+(const CampoVettoriale&) const;

    private:
        double vx, vy, vz;

};

#endif