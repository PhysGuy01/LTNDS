all: compila

ROOT_FLAGS := `root-config --cflags --libs`

compila: main.cpp Solutore.h FunzioneBase.h
	${CXX} -o esercizio_6.3 $< ${ROOT_FLAGS}

clean:
	rm *.o