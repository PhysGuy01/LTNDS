#include <iostream>

using namespace std;

// Posso creare una classe generica di vettore che puo' contenere diversi tipi di dati 
template <typename T> class Vettore {
    public:
        Vettore();
        Vettore(int N);
        Vettore(const Vettore& );

        // Ridefinisce gli operatori = e [] per i vettori
        Vettore& operator=(const Vettore&);
        double& operator[](int i);

        // Distruttore
        ~Vettore();

        int GetN() const {return m_N;}
        void SetComponent(int i, T a);
        T GetComponent(int i) const; 

        const void Scambia(int primo, int secondo);

    private:
        int m_N;    // Dimensione vettore
        T* m_v;    // Array di double
};



// template <template T> ....

// Vettore Read(int nDat, string& filename) {
//     fstream f;
//     f.open(filename, ios::in);

//     Vettore V(nDat);

//     for (int i = 0; i < nDat; i++) 
//         f >> V[i];

//     return V;
// }

//              NOTA MOLTO BENE
// Quando chiamo una funzione template NON POSSO compilare per parti
// devo per forza compilare tutto insieme


// --------------------
//         STL
// --------------------

// vector: array di memoria cnotigue, lento l'accesso a elementi centrali
// Lista: aray di memoria piu' veloce per accesso elem centr

// Vector:
#include <vector>
// ...


// -----------------
//      ROOT
// -----------------

// forse si puo' usare anche python x matplotlib
// se uso root devo spcificarlo nel makefile:
// LIBS := 'root-config --libs'
// INCS :+ 'root-config --cflags'


int main() {
    int ndata;
    char * filename;
    Vettore <double> v = Read<double>(ndata, filename); // Devo specificare in che tipo concretizzo la mia classe 
    double media = calcMedia<double>(v); 

    // Vector:
    double a;
    vector<double> vnull;
    vnull.push_back(a); // aggiunge in coda

    return 0;
}