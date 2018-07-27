// Fichier './Exemples/Rationnel/Part2.h'
#if defined( PART2) || defined( PART3) || defined( PART4) \
    || defined( PART5)

  private:
    void reduit( void) {
        int i = pgcd( (num > 0) ? num : -num, den) ;
        num /= i ; den /= i ;
    }

  public:
    void Affiche( void) const { std::cout << num << '/' << den; }

    Rationnel &ajoute( const Rationnel &r) {
        int i = pgcd( den, r.den) ;
        int m1 = r.den / i ;
        int m2 = den / i ;
        num = ( num * m1 ) + ( r.num * m2 ) ;
        den = den * m1 ;
        reduit() ; return *this ;
    }
    #include "Part3.h"

#endif        // Fin de './Exemples/Rationnel/Part2.h'
