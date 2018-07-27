#include <functional>        // std::ref()
#include <iostream>          // std::cout std::endl
using std::cout;

template <class C>
void func(C c){
    cout << "     dans f() c==" << c << "  puis  " ;
    c += 1;
    cout << "c==" << c << std::endl ;
}

int main( void) {  // ------------------------------------------------ 73
    int x{ 3};                  // Initialisation uniforme du C++11
    cout << "x==" << x << " apres creation de x\n" ;
    func( x);                   // x n'est pas modifie (facon du C)
    cout << "x==" << x << " car passage d'argument par valeur\n" ;
    func( &x);    // incremente une variable intermediaire 'adresse de x'
    cout << "x==" << x << " : le template ne peut pas faire...\n" ;
    func( (int&)x);             // Reference vers x : cela marche-t-il ?
    cout << "x==" << x << "   cela a-t-il marche ?\n" ;
    int& y=x ; func( y);        // Autre technique de reference vers x...
    cout << "x==" << x << "   et cela ?\n" ;
    func( std::ref( x));        // Reference << explicite >>
    cout << "x==" << x << "   et maintenant ?\n" ;
}    // Fin de fichier
