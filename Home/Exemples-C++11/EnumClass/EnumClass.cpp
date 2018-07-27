// Fichier './Home/Exemples-C++11/EnumClass/EnumClass.cpp'
#include <iostream>
using std::cout ;

int main( void) {  // ------------------------------------------------ 73
    enum class Couleur { blanc, jaune, vert } d=Couleur::blanc ;
    enum class Sens { droite, gauche } e( Sens::droite) ;
    if ( d < Sens::gauche ) cout<< "Erreur... on ne compile plus\n";
    if ( d < 3 ) cout << "Autre erreur, ne compile pas plus\n";
    if ( d > e ) cout << "Autre erreur, ne compile pas plus\n";
    Couleur a ;         // Mais ici warning seul.
}   // fin de fichier
