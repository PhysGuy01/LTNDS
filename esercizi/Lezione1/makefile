.PHONY: all esegui compila clean

MAKEFLAGS += --silent

all: compila

funzioni: funzioni.h funzioni.cpp
	${CXX} -c funzioni.cpp

main: main.cpp
	${CXX} -c $^

compila: main.o funzioni.o
	${CXX} -o prog $^

clean: 
	rm -f funzioni.o main.o prog