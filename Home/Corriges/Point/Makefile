# Makefile du repertoire './Point'
# Makefile du repertoire './Corriges/Point'

TAR_FILE = ./Point.tar

Point: Main.o Point.o
	g++ -o Point Main.o Point.o

test: Point
	strip Point
	@echo
	./Point
	@echo

Main.o: Point.h Makefile Main.cpp
	g++ -Wall -c Main.cpp

Point.o: Point.h Makefile Point.cpp
	g++ -Wall -c Point.cpp

cleanrep:
	@rm -f *.o *.tar Point

tarrep: tar-rep
tar-rep: cleanrep
	@echo
	tar --exclude="$(TAR_FILE)" -cf "$(TAR_FILE)" .
	@echo
	@ls -lh "$(TAR_FILE)"
	@echo

# Fin du Makefile './Point/Makefile'
