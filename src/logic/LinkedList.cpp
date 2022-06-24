#include "includes/LinkedList.h"

using namespace std;

LinkedList::LinkedList(){
    this->head = nullptr;
    this->num_nodes = 0;
}

void LinkedList::agregar(Persona p){
    Nodo* n = new Nodo(p);
    if(this->head == nullptr){
        this->head = n;
        this->num_nodes++;
    }
    else{
        Nodo* aux = this->head;
        n->setNext(aux);
        this->head = n;
    }
}

int LinkedList::size(){
    return this->num_nodes;
}

Nodo* LinkedList::buscar(int id){
    Nodo* aux = this->head;
    while(aux->getNext() != NULL){
        if(aux->getPersona().getId() == id){
            break;
        }
        aux = aux->getNext();
    }
    return aux;
}

LinkedList::~LinkedList(){
    
}