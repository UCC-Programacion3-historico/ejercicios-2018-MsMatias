#ifndef ARBOLBINARIO_H
#define ARBOLBINARIO_H

#include "NodoArbol.h"
#include <iostream>

using namespace std;

template<class T>
class ArbolBinario {
private:
	enum {IZQUIERDO, DERECHO};
    NodoArbol<T> *raiz;
    NodoArbol<T> *actual;
public:
    ArbolBinario();

    void put(T dato);

    T search(T dato);

    void remove(T dato);

    void preorder();

    void inorder();

    void postorder();

    ~ArbolBinario();

    bool esVacio();

    void print();
    
    void balance(NodoArbol<T> *nodo, int rama, bool nuevo);
    
    void RDD(NodoArbol<T> *nodo);
    
    void RDI(NodoArbol<T> *nodo);
    
    void RSI(NodoArbol<T> *nodo);
    
    void RSD(NodoArbol<T> *nodo);
protected:
    void put(T dato, NodoArbol<T> *r);

    T search(T dato, NodoArbol<T> *r);

    NodoArbol<T> *remove(T dato, NodoArbol<T> *r);

    void preorder(NodoArbol<T> *r);

    void inorder(NodoArbol<T> *r);

    void postorder(NodoArbol<T> *r);
};


/**
 * Constructor del Arbol
 * @tparam K Clave por la cual va a ordenar el árbol
 * @tparam T Valor guardado por el árbol
 */
template<class T>
ArbolBinario<T>::ArbolBinario() {
    raiz = nullptr;
}


/**
 * Destructor del Arbol
 */
template<class T>
ArbolBinario<T>::~ArbolBinario() { }


/**
 * Busca un dato en el árbol. Si no esta el dato en el árbol
 * tira una excepción
 * @param clave Valor a buscar
 * @return el valor buscado
 */
template<class T>
T ArbolBinario<T>::search(T dato) {
    return search(dato, raiz);
}

template<class T>
T ArbolBinario<T>::search(T dato, NodoArbol<T> *r) {
		
    /*if (r == nullptr)
        throw 404;

    if (dato == r->getDato())
        return r->getDato();

    if (dato > r->getDato())
        return search(dato, r->getDer());

    if (dato < r->getDato())
        return search(dato, r->getIzq());*/
        
	actual = raiz;

   // Todav�a puede aparecer, ya que quedan nodos por mirar
   while(actual != nullptr) {
      if(dato == actual->getDato()) return actual->getDato(); // dato encontrado
      else if(dato > actual->getDato()) actual = actual->getDer(); // Seguir
      else if(dato < actual->getDato()) actual = actual->getIzq();
   }
   throw 404; // No est� en �rbol
}

/**
 * Agrega un dato al árbol
 * @param clave Clave para agregar el dato
 * @param dato Dato a agregar
 */
template<class T>
void ArbolBinario<T>::put(T dato) {
   NodoArbol<T> *padre = NULL;

   actual = raiz;
   // Buscar el dato en el �rbol, manteniendo un puntero al nodo padre
   while(actual != nullptr && dato != actual->getDato()) {
      padre = actual;
      if(dato > actual->getDato()) actual = actual->getDer();
      else if(dato < actual->getDato()) actual = actual->getIzq();
   }

   // Si se ha encontrado el elemento, regresar sin insertar
   if(actual != nullptr) throw 200;
   // Si padre es NULL, entonces el �rbol estaba vac�o, el nuevo nodo ser�
   // el nodo raiz
   if(padre == nullptr) raiz = new NodoArbol<T>(dato);
   // Si el dato es menor que el que contiene el nodo padre, lo insertamos
   // en la rama izquierda
   else if(dato < padre->getDato()) {
   	  auto *nuevo = new NodoArbol<T>(dato);
   	  nuevo->setPad(padre);
      padre->setIzq(nuevo);
      balance(padre, IZQUIERDO, true);
   }
   // Si el dato es mayor que el que contiene el nodo padre, lo insertamos
   // en la rama derecha
   else if(dato > padre->getDato()) {
      auto *nuevo = new NodoArbol<T>(dato);
      nuevo->setPad(padre);
      padre->setDer(nuevo);
      balance(padre, DERECHO, true);
   }
   /* if(raiz != nullptr)
        put(dato, raiz);
    else
        raiz = new NodoArbol<T>(dato);*/
}

