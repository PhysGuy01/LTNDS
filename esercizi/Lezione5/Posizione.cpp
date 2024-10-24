#include "Posizione.h"
#include <cmath>

Posizione::Posizione() {
    mx = 0;
    my = 0;
    mz = 0;
}

Posizione::Posizione(double x, double y, double z) {
    mx = x;
    my = y;
    mz = z;
}

double Posizione::getX() const {
    return mx;
}
double Posizione::getY() const {
    return my;
}
double Posizione::getZ() const {
    return mz;
}

double Posizione::getR() const {
    return sqrt(pow(mx,2) + pow(my,2) + pow(mz,2));
}       
double Posizione::getPhi() const {
  return atan2(my,mx);
}
double Posizione::getTheta() const {
  return acos(mz/getR());
}

double Posizione::getRho() const {
  return sqrt(mx*mx+my*my);
}


double Posizione::calcDist(const Posizione& p) const {
    return sqrt(pow(getX()-p.getX(), 2) + pow(getY()-p.getY(), 2) + pow(getZ()-p.getZ(), 2));
}
