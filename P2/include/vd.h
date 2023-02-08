/**
 * @file vd.h
 * @brief Fichero cabecera del TDA Vector Dinamico
 *
 */

#ifndef VD_H
#define VD_H

/**
 * @brief T.D.A. VD
 *
 * Una instancia @e c del tipo de datos abstracto @c VD es un array 1d que almacena
 * objetos de un tipo base. Esta especialmente diseñado para
 * hacer accesos a la informacion de forma rapida. El conjunto de datos seria
 * (a0, a1, ..., an).
 *
 * @author Linqi Zhu
 * @date Octubre 2021
 */
template <class T>
class VD
{
private:
  /**
   * @page repVD Rep del TDA VD
   *
   * @section invVD Invariante de la representacion
   *
   * El invariante es \e rep.n>=0 y rep.dato tiene un espacio de rep.reservado
   *
   * @section faVD Función de abstraccion
   *
   * Un objeto valido @e rep del TDA VD representa a un array con los objetos
   * (rep.dato[0], rep.dato[1], ..., rep.dato[n-1])
   */
  T *datos;       /**< zona de memoria del array */
  int reservados; /**< espacio reservado en datos */
  int n;          /**< elementos almacenados */
  /**
   * @brief Cambio del tamaño del vector dinamico
   * @param tam tamaño del vector dinamico
   * @return Crea el VD de con espacio reservado de tamaño tam
   */
  void resize(int tam);

  /**
   * @brief copias de la clase
   * @param v.reservados espacio reservado en datos a construir
   * @param v.n lementos almacenados a construir
   */
  void copiar(const VD<T> &v);

  /**
   * @brief liberar la clase, eliminando los elementos
   */
  void liberar();

public:
  /**
   * @brief Constructor de la clase
   * @param tam tamaño del vector dinamico
   * @return Crea el VD de con espacio reservado de tamaño mayor que 1
   */
  VD(int tam = 1);

  /**
   * @brief Constructor de copias de la clase
   * @param v.reservados espacio reservado en datos a construir
   * @param v.n lementos almacenados a construir
   */
  VD(const VD<T> &v);

  /**
   * @brief Asignacion de dos vector dinamico
   * @param v vector a asignar con el objeto implicito
   */
  VD<T> &operator=(const VD<T> &v);

  /**
   * @brief Destructor de la clase
   */
  ~VD();

  /**
   * @brief Devolver el elemento almacenados n
   */
  int size() const;

  /**
   * @brief Devuelve una referencoa al objeto i-th en el vactor
   * @param i: indice del elemento a devolver
   * @return una referencia al objeto i-th
   * @pre i>=0 y i<n
   **/
  T &operator[](int i);

  const T &operator[](int i) const;
  /**
   * @brief Insertar un nuevo elemento en una posicion dada
   * @param pos: posicion donde se inserta el elemento
   * @param d: elemento a insertar
   * @pre que la posicion debe estar entre 0 y n
   **/
  void insert(int pos, const T &d);

  /**
   * @brief Eliminar un elemento en una posicion dada
   * @param pos: posicion donde se elimina el elemento
   * @pre que la posicion debe estar entre 0 y n
   **/
  void erase(int pos);

  /**
   * @brief Inicializa el elementos almacenados a 0
   */
  void clear();
};
#include "../src/vd.cpp"

#endif // VD_H
