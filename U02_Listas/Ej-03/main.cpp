#include <iostream>
#include "../Lista/Lista.h"

using namespace std;

int main() {
    std::cout << "Ejercicio 01/03\n" << std::endl;
    
    int pos = 0;
    
    Lista<int> *lista = new Lista<int>();
    for(int i = 1; i < 20; i++)
		lista->insertarUltimo(i);
		
	cout << "Lista: " << *lista << endl;
	
	while(1){
	
		do{
    		cout<<"Indique cual elemento borrar: ";
 		   	cin>>pos;
	    	system("CLS");
    	
	    	if(pos == -1)
	    		return 0;
    		
		}while(pos > lista->getTamanio());
	
		cout<<"Se elimino el elemento "<< pos <<endl;
		cout << "Lista original: " << *lista << endl;
		lista->remover(pos);
		cout << "Lista nueva: " << *lista << endl;
	
	}
	
	system("PAUSE");    
    return 0;
}
