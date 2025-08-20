.PHONY = all clean compila clean

all : compila

compila : main.o funzioni.o
	${CXX} -o esercizio1.3 $^

main : main.cpp
	${CXX} -c $^

funzioni : funzioni.cpp funzioni.h
	${CXX} -c $<

clean : 
	rm funzioni.o main.o esercizio1.3
