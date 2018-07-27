// Debut de Home/Exemples-C++11/unique_ptr/unique_ptr.cpp
#include <iostream>    // std::cout
#include <memory>      // std::unique_ptr std::move

using std::cout ;
using std::unique_ptr ;

class Foo {  // ------------------------------------------------------ 73
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
    Foo& operator=( Foo const& f) {
        _f = "affectation copie de '" ;
        _f += f._f ; _f += "'" ;
        cout << "Affection copie de foo( " << _f << ")\n" ;
        return *this ;
    }
    Foo& operator=( Foo&& f) {
        _f = "affectation move de '" ;
        _f += f._f ; _f += "'" ;
        cout << "Affection move de foo( " << _f << ")\n" ;
        return *this ;
    }
    ~Foo() { cout << "Dtor ~foo() " << _f << '\n' ; }
    std::string const& GetMesg( void) const noexcept { return _f; }

  public:
    void AjoutePlus( void) noexcept { _f += '+' ; }
    void Affiche( char const* s) noexcept {
        cout << " *** " << s << ": " << _f << '\n' ;
    }

  private:
    std::string _f ;
} ; 



#if !defined( FOO_CPP_FILE) && !defined( SHARED_PTR_CPP_FILE)

static Foo f_0( "f_0") ;       // Quel sera l'ordre des constructeurs -1-
Foo f_1( "f_1") ;
static Foo f_2( "f_2") ;

// ------------------------------------------------------------------- 73
// ci dessous compile tout de meme...          mais ne compile pas en -4-
void func( unique_ptr< Foo> copie) {
    cout << "     dans func()\n" ;
    return ;
}



int main( void) { // ------------------------------------------------- 73

    unique_ptr< Foo> p0( new Foo( "h_0")), ph_1( new Foo( "h_1"));
//  cout << "p0 --> " << p0.GetMesg()  << '\n'; // ne compile pas -2-
    cout << "p0 --> " << p0->GetMesg() << '\n';

//  Foo* p = ph_1 ;                                 // ne compile pas -3-
    Foo& r = *ph_1 ;  // ... mais compile ici, ce qui revient au meme car
    Foo* p = &r ;
    cout << "r --> " <<  r.GetMesg() << '\n';
    cout << "p --> " << p->GetMesg() << '\n';
    // Ci dessous il n'y a aucune raison de faire un delete! Voyons...
//  delete p ;        // comme ci dessous, un pointeur, une reference...
//  delete &r ;       // plantage assure en sortie de programme !
//  delete p0 ;     // Ne compile pas car p0 n'est pas un pointeur

//  func( p0) ;                                   // ne compile pas -4-

    unique_ptr< Foo> p1 ;
    { Foo& r1 = *new Foo( "new-r1") ;
//    p1 = &r1 ;                                    // ne compile pas -5-
//    p1 = std::move( &r1) ;                        // ne compile pas -6-

//    unique_ptr< Foo> p2( p1) ;                    // ne compile pas -7-
//    unique_ptr< Foo> p2( &p1) ;                   // non plus       -7-
      unique_ptr< Foo> p3( std::move( &r1)) ;       // mais la c'est OK

      p3->AjoutePlus() ;
      std::cout << "Combien vaut r1? " << r1.GetMesg()  << '\n' ;
      std::cout << "Combien vaut p3? " << p3->GetMesg() << '\n';    //-8-

//    unique_ptr< Foo> p4( &r1) ;// compile mais va planter pour sur -9-
    }

    // Pour afficher un objet, ou quoi que ce soit il faut verifier qu'il
    // n'a pas ete desalloue tout comme on met nullptr dans les pointeurs
    if ( ! p1   ) cout << " *** p1: vide\n" ; else p1->Affiche( "p1") ;
    if ( ! p0   ) cout << " *** p0: vide\n" ; else p0->Affiche( "p0") ;

    return 0 ;
}
#endif    // fin de fichier