template<class T>
void ArbolBinario<T>::put(T dato, NodoArbol<T> *r) {
    T miDato = r->getDato();

    if(miDato == dato)
        throw 200;

    if(dato > miDato) {
        if(r->getDer() != nullptr) {
            put(dato, r->getDer());
        }else{
            auto *nuevo = new NodoArbol<T>(dato);
            r->setDer(nuevo);            
        }
        balance(r, DERECHO, true);
    }else{
        if (r->getIzq() != nullptr) {
            put(dato, r->getIzq());
        }else{
            auto *nuevo = new NodoArbol<T>(dato);
            r->setIzq(nuevo);            
        }
        balance(r, IZQUIERDO, true);
    }
}

// Equilibrar �rbol AVL partiendo del nodo nuevo
template<class T>
void ArbolBinario<T>::balance(NodoArbol<T> *nodo, int rama, bool nuevo)
{
   bool salir = false;

   // Recorrer camino inverso actualizando valores de FE:
   while(nodo && !salir) {
      if(nuevo)
         if(rama == IZQUIERDO) nodo->FE--; // Depende de si a�adimos ...
         else                  nodo->FE++;
      else
         if(rama == IZQUIERDO) nodo->FE++; // ... o borramos
         else                  nodo->FE--;
      
         
      if(nodo->FE == 0) salir = true; // La altura de las rama que
                                      // empieza en nodo no ha variado,
                                      // salir de Equilibrar      
      else if(nodo->FE == -2) { // Rotar a derechas y salir:
		if(nodo->getIzq() != nullptr){
			if(nodo->getIzq()->FE == 1) RDD(nodo); // Rotaci�n doble
			else RSD(nodo);                         // Rotaci�n simple
		}    
		salir = true;
      }
      else if(nodo->FE == 2) {  // Rotar a izquierdas y salir:
		if(nodo->getDer() != nullptr){
			if(nodo->getDer()->FE == -1) RDI(nodo); // Rotaci�n doble
         	else RSI(nodo);                        // Rotaci�n simple
		}         
        salir = true;
      }
      if(!nuevo && (nodo->FE == 1 || nodo->FE == -1)) salir = true;
      if(nodo->getPad() != nullptr){
      	if(nodo->getPad()->getDer() == nodo) rama = DERECHO; else rama = IZQUIERDO;      	
	  }         
      nodo = nodo->getPad(); // Calcular FE, siguiente nodo del camino.
   }   
}

// Rotaci�n doble a derechas
template<class T>
void ArbolBinario<T>::RDD(NodoArbol<T> *nodo)
{
	cout << "rotamos DD" << endl;
   NodoArbol<T>  *Padre = nodo->getPad();
   NodoArbol<T>  *P = nodo;
   NodoArbol<T>  *Q = P->getIzq();
   NodoArbol<T>  *R = Q->getDer();
   NodoArbol<T>  *B = R->getIzq();
   NodoArbol<T>  *C = R->getDer();

   if(Padre) 
     if(Padre->getDer() == nodo) Padre->setDer(R);
     else Padre->setIzq(R);
   else raiz = R;

   // Reconstruir �rbol:
   Q->setDer(B);
   P->setIzq(C);
   R->setIzq(Q);
   R->setDer(P);
   
   // Reasignar padres:
   R->setPad(Padre);
   P->setPad(Q);
   Q->setPad(R);
   if(B) B->setPad(Q);
   if(C) C->setPad(P);

   // Ajustar valores de FE:
   switch(R->FE) {
      case -1: Q->FE = 0; P->FE = 1; break;
      case 0:  Q->FE = 0; P->FE = 0; break;
      case 1:  Q->FE = -1; P->FE = 0; break;
   }
   R->FE = 0;
}

// Rotaci�n doble a izquierdas
template<class T>
void ArbolBinario<T>::RDI(NodoArbol<T> *nodo)
{
	cout << "rotamos DI" << endl;
   NodoArbol<T>  *Padre = nodo->getPad();
   NodoArbol<T>  *P = nodo;
   NodoArbol<T>  *Q = P->getDer();
   NodoArbol<T>  *R = Q->getIzq();
   NodoArbol<T>  *B = R->getIzq();
   NodoArbol<T>  *C = R->getDer();

   if(Padre)
     if(Padre->getDer() == nodo) Padre->setDer(R);
     else Padre->setIzq(R);
   else raiz = R;

   // Reconstruir �rbol:
   P->setDer(B);
   Q->setIzq(C);
   R->setIzq(P);
   R->setDer(Q);
   
   // Reasignar padres:
   R->setPad(Padre);
   P->setPad(Q);
   Q->setPad(R);
   if(B) B->setPad(P);
   if(C) C->setPad(Q);

   // Ajustar valores de FE:
   switch(R->FE) {
      case -1: P->FE = 0; Q->FE = 1; break;
      case 0:  P->FE = 0; Q->FE = 0; break;
      case 1:  P->FE = -1; Q->FE = 0; break;
   }
   R->FE = 0;
}

