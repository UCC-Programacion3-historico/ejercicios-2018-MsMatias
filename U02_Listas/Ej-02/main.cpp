#include <iostream>
#include "../Lista/Lista.h"

using namespace std;

int main() {
    std::cout << "Ejercicio 01/02\n" << std::endl;
    
    Lista<int> *lista = new Lista<int>();
    int opcion = 0;
    int numero = 0;
    int pos = 0;
    
    do{
	    
   	 cout<<" 1 - Agregar al principio"<< endl;
   	 cout<<" 2 - Agregar al medio"<< endl;
   	 cout<<" 3 - Agregar al final"<< endl;
   	 cout<<" 4 - imprimir lista"<< endl;
   	 cout<<" 0 - Salir"<< endl;
         
   	 cin>>opcion;
	 system("CLS");
		if(opcion > 0 && opcion < 4){
   			cout<<"Ingrese el numero a agregar: ";
			cin>>numero;
			if(opcion == 1){
				lista->insertarPrimero(numero);
				cout<<"Se inserto al principio"<<endl;
			}else if(opcion == 2){
				pos = lista->getTamanio() / 2;
				lista->insertar(pos, numero);
				cout<<"Se inserto al medio"<<endl;
			}else if(opcion == 3){
				lista->insertarUltimo(numero);
				cout<<"Se inserto al ultimo"<<endl;
			}
		}else if(opcion == 4){
			cout<<"Lista; "<< *lista<<endl;
		}		
	}while(opcion);
    
    system("PAUSE");
    return 0;
}
