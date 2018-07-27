// Debut de ./Exemples-C++11/std__guard/std__guard.cpp
#include <thread>
#include <mutex>
#include <iostream>
                // inspire d'un exemple de http://www.cppreference.com
int i = 0;           // variable a proteger par ...
std::mutex Mutex;    // ... ce mutex 
  
void MonThread( void) {  // --------------------------------------- 70

    std::lock_guard< std::mutex> VerrouAutomatique( Mutex);
    i++;
    std::cout << std::this_thread::get_id() << ": " << i << '\n';
    // Le verrou est libere a la destruction du std::loack_guard<>
}

int main() {  // -------------------------------------------------- 70

    std::cout << __PRETTY_FUNCTION__ << ": " << i << '\n';

    std::thread t1( MonThread);
    std::thread t2( MonThread);
    std::thread t3( MonThread);
    t1.join(); t2.join(); t3.join();

    std::cout << __func__ << ": " << i << '\n';
}   // fin de fichier
