#include "../U02_Listas/Lista/Lista.h"
#ifndef FNINVERTIRF_H
#define FNINVERTIRF_H


template <class T>
void fnInvierteF (Lista<T> *lis);


template <class T>
void fnInvierteF (Lista<T> *lis){
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
