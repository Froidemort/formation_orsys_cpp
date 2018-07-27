#include <iostream>
#include <thread>

int main()
{
    std::thread t1 ;		// t1 n'est pas un thread, fnfin pas encore

	if ( t1.joinable() ) {
		std::thread::id t1_id = t1.get_id();
		std::cout << "t1's id: " << t1_id << '\n';
		return 0 ;
	} else {
		std::cout << "t1 is not a thread\n";
		return 2 ;
	}
}
