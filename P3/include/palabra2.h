#ifndef PALABRA__H
#define PALABRA__H

#include <iostream>
#include <set>
#include <sstream>

using namespace std;

class Palabra
{
private:
  string tipo;           //!< tipo de la palabra
  string word;           //!< la palabra
  set<string> sinonimos; //!<los sinonimos a la palabra. Se almacenan ordenados

  //nos dice si s esta entre los sinonimos. Si esta pos indica la posicion donde esta
  //en sinonimos. En caso contrario que no este el iterator apuntaria a end
  pair<bool, set<string>::const_iterator> Esta(const string &s) const;

public:
  //Constructores
  Palabra(){};
  Palabra(const string &t, const string &w);

  //obtiene el tipo de una palabra. Ej: adjetivo, proposicion ,etc
  string getTipo() const { return tipo; }

  //Obtiene la palabra
  string getPalabra() const { return word; }

  //obtiene el i-th sinonimo
  string getSinonimo(int i) const;

  //Inserta un nuevo sinonimo de forma ordenada
  void insertSinonimo(const string &s);

  //Elimina el sinonimo s
  void eraseSinonimo(const string &s);

  //modifica la palabra
  void setPalabra(const string &w);

  //modifica el tipo de palabra
  void setTipo(const string &t);

  //modifica el i-th sinonimo con s
  void setSinonimo(int i, const string &s);

  //Devuelve si es sinonimo w a la palabra
  bool isSinonimo(string w) const;

  //Devuelve el numero de sinonimos
  int numSinonimos() const;
  class const_iterator_sinonimos; //Declaracion adelantada
  class iterator_sinonimos
  {
  private:
    //Completar
    set<string>::iterator it;

  public:
    //Completar
    iterator_sinonimos() {}
    bool operator==(const iterator_sinonimos &i) const
    {
      return it == i.it;
    }
    bool operator!=(const iterator_sinonimos &i) const
    {
      return it != i.it;
    }
    const string &operator*()
    {
      return *it;
    }
    iterator_sinonimos &operator++()
    {
      ++it;
      return *this;
    }
    iterator_sinonimos &operator--()
    {
      --it;
      return *this;
    }
    friend class Palabra;
    friend class const_iterator_sinonimos;
  };
  class const_iterator_sinonimos
  {
  private:
    //Completar
    set<string>::const_iterator it;

  public:
    //Completar
    const_iterator_sinonimos() {}

    const_iterator_sinonimos(const iterator_sinonimos &i) : it(i.it) {}

    bool operator==(const const_iterator_sinonimos &i) const
    {
      return it == i.it;
    }
    bool operator!=(const const_iterator_sinonimos &i) const
    {
      return it != i.it;
    }
    const string &operator*()
    {
      return *it;
    }
    const_iterator_sinonimos &operator++()
    {
      ++it;
      return *this;
    }
    const_iterator_sinonimos &operator--()
    {
      --it;
      return *this;
    }
    friend class Palabra;
  };

  //Clase begin y end
  iterator_sinonimos begin()
  {
    //Completar
    iterator_sinonimos i;
    i.it = sinonimos.begin();
    return i;
  }
  iterator_sinonimos end()
  {
    //Completar
    iterator_sinonimos i;
    i.it = sinonimos.end();
    return i;
  }

  const_iterator_sinonimos begin() const
  {
    //Completar
    const_iterator_sinonimos i;
    i.it = sinonimos.cbegin();
    return i;
  }
  const_iterator_sinonimos end() const
  {
    //Completar
    const_iterator_sinonimos i;
    i.it = sinonimos.cend();
    return i;
  }

  //operator de entrada
  friend istream &operator>>(istream &is, Palabra &P);

  //operator de salida
  friend ostream &operator<<(ostream &os, const Palabra &P);
};
//bool operator==(const Palabra &p1, const Palabra &p2);
//bool operator<(const Palabra &p1, const Palabra &p2);
#endif // PALABRA__H

