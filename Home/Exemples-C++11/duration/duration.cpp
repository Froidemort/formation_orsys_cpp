// Debut de './Exemples-C++11/duration/duration.cpp'
#include <chrono>       // std::chrono::duration
#include <iostream>     // std::cout
 
int main()  // ---------------------------------------------------- 70
{   using std::cout ;
    const std::chrono::duration< char> UneSeconde( 1) ;
    cout << "UneSeconde (" <<sizeof UneSeconde << " octet(s)) : ";
    cout << (unsigned int)UneSeconde.count() << " s\n";

}   // fin de fichier
