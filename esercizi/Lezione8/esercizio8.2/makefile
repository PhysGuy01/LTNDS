.PHONY = all compila clean

ROOT_FLAGS := `root-config --cflags --libs`

all: compila

compila: main.cpp EqDifferenziali.h VectorOperations.h
	${CXX} -o esercizio8.2 $< ${ROOT_FLAGS}
	
clean:
	rm *.o