#include <iostream>
#include <string>
#include "../Pila/Pila.h"

using namespace std;


int main() {
    std::cout << "Ejercicio 03/03\n" << std::endl;
    
    Pila<char> *pila = new Pila<char>();
    string funcion = "(6+2)*5-8/4";
    
    for(int i = 0; i < funcion.length(); i++)
    	pila->push(funcion[i]);
    	
        
    return 0;
}
