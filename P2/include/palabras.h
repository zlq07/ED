#ifndef PALABRAS__H
#define PALABRAS__H
#include "palabra.h"

class Palabras
{
private:
   string idioma;     /**< el idioma del conjunto de palabras */
   VD<Palabra> datos; /**< Se mantiene las palabras ordenadas por palabra y tipo */

   /**
    * @brief i la palabra a con tipo esta en Palabras. Si esta pos indica la posicion donde esta
    * en datos. En caso contrario pos indica donde deberia insertarse
    * @param a la palabra
    * @param t tipo de palabra
    * @param pos posicion de palabra
    * @return true si encontramos la palabra y false si no lo encontramos
    */
   bool esta(const string &a, const string &tipo, int &pos) const;

public:
   /**
    * @brief Constructor por defecto de la clase.
    */
   Palabras(){};

   /**
   * @brief Devuelve una referencoa al objeto i-th 
   * @param i: indice del elemento a devolver
   * @return una referencia al objeto i-th
   * @pre i>=0 y i<datos.size()
   **/
   Palabra &operator[](int i);
   const Palabra &operator[](int i) const;

   /**
   * @brief se inserta una nueva palabra
   * @param P palabra a insertar
   */
   void insert(const Palabra &P);

   /**
   * @brief se borra la palabra con valor a y tipo
   * @param a valor de la palabra
   * @param tipo tipo de la palabra
   * @pre la palabra que queremos eliminar debe existir
   */
   void erase(const string &a, const string &tipo);

   /**
   * @brief obterner tamaño de palabras insertadas
   * @return numero de palabras insertadas
   */
   int size() const;

   /**
   * @brief Obtiene un nuevo conjunto de palabras ordenadas por tipo y a igualdad ordenadas por valor de palabra
   * @return nuevo conjunto de palabras ordenadas
   */
   Palabras getOrdenadasTipo() const;

   /**
   * @brief obtiene lso tipos didferentes en el conjunto. Ordenados de mayor a menor tipo.
   * @return tipos didferentes en el conjunto
   */
   VD<string> getDiferentTipos() const;

   /**
   * @brief obtiene todas las palabras de un determinado tipo
   * @return todas las palabras de un determinado tipo
   */
   Palabras getPalabrasTipo(string tipo) const;

   /**
   * @brief obtenemos tipo(s) de una palabra
   * @return tipo(s) de una palabra
   */
   VD<string> getTipoPalabra(const string &a);

   /**
   * @brief omprueba si dos palabras de un determinado tipo son sinonimas.
   * @return 
   */
   bool areSinonimos(const string &s1, const string &s2, const string &tipo) const;

   /**
   * @brief limpia los datos
   */
   void clear();

   /**
   * @brief Operador de entrada de una palabra
   * @param is stream de entrada
   * @param P palabra 
   */
   friend istream &operator>>(istream &is, Palabras &P);

   /**
   * @brief Operador de salida
   * @param os stream de salida
   * @param P Parabra a escribir
   */
   friend ostream &operator<<(ostream &os, const Palabras &P);
};

#endif // PALABRAS__H
