#include "../Pila/Pila.h"

#ifndef IGUALES_H
#define IGUALES_H


template<class T>
bool iguales(Pila<T> *pilaA, Pila<T> *pilaB) {
			
	while(!pilaA->esVacia() && !pilaB->esVacia()){
		
		if(pilaA->pop() != pilaB->pop())
			return false;
		
	}
		
    return (pilaA->esVacia() && pilaB->esVacia());
}


#endif //IGUALES_H
