ROOT_FLAGS := `root-config --cflags --libs`

all: compila

compila: main.cpp RandomGen.h EsperimentoPrisma.h
	${CXX} -o esercizio12 $< ${ROOT_FLAGS}

clean:
	rm esercizio12