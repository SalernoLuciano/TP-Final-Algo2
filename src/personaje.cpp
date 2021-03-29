#include "../headers/personaje.h"
#include <iostream>

using namespace std;

Personaje::Personaje(string nombre, int escudo, int vida) {
    this->nombre = nombre;
    this->escudo = escudo;
    this->vida = vida;
    jugador = 0;
    seleccionado = false;
    estaDefendiendo = false;
    asignarEnergia();
}

bool Personaje::getEstaDefendiendo(){
    return estaDefendiendo;
}

void Personaje::setEstaDefendiendo(){
    estaDefendiendo = true;
}

void Personaje::asignarJugador(int jug){
    jugador = jug;
}

int Personaje::devolverJugador(){
    return jugador;
}

void Personaje::asignarEnergia(){
    energia  = rand() % 20 +1;
}

string Personaje::obtenerNombre(){
    return nombre;
}

int Personaje::obtenerEscudo() {
    return escudo;
}

int Personaje::obtenerVida() {
    return vida;
}

int Personaje::obtenerEnergia() {
    return energia;
}

void Personaje::restarEnergia(int puntos) {
    energia -= puntos;
}

void Personaje::curar() {
	vida += 10;
    cout << nombre << " se curo 10 puntos de vida" << endl;
}

void Personaje::bajar_escudo() {
	escudo -= 2;
    estaDefendiendo = false;
    cout << nombre << " dejo de defenderse, su escudo se reducio en 2 puntos" << endl;
}

void Personaje::perder_vida() {
	vida -= 5;
}

void Personaje::mostrarAtributos() {
    cout << "--------------------------" << endl
         << "Nombre: " << obtenerNombre() << endl
         << "Escudo: " << obtenerEscudo() << endl
         << "Vida: " << obtenerVida() << endl
         << "Energia: " << obtenerEnergia() << endl
         << "--------------------------" << endl;
}

bool Personaje::estaSeleccionado(){
    return seleccionado;
}

void Personaje::seleccionar(){
    seleccionado = true;
}

void Personaje::recuperarEnergia(){
    int cambio = energia;
    energia += 5;
    if(energia > 20){
        energia = 20;
    }
    cambio = energia - cambio;
    cout << nombre << " recupero " << cambio << " de energia." << endl;
}

void Personaje::asignarVida(int num){
    this->vida = num;
}

Personaje::~Personaje(){}
