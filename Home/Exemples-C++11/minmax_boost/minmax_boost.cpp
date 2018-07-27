// Fichier './Home/Exemples-C++11/minmax_boost/minmax_boost.cpp
#include <boost/algorithm/minmax_element.hpp>
#include <array>
#include <iostream>

int main( void)   // ------------------------------------------------- 73
{
    typedef std::array< int, 4> array; // std::array est nouveau en C++11
    array a{7, 0, 2, 1};              // initialisation uniforme du C++11

    std::pair< array::iterator, array::iterator> p =
            boost::minmax_element( a.begin(), a.end());

    std::cout << *p.first  << '\n' << *p.second << '\n';
} // fin de fichier
