#ifndef ESCRITORIO_PERSONAJE_TIERRA_H
#define ESCRITORIO_PERSONAJE_TIERRA_H

#include "personaje.h"

const int ALIMENTO_TIERRA = 8;

class PersonajeTierra : public Personaje {

    // Atributos.

public:
    // Metodos.

    // Constructor.
    // PRE: -
    // POS: Crea un personaje de tipo Tierra con herencia en la clase 'Personaje'.
    PersonajeTierra(string nombre, int escudo, int vida);

    // PRE: -
    // POS: Si 'energia' <= 12 -> 'energia' + 8. sino 'energia' = 20.
    bool alimentar();

    //PRE:
    //POS: resta vida
    void recibirAtaque(string tipo, int casosTierra);

    //PRE:
    //POS: escudo + 2 & energia - 5
    bool defender();

    //POS: Retorna entero que indica el tipo
    int devolverTipo();

    //No se usa en esta clase
    void asignarAlimentos(int cant);
    //No se usa en esta clase
    int obtenerAlimentos();
};

#endif //ESCRITORIO_PERSONAJE_TIERRA_H
