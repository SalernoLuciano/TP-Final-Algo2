#ifndef RENDERWINDOW_H
#define RENDERWINDOW_H
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
using namespace std;

class RenderWindow{
    private:
        SDL_Window* window;
        SDL_Renderer* renderer;
    public:
        RenderWindow();
        // PRE:
        // POS: Devuelve la ventana
        SDL_Window* getWindow();
        // PRE: Recibe un array de caracteres que indica el path de la imagen
        // POS: Carga la imagen en una variable SDL_Texture* y la devuelve
        SDL_Texture* LoadTexture(const char* filePath);
        // POS: vacia la ventana SDL
        void clear();
        // PRE: Recibe una textura y la fila y columna donde debe mostrarse
        // POS: Ubica la textura en la ventana (para que se vea hay que actualizarla)
        void render(SDL_Texture* texture, int fila, int columna);
        // POS: Actualiza la ventana
        void display();
        ~RenderWindow();
};


#endif