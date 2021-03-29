#include "../headers/personaje_agua.h"
#include <iostream>

PersonajeAgua::PersonajeAgua(string nombre, int escudo, int vida) : Personaje(nombre, escudo, vida){
    vecesAlimentado = 0;
}

bool PersonajeAgua::alimentar() {
    int energiaInicial;
    int energiaFinal;
    if(vecesAlimentado == LIMITE_ALIMENTACION){
        cout << "ATENCION!!!. " << obtenerNombre() << " no puede alimentarse mas." << endl;
        return false;
    }
    if(vecesAlimentado < LIMITE_ALIMENTACION && energia < MAX_ENERGIA) {
        energiaInicial = obtenerEnergia();
        if(energia + ALIMENTO_AGUA > MAX_ENERGIA){
            energia = MAX_ENERGIA;
            energiaFinal = obtenerEnergia();
        }else{
            energia += ALIMENTO_AGUA;
            energiaFinal = obtenerEnergia();
        }
        vecesAlimentado++;
        std::cout << obtenerNombre() << " se alimenta de Plancton. Recuperó: " << energiaFinal - energiaInicial << " puntos de energia." << std::endl;
        return true;
    }else{
        std::cout << obtenerNombre() << " llego al maximo posible de energia." << std::endl;
        return false;
    }

}

void PersonajeAgua::recibirAtaque(string tipo, int casosTierra) {
    int danio;
    if (tipo == "agua"){
        danio = 20 - (obtenerEscudo() * 200 / 100);
    }
    else if (tipo == "aire"){
        danio = 15 - (obtenerEscudo() * 150 / 100);
    }
    else if (tipo == "fuego"){
        danio = 10 - (obtenerEscudo() * 100 / 100);
    }
    else if (tipo == "tierra"){
        switch(casosTierra){
            case 1: danio = 50 - (obtenerEscudo() * 500 / 100);
                break;
            case 2: danio = 40 - (obtenerEscudo() * 400 / 100);
                break;
            case 3: danio = 30 - (obtenerEscudo() * 300 / 100);
                break;
        }
    }
    vida -= danio;
    cout<<"El personaje "<< obtenerNombre() <<" recibió un daño de "<< danio <<endl;
}

bool PersonajeAgua::defender(){
    int vidaInicial = vida, vidaFinal;
    if (obtenerEnergia() >= DEFENSA_AGUA && obtenerVida() <= MAX_VIDA){
        restarEnergia(DEFENSA_AGUA);
        if (obtenerVida() + 50 > MAX_VIDA){
            vida = MAX_VIDA;
        }
        else{
            vida += 50;
        }
        vidaFinal = vida;
        cout << "El personaje " << obtenerNombre() << " utilizó defensa y se curo " << vidaFinal - vidaInicial << " puntos de vida" <<endl;
        return true;
    }
    else if (obtenerEnergia() < DEFENSA_AGUA){
        cout << "El personaje " << obtenerNombre() << " no cuenta con la energia necesaria para defenderse" << endl;
        return false;
    }
    else{
        cout << "El personaje " << obtenerNombre ()<< " ya tiene su vida al máximo" << endl;
        return false;
    }
}

int PersonajeAgua::devolverTipo(){
    return TIPO_AGUA;
}

int PersonajeAgua::obtenerAlimentos() {
    return vecesAlimentado;
}

void PersonajeAgua::asignarAlimentos(int cant){
    vecesAlimentado = cant;
}