.PHONY = all clean compila 

all : compila

compila : main.o funzioni.o Vettore.o
	g++ -o esercizio2.2 $^

main : main.cpp
	g++ -c $^

funzioni : funzioni.cpp funzioni.h 
	g++ -c $<

Vettore : Vettore.cpp Vettore.h
	g++ -c $< 

clean :
	rm funzioni.o main.o esercizio2.2 Vettore.o