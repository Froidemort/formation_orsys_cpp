# Fichier './Rand/Makefile'
# Fichier './Corriges/Rand/Makefile' (lien physique)

CC   = g++
CORE = Rand.h
PRG  = Test-Rand
FLAGS = -std=c++11

help:
	@echo "make [help]   : affiche cet ecran d'aide"
	@echo "make test     : compile et teste '$(PRG)'"
	@echo "make cleanrep : nettoie le repertoire"

$(PRG): Rand.o $(PRG).o $(CORE)
	$(CC) $(FLAGS) $(PRG).o -o $(PRG) $<

%.o: %.cpp $(CORE)
	$(CC) -Wall -c $<

test: $(PRG)
	@echo
	@echo Lance 6 fois le test
	@echo
	@./$(PRG)
	@./$(PRG)
	@./$(PRG)
	@./$(PRG)
	@./$(PRG)
	@./$(PRG)
	@echo
	@echo Attend 2 secondes puis relance 2 fois le test
	@echo
	@sleep 2
	@./$(PRG)
	@./$(PRG)

cleanrep:
	@rm -f *.o $(PRG)

# Fin de './Rand/Makefile'
