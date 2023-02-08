#include "jugador.h"

string Jugador::getNombre()
{
    return nombre;
}

TIPOJ Jugador::getTipo() const
{
    return tipo;
}

bool Jugador::getIniciaJuego() const
{
    return inicia_juego;
}

string Jugador::nextWord(string ultimaword, const set<string> &pp)
{
    string word;
    set<string>::const_iterator it;
    it = pp.find(ultimaword);
    if (it != pp.cend())
    {
        if (tipo == HUMANO)
        {
            word = juegaHumano();
        }
        else if (tipo == MAQUINA1 || tipo == MAQUINA2)
        {
            word = juegaMaquina(ultimaword, pp);
        }
    }
}

// Le pide al usuario humano que inserte su jugada
string Jugador::juegaHumano()
{
    string n;
    nombre = n;
    cout << "Cual es tu palabra: ";
    cin >> n;
    return n;
}

// El jugador Maquin que devuelve su jugada. Para ello creara una estrategia
//  y llamara al tipo de logica que siga (simple o más compleja).
string Jugador::juegaMaquina(string ultimaword, const set<string> &pp)
{
    Strategy est ;
    est.setPalabras(pp);
    return est.getWord_1(ultimaword);
}

void Jugador::setIniciaJuego(bool i)
{
    this->inicia_juego = i;
}

void Jugador::addPartidaGanada()
{
    this->winner_player++;
}

int Jugador::num_ganadas() const
{
    return winner_player;
}