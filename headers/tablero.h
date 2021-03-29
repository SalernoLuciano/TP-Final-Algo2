

#ifndef TABLERO_H_
#define TABLERO_H_
#include <fstream>
#include "graphics.h"
#include "casillero.h"
using namespace std;

const char* const FILE_PATH = "res/mapa.txt";
const int NUM_FILAS = 8;
const int NUM_COLUMNAS = 8;

class Tablero{
	private:
		Casillero* first;
		Graphics graficos;
	public:
		//PRE: recibe un archivo donde se
		// especifica el tipo de cada cacillero
		//POS: crea una fila de nodos
		Casillero* createRow(ifstream &map);
		//PRE: recibe dos filas
		//POS: une las dos filas, la primera es la que esta arriba
		// y la segunda es la que esta abajo
		void linkRows(Casillero* firstPtr, Casillero* lastPtr);
		//POS: Imprime todo el tablero en consol
		void printBoard();
		//POS: muestra el tablero en una ventana aparte con SDL
		void showBoard();
		//PRE: recibe un archivo donde se
		// especifica el tipo de cada cacillero
		//POS: crea los cacilleros del tablero
		void fillBoard(ifstream &map);
		//PRE:
		//POS: devuelve la primera posicion del tablero
		Casillero* returnFirst();
		//PRE: necesita un vector con 2 enteros que marquen las coordenadas (fila/columna)
		//POS: devuelve el casillero en la coordenada ingresada
		Casillero* returnItem(int *coord);
		Tablero();
		~Tablero();
};



#endif /* TABLERO_H_ */
