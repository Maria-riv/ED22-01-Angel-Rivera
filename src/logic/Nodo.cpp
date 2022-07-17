#include "includes/Nodo.h"
// contructor con parametro objeto persona
Nodo::Nodo(Persona per){
    this->p = per;
    this->next = NULL;
};
//get y set de los atributos
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
