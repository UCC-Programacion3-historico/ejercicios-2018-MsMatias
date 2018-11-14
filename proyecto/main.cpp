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

    par busca, palabras;
    ifstream diccionario, entrada;
    string linea, palabra, salida;
    unsigned char aux;
    bool mayuscula = false;
    string sOut, simbolo;

    auto *arbol = new ArbolBinario<par>;
    
    entrada >> noskipws;

    for(int i = 0;i < argc;i++) {
        if (strcmp(argv[i], "-l") == 0) {
            diccionario.open(argv[i + 1]);
        } else if (strcmp(argv[i], "-i") == 0) {
            entrada.open(argv[i + 1]);
        } else if (strcmp(argv[i], "-o") == 0) {
            salida = argv[i + 1];
        }
    }
    
    while(getline(diccionario, linea)){
        unsigned long count = linea.find('\t');
        palabras.set(linea.substr(0, count), linea.substr(count+1, linea.length()));
        arbol->put(palabras);
    }

    std::ofstream outfile (salida);

    while (entrada >> aux){
        try{
		
        	if(aux <= 90 && aux >= 65 || aux == 193 || aux == 201 || aux == 205 || aux == 211 || aux == 218) {
                aux += 32;
                mayuscula = true;
            }
            				
        	if((aux <= 122 && aux >= 97) || aux == 225 || aux == 233 || aux == 237 || aux == 243 || aux == 250){
            	palabra += aux;
        	}else{
        	    if(palabra != "") {
                    busca.set(palabra, "");                    
                    sOut = arbol->search(busca).getDecodificado();
                    if (mayuscula) {
                        if((sOut[0] <= 122 && sOut[0] >= 97) || sOut[0] == 225 || sOut[0] == 233 || sOut[0] == 237 || sOut[0] == 243 || sOut[0] == 250) {
                            sOut[0] = (char) (sOut[0] - 32);
                        }
                        mayuscula = false;
                    }
                    outfile << sOut;
                    palabra = "";
                }
                outfile << aux;
			}		            
        }catch(int e){
        	sOut = palabra;
        	outfile << sOut;
        	if (mayuscula) {
				if((sOut[0] <= 122 && sOut[0] >= 97) || sOut[0] == 225 || sOut[0] == 233 || sOut[0] == 237 || sOut[0] == 243 || sOut[0] == 250) {
					sOut[0] = (char) (sOut[0] - 32);
				}
				mayuscula = false;
            }
        	outfile << aux;
        	palabra = "";
        }
    }

    outfile.close();

    return 0;
}

