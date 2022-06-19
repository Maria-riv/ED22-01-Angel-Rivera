#ifndef LIST_H
#define LIST_H
 
#include <fstream>
#include <iostream>
#include <string>
#include <stdlib.h>
 
#include "Nodo.h"
#include "Nodo.cpp"
 
using namespace std;
 
 
class List
{
    public:
        List();
        ~List();
 
        void add_head(T);
        void add_end(T);
        void del_by_position(int);
        void print();
        void search(T);
 
    private:
        Nodo *m_head;
        int m_num_nodes;
};
 
#endif 