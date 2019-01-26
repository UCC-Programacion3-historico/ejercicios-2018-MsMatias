 #include <iostream>
#include <string>
#include "HashMap.h"

//Tamano de elementos
#define TAM 5
//Tamano de hash
#define TAMH 9 

using namespace std;

unsigned int hashFunc(int clave) {
    return clave % TAMH;
}

int main() {
    string s[TAM] = {"John Smith", "Lisa Smith", "Sandra Dee", "Ted Baker", "Sam Doe"};
    int claves[TAM] = {59, 12, 72, 92, 15};
    //Tenia que modificar el tamano del hash (TAM->TAMH) pq habia colisiones con tamano de TAM
    HashMap<int, string> hash(TAMH, &hashFunc);
     std::cout << "Ejercicio 05/01\n" << std::endl;

    for(int i = 0; i < TAM; i++)
        hash.put(claves[i], s[i]);

    for(int i = 0; i < TAM; i++)
        cout << "Posicion: " << i+1 << "\tClave: " << claves[i] << "\t Valor: " << hash.get(claves[i]) << endl;

    hash.remove(claves[3]);

    for(int i = 0; i < TAM; i++) {
        if(i == 3)
            continue;
        cout << "Posicion: " << i+1 << "\tClave: " << claves[i] << "\t Valor: " << hash.get(claves[i]) << endl;
    }

     return 0;
}
