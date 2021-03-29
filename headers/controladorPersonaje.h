#ifndef CONTROLADORPERSONAJE_H
#define CONTROLADORPERSONAJE_H
#include <cstdlib>
#include <unistd.h>
#include "pila.h"
#include "tablero.h"
#include "personaje_agua.h"
#include "personaje_fuego.h"
#include "personaje_aire.h"
#include "personaje_tierra.h"

enum opciones1{
    //etapa 1
    ALIMENTARSE = 1,
    MOVERSE = 2,
    //etapa 2
    ATACAR = 1,
    DEFENDERSE = 2,
    // en ambas
    PASAR = 3,
};

enum direcciones{
    ARRIBA = 1,
    DERECHA = 2,
    ABAJO = 3,
    IZQUIERDA = 4,
};

class ControladorPersonaje
{
    protected:
        Personaje* personaje;
        Casillero* ptrCasillero;
        Tablero* tablero;
        int ubicacion[2];
        int costo[64];
        int anterior[64];
        // PRE: Recibe un puntero casillero
        // POS: Devuelve el coste que supondria moverse a ese casillero
        virtual int evaluarDir(Casillero* dir) = 0;
    public:
        ControladorPersonaje();
        // PRE:
        // POS: Busca los caminos minimos
        void encontrarCaminos();
        //PRE:
        //POS: devuelve un ptr con la ubicacion del personaje
        int* devolverUbicacion();
        //PRE:
        //POS: devuelve el casillero donde se encuentra el personaje
        Casillero* devolverCasillero();
        //PRE:
        //POS: devuelve puntero a personaje
        Personaje* devolverPersonaje();
        // PRE: recibe las coordenadas del destino
        // POS: lo mueve a esa posicion si tiene la energia suficiente
        bool moverse(int *destino);
        // PRE: recibe una posicion del tablero (fila/columna)
        // POS: ubica el personaje en la posicion indicada
        // Retorna false si no lo puede ubicar
        // (SOLO USAR AL PRINCIPIO DE LA PARTIDA)
        bool ubicarPersonaje(int* destino);
        // PRE: Recibe un vector con los controladores de personaje del oponente
        // POS: realiza su ataque, si tiene exito devuelve true, si falla devuelve false
        virtual bool atacar(ControladorPersonaje** ControladoresEnemigo) = 0;
        // POS: Utiliza su defensa, retorna true si tiene exito o false
        // si falla
        virtual bool defensa() = 0;
        //POS: cura al personaje
        void se_curo();
        //Pos: reinicia el escudo del personaje a su valor original
        void reiniciar_escudo();
        //POS: devuelve un entero dependiendo de si el personaje defendio o no
        int conocerDefensa();
        virtual ~ControladorPersonaje();
    private:
        // POS: Evalua el coste de los nodos circundantes y guarda su en costo[]
        // y su identificador anterior[]
        void evaluarNodos(int currentID, bool* visto, Casillero* current);
        // PRE: Recibe una coordenada
        // POS: Devuelve un identificador
        int coordToId(int *coord);
        // PRE: Recibe un identificador y una cordenada
        // POS: Crea una coordenada a partir del identificador
        // y la guarda en la coordenada ingresada
        void idToCoord(int ID, int* coord);
        // PRE: Recibe un vector de booleanos que indique por que nodos ya se paso
        // POS: Devuelve el identificador del grafo con menor coste y que no haya sido
        // visitado
        int buscarMinimo(bool* visto);

};

#endif
