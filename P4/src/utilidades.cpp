#include "utilidades.h"

// Obtiene el conjunto diferencia entre los conjuntos s1 y s2
set<string> WordDiference(const set<string> &s1, const set<string> &s2)
{
    set<string>::iterator it = s1.cbegin();
    set<string>::iterator it1 = s2.cbegin();
    set<string> d; // diferencia
    while (it != s1.cend())
    {
        while (it1 != s1.cend())
        {
            if(*it != *it1){
                d.insert(*it);
            }
            it1 ++;
        }
        it++;
    }

    return d;
}

// Obtiene el número de letras en las que son diferentes las cadenas s1 y s2
int DistanceWords(const string &s1, const string &s2)
{
    int cont = 0;
    for (int i = 0; i < s1.size(); i++)
    {
        for (int j = 0; j < s2.size(); j++)
        {
            if (s1[i] != s2[i])
            {
                cont++;
            }
        }
    }
    return cont;
}

// Obtiene el conjunto de palabras de s que se diferencia de w en solo una letra
set<string> getWordDistanceOne(const set<string> &s, string w)
{
    set<string>::iterator it = s.cbegin();
    set<string> c;
    while (it != s.cend())
    {
        if (DistanceWords(*it, w) == 1)
        {
            c.insert(*it);
        }
        it ++;
    }
    return c;
}



// Devuelve true si la palabra w esta en el camino de la raiz del arbol al nodo n
bool EstaEtiquetaCamino(ArbolGeneral<string> &a, ArbolGeneral<string>::Nodo n, const string &w)
{
    bool result = false;
    if (a.etiqueta(n) == w)
    {
        result = true;
    }
    return result;
}

// Crea el Arbol General a partir del nodo n de forma que la diferencia en
// letras de las palabras que almacena un nodo y su padre no puede ser mayor que 1.
//  La variable lc permite no ramificar el arbol más all de lw.
// Es decir se llama con lc=0 y cuando lc alcanza lw por una rama se termina.
void CreaTree(ArbolGeneral<string> &a, ArbolGeneral<string>::Nodo n, const set<string> &pp, int lc, int lw)
{
    if (a.Nulo(n))
        return;
    if (lc == lw)
    { // cortamos la ramificación
        return;
    }

    set<string> ww = getWordDistanceOne(pp, a.etiqueta(n));
    if (ww.size() == 0)
        return;
    else
    {

        for (auto it = ww.begin(); it != ww.end(); ++it)
            if (!EstaEtiquetaCamino(a, n, *it))
            {
                ArbolGeneral<string> rama(*it);
                a.insertar_hijomasizquierda(n, rama);
            }

        ww.clear();
        if (a.Nulo(a.hijomasizquierda(n)))
            return;
        ArbolGeneral<string>::Nodo aux = a.hijomasizquierda(n);

        for (aux = a.hijomasizquierda(n); a.Nulo(aux) == false; aux = a.hermanoderecha(aux))
        {
            CreaTree(a, aux, pp, lc + 1, lw);
        }
    }
    return;
}

// Convierte una lista a un set
set<string> ConvertList_Set(const list<string> &s)
{
    set<string> aux;
    for (auto it = s.cbegin(); it != s.cend(); ++it)
    {
        aux.insert(*it);
    }
    return aux;
}

// Obtiene la longitud del mayor camino dentro del arbol
int MaxWay(ArbolGeneral<string> &a, ArbolGeneral<string>::Nodo n)
{
    // PASOS A SEGUIR:
    // 1. - Si el nodo es nulo devolver - 1
    if (n == nullptr)
    {
        return -1;
    }
    else
    {
        // 2. - recorrer los hijos y obtener la longitud del maximo camino entre los hijos.Devolver esa maxima longitud + 1.
        int hl = MaxWay(a,n->drcha);
        int hr = MaxWay(a,n->izqda);

        return max(hl,hr) + 1;
    }
}

// Obtiene a partir de una palabra s y un conjunto de palabras todas las palabras que se diferencia
// en sola una letra. Y además el mayor camino que se obtendría si ramificamos el arbol de jugadas
// desde esa palabra.
pair<int, set<string>> PosiblesPalabrasDesde(const string &s, const set<string> &pp)
{
    ArbolGeneral<string> a;

    a.AsignaRaiz(s);

    set<string> dif = pp;
    dif.erase(s);
    ArbolGeneral<string>::Nodo n = a.raiz();

    CreaTree(a, n, dif, 0, 4);

    int maxway = MaxWay(a, a.raiz());

    set<string> nexts;
    if (maxway <= 0)
        return pair<int, set<string>>(maxway, nexts);
    n = a.hijomasizquierda(n);
    for (; !a.Nulo(n); n = a.hermanoderecha(n))
        nexts.insert(a.etiqueta(n));
    return pair<int, set<string>>(maxway, nexts);
}
