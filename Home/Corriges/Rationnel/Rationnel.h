// Fichier './Corriges/Rationnel/Rationnel.h'

#include <iostream>
#include <stdexcept>


class zero_divide : public std::runtime_error {
  public:
    zero_divide() : std::runtime_error(
        "Le denominateur d'un rationnel ne peut pas valoir 0") {}
} ;


inline int pgcd( const int a, const int b) {
    return (!b) ? a : pgcd( b, a%b) ;
}


class Rationnel {

    int num; unsigned den ;

    void reduit( void) {
        int i = pgcd( (num>0) ? num : -num, den) ;
        num /= i ;
        den /= i ;
    }

    friend std::ostream &operator << ( std::ostream &, const Rationnel &) throw() ;
    friend bool operator == ( const Rationnel &, const Rationnel &) throw() ;
    friend bool operator != ( const Rationnel &, const Rationnel &) throw() ;
    friend Rationnel operator -( const Rationnel &) throw() ;
    friend Rationnel operator ~( const Rationnel &) throw( zero_divide) ;

  public:
    Rationnel( void) {
        std::cerr << "Constructeur vide\n" ;
        num=0; den=1;
    }

    Rationnel( const int n) {
        std::cerr << "Constructeur a un entier \n" ;
        num=n ; den=1 ;
    }

    Rationnel( const int n, const int d) throw( zero_divide) {
        std::cerr << "Constructeur a 2 entiers (" << n << "):(" << d << ")\n" ;
        if ( d==0 ) throw zero_divide() ;
        if ( d<0 ) { num = -n ; den = -d ;}
        else { num = n ; den = d ; }
    }

    Rationnel( const Rationnel &r) {
        std::cerr << "Constructeur de copie (" << r.num << "):(" << r.den << ")\n" ;
        num=r.num ; den=r.den ;
    }

    ~Rationnel() {}

    Rationnel &operator =( const Rationnel &r) {
        std::cerr << "Operateur Affectation(=) \n" ;
        num=r.num ; den=r.den ;
        return *this ;
    }

    Rationnel &operator +=( const Rationnel &r) {
        std::cerr << "Operateur Affectation(+=) \n" ;
        int i = pgcd( den, r.den) ;
        int m1 = r.den / i ;
        int m2 = den / i ;
        num = ( num * m1 ) + ( r.num * m2 ) ;
        den = den * m1 ;
        reduit() ;
        return *this ;
    }

    const Rationnel &operator +( void) const {
        std::cerr << "Operateur unaire +\n" ;
        return *this ;
    }

    Rationnel &operator -=( const Rationnel &r) {
        std::cerr << "Operateur Affectation(-=) \n" ;
        return *this +=  -r  ;
    }

    operator double() const {
        return (double)num/den ; 
    }

    operator int() const {
        Rationnel r = *this ; r += Rationnel(1,2) ; return (int)(double)r ;
    }
} ;

inline std::ostream &operator << ( std::ostream &c, const Rationnel &r) throw() {
    return c << r.num << '/' << r.den ;
}

inline bool operator == ( const Rationnel &r, const Rationnel &s) throw() {
     Rationnel x=r; Rationnel y=s; x.reduit() ; y.reduit() ;
     return x.num==y.num && x.num==y.num ;
}

inline bool operator != ( const Rationnel &r, const Rationnel &s) throw() {
     return !(r==s) ;
}

inline Rationnel operator -( const Rationnel &r) throw() {
     return Rationnel( (-1)*r.num, r.den) ;
}

inline Rationnel operator ~( const Rationnel &r) throw( zero_divide ) {
     if ( r.den == 0 ) throw zero_divide() ;
     return Rationnel( r.den, r.num) ;
}

// Fin de './Corriges/Rationnel/Rationnel.h'
