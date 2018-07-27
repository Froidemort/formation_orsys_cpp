// debut de './Exemples-C11/delete/delete.cpp'
#include <iostream>

class T {
  public:
    T() = default ;
    int GetVal( void) const noexcept { return _i; }
    T( T const&) = delete ;
    T( bool) noexcept {}
  private:
    int _i ;
} ;


int main() noexcept {

    T x, y( 12) ; 

//  T z( x) ;
// error: use of deleted function 'T::T(const T&)'

    std::cout << "x >" << x.GetVal() << "< et y >" ;
    std::cout << y.GetVal() << "<\n" ;
}   // fin de fichier
