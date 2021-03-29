#ifndef PERSONAJE_AIRE_H_INCLUDED
#define PERSONAJE_AIRE_H_INCLUDED

#include "personaje.h"
const int ATAQUE_AIRE = 8;
const int DEFENSA_AIRE = 15;

class PersonajeAire: public Personaje{

    // Atributos.

public:
    // Metodos.

    // Constructor.
    // PRE: -
    // POS: Crea un personaje de tipo Aire con herencia en la clase 'Personaje'. Con un nombre, escudo y vida asignado por el usuario, un valor de energia generado aleatoriamente y 'elemento' = Aire.
    PersonajeAire(string nombre, int escudo, int vida);


    // PRE: -
    // POS: No realiza ninguna accion ya que 'Aire' no se alimenta, pero hereda de 'Personaje' el metodo virtual 'alimentar'.
    bool alimentar();

    // PRE: -
    // POS: resta vida
    void recibirAtaque(string tipo, int casosTierra);

    //PRE: -
    //POS: energia - 15
    bool defender();

    //POS: Retorna entero que indica el tipo
    int devolverTipo();

    //PRE: recibe un entero
    //POS: lo asigna al atributo vecesAlimentado
    void asignarAlimentos(int cant);
    //POS: retorna vecesAlimentado
    int obtenerAlimentos();

};

#endif