// Fichier de './Exemples/MonMax.cpp'
#include <iostream>
#include <string>
using std::cout; using std::endl ; using std::string ;

template< class T >
const T &MonMax( const T &x, const T &y) { return x>=y ? x : y ; }

int main( void) {
    int i=4, j=3 ;
    double pi = 3.14, e = 2.79 ;
    char s1[]="ab", s2[]="za" ;
    string t1( "AB"), t2( "ZA") ;

    cout << "MonMax = " << MonMax( i, j)   << endl ;
    cout << "MonMax = " << MonMax( pi, e)  << endl ;
    cout << "MonMax = " << MonMax( s1, s2) << endl ;
    cout << "MonMax = " << MonMax( s2, s1) << endl ;
    cout << "MonMax = " << MonMax( t1, t2) << endl ;
//    cout << "MonMax = " << MonMax( i, pi)  << endl ;
    cout << "MonMax = " << MonMax<double>( j, pi)  << endl ;
    cout << "MonMax = " << MonMax<int>( j, pi)  << endl ;
    return 0 ;
}                  // Fin de './Exemples/MonMax.cpp'
