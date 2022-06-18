#ifndef NODO_H
#define NODO_H

#include <iostream>

#include "Persona.h"

using namespace std;

class Nodo{
    private:
    int id;
    int contador;
    Persona p;
    Nodo* next;

    public:
    Nodo();
    Nodo(Persona);
    void setId(int);
    void setContador(int);
    void setNext(Nodo*);
    void setPersona(Persona);
    int getId();
    int getContador();
    Persona getPersona();
    Nodo* getNext();
    ~Nodo();

};

#endif