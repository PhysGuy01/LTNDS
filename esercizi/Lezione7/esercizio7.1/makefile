.PHONY: all compila clean

ROOT_FLAGS := `root-config --cflags --libs`

all: compila

compila: main.cpp FunzioneBase.h Integral.h
	${CXX} -o esercizio7.1 $< ${ROOT_FLAGS}

clean:
	rm *.o