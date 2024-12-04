ROOT_FLAGS := `root-config --cflags --libs`

all: compila

compila: main.cpp RandomGen.h
	${CXX} -o prog $< ${ROOT_FLAGS}

clean:
	rm *.o