#include "../headers/juego.h"

Juego::Juego(){
    jugadores[0].asignar_rival(&jugadores[1]);
    jugadores[1].asignar_rival(&jugadores[0]);
    for(int i = 0; i < 2; i++){
        jugadores[i].asignarTablero(&tablero);
    }
    ifstream partidaGuardada("res/partida.csv");
    system("clear");
    if(partidaGuardada.fail()){
        partidaGuardada.close();
        cout << "No se encontro una partida guardada." << endl;
        partidaCargada = false;
        turnoActual = 0;
        ifstream archivo("res/personajes.csv");
        if(archivo.is_open()){
            procesarArchivo(archivo);
            archivo.close();
        } else {
            cout << "fallo al abrir archivo de personajes";
        }
    } else{
        cout << "Se encontro una partida guardada." << endl;
        cargarPartida(partidaGuardada);
        partidaCargada = true;
        partidaGuardada.close();
    }
    srand(time(0));
}

void Juego::cargarPartida(ifstream &partidaGuardada){
    int primerJugadorEntero = 0, escudoEntero, vidaEntero, energiaEntero;
    int tipoEntero, filaEntero, columnaEntero, extraEntero;
    int ubicacion[2];
    string primerJugador, nombre, escudo, vida, energia, tipo, fila, columna, extra;
    Personaje* aux;
    getline(partidaGuardada, primerJugador, '\n');
    primerJugadorEntero = stoi(primerJugador);
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 3; j++){
            getline(partidaGuardada, tipo, ',');
            if(tipo != "0"){
                getline(partidaGuardada, nombre, ',');
                getline(partidaGuardada, escudo, ',');
                getline(partidaGuardada, vida, ',');
                getline(partidaGuardada, energia, ',');
                getline(partidaGuardada, fila, ',');
                getline(partidaGuardada, columna, ',');
                getline(partidaGuardada, extra, '\n');
                escudoEntero = stoi(escudo);
                vidaEntero = stoi(vida);
                extraEntero = stoi(extra);
                ubicacion[0] = stoi(fila);
                ubicacion[1] = stoi(columna);
                aux = crearPersonaje(tipo, nombre, escudoEntero, vidaEntero);
                diccionario.insertarHoja(aux);
                if(tipo == "Tierra"){
                    if(extraEntero == 1){
                        aux->setEstaDefendiendo();
                    }
                } else if(tipo == "Agua"){
                    aux->asignarAlimentos(extraEntero);
                }
                asignarPersonaje(i, j, aux);
                aux->asignarJugador(i + 1);
                jugadores[i].devolverControladores()[j]->ubicarPersonaje(ubicacion);
            } else {
                jugadores[i].devolverControladores()[j] = 0;
                getline(partidaGuardada, tipo, '\n');
            }
        }
    }
    turnoActual = primerJugadorEntero - 1;
}


void Juego::iniciar(){
    if(partidaCargada){
        // si hay partida guardada
        partida();
    } else {
        // si no hay partida guardada
        opcionesPersonaje();
    }
}

