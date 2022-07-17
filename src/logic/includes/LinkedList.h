#ifndef LIST_H
#define LIST_H

#include <iostream>
#include "Nodo.h"

// Clase de la lista enlazada 
class LinkedList{
    // metodos de la lista enlazada
    private:
    Nodo* head; // nodo cabezal
    int size; // total de nodos de la lista

    public:
    LinkedList(); // constructor
    void add(Persona p); // añadir persona
    Persona get(int id); // obtener una persona en relacion a su id
    bool isEmpty(); // verificar si la lista esta vacia
    void actualizar(Persona p);// actualizar la persona segun el nodo en donde se encuentre

};


#endif // LIST_H