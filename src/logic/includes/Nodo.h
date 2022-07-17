#ifndef NODO_H
#define NODO_H

#include <iostream>

#include "Persona.h"

using namespace std;
//Clase nodo que almacena una persona
class Nodo{
    private:
    Persona p;//objeto persona
    Nodo* next; // nodo siguiente

    public:
    Nodo();// contructor sin parametros
    Nodo(Persona);  // constructor con persona de parametro
    void setNext(Nodo*);
    void setPersona(Persona);
    Persona getPersona();
    Nodo* getNext();
    ~Nodo();

};

#endif