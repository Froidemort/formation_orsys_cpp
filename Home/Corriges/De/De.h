// Fichier 'Corriges/De/De.h'

#ifndef DE_H_INCLUDED
#define De_H_INCLUDED

#include "../Rand/Rand.h"

// #define WITH_ENUM_FACE // A definir pour tout le projet
#ifdef WITH_ENUM_FACE
    enum Face { Un=1, Deux, Trois, Quatre, Cinq, Six } ;
#else
    typedef unsigned int Face ;
#endif

class De {
  private :
    Face face ;
  public :
    Face valeur(  void) const { return face ; }
    Face lance( void) { return face=(Face)Rand( 6) ; }
    De( void) { lance() ; }
} ;

#endif          // fin de 'Corriges/De/De.h'
