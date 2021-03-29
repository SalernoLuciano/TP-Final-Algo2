#include "../headers/pila.h"

Pila::Pila(){
     ultimo = NULL;
}
void Pila::agregar(Info i) {

    nodo* nuevo = new nodo;
    nuevo -> info = i;
    nuevo -> siguiente = ultimo;
    ultimo = nuevo;
}

void Pila::eliminar(){
    if(ultimo != NULL)
    {
        nodo* temporal = ultimo;
        ultimo = ultimo -> siguiente;
        delete temporal;
    }
}

void Pila::mostrarPila()
{
    nodo* temporal = ultimo;
    while(temporal != NULL)
    {
        cout << temporal -> info << endl;
        temporal = temporal -> siguiente;
    }
}

Info Pila::consulta()
{
    Info valor;
    if(ultimo != 0){
        nodo* temporal = ultimo;
        valor = temporal -> info;
    } else{
        valor = finPila;
    }
    return valor;
}


Pila::~Pila()
{
    while(ultimo != NULL)
    {
        nodo* temporal = ultimo;
        ultimo = ultimo -> siguiente;
        delete temporal;
    }
}
