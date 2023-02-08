#ifndef ESTRATEGIA__H
#define ESTRATEGIA__H
#include "ArbolGeneral.h"
#include <set>
#include <list>
#include "utilidades.h"
#include <string>
using namespace std;


class Strategy{
    private:

      set<string> total_palabras;
      ArbolGeneral<string> a;

    public:
      //Constructores	
      Strategy();
      Strategy(const set<string> &todasw);

     //Crea el arbol del juego a partir de la palabra w	
      bool CrearJugadas(const string & w);
	
      //Limpia los datos 		
      void clear();    

      //Modifica el conjunto de palabras	
      void setPalabras(const set<string> & p);

      //Estrategia simple para escoger la siguiente palabra. Crea las jugadas (CrearJugadas)
      //y escoge su siguiente palabra a devolver
      string getWord_1(string ultimaword);

      //Estrategia mas inteligente para escoger la siguiente palabra. Crea las jugadas (CrearJugadas)
      //y escoge su siguiente palabra a devolver. Esta funcion es opcional a implementar.
      string getWord_2(string ultimaword);

};
#endif
