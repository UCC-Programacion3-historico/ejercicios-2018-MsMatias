#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

using namespace std;

void asteriscos(int numero);

int main(int argc, char** argv) {
	
	asteriscos(10);
	
	system("PAUSE");
	return 0;
}

void asteriscos(int numero){
	
	cout<<"*";
	
	numero--;
	
	if(numero > 0)
		asteriscos(numero);
}
