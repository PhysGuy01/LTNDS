.PHONY: all esegui compila clean

MAKEFLAGS += --silent

all: compila

funzioni: funzioni.h funzioni.cpp
	${CXX} -c funzioni.cpp

main: main.cpp
	${CXX} -c $^

compila: main.o funzioni.o
	${CXX} -o esercizio1.3 $^

clean: 
	rm -f *.o esercizio1.3