// Fichier './Exemples/ConvRef.cpp'

int f( int &) ;             int g( const int &) ;
int ff( double &) ;         int gg( const double &) ;

int main( void) {

    int i=5 ;       const int j=8 ;

    f( i) ;    // -ok- 'f' peut modifier i
//  f( j) ;    // reference 'int&' impossible vers 'const int'
//  f( 6) ;    // reference non-const 'int&' impossible vers rvalue
//  ff( i) ;   // reference 'double&' impossible vers 'int'
//  ff( j) ;   // reference 'double&' impossible vers 'const int'
//  ff( 6) ;   // reference non-const 'double&' impossible vers rvalue

    g( i) ;    // -ok- 'g' ne modifiera pas i
    g( j) ;    // -ok-
    g( 6) ;    // -ok-
    gg( i) ;   // -ok- empilement d'une var intermediaire (double)i
    gg( j) ;   // -ok- empilement d'une var intermediaire (double)j

    return 0 ;
}   // Fin de './Exemples/ConvRef.cpp'
