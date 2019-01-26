#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void sortBubble(int *a, int n) {
    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < n - 1; j++) {
            if(a[j] > a[j+1]) {
                int temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    } 
}

int main() {
    cout << "Ejercicio 08/01\n" << endl;
    srand(time(NULL));
    int a[30];
    cout << "Antes: ";
    for(int i = 0; i < 30; i++) {
        a[i] = rand() % 400 + 100;
        cout << a[i] << ' ';
    }
    sortBubble(a, 30);
    cout << endl << "Despues: ";
    for(int i = 0; i < 30; i++)
        cout << a[i] << ' ';
    cout << endl;
    
    return 0;
}
