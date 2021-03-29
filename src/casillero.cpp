#include "../headers/casillero.h"
using namespace std;

Casillero::Casillero(int type){
	up = 0;
	right = 0;
	down = 0;
	left = 0;
	character = 0;
	this->type = type;
}


void Casillero::printCasillero(){
	if(character == 0){
		switch(type){
			case MOUNTAIN:
				cout << "M";
				break;
			case PRECIPICE:
				cout << "U";
				break;
			case VOLCANO:
				cout << "A";
				break;
			case LAKE:
				cout << "O";
				break;
			case ROAD:
				cout << "+";
				break;
			case VOID:
				cout << "X";
				break;
		}
	} else {
		if (character->devolverJugador() == 1){
		    cout << "1" ;
		}
		else{
		    cout << "2";
		}
	}
}

void Casillero::setUp(Casillero* ptr){
	up = ptr;
}

void Casillero::setRight(Casillero* ptr){
	right = ptr;
}

void Casillero::setDown(Casillero* ptr){
	down = ptr;
}

void Casillero::setLeft(Casillero* ptr){
	left = ptr;
}

void Casillero::setCharacter(Personaje* ptr){
	character = ptr;
}

Casillero* Casillero::getUp(){
	return up;
}

Casillero* Casillero::getRight(){
	return right;
}

Casillero* Casillero::getDown(){
	return down;
}

Casillero* Casillero::getLeft(){
	return left;
}

Personaje* Casillero::getCharacter(){
	return character;
}

int Casillero::getType(){
	return type;
}