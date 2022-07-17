#include "includes/LinkedList.h"
// constructor de la linkedList 
LinkedList::LinkedList(){
    head = nullptr;
    size = 0;
};
// verifica si la lista enlazada esta vacia
bool LinkedList::isEmpty(){
    return head == nullptr;
}
// Metodo que añade a una persona
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
// Metodo que obtiene a una persona segun su identificador
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
//Se busca una persona y se actualiza en el nodo correspondiente
void LinkedList::actualizar(Persona p){
    Nodo* current = head;
    while(current->getNext()){
        if(current->getPersona().getId() == p.getId()){
            current->setPersona(p);
        }
    }
}