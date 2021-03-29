#include "../headers/assetManager.h"


AssetManager::AssetManager(){
    for(int i = 0; i < CANT_ASSETS; i++){
        assets[i] = 0;
    }
}

void AssetManager::storeAsset(SDL_Texture* texture, int pos){
    assets[pos] = texture;
}

SDL_Texture* AssetManager::getAsset(int pos){
    return assets[pos];
}

SDL_Texture* AssetManager::getTerrainTexture(int type){
    SDL_Texture* aux;
    switch (type)
    {
    case MOUNTAIN:
        aux = assets[MOUNTAIN_TEXTURE];
        break;
    case LAKE:
        aux = assets[LAKE_TEXTURE];
        break;
    case VOLCANO:
        aux = assets[VOLCANO_TEXTURE];
        break;
    case VOID:
        aux = assets[VOID_TEXTURE];
        break;
    case ROAD:
        aux = assets[ROAD_TEXTURE];
        break;
    case PRECIPICE:
        aux = assets[PRECIPICE_TEXTURE];
        break;
    default:
        aux = 0;
        break;
    }
    return aux;
}

SDL_Texture* AssetManager::getCharacterTexture(int numJugador, int tipoPer){
    SDL_Texture* auxTexture;
    switch(numJugador){
        case 1:
            switch(tipoPer){
                case TIPO_AGUA:
                    auxTexture = assets[PLAYER1_WATER];
                    break;
                case TIPO_AIRE:
                    auxTexture = assets[PLAYER1_AIR];
                    break;
                case TIPO_FUEGO:
                    auxTexture = assets[PLAYER1_FIRE];
                    break;
                case TIPO_TIERRA:
                    auxTexture = assets[PLAYER1_EARTH];
                    break;
            }
            break;
        case 2:
            switch(tipoPer){
                case TIPO_AGUA:
                    auxTexture = assets[PLAYER2_WATER];
                    break;
                case TIPO_AIRE:
                    auxTexture = assets[PLAYER2_AIR];
                    break;
                case TIPO_FUEGO:
                    auxTexture = assets[PLAYER2_FIRE];
                    break;
                case TIPO_TIERRA:
                    auxTexture = assets[PLAYER2_EARTH];
                    break;
            }
            break;
    }
    return auxTexture;
}


AssetManager::~AssetManager(){
    for(int i = 0; i < CANT_ASSETS; i++){
        if(assets[i] != 0){
            SDL_DestroyTexture(assets[i]);
        }
    }
}