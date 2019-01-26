#include <iostream>
#include "../Arbol/ArbolBinario.h"
#include <ctime>
#include <cstdlib>

using namespace std;

bool contains(int *i, int c, int s) {
    for(int j = 0; j < s; j++) {
        if(*i == c)
            return true;
        i++;
    }

    return false;
}

int main() {
    int numeros[30];
    ArbolBinario<int> arbol;

    srand(time(NULL));
    cout << "Ejercicio 05/01\n" << endl;

    cout << "Los numeros: ";
    for(int i = 0; i < 30; i++) {
        int numeroR = (rand() % 400) + 100;

        //To garuntee the numbers are unique that are added to the array, or an error throws
        if(!contains(numeros, numeroR, i)) {
            numeros[i] = numeroR;
            cout << numeros[i] << ' ';
            arbol.put(numeros[i]);
        }else{
            i--;
        }
    }
    cout << endl << "Inorden: ";

    arbol.inorder();

    cout << endl;

    return 0;
}
