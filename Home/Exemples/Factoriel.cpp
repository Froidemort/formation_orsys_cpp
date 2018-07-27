// Fichier './Exemples/Factoriel.cpp'
#include <iostream>
using namespace std ;

template<int N>
class Factoriel {
  public:
    enum { value = N * Factoriel<N-1>::value } ;
};
    
template<>             // template<0> ne marche pas
class Factoriel<0> {
  public:
    enum { value = 1 } ;
};
    
int main()
{
    // const int pp = Factoriel::value ; // Ne marche pas
    const int p0 = Factoriel<0>::value ;
    const int p1 = Factoriel<1>::value ;
    const int p2 = Factoriel<2>::value ;
    const int p3 = Factoriel<3>::value ;
    const int p4 = Factoriel<4>::value ;
    const int p5 = Factoriel<5>::value ;
    const int p10 = Factoriel<10>::value ;

    cout << " 0! = " << p0 << endl ;
    cout << " 1! = " << p1 << endl ;
    cout << " 2! = " << p2 << endl ;
    cout << " 3! = " << p3 << endl ;
    cout << " 4! = " << p4 << endl ;
    cout << " 5! = " << p5 << endl ;
    cout << "   ..." << endl ;
    cout << "10! = " << p10 << endl ;

    return 0 ;
}
// Fin de './Exemples/Factoriel.cpp'
