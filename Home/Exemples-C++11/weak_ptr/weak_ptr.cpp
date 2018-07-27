// Debut de Home/Exemples-C++11/weak_ptr
// Exemple tire de http://fr.cppreference.com/w/cpp/memory/weak_ptr
#include <iostream>
#include <memory>
std::weak_ptr< int> gw;
  
void f() { // ----------------------------------------------------- 70
    if ( auto sp = gw.lock() ) {
        // lock() cree un share_ptr, un weak_ptr ne peut pas etre
        // utilise directement
        std::cout << *sp << "\n";
    } else {
        std::cout << "gw is expired\n";
    }
}   // fin de f()
                             
int main() { // --------------------------------------------------- 70
    {    
        auto sp = std::make_shared< int>( 42);
        gw = sp;
        f();
    }
    f();
}   // fin de main()
