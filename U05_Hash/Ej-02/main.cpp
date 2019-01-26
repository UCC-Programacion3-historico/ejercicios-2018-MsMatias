#include <iostream>
#include <string>
#include "HashMap.h"
#include "../../U02_Listas/Lista/Lista.h"

//Tamano de elementos
#define TAM 5
//Tamano de hash
#define TAMH 17

using namespace std;

unsigned int hashFunc(int clave) {
    return clave % TAMH;
}

int main() {
    string s[TAM] = {"John Smith", "Lisa Smith", "Sandra Dee", "Ted Baker", "Sam Doe"};
    int claves[TAM] = {59, 12, 72, 31, 14};
    //Tenia que modificar el tamano del hash (TAM->TAMH) pq habia colisiones con tamano de TAM
    HashMap<int, string> hash(TAMH, &hashFunc);
    std::cout << "Ejercicio 05/02\n" << std::endl;

    for(int i = 0; i < TAM; i++)
        hash.put(claves[i], s[i]);

    for(int i = 0; i < TAM; i++) {
        cout << "Posicion: " << i+1 << "\tClave: " << claves[i] << "\t Valor: ";
        Lista<string> *l = hash.get(claves[i]);
        for(int i = 0; i < l->getTamanio(); i++) {
            cout << l->getDato(i);
            if(i != l->getTamanio() - 1)
                cout << "->";
        }
        cout << endl;
    }

     return 0;
}
