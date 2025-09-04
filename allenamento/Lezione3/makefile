.PHONY = all compila clean

LIBS:=`root-config --libs`
INCS:=`root-config --cflags`

all : compila

compila : main.cpp funzioni.h
	${CXX} -o esercizio3.1 $< ${LIBS} ${INCS}

clean : 
	rm esercizio3.1