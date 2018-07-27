// Fichier './Exemples/ToUpper.cpp'

#include <string>         // header du C++
#include <iostream>
using namespace std ;
 
int main( void) {

    string c ; c.assign( "denis Gillain") ;
    int lg=c.length() ;            // Une methode

    for( int i=0; i<lg; i++)
         c[ i] = toupper( c[ i]) ; // Une fonction

    cout << "string: "<< c << endl ;
    return 0 ;
}

// Fin de './Exemples/ToUpper.cpp'
