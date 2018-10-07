#include <iostream>
#include <string.h>
#include "../U02_Listas/Lista/Lista.h"
#include "../U03_Pilas/Pila/Pila.h"

using namespace std;

void busquedaValor(Pila<int> *pil, Lista<int> *lis);

int main() {
	
	Pila<int> *pila = new Pila<int>();
	Lista<int> *lista = new Lista<int>();	
	
	for(int i = 1; i < 10; i++)
		lista->insertarUltimo(i);
		
	pila->push(1);
	pila->push(8);
	
	cout << "Lista Original: " << *lista << endl;
	
	eliminarPos(pila, lista);
	
	cout << "Lista Final: " << *lista << endl;
 
    return 0;
}

void eliminarPos(Pila<int> *pil, Lista<int> *lis){
	while(!pil->esVacia()){
		lis->remover(pil->pop());
	}
	
	return;
}
