#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void quickSort(int *a, int lb, int ub) {
    if(lb >= ub)
        return;
    int pivote = a[lb];
    int arriba = ub;
    int abajo = lb;
    while(abajo < arriba) {
        while(a[abajo] <= pivote and abajo < ub) abajo++;
        while(a[arriba] > pivote) arriba--;
        if(abajo < arriba) {
            int temp = a[abajo];
            a[abajo]= a[arriba];
            a[arriba] = temp;
        }
    }
    a[lb] = a[arriba];
    a[arriba] = pivote;
    quickSort(a, lb, arriba-1);
    quickSort(a, arriba+1, ub);
}

int main() {
    cout << "Ejercicio 08/03\n" << endl;
    srand(time(NULL));
    int a[30];
    cout << "Antes: ";
    for(int i = 0; i < 30; i++) {
        a[i] = rand() % 400 + 100;
        cout << a[i] << ' ';
    }
    quickSort(a, 0, 30);
    cout << endl << "Despues: ";
    for(int i = 0; i < 30; i++)
        cout << a[i] << ' ';
    cout << endl;
    
    return 0;
}
