#include <iostream>
#include <string.h>
#include "../U02_Listas/Lista/Lista.h"
#include "../U03_Pilas/Pila/Pila.h"
#include "fnbusqueda.h"

using namespace std;


int main() {
	
	Pila<int> *pila = new Pila<int>();
	Lista<int> *lista = new Lista<int>();	
	
	for(int i = 20; i > 0; i--)
		lista->insertarUltimo(i);
		
	cout << "Lista Original: " << *lista << endl;
	
	fnBusqueda(5, lista);
	
	cout << "Lista Final: " << *lista << endl;
 
    return 0;
}
