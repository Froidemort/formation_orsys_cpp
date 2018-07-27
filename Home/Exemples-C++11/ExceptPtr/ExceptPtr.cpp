// Debut de ./Exemples-C++11/ExceptPtr/ExceptPtr.cpp
#include <iostream>  // std::cout
#include <exception> // exception_ptr current_exception rethrow_exception
#include <stdexcept> // std::logic_error
                     // Exemple inspire de 'http://www.cplusplus.com'
int main () { // ----------------------------------------------------- 73
     std::exception_ptr p;
     try { throw std::logic_error("some logic_error exception");
     } catch(const std::exception& e) {
        p = std::current_exception();
        std::cout << "exception caught, but continuing...\n";
    }

    std::cout << "(after exception)\n";

    try { std::rethrow_exception( p);
    } catch (const std::exception& e) {
        std::cout << "exception caught: " << e.what() << '\n';
    }
}   // fin de fichier
