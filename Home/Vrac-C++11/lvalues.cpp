#include <iostream>
 
// struct A { double x; };
// const A* a = new A{ 0};
// decltype( a->x) y = ;       // type of y is double (declared type)
// decltype( (a->x)) z = y; // type of z is const double& (lvalue expression)

auto x = 8.8 ;
auto y = x ;
auto z = (x) ;

int main() {

	x = 1.1 ;
	y = 8.8 ;
	z = 9.9 ;
	std::cout << x << ", " << y << ", " << z << std::endl ;
}
