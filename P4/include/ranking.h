#ifndef __RANKING__H
#define __RANKING__H
#include <map>
#include <string>
#include <iostream>
#include <sstream>
using namespace std;
class Ranking
{
private:
        // nombre de jugador partidas ganadas totales
        map<string, int> datos;

public:
        // Constructor
        Ranking();

        // Elimina un jugador del ranking
        void erase(const string &juga);

        // si existe le suma las nuevas partidas ganadas
        // en caso contrario lo inserta como una nueva entrada
        void addData(const string &juga, int play_winned);

        // Obtiene el numero de partidas ganadas por el jugador
        int getPartidasGanadas(const string &juga);
        // obtiene los nombres de los jugadores ordenados por partidas ganadas

        multimap<int, string> getOrdenadosGanadas();
        int size() const;

        class iterator
        {
                // COMPLETAR: itera por los jugadores en el ranking
        private:
                map<string, int>::iterator it;

        public:
                iterator() {}
                pair<const string, int> * operator->(){
                        return &(*it);
                }

                iterator &operator++()
                {
                        ++it;
                        return *this;
                }

                iterator &operator--()
                {
                        --it;
                        return *this;
                }

                pair<const string, int> &operator*()
                {
                        return *it;
                }

                bool operator==(const iterator &i) const
                {
                        return i.it == it;
                }

                bool operator!=(const iterator &i) const
                {
                        return i.it != it;
                }
                friend class Ranking;
        };
        class const_iterator
        {
                // COMPLETAR: itera por los jugadores en el ranking
        private:
                map<string, int>::const_iterator it;

        public:
                const_iterator() {}

                const_iterator &operator++()
                {
                        ++it;
                        return *this;
                }

                const_iterator &operator--()
                {
                        --it;
                        return *this;
                }

                const pair<const string, int> &operator*()
                {
                        return *it;
                }

                bool operator==(const const_iterator &i) const
                {
                        return i.it == it;
                }

                bool operator!=(const const_iterator &i) const
                {
                        return i.it != it;
                }
                friend class Ranking;
        };

        iterator begin()
        {
                iterator i;
                i.it = datos.begin();
                return i;
        }

        const_iterator begin() const
        {
                const_iterator i;
                i.it = datos.cbegin();
                return i;
        }

        iterator end()
        {
                iterator i;
                i.it = datos.end();
                return i;
        }
        const_iterator end() const
        {
                const_iterator i;
                i.it = datos.cend();
                return i;
        }

        // LImpia el ranking
        void clear();

        // operadores de entrada y salida.
        friend istream &operator>>(istream &is, Ranking &R);
        friend ostream &operator<<(ostream &os, const Ranking &R);
};

#endif // __RANKING__H
