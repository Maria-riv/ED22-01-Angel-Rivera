#ifndef NODO_H
#define NODO_H

#include <iostream>

#include "Persona.h"

using namespace std;

class Nodo{
    private:
    Persona p;
    Nodo* next;

    public:
    Nodo();
    Nodo(Persona);
    void setNext(Nodo*);
    void setPersona(Persona);
    Persona getPersona();
    Nodo* getNext();
    ~Nodo();

};

#endif