#include <iostream>

using namespace std;

int main(int argc, char** argv){
    // ./ex_argv argv[0] argv[1] ...
    // occhio alla fnz atoi() [character to integer]

    if (argc < 3) {
        cout << "uso del programma: " << argv[0] << " <n_dati> <filename>" << endl;
        return 1;
    }


    // obbiettio primo esercizio:

    // aprire file 1941.txt e leggere elementi in un arrya dinamici
    //... 
    
    // Cakcolare media dev std........
    // altro che non ho scrtitto
    return 0;
}


/*
non usiamo un array fissato perche non sappiamo il numero di elementi a compilazione 
(quindi a compilazione la macchina non sa quanta memoria llocare per l'array)
con un array dinamico invece allochiamo dibamicanente la memoria a runtime 
*/