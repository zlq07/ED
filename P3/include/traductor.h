#ifndef Traductor__H
#define Traductor__H
#include "palabras.h"
#include <map> //para poder usar multimap

//Como comparar dos pares de cualquier tipo
template <class T, class U>
bool operator<(pair<T, U> &p1, pair<T, U> &p2)
{
  return (p1.first < p2.first || (p1.first == p2.first && p1.second < p2.second));
}

class Traductor
{
private:
  string idioma_origen, idioma_destino;
  //first  tipo de la palabra y palabra en el idioma origen
  //second  palabra en el idioma destino
  multimap<pair<string, string>, string> tra;

public:
  //Constructor por defecto
  Traductor() {}

  //Constructor con parametros.Inicializa los idiomas

  Traductor(const string &idioma_o, const string &idiom_d);

  /**
     @brief Obtiene un conjunto de palabras con las traducciones correspondiente a la entrada
     @exception en caso de que no exista esa palabra devuelve un conjunto de palabras vacio
    */
  Palabras getTraduccion(const string &tipo, const string &p) const;

  /**
     @brief Devuelve el numero de entradas en el traductor
     */
  int size() const;
  /**
     @brief Devuelve el idioma origen
     */

  string getIdiomaOrigen() const;
  /**
     @brief Devuelve el idioma destino
     */

  string getIdiomaDestino() const;

  /**
     @brief Borra todas las entradas con palabra origen p y tipo tipo

    */
  void erase(const string &tipo, const string &p);
  /**
     @brief inserta una nueva entrada al traductor
     @param tipo : tipo de las palabras
     @param por: palabra en el idioma origen
     @param pdes: palabra en el idioma destino
     @post si existe una entrada ya con <tipo,por,pdes> no se insertara nada. El traductor
     no se modifica
    */

  void insert(const string &tipo, const string &por, const string &pdes);

  /**
     @brief Obtiene el traductor del idioma destino al origen
    */
  Traductor TraductorInverso() const;
  /**
     @brief Operador de entrada
     */

  /*********************ITERADORES***************************/
  class iterator
  {
  private:
    //Completar
    multimap<pair<string, string>, string>::iterator it, final;

  public:
    //Completar
    iterator() {}
    pair<const pair<string, string>, string> &operator*() { return *it; }
    /**
        * @brief Operador ++ PRE-incremento
        * @return Devuelve un iterador a la siguiente posicion
        */
    iterator &operator++()
    {
      ++it;
      return *this;
    }

    /**
        * @brief Operador -- PRE-decremento
        * @return Devuelve un iterador a la anterior posicion
        */
    iterator &operator--()
    {
      --it;
      return *this;
    }

    /**
        * @brief Operador ==. Compara si dos iteradores son iguales
        * @return Devuelve true si son iguales y false en caso contrario
        */
    bool operator==(const iterator &orig) const
    {
      return it == orig.it;
    }

    /**
        * @brief Operador !=. Compara si dos iteradores no son iguales
        * @return Devuelve true si no son iguales y false en caso contrario
        */
    bool operator!=(const iterator &orig) const
    {
      return it != orig.it;
    }
    // Clase friend Traductor
    friend class Traductor;
  };

  class const_iterator
  {
  private:
    //Completar
    multimap<pair<string, string>, string>::const_iterator it;

  public:
    //Completar
    /**
        * @brief Constructor por defecto
        */
    const_iterator(){};

    /**
        * @brief Constructor copia
        */
    const_iterator(const multimap<pair<string, string>, string>::const_iterator i) : it(i){};

    /**
        * @brief Operador ++ PRE-incremento
        * @return Devuelve un iterador a la siguiente posicion
        */
    const_iterator &operator++()
    {
      ++it;
      return *this;
    }

    /**
        * @brief Operador -- PRE-decremento
        * @return Devuelve un iterador a la anterior posicion
        */
    const_iterator &operator--()
    {
      --it;
      return *this;
    }

    /**
        * @brief Operador ==. Compara si dos iteradores son iguales
        * @return Devuelve true si son iguales y false en caso contrario
        */
    bool operator==(const const_iterator &orig) const
    {
      return it == orig.it;
    }

    /**
        * @brief Operador !=. Compara si dos iteradores no son iguales
        * @return Devuelve true si no son iguales y false en caso contrario
        */
    bool operator!=(const const_iterator &orig) const
    {
      return it != orig.it;
    }
    // Clase friend Traductor
    friend class Traductor;
  };
  iterator begin()
  {
    //Completar
    iterator i;
    i.it = tra.begin();
    return i;
  }
  const_iterator begin() const
  {
    //Completar
    const_iterator i;
    i.it = tra.cbegin();
    return i;
  }
  iterator end()
  {
    //Completar
    iterator i;
    i.it = tra.end();
    return i;
  }
  const_iterator end() const
  {
    //Completar
    const_iterator i;
    i.it = tra.cend();
    return i;
  }

  /**
     @brief Operador de entrada. 
	Ejemplo de fichero esta en datos/tra_spanish_english.txt
     */

  friend istream &operator>>(istream &os, Traductor &T);
  /**
     @brief Operador de salida
     */
  friend ostream &operator<<(ostream &os, const Traductor &T);
};

#endif
