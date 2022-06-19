#include "includes/LinkedList.h"
#include "includes/Nodo.h"

#include "Nodo.cpp"

using namespace std;
 

LinkedList::LinkedList()
{
    num_nodes = 0;
    head = NULL;
}


void LinkedList::add_head(T data)
{
    Nodo *new_node = new Nodo (data_);
    Nodo *temp = m_head;
 
    if (!m_head) {
        m_head = new_node;
    } else {
        new_node->next = m_head;
        m_head = new_node;
 
        while (temp) {
            temp = temp->next;
        }
    }
    m_num_nodes++;
}
 


void LinkedList::add_end(T data_)
{
    Nodp *new_node = new Nodo (data_);
    Nodo *temp = m_head;
 
    if (!m_head) {
        m_head = new_node;
    } else {
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
    }
    m_num_nodes++;
}


// Eliminar por posición del nodo
template<typename T>
void Linkedlist::del_by_position(int pos)
{
    Nodo *temp = m_head;
    Nodo *temp1 = temp->next;
 
    if (pos < 1 || pos > m_num_nodes) {
        cout << "Fuera de rango " << endl;
    } else if (pos == 1) {
        m_head = temp->next;
    } else {
        for (int i = 2; i <= pos; i++) {
            if (i == pos) {
                Node<T> *aux_node = temp1;
                temp->next = temp1->next;
                delete aux_node;
                m_num_nodes--;
            }
            temp = temp->next;
            temp1 = temp1->next;
        }
    }
}
void LinkedList::print()
{
    Nodo *temp = m_head;
    if (!m_head) {
        cout << "La Lista está vacía " << endl;
    } else {
        while (temp) {
            temp->print();
            if (!temp->next) cout << "NULL";
                temp = temp->next;
        }
  }
  cout << endl << endl;
}
 
// Buscar el dato de un nodo
void Linkedlist::search(T data_)
{
    Nodo *temp = m_head;
    int cont = 1;
    int cont2 = 0;
 
    while (temp) {
        if (temp->data == data_) {
            cout << "El dato se encuentra en la posición: " << cont << endl;
            cont2++;
        }
        temp = temp->next;
        cont++;
    }
 
    if (cont2 == 0) {
        cout << "No existe el dato " << endl;
    }
    cout << endl << endl;
}
 
// Ordenar de manera ascendente

void LinkedList::sort()
{
    Nodo temp;
    Nodo *aux_node = m_head;
    Nodo *temp = aux_node;
 
    while (aux_node) {
        temp = aux_node;
 
        while (temp->next) {
            temp = temp->next;
 
            if (aux_node->data > temp->data) {
                temp_data = aux_node->data;
                aux_node->data = temp->data;
                temp->data = temp_data;
            }
        }
 
        aux_node = aux_node->next;
    }
}
 

LinkedList::~LinkedList() {}