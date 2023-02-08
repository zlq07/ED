#include "../include/palabras.h"
#include <cassert>
#include <vector>

pair<bool, list<Palabra>::const_iterator> Palabras::esta(const string &a, const string &tipo) const
{
    pair<bool, list<Palabra>::const_iterator> out;
    list<Palabra>::const_iterator it = datos.cbegin();

    int ini = 0, fin = datos.size();
    while (ini < fin)
    {
        int mitad = (ini + fin) / 2;
        advance(it, mitad);

        if ((*it).getPalabra() == a && (*it).getTipo() == tipo)
        {
            out.first = true;
            out.second = it;
            return out;
        }
        else if ((*it).getPalabra() < a || ((*it).getPalabra() == a && (*it).getTipo() < tipo))
        {
            ini = mitad + 1;
        }
        else
        {
            fin = mitad;
        }
    }
    advance(it, ini);
    out.first = false;
    return out;
}

pair<bool, list<Palabra>::iterator> Palabras::esta(const string &a, const string &tipo)
{
    pair<bool, list<Palabra>::iterator> out;
    list<Palabra>::iterator it = datos.begin();

    int ini = 0, fin = datos.size();
    while (ini < fin)
    {
        int mitad = (ini + fin) / 2;
        advance(it, mitad);

        if ((*it).getPalabra() == a && (*it).getTipo() == tipo)
        {
            out.first = true;
            out.second = it;
            return out;
        }
        else if ((*it).getPalabra() < a || ((*it).getPalabra() == a && (*it).getTipo() < tipo))
        {
            ini = mitad + 1;
        }
        else
        {
            fin = mitad;
        }
    }
    advance(it, ini);
    out.first = false;
    return out;
}

Palabra &Palabras::operator[](int i)
{
    iterator iter;
    iter.it = datos.begin();
    advance(iter.it, i);
    return *(iter.it);
}

const Palabra &Palabras::operator[](int i) const
{
    const_iterator iter;
    iter.it = datos.cbegin();
    advance(iter.it, i);
    return *(iter.it);
}

void Palabras::insert(const Palabra &P)
{
    auto a = esta(P.getPalabra(), P.getTipo());
    if (a.first == false)
    {
        datos.insert(a.second, P);
    }
}

//Borra la palabra con valor a y tipo
void Palabras::erase(const string &a, const string &tipo)
{
    auto b = esta(a, tipo);
    if (b.first == true)
    {
        datos.erase(b.second);
    }
}

int Palabras::size() const
{
    return datos.size();
}

Palabras Palabras::getOrdenadasTipo() const
{
    Palabras aux;
    list<Palabra>::const_iterator it;
    sort(datos.cbegin(), datos.cend());
    it = datos.cbegin();
    while (it != datos.cend())
    {
        aux.insert(*it);
    }
    return aux;
}

Palabras Palabras::getOrdenadasTipoLenta() const
{
    Palabras aux;
    list<Palabra>::const_iterator it;
    int i = 0, fin = datos.size();
    int j = 0;
    while (i < fin)
    {
        i++;
        advance(it, i);
        while (j < fin - 1 - i)
        {
            j++;
            advance(it, j);
        }
    }
    it = datos.cbegin();
    while (it != datos.cend())
    {
        aux.insert(*it);
    }
    return aux;
}

vector<string> Palabras::getDiferentTipos() const
{
    list<Palabra>::const_iterator it = datos.cbegin();
    vector<string> tipos;
    int cont = 0;
    while (cont != datos.size())
    {
        advance(it, cont);
        tipos.push_back((*it).getTipo());
        cont++;
    }
    // Borrar repetidos
    tipos.erase(unique(tipos.begin(), tipos.end()), tipos.end());
    // ordenar de mayor a menor
    sort(tipos.begin(), tipos.end(), greater<string>());
    return tipos;
}

Palabras Palabras::getPalabrasTipo(string tipo) const
{
    Palabras aux;
    list<Palabra>::const_iterator it = datos.cbegin();
    int cont = 0;
    while (cont != datos.size())
    {
        advance(it, cont);
        if ((*it).getTipo() == tipo)
        {
            aux.insert((*it));
        }
        cont++;
    }
    return aux;
}

vector<string> Palabras::getTipoPalabra(const string &a)
{
    list<Palabra>::const_iterator it = datos.cbegin();
    vector<string> tipos;
    int cont = 0;
    while (cont != datos.size())
    {
        advance(it, cont);
        if ((*it).getPalabra() == a)
        {
            tipos.push_back((*it).getTipo());
        }
        cont++;
    }
    return tipos;
}

bool Palabras::areSinonimos(const string &s1, const string &s2, const string &tipo) const
{
    pair<bool, list<Palabra>::const_iterator> out;
    list<Palabra>::const_iterator it = datos.cbegin();
    int cont = 0;
    while (cont != datos.size())
    {
        advance(it, cont);
        if (esta(s1, tipo).first)
        {
            return (*it).isSinonimo(s2);
        }
        else
        {
            out.first = false;
        }
        cont++;
    }
    return out.first;
}

void Palabras::clear()
{
    datos.clear();
}

Palabras::iterator Palabras::find(const string &tipo, const string &p)
{

    Palabras::iterator out;
    list<Palabra>::const_iterator it = datos.begin();

    int ini = 0, fin = datos.size();
    while (ini < fin)
    {
        int mitad = (ini + fin) / 2;
        advance(it, mitad);

        if ((*it).getPalabra() == p && (*it).getTipo() == tipo)
        {
            out = begin();
            return out;
        }
        else if ((*it).getPalabra() < p || ((*it).getPalabra() == p && (*it).getTipo() < tipo))
        {
            ini = mitad + 1;
        }
        else
        {
            fin = mitad;
        }
    }
    out = end();
    advance(it, ini);
    return out;
}

//operator de entrada
istream &operator>>(istream &is, Palabras &P)
{
    is >> P.idioma;
    is.ignore(500, '\n'); //getline(is,line)

    string linea;
    getline(is, linea);
    P.datos.clear();
    Palabra mip;
    while (is >> mip)
    {
        P.insert(mip);
    }
    return is;
}

//operator de salida
ostream &operator<<(ostream &os, const Palabras &P)
{
    Palabras aux;
    list<Palabra>::const_iterator it;
    it = P.datos.cbegin();
    while (it != P.datos.cend())
    {
        aux.insert(*it);
    }
    for (int i = 0; i < aux.size(); i++)
    {
        os << " " << aux[i];
    }
    os << endl;
    return os;
}