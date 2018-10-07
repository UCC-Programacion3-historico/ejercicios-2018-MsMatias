#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

using namespace std;

void imparesMenores(int numero);

int main(int argc, char** argv) {
	
	imparesMenores(7);
	
	system("PAUSE");
	return 0;
}

void imparesMenores(int numero){
	
	if(numero%2 == 0)
		numero -= 1;
	else
		numero -= 2;
	
	cout << "impar menor: "<< numero << endl;
	
	if(numero > 1)
		imparesMenores(numero);
}
S
