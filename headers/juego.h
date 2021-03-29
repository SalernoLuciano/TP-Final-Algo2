#ifndef JUEGO_H
#define JUEGO_H
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <ctime>
#include "jugador.h"
#include "tablero.h"
#include "personaje_fuego.h"
#include "personaje_tierra.h"
#include "personaje_aire.h"
#include "personaje_agua.h"
#include "controladorAire.h"
#include "controladorFuego.h"
#include "controladorTierra.h"
#include "controladorAgua.h"
#include "ABB.h"
using namespace std;

class Juego{
    public:

        // POS: corrre el juego
        void iniciar();
        Juego();
        ~Juego();
    private:

        // PRE: -
        // POS: agrega un nuevo personaje al diccionario.
        void agregarPersonaje();

        // PRE: el diccionario no debe estar vacio.
        // POS: elimina el nodo del ABB que coincida la clave del nodo con el nombre ingresado por teclado.
        void eliminarPersonaje();

        // PRE: -
        // POS: Muestra por pantalla los nombres de los personajes ene le diccionario en orden alfabetico.
        void mostrarPersonajes();

        // PRE: -
        // POS: Muestra por pantalla el detalle de un personaje buscado por teclado.
        void mostrarDetalle();

        // PRE: recibe un entero que indica el jugador
        // POS: permite a un jugador seleccionar un personaje
        // si la seleccion tiene exito devuelve true, y sino devuelve false
        bool seleccionarPersonaje(int numJugador);

        // PRE: recibe un archivo de partida guardada
        // POS: carga la partida
        void cargarPartida(ifstream &partidaGuardada);

        // PRE: recibe un entero que indica el tipo de personaje
        // POS: devuelve un string que indica el tipo de personaje
        string tipoString(int tipo);

        // POS: Muestra el menu donde se agregan, eliminan, o se hacen consultas
        // sobre personajes
        void opcionesPersonaje();
        // POS: Muestra el menu donde se elijen los personajes
        void comenzarJuego();

        //PRE: -
        //POS: devuelve un booleano dependiendo de si el jugador decidio guardar la partida o no
        bool preguntarGuardado(int jugador);

        //PRE: -
        //POS: crea un archivo partida csv con los stats al final de la partida
        void guardarPartida(int jugador);

        //POS: muestra y da a elegir las opciones del juego a cada jugador
        void partida();

        //PRE: -
        //POS: Ubica a los personajes del jugador en el tablero
        void ubicarPersonajes(int jugador);
        //POS: imprime las opciones del menu de agregar/eliminar/consultar personajes
        void imprimirOpcionesPersonajes();
        //POS: imprime el menu de seleccion de personajes
        void imprimirOpcionesComenzar();
        // PRE: recibe un caracter el cual debe ser un numero que indique
        // la cantidad maxima de opciones
        // POS: recibe input y lo retorna 
        char recibirOpcion(char maxOpciones);
        
        // PRE: -
        // POS: Registra un elemento valido para la creacion de un personaje ( AIRE, AGUA, FUEGO, TIERRA )
        void registrarElemento(string &elementoAgregar);

        // PRE: -
        // POS: Devuelve un puntero al nuevo personaje.
        Dato crearPersonaje(string elemento, string nombre);

        // Metodo sobrecargado para crear personajes desde archivo con valores de escudo y vida ya dterminados.
        // PRE: -
        // POS: Devuelve un puntero al nuevo personaje.
        Dato crearPersonaje(string elemento, string nombre, int escudo, int vida);

        // PRE: -
        // POS: lee una cadena ingresada por teclado y la deja con la primer letra de cada palabra en mayusculas.
        void leerCadena(string &cadena);

        // PRE: -
        // POS: Deja la 1° letra de cada palabra de la cadena pasada (nombre) en mayuscula.
        void nombreMayuscula(string &nombre);

        // PRE: El archivo debe pasarse abierto.
        // POS carga todos los personajes en el archivo en el diccionario.
        void procesarArchivo(ifstream &archivo);

        // PRE: el archivo se debe pasar abierto.
        // POS: Almacena 'elemento', 'nombre', 'escudo', y 'vida' en variables y convierte estas ultimas 2 a INT.
        void procesarDatosPersonaje(ifstream &archivo, string &elemento, string &nombre, string &escudo, string &vida, int &escudoEntero, int &vidaEntero);
        
        // PRE: Recibe un entero indicando el jugador, otro indicando el numero de personaje
        // y un personaje para asignarle
        // POS: le asigna el personaje a un controlador, y guarda ese controlador
        // en el vector de controladores del jugador indicado por numJugador
        // en el espacio indicado por numPer (0, 1, 2), si num per es 3 asigna el personaje
        // y su controlador en el primer puntero vacio que encuentre en el vector controladores
        // del jugador
        void asignarPersonaje(int numJugador, int numPer, Personaje* personaje);

        // POS: si la partida no termino devuelve 0, si gano el jugador 1 devuelve 1
        // y si gano el jugador 2 devuelve 2
        int finPartida();

    private:
        //Atributos
        ABB diccionario;
        Tablero tablero;
        Jugador jugadores[2];


        //atributos para cargar partida
        bool partidaCargada;
        int turnoActual;
};

#endif