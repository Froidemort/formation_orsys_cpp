// Fichier './Home/Exemples-C++11/mimax_boost/mimax_boost.cpp
#include <algorithm>
#include <array>
#include <iostream>

int main( void)   // ------------------------------------------------- 73
{
    typedef std::array< int, 4> array; // std::array est nouveau en C++11
    array a{6, 0, 2, 1};              // initialisation uniforme du C++11

    std::pair< array::iterator, array::iterator> p =
            std::minmax_element( a.begin(), a.end());

    std::cout << *p.first  << '\n' << *p.second << '\n';
} // fin de fichier
