#include "../include/traductor.h"
//completar

Traductor::Traductor(const string &idioma_o, const string &idiom_d)
{
    idioma_origen = idioma_o;
    idioma_destino = idiom_d;
}

Palabras Traductor::getTraduccion(const string &tipo, const string &p) const
{
    Palabras out;
}

int Traductor::size() const
{
    return tra.size();
}

string Traductor::getIdiomaOrigen() const
{
    return idioma_origen;
}

string Traductor::getIdiomaDestino() const
{
    return idioma_destino;
}

void Traductor::erase(const string &tipo, const string &p)
{
    multimap<pair<string, string>, string>::iterator it = tra.begin();
    int cont = 0;
    while ((*it).first.first == tipo && (*it).first.second == p)
    {
        advance((*it), cont);
        pair<string, string> s(tipo, p);
        pair<pair<string, string>, string> a(s, getIdiomaDestino());
        tra.erase(a);
    }
    cont++;
}

void Traductor::insert(const string &tipo, const string &por, const string &pdes)
{
    multimap<pair<string, string>, string>::iterator it = tra.begin();
    int cont = 0;
    while ((*it).first.first != tipo && (*it).first.second != por)
    {
        advance((*it), cont);
        pair<string, string> s(tipo, por);
        pair<pair<string, string>, string> a(s, pdes);
        tra.insert(a);
    }
    cont++;
}

Traductor Traductor::TraductorInverso() const
{
    
}
