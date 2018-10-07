#include <iostream>
#include <string>
#include "../Cola/Cola.h" 
#include "iguales.h"

using namespace std;

int main() {
    std::cout << "Ejercicio 04/01\n" << std::endl;
    
    Cola<char> *col1 = new Cola<char>();
    Cola<char> *col2 = new Cola<char>();
    
    string texto1 = "hola";
    string texto2 = "holaa";
    
    for(int i = 0; i < texto1.length(); i++)
    	col1->encolar(texto1[i]);
    	
    for(int i = 0; i < texto2.length(); i++)
    	col2->encolar(texto2[i]);
    
     cout << "Las colas son " << ((iguales(col1, col2)) ? "iguales" : "diferentes") << endl;
    
    return 0;
}
