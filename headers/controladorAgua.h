#ifndef CONTROLADORAGUA_H
#define CONTROLADORAGUA_H
#include "controladorPersonaje.h"

class ControladorAgua : public ControladorPersonaje{
    private:
        //PRE: -
        //POS: devuelve un bool dependiendo de si existe un personaje oara atacar o no
        bool comprobarPosicon(int posicionAtacada[2]);
    public:
        // POS: Utiliza su defensa, retorna true si tiene exito o false
        // si falla
        bool defensa();
        // PRE: Recibe un vector con los controladores de personaje del oponente
        // POS: realiza su ataque, si tiene exito devuelve true, si falla devuelve false
        bool atacar(ControladorPersonaje** ControladoresEnemigo);
        // PRE: Recibe un puntero a casillero
        // POS: Retorna el costo que supondria moverse a ese casillero
        int evaluarDir(Casillero* dir);
        ControladorAgua(Personaje* personaje, Tablero* tablero);
};

#endif
