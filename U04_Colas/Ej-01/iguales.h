#include "../Cola/Cola.h"

#ifndef IGUALES_H
#define IGUALES_H


template<class T>
bool iguales(Cola<T> *colA, Cola<T> *colB) {
			
	while(!colA->esVacia() && !colB->esVacia()){
		if(colA->desencolar() != colB->desencolar())
			return false;
	}
	
	return (colA->esVacia() && colB->esVacia());
		
}


#endif //IGUALES_H
