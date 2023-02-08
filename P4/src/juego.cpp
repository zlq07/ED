#include "juego.h"

// Imprime las palabras que se han dicho y las palabras posibles
// que pueden ocurrir en el juego (all_words-wsaid)
void Juego::ImprimeResumen()
{

    set<string> set_wsaid = ConvertList_Set(wsaid);

    cout << "Las palabras dichas son:" << endl;
    set<string>::iterator it = set_wsaid.begin();
    while (it != set_wsaid.end())
    {
        cout << *it << " ";
        it++;
    }

    cout << "Escoge una palabra entre el siguiente conjunto: " << endl;
    all_words = WordDiference(all_words, set_wsaid);
    set<string>::iterator it1 = all_words.begin();
    while (it1 != all_words.end())
    {
        cout << *it1 << " ";
        it1++;
    }
}

// FUncion auxiliar para comprobar que los caracteres van desde [a-z]
bool HaveCharracterRaros(const string &s)
{
    for (int i = 0; i < s.size(); i++)
        if (!(s[i] >= 'a' && s[i] <= 'z'))
            return true;
    return false;
}

set<string> Juego::getPosiblesWordToPlay()
{
    all_words.clear();
    for (auto it = mispalabras.begin(); it != mispalabras.end(); ++it)
    {
        string aux = (*it).getPalabra();

        if (aux.size() == l_words && !HaveCharracterRaros(aux))
        {
            all_words.insert(aux);
        }
    }
    set<string> posibles_w;

    for (auto it = all_words.begin(); it != all_words.end(); ++it)
    {

        if (PosiblesPalabrasDesde(*it, all_words).first >= 3)
        {
            posibles_w.insert(*it);
        }
    }
    return posibles_w;
}

Juego::Juego(Jugador &jug1, Jugador &jug2, const string &nfile_words, int len_words, int turno)
{
    j1 = &jug1;
    j2 = &jug2;
    ifstream f(nfile_words);
    f >> mispalabras;
    l_words = len_words;
    this->turno = turno;
}

// Función que orquesta el juego. Va pidiendo según el turno que jueguen los jugadores
// y va lanzando los mensajes correspondientes.
void Juego::Juega()
{
    Jugador *j;
    bool fin = false, salir = false;
    while (!fin)
    {
        // cambiaTurno();
        while (!salir)
        {
            // 1.2.1escoger el jugador con el turno j-currren
            if (turno == 0)
            {
                j = j1;
            }
            else
            {
                j = j2;
            }
            ImprimeResumen();
            cout << j->getNombre() << ">>" << endl;
            string actualworld = j->nextWord(ultimaword, all_words);
            if (validaword(ultimaword, actualworld) && actualworld != "0")
            {
                ultimaword = actualworld;
            }
            else
            {
                salir = true;
            }
            cambiaTurno();
        }
        set<string> set_wsaid = ConvertList_Set(wsaid);

        cout << "Las palabras dichas son:" << endl;
        set<string>::iterator it = set_wsaid.begin();
        while (it != set_wsaid.end())
        {
            cout << *it << " ";
            it++;
        }
        cout << "Jugador ganador: " << j->getNombre() << endl;
        string res;
        if (j1->getTipo() == HUMANO || j2->getTipo() == HUMANO)
        {
            cout << "Quieres segir jugando?";
            cin >> res;
            if (res == "SI" || res == "si")
            {
                fin = false;
            }
            else
            {
                fin = true;
            }
        }
    }
    cout << "Partidas ganados: " << endl;
    cout << "Jugador 1: " << j1->num_ganadas();
    cout << "Jugador 2: " << j2->num_ganadas();
}

// Comprueba que esta dentro de all_words pero no en word_said ademas
// la distancia con la ultima palabra es 1
bool Juego::validaword(const string lastword, const string nextword)
{
    set<string> set_wsaid = ConvertList_Set(wsaid);
    set<string> d = WordDiference(all_words, set_wsaid);
    set<string>::iterator it;

    it = d.find(nextword);
    if (it != d.end())
    {
        if (DistanceWords(lastword, nextword) == 1)
        {
            return true;
        }
    }
    return false;
}

// limpia las palabras dichas (wsaid)
void Juego::clearPalabrasdichas()
{
    wsaid.clear();
}

// Escoge una nueva longitud de palabras y recarga all_words con las palabras validas
// a esa longitud y que permita al menos 3 turnos en el juego.
void Juego::updatePalabrasToLen(){
    cout << "Introduzaca otro longitud: ";
    int n_lword;
    cin >> n_lword ;
    l_words = n_lword;
    all_words = getPosiblesWordToPlay();
}

// Modifica el turno
void Juego::cambiaTurno()
{
    if (turno == 1)
    {
        turno = 0;
    }
    else if (turno == 0)
    {
        turno = 1;
    }
}

bool Juego::mostrarAyuda()
{
}