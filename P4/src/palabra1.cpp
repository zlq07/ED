#include "../include/palabra1.h"
//completar

pair<bool, vector<string>::const_iterator> Palabra::Esta(const string &s) const
{
    pair<bool, vector<string>::const_iterator> out;
    // aplicamos el argoritmo de busqueda binaria
    vector<string>::const_iterator it = sinonimos.cbegin();
    int ini = 0, fin = sinonimos.size();
    while (ini < fin)
    {
        int m = (ini + fin) / 2;
        if (sinonimos[m] == s)
        {
            out.first = true;
            advance(it, m);
            out.second = it;
            return out;
        }
        else if (sinonimos[m] < s)
        {
            ini = m + 1;
        }
        else
        {
            fin = m;
        }
    }
    out.first = false;
    advance(it, ini);
    out.second = it; //aunque no esta el elemento en que poscion debe insertarse
    return out;
}

string Palabra::getSinonimo(int i) const
{
    assert(i >= 0 && i < sinonimos.size());
    return sinonimos[i];
}

void Palabra::insertSinonimo(const string &s)
{
    auto a = Esta(s);
    if (a.first == false)
    {
        sinonimos.insert(a.second, s);
    }
}

void Palabra::eraseSinonimo(const string &s)
{
    auto a = Esta(s);
    if (a.first == true)
    {
        sinonimos.erase(a.second);
    }
}

void Palabra::setPalabra(const string &w)
{
    word = w;
}

void Palabra::setTipo(const string &t)
{
    tipo = t;
}

void Palabra::setSinonimo(int i, const string &s)
{
    auto a = Esta(s);
    if (a.first == false && a.first != i)
    {
        sinonimos.erase(a.second);
        sinonimos.insert(a.second, s);
    }
}

bool Palabra::isSinonimo(string w) const
{
    auto a = Esta(w);
    if (a.first == true)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int Palabra::numSinonimos() const
{
    return sinonimos.size();
}

istream &operator>>(istream &is, Palabra &P)
{
    string linea;
    getline(is, linea);
    istringstream iss(linea);

    string t, w;
    getline(iss, t, ';');
    if (t == " ")
    {
        return is;
    }
    P.tipo = t;
    getline(iss, w, ';');
    P.word = w;
    P.sinonimos.clear();
    while (getline(iss, t, ';'))
    {
        P.insertSinonimo(t);
    }
    return is;
}

ostream &operator<<(ostream &os, const Palabra &P)
{
    os << " " << P.getPalabra();
    return os;
}