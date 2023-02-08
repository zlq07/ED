#include <iostream>
#include <fstream>
#include "palabra.h"
#include "palabras.h"


int main(int argc,char * argv[]){
    if (argc!=2){
        cout<<"Los parametros son "<<endl;
        cout<<"1.- El fichero con el diccionario"<<endl;
        return 0;
    }
    //Abrimos el fichero y testeamos que todo va bien.
    ifstream f (argv[1]);
    if (!f){
        cout<<"No puedo leer el fichero "<<argv[1]<<endl;
        return 0;
    }
    //SECTION 0.___________________________________________________
    //Leemos el idioma del diccionario y la linea de comentario
    string idioma;
    f>>idioma;
    f.ignore(256,'\n');
    cout<<"Idioma del diccionario es "<<idioma<<endl;
    //leemos la linea de comentario
    string linea;
    getline(f,linea);


    //________________________________________________________________
    //SECTION 1.
    // Comprobamos que la clase palabra funciona bien.

    //Comprobamos el constructor por defecto
    Palabra mipalabra;

    //Comprobamos el oeprador >>, insertSinonimos

    f>>mipalabra;

    //Comprobamos el operator <<
    cout<<"La palabra leida es :";
    cout<<mipalabra<<endl;
    cout<<"Pulsa un tecla para continuar...."<<endl;
    cin.get();

    cout<<"Tipo: "<<mipalabra.getTipo()<<endl;
    cout<<"Palabra: "<<mipalabra.getPalabra()<<endl;

    //Comprobacion de los sinonimos
    cout<<"El numero de sinonimos es "<<mipalabra.numSinonimos()<<endl;
    
    //Imprimimos los sinonimos
    if (mipalabra.numSinonimos()>0){
        cout<<"Los sinonimos son:";
        for (int i=0;i<mipalabra.numSinonimos();i++){
            cout<<mipalabra.getSinonimo(i)<<";";
        }

        //Probamos a borrar un sinonimo
        cout<<"Vamos a borrar el sinonimo "<<mipalabra.getSinonimo(0)<<endl;
        mipalabra.eraseSinonimo(mipalabra.getSinonimo(0));
        //Comprobacion de los sinonimos tras el borrado
        cout<<"El numero de sinonimos es "<<mipalabra.numSinonimos()<<endl;
        //Imprimimos los sinonimos
        cout<<endl;
        cout<<"Los sinonimos son:";
        for (int i=0;i<mipalabra.numSinonimos();i++){
            cout<<mipalabra.getSinonimo(i)<<";";
        }
    }
    cout<<endl<<"Pulsa un tecla para continuar...."<<endl;
    cin.get();
   
    //________________________________________________________________
    //SECTION2. Comprobamos los iterator_sinonimos
    cout<<"Otra forma de ver los sinonimos con iteradores...."<<endl;
    Palabra::iterator_sinonimos it;
    for (it=mipalabra.begin(); it!=mipalabra.end(); ++it)
        cout<<*it<<endl;

    cout<<endl<<"Pulsa un tecla para continuar...."<<endl;
    cin.get();


    //Nos colocamos al principio del fichero
    f.seekg(ios::beg);

/*
    //________________________________________________________________
    //SECTION3.
    // Comprobaci�n del TDA Palabras: Constructor operator>> operator<<, insert, esta
    Palabras mispalabras;
    f>>mispalabras;
    cout<<"Las palabras leidas son :"<<endl;
    //debe aparecer ordenados por palabra.
    cout<<mispalabras;
    cout<<"El numero de palabras es "<<mispalabras.size()<<endl;
 
    //Comprobamos que erase funciona
    string w,t;
    cout<<"Dime una palabra ";
    getline(cin,w);
    cout<<"Dime su tipo ";
    cin>>t;
    cin.clear();
    auto iter=mispalabras.find(t,w);
    if (iter!=mispalabras.end()){
      cout<<"Borrando "<<*iter<<endl;
      mispalabras.erase(w,t);
    }
    cout<<"Ahora el numero de palabras es "<<mispalabras.size()<<endl;
    cout<<"Pulse una tecla para continuar...."<<endl;
    cin.get();
    cout<<"Las palabras son:"<<endl;
    cout<<"Pulse una tecla para continuar...."<<endl;
    cin.get();
    //Probamos el operator []

    for (int i=0;i<mispalabras.size();i++)
        cout<<mispalabras[i]<<endl;
    cout<<"Pulse una tecla para continuar...."<<endl;
    cin.get();


    //Hacemos lo mismo con los iteradores
    cout<<"Ahora mostramos usando los iteradores...."<<endl;
    cout<<"Pulse una tecla para continuar...."<<endl;
    cin.get();
    Palabras::iterator it2;
    for (it2=mispalabras.begin();it2!=mispalabras.end();++it2)
        cout<<*it2<<endl;
    cout<<"Pulse una tecla para continuar...."<<endl;
    cin.get();


    //________________________________________________________________
    //Section 4.
    //Comprobamos la obtenci�n de otro objeto palabras ordenado por tipo y a igualdad de tipo
    //ordenado por palabra.
    cout<<"Vamos a obtener ordenadas...(esto puede tardar como  n*n (peor) o n*log(n) (mejor))"<<endl;
    Palabras otraspalabras=mispalabras.getOrdenadasTipo();
    cout<<"Palabras ordendas por tipo y a igualdad por palabra...."<<endl;
    cout<<"Pulse una tecla para continuar...."<<endl;
    cout<<otraspalabras<<endl;
    cout<<"Pulse una tecla para continuar...."<<endl;
    cin.get();

    //________________________________________________________________
    //Section 5.
    //Obtenemos todos los tipos diferentes de palabras en el diccionario de forma ordenada
    vector<string> tipos=mispalabras.getDiferentTipos();
    cout<<"El n�mero de tipos es "<<tipos.size()<<" y son :"<<endl;

    for (int i=0;i<tipos.size();i++){
        cout<<tipos[i]<<endl;
    }
    cout<<"Pulse una tecla para continuar...."<<endl;
    cin.get();

    //Conseguimos las palabras de un determinado tipo
    cout<<"Dime el tipo que quieres consultar ";
    string tipo_consultar;
    cin>>tipo_consultar;
    Palabras palabrastipo=mispalabras.getPalabrasTipo(tipo_consultar);
    cout<<"Las palabras con tipo "<<tipo_consultar<< "son "<<endl;
    cout<<palabrastipo<<endl;
    cout<<"Pulse una tecla para continuar...."<<endl;
    cin.get();

    //Obtenemos los tipos de una determinada palabra
    string p;
    cout<<"Dime una palabra para obtener sus tipos: ";
    getline(cin,p);
    vector<string> tiposp=mispalabras.getTipoPalabra(p);
    cout<<"Los tipos son: "<<endl;
    for (int i=0;i<tiposp.size();i++)
        cout<<tiposp[i]<<endl;

    cout<<"Pulse una tecla para continuar...."<<endl;
    cin.get();

    //________________________________________________________________
    //Section 6.-
    //Comprobar si dos palabras son sinonimas
    cout<<"Dime un tipo de palabra ";
    cin>>tipo_consultar;
    cin.ignore(256,'\n');
    cout<<endl<<"Dime las dos palabras para ver si son sinonimos ";
    string p1,p2;
    cout<<endl<<"Palabra 1: ";
    getline(cin,p1);
    cout<<endl<<"Palabra 2: ";
    getline(cin,p2);
    if (mispalabras.areSinonimos(p1,p2,tipo_consultar))
        cout<<"Son sinonimos "<<endl;
    else
        cout<<"No son sinonimos"<<endl;
*/

}
