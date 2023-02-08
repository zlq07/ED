#include "ranking.h"

void Ranking::erase(const string &juga)
{
    auto it = datos.find(juga);
    if (it != datos.end())
    {
        datos.erase(juga);
    }
}

// si existe le suma las nuevas partidas ganadas
// en caso contrario lo inserta como una nueva entrada
void Ranking::addData(const string &juga, int play_winned)
{

}

// Obtiene el numero de partidas ganadas por el jugador
int Ranking::getPartidasGanadas(const string &juga)
{
    auto it = datos.find(juga);
    if (it != datos.end())
    {
        return it->second;
    }
}

// obtiene los nombres de los jugadores ordenados por partidas ganadas
multimap<int, string> getOrdenadosGanadas();

int Ranking::size() const
{
    return datos.size();
}

void Ranking::clear()
{
    datos.clear();
}

// operadores de entrada y salida.
istream &operator>>(istream &is, Ranking &R)
{

    
}

ostream &operator<<(ostream &os, const Ranking &R)
{
    /*
    for (int i = R->second.begin(); i < R->second.end(); i++)
    {
        os << R->first.i << " " << R->second.i;
    }
    os << endl;
    return os;
    */
}