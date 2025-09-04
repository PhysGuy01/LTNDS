.PHONY = all compila clean

LIBS := `root-config --libs`
INCS := `root-config --cflags`


all: compila


compila: main.cpp 
	${CXX} -o esercizio5 $^ ${LIBS} ${INCS}

clean:
	rm esercizio5 main.o funzioni.o