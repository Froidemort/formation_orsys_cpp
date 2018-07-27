// Fichier './Home/Exemples-C++11/decltype_expr/decltype_expr.cpp'
#include <typeinfo>        // typeid()
#include <iostream>        // std::cout

int main() {   // ---------------------------------------------------- 73

    // x ++x ++++x ++(++x) ++++++x sont des variables, des << lvalues >> 
    int x ; x=2; ++x ; ++++x ; ++++++x=2;        // compile sans souci
    std::cout << "x==" << x << " de type " << typeid( x).name() << '\n' ;

    decltype( x) i ;      // i est une << lvalue >> (ie. une variable)
    i = 8 ; i++ ;
//  (i++)++ ;             // Ne compile pas car i++ n'est pas variable
    std::cout << "i==" << i << " de type " << typeid( i).name() << '\n' ;

    // x+0 (x+0) x++ sont des << rvalues >> (ie. des constantes)
    decltype( x+0) j;     // Compile car x+0 est constante donc j est int
    decltype( x++) n ;    // Compile car x++ est constante donc ...
    decltype( (x+0)) o ;  // ...

    // mais ++x est une lvalue, donc k sera du type int&
//  decltype( ++x) k ;    // Erreur une reference doit etre affectee!
    // tout comme pour (x) qui est aussi une lvalue
//  decltype( (x)) m ;    // Erreur une reference doit etre affectee!

    // Il s'agit d'une instruction de compilation: x n'est pas evalue
    decltype( x++) t ;    // x n'est pas evalue: sa valeur n'a pas change
    std::cout << "x==" << x << " de type " << typeid( x).name() << '\n' ;
    std::cout << "n==" << n << " de type " << typeid( n).name() << '\n' ;

}    // fin de fichier
