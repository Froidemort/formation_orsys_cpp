# Fichier './Rand/Makefile'
# Fichier './Corriges/Rand/Makefile' (lien physique)

CC   = g++
CORE = Makefile Rand.h
PRG  = Test-Rand

help:
	@echo "make [help]   : affiche cet ecran d'aire"
	@echo "make test     : compile et teste '$(PRG)'"
	@echo "make cleanrep : nettoie le repertoire"

$(PRG): Rand.o $(PRG).o $(CORE)
	$(CC) $(PRG).o -o $(PRG) $<

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
