// Fichier './Corriges/Face/Face.h'

#ifndef FACE_H_INCLUDED
#define FACE_H_INCLUDED
#include <stdlib.h>
#include <time.h>
#include "../Rand/Rand.h"


class De {

    public:
        enum Face { Un=1, Deux=2, Trois=3, Quatre=4, Cinq=5, Six=6 } ;

    public:
        // Un seul constructeur : Le constructeur vide
        De( void) {
            lance();
        }

        // Fait rouler le De
        Face lance( void) {
            switch( Rand( 6)) {
                case 1 : return face = Un ;
                case 2 : return face = Deux ;
                case 3 : return face = Trois ;
                case 4 : return face = Quatre ;
                case 5 : return face = Cinq ;
                case 6 : return face = Six ;
            } ;
            // Manque un cas: provoque le Warning a la compilation
            // Faire: lever une exception par 'throw quelquechose'
        }

        // Retourne la valeur du De
        Face valeur( void) const {
            return face;
        }

    private:
        Face face;

} ;
#endif                       // Fin de './Corriges/Face/Face.h'
