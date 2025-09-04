.PHONY: all esegui compila clean

MAKEFLAGS += --silent

all: compila

funzioni: funzioni.cpp funzioni.h
	${CXX} -c $<

Vettore: Vettore.cpp Vettore.h
	${CXX} -c $<

main: main.cpp
	${CXX} -c $^

compila: main.o funzioni.o Vettore.o
	${CXX} -o esercizio2.2 $^

clean: 
	rm -f *.o esercizio2.2