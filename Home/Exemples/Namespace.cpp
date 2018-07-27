// Fichier './Exemples/Namespace.cpp'

#include <iostream>
using std::cout ; using std::endl ;

namespace gillain
{
    int var = 5;
}

namespace ellipsys
{
    double var = 3.1416;

    namespace xml {
        char var = 'g' ;
    }
}

const char var[] = "4 variables globales" ;

int main( void) {

    cout << gillain::var << endl;
    cout << ellipsys::var << endl;
    cout << ellipsys::xml::var << endl;
    ::std::cout << ::ellipsys::xml::var << endl;
    cout << ::var << endl;
    cout << var << endl;

//    cout << xml::var << endl; // Il faut garder l'imbrication !
// Namespace.cpp: In function 'int main()':
// Namespace.cpp:30:13: error: 'xml' has not been declared

    return 0;
}                             // Fin de './Exemples/Namespace.cpp'
