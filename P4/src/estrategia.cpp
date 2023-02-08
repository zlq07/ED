#include "estrategia.h"
#include "utilidades.h"

Strategy::Strategy(const set<string> &todasw)
{
    total_palabras = todasw;
}

// Crea el arbol del juego a partir de la palabra w
bool Strategy::CrearJugadas(const string &w)
{
    // 1.-LImpiar el arbol
    a.~ArbolGeneral();
    // 2.- Asignar a la raiz del arbol la palabra w
    a.AsignaRaiz(w);
    // 3.- LLamar a CrearTree con el arbol y la raiz dando lc=0 y lw= 10
    CreaTree(a, a.raiz(), total_palabras, 0, 10);
    return true;
}

// Limpia los datos
void Strategy::clear()
{
    a.~ArbolGeneral();
}

// Modifica el conjunto de palabras
void Strategy::setPalabras(const set<string> &p)
{
    total_palabras = p;
}

// Estrategia simple para escoger la siguiente palabra. Crea las jugadas (CrearJugadas)
// y escoge su siguiente palabra a devolver
string Strategy::getWord_1(string ultimaword)
{
    CrearJugadas(ultimaword);
    // Devoler "0" si el arbol no tiene hijo mas a la izquierda
    // En otro caso Devolver la etiqueta del hijo mas a la izquierda
    ArbolGeneral<string>::Nodo aux = a.hijomasizquierda(a.raiz());
    if (a.Nulo(a.hijomasizquierda(a.raiz()))){
        return "0";
    }else{
        return aux->etiqueta;
    }
}

// Estrategia mas inteligente para escoger la siguiente palabra. Crea las jugadas (CrearJugadas)
// y escoge su siguiente palabra a devolver. Esta funcion es opcional a implementar.
/*
string Strategy::getWord_2(string ultimaword)
{

}
*/