// Rotaci�n simple a derechas
template<class T>
void ArbolBinario<T>::RSD(NodoArbol<T> *nodo)
{
	cout << "rotamos SD" << endl;
   NodoArbol<T> *Padre = nodo->getPad();
   NodoArbol<T> *P = nodo;
   NodoArbol<T> *Q = P->getIzq();
   NodoArbol<T> *B = Q->getDer();

   if(Padre)
     if(Padre->getDer() == P) Padre->setDer(Q);
     else Padre->setIzq(Q);
   else raiz = Q;

   // Reconstruir �rbol:
   P->setIzq(B);
   Q->setDer(P);
   
   // Reasignar padres:
   P->setPad(Q);
   if(B) B->setPad(P);
   Q->setPad(Padre);

   // Ajustar valores de FE:
   P->FE = 0;
   Q->FE = 0;
}

// Rotaci�n simple a izquierdas
template<class T>
void ArbolBinario<T>::RSI(NodoArbol<T> *nodo)
{
	cout << "rotamos SI" << endl;
   NodoArbol<T> *Padre = nodo->getPad();
   NodoArbol<T> *P = nodo;
   NodoArbol<T> *Q = P->getDer();
   NodoArbol<T> *B = Q->getIzq();

   if(Padre) 
     if(Padre->getDer() == P) Padre->setDer(Q);
     else Padre->setIzq(Q);
   else raiz = Q;

   // Reconstruir �rbol:
   P->setDer(B);
   Q->setIzq(P);
   
   // Reasignar padres:
   P->setPad(Q);
   if(B) B->setPad(P);
   Q->setPad(Padre);
   
   // Ajustar valores de FE:
   P->FE = 0;
   Q->FE = 0;
}

/**
 * Elimina un dato del árbol
 * @param clave Clave para identificar el nodo a borrar
 */
template<class T>
void ArbolBinario<T>::remove(T dato) {
    raiz = remove(dato, raiz);
}

template<class T>
NodoArbol<T> *ArbolBinario<T>::remove(T dato, NodoArbol<T> *r) {
    if(r == nullptr)
        throw 404;
    if(dato > r->getDato()) {
        r->setDer(remove(dato, r->getDer()));
        return r;
    }
    if(dato < r->getDato()) {
        r->setIzq(remove(dato, r->getIzq()));
        return r;
    }

    NodoArbol<T> *aux;
    if (r->getIzq() != nullptr) {
        if (r->getDer()) {
            put(r->getIzq(), r->getDer());
            aux = r->getDer();
        } else {
            aux = r->getIzq();
        }
    }

    delete r;
    return aux;
}

/**
 * Informa si un árbol esta vacío
 * @return
 */
template<class T>
bool ArbolBinario<T>::esVacio() {
    return (raiz == nullptr);
}


/**
 * Recorre un árbol en preorden
 */
template<class T>
void ArbolBinario<T>::preorder() {
    if (raiz != nullptr)
        preorder(raiz);
}

template<class T>
void ArbolBinario<T>::preorder(NodoArbol<T> *r) {
    cout << r->getDato() << ' ';
    if(r->getIzq() != nullptr)
        preorder(r->getIzq());
    if(r->getDer() != nullptr)
        preorder(r->getDer());
}


/**
 * Recorre un árbol en orden
 */
template<class T>
void ArbolBinario<T>::inorder() {
    if (raiz != nullptr)
        inorder(raiz);
}

template<class T>
void ArbolBinario<T>::inorder(NodoArbol<T> *r) {
    if(r->getIzq() != nullptr)
        inorder(r->getIzq());

    cout << r->getDato() << ' ';

    if(r->getDer() != nullptr)
        inorder(r->getDer());
}

/**
 * Recorre un árbol en postorden
 */
template<class T>
void ArbolBinario<T>::postorder() {
    if (raiz != nullptr)
        postorder(raiz);
}

template<class T>
void ArbolBinario<T>::postorder(NodoArbol<T> *r) {
    if(r->getIzq() != nullptr)
        postorder(r->getIzq());
    if(r->getDer() != nullptr)
        postorder(r->getDer());

    cout << r->getDato() << ' ';
}

/**
 * Muestra un árbol por consola
 */
template<class T>
void ArbolBinario<T>::print() {

}


#endif //ARBOLBINARIO_H
