#include <iostream>
#include <locale>
#include <string>
#include <codecvt>
#include <fstream>

int main ()
{
	std::u32string str ( U"\U00004f60\U0000597d" );  // ni hao (??)
  
    std::locale loc (std::locale(), new std::codecvt_utf8< char32_t>);
    std::basic_ofstream<char32_t> ofs ("test.txt");
    ofs.imbue(loc);
		
    std::cout << "Writing to file (UTF-8)... ";
    ofs << str;
    std::cout << "done!\n";
    std::cout << str << "\n";
			  
	return 0;
}
