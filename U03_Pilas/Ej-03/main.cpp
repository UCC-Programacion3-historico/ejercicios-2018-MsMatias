#include <iostream>
#include <string>
#include "../Pila/Pila.h"

using namespace std;

bool balance(Pila<char> *pil);

int main() {
    std::cout << "Ejercicio 03/03\n" << std::endl;
    
    Pila<char> *pila = new Pila<char>();
    string funcion = "{[(12 + 4)*4]+[(4*5)+(5/2)]}";
    
    for(int i = 0; i < funcion.length(); i++)
    	pila->push(funcion[i]);
    	
    cout<< "La funcion matematica esta "<< ((balance(pila)) ? "Balanceada" : "Desbalanceada") << endl;
    
    return 0;
}

bool balance(Pila<char> *pil){
	
	int llaves = 0;
	int corchetes = 0;
	int parentesis = 0;
	
	while(!pil->esVacia()){
		char caracter = pil->pop();
		if(caracter == '{')
			llaves++;
		if(caracter == '}')
			llaves--;
		if(caracter == '[')
			corchetes++;
		if(caracter == ']')
			corchetes--;
		if(caracter == '(')
			parentesis++;
		if(caracter == ')')
			parentesis--;			
	}
	
	if(llaves != 0 || corchetes != 0 || parentesis != 0)
		return false;
		
	return true;
}
