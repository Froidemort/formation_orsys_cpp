// Fichier './Exemples/RefB.cpp'

// Compiler 'g++ -Wall RefB.cpp -o a.out'

#include <iostream>
using namespace std ;

const int TAILLE_NOM = 20 ;
const int TAILLE_EMAIL = 256 ;

struct Contact {
    char nom[ TAILLE_NOM] ;
    char prenom[ TAILLE_NOM] ;
    char email[ TAILLE_EMAIL];
} ;

void Affiche(
    const Contact &f
) {
    cout << f.nom << " " << f.prenom;
    cout << " " << f.email << endl;
}

int main() 
{
    Contact user = {
        "gillain",    // .prenom = "denis" : C seul
        "denis",      // .nom = "gillain"  : C seul
        "denis.gillain@ellipsys.fr"
    };
    Affiche( user);
    // Manque return 0; pas d'erreur/warning en C++
}   // Fin de './Exemples/RefB.cpp'
