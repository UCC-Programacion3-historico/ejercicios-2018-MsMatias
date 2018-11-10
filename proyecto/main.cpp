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
    
    entrada >> noskipws;

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
        palabras.set(linea.substr(0, count), linea.substr(count+1, linea.length()));
        arbol.put(palabras);
    }

    std::ofstream outfile (salida);

    char aux;
    while (entrada >> aux){        
        try{
        	
        	if(aux == 181)
    			aux = 160;
    		
    		if(aux == 144)
    			aux = 130;
    		
    		if(aux == 214)
    			aux = 161;
    	
    		if(aux == 224)
    			aux = 162;
    		
    		if(aux == 233)
    			aux = 163;
    	
        	if(aux <= 90 && aux >= 65)
            	aux += 32;
            	
        	if((aux <= 122 && aux >= 97) || aux == 160 || aux == 130 || aux == 161 || aux == 162 || aux == 163){        		
            	palabra += aux;
        	}else{		
        		busca.set(palabra, "");
        		outfile << arbol.search(busca).getDecodificado() << aux ;	
        		palabra = "";
			}
		            
        }catch(int e){

        }
    }

    outfile.close();

    return 0;
}

