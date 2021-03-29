#ifndef PILA_H
#define PILA_H

#include <iostream>
using namespace std;
typedef int Info;
const int finPila = 1000;

struct nodo{
    Info info;
    nodo* siguiente;
};

class Pila
{
private:
    nodo* ultimo;

public :
    //PRE: -
    //POS: crea una pila vacía
    Pila();

    //PRE: -
    //POS: agrega un Dato dat
    void agregar(Info i);

    //PRE: pila no vacía
    //POS: elimina el dato de la cima y cambial puntero siguiente
    void eliminar();

    //PRE: pila no vacía
    //POS: muestra toda la pila
    void mostrarPila();

    //PRE: -
    //POS: devuelve el ultimo dato
    Info consulta();

    //PRE: -
    //POS: vacia la lista y libera memoria
    ~Pila();
};


#endif //PILA_H
