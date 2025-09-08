
ROOT_FLAGS := `root-config --cflags --libs`

all: compila

compila: main.cpp EqDifferenziali.h VectorOperations.h
	${CXX} -o prog $< ${ROOT_FLAGS}
	
clean:
	rm prog