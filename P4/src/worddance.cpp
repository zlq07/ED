#include "juego.h"
#include "jugador.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "ranking.h"
#include <fstream>
using namespace std;
/**
 @brief Inicia el tipo de jugador.
 @param input: caracter que distingue el tipo de jugador
 @param t: parametro de salida que almacenar� el valor de tipo de jugador. ES MODIFICADO
 @return true si es valido el tipo de jugador false en caso contrario.
*/
bool LeeTipoJugador(const char *input, TIPOJ &t)
{
    // COMPLETAR
    if (*input == '0')
    {
        t = HUMANO;
        return true;
    }
    else if (*input == '1')
    {
        t = MAQUINA1;
        return true;
    }
    else
    {
        t = MAQUINA2;
        return true;
    }
    return false;
}

int main(int argc, char *argv[])
{

    if (argc != 8)
    {
        cout << "1.-Dime el nombre del fichero con el conjunto de palabras" << endl;
        cout << "2.- Tipo de jugador 1 (0:HUMANO, 1:MAQUINA (simple) 2:MAQUINA (inteligente)" << endl;
        cout << "3.- Nombre del jugador 1" << endl;
        cout << "4.- Tipo de jugador 2 (0:HUMANO, 1:MAQUINA (simple) 2:MAQUINA (inteligente)" << endl;
        cout << "5.- Nombre  del jugador 2" << endl;
        cout << "6.- Longitud de las palabras " << endl;
        cout << "7.- Fichero con los jugadores y partidas ganadas" << endl;
        return 0;
    }

    // Creamos los jugadores
    TIPOJ t1;
    if (!LeeTipoJugador(argv[2], t1))
    {
        cout << "Error al insertar tipo de jugador 1" << endl;
        return 0;
    }
    TIPOJ t2;
    if (!LeeTipoJugador(argv[4], t2))
    {
        cout << "Error al insertar tipo de jugador 2" << endl;
        return 0;
    }
    srand(time(0));
    int turno = rand() % 2;

    Jugador jug1(t1, argv[3], turno == 0);
    Jugador jug2(t2, argv[5], turno == 1);

    int lw = atoi(argv[6]);
    cout << "Creados jugadores" << endl;

    ifstream fstat(argv[7]);
    if (!fstat)
    {
        cout << "No puedo abrir el fichero " << argv[7] << endl;
        return 0;
    }

    Ranking R;
    fstat >> R;
    fstat.close();
    // Creamos el juego

    Juego worddance(jug1, jug2, argv[1], lw, turno);
    cout << "Creado juego" << endl;
    // Comenzamos el juego
    worddance.Juega();

    // Actualizamos la estadistica

    R.addData(jug1.getNombre(), jug1.num_ganadas());

    R.addData(jug2.getNombre(), jug2.num_ganadas());
    // Abrimos el fichero en modo salida y a�adir
    ofstream fstat_out(argv[7]);
    fstat_out << R << endl;

    multimap<int, string> rptos = R.getOrdenadosGanadas();
    cout << endl
         << endl
         << "Global Ranking  .............." << endl;

    if (rptos.size() > 0)
    {
        auto it = rptos.end();
        int i = 1;
        do
        {
            --it;
            cout << i << ".-" << it->second << "\t" << it->first << endl;
            i++;
        } while (it != rptos.begin());
    }
}
