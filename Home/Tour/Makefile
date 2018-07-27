#!/usr/bin/make -rf
# Fichier './Corriges/Tour/Makefile'
# Fichier './Tour/Makefile' (lien physique)

# ------- options employees -----------------
# -Wall : niveau maximum de 'warnings'
# -p    : inclut les informations du profiler
CC   = g++ -Wall -p

CORE = Makefile Tour.h
PRG  = Test-Tour

test: $(PRG)
	@./$(PRG)
	@echo

$(PRG): Tour.o Rand.o $(PRG).o $(CORE)
	$(CC) -o $(PRG) Tour.o Rand.o $(PRG).o
	@echo

Rand.o: ../Rand/Rand.cpp ../Rand/Rand.h
	$(CC) -c ../Rand/Rand.cpp
	
%.o: %.cpp $(CORE)
	$(CC) -c $<

cleanrep:
	@rm -f *.o $(PRG) gmon.out
	@chmod 644 * ; chmod 755 Makefile

# Fin de Makefile
