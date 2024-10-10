#ifndef __Vettore_h__
#define __Vettore_h__

#include <iostream>

using namespace std;

template <typename T> class Vettore {
    public:
        Vettore();
        Vettore(int N);
        Vettore(const Vettore& );

        // Ridefinisce gli operatori = e [] per i vettori
        Vettore& operator=(const Vettore&);
        T& operator[](int i);

        // Distruttore
        ~Vettore();

        int GetN() const {return m_N;}
        void SetComponent(int i, T d);
        T GetComponent(int i) const; 

        void Scambia(int primo, int secondo);

    private:
        int m_N;    // Dimensione vettore
        T* m_v;    // Array di T
};



template <typename T> Vettore<T>::Vettore()  {
  m_N = 0;
  m_v = NULL;
}

template <typename T> Vettore<T>::Vettore(int N) {
	if ( N < 0 ) {
		cout << "Errore: la dimensione deve essere positiva " << endl;
		exit (1); 
	} else {
		m_N = N;
		// Crea un array di double della giusta dimensione
		// e inizializza gli elementi a 0
		m_v = new T[N];
		for (int k = 0 ; k < N ; k++) 
			m_v[k] = 0;
	}
}

// Destructor
template <typename T> Vettore<T>::~Vettore() {
	delete[] m_v;
}

// Assegna il valore a all'elemento i-esimo del vettore
template <typename T> void Vettore<T>::SetComponent(int i, T a) {
	if (i < m_N) {
		m_v[i] = a;
	} else {
		cout << "Errore: indice passato in SetComponent: " << i << endl;
		exit (2); 
	}
}

// Restituisce il valore i-esimo
template <typename T> T Vettore<T>::GetComponent(int i) const {
	if (i < m_N) {
		return m_v[i];
	} else {
		cout << "Errore: indice passato in GetComponent: " << i << endl;
		exit(2); 
	}
}

// Scambia due valori nell'array
template <typename T> void Vettore<T>::Scambia(int primo, int secondo) {
	double temp = GetComponent(primo);
	SetComponent(primo, GetComponent(secondo));
	SetComponent(secondo, temp);
}

// Overloading costruttore di copia
template <typename T> Vettore<T>::Vettore(const Vettore& V) {
	m_N = V.GetN();
	m_v = new double[m_N];
	for (int i = 0; i < m_N; i++) 
		m_v[i] = V.GetComponent(i);
}

template <typename T> Vettore<T>& Vettore<T>::operator=(const Vettore<T>& V) {
    m_N = V.GetN();
    m_v = new double[m_N];

    for (int i = 0; i < m_N; i++) {
        m_v[i] = V.GetComponent(i);
    }
    return *this;
}


template <typename T> T& Vettore<T>::operator[](int i) {
    if ( i < m_N ) {
        return m_v[i];
    } else {
		cout << "Errore: indice passato: " << i << endl;
        exit(2);
    }
}

#endif 