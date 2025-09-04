LIBS := `root-config --libs`
CFLAG := `root-config --cflags` 

all : compila

compila: main.cpp funzioni.h FunzioneBase.h Integral.h
	g++ -o esercizio7.1 $< ${LIBS} ${CFLAG}

clean:
	rm esercizio7.1