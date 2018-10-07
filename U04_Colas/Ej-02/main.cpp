#include <iostream>
#include <string>
#include "../Pila/Pila.h"
#include "../Cola/Cola.h"

using namespace std;

bool palindromo(string texto);

int main() {
    std::cout << "Ejercicio 04/02\n" << std::endl;
    
    string texto = "la ruta nos aporto otro paso natural";
    
     cout << "El texto " << ((palindromo(texto)) ? "" : "no") << " es palindromo" << endl;
    
    return 0;
}

bool palindromo(string texto){
	Pila<char> *pila = new Pila<char>();
    Cola<char> *cola = new Cola<char>();
    
    for(int i = 0; i < texto.length(); i++){
    	if(tolower(texto[i]) > 'a' && tolower(texto[i]) < 'z'){
    		pila->push(tolower(texto[i]));
    		cola->encolar(tolower(texto[i]));
		}
	}
	
	while(!pila->esVacia() && !cola->esVacia()){
    	if(pila->pop() != cola->desencolar())
    		return false;
	}
	
	return true;
}
