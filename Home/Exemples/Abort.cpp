// Fichier './Exemples/Abort.cpp'

#include <cstdlib> // version C++ du '#include <stdlib.h>'

// Quel code retour pour le shell ?
// sous Linux: 134 parce que 128+6 (SIGABRT==6)

int main( void) {
    abort() ;
    return 0 ;
}

// Fin de './Exemples/Abort.cpp'
