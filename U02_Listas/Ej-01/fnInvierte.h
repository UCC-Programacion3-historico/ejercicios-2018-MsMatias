#include "../Lista/Lista.h"
#ifndef FNINVIERTE_H
#define FNINVIERTE_H


template <class T>
void fnInvierte (Lista<T> *lis);


template <class T>
void fnInvierte (Lista<T> *lis){
	int length = lis->getTamanio() - 1;
	
	for(int i = 0; i < length/2; i++){
		T temp = lis->getDato(i);
		lis->reemplazar(i, lis->getDato(length - i));
		lis->reemplazar(length - i, temp);
	}
}


#endif //FNINVIERTE_H
