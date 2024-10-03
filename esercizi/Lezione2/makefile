.PHONY: all esegui compila clean

MAKEFLAGS += --silent

all: compila

funzioni: funzioni.h funzioni.cpp
	${CXX} -c funzioni.cpp

Vettore: Vettore.cpp Vettore.h
	${CXX} -c $<

main: main.cpp
	${CXX} -c $^

compila: main.o funzioni.o Vettore.o
	${CXX} -o prog $^

clean: 
	rm -f funzioni.o main.o Vettore.o prog