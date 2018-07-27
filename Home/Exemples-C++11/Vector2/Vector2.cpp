// Debut Home/Exemples-C++11/Vector2/Vector2.cpp
#include <vector>    // std::vector
#include <algorithm> // std::for_each
#include <iostream>  // std::cout

auto main( void) -> int { // -------------------------------------- 70

    std::vector< int> v{ 1, 2, 3, 4, 5, 6 } ;

    std::for_each( v.cbegin(), v.cend(),
                    []( int i) { std::cout << i << ' '; }
                ) ;
    std::cout << std::endl ;

    std::for_each( v.begin(), v.end(),
                    []( int& i) { i=i*2; return; }
                ) ;

    std::for_each( v.cbegin(), v.cend(),
                    []( int i) { std::cout << i << ' '; }
                ) ;
    std::cout << std::endl ;
    return 0 ;
}   // end of file