char Juego::recibirOpcion(char maxOpciones){
    char opcion;
    bool salir = false;
    cout << "Ingrese una opcion: ";
    cin >> opcion;
    cin.clear();
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    while(opcion < '1' || opcion > maxOpciones){
        cout << "Ingrese una opcion valida: ";
        cin >> opcion;
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    return opcion;
}

void Juego::imprimirOpcionesPersonajes(){
    cout << "----------BATALLA DE LOS ELEMENTOS----------" << endl;
    cout <<"Bienvenido al juego" << endl;
    cout << "Opciones: " << endl;
    cout << "1. Agregar nuevo personaje" << endl;
    cout << "2. Eliminar personaje" << endl;
    cout << "3. Mostrar todos los personajes" << endl;
    cout << "4. Buscar detalles de un personaje" << endl;
    cout << "5. Comenzar Juego" << endl;
    cout << "6. Salir" << endl;
}

void Juego::imprimirOpcionesComenzar(){
    cout << "----------BATALLA DE LOS ELEMENTOS----------" << endl;
    cout <<"Bienvenido al juego" << endl;
    cout << "Opciones: " << endl;
    cout << "1. Buscar personaje en particular" << endl;
    cout << "2. Mostrar los nombres de todos los personajes" << endl;
    cout << "3. Seleccionar personaje" << endl;
    cout << "4. Salir " << endl;
};

void Juego::opcionesPersonaje(){
    bool salir = false;
    char opcion;
    while(!salir){
        imprimirOpcionesPersonajes();
        opcion = recibirOpcion('6');
        switch (opcion)
        {
        case '1':
            agregarPersonaje();
            break;
        case '2':
            eliminarPersonaje();
            break;
        case '3':
            mostrarPersonajes();
            break;
        case '4':
            mostrarDetalle();
            break;
        case '5':
            comenzarJuego();
            salir = true;
            break;
        case '6':
            salir = true;
            break;
        }
    }
}

void Juego::mostrarDetalle() {
    string nombreBuscado;
    Nodo* encontrado;
    cout << "\tMOSTRAR DETALLE DE PERSONAJE." << endl <<
         "Ingrese el nombre del personaje a buscar en el diccionario: ";
    leerCadena(nombreBuscado);
    encontrado = diccionario.buscarPersonaje(nombreBuscado);
    while(!encontrado){
        cout << "\tEl personaje que intenta buscar NO existe." << endl
             << "Estos son los personajes disponibles: " << endl;
        mostrarPersonajes();
        cout << "Ingrese el nombre del personaje a buscar en el diccionario: ";
        leerCadena(nombreBuscado);
        encontrado = diccionario.buscarPersonaje(nombreBuscado);
    }
    system("clear");
    encontrado->obtenerDato()->mostrarAtributos();
}

void Juego::mostrarPersonajes(){
    system("clear");
    cout << "===============PERSONAJES======================" << endl;
    diccionario.enOrden();
}

void Juego::agregarPersonaje() {
    string elementoAgregar, nombreAgregar;
    Dato personajeAgregar;
    Nodo* encontrado;

    cout << "\tAGREGAR PERSONAJE." << endl;
    registrarElemento(elementoAgregar);

    cout << "Ingrese el nombre del nuevo personaje: ";
    leerCadena(nombreAgregar);
    encontrado = diccionario.buscarPersonaje(nombreAgregar);
    while(encontrado){
            cout << "El personaje que quiere agregar ya existe. Ingrese otro nombre para un nuevo personaje: ";
            leerCadena(nombreAgregar);
            encontrado = diccionario.buscarPersonaje(nombreAgregar);
    }
    personajeAgregar = crearPersonaje(elementoAgregar, nombreAgregar);
    diccionario.insertarHoja(personajeAgregar);
    system("clear");
}

void Juego::leerCadena(string &cadena){
    getline(cin, cadena);
    nombreMayuscula(cadena);
}

void Juego::nombreMayuscula(string &nombre){
    for(int i = 0; i < (int)nombre.length(); i++){
        if(i == 0)
            nombre[i] = toupper(nombre[i]);
        else if(nombre[i-1] != ' ')
            nombre[i] = tolower(nombre[i]);
        if(nombre[i] == ' ')
            nombre[i+1] = toupper(nombre[i+1]);
    }
}

Dato Juego::crearPersonaje(string elemento, string nombre){
    Dato nuevo;
    int escudo = rand() % 3;
    int vida = rand() % 91 + 10;
    if(elemento == "Agua")
        nuevo = new PersonajeAgua(nombre, escudo, vida);
    else if(elemento == "Aire")
        nuevo = new PersonajeAire(nombre, escudo, vida);
    else if(elemento == "Fuego")
        nuevo = new PersonajeFuego(nombre, escudo, vida);
    else
        nuevo = new PersonajeTierra(nombre, escudo, vida);
    return nuevo;
}

Dato Juego::crearPersonaje(string elemento, string nombre, int escudo, int vida){
    Dato nuevo;
    if(elemento == "Agua")
        nuevo = new PersonajeAgua(nombre, escudo, vida);
    else if(elemento == "Aire")
        nuevo = new PersonajeAire(nombre, escudo, vida);
    else if(elemento == "Fuego")
        nuevo = new PersonajeFuego(nombre, escudo, vida);
    else
        nuevo = new PersonajeTierra(nombre, escudo, vida);
    return nuevo;
}

void Juego::registrarElemento(string &elementoAgregar){
    cout << "Ingrese el elemento del nuevo personaje ( AGUA, AIRE, TIERRA, FUEGO ): ";
    leerCadena(elementoAgregar);
    while(elementoAgregar != "Agua" && elementoAgregar != "Aire" && elementoAgregar != "Tierra" && elementoAgregar != "Fuego") {
        cout << "\tERROR. Ingrese un elemento válido ( AGUA, AIRE, TIERRA, FUEGO ): ";
        leerCadena(elementoAgregar);
    }
}

void Juego::procesarArchivo(ifstream &archivo){
    if (archivo.is_open()){
        string elemento, nombre, escudo, vida;
        int escudoEntero, vidaEntero;
        while(!archivo.eof() && archivo.peek() != EOF){
            procesarDatosPersonaje(archivo, elemento, nombre, escudo, vida, escudoEntero, vidaEntero);
            Dato nuevo = crearPersonaje(elemento, nombre, escudoEntero, vidaEntero);
            diccionario.insertarHoja(nuevo);
        }
    }
}

void Juego::procesarDatosPersonaje(ifstream &archivo, string &elemento, string &nombre, string &escudo, string &vida, int &escudoEntero, int &vidaEntero){
    getline(archivo, elemento, ',');
    getline(archivo, nombre, ',');
    getline(archivo, escudo, ',');
    getline(archivo, vida, '\n');
    nombreMayuscula(elemento);
    nombreMayuscula(nombre);
    escudoEntero = stoi(escudo);
    vidaEntero = stoi(vida);
}

void Juego::asignarPersonaje(int numJugador, int numPer, Personaje* personaje){
    int tipo = personaje->devolverTipo();
    ControladorPersonaje* controlador;
    switch (tipo)
    {
    case TIPO_AGUA:
        controlador = new ControladorAgua(personaje, &tablero);
        break;
    case TIPO_TIERRA:
        controlador = new ControladorTierra(personaje, &tablero);
        break;
    case TIPO_FUEGO:
        controlador = new ControladorFuego(personaje, &tablero);
        break;
    case TIPO_AIRE:
        controlador = new ControladorAire(personaje, &tablero);
        break;
    }
    if(numPer < 3){
        jugadores[numJugador].asignar_controlador(controlador, numPer);
    } else if(numPer = 3){
        jugadores[numJugador].asignar_controlador(controlador);
    }
    personaje->seleccionar();
}

bool Juego::seleccionarPersonaje(int numjugador){
    string nombre;
    Personaje* personaje;
    Nodo* nodo;
    bool personajeSeleccionado = false; 
    cout << "Ingrese el nombre del personaje: ";
    cin >> nombre;
    nombreMayuscula(nombre);
    nodo = diccionario.buscarPersonaje(nombre);
    system("clear");
    if(nodo != 0){
        personaje = nodo->obtenerDato();
        if(personaje->estaSeleccionado() == false){
            asignarPersonaje(numjugador, 3, personaje);
            personaje->asignarJugador(numjugador + 1);
            personajeSeleccionado = true;
        }
        else{
            cout << "Ese personaje ya fue seleccionado" << endl;
        }
    } else {
        cout << "No hay un personaje con ese nombre" << endl;
    }
    return personajeSeleccionado;
}

void Juego::comenzarJuego(){
    bool salir = false;
    char opcion;
    int per = 0;
    int jug = 0;
    system("clear");
    while(!salir && jug < 2){
        while(!salir && per < 3){
            imprimirOpcionesComenzar();
            cout << endl << "Jugador " << jug + 1 << endl;
            opcion = recibirOpcion('4');
            switch (opcion)
            {
            case '1':
                mostrarDetalle();
                break;
            case '2':
                mostrarPersonajes();
                break;
            case '3':
                if(seleccionarPersonaje(jug)){ per++;}
                break;
            case '4':
                salir = true;
                break;
            }
        }
        per = 0;
        jug++;
    }
    if(!salir){
        partida();
    }
}

void Juego::eliminarPersonaje() {
    string eliminar;
    cout << "\tELIMINAR PERSONAJE DE LA LISTA." << endl
         << "Ingrese el nombre del personaje a eliminar: ";
    leerCadena(eliminar);
    system("clear");
    diccionario.borrarNodo(eliminar);
}

int Juego::finPartida(){
    int ganador = 0;
    int personajesPerdidos;
    for(int i = 0; i < 2; i++){
        personajesPerdidos = 0;
        ControladorPersonaje** controladores = jugadores[i].devolverControladores();
        for(int j = 0; j < 3; j++){
            if(controladores[j] == 0){
                personajesPerdidos++;
            }
        }
        if(personajesPerdidos == 3){
            if(i == 0){
                ganador = 2;
            } else if(i == 1){
                ganador = 1;
            }
        }
    }
    return ganador;
}

void Juego::ubicarPersonajes(int jugador){
    int ubicacion[2];
    ControladorPersonaje** controladores = jugadores[jugador].devolverControladores();
    for (int i = 0; i < 3 ; i++){
        cout << "Ubicando los personajes del jugador: " << jugador + 1<< endl;
        tablero.showBoard();
        bool ubicar = false;
        while ( !ubicar ) {
            cout << "Ingrese la ubicacion donde iniciara: " << controladores[i]->devolverPersonaje()->obtenerNombre() << endl;
            cout << "Fila: " ;
            cin >> ubicacion[0];
            cout << "" << endl;
            while (ubicacion[0] > 8 || ubicacion[0] < 1  ){
                if(!cin){
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
                cout << "Ingrese un valor valido: " << endl;
                cout << "Fila: " ;
                cin >> ubicacion[0];
                cout << "" << endl;
            }
            cout << "Columna: ";
            cin >> ubicacion[1];
            cout << "" << endl;
            while (ubicacion[1] > 8 || ubicacion[1] < 1  ){
                if(!cin){
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
                cout << "Ingrese un valor valido: " << endl;
                cout << "Columna: " ;
                cin >> ubicacion[1];
                cout << "" << endl;
            }
            system("clear");
            ubicar = controladores[i]->ubicarPersonaje(ubicacion);
        }
    }
}

bool Juego::preguntarGuardado(int jugador) {
    bool salir = false;
    bool guardar;
    char decision;
    cout << "Jugador " << jugador << " deseas guardar la partida? " << endl;
    cout << "1. Guardar y salir." << endl;
    cout << "2. Continuar " << endl;
    cout << "Seleccione una opcion: ";
    cin >> decision;
    cout << " "<< endl;
    while ( !salir ){
        switch (decision) {
            case '1' :
                cout << "Se guardará la partida" << endl;
                salir = true;
                guardar = true;
                break;
            case '2' :
                system("clear");
                salir = true;
                guardar = false;
                break;
            default:
                cout << "Opción no valida, por favor seleccione una opción válida" << endl;
                cout << "1. Guardar y salir." << endl;
                cout << "2. Continuar " << endl;
                cout << "Seleccione una opcion: ";
                cin >> decision;
                cout << "" << endl;
                break;
        }
    }
    return guardar;
}

void Juego::partida() {
    int actual; 
    int segundo;
    int terminar = 0;
    int opcion = 0;
    bool guardado = false;
    if(!partidaCargada){
        actual = rand() % 2;
        if(actual == 0){
            segundo = 1;
        }
        else{
            segundo = 0;
        }
        cout << "El jugador " << actual + 1 << " tendra el primer turno"<< endl;
        ubicarPersonajes(actual);
        ubicarPersonajes(segundo);
        cout << "Todos los personajes fueron ubicados" << endl << endl;
        tablero.showBoard();
        cout << endl;
    } else {
        actual = turnoActual;
        if(actual == 0){
            segundo = 1;
        }
        else{
            segundo = 0;
        }
    }
    while (terminar == 0) {
        if(terminar == 0){
            guardado = preguntarGuardado(actual + 1);
            if (guardado){
                guardarPartida(actual + 1);
                terminar = 3;
            }
            else{
                jugadores[actual].turno(actual);
                terminar = finPartida();
                if(terminar == 0){
                    guardado  = preguntarGuardado(segundo + 1);
                    if (guardado){
                        guardarPartida(segundo + 1);
                        terminar = 3;
                    }
                    else{
                        jugadores[segundo].turno(segundo);
                    }
                }
            }
            if (terminar == 0){
                terminar = finPartida();
            }
        }
    }
    tablero.showBoard();
    if(terminar == 1){
        cout << endl << endl << "EL GANADOR ES EL JUGADOR 1" << endl;
        SDL_Delay(3000);
    }
    else if(terminar == 2){
        cout << endl << endl << "EL GANADOR ES EL JUGADOR 2" << endl;
        SDL_Delay(3000);
    }
    else if (terminar == 3){
        cout << endl << endl << "PARTIDA TERMINADA PORQUE UN JUGADOR DECIDIO GUARDAR LA PARTIDA" << endl;
    }
    if(terminar == 1 || terminar == 2){
        if(remove("res/partida.csv") != 0){
            cout << "Error al borrar partida guardada" << endl;
        } else{
            cout << "Exito al eliminar partida guardada" << endl;
        }
    }
}

string Juego::tipoString(int tipo){
    string ret;
    switch(tipo){
        case TIPO_AGUA:
            ret = "Agua";
            break;
        case TIPO_AIRE:
            ret = "Aire";
            break;
        case TIPO_TIERRA:
            ret = "Tierra";
            break;
        case TIPO_FUEGO:
            ret = "Fuego";
            break;
    }
    return ret;
}

void Juego::guardarPartida(int jugador) {
    ofstream archivoPartida("res/partida.csv", ios::out);
    archivoPartida << jugador << "\n";
    for (int i = 0; i < 2; i++) {
        ControladorPersonaje **controladores = jugadores[i].devolverControladores();
        for (int j = 0; j < 3; j++) {
            if (controladores[j] != 0) {
                string tipo;
                string nombre;
                string adicional;
                string linea;

                string fila = to_string(controladores[j]->devolverUbicacion()[0]);
                string columna = to_string (controladores[j]->devolverUbicacion()[1]);
                Personaje *actual = controladores[j]->devolverPersonaje();
                tipo = tipoString(actual->devolverTipo());
                if (actual->devolverTipo() == TIPO_AGUA){
                     adicional = to_string(actual->obtenerAlimentos());
                }
                else {
                    adicional = to_string(controladores[j]->conocerDefensa());
                }
                nombre = actual->obtenerNombre();
                string escudo = to_string(actual->obtenerEscudo());
                string vida = to_string(actual->obtenerVida());
                string energia = to_string(actual->obtenerEnergia());
                linea = tipo + "," + nombre + "," + escudo + "," + vida + "," + energia + "," + fila + "," + columna + "," + adicional;
                archivoPartida << linea + ",\n" ;

            }
            else
                archivoPartida << "0,\n";
        }
    }
    cout << "Partida guardada con éxito" << endl;
    archivoPartida.close();
}

Juego::~Juego(){

}