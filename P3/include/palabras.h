#ifndef PALABRAS__H
#define PALABRAS__H
#include "palabra.h"
#include <list>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <vector>

class Palabras
{
private:
      string idioma;       //<! el idioma del conjunto de palabras
      list<Palabra> datos; //<!Se mantiene las palabras ordenadas por palabra y tipo

      //Si la palabra a con tipo esta en Palabras.
      //esta cabecera se ha modificado de la practica2
      pair<bool, list<Palabra>::const_iterator> esta(const string &a, const string &tipo) const;
      pair<bool, list<Palabra>::iterator> esta(const string &a, const string &tipo);

public:
      //constructor
      Palabras(){};
      //modificadores, consultadores
      Palabra &operator[](int i);
      const Palabra &operator[](int i) const;

      //se inserta una nueva palabra
      void insert(const Palabra &P);

      //se borra la palabra con valor a y tipo
      void erase(const string &a, const string &tipo);

      //numero de palabras insertadas
      int size() const;

      //Obtiene un nuevo conjunto de palabras ordenadas por tipo y a igualdad ordenadas
      //por valor de palabra
      //Ordenacion usando sort de la clase list (n*log n)
      Palabras getOrdenadasTipo() const;

      //Version lenta (n*n) de la ordeancion por ejemplo usando burbuja
      Palabras getOrdenadasTipoLenta() const;

      //obtiene lso tipos didferentes en el conjunto. Ordenados de mayor a menor tipo.
      vector<string> getDiferentTipos() const;

      //obtiene todas las palabras de un determinado tipo
      Palabras getPalabrasTipo(string tipo) const;

      //obtenemos tipo(s) de una palabra
      vector<string> getTipoPalabra(const string &a);

      //comprueba si dos palabras de un determinado tipo son sinonimas.
      bool areSinonimos(const string &s1, const string &s2, const string &tipo) const;

      //limpia los datos
      void clear();

      //___________________________ITERADORES
      class const_iterator; //declaracion adelantada.
      class iterator
      {
      private:
            //Completar
            list<Palabra>::iterator it;

      public:
            //Completar
            iterator() {}
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

            
            // Clase friend
            friend class Palabras;
      };
      class const_iterator
      {
      private:
            //Completar
            list<Palabra>::const_iterator it;

      public:
            //Completar
            /**
             * @brief Constructor por defecto
             */
            const_iterator(){};

            /**
             * @brief Constructor copia
             */
            const_iterator(const list<Palabra>::const_iterator i) : it(i){};

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

            // Clase friend
            friend class Palabras;
      };

      //Clase begin y end
      iterator begin()
      {
            //Completar
            iterator i;
            i.it = datos.begin();
            return i;
      }
      const_iterator begin() const
      {
            //Completar
            const_iterator i;
            i.it = datos.cbegin();
            return i;
      }
      iterator end()
      {
            //Completar
            iterator i;
            i.it = datos.end();
            return i;
      }
      const_iterator end() const
      {
            //Completar
            const_iterator i;
            i.it = datos.cend();
            return i;
      }

      //Obtiene un iterador apuntando a la Palabra con tipo y p
      //En caso de que no este el operador apunta a end
      Palabras::iterator find(const string &tipo, const string &p);

      //operator de entrada
      friend istream &operator>>(istream &is, Palabras &P);

      //operator de salida
      friend ostream &operator<<(ostream &os, const Palabras &P);
};

#endif // PALABRAS__H
