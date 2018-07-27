// Fichier './Exemples/Civil.c'

// Compiler 'cc -w Civil.c -o a.out' 
// '-w' supprime tous les warnings, sauf introduits par '-W'

#include <stdio.h>

// 'struct Personne' est ignore: objet sans taille et warning suivant
// warning: declaration does not declare anything [enabled by default]
struct Personne {
    enum EtatCivil { M, Mlle, Mme } ;
} ;

int main( void) {

    enum EtatCivil ec ;

    ec = Mlle ;
    printf( "sizeof==%zd et ec==%d\n", sizeof (struct Personne), ec) ;
    return 0 ;
}                                // Fin de './Exemples/Civil.c'
