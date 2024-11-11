INCS=`root-config --cflags`
LIBS=`root-config --libs`

esercizio_5.3: esercizio_5.3.o Posizione.o PuntoMateriale.o CampoVettoriale.o Particella.o
	${CXX} -o $@ $^ ${LIBS}

esercizio_5.3.o: esercizio_5.3.cpp Particella.h PuntoMateriale.h Posizione.h CampoVettoriale.h
	${CXX} -c $< -o $@ ${INCS}       

Particella.o: Particella.cpp Particella.h
	${CXX} -c $< -o $@ 

Posizione.o: Posizione.cpp Posizione.h
	${CXX} -c $< -o $@ 

PuntoMateriale.o: PuntoMateriale.cpp PuntoMateriale.h Posizione.h Particella.h
	${CXX} -c $< -o $@ 

CampoVettoriale.o: CampoVettoriale.cpp CampoVettoriale.h Posizione.h
	${CXX} -c $< -o $@ 

clean:
	rm *.o