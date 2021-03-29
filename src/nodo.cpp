#include "../headers/nodo.h"

Nodo::Nodo(Dato d) {
    dato = d;
    cambiarClave(d->obtenerNombre());
    izquierdo = nullptr;
    derecho = nullptr;
    padre = nullptr;
}

void Nodo::cambiarClave(string nuevaClave){
    if(clave != nuevaClave)
        clave = nuevaClave;
}

void Nodo::cambiarDato(Dato nuevo) {
    dato = nuevo;
    cambiarClave(nuevo->obtenerNombre());
}

void Nodo::cambiarIzquierdo(Nodo* izq, Nodo* nuevoPadre) {
    this->izquierdo = izq;
    izquierdo->cambiarPadre(nuevoPadre);
}

void Nodo::cambiarIzquierdo(Nodo* izq) {
    izquierdo = izq;
}

void Nodo::cambiarDerecho(Nodo* der, Nodo* nuevoPadre) {
    derecho = der;
    derecho->cambiarPadre(nuevoPadre);
}

void Nodo::cambiarDerecho(Nodo* der) {
    derecho = der;
}

void Nodo::cambiarPadre(Nodo *nuevoPadre) {
    this->padre = nuevoPadre;
}

string Nodo::obtenerClave(){
    return clave;
}

Dato Nodo::obtenerDato() {
    return dato;
}

Nodo* Nodo::obtenerIzquierdo() {
    return izquierdo;
}

Nodo* Nodo::obtenerDerecho() {
    return derecho;
}

Nodo* Nodo::obtenerPadre() {
    return padre;
}

bool Nodo::esHoja() {
    return !(obtenerIzquierdo() || obtenerDerecho());
}

bool Nodo::soloHijoDerecho() {
    return ((!obtenerIzquierdo()) && obtenerDerecho());
}

bool Nodo::soloHijoIzquierdo() {
    return (obtenerIzquierdo() && (!obtenerDerecho()));
}

void  Nodo::borrarPersonaje() {
    delete dato;
}

Nodo::~Nodo() {
    borrarPersonaje();
}
