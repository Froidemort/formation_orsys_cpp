#include "Rationnel.h"
#include <iostream>
#include <string>

int main(void) {
	std::cout << "test_rationnel.cpp\n";
	Rationnel r(1,3);
	Rationnel s(1,4);
	r += Rationnel(2,3);
	std::cout << "r: " << r << "= 1 ?\n";

	r = -s;
	std::cout << "r: " << r << "= -1/4 ?\n";

	s -= Rationnel(1,3);
	std::cout << "s: " << s << "= -1/12 ?\n";

	std::cout << "1/s: " << ~s << "= -12/1 ?\n";
	Rationnel t = Rationnel(5,8);
	std::cout << double(t) << "\n";
	int i = t;
	std::cout << i << "\n";


	return 0;
}