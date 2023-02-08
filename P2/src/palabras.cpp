#include "../include/palabras.h"
#include <cassert>

bool Palabras::esta(const string &a, const string &tipo, int &pos) const
{
    // aplicamos el argoritmo de busqueda binaria
    int ini = 0, fin = datos.size();
    while (ini < fin)
    {
        int mitad = (ini + fin) / 2;
        if (datos[mitad].getPalabra() == a && datos[mitad].getTipo() == tipo)
        {
            pos = mitad;
            return true;
        }
        else if (datos[mitad].getPalabra() < a || (datos[mitad].getPalabra() == a && datos[mitad].getTipo() < tipo))
        {
            ini = mitad + 1;
        }
        else
        {
            fin = mitad;
        }
    }
    pos = ini;
    return false;
}

Palabra &Palabras::operator[](int i)
{
    assert(i >= 0 && i < datos.size());
    return datos[i];
}

const Palabra &Palabras::operator[](int i) const
{
    assert(i >= 0 && i < datos.size());
    return datos[i];
}

bool operator==(const Palabra &p1, const Palabra p2)
{
    return (p1.getPalabra() == p2.getPalabra() && p1.getTipo() < p2.getPalabra());
}

void Palabras::insert(const Palabra &P)
{
    int pos;
    if (!esta(P.getPalabra(), P.getTipo(), pos))
    {
        datos.insert(pos, P);
    }
}

//Borra la palabra con valor a y tipo
void Palabras::erase(const string &a, const string &tipo)
{
    int pos;
    if (esta(a, tipo, pos))
    {
        datos.erase(pos);
    }
}

int Palabras::size() const
{
    return datos.size();
}

Palabras Palabras::getOrdenadasTipo() const
{
    Palabras aux;
    for (int i = 0; i < datos.size(); i++)
    {
        aux.insert(datos[i]);
    }
    return aux;
}

VD<string> Palabras::getDiferentTipos() const
{
    VD<string> aux;
    int cont = 0;
    aux.insert(cont, datos[0].getTipo());
    for (int i = 1; i < datos.size(); i++)
    {
        if (datos[i].getTipo() != datos[i - 1].getTipo())
        {
            cont++;
            aux.insert(cont, datos[i].getTipo());
        }
    }
    int cont2 = 0;
    int flag;
    VD<string> tipos;
    for (int k = 0; k < aux.size(); k++)
    {
        flag = 0;
        for (int j = 0; j < k; j++)
        {
            if (aux[k] == aux[j])
            {
                flag = 1;
            }
        }
        if (flag == 0)
        {
            tipos.insert(cont2, aux[k]);
            cont2++;
        }
    }

    // ordenar por orden de alfabeto
    string temp;
    for (int i = 0; i < cont2 - 1; i++) 
    {
        for (int j = 0; j < cont2 - i - 1; j++)
        {
            if (tipos[j] > tipos[j + 1])
            {
                temp = tipos[j];
                tipos[j] = tipos[j + 1];
                tipos[j + 1] = temp;
            }
        }
    }
    return tipos;
}

Palabras Palabras::getPalabrasTipo(string tipo) const
{
    Palabras aux;
    for (int i = 0; i < datos.size(); i++)
    {
        if (datos[i].getTipo() == tipo)
        {
            aux.insert(datos[i]);
        }
    }
    return aux;
}

VD<string> Palabras::getTipoPalabra(const string &a)
{
    VD<string> tipos;
    int cont = 0;
    for (int i = 0; i < datos.size(); i++)
    {
        if (datos[i].getPalabra() == a)
        {
            cont++;
            for (int j = 0; j < cont; j++)
            {
                tipos.insert(j, datos[i].getTipo());
            }
        }
    }
    return tipos;
}

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

bool Palabras::areSinonimos(const string &s1, const string &s2, const string &tipo) const
{
    int pos;
    if (esta(s1, tipo, pos))
    {
        return datos[pos].isSinonimo(s2);
    }
    else
    {
        return false;
    }
}

ostream &operator<<(ostream &os, const Palabras &P)
{
    for (int i = 0; i < P.datos.size(); i++)
    {
        os << " " << P.datos[i];
    }
    os << endl;
    return os;
}

void Palabras::clear()
{
    datos.clear();
}
