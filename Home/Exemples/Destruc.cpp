// Fichier './Exemples/Destruc.cpp'

#include <iostream>
using namespace std ;

class Polygone { //------------------------------------------
    public:
        Polygone() {}
        ~Polygone() { cout << "destructeur Polygone\n" ; }
} ;     // ERREUR ci dessus: le destructeur doit etre virtuel

class Rectangle : public Polygone { //-----------------------
    public:
        Rectangle() : Polygone() {}
        ~Rectangle() { cout << "destructeur Rectangle\n" ; }
} ;

int main( //-------------------------------------------------
     void
) {
    Polygone *p = new Rectangle() ;
    delete p ;
}                     // Fin de './Exemples/Destruc.cpp'
