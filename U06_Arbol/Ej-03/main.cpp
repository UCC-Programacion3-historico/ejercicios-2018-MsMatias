#include <iostream>
#include "../Arbol/ArbolBinario.h"
#include <ctime>
#include <cstdlib>
#include <vector>

using namespace std;

bool find(vector<int> &buf, int v) {
    for(int i = 0; i < buf.size(); i++) {
        if(buf[i] == v)
            return true;
    }
    return false;
}

int main() {
    ArbolBinario<int> *a = new ArbolBinario<int>();
    srand(time(NULL));
    //A buffer to make sure no duplicate numbers are added to the tree
    vector<int> buf;
    for(int i = 0; i < 25; i++) {
        int num = rand() % 4000 + 200;
        //Gets a new number if a duplicate is detected
        if(find(buf, num)) {
            i--;
            continue;
        }
        buf.push_back(num);
        a->put(num);
    }

    cout << "Ejercicio 05/03\n" << endl;

    for(int i = 0; i < 10; i++)
        cout << "Nivel " << i << ": " << a->contarPorNivel(i) << endl;

    return 0;
}
