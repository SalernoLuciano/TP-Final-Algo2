#include "../headers/personaje_fuego.h"
#include <iostream>

PersonajeFuego::PersonajeFuego(string nombre, int escudo, int vida): Personaje(nombre, escudo, vida) {
    cantMadera = rand() % 5;
}

void PersonajeFuego::recargarVida(){
    if(obtenerVida() + ALIMENTO_FUEGO > MAX_VIDA)
        vida = MAX_VIDA;
    else
        vida += ALIMENTO_FUEGO;
    cantMadera--;
}

void PersonajeFuego::recargarEnergia() {
    if(obtenerEnergia() + ALIMENTO_FUEGO_ENERGIA > MAX_ENERGIA){
        energia = MAX_ENERGIA;
    }
    else{
        energia += ALIMENTO_FUEGO_ENERGIA;
    }
}


bool PersonajeFuego::alimentar() {
    int vidaInicial = obtenerVida();
    int vidaFinal;
    int energiaInicial = obtenerEnergia();
    int energiaFinal;
    if(tieneMadera()){
        recargarVida();
        vidaFinal = obtenerVida();
        recargarEnergia();
        energiaFinal = obtenerEnergia();
        std::cout << obtenerNombre() << " se alimenta de madera. Recupero " << vidaFinal - vidaInicial << " puntos de vida";
        std::cout << " Y " << energiaFinal - energiaInicial  << " puntos de energía." << std::endl;
        return true;
    }else{
        std::cout << obtenerNombre() << " no tiene suficiente madera para alimentarse. Su vida es: " << obtenerVida() << " y su energía es: "<< obtenerEnergia() <<std::endl;
        return false;
    }
}

bool PersonajeFuego::tieneMadera() {
    return (cantMadera > 0);
}

void PersonajeFuego::recibirAtaque(string tipo, int casosTierra) {
    int danio = 0;
    if (tipo == "agua"){
        danio = 30 - (obtenerEscudo() * 300 / 100);
    }
    else if (tipo == "aire"){
        danio = 15 - (obtenerEscudo() * 150 / 100);
    }
    else if (tipo == "fuego"){
        danio = 20 - (obtenerEscudo() * 200 / 100);
    }
    else if (tipo == "tierra"){
        switch(casosTierra){
            case 1: danio = 30 - (obtenerEscudo() * 300 / 100);
                break;
            case 2: danio = 20 - (obtenerEscudo() * 200 / 100);
                break;
            case 3: danio = 10 - (obtenerEscudo() * 100 / 100);
                break;
        }
    }
    vida -= danio;
    cout<<"El personaje "<< obtenerNombre() <<" recibió un daño de "<< danio <<endl;
}

bool PersonajeFuego::defender(){
    int vidaInicial;
    int vidaFinal;
    if (obtenerEnergia() >= 10){
        energia -= 10;
        vidaInicial = vida;
        vida += 10;
        vidaFinal = vida;
        cout<<"El personaje "<< obtenerNombre() <<" utilizo defensa. Perdio 10 puntos de energia y se curo " << vidaFinal - vidaInicial << " puntos de vida" <<endl;
        return true;
    }
    else{
        cout<<"El personaje "<< obtenerNombre() <<" no cuenta con la energía suficiente para utilizar su defensa"<<endl;
        return false;
    }
}

int PersonajeFuego::devolverTipo(){
    return TIPO_FUEGO;
}

int PersonajeFuego::obtenerAlimentos() {
    return 0;
}

void PersonajeFuego::asignarAlimentos(int cant){}