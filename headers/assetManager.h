#ifndef ASSETMANAGER_H
#define ASSETMANAGER_H
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "casillero.h"

const int CANT_ASSETS = 14;
enum texturas{
    LAKE_TEXTURE = 0,
    MOUNTAIN_TEXTURE = 1,
    PRECIPICE_TEXTURE = 2,
    ROAD_TEXTURE = 3,
    VOID_TEXTURE = 4,
    VOLCANO_TEXTURE = 5,
    PLAYER1_WATER = 6,
    PLAYER1_AIR = 7,
    PLAYER1_FIRE = 8,
    PLAYER1_EARTH = 9,
    PLAYER2_WATER = 10,
    PLAYER2_AIR = 11,
    PLAYER2_FIRE = 12,
    PLAYER2_EARTH = 13,
};

class AssetManager{
    public:
        AssetManager();
        //PRE: Recibe una textura y un entero que indica donde en el vector guardarla
        //POS: Guarda una textura en el vector assets
        void storeAsset(SDL_Texture* texture, int pos);
        //PRE: Recibe un entero que indica la posicion
        //POS: Devuelve el asset en esa posicion
        SDL_Texture* getAsset(int pos);
        //PRE: recibe un entero que indica el tipo de terreno o personaje
        //POS: devuelve la textura correspondiente
        SDL_Texture* getTerrainTexture(int type);
        //PRE: Recibe dos enteros, uno indica el numero de jugador y el otro el elemento
        // del personaje
        //POS: Retorna la textura del personaje de ese elemento y jugador
        SDL_Texture* getCharacterTexture(int numJugador, int tipoPer);
        ~AssetManager();
    private:
        SDL_Texture* assets[CANT_ASSETS];
};

#endif