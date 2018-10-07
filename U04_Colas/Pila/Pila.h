#ifndef PILA_H
#define PILA_H
#include "nodo.h"
/**
 * Clase que implementa una Pila generica, ya que puede
 * almacenar cualquier tipo de dato T
 * @tparam T cualquier tipo de dato
 */
template<class T>
class Pila {
private:
	nodo<T> *tope;
public:
    Pila();

    ~Pila();

    void push(T dato);

    T pop();

    bool esVacia();
    
    T peek();
};


/**
 * Constructor de la clase Pila
 * @tparam T
 */
template<class T>
Pila<T>::Pila() {
	tope = nullptr;
}


/**
 * Destructor de la clase PILA, se encarga de liberar la memoria de todos los nodos
 * utilizados en la PILA
 * @tparam T
 */
template<class T>
Pila<T>::~Pila() {
	nodo <T> *aux = tope;

    while (aux != nullptr){
        tope = aux->getNext();
        delete aux;
        aux = tope;
    }
}


/**
 * Inserta un dato en la pila
 * @tparam T
 * @param dato  dato a insertar
 */
template<class T>
void Pila<T>::push(T dato) {
	auto *nuevo = new nodo<T>();
	nuevo->setNext(tope);
	tope = nuevo;
	nuevo->setDato(dato);
}


/**
 * Obtener el dato de la pila
 * @tparam T
 * @return dato almacenado en el nodo
 */
template<class T>
T Pila<T>::pop() {
	
	if(tope == nullptr){
        throw 1;
    }
    
	T dato = tope->getDato();	
	nodo<T> *aux = tope;
	tope = tope->getNext();
	
    delete aux;
    return dato;
}

/**
 * Responde si la pila se encuentra Vacía
 * @tparam T
 * @return
 */
template<class T>
bool Pila<T>::esVacia() {
	return tope == nullptr;
}

/**
 * Leer el dato del nodo tope de la pila
 * @tparam T
 * @return dato almacenado en el nodo
 */
template<class T>
T Pila<T>::peek(){
    if(tope == nullptr){
        throw 1;
    }
    return tope->getDato();
}

#endif //PILA_H
