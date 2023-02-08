#include "../include/palabra.h"

bool Palabra::Esta(const string &s, int &pos) const
{
    // aplicamos el argoritmo de busqueda binaria
    int ini = 0, fin = sinonimos.size();
    while (ini < fin)
    {
        int m = (ini + fin) / 2;
        if (sinonimos[m] == s)
        {
            pos = m;
            return true;
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
    pos = ini;
    return false;
}

string Palabra::getSinonimo(int i) const
{
    assert(i >= 0 && i < sinonimos.size());
    return sinonimos[i];
}

void Palabra::insertSinonimo(const string &s)
{
    int pos;
    if (!Esta(s, pos))
    {
        sinonimos.insert(pos, s);
    }
}

void Palabra::eraseSinonimo(const string &s)
{
    int pos;
    if (Esta(s, pos))
    {
        sinonimos.erase(pos);
    }
}

void Palabra::setPalabra(const string &w)
{
    word = w;
}

void Palabra::setTipo(const string &t){
    tipo = t;
}

void Palabra::setSinonimo(int i, const string &s)
{
    int pos;
    if (!Esta(s, pos) && pos != i)
    {
        sinonimos.erase(i);
        sinonimos.insert(pos, s);
    }
}

bool Palabra::isSinonimo(string w) const{
    int pos;
    return Esta(w,pos);
}

int Palabra::numSinonimos() const{
    return sinonimos.size();
}

istream &operator>>(istream &is, Palabra &P){
    string linea;
    getline(is,linea);
    istringstream iss(linea);

    string t,w;
    getline(iss,t,';');
    if (t==" ")
    {
        return is;
    }
    P.tipo = t;
    getline(iss,w,';');
    P.word = w;
    P.sinonimos.clear();
    while (getline(iss,t,';'))
    {
        P.insertSinonimo(t);
    }
    return is;
}

ostream &operator<<(ostream &os, const Palabra &P){
    os << " " << P.getPalabra();
    return os;
}