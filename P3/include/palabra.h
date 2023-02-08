#define CUAL_COMPILA 2
#if CUAL_COMPILA==1
     #include "palabra1.h"
#elif CUAL_COMPILA==2
     #include "palabra2.h"
#endif

bool operator==(const Palabra &p1,const Palabra &p2);

bool operator<(const Palabra &p1,const Palabra &p2);
