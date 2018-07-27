// Debut de './Corriges/String/Test.cpp'

#include "String.h"

int main( void) 
{
    String Essai( "uname") , Rien ;
    cout << Essai << endl ;

    Essai += " -a" ;
    cout << Essai << endl ;

    cout << "rien " << Rien << endl ;
    Rien  += "qqch" ;
    cout << "qqch " << Rien << endl ;
    Rien  += "" ;
    cout << "plus " << Rien << endl ;
    
    Essai -= 5 ;
    cout << Essai << endl ;
    Essai-=1 ; cout << Essai << endl ;
    Essai-=1 ; cout << Essai << endl ;
    Essai-=1 ; cout << Essai << endl ;
    Essai-=1 ; cout << Essai << endl ;
    Essai-=1 ; cout << Essai << endl ;
    Essai-=1 ; cout << Essai << endl ;

    return 0 ;
}

// Fin de './Corriges/String/Test.cpp'
