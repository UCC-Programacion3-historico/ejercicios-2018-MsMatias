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
    par palabras, busca;
    ifstream diccionario, entrada;
    string linea, palabra = "", salida;

    for(int i = 0;i < argc;i++){
        if(strcmp(argv[i], "-l") == 0)
            diccionario.open(argv[i+1]);
        else if(strcmp(argv[i], "-i") == 0)
            entrada.open(argv[i+1]);
        else if(strcmp(argv[i], "-o") == 0)
            salida = argv[i+1];
    }



    while(getline(diccionario, linea)){
        unsigned long count = linea.find('\t');
        palabras.set(linea.substr(0, count), linea.substr(count, linea.length()));
        arbol.put(palabras);
    }

    std::ofstream outfile (salida);

    char aux;
    while (entrada >> aux){
        if((aux > 64 && aux < 91))
            aux += 32;

        if(aux > 96 && aux < 123){
            palabra += aux;
        }

        busca.set(palabra, "");
        try{
            outfile << arbol.search(busca).getDecodificado();
        }catch(int e){

        }
    }

    outfile.close();

    return 0;
}

