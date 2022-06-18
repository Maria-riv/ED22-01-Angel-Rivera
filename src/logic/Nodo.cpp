#include "includes/Nodo.h"

Nodo::Nodo(Persona per){
    this->p = per;
    this->contador = 0;
    this->id = 0;
    this->next = NULL;
};

int Nodo::getContador(){
    return this->contador;
}

int Nodo::getId(){
    return this->id;
}

Nodo* Nodo::getNext(){
    return this->next;
}

Persona Nodo::getPersona(){
    return this->p;
}

void Nodo::setContador(int cont){
    this->contador = cont;
    
}