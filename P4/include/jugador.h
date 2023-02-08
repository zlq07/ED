#ifndef __JUGADOR__H
#define __JUGADOR__H
#include "estrategia.h"
#include <string>
#include <iostream>
using namespace std;
//MAQUINA1 es una maquina con una estrategia simple
//MAQUINA2 es una maquina con una estrategia mas compleja
enum TIPOJ {HUMANO, MAQUINA1,MAQUINA2,DESCONOCIDO};

class Jugador{
  private:
    TIPOJ tipo;
    string nombre;
    int winner_player;
    bool inicia_juego;
  public:
    //Constructores
    Jugador():nombre(""),tipo(DESCONOCIDO),winner_player(0),inicia_juego(false){}
    Jugador(TIPOJ t,const string &s,bool comienza):tipo(t),nombre(s),winner_player(0),inicia_juego(comienza){}


    string getNombre();
    TIPOJ getTipo()const;
    bool getIniciaJuego()const;
 
    //Devuelve la palabra que juega el jugador. Debe ser una de las que 
    //aparecen en pp.Dependiendo del tipo de jugador llamara a juegaHumano
    // o juegaMaquina 	
    string nextWord(string ultimaword,const set<string> &pp);

    //Le pide al usuario humano que inserte su jugada
    string juegaHumano();

    //El jugador Maquin que devuelve su jugada. Para ello creara una estrategia
    // y llamara al tipo de logica que siga (simple o más compleja). 
    string juegaMaquina(string ultimaword,const set<string>&pp);


    void setIniciaJuego(bool i);

    //INcrementa el numero de partidas ganadas	
    void addPartidaGanada();

    //devuelve el numero de partidas ganadas
    int num_ganadas()const;
};


#endif
