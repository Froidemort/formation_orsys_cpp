// Debut de ./Exemples-C++11/std__ref/std__ref.cpp
#include <iostream>         // std::cout std::endl
#include <thread>           // std::thread
#include <functional>       // std::ref

void func( int& arg) { arg++; }


int main() {
    int i = 5;
    func( i) ; // Compile car le compilateur connait/verifie func()

    // Ne compile pas car le compilateur ne verifie pas func() mais t
    std::thread t( func, i);

    // Correction: le developpeur doit fabriquer explicitement la
    // reference en utilisant le 'wrapper' std::ref() de <functional>
    //     std::thread t( func, std::ref( i));

    t.join(); std::cout << i << std::endl;
    return 0;
}   // fin de fichier
