.PHONY: compila clean

MAKEFLAGS += --silent

all: compila

compila: main.cpp Vettore.h funzioni.h
	${CXX} -o esercizio3.0 $^

clean:
	rm -f esercizio3.0