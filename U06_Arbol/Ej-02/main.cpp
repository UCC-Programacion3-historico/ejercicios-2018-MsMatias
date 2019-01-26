#include <iostream>
#include "../Arbol/ArbolBinario.h"

using namespace std;


int main() {
    int apre[9] = {2,5,3,9,7,1,6,4,8};
    int ain[9] = {9,3,7,5,1,2,6,8,4}; 
    int bin[13] = {5,6,12,10,1,9,13,4,8,2,7,3,11};
    int bpost[13] = {6,5,10,9,1,13,12,2,8,3,11,7,4};

    ArbolBinario<int> *a = new ArbolBinario<int>();
    a->put(apre[0]);
    //a->buildArbolInPre(ain, apre);
    ArbolBinario<int> *b = new ArbolBinario<int>();
    //b->put(bpost[12]);
    b->buildArbolInPost(bin, bpost, 13);

    cout << "Ejercicio 05/02\n" << endl;

    cout << "A preorden: ";
    a->preorder();
    cout << endl;

    cout << "A inorden: ";
    a->inorder();
    cout << endl;

    cout << "A postorden*: ";
    a->postorder();
    cout << endl << endl;

    cout << "B preorden*: ";
    b->preorder();
    cout << endl;

    cout << "B inorden: ";
    b->inorder();
    cout << endl;

    cout << "B postorden: ";
    b->postorder();
    cout << endl;

    return 0;
}
