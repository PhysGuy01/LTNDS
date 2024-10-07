#include "Vettore.h"


Vettore::Vettore()  {
  m_N = 0;
  m_v = NULL;
}

Vettore::Vettore(int N) {
	if ( N < 0 ) {
		cout << "Errore: la dimensione deve essere positiva " << endl;
		exit (1); 
	} else {
		m_N = N;
		// Crea un array di double della giusta dimensione
		// e inizializza gli elementi a 0
		m_v = new double[N];
		for (int k = 0 ; k < N ; k++) 
			m_v[k] = 0;
	}
}

// Destructor
Vettore::~Vettore() {
	delete[] m_v;
}

// Assegna il valore a all'elemento i-esimo del vettore
void Vettore::SetComponent(int i, double a) {
	if (i < m_N) {
		m_v[i] = a;
	} else {
		cout << "Errore: indice passato in SetComponent: " << i << endl;
		exit (2); 
	}
}

// Restituisce il valore i-esimo
double Vettore::GetComponent(int i) const {
	if (i < m_N) {
		return m_v[i];
	} else {
		cout << "Errore: indice passato in GetComponent: " << i << endl;
		exit(2); 
	}
}

// Scambia due valori nell'array
const void Vettore::Scambia(int primo, int secondo){
	double temp = GetComponent(primo);
	SetComponent(primo, GetComponent(secondo));
	SetComponent(secondo, temp);
}

// Overloading costruttore di copia
Vettore::Vettore(const Vettore& V) {
	m_N = V.GetN();
	m_v = new double[m_N];
	for (int i = 0; i < m_N; i++) 
		m_v[i] = V.GetComponent(i);
}

Vettore& Vettore::operator=(const Vettore& V) {
    m_N = V.GetN();
    m_v = new double[m_N];

    for (int i = 0; i < m_N; i++) {
        m_v[i] = V.GetComponent(i);
    }
    return *this;
}

double& Vettore::operator[](int i) {
    if ( i < m_N ) {
        return m_v[i];
    } else {
		cout << "Errore: indice passato: " << i << endl;
        exit(2);
    }
}
