#include "../U02_Listas/Lista/Lista.h"
#ifndef FNBUSQUEDA_H
#define FNBUSQUEDA_H


template <class T>
void fnBusqueda (T valor, Lista<T> *lis);


template <class T>
void fnBusqueda (T valor, Lista<T> *lis){
	int length = lis->getTamanio() - 1;
	
	for(int i = 0; i < length; i++){
		T temp = lis->getDato(i);
		if(temp == valor){
			lis->insertarPrimero(valor);
			lis->remover(i+1);
		}
	}
}


#endif //FNINVIERTE_H
