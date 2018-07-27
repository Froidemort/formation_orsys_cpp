#!/usr/bin/make -rf
# Fichier './Exemples/Point/Makefile'

test: Test
		@echo
	    @./Test | tee Point.txt

Test: Test.o Point.o
	    g++ -o Test Test.o Point.o

Test.o: Point.h Makefile Test.cpp
	    g++ -c -Wall Test.cpp

Point.o: Point.h Makefile Point.cpp
	    g++ -c -Wall Point.cpp

clean: 
	    @rm -f *.o *.tar Point Test
	    @chmod 644 * ; chmod 755 Makefile

# Fin du Makefile './Exemples/Point/Makefile'
