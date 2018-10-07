#include <iostream>
#include "../Pila/Pila.h"
#include "iguales.h"

using namespace std;

int main() {
    std::cout << "Ejercicio 03/02\n" << std::endl;
    
    Pila<int> *p1 = new Pila<int>();
    Pila<int> *p2 = new Pila<int>();
    
    for(int i = 2; i < 10; i++)
    	p1->push(i);
    	
    for(int i = 2; i < 10; i++)
    	p2->push(i);
    	
    cout << "Las pilas son " << ((iguales(p1, p2)) ? "iguales" : "diferentes") << endl;
    
    system("PAUSE");
    return 0;
}
