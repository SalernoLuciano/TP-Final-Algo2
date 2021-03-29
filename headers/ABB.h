#ifndef ABB_H
#define ABB_H

#include "nodo.h"

class ABB{
private:
    // Atributos
    Nodo* raiz;

public:
    //Metdodos

    // PRE: -
    // POS: Crea un arbol binario de busqueda vacio con 'raiz' apuntando a null.
    ABB();//Constructor

    // PRE: -
    // POS: Devuelve el nodo raiz o nullptr si el arbol esta vacio.
    Nodo* obtenerRaiz();

    // PRE: -
    // POS: inserta un nuevo nodo con 'nuevoPersonaje' en el arbol binario.
    void insertarHoja(Dato &nuevoPersonaje);

    // PRE: -
    // POS: Devuelve el NODO que coincida su 'clave' con 'buscado'
    // si el valor buscado no esta en el arbol devuelve nullptr.
    Nodo* buscarPersonaje(const string& buscado);

    // PRE: -
    // POS: Imprime todas las claves del diccionario en orden alfabetico.
    // Si el arbol esta vacio no imprime nada.
    void enOrden();

    // PRE: -
    // POS: Devuelve el Personaje* que posea la menor clave ( alfabetica ),
    // si el arbol esta vacio devuelve nullptr.
    Dato encontrarMenor();

    // PRE: -
    // POS: Devuelve el Personaje* que posea la mayor clave ( alfabetica ),
    // si el arbol esta vacio devuelve nullptr.
    Dato encontrarMayor();

    // PRE: -
    // POS: Devuelve el Personaje* siguiente (alfabeticamente).
    // En caso de no tener un siguiente ( alfabeticamente ) devuelve nullptr.
    Dato encontrarSucesor(string claveActual);

    // PRE: -
    // POS: Devuelve el Personaje* anterior (alfabeticamente).
    // En caso de no tener un anterior ( alfabeticamente ) devuelve nullptr.
    Dato encontrarPredecesor(string claveActual);

    // PRE: El arbol no debe estar vacio.
    // POS: elimina el Nodo que 'clave' == 'eliminar'.
    void borrarNodo(string eliminar);

    // PRE: -
    // POS: Retorna true si raiz == nullptr, false en caso contrario.
    bool arbolVacio();

    // PRE: -
    // POS: Elimina el arbol completo.
    void borrarArbol();

    //Destructor
    ~ABB();

private:

    // PRE: -
    // POS: Agrega un nuevo nodo recursivamente, acomodado alfabeticamente.
    //      ( actual sera el nodo padre del nuevo nodo ).
    Nodo* agregarNodo(Nodo* actual, Dato &nuevoPersonaje);

    // PRE: -
    // POS: Devuelve el NODO que actual->clave == buscado recursivamente,
    //      si el valor buscado no esta en el arbol devuelve nullptr.
    //      ( actual sera el nodo que coincida con el buscado - si coincide con la clave )
    Nodo* consultarPersonaje(Nodo* actual, const string& buscado);

    // PRE: -
    // POS: Imprime recursivamente y en orden alfabetico las claves del diccionario
    //      ( se imprime el subarbol izquierdo de actual y luego el subarbol derecho de actual )
    void imprimirEnOrden(Nodo* actual);

    // PRE: -
    // POS: Devuelve el Personaje* menor (alfabeticamente) del diccionario, recursivamente
    //      recorriendo el subarbol izquierdo de actual. actual seria el padre del menor.
    //      Si actual esta vacio retorna nullptr.
    //      Si actual no pose subarbol izquierdo entonces es el menor.
    Dato menor(Nodo* actual);

    // PRE:
    // POS: Devuelve el Personaje* mayor (alfabeticamente) del diccionario, recursivamente
    //      recorriendo el subarbol derecho de actual. actual seria el padre del mayor.
    //      Si actual esta vacio retorna nullptr.
    //      Si actual no pose subarbol derecho entonces es el mayor.
    Dato mayor(Nodo* actual);

    // PRE: El arbol no debe estar vacio.
    // POS: retorna el Personaje* menor alfabeticamente del subarbol derecho de actual.
    Dato sucesor(Nodo* actual);

    // PRE: El arbol no debe estar vacio.
    // POS: retorna el Personaje* mayor alfabeticamente del subarbol izquierdo de actual.
    Dato predecesor(Nodo* actual);

    // PRE: -
    // POS: Eliminar el Nodo que clave == eliminar recursivamente
    //      si eliminar > clave( actual ) se invoca recursivamente a elimimnarNodo en el subarbol derecho de actual.
    //      si eliminar < clave( actual ) se invoca recursivamente a elimimnarNodo en el subarbol izquierdo de actual.
    //      Dejando el arbol en orden alfabetico
    //      Si el diccionario esta vacio retorna nullptr.
    Nodo* eliminarNodo(Nodo* actual, string eliminar);

    // PRE: -
    // POS: Elimina el Nodo actual y lo deja en nullptr.
    void eliminarHoja(Nodo* &actual);

    // PRE: -
    // POS: Elimina el nodo del diccionario que tenga un solo hijo
    //      Al hijo de actual se le cambia el padre, al padre de actual ( para no perder el nodo hijo )
    //      actual = hijo. el nodo a borrar que fue guardado en un auxiliar se lo elimina.
    void eliminarNodoConHijo(Nodo* &actual, Nodo* hijo);

    // PRE: -
    // POS: Elimina el nodo del diccionario que tenga 2 hijos
    //      Halla el sucesor de actual le cambia el padre del sucesor por el padre de actual.
    //      seteo el subarbol izquierdo de sucesor con el subarbol izquierdo de actual
    //      actual = sucesor
    //      y el nodo a eliminar ( guardado en un auxiliar ) se lo elimina
    //      Por ultimo elimino el nodo sucesor del nuevo actual ya que estaria repetido )
    void eliminarNodoConHijos(Nodo* &actual);

    // PRE: El arbol no debe estar vacio.
    // POS: Elimina el nodo raiz del diciconario, tomando en cuenta si raiz es hoja, tiene un solo hijo o ambos.
    //      Dejando el arbol: vacio o con una nueva raiz.
    void eliminarRaiz();

    // PRE: -
    // POS: Eliminar recursivamente, primero el subarbol izquierdo y luego el subarbol derecho.
    void borrarTodo(Nodo* actual);
};

#endif // ABB_H
