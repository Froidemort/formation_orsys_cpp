// Debut de ./Home/Exemples-C++11/InitMembres/InitMembres.cpp
#include <cmath>                 // std::sqrt()
#include <iostream>              // std::cout

class UneClasse {  // --------------------------------------------- 70
  public:
    UneClasse() {}
    explicit UneClasse( int valeur) : _UneValeur( valeur) {}

  private:
    int _UneValeur = 5;                     // C++11
    const int _UneConst = 12;               // C++03/C++11
  public:
    double _UnEssai = std::sqrt( -12.12);   // C++11
} ;

int main() {  // -------------------------------------------------- 70

    UneClasse a, b(3) ;
//  a = 12 ; // Ne compilerait pas : le ctor est specifie 'explicite'

    std::cout << a._UnEssai << '\n' ;       // Nan : Not-a-Number
}
//  fin de fichier
