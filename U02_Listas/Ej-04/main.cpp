#include <iostream>
#include "../Lista/Lista.h"
#include "union.h"

using namespace std;

int main() {
    std::cout << "Ejercicio 01/04\n" << std::endl;
    
    Lista<int> *l1 = new Lista<int>();
	Lista<int> *l2 = new Lista<int>();
    
    for(int i = 1; i < 10; i++)
		l1->insertarUltimo(i);
    
    for(int i = 10; i < 20; i++)
		l2->insertarUltimo(i);
		
	cout << "Lista 1: " << *l1 << endl;
		
	cout << "Lista 2: " << *l2 << endl;
		
	Lista<int> *c = unir(l1, l2);
	
	cout << "Lista Unida: " << *c << endl;	
    
    return 0;
}
