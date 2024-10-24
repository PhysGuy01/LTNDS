#ifndef __Posizione_h__
#define __Posizione_h__

using namespace std;

class Posizione {
    public:
        Posizione();
        Posizione(double x, double y, double z);

        ~Posizione(){;};

        double getX() const;
        double getY() const;               
        double getZ() const;

        double getR() const;
        double getPhi() const;
        double getTheta() const;

        double getRho() const;

        double calcDist(const Posizione&) const;

    private:
        double mx, my, mz;
};

#endif