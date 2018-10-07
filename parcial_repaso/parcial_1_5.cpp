#include <iostream>
#include <string.h>
#include "../U03_Pilas/Pila/Pila.h"

using namespace std;

int main() {
    std::cout << "Ejercicio 03/01\n" << std::endl;
    
    string texto;
    Pila<char> *pila = new Pila<char>();
    
    cout<<"Ingrese el texto deseado: ";
    
    getline(cin, texto);
    
   	for(int i = 0; i < texto.length(); i++){
    	pila->push(texto[i]); 
	}
	
	for(int i = texto.length(); i > 0; i--){
		cout << pila->pop();
	}
    
    return 0;
}
