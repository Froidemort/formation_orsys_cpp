// Fichier ./Home/Corriges-C++11/EnumClass/EnumClass.cpp'
#include <iostream>                // std::cout std::cerr

enum class Face { Un=1, Deux, Trois, Quatre, Cinq, Six } ;

std::ostream& operator<<( std::ostream& c, Face const& f)  // ----- 70
throw( std::runtime_error) {
    switch( f ) {
        case Face::Un     : return c << " -un- " ;
        case Face::Deux   : return c << " -de- " ;
        case Face::Trois  : return c << " -tr- " ;
        case Face::Quatre : return c << " -qu- " ;
        case Face::Cinq   : return c << " -ci- " ;
        case Face::Six    : return c << " -si- " ;
    }
    // Ci dessous necessaire pour un objet qui n'est pas un de
    throw std::runtime_error( "Valeur impossible d'une face de de") ;
}   // fin de operator<<()

Face Int2Face( int a) throw( std::runtime_error) {  // ------------ 70
    switch( a ) {
        case 1 : return Face::Un ;
        case 2 : return Face::Deux ;
        case 3 : return Face::Trois ;
        case 4 : return Face::Quatre ;
        case 5 : return Face::Cinq ;
        case 6 : return Face::Six ;
    }
    throw std::runtime_error( "Int2Face(): Convertion impossible") ;
}    // fin de Int2Face()


class De {  // ---------------------------------------------------- 70
  public:
    De( void) noexcept {
        std::cerr << "constructeur vide\n" ;
        roule();
    }
    Face valeur( void) const noexcept { return _face; } ;
    Face roule( void) noexcept {
        static bool InitOk = false ;
        if ( ! InitOk ) {
            InitOk = true ;
            srand( time( NULL)) ;
        }
//      _face = (Face)rand() ; // Le cast doit etre oublie en C++
        _face = Int2Face(rand()%6+1);// A la place on ecrit Int2Face()
        return _face ;
    }    // fin de la methode roule()

  private:
    Face _face ;
};  // fin de class De -------------------------------------------- 70

inline std::ostream& operator<<( std::ostream& c, De const& d)
throw( std::runtime_error) {
    return c << d.valeur() ;
}


int main( void) {  // --------------------------------------------- 70

    De d, Tab[ 5] ;

    std::cout    <<    "Un de    : " << d << '\n' ;
    std::cout    <<    "Un autre : " << De() << '\n' ;

    std::cout    <<    "Tableau de 5 des:" ;
    for ( size_t i=0; i<5; i++) {
        std::cout << " " << Tab[ i] ;
    }
    std::cout    << '\n' ;

    std::cout    <<    "Objet errone : " << Tab[ 10] << '\n' ;
    // 'make valgrind' trouve l'erreur a l'execution par le message:
    // ==19413==   .....  by 0x400F39: main (EnumClass.cpp:75)
    return 0 ;
}   // fin de main()
// fin de fichier
