// Fichier './Exemples/Civil.cpp'
// Compiler 'g++ -w Civil.cpp -o a.out' 
#include <stdio.h>  // '-w' supprime les warnings sauf -W.. explicites

struct Personne {
    enum EtatCivil { M, Mlle, Mme } ;
} ;

int main( void) {

    // enum EtatCivil ec ;   // Erreur C++: tout n'est pas compatible
    Personne::EtatCivil ec ; // C++: le mot clef 'enum' est facultatif

    // ec = Mlle ;           // Erreur en C++
    ec = Personne::Mlle ;
                             // Ci dessous: 'struct' est facultatif
    printf( "sizeof==%zd et ec==%d\n", sizeof (Personne), ec) ;
    return 0 ;
}                            // Fin de './Exemples/Civil.cpp'
