//
// Created by alumno on 30/10/18.
//

#ifndef PROYECTO_PAR_H
#define PROYECTO_PAR_H

#include <iostream>
#include <string.h>

using namespace std;

class par {

private:
    string codificado;
    string decodificado;

public:
    par(){};
    void set(string _codificado, string _decodificado){ codificado = _codificado; decodificado = _decodificado;};
    string getCodificado();
    string getDecodificado();
    bool operator == (const par &p);
    bool operator != (const par &p);
    bool operator > (const par &p);
    bool operator < (const par &p);
    bool operator >= (const par &p);
    bool operator <= (const par &p);

};

string par::getCodificado(){
    return codificado;
}

string par::getDecodificado(){
    return decodificado;
}

bool par::operator != (const par &p){
    return codificado != p.codificado;
}


bool par::operator == (const par &p){
    return codificado == p.codificado;
}

bool par::operator > (const par &p){
    return codificado > p.codificado;
}

bool par::operator < (const par &p){
    return codificado < p.codificado;
}

bool par::operator >= (const par &p){
    return codificado >= p.codificado;
}

bool par::operator <= (const par &p){
    return codificado <= p.codificado;
}


#endif //PROYECTO_PAR_H
