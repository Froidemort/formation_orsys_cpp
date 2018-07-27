# Fichier './De/Makefile'
# Lien physique './Corriges/De/Makefile'

CXX  = g++
CORE = Makefile De.h ../Rand/Rand.o
PRG  = Test-De

help:
	@echo "make [help]   : affiche cet ecran d'aide"
	@echo "make test     : compile et teste '$(PRG)'"
	@echo "make cleanrep : nettoie le repertoire"

$(PRG): $(PRG).o $(CORE)
	$(CXX) ../Rand/Rand.o -o $(PRG) $<

%.o: %.cpp $(CORE)
	$(CXX) -Wall -c -o $*.o $<

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
