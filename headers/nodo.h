#ifndef NODO_H_INCLUDED
#define NODO_H_INCLUDED

#include "personaje.h"
#include <string>

typedef Personaje* Dato;

class Nodo {
private:
    // Atributos.
    string clave;
    Dato dato;
    Nodo* izquierdo;
    Nodo* derecho;
    Nodo* padre;

public:
    // Metodos Publicos.

    // Constructor.
    // PRE: -
    // POS: Crea un nodo con dato = d, cambiarClave(d->obtenerNombre()) [cambia 'clave' por el nombre de 'd', izquierdo = derecho = 0,
    Nodo(Dato d);

    // PRE: -
    // POS: Reemplaza el dato del nodo por d ( dato = d ), ademas actualiza la clave del nodo con el nombre del nuevo 'dato'
    void cambiarDato(Dato nuevo);

    // PRE: -
    // POS: Deja al nodo 'izquierdo' apuntando al nodo 'izq' ( izquierdo = izq). 'izquierdo' sera un antecesor al actual.
    void cambiarIzquierdo(Nodo* izq, Nodo* nuevoPadre);

    // PRE: -
    // POS: Deja al nodo 'izquierdo' apuntando al nodo 'izq' ( izquierdo = izq). 'izquierdo' sera un antecesor al actual.
    void cambiarIzquierdo(Nodo* izq);

    // PRE: -
    // POS: Deja al nodo 'derecho' apuntando al nodo 'der' ( derecho = der). 'derecho' sera un sucesor mayor al actual.
    void cambiarDerecho(Nodo* der, Nodo* nuevoPadre);

    // PRE: -
    // POS: Deja al nodo 'derecho' apuntando al nodo 'der' ( derecho = der). 'derecho' sera un sucesor mayor al actual.
    void cambiarDerecho(Nodo* der);

    // PRE: -
    // POS: Deja al nodo 'padre' apuntando a 'nuevoPadre'.
    void cambiarPadre(Nodo* nuevoPadre);

    // PRE: -
    // POS: Devuelve la clave del nodo ( return clave | return this->clave )
    string obtenerClave();

    // PRE: -
    // POS: Retorna el dato del nodo ( return dato | return this->dato).
    Dato obtenerDato();

    // PRE: -
    // POS: Retorna el nodo 'izquierdo' o NULL.
    Nodo* obtenerIzquierdo();

    // PRE: -
    // POS: Retorna el nodo 'derecho' o NULL.
    Nodo* obtenerDerecho();

    // PRE: -
    // POS: Retorna el nodo 'padre' o NULL.
    Nodo* obtenerPadre();

    // PRE: -
    // POS: Devuelve TRUE si 'izquierdo' y 'derecho' = NULL, FALSE en caso contrario.
    bool esHoja();

    // PRE: -
    // POS: Devuelve true si derecho!= nullptr && izquierdo == nullptr, en otro caso devuelve false.
    bool soloHijoDerecho();

    // PRE: -
    // POS: Devuelve true si izquierdo!= nullptr && derecho == nullptr, en otro caso devuelve false.
    bool soloHijoIzquierdo();

    // PRE: -
    // POS: Libera memoria del personaje 'dato'
    void borrarPersonaje();

    ~Nodo();//Destructor

private:
	//Metodos Privados.

	// PRE: -
    // POS: Chequea si el nombre de la clave coincide con el nombre de 'nuevaClave' ( si no coincide clave es reemplazado por 'nuevaClave' )
    void cambiarClave(string nuevaClave);

};

#endif // NODO_H_INCLUDED
