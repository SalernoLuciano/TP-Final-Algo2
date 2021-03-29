#ifndef ESCRITORIO_PERSONAJE_FUEGO_H
#define ESCRITORIO_PERSONAJE_FUEGO_H

#include "personaje.h"

const int ALIMENTO_FUEGO = 5;
const int ALIMENTO_FUEGO_ENERGIA = 10;
const int ATAQUE_FUEGO = 5;

class PersonajeFuego : public Personaje {
private:

    int cantMadera;

public:
    // Metodos.

    // Constructor.
    // PRE: -
    // POS: Crea un personaje de tipo Fuego con herencia en la clase 'Personaje'. Con un nombre, escudo y vida asignado por el usuario y un valor de energia, cantMadera generados aleatoriamente y 'elemento' = Fuego.
    PersonajeFuego(string nombre, int escudo, int vida);

    // PRE: -
    // POS: Si tiene madera le recarga la vida el valor que determina el metodo 'recargarVida' y la energia que determina el metodo 'recargarEnergia', si no tiene madera no hace nada.
    bool alimentar();

    // PRE: -
    // POS: resta vida
    void recibirAtaque(string tipo, int casosTierra);

    //PRE: -
    //POS: energia - 10 & vida + 10
    bool defender();

    //POS: Retorna entero que indica el tipo
    int devolverTipo();

    //No se usa en esta clase
    int obtenerAlimentos();
    //No se usa en esta clase
    void asignarAlimentos(int cant);
private:

    // PRE: -
    // POS: Retorna 'True' si 'cantMadera' > 0, 'False' si es = 0 o menor.
    bool tieneMadera();

    // PRE: -
    // POS: le aumenta 5 puntos de vida si 'vida' <= 95, sino aumenta la vida a 100.
    void recargarVida();

    //PRE:-
    //POS: aumenta 10 puntos de energia si energia <= 10, sino aumenta energia a 20
    void recargarEnergia();

};


#endif //ESCRITORIO_PERSONAJE_FUEGO_H
