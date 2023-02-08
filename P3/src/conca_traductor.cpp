#include "traductor.h"
#include <fstream>
Traductor Concatena_Traductor(const Traductor &t1,const Traductor &t2){
    //completar
}


int main(int argc, char *argv[]){
 if (argc!=4){
    cout<<"Los parametros son:"<<endl;
    cout<<"1.-El nombre del fichero con el traductor 1 idiomas (A,B)"<<endl;
    cout<<"2.-El nombre del fichero con el  traductor 2 idiomas (A,C)"<<endl;
    cout<<"3.-El nombre del fichero con el traductor de salida idiomas (B,C)"<<endl;
    return 0;

 }
 ifstream f1(argv[1]);
 if (!f1){
    cout<<"No se puede abrir el fichero "<<argv[1]<<endl;
    return 0;
 }
 ifstream f2(argv[2]);
 if (!f2){
    cout<<"No se puede abrir el fichero "<<argv[2]<<endl;
    return 0;
 }
 Traductor t1,t2,t3;
 f1>>t1;
 cout<<"Traductor "<<t1.getIdiomaOrigen()<<" a "<<t1.getIdiomaDestino()<<" cargado..."<<endl;

 f2>>t2;
 cout<<"Traductor "<<t2.getIdiomaOrigen()<<" a "<<t2.getIdiomaDestino()<<" cargado..."<<endl;

  //Obtenemos el traductor inverso

  t3=t1.TraductorInverso();

  Traductor tcon=Concatena_Traductor(t3,t2);

  //Salvamos a disco
  ofstream fout(argv[3]);
  if (!fout){
    cout<<"No puedo crear "<<argv[3]<<endl;
    return 0;
  }
  fout<<tcon;
  fout.close();



}
