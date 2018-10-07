#include "../Lista/Lista.h"

#ifndef UNION_H
#define UNION_H


template<class T>
Lista<T> *unir(Lista<T> *lisA, Lista<T> *lisB) {
	
	int lengthA = lisA->getTamanio();
	int lengthB = lisB->getTamanio();
	Lista<T> *nueva = new Lista<T>();
	
	for(int i = 0; i < lengthA; i++){
		nueva->insertarUltimo(lisA->getDato(i));
	}
	
	for(int i = 0; i < lengthB; i++){
		nueva->insertarUltimo(lisB->getDato(i));
	}
	
    return nueva;
}


#endif //UNION_H
