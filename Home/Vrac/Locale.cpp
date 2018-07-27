// Fichier './Exemples/Locale.cpp'

#include <ctime>
#include <iostream>
#include <locale>

using namespace std;

int main( void)
{
    locale::global(locale(""));

    time_t date;
    time(&date);
    struct tm *TL = localtime(&date);
    use_facet< time_put< char> >(locale()).put( cout, cout, ' ', TL, 'c');
    cout << endl;

    char s[64];
    strftime(s, 64, "%c", TL);
    cout << s << endl;

    return 0;
}               // Fin de './Exemples/Locale.cpp'
