all: resorte

resorte: main.o resorte.o vector.o junta.o
	g++ resorte.o vector.o junta.o -lm -o resorte

main.o:
	g++ -c main.cpp

resorte.o: resorte.cpp
	g++ -c resorte.cpp 

vector.o: vector.cpp
	g++ -c vector.cpp 

junta.o: junta.cpp
	g++ -c junta.cpp

clean:
	rm -rf *o resorte
