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

        void agregar(Nodo*);
        int size();
        Nodo* buscar();
 
    private:
        Nodo *head;
        int num_nodes;
};
 
#endif 