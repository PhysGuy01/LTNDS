#include <iostream>

using namespace std;

// Meglio scrivere file separati per funzioni di classi diverse

class Vettore { // Definisco un nuovo tipo di variabile (di tipo Vettore)

    public:
        Vettore() { // Costruttore
            m_N = 0;
            m_v = NULL;
        };

        Vettore(int N) { // Altro tipo di costruttore, costruisce vettore con 10 spazi
            m_N = N;
            m_v = new double[N];
            for (int k =0; k < N; k++) m_v = 0;
        }

        // Manca distruttore 
        ~Vettore
    private: // nessuno puo' accedere a questi dati a meno che non siano metodi della classe stessa
        unsigned int m_N;
        double *m_v;

};

int main() {
    Vettore myvett_obj_1; // ho costruito un oggetto di tipo vettore
    Vettore myvett_obj_2 (10);
    Vettore myvett_obj_3 {10}; // migliore

    Vettore *myvett_poi = new Vettore(); // ho costruito un puntatore a un oggetto di tipo vettore
    Vettore *myvett_poi = new Vettore(10);

    myvett_obj_2.SetComponent(3,99.) // Guarda pdf...

   return 0;
}