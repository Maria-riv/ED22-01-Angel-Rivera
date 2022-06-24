#include "includes/Nodo.h"

Nodo::Nodo(Persona per){
    this->p = per;
    this->next = NULL;
};

Nodo* Nodo::getNext(){
    return this->next;
}

Persona Nodo::getPersona(){
    return this->p;
}

void Nodo::setNext(Nodo* n){
    this->next = n;
}

void Nodo::setPersona(Persona per){
    this->p = per;
}
