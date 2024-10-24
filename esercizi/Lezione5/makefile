INCS=`root-config --cflags`
LIBS=`root-config --libs`

esercizio_5.3: esercizio_5.3.o Posizione.o PuntoMateriale.o CampoVettoriale.o Particella.o
	g++ -o esercizio_5.3 esercizio_5.3.o Posizione.o PuntoMateriale.o CampoVettoriale.o Particella.o ${LIBS}

esercizio_5.3.o: esercizio_5.3.cpp Particella.h PuntoMateriale.h Posizione.h CampoVettoriale.h
	g++ -c esercizio_5.3.cpp -o esercizio_5.3.o ${INCS}       

Particella.o: Particella.cpp Particella.h
	g++ -c Particella.cpp -o Particella.o

Posizione.o: Posizione.cpp Posizione.h
	g++ -c Posizione.cpp -o Posizione.o

PuntoMateriale.o: PuntoMateriale.cpp PuntoMateriale.h Posizione.h Particella.h
	g++ -c PuntoMateriale.cpp -o PuntoMateriale.o

CampoVettoriale.o: CampoVettoriale.cpp CampoVettoriale.h Posizione.h
	g++ -c CampoVettoriale.cpp -o CampoVettoriale.o

clean:
	rm *.o