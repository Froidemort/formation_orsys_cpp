// Fichier ./Home/ClassFace/ClassFace.cpp'

#include <iostream>                // std::cout std::cerr



class Face {   // ------------------------------------------------- 70
  protected:   // Constructeur accessible seulement dans la classe De
    Face( void) noexcept {
        // std::cerr << "constructeur Face vide\n" ;
        static bool InitOk = false ;
        if ( ! InitOk ) {
            InitOk=true; srand( time( NULL));
        }
        Set() ;
    }
    Face Get( void)     const noexcept { return _face ; }
    Face GetFace( void) const noexcept { return Get() ; }

  private:                                    // Constructeur +
    Face( int i) throw( std::runtime_error) { // Conversion int->Face
        std::cerr << "conversion d'un 'int' en Face\n" ;
        if ( i<=0 || i>=7 ) {
            throw std::runtime_error( "Face::Face(): de impossible");
        } else _face = i ;
    }

  public:
    operator int() const { return _face ; }   // Conversion Face->int

  protected:    // Seul le de peut changer une Face (arbitraire)
      void Set( void)     noexcept { _face = rand()%6 +1 ; }
      void SetFace( void) noexcept { Set() ; }
      void roule( void)   noexcept { Set() ; }

  private:
    int _face ;

} ;    // fin de class Face



// L'affichage du De se fait par affichage de sa face  ------------ 70
inline std::ostream& operator<<( std::ostream& c, Face const& f)
throw( std::runtime_error) { 
    switch ( (int)f ) {
        case 1 : return c << " -un- " ;
        case 2 : return c << " -de- " ;
        case 3 : return c << " -tr- " ;
        case 4 : return c << " -qu- " ;
        case 5 : return c << " -ci- " ;
        case 6 : return c << " -si- " ;
    }
    throw std::runtime_error( "operator<<() l'objet n'est pas un de");
}    // fin de operator<<( Face const&)



class De : public Face {  // -------------------------------------- 70
  public:
    De( void) noexcept {
        std::cerr << "constructeur De vide\n" ;
    }
    Face valeur( void) const noexcept { return Face::GetFace() ; }
    Face GetFace( void) const noexcept { return Face::GetFace() ; }

};  // fin de class De



int main( void) {   // -------------------------------------------- 70

    De d, Tab[ 5] ;
    std::cout    <<    "Un de    : " << d << '\n' ;
    std::cout    <<    "Un autre : " << De() << '\n' ;

    std::cout    <<    "Tableau de 5 des:" ;
    for ( size_t i=0; i<5; i++) {
        std::cout << " " << Tab[ i] ;
    }
    std::cout    << '\n' ;

    std::cout    <<    "Objet errone : " << Tab[ 10] << '\n' ;
    return 0 ;
}    // fin de main()

// fin de fichier
