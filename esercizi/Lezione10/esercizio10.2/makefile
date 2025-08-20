ROOT_FLAGS := `root-config --cflags --libs`

all: integrali grafico

integrali: calcInt.cpp FunzioneBase.h IntegraleMC.h RandomGen.h
	${CXX} -o integrali $<

grafico: graph.cpp 
	${CXX} -o grafico $< ${ROOT_FLAGS}

clean :
	rm *.o