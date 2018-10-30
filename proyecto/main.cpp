//
// Created by alumno on 30/10/18.
//
#include <iostream>
#include <string.h>
#include <fstream>
#include "Arbol/ArbolBinario.h"
#include "par.h"

using namespace std;

int main(int argc, char **argv) {

    ArbolBinario<par> arbol;
    par palabras;
    ifstream diccionario, entrada, salida;
    string linea;

    for(int i = 0;i < argc;i++){
        if(strcmp(argv[i], "-l") == 0)
            diccionario.open(argv[i+1]);
        else if(strcmp(argv[i], "-i") == 0)
            entrada.open(argv[i+1]);
        else if(strcmp(argv[i], "-o") == 0)
            salida.open(argv[i+1]);
    }



    while(getline(diccionario, linea)){
        unsigned long count = linea.find('\t');
        palabras.set(linea.substr(0, count), linea.substr(count, linea.length()));
        arbol.put(palabras);
    }

    //arbol.inorder();

    while(getline(entrada, linea)){
        par busca;
        busca.set(linea, "");

        try{
            cout << arbol.search(busca).getDecodificado() << endl;
        }catch(int e){

        }

    }

    return 0;
}

