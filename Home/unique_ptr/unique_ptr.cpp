// Debut de Home/unique_ptr/unique_ptr.cpp
#pragma GCC diagnostic ignored "-Wunused-variable"     // GCC et clang
#pragma GCC diagnostic ignored "-Wunused-but-set-variable" // GCC seul

#include <iostream>    // std::cout
#include <memory>      // std::unique_ptr
#include <ctime>       // std::time()

using std::cout ;
using std::unique_ptr ;

inline void VerifieSalaire( void) throw( std::logic_error) { // --- 70
    cout << "Entre dans " << __func__ << '\n' ;
    throw std::logic_error(
        "Le salaire d'un developpeur ne peut pas etre bas"
    ) ;
}   // fin de VerifieSalaire()

// #define MODIF_1
// #define MODIF_2



class Foo {  // --------------------------------------------------- 70
  public:
    Foo( char const* mesg) : _f( mesg) {
        cout << "Ctor foo( " << _f << ")\n" ;
    }
    Foo( Foo const& f) : _f( "copie de '") {
        _f += f._f ; _f += "'" ;
        cout << "Ctor copie de foo( " << _f << ")\n" ;
    }
    Foo( Foo&& f) : _f( "move de '") {
        _f += f._f ; _f += "'" ;
        cout << "Ctor move de foo( " << _f << ")\n" ;
    }
    ~Foo() { cout << "Dtor ~foo() " << _f << '\n' ; }
    std::string const& GetMesg( void) const noexcept { return _f; }

  public:
    void AjoutePlus( void) noexcept { _f += '+' ; }

  private:
    std::string _f ;
} ; // fin de class Foo {}



int main( void) { // ---------------------------------------------- 70

    Foo o1( "o1-pile") ;             // Objet dans la pile
    Foo& r1 = o1 ;                   // Pas de nouvel objet, reference
    Foo* p1 = new Foo( "*p1-tas") ;  // Objet dans le tas

#ifdef MODIF_1
    if ( time( nullptr)%2 ) return 0 ;
#endif 

#ifdef MODIF_2
    try { VerifieSalaire() ;
          delete p1 ;
          return 0 ;
    } catch ( std::logic_error const& e ) {
          cout<< "Dans le traiteur d'exceptions: " << e.what() <<'\n';
          return 0 ;
    }
#else
    delete p1 ;
    return 0 ;
#endif 
}   // fin de main()
