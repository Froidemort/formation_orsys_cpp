// debut de ./Exemples-C++11/NewCtor/NewCtor.cpp
#include <iostream>                     // std::cerr
#include <cstring>                      // std::strlen
// NB: Ce fichier est inclus depuis ../Swap/Swap.cpp ... pas terrible ...

// #define AVEC_CTOR_MOVE               // Bonne pratique du C++11
// #define AVEC_CTOR_MOVE_DELETE        // Simple curiosite


#ifdef AVEC_CTOR_MOVE                    // Cette option est prioritaire
    #undef AVEC_CTOR_MOVE_DELETE
#endif


class T {        // Classe allouant de la memoire
  public:
                  // Constructeur fonctionnel ------------------------ 73
    T( char const* s) {
        _GrosContenu=(char*)malloc( sizeof(char) * (std::strlen( s)+1)) ;
        char* t= _GrosContenu ;
        while ( (*t++=*s++) != '\0') ;
        std::cerr << "(debug) ctor fonctionnel: _GrosContenu >" ;
        std::cerr << _GrosContenu << "<\n" ;
        // A priori _GrosContenu est toujours != nullptr // sauf YYYY
    }



                  // Destructeur (obligatoire) ----------------------- 73
    ~T() {
        if ( _GrosContenu ) {
            std::cerr << "(debug) dtor >" << _GrosContenu << "<\n" ;
        } else {
            std::cerr << "(debug) dtor d'un objet vide de son contenu\n";
        }
        if ( _GrosContenu ) free( _GrosContenu) ;
    }



                // Constructeur de copie (obligatoire) --------------- 73
    T( T const& a) {
        _GrosContenu = (char*)malloc( sizeof (char) * a.Taille()) ;
        char const* s = a.GrosContenu(); char* t= _GrosContenu ;
        while ( (*t++=*s++) != '\0') ;
        std::cerr << "(debug) ctor de copie pour lvalues" << '\n' ;
    }
                // Surcharge de l'affectation par copie (obligatoire) ---
    T& operator=( T const& a) {
        if ( this != &a ) {
            char* tmp = (char*)malloc( sizeof (char) * a.Taille()) ;
            char const* s = a.GrosContenu() ; char* t=tmp ;
            while ( (*t++=*s++) != '\0') ;
            free( _GrosContenu) ;
            _GrosContenu = tmp ;
        }
        std::cerr << "(debug) affectation '=' par copie pour lvalues\n" ;
        return *this;
    }



#if defined( AVEC_CTOR_MOVE)
                // Constructeur de copie par deplacement ------------- 73
    T( T&& a) {
        _GrosContenu = a._GrosContenu ;
        a._GrosContenu = nullptr;                                 // YYYY
        std::cerr << "(debug) ctor de copie pour rvalues" << '\n' ;
    }
#elif defined( AVEC_CTOR_MOVE_DELETE)
    T( T&& a) =delete ;
#endif
                // Surcharge de l'affectation par deplacement -----------
#if defined( AVEC_CTOR_MOVE) || defined( AVEC_CTOR_MOVE_DELETED)
    T& operator=( T&& a) {
        if ( this != &a ) {
            _GrosContenu = a._GrosContenu;
            a._GrosContenu = nullptr ;                            // YYYY
        }
        std::cerr << "(debug) affectation '=' par move pour rvalues\n" ;
        return *this;
    }
#endif



                // Get'eurs ------------------------------------------ 73
    size_t Taille( void) const  {
        return std::strlen( _GrosContenu) +1 ;
    }
    char const* GrosContenu( void) const  {
        return _GrosContenu ;
    }
    void Dump( void) const {
        std::cerr << GrosContenu() << " (taille " << Taille() << ")\n";
    }


                // Donnees membres privees de la classe enorme ------- 73
  private:
      char* _GrosContenu ;

} ; // fin de 'class T'



#if !defined( SWAP_CPP_FILE) && !defined( IS_CONSTRUCTABLE_CPP_FILE)
int main( void) {       // ------------------------------------------- 73

    std::cerr << "\ncree et supprime 1 objet:\n";
    { T D( "denis") ; }


    std::cerr << "\ncree 2 objets:\n";
    T D( "denis"), E( "tania") ;

    std::cerr << "\ncree 1 objet par copie d'une lvalue:\n";
    T C( D) ;

    std::cerr << "\naffectation par copie d'une lvalue:\n";
    C=E ;

    std::cerr << "\ncree 1 objet par copie d'une rvalue:\n";
    T F( T( "mathieu")) ;

    std::cerr << "\naffectation par copie d'une rvalue:\n";
    C=T( "charlie") ;

    std::cerr << "\nfin du programme\n";
    return 0;
}
#endif            // fin de fichier
