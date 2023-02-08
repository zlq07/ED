#include "../include/palabra.h"
#if CUAL_COMPILA==1
    #include "palabra1.cpp"
#elif CUAL_COMPILA==2
    #include "palabra2.cpp"
#endif
bool operator<(const Palabra &p1, const Palabra &p2){
 return (p1.getTipo()<p2.getTipo() ||
         (p1.getTipo()==p2.getTipo() && p1.getPalabra()<p2.getPalabra()));

}

bool operator==(const Palabra &p1, const Palabra &p2){
 return (p1.getTipo()==p2.getTipo() && p1.getPalabra()==p2.getPalabra());

}
