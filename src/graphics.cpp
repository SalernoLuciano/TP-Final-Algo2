#include "../headers/graphics.h"

Graphics::Graphics(){
    loadAssets();
}

void Graphics::loadAssets(){
    assets.storeAsset(window.LoadTexture("res/lake.png"), LAKE_TEXTURE);
    assets.storeAsset(window.LoadTexture("res/mountain.png"), MOUNTAIN_TEXTURE);
    assets.storeAsset(window.LoadTexture("res/precipice.png"), PRECIPICE_TEXTURE);
    assets.storeAsset(window.LoadTexture("res/road.png"), ROAD_TEXTURE);
    assets.storeAsset(window.LoadTexture("res/void.png"), VOID_TEXTURE);
    assets.storeAsset(window.LoadTexture("res/volcano.png"), VOLCANO_TEXTURE);
    assets.storeAsset(window.LoadTexture("res/personaje1Agua.png"), PLAYER1_WATER);
    assets.storeAsset(window.LoadTexture("res/personaje1Aire.png"), PLAYER1_AIR);
    assets.storeAsset(window.LoadTexture("res/personaje1Fuego.png"), PLAYER1_FIRE);
    assets.storeAsset(window.LoadTexture("res/personaje1Tierra.png"), PLAYER1_EARTH);
    assets.storeAsset(window.LoadTexture("res/personaje2Agua.png"), PLAYER2_WATER);
    assets.storeAsset(window.LoadTexture("res/personaje2Aire.png"), PLAYER2_AIR);
    assets.storeAsset(window.LoadTexture("res/personaje2Fuego.png"), PLAYER2_FIRE);
    assets.storeAsset(window.LoadTexture("res/personaje2Tierra.png"), PLAYER2_EARTH);
}


void Graphics::windowClear(){
    window.clear();
}

SDL_Texture* Graphics::getTerrainTexture(int tipo){
    return assets.getTerrainTexture(tipo);
}

SDL_Texture* Graphics::getCharacterTexture(int numJugador, int tipoPer){
    return assets.getCharacterTexture(numJugador, tipoPer);
}

void Graphics::renderTexture(SDL_Texture* textura, int fila, int columna){
    window.render(textura, fila, columna);
}

void Graphics::display(){
    window.display();
}

