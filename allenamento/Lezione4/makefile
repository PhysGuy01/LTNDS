.PHONY = all compila clean

LIBS := `root-config --libs`
INCS := `root-config --cflags`

all : compila

compila : main.cpp funzioni.h
	${CXX} -o esercizio4.0 $< ${LIBS} ${INCS}

clean : 
	rm esercizio4.0