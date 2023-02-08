#include <fstream>
#include <iostream>
#include "../include/palabras.h"
#include "../include/palabra.h"

using namespace std;

void AllLower(string &txt)
{
    // convertir todo el txt a minuscula
    for (int i = 0; i < txt.size(); i++)
    {
        txt[i] = tolower(txt[i]);
    }
}

int aparece(const string &txt, const string &s)
{
    int cont = 0;
    int i = 0;
    while (i < txt.size())
    {
        for (int j = 0; j < s.size(); j++)
        {
            while (txt[i] == s[j])
            {
                if (j == s.size() && txt[i + j] == ' ')
                {
                    cont++;
                    i = i + j;
                }
                else
                {
                    i++;
                }
            }
        }
    }
    return cont;
}

int WhereTipo(VD<string> &tipos, string t)
{
    int pos = -1;
    for (int i = 0; i < tipos.size(); i++)
    {
        if (tipos[i] == t)
        {
            pos++;
        }
    }
    return pos;
}

void Contabiliza(const string &mitexto, const Palabras &mispalabras, VD<string> &tipos, VD<int> &count_t)
{
    int pos = 0;
    int k = 0;

    for (int i = 0; i < mispalabras.size(); i++)
    {
        pos = WhereTipo(tipos, tipos[i]);
        k = aparece(mitexto, mispalabras.getDiferentTipos()[i]);
        while (k < 0)
        {
            count_t[k] = pos;
            k--;
        }
    }
}

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        cout << "Los parametros son" << endl;
        cout << "1.-El fichero con el texto de entrada" << endl;
        cout << "2.-El fichero con el disccionario " << endl;
        return 0;
    }

    Palabras mispalabras;
    string mitexto;
    ifstream file(argv[1]);
    if (!file)
    {
        cout << "No existe el fichero " << argv[1] << endl;
        return 0;
    }
    ifstream fdic(argv[2]);
    if (!fdic)
    {
        cout << "No existe el fichero " << argv[1] << endl;
        return 0;
    }

    string a;
    while (getline(file, a))
    {
        mitexto = mitexto + a;
    }
    AllLower(mitexto);

    fdic >> mispalabras;

    VD<string> tipos = mispalabras.getDiferentTipos();

    cout << "Los tipos de las palabras son: " << endl;
    for (int i = 0; i < tipos.size(); i++)
    {
        cout << tipos[i] << endl;
    }
    cin.get();

    VD<int> contabilizador;
    for (int i = 0; i < tipos.size(); i++)
    {
        contabilizador.insert(0, 0);
    }
    Contabiliza(mitexto, mispalabras, tipos, contabilizador);
    for (int i = 0; i < tipos.size(); i++)
    {
        cout << "Tipo " << tipos[i] << " aparece " << contabilizador[i] << endl;
    }
}