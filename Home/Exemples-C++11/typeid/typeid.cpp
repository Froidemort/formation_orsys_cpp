// Fichier ./Home/Exemples-C++11/typeid/typeid.cpp
// selon http://en.cppreference.com/w/cpp/types/type_info/hash_code

#include <iostream>            // std::cout
#include <unordered_map>       // std::unordered_map<>
#include <typeinfo>            // typeid()
#include <functional>

using TypeInfoRef = std::reference_wrapper< const std::type_info>;

struct Hasher {
    std::size_t operator()( TypeInfoRef code) const {
                return code.get().hash_code();
    }
} ; // fin de struct Hasher
                     
struct EqualTo {
     bool operator()( TypeInfoRef lhs, TypeInfoRef rhs) const {
                 return lhs.get() == rhs.get();
     }
} ; // fin de struct EqualTo

int main() {  // ----------------------------------------------------- 73

    std::unordered_map< TypeInfoRef, std::string, Hasher, EqualTo> Types;
    int i{5} ;
    extern int f( void) ;
    extern int g( void) noexcept ;
    extern int h( int) ;

    Types[ typeid( int)] = "int";
    Types[ typeid( f)] = "int (*)( void)";
    // En C++11 ni 'noexcept' ni 'throw' ne sont dans la signature
    // l'affectation ci dessous remplace celle ci dessus
    Types[ typeid( g)] = "int (*)( void) noexcept";

    std::cout << "  i is " << Types[ typeid( i)]   << '\n';
    std::cout << "f() is " << Types[ typeid( f())] << '\n';
    std::cout << "  f is " << Types[ typeid( f)]   << '\n';
    std::cout << "  g is " << Types[ typeid( g)]   << '\n';
    std::cout << "  h is " << Types[ typeid( h)]   << '\n';
}   // fin de fichier
