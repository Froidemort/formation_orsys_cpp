# Debut de './Face/Makefile'
# Lien physique vers './Corriges/Face/Makefile'

CXX  = g++ -Wall -W
CORE = Makefile Face.h ../Rand/Rand.h
PRG  = Test-Face

all: $(PRG)

%.o: %.cpp %.h $(CORE)
	$(CXX) -c -o $*.o $<

$(PRG): ../Rand/Rand.o $(PRG).o $(CORE)
	$(CXX) $(PRG).o -o $(PRG) $<

test: $(PRG)
	@echo
	@echo Lance 1 fois le test
	@echo
	@./$(PRG)

cleanrep:
	@rm -f *.o $(PRG) ../Rand/Rand.o

# Fin de './Face/Makefile'
