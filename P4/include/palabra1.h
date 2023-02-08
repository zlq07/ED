#ifndef PALABRA__H
#define PALABRA__H

#include <iostream>
#include "vector"
#include <cassert>
#include <sstream>
using namespace std;

class Palabra{
  private:
    string tipo; //!< tipo de la palabra
    string  word;//!< la palabra
    vector<string> sinonimos; //!<los sinonimos a la palabra. Se almacenan ordenados

    //nos dice si s esta entre los sinonimos. Si esta pos indica la posicion donde esta
    //en sinonimos.
    //La cabecera ha cambiado con respecto a la practica 2
    pair<bool,vector<string>::const_iterator> Esta(const string &s)const;
  public:
      //Constructores
      Palabra();
      Palabra(const string &t, const string &w);

      //obtiene el tipo de una palabra. Ej: adjetivo, proposicion ,etc
      string getTipo()const;

      //Obtiene la palabra
      string getPalabra()const;

      //obtiene el i-th sinonimo
      string getSinonimo(int i)const;

      //Inserta un nuevo sinonimo de forma ordenada
      void insertSinonimo(const string & s);

      //Elimina el sinonimo s
      void eraseSinonimo(const string &s);

      //modifica la palabra
      void setPalabra(const string &w);

      //modifica el tipo de palabra
      void setTipo(const string &t);

      //modifica el i-th sinonimo con s
      void setSinonimo(int i,const string & s);


      //Devuelve si es sinonimo w a la palabra
      bool isSinonimo(string w)const;

      //Devuelve el numero de sinonimos
      int numSinonimos()const;



       //_____________________ITERADORES____________________________
      class const_iterator_sinonimos;//Declaracion adelantada
      class iterator_sinonimos{
            private:
                vector<string>::iterator it;
            public:
                iterator_sinonimos(){}

                bool operator==(const iterator_sinonimos &i)const {
                    return it==i.it;
                }
                bool operator!=(const iterator_sinonimos &i)const {
                    return it!=i.it;
                }
                const string & operator*(){
                    return *it;
                }
                iterator_sinonimos & operator++(){
                    ++it;
                    return *this;
                }
                iterator_sinonimos & operator--(){
                    --it;
                    return *this;
                }
                friend class Palabra;
                friend class const_iterator_sinonimos;
      };
      class const_iterator_sinonimos{
            private:
                vector<string>::const_iterator it;
            public:

                const_iterator_sinonimos(){}

                const_iterator_sinonimos(const iterator_sinonimos &i):it(i.it){}

                bool operator==(const const_iterator_sinonimos &i)const {
                    return it==i.it;
                }
                bool operator!=(const const_iterator_sinonimos &i)const {
                    return it!=i.it;
                }
                const string & operator*(){
                    return *it;
                }
                const_iterator_sinonimos & operator++(){
                    ++it;
                    return *this;
                }
                const_iterator_sinonimos & operator--(){
                    --it;
                    return *this;
                }
                friend class Palabra;
      };

      //Clase begin y end
      iterator_sinonimos begin(){
       iterator_sinonimos i;
       i.it = sinonimos.begin();
       return i;

      }
      iterator_sinonimos end(){
       iterator_sinonimos i;
       i.it = sinonimos.end();
       return i;
      }

      const_iterator_sinonimos begin()const{
       const_iterator_sinonimos i;
       i.it = sinonimos.cbegin();
       return i;

      }
      const_iterator_sinonimos end()const{
       const_iterator_sinonimos i;
       i.it = sinonimos.cend();
       return i;

      }


      //operator de entrada
      friend istream & operator>>(istream &is, Palabra &P);

      //operator de salida
      friend ostream & operator<<(ostream &os, const Palabra &P);
};


#endif // PALABRA__H
