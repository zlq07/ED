/**
 * @file palabra.h
 */

#ifndef PALABRA__H
#define PALABRA__H
#include <cassert>
#include <string>
#include <sstream>
#include <iostream>
#include "vd.h"
using namespace std;

class Palabra
{
private:
  string tipo;          /**< tipo de la palabra */
  string word;          /**< la palabra */
  VD<string> sinonimos; /**< los sinonimos a la palabra. Se almacenan ordenados */

  /**
   * @brief nos dice si s esta entre los sinonimos. Si esta pos indica la posicion donde esta
   * en sinonimos. En caso contrario pos indica donde deberia insertarse
   * @param s siniminos que queremos buscar
   * @param pos posicion de sinonimo
   * @return true si encontramos el sinomo y false si no lo encontramos
   */
  bool Esta(const string &s, int &pos) const;

public:
  /**
   * @brief Constructor por defecto de la clase.
   */
  Palabra(){}

  /**
   * @brief Constructor de la clase
   * @param t tipo de la palabra a construir
   * @param w la palabra a construir
   * @return Crea una palabra con su tipo
   */
  Palabra(const string &t, const string &w) : tipo(t), word(w) {}

  /**
   * @brief Obtiene el tipo de una palabra. Ej: adjetivo, proposicion ,etc
   * @return tipo de una palabra
   */
  string getTipo() const { return tipo; }

  /**
   * @brief Obtiene la palabra
   * @return una palabra
   */
  string getPalabra() const { return word; }

  /**
   * @brief Obtiene el i-th sinonimo
   * @param i posicion de sinonimo que obtener
   * @return una palabra(sinonimo en posicion i)
   */
  string getSinonimo(int i) const;

  /**
   * @brief Inserta un nuevo sinonimo de forma ordenada
   * @param s sinonimo a insertar
   * @pre el sinonimo que queremos insertar no este en la lista de sinonimos ya existentes
   */
  void insertSinonimo(const string &s);

  /**
   * @brief Elimina el sinonimo s
   * @param s sinonimo a eliminar
   * @pre el sinonimo que queremos eliminar debe estar en la lista de sinonimos ya existentes
   */
  void eraseSinonimo(const string &s);

  /**
   * @brief Modifica la palabra
   * @param w palabra queremos ahora
   */
  void setPalabra(const string &w);

  /**
   * @brief Modifica el tipo de palabra
   * @param t el tipo de palabra queremos ahora
   */
  void setTipo(const string &t);

  /**
   * @brief Modifica el i-th sinonimo con s
   * @param s sinonimo que queremos ahora
   * @param i posicion de sinonimo que desamos modificar
   */
  void setSinonimo(int i, const string &s);

  /**
   * @brief Devuelve si es sinonimo w a la palabra
   * @param w la palabra que queremos saber si es sinomino 
   * @return Devolver true si es sinonimo, false no es sinonimo
   */
  bool isSinonimo(string w) const;

  /**
   * @brief Devuelve el numero de sinonimos
   * @return el tamaño del sinonimos
   */
  int numSinonimos() const;

  /**
  * @brief Operador de entrada de una palabra
  * @param is stream de entrada
  * @param P palabra 
  */
  friend istream &operator>>(istream &is, Palabra &P);

/**
  * @brief Operador de salida
  * @param os stream de salida
  * @param P Parabra a escribir
  */
  friend ostream &operator<<(ostream &os, const Palabra &P);
};
#endif // PALABRA__H
