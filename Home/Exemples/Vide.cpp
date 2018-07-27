// Fichier './Exemples/Vide.cpp'

#include <iostream>
using namespace std ;

class Rien        // Aucune donnee membre pour essayer sizeof
{ public:
     int Identite(int t) { return t; }
} ; 

int main( void) {   Rien a ;

   cout << "identi( 6)==" << a.Identite( 6) << endl ;
   cout << endl ;
   cout << "sizeof a ==" << sizeof a << endl ;     // ???
   cout << "octet 1: >" << (*(char *)&a) << "<\n" ;
   cout << "octet 1: >" << (int)(*(char *)&a) << "<\n" ;
   cout << "octet '\\0': >" << '\0' << "<\n" ;
   return 0 ;
}                             // Fin de './Exemples/Vide.cpp'
