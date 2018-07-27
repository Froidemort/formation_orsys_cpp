# Fichier './De/Makefile'
# Lien physique './Corriges/De/Makefile'

CXX  = g++
CORE = Makefile include/De.h ../Rand/Rand.o
PRG  = Test-De

help:
	@echo "make [help]   : affiche cet ecran d'aide"
	@echo "make test     : compile et teste '$(PRG)'"
	@echo "make cleanrep : nettoie le repertoire"

$(PRG): $(PRG).o $(CORE)
	$(CXX) ../Rand/Rand.o -o $(PRG) $<

%.o: src/%.cpp $(CORE)
	$(CXX) -Wall -std=c++11 -c -o $*.o $<

all: test
test: $(PRG)
	@echo
	@echo Lance 3 fois le test
	@echo
	@./$(PRG)
	@echo
	@./$(PRG)
	@echo
	@./$(PRG)

cleanrep:
	@rm -f *.o $(PRG) ../Rand/Rand.o

# Fin de './De/Makefile'
