#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void interSort(int *a, int n) {
    for(int i = 1; i < n; i++) {
        for(int j = i; j > 0 and a[j-1] > a[j]; j--) {
            int temp = a[j];
            a[j] = a[j-1];
            a[j-1] = temp;
        }
    } 
}

int main() {
    cout << "Ejercicio 08/02\n" << endl;
    srand(time(NULL));
    int a[30];
    cout << "Antes: ";
    for(int i = 0; i < 30; i++) {
        a[i] = rand() % 400 + 100;
        cout << a[i] << ' ';
    }
    interSort(a, 30);
    cout << endl << "Despues: ";
    for(int i = 0; i < 30; i++)
        cout << a[i] << ' ';
    cout << endl;
    
    return 0;
}
