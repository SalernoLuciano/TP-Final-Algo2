#ifndef GRAPHICS_H
#define GRAPHICS_H
#include "sdlInit.h"
#include "renderWindow.h"
#include "assetManager.h"
#include "casillero.h"


class Graphics{
    public:
        //POS: limpia la ventana SDL
        void windowClear();
        //PRE: Recibe un entero que indica el tipo de terreno del casillero
        //POS: Retorna una textura del terreno de ese tipo
        SDL_Texture* getTerrainTexture(int tipo);
        //PRE: Recibe dos enteros, uno indica el numero de jugador y el otro el elemento
        // del personaje
        //POS: Retorna la textura del personaje de ese elemento y jugador
        SDL_Texture* getCharacterTexture(int numJugador, int tipoPer);
        //PRE: Recibe una textura, y 2 enteros que indican la fila y la columna
        //POS: renderiza la textura en esa ubicacion del tablero grafico
        void renderTexture(SDL_Texture* textura, int fila, int columna);
        //POS: Actualiza la ventana
        void display();
        Graphics();
    private:
        //POS: Carga y guarda las texturas en el objeto assets
        void loadAssets();
    private:
        //Atributos
        SdlInit init;
        RenderWindow window;
        AssetManager assets;
};

#endif