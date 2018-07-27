// Debut de ./Exemples-C++11/ratio/ratio.cpp
#include <iostream>      // std::cout 
#include <ratio>
int main () // ---------------------------------------------------- 70
{
    typedef std::ratio< 1,5>  Un   ;
    typedef std::ratio< 4,10> Deux ;
    typedef std::ratio_add< Un, Deux> Trois ;
    typedef std::ratio< 1, -5> Moins ;

    std::cout << " 1/5 = " << Un::num << "/" << Un::den << '\n' ;
    std::cout << " 2/5 = " << Deux::num << "/" << Deux::den << '\n' ;
    std::cout << " 3/5 = " << Trois::num << "/" << Trois::den << '\n';
    std::cout << "-1/5 = " << Moins::num << "/" << Moins::den << '\n';

    typedef std::ratio< 1, 0> Err ;  // compile et echoue ci dessous
//  std::cout << "err. = " << Err::num << "/" << Err::den << '\n';
    // static_assert( _Den != 0, "denominator cannot be zero");

    std::ratio< 0, 5> Zero ;
//  std::cout << " 0/5 = " << Zero::num << "/" << Zero::den << '\n';
    // error: 'Zero' is not a class, namespace, or enumeration
    return 0 ;
}   // fin de fichier
