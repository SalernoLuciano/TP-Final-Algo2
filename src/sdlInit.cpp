#include "../headers/sdlInit.h"

SdlInit::SdlInit(){
    if(SDL_Init(SDL_INIT_VIDEO) < 0){
        cout << "Inicializacion de video fallo: \n\n" << SDL_GetError() << endl;
    }
    if(SDL_Init(IMG_INIT_PNG) < 0){
        cout << "Inicializacion formato png fallo: " << SDL_GetError() << endl;
    }
}

SdlInit::~SdlInit(){
    IMG_Quit();
    SDL_Quit();
}

