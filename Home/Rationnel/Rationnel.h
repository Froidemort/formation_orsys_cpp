// Fichier './Rationnel/Rationnel.h'

#include <iostream>
#include <stdexcept>


class zero_divide : public std::runtime_error {
  public:
    zero_divide() : std::runtime_error( "Le denominateur d'un rationnel ne peut etre egal a 0") {}
} ;



inline int pgcd( const int a, const int b) {
	return (!b) ? a : pgcd( b, a%b) ;
}


class Rationnel {

    int num; unsigned int den ;   // Le denominateur doit toujours rester >0

	void reduit( void) {
		int i = pgcd( (num>0) ? num : -num, den) ;
		num /= i ;
		den /= i ;
	}

    friend std::ostream &operator <<( std::ostream &c, const Rationnel &r) ;

  public :
    Rationnel( void) {
		std::cerr << "(debug) Constructeur vide\n" ;
		num=0; den=1;
	}

    Rationnel( const int n) {
		std::cerr << "(debug) Constructeur a un entier \n" ;
		num=n ; den=1 ;
    }

    Rationnel( const int n, const int d) {
		std::cerr << "(debug) Constructeur a 2 entiers\n" ;
		if ( d==0 ) throw zero_divide() ;
        if ( d<0 ) { num = -n ; den = -d ;}
        else { num = n ; den = d ; }
    }

    Rationnel( const Rationnel &r) {
		std::cerr << "(debug) Constructeur de copie\n" ;
        num=r.num ; den=r.den ;
	}

    ~Rationnel( ) {}

	Rationnel &operator =( const Rationnel &r) {
        std::cerr << "(debug) Operateur affectation(=) \n" ;
        num=r.num ; den=r.den ;
        return *this ;
	}

    Rationnel &operator +=( const Rationnel &r) {
        std::cerr << "(debug) Operateur affectation(+=) \n" ;
		int i = pgcd( den, r.den) ;
		int m1 = r.den / i ;
		int m2 = den / i ;
		num = ( num * m1 ) + ( r.num * m2 ) ;
		den = den * m1 ;
		reduit() ;
        return *this ;
    }

    bool operator ==(const Rationnel &r) const {
    	return (this->num * r.den) == (this->den * r.num) ;
    }

    bool operator !=(const Rationnel &r) const {
    	return ! ((*this) == r) ;
    }

    Rationnel operator -() const {
    	return Rationnel((-1)*(this->num), this->den);
    }

    Rationnel &operator -=( const Rationnel &r) {
    	(*this) += -r;
    	reduit();
    	return *this;
    }

    Rationnel operator ~() const {
    	return Rationnel(this->den, this->num);
    }

    operator double() const { return this->num/double(this->den) ;}

    operator int() const {return int(this->num/double(this->den)+0.5);}



} ;

inline std::ostream &operator << ( std::ostream &c, const Rationnel &r) {
	return c << r.num << '/' << r.den ;
}

// Fin de './Rationnel/Rationnel.h'
