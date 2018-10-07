#ifndef LISTA_H
#define LISTA_H

#include "nodo.h"
//#include <iostream>

//using namespace std;

/**
 * Clase que implementa una Lista Enlasada generica, ya que puede
 * almacenar cualquier tipo de dato T
 * @tparam T cualquier tipo de dato
 */
template<class T>
class Lista {
private:
    nodo<T> *inicio;
public:
    Lista();

    Lista(const Lista<T> &li);

    ~Lista();

    bool esVacia();

    int getTamanio();

    void insertar(unsigned int pos, T dato);

    void insertarPrimero(T dato);

    void insertarUltimo(T dato);

    void remover(unsigned int pos);

    T getDato(int pos);

    void reemplazar(int pos, T dato);

    void vaciar();
};


/**
 * Constructor de la clase Lista
 * @tparam T
 */
template<class T>
Lista<T>::Lista() {
	inicio = nullptr;
}


/**
 * Constructor por copia de la clase Lista
 * @tparam T
 * @param li
 */
template<class T>
Lista<T>::Lista(const Lista<T> &li) {}


/**
 * Destructor de la clase Lista, se encarga de liberar la memoria de todos los nodos
 * utilizados en la lista
 * @tparam T
 */
template<class T>
Lista<T>::~Lista() {
	int length = this->getTamanio() - 1;
	nodo <T> *aux = inicio;
	nodo <T> *remover = inicio;
	
	while(length > 0 && aux != nullptr){
		length--;
		remover = aux;
		delete remover;
		aux = aux->getNext();
	}
}


/**
 * Metodo para saber si la lista esta vacia
 * @tparam T
 * @return true si la lista esta vacia, sino false
 */
template<class T>
bool Lista<T>::esVacia() { 
	return inicio == nullptr;	
}


/**
 * Metodo para obtener la cantidad de nodos de la lista
 * @tparam T
 * @return la cantidad de nodos de la lista
 */
template<class T>
int Lista<T>::getTamanio() {
    int cant = 0;
    nodo<T> *aux = inicio;

    while(aux != nullptr) {
        cant++;
        aux = aux->getNext();
    }

    return cant;
}



/**
 * Inserta un nodo con el dato en la posicion pos
 * @tparam T
 * @param pos lugar donde será insertado el dato
 * @param dato  dato a insertar
 */
template<class T>
void Lista<T>::insertar(unsigned int pos, T dato) {
    auto *nuevo = new nodo<T>(); //Nuevo nodo vacio
    nuevo->setDato(dato); //Seteamos valor al nuevo nodo
    nodo<T> *aux = inicio; //Guardamos el nodo de inicio en un espacio de memoria temporal
    unsigned int pos_actual = 0; //Inicializamos contador de posicion a 0

	//Si pos (argumento) = 0 entonces 
    if(pos == 0) {
        nuevo->setNext(inicio); //Seteamos como siguiente nodo del nodo nuevo al nodo inicio ya existente en la lista
        inicio = nuevo; //El nodo de inicio de la lista es ahora el nodo nuevo
        return;
    }

	//Mientras el contador por es menor a pos -1 y el nodo temporal no es nullo se ejecutar� el bucle
	//cout << "comienza lectura con pos enviada" << pos <<endl;
    while(pos_actual < pos - 1 and aux != nullptr) {
    	//cout << "pos actual " << pos_actual << " - pos enviada " << pos << endl;
        pos_actual++;        
        aux = aux->getNext(); //Buscamos el nodo anterior donde queremos colocar el nuevo
    }

    if(aux == nullptr)
        throw 1;

    nuevo->setNext(aux->getNext()); //Seteamos como siguiente nodo del nodo nuevo al siguente del nodo temporal
    aux->setNext(nuevo); //Seteamos como siguiente nodo del nodo temporal al nodo nuevo
}


/**
 * Inserta un nodo con el dato en la primera posicion
 * @tparam T
 * @param dato dato a insertar
 */
template<class T>
void Lista<T>::insertarPrimero(T dato) {
	 insertar(0, dato);
}


/**
 * Inserta un nodo con el dato en la ultima posicion
 * @tparam T
 * @param dato dato a insertar
 */
template<class T>
void Lista<T>::insertarUltimo(T dato) {
	 insertar(getTamanio(), dato);
}


/**
 * Elimina el nodo en la posicion 'pos' de la lista enlasada
 * @tparam T
 * @param pos posicion del nodo a eliminar
 */
template<class T>
void Lista<T>::remover(unsigned int pos) {
	auto *last = inicio;
	auto *aux = inicio;
	auto *next = inicio;
	
	if(pos == 0){
		inicio = last->getNext();
		return;
	}
	
	while(pos > 0 && aux != nullptr){
		pos--;
		last = aux;
		aux = aux->getNext();
		next = aux->getNext();
	}
	
	if(aux == nullptr)
		throw 1;
		
	last->setNext(next);
}


/**
 * Obtener el dato del nodo en la posicion pos
 * @tparam T
 * @param pos posicion del dato
 * @return dato almacenado en el nodo
 */
template<class T>
T Lista<T>::getDato(int pos) {
	auto *aux = inicio;

    while (pos > 0 && aux != nullptr) {
        pos--;
        aux = aux->getNext();
    }

    if (aux == nullptr)
        throw 1;

    return aux->getDato();
}


/**
 * Reemplaza el dato almacenado en un nodo por este otro
 * @tparam T
 * @param pos posicion donde se desea reemplazar
 * @param dato nuevo dato a almacenar
 */
template<class T>
void Lista<T>::reemplazar(int pos, T dato) {
	auto *aux = inicio;

    while (pos > 0 && aux != nullptr) {
        pos--;
        aux = aux->getNext();
    }
    
    if (aux == nullptr)
        throw 1;
        
    aux->setDato(dato);
}


/**
 * Función que vacia la lista enlazada
 * @tparam T
 */
template<class T>
void Lista<T>::vaciar() {	
	inicio->setNext(nullptr);
	inicio = nullptr;	
}

template<class T>
std::ostream& operator<<(std::ostream& out, Lista<T>& l) {
  	for(int i = 0; i < l.getTamanio(); i++) {
        out << l.getDato(i);
        if(i != l.getTamanio()-1)
            out << "->";
    }  
    return out;
}


#endif //LISTA_H
