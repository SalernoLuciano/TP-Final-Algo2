#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "../headers/juego.h"
using namespace std;

// hay que permitir que main reciba argumentos para poder usar SDL
int main(int argc, char **argv){
    Juego nuevo;
    nuevo.iniciar();
    return 0;
}