#include <iostream>

using namespace std;

// classes

class Vettore { // Definisco un nuovo tipo di variabile (di tipo Vettore)

    public:
        unsigned int GetN() const {return m_N;}; // funzione che restituisce m_N, const = funz non puo' modificare la classe
        void SetComponent(int, double); // dove vuoi mettere il contenuto del vettore? (indice int)
        double GetComponent(int) const; // prende il contenuto del vettore all'indice int

    private: // nessuno puo' accedere a questi dati a meno che non siano metodi della classe stessa
        unsigned int m_N;
        double *m_v;

};

int main() {
    Vettore myvett_obj; // ho costruito un oggetto di tipo vettore
    Vettore *myvett_poi = new Vettore(); // ho costruito un puntatore a un oggetto di tipo vettore

    cout <<"Size of my vector: " << myvett_obj.GetN() << endl;
    cout <<"Size of my vector: " << myvett_poi->GetN() << endl;
    /*  Questo non lo posso fare perche' m_N e' privato!
    cout <<"Size of my vector: " << myvett_obj.m_N << endl;
    cout <<"Size of my vector: " << myvett_poi->m_N << endl;
    */

   return 0;
}