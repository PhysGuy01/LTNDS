#ifndef __Particella_h__
#define __Particella_h__


class Particella {

    public:
        // Particella();
        Particella(double massa, double carica);
        
        ~Particella(){;};

        double getMassa() const;
        double getCarica() const;

        void Print() const;

    protected:
        double m_massa, m_carica;
};

class Elettrone : public Particella {
    public:
        Elettrone();
        ~Elettrone(){;};   

        void Print() const;
};

#endif