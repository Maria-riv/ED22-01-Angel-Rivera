#ifndef LINKEDLIST_H
#define LINKEDLIST_H
 
#include <fstream>
#include <iostream>
#include <string>
#include <stdlib.h>
 
#include "Nodo.h"
 
using namespace std;
 
 
class LinkedList
{
    public:
        LinkedList();
        ~LinkedList();

        void agregar(Persona);
        int size();
        Nodo* buscar(int);
 
    private:
        Nodo *head;
        int num_nodes;
};
 
#endif 