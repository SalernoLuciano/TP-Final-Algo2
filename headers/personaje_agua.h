#ifndef ESCRITORIO_PERSONAJE_AGUA_H
#define ESCRITORIO_PERSONAJE_AGUA_H

#include "personaje.h"

const int ALIMENTO_AGUA = 10;
const int LIMITE_ALIMENTACION = 3;
const int ATAQUE_AGUA = 5;
const int DEFENSA_AGUA = 12;

class PersonajeAgua : public Personaje{

private:
    // Atributos.
    int vecesAlimentado;

public:
    // Metodos.

    // Constructor.
    // PRE: -
    // POS: Crea un personaje de tipo Agua con herencia en la clase 'Personaje'. Con un nombre, escudo y vida asignado por el usuario, un valor de energia generado aleatoriamente, 'vecesAlimentado = 0 y 'elemento' = Agua.
    PersonajeAgua(string nombre, int escudo, int vida);

    // PRE: -
    // POS: aumenta el valor del atributo 'energia' en 10 puntos si 'energia' <= 10 ó deja 'energia' = 20 si 'energia' > 10.
    bool alimentar();


    //PRE: -
    //POS: resta vida
    void recibirAtaque(string tipo, int casosTierra);

    //PRE: -
    //POS: energia - 12 & vida + 50 (los otros personajes del jugador tambien recibiran 10 de vida)
    bool defender();

    //POS: Retorna entero que indica el tipo
    int devolverTipo();

    //PRE:
    //POS: Retorna la cantidad de veces que fue alimentado el perosnaje
    int obtenerAlimentos();

    //PRE: recibe un entero
    //POS: asigna ese entero a la variable vecesAlimentado(solo sera utilizado en el caso de agua)
    void asignarAlimentos(int cant);
};


#endif //ESCRITORIO_PERSONAJE_AGUA_H
