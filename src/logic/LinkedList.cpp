#include "includes/LinkedList.h"

LinkedList::LinkedList(){
    head = nullptr;
    size = 0;
};

bool LinkedList::isEmpty(){
    return head == nullptr;
}

void LinkedList::add(Persona p){
    Nodo* newNodo = new Nodo(p);
    if(this->isEmpty()){
        head = newNodo;
    }
    else{
        Nodo* current = head;
        while(current->getNext()){
            current = current->getNext();
        }
        current->setNext(newNodo);
    }
}

Persona LinkedList::get(int id){
    Nodo* current = head;
    Persona p = Persona();
    while(current->getNext()){
        if(current->getPersona().getId() == id){
            p = current->getPersona();
        }
    }
    return p;
}

void LinkedList::actualizar(Persona p){
    Nodo* current = head;
    while(current->getNext()){
        if(current->getPersona().getId() == p.getId()){
            current->setPersona(p);
        }
    }
}