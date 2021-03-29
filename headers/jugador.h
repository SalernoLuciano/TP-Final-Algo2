#ifndef JUGADOR_H_
#define JUGADOR_H_
#include "controladorPersonaje.h"
#include <cstdlib>
#include <ctime>
#include <limits>

class Jugador {
protected:
	ControladorPersonaje* controladores[3];
	Tablero* tablero;
	Jugador* oponente;

public:
	Jugador();
	//PRE: recibe el numero del jugador
    //POS: imprime la vida, el escudo y la energia de todos los personajes
    void imprimirEstados(int jug);
	// PRE: recibe un vector de punteros ControladoresPersonaje
	// POS: imprime los atributos de los persnajes de los controladores
	void imprimirPersonajes(ControladorPersonaje** cont);
	// PRE: se debe invocar cada vez que un personaje ataque
    // POS: revisa si hay personajes con 0 o menos de vida y fija el controlador
    void matarPersonajes();
	// PRE: recibe un personaje
	// POS: Devuelve la defensa a su atributo original si el
	// personaje era de tierra y se estaba defendiendo
	void detenerDefensa(ControladorPersonaje* cont);
	// PRE: recibe un personaje
	// POS: si es un personaje de aire, recupera energia
	void recuperarEnergia(Personaje* personaje);
	// PRE: recibe el controlador del personaje de agua
	// POS: cura a los personajes si un personaje de agua se defiende
	void curarPersonajes(ControladorPersonaje* cont);
	// PRE: recibe un puntero tablero
	// POS: asigna el tablero al atributo tablero de jugador
	void asignarTablero(Tablero* tablero);
	// PRE: recibe un controlador y un entero
	// POS: Asigna el controlador en el vector controladores en el
	// espacio indicado por el entero (USAR EN CARGAR PARTIDA)
	void asignar_controlador(ControladorPersonaje* controlador, int numPer);
	// PRE: recibe un controlador
	// POS: Asigna el controlador en el primer espacio
	// libre del vector controladores (USAR EN COMENZAR PARTIDA)
	void asignar_controlador(ControladorPersonaje* controlador);
	// PRE: Recibe 3 enteros que indican que opcion se eligio, de que etapa es
	// y el personaje
	// POS: Ejecuta la opcion elegida
    bool procesarOpcion(int opcionElegida, int etapa, int personajeActual);
	// PRE: Recibe un entero que indica el jugador
	// POS: Permite al jugador darle ordenes a sus personajes
    void turno(int actual);
	// PRE: Recibe un puntero a jugador
	// POS: Lo asigna al atributo oponente
	void asignar_rival(Jugador* rival);
	// PRE: Recibe un personaje
	// POS: Si el personaje es de fuego y no tiene energia recibe 5 de daño
	void sinEnergia(Personaje* personaje);
	ControladorPersonaje** devolverControladores();
	~Jugador();

private:
	//PRE: recibe enteros que indican el jugador y el personaje de este
	//POS: imprime las opciones de la primera etapa
    void mostrarOpcionesPrimerEtapa(int jugadorActual, int personajeActual);
	//PRE: recibe enteros que indican el jugador y el personaje de este
	//POS: imprime las opciones de la primera etapa
    void mostrarOpcionesSegudaEtapa(int jugadorActual, int personajeActual);
	//POS: le pide al usuario que ingrese una opcion
    int solicitarOpcion();
	//PRE: Recibe un entero que indica o una fila o una columna
	//POS: Retorna bool si la posicion es valida
    bool verificarPosicion(int ingreso);
};



#endif /* JUGADOR_H_ */
