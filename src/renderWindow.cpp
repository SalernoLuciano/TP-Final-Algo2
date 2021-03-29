#include "../headers/renderWindow.h"

RenderWindow::RenderWindow(){
    window = 0;
    window = SDL_CreateWindow("LA BATALLA DE LOS ELEMENTOS", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 552, 552, SDL_WINDOW_SHOWN);
    if(window == 0){
        cout << "Error al crear ventana: \n" << SDL_GetError() << endl;
    }
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
}

SDL_Texture* RenderWindow::LoadTexture(const char* filePath){
    SDL_Texture* texture = 0;
    texture = IMG_LoadTexture(renderer, filePath);
    if(texture == 0){
        cout << "Fallo al cargar textura";
    }
    return texture;
}

void RenderWindow::clear(){
    SDL_RenderClear(renderer);
}

void RenderWindow::render(SDL_Texture* texture, int fila, int columna){
    SDL_Rect src;
    src.x = 0;
    src.y = 0;
    src.w = 64;
    src.h = 64;
    SDL_Rect dist;
    dist.x = 20 + (64 * columna);
    dist.y = 20 + (64 * fila);
    dist.w = 64;
    dist.h = 64;
    SDL_RenderCopy(renderer, texture, &src, &dist);
}

void RenderWindow::display(){
    SDL_RenderPresent(renderer);
}
SDL_Window* RenderWindow::getWindow(){
    return window;
}

RenderWindow::~RenderWindow(){
    SDL_DestroyWindow(window);
}

