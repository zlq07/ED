#ifndef PALABRAS__H
#define PALABRAS__H
#include "palabra.h"
#include <list>
#include <algorithm>
class Palabras{
 private:
    string idioma;//<! el idioma del conjunto de palabras
    list<Palabra> datos; //<!Se mantiene las palabras ordenadas por palabra y tipo

    //Si la palabra a con tipo esta en Palabras.
    //esta cabecera se ha modificado de la practica2
    pair<bool,list<Palabra>::const_iterator> esta(const string &a,const string &tipo)const;
    pair<bool,list<Palabra>::iterator> esta(const string &a,const string &tipo);
 public:
    //constructor
    Palabras();
    //modificadores, consultadores
    Palabra & operator[](int i);
    const Palabra & operator[](int i)const ;

    //se inserta una nueva palabra
    void insert(const Palabra &P);

    //se borra la palabra con valor a y tipo
    void erase(const string &a,const string &tipo);

    //numero de palabras insertadas
    int size()const;

    //Obtiene un nuevo conjunto de palabras ordenadas por tipo y a igualdad ordenadas
    //por valor de palabra
    Palabras getOrdenadasTipo()const;
    Palabras  getOrdenadasTipoLenta()const;

    //obtiene lso tipos didferentes en el conjunto. Ordenados de mayor a menor tipo.
    vector<string> getDiferentTipos()const;

    //obtiene todas las palabras de un determinado tipo
    Palabras getPalabrasTipo(string tipo)const;

    //obtenemos tipo(s) de una palabra
    vector<string> getTipoPalabra(const string &a );

    //comprueba si dos palabras de un determinado tipo son sinonimas.
    bool areSinonimos(const string &s1,const string &s2,const string &tipo)const;

    //limpia los datos
    void clear();

    //___________________________ITERADORES
    class const_iterator; //declaracion adelantada.
    class iterator{
      private:
        list<Palabra>::iterator it;
      public:
                iterator(){}

                bool operator==(const iterator &i)const {
                    return it==i.it;
                }
                bool operator!=(const iterator &i)const {
                    return it!=i.it;
                }
                Palabra & operator*(){
                    return *it;
                }
                iterator & operator++(){
                    ++it;
                    return *this;
                }
                iterator & operator--(){
                    --it;
                    return *this;
                }
                
                friend class Palabras;
                friend class const_iterator;
      };
      class const_iterator{
            private:
                list<Palabra>::const_iterator it;
            public:

                const_iterator(){}

                const_iterator(const iterator &i):it(i.it){}

                bool operator==(const const_iterator &i)const {
                    return it==i.it;
                }
                bool operator!=(const const_iterator &i)const {
                    return it!=i.it;
                }
                const Palabra & operator*(){
                    return *it;
                }
                const_iterator & operator++(){
                    ++it;
                    return *this;
                }
                const_iterator & operator--(){
                    --it;
                    return *this;
                }
                friend class Palabras;
      };

      //Clase begin y end
      iterator begin(){
       iterator i;
       i.it = datos.begin();
       return i;

      }
      iterator end(){
       iterator i;
       i.it = datos.end();
       return i;
      }

      const_iterator begin()const{
       const_iterator i;
       i.it = datos.cbegin();
       return i;

      }
      const_iterator end()const{
       const_iterator i;
       i.it = datos.cend();
       return i;

      }

    Palabras::iterator find(const string &tipo,const string& p );


    //operator de entrada
    friend istream & operator>>(istream &is,Palabras &P);

    //operator de salida
    friend ostream & operator<<(ostream &os,const Palabras &P);

};


#endif // PALABRAS__H
