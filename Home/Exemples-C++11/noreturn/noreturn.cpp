// Fichier './Home/Exemples-C++11/noreturn/noreturn.cpp'
// Selon 'http://en.cppreference.com/w/c/language/_Noreturn'

#include <stdlib.h>
#include <stdio.h>
#include <stdnoreturn.h>

// causes undefined behavior if i <= 0
// exits if i > 0
noreturn void stop_now( int i) {
    if (i > 0) exit(i);        // compile avec warning a cause du 'if'
}

int main( void) {  // ------------------------------------------------ 73
    puts("Preparing to stop...");
    stop_now( 2);
    puts("This code is never executed.");
}   // fin de fichier
