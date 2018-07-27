// Debut de './Exemples/Rationnel/Rationnel.h'
#include <stdexcept>
#include "Pgcd.h"

class zero_divide : public std::runtime_error {
  public:
    zero_divide() : std::runtime_error( "Un denominateur est null") {}
} ;

class Rationnel {      // Part1
    int num;
    unsigned int den ; // le denominateur est toujours >0
  public :
    Rationnel( void) { num=0; den=1; }
    Rationnel( const int n) { num=n; den=1; }
    Rationnel( const int n, const int d) throw( zero_divide)
    {   if ( d==0 ) throw zero_divide() ;
        if ( d<0 ) { num = -n ; den = -d ;}
        else { num = n ; den = d ;}
    }
    Rationnel( const Rationnel &r) { num=r.num; den=r.den; }
    ~Rationnel() {}

    #include "Part2.h"
} ;                    // Fin de './Exemples/Rationnel/Rationnel.h'
