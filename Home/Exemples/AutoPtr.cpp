// Fichier './Exemples/AutoPtr.cpp'

#include <iostream>   // cout, endl
#include <cstring>    // strcpy()
#include <memory>     // auto_ptr

class Contact {  // ----------------------------------------------- 70
    char Nom[ 20] ; int  Age ;

  public:
    Contact( const char*S, int i) { strcpy( Nom, S); Age=i;
        std::cout << "Constructeur de " << S << "\n" ; }
    ~Contact() { std::cout << "Destructeur de " << Nom << "\n";}
    size_t Sizeof( void) const { return sizeof *this ; }
    char const *GetNom( void) const { return Nom;}
} ;

int main( void) {  // --------------------------------------------- 70

    Contact *p0( new Contact( "c0", 0)) ;
    Contact *p1 = new Contact( "c1", 1) ;
    Contact *p2( new Contact( "c2", 2)) ;

    std::auto_ptr< Contact> p3(  new Contact( "c3", 3)) ;
//  std::auto_ptr< Contact> p4 = new Contact( "c4", 4) ; // Non def-1-
//  Contact *p5; p5 = p3 ;                          // Non definie -2-
//  std::auto_ptr< Contact> p6 ; p6 = p2 ;          // Non definie -1-

    std::cout << "p3 pointe vers " << p3->GetNom() << '\n' ;
    { std::auto_ptr< Contact> p7 ; p7 = p3 ; }
    std::cout << "Apres destruction de c3 via p7\n" ;
//  std::cout << "p3 vaut " << p3 << std::endl ;    // Non definie -3-
//  std::cout << "p3 pointe vers " << p3->GetNom() << '\n' ; // -4-

//  delete p1 ;                   // oups, oubli de faire p1=NULL; -5-
    std::auto_ptr< Contact> p8( p1) ; // sinon plantage detecte glibc
    p8.reset( p2) ;

    std::cout << "c0 n'est jamais detruit :o(\n" ;              // -6-
    return 0 ;
}                                   // Fin de './Exemples/AutoPtr.cpp'
