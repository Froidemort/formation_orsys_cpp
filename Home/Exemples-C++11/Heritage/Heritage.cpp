// Deut de ./Exemples-C++11/Heritage/Heritage.cpp
#include<iostream>       // std::cout
#include<typeinfo>       // typeid
#include<typeindex>      // std::type_index
#include<unordered_map>  // std::unordered_map
#include<string>         // std::string

struct C { virtual char const* id( void) { return " (C)\n" ;} };
struct D : public C
         { virtual char const* id( void) { return " (D)\n" ;} };

int main() { // --------------------------------------------------- 70
    C c, *p; D d;
    std::unordered_map< std::type_index, std::string> Types;

    Types[ typeid( int)]    = "int";     // typeid est un operateur
    Types[ typeid( double)] = "double";
    Types[ typeid( C)]      = "class C";
    Types[ typeid( d)]      = "class D";

    std::cout << "int: "    << Types[ typeid( int)]    << '\n';
    std::cout << "double: " << Types[ typeid( double)] << '\n';
    std::cout << "C: "      << Types[ typeid( C)]      << '\n';
    std::cout << "d: "      << Types[ typeid( D)]      << '\n';

    p=&c; std::cout << "*p: " << Types[ typeid( *p)] << p->id();
    p=&d; std::cout << "*p: " << Types[ typeid( *p)] << p->id();
    return 0;
}   // fin de fichier
