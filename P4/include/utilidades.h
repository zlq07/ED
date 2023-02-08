#ifndef __UTILIDADES__H
#define __UTILIDADES__H
#include <set>
#include <list>
#include <string>
#include "ArbolGeneral.h"
#include <limits>
using namespace std;
//Obtiene el conjunto diferencia entre los conjuntos s1 y s2
set<string> WordDiference(const set<string> &s1,const set<string> &s2);

//Obtiene el número de letras en las que son diferentes las cadenas s1 y s2
int DistanceWords(const string &s1,const string &s2);

//Obtiene el conjunto de palabras de s que se diferencia de w en solo una letra
set <string> getWordDistanceOne(const set<string> &s,string w);

//Devuelve true si la palabra w esta en el camino de la raiz del arbol al nodo n
bool EstaEtiquetaCamino(ArbolGeneral<string> &a, ArbolGeneral<string>::Nodo n,const string & w);

//Crea el Arbol General a partir del nodo n de forma que la diferencia en 
//letras de las palabras que almacena un nodo y su padre no puede ser mayor que 1.
// La variable lc permite no ramificar el arbol más all de lw. 
//Es decir se llama con lc=0 y cuando lc alcanza lw por una rama se termina. 
void CreaTree(ArbolGeneral<string> &a, ArbolGeneral<string>::Nodo n,const set<string> &pp,int lc,int lw=numeric_limits<int>::max());

//Convierte una lista a un set
set<string> ConvertList_Set(const list<string> &s);
//Obtiene la longitud del mayor camino dentro del arbol
int MaxWay(ArbolGeneral<string> &a,ArbolGeneral<string>::Nodo n);

//Obtiene a partir de una palabra s y un conjunto de palabras todas las palabras que se diferencia 
//en sola una letra. Y además el mayor camino que se obtendría si ramificamos el arbol de jugadas 
//desde esa palabra.
pair<int,set<string>> PosiblesPalabrasDesde(const string &s,const set<string> &pp);

#endif
