#include "../headers/controladorAire.h"



int ControladorAire::evaluarDir(Casillero* dir){
    int valor = 0;
    int tipo = dir->getType();
    switch(tipo){
        case MOUNTAIN:
            valor = 2;
            break;
        case VOID:
            valor = 15;
            break;
        case ROAD:
            valor = 1;
            break;
        case PRECIPICE:
            valor = 0;
            break;
        case LAKE:
            valor = 1;
            break;
        case VOLCANO:
            valor = 1;
            break;
    }
    return valor; 
}

bool ControladorAire::atacar(ControladorPersonaje** ControladoresEnemigo){
    system("clear");
    if(personaje->obtenerEnergia() >= ATAQUE_AIRE){
        personaje->restarEnergia(ATAQUE_AIRE);
        for(int i = 0; i < 3; i++){
            if(ControladoresEnemigo[i] != 0){
                (ControladoresEnemigo[i]->devolverPersonaje())->recibirAtaque("aire",0);
            }
        }
        return true;
    }else{
        cout << "No posee suficiente energia para atacar." << endl;
        return false;
    }
}

bool ControladorAire::defensa() {
	bool seDefiende = personaje->defender();
    bool ubicar = false;
	if (seDefiende){
		while ( !ubicar ) {
            cout << "Ingrese la ubicacion donde se movera: " << endl;
            cout << "Fila: " ;
            cin >> ubicacion[0];
            cout << "" << endl;
            while (ubicacion[0] > 8 || ubicacion[0] < 1  ){
                cout << "Ingrese un valor valido" << endl;
                cout << "Fila: " ;
                cin >> ubicacion[0];
                cout << "" << endl;
            }
            cout << "Columna: ";
            cin >> ubicacion[1];
            cout << "" << endl;
            while (ubicacion[1] > 8 || ubicacion[1] < 1  ){
                cout << "Ingrese la ubicacion donde se movera: " << endl;
                cout << "Fila: " ;
                cin >> ubicacion[1];
                cout << "" << endl;
            }
            ptrCasillero->setCharacter(0);
            ubicar = ubicarPersonaje(ubicacion);
        }
        system("clear");
        cout << personaje->obtenerNombre() << " utilizo defensa y volo a otra zona del mapa" << endl;
	} else {
        cout << personaje->obtenerNombre() <<" no cuenta con la energía necesaria para defenderse"<<endl;
    }
    tablero->showBoard();
    return seDefiende;
}

ControladorAire::ControladorAire(Personaje* personaje, Tablero* tablero) {
	this->personaje = personaje;
    this->tablero = tablero;
    for(int i = 0; i<2; i++){ubicacion[i] = 0;};
    ptrCasillero = 0;
}
