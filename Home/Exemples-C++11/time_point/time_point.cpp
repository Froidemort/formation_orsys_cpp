// Debut de ./Exemples-C++11/time_point/time_point.cpp
#include <chrono>
#include <iostream>
 
using Clock     = std::chrono::system_clock ;
using TimePoint = std::chrono::time_point< Clock> ;
using Secondes  = std::chrono::seconds ;
  
void Affiche( TimePoint const& pt) {
    std::cout <<
        std::chrono::duration_cast< Secondes>(
            pt.time_since_epoch()).count()
              << " s\n";
}
   
int main() { // --------------------------------------------------- 70
    Affiche( TimePoint());       // 0 s
    Affiche( Clock().now());     // 1469822754 s
}   // fin de fichier
