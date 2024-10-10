.PHONY: compila clean

ROOT_FLAGS := `root-config --cflags --libs`

all: compila

compila: main.cpp funzioni.h
	${CXX} -o esercizio3.2 $^ ${ROOT_FLAGS}

clean:
	rm -f esercizio3.2