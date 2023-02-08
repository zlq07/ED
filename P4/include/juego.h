#ifndef __JUEGO_H
#define __JUEGO_H
#include "jugador.h"
#include "palabras.h"
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <string>
using namespace std;
class Juego
{
private:
  // Todas las palabras
  Palabras mispalabras;
  int l_words; // longitud de las palabras
  // Palabras válidas para el juego
  set<string> all_words;
  list<string> wsaid; // palabras que han salida en la partida
  // punteros a los jugadores
  Jugador *j1, *j2;
  int turno;         // 0 jugador 1 1 jugador 2
  string ultimaword; // Ultima palabra

  // Imprime las palabras que se han dicho y las palabras posibles
  // que pueden ocurrir en el juego (all_words-wsaid)
  void ImprimeResumen();

  // obtiene un conjunto de palabras posibles para iniciar el juego
  //  1. Palabras de longitud l_word
  //  2. Palabras que contenga solamente caracteres de la a-z
  //  3. Con las palabras filtradas con 1 y 2 escoger aquellas que por lo menos
  //  genera un arbol con camino de longitud 3. Ver PosiblesPalabrasDEsde
  set<string> getPosiblesWordToPlay();

public:
  Juego();
  /**
    @brief Inicializa el juego
    @param jug1: Jugador 1
    @param jug2: Jugador 2
    @param nfile_words: nombre del fichero con todas las palabras (para inicia mispalabras)
    @param len_words: longitud de las palabras para el juego
    @param turno: 0 inicia el jugador 1 1 inicia el jugador 2
  */
  Juego(Jugador &jug1, Jugador &jug2, const string &nfile_words, int len_words, int turno);
  // j1=&jug1; j2=&juga; j1 -> nextWorld()

  // Función que orquesta el juego. Va pidiendo según el turno que jueguen los jugadores
  // y va lanzando los mensajes correspondientes.
  void Juega();
  /*
  1mientrer no terminar
  1.1actualizar el juegador que inicia el juego
  1.2mientre no salir
  1.2.1escoger el jugador con el turno j-currren
  1.2.2 llamar a imprimirResumen (imprime el )
  1.2.3 Sace el nombre del juego con el turno(p,e Rosa >>)
  1.2.4llama al metodo nextWord de j_currenr para obtener la siguiente palabra
  1.2.5Comprueba que la palabra dicha es valida y diferente de 0
  1.2.6Si la palabra o termina la partida opcionalmente ofrece a ayuda
  1.2.7En otro caso inserta la palabra wsaid y ultimapalabra se modifica.CambiaTurno
  1.3 Se finaliza la partida: Se muestra las palabras dichas, el nombre del jugador
  que gana y se pregunta si quiere otra partida( si alguno jugador es humano)
  2Por cada jugador se muestr la partidas ganadas

  */

  // Comprueba que esta dentro de all_words pero no en word_said ademas
  // la distancia con la ultima palabra es 1
  bool validaword(const string lastword, const string nextword);

  // limpia las palabras dichas (wsaid)
  void clearPalabrasdichas();

  // Escoge una nueva longitud de palabras y recarga all_words con las palabras validas
  // a esa longitud y que permita al menos 3 turnos en el juego.
  void updatePalabrasToLen();

  // Modifica el turno
  void cambiaTurno();

  // Imprime las posibles palabras siguientes a una dada
  // devuelve true si existen palabras siguientes y false en caso contrario
  // Esta funcion se implementa si el alumno/a escoge implementar la parte
  // de proporcionar ayuda al jugador humano cuando inserte "0". En caso
  // contrario simplemente devolver false.
  bool mostrarAyuda();

  class iterator
  {
    // COMPLETAR: itera sobre las palabras dichas
  private:
    list<string>::iterator it;

  public:
    iterator() {}
    bool operator==(const iterator &i) const
    {
      return it == i.it;
    }
    bool operator!=(const iterator &i) const
    {
      return it != i.it;
    }
    const string &operator*()
    {
      return *it;
    }
    iterator &operator++()
    {
      ++it;
      return *this;
    }
    iterator &operator--()
    {
      --it;
      return *this;
    }
    friend class Juego;
    friend class const_iterator;
  };
  class const_iterator
  {
    // COMPLETAR: itera sobre las palabras dichas
  private:
    list<string>::const_iterator it;

  public:
    const_iterator() {}
    bool operator==(const const_iterator &i) const
    {
      return it == i.it;
    }
    bool operator!=(const const_iterator &i) const
    {
      return it != i.it;
    }
    const string &operator*()
    {
      return *it;
    }
    const_iterator &operator++()
    {
      ++it;
      return *this;
    }
    const_iterator &operator--()
    {
      --it;
      return *this;
    }
    friend class Juego;
  };
  iterator begin()
  {
    iterator i;
    i.it = wsaid.begin();
    return i;
  }
  const_iterator begin() const
  {
    const_iterator i;
    i.it = wsaid.cbegin();
    return i;
  }

  iterator end()
  {
    iterator i;
    i.it = wsaid.end();
    return i;
  }

  const_iterator end() const
  {
    const_iterator i;
    i.it = wsaid.cend();
    return i;
  }
};

#endif // __JUEGO_H
