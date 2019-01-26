#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void shellSort(int *a, int n) {
    for (int k = n/2; k > 0; k /= 2) { 
        for (int i = k; i < n; i++) { 
            int temp = a[i]; 
            int j;
            for (j = i; j >= k and a[j - k] > temp; j -= k) 
                a[j] = a[j - k]; 
            a[j] = temp; 
        } 
    }
}

int main() {
    cout << "Ejercicio 08/04\n" << endl;
    srand(time(NULL));
    int a[30];
    cout << "Antes: ";
    for(int i = 0; i < 30; i++) {
        a[i] = rand() % 400 + 100;
        cout << a[i] << ' ';
    }
    shellSort(a, 30);
    cout << endl << "Despues: ";
    for(int i = 0; i < 30; i++)
        cout << a[i] << ' ';
    cout << endl;
    
    return 0;
}
