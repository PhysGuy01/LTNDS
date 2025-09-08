ROOT_FLAGS := `root-config --cflags --libs`

all: compila

compila: main.cpp RandomGen.h
	${CXX} -o esercizio10.0 $< ${ROOT_FLAGS}

clean:
	rm esercizio10.0