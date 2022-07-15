#ifndef LIST_H
#define LIST_H

#include <iostream>
#include "Nodo.h"


class LinkedList{
    private:
    Nodo* head;
    int size;

    public:
    LinkedList();
    void add(Persona p);
    Persona get(int id);
    bool isEmpty();
    void actualizar(Persona p);

};


#endif // LIST_H