#include "../headers/tablero.h"


void Tablero::printBoard(){
	Casillero* current;
	Casillero* below;
	below = first;
	while(below != 0){
		current = below;
		below = current->getDown();
		while(current != 0){
			current->printCasillero();
			cout << " ";
			current = current->getRight();
		}
		cout << "\n";
	}
}

Casillero* Tablero::createRow(ifstream &map){
		Casillero* newFirst;
		Casillero* current = 0;
		Casillero* last = 0;
		int tipo = 0;
		map >> tipo;
		newFirst = new Casillero(tipo);
		last = newFirst;
		for(int i = 0; i < NUM_COLUMNAS -1; i++){
			map >> tipo;
			current = new Casillero(tipo);
			last->setRight(current);
			current->setLeft(last);
			last = current;
		}
		return newFirst;
}

void Tablero::linkRows(Casillero* firstPtr, Casillero* lastPtr){
	for(int i = 0; i < NUM_COLUMNAS; i++){
		firstPtr->setDown(lastPtr);
		lastPtr->setUp(firstPtr);
		firstPtr = firstPtr->getRight();
		lastPtr = lastPtr->getRight();
	}
}


Tablero::Tablero(){
	first = 0;
	ifstream map(FILE_PATH);
	if(!map.fail()){
		fillBoard(map);
	} else {
		cout << "Error al abrir el archivo de mapa" <<endl << endl;
	}
	map.close();
}

void Tablero::fillBoard(ifstream &map){
	Casillero* lastRow = 0;
	Casillero* currentRow = 0;
	first = createRow(map);
	lastRow = first;
	for(int i = 0; i < NUM_FILAS -1; i++){
		currentRow = createRow(map);
		linkRows(lastRow, currentRow);
		lastRow = currentRow;
	}
}

Casillero* Tablero::returnFirst(){
	return first;
}

Casillero* Tablero::returnItem(int *coord){
	Casillero* aux;
	aux = first;
	for(int i = 0; i < coord[0] - 1; i++){
		aux = aux->getDown();
	}
	for(int i = 0; i < coord[1] - 1; i++){
		aux = aux->getRight();
	}
	return aux;
}

Tablero::~Tablero(){
	Casillero* current;
	Casillero* below;
	Casillero* del;
	below = first;
	while(below != 0){
		current = below;
		below = current->getDown();
		while(current != 0){
			del = current;
			current = current->getRight();
			delete del;
		}
	}
}

void Tablero::showBoard(){
	graficos.windowClear();
    SDL_Texture* auxTexture = 0;
    Casillero* current;
	Casillero* below;
    int fila = 0;
    int columna = 0;
	below = first;
	while(below != 0){
		current = below;
		below = current->getDown();
		while(current != 0){
			Personaje* auxPer = current->getCharacter();
			auxTexture = graficos.getTerrainTexture(current->getType());
			graficos.renderTexture(auxTexture, fila, columna);
			if(auxPer != 0){
				auxTexture = graficos.getCharacterTexture(auxPer->devolverJugador(), auxPer->devolverTipo());
				graficos.renderTexture(auxTexture, fila, columna);
			}
			current = current->getRight();
            columna++;
		}
        columna = 0;
        fila++;
	}
    graficos.display();
}