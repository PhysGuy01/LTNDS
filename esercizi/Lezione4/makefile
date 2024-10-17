.PHONY: compila clean

ROOT_FLAGS := `root-config --cflags --libs`

all: compila

compila: main.cpp funzioni.h
	${CXX} -o esercizio4.1 $< ${ROOT_FLAGS}

clean:
	rm esercizio4.1