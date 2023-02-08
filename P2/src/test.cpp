#include <iostream>
#include <fstream>
#include "../include/palabra.h"
#include "../include/palabras.h"

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        cout << "Los parametros son " << endl;
        cout << "1.- El fichero con el diccionario" << endl;
        return 0;
    }
    //Abrimos el fichero y testeamos que todo va bien.
    ifstream f(argv[1]);
    if (!f)
    {
        cout << "No puedo leer el fichero " << argv[1] << endl;
        return 0;
    }
    //SECTION 0.___________________________________________________
    //Leemos el idioma del diccionario y la linea de comentario
    string idioma;
    f >> idioma;
    f.ignore(256, '\n');
    cout << "Idioma del diccionario es " << idioma << endl;
    //leemos la linea de comentario
    string linea;
    getline(f, linea);

    //________________________________________________________________
    //SECTION 1.
    // Comprobamos que la clase palabra funciona bien.

    //Comprobamos el constructor por defecto
    Palabra mipalabra;

    //Comprobamos el oeprador >>, insertSinonimos

    f >> mipalabra;

    //Comprobamos el operator <<
    cout << "La palabra leida es :";
    cout << mipalabra << endl;
    cout << "Pulsa un tecla para continuar...." << endl;
    cin.get();

    cout << "Tipo: " << mipalabra.getTipo() << endl;
    cout << "Palabra: " << mipalabra.getPalabra() << endl;

    //Comprobacion de los sinonimos
    cout << "El numero de sinonimos es " << mipalabra.numSinonimos() << endl;
    //Imprimimos los sinonimos
    if (mipalabra.numSinonimos() > 0)
    {
        cout << "Los sinonimos son:";
        for (int i = 0; i < mipalabra.numSinonimos(); i++)
        {
            cout << mipalabra.getSinonimo(i) << ";";
        }

        //Probamos a borrar un sinonimo
        cout << "Vamos a borrar el sinonimo " << mipalabra.getSinonimo(0) << endl;
        mipalabra.eraseSinonimo(mipalabra.getSinonimo(0));
        //Comprobacion de los sinonimos tras el borrado
        cout << "El numero de sinonimos es " << mipalabra.numSinonimos() << endl;
        //Imprimimos los sinonimos
        cout << endl;
        cout << "Los sinonimos son:";
        for (int i = 0; i < mipalabra.numSinonimos(); i++)
        {
            cout << mipalabra.getSinonimo(i) << ";";
        }
    }
    cout << endl
         << "Pulsa un tecla para continuar...." << endl;
    cin.get();

    //Nos colocamos al principio del fichero
    f.seekg(ios::beg);
    //________________________________________________________________
    //SECTION2.
    // ComprobaciÛn del TDA Palabras: Constructor operator>> operator<<, insert, esta
    Palabras mispalabras;
    f >> mispalabras;
    cout << "Las palabras leidas son :" << endl;
    //debe aparecer ordenados por palabra.
    cout << mispalabras;
    cout << "El numero de palabras es " << mispalabras.size() << endl;

    //Comprobamos que erase funciona
    string w, t;
    cout << "Dime una palabra ";
    cin >> w;
    cout << "Dime su tipo ";
    cin >> t;
    mispalabras.erase(w, t);
    cout << "Ahora el numero de palabras es " << mispalabras.size() << endl;
    cout << "Pulse una tecla para continuar...." << endl;
    cin.get();

    //________________________________________________________________
    //Section 3.
    //Comprobamos la obtenciÛn de otro objeto palabras ordenado por tipo y a igualdad de tipo
    //ordenado por palabra.

    Palabras otraspalabras = mispalabras.getOrdenadasTipo();
    cout << "Palabras ordendas por tipo y a igualda por palabra...." << endl;
    cout << "Pulse una tecla para continuar...." << endl;
    cout << otraspalabras << endl;
    cout << "Pulse una tecla para continuar...." << endl;
    cin.get();

    //________________________________________________________________
    //Section 4.
    //Obtenemos todos los tipos diferentes de palabras en el diccionario de forma ordenada
    VD<string> tipos = mispalabras.getDiferentTipos();
    cout << "El n˙mero de tipos es " << tipos.size() << " y son :" << endl;
    for (int i = 0; i < tipos.size(); i++)
    {
        cout << tipos[i] << endl;
    }
    cout << "Pulse una tecla para continuar...." << endl;
    cin.get();

    //Conseguimos las palabras de un determinado tipo
    cout << "Dime el tipo que quieres consultar ";
    string tipo_consultar;
    cin >> tipo_consultar;
    Palabras palabrastipo = mispalabras.getPalabrasTipo(tipo_consultar);
    cout << "Las palabras con tipo " << tipo_consultar << "son " << endl;
    cout << palabrastipo << endl;
    cout << "Pulse una tecla para continuar...." << endl;
    cin.get();

    //Obtenemos los tipos de una determinada palabra
    string p;
    cout << "Dime una palabra para obener sus tipos: ";
    getline(cin, p);
    VD<string> tiposp = mispalabras.getTipoPalabra(p);
    cout << "Los tipos son: " << endl;
    for (int i = 0; i < tiposp.size(); i++)
        cout << tiposp[i] << endl;

    cout << "Pulse una tecla para continuar...." << endl;
    cin.get();

    //________________________________________________________________
    //Section 5.-
    //Comprobar si dos palabras son sinonimas
    cout << "Dime un tipo de palabra ";
    cin >> tipo_consultar;
    cin.ignore(256, '\n');
    cout << endl
         << "Dime las dos palabras para ver si son sinonimos ";
    string p1, p2;
    cout << endl
         << "Palabra 1: ";
    getline(cin, p1);
    cout << endl
         << "Palabra 2: ";
    getline(cin, p2);
    if (mispalabras.areSinonimos(p1, p2, tipo_consultar))
        cout << "Son sinonimos " << endl;
    else
        cout << "No son sinonimos" << endl;
}
