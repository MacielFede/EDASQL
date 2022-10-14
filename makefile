todo: main.o bd.o tabla.o columna.o dato.o tablas.o columnas.o datos.o
	g++ -Wall -o main bd.o main.o tabla.o columna.o dato.o tablas.o columnas.o datos.o
main.o: bd.o main.c
	g++ -Wall -c main.c
bd.o: bd.c bd.h
	g++ -Wall -c bd.c
tabla.o: tabla.c tabla.h
	g++ -Wall -c tabla.c
columna.o: columna.c columna.h
	g++ -Wall -c columna.c
dato.o: dato.c dato.h
	g++ -Wall -c dato.c
tablas.o: tablas.c tablas.h
	g++ -Wall -c tablas.c
columnas.o: columnas.c columnas.h
	g++ -Wall -c columnas.c
datos.o: datos.c datos.h
	g++ -Wall -c datos.c
clean:
	rm -f *.o
	rm -f main

