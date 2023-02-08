#include "../include/palabra2.h"
//completar

pair<bool, set<string>::const_iterator> Palabra::Esta(const string &s) const
{
    pair<bool, set<string>::const_iterator> out(false, sinonimos.cend());
    set<string>::const_iterator it;
    it = sinonimos.find(s);
    if (it != sinonimos.cend())
    {
        out.first = true;
        out.second = it;
    }
    return out;
}

Palabra::Palabra(const string &t, const string &w)
{
    tipo = t;
    word = w;
}

void Palabra::insertSinonimo(const string &s)
{
    auto a = Esta(s);
    if (a.first == false)
    {
        sinonimos.insert(s);
    }
}

void Palabra::eraseSinonimo(const string &s)
{
    auto a = Esta(s);
    if (a.first == true)
    {
        sinonimos.erase(s);
    }
}

string Palabra::getSinonimo(int i) const
{
    set<string>::const_iterator it = sinonimos.cbegin();
    advance(it, i);
    return *it;
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
    if (a.first == false)
    {
        for (int j = 0; j < sinonimos.size(); j++)
        {
            if (i == j)
            {
                sinonimos.erase(s);
                sinonimos.insert(s);
            }
        }
    }
}

int Palabra::numSinonimos() const
{
    return sinonimos.size();
}

bool Palabra::isSinonimo(string w) const
{
    auto it = sinonimos.find(w);
    return it != sinonimos.cend();
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
