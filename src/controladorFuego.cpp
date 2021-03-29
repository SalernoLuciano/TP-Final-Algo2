#include "../headers/controladorFuego.h"



int ControladorFuego::evaluarDir(Casillero* dir){
    int valor = 0;
    int tipo = dir->getType();
    switch(tipo){
        case MOUNTAIN:
            valor = 1;
            break;
        case VOID:
            valor = 15;
            break;
        case ROAD:
            valor = 1;
            break;
        case PRECIPICE:
            valor = 1;
            break;
        case LAKE:
            valor = 2;
            break;
        case VOLCANO:
            valor = 0;
            break;
    }
    return valor; 
}

bool ControladorFuego::atacar(ControladorPersonaje** ControladoresEnemigo){
    system("clear");
    if(this->personaje->obtenerEnergia() >= ATAQUE_FUEGO){
        this->personaje->restarEnergia(ATAQUE_FUEGO);
        for(int i = 0; i < 3; i++) {
            if(ControladoresEnemigo[i] != 0){
                if ((ControladoresEnemigo[i]->devolverUbicacion())[0] == this->ubicacion[0] || (ControladoresEnemigo[i]->devolverUbicacion())[0] == this->ubicacion[0] + 1 || (ControladoresEnemigo[i]->devolverUbicacion()[0] == this->ubicacion[0] - 1)){
                    ControladoresEnemigo[i]->devolverPersonaje()->recibirAtaque("fuego",0);
                }
            }
        }
        return true;
    }else{
        cout << "No posee suficiente energia para atacar." << endl;
        return false;
    }
}

ControladorFuego::ControladorFuego(Personaje* personaje, Tablero* tablero) {
	this->personaje = personaje;
    this->tablero = tablero;
    for(int i = 0; i<2; i++){ubicacion[i] = 0;};
    ptrCasillero = 0;
}

bool ControladorFuego::defensa(){
    return personaje->defender();
}