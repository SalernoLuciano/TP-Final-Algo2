#ifndef SDLINIT_H
#define SDLINIT_H
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
using namespace std;

class SdlInit{
    public:
        // POS: inicializa SDL
        SdlInit();
        // POS: cierra SDL
        ~SdlInit();
};

#endif