all: resorte

resorte: resorte.o vector.o
	g++ resorte.o vector.o -lm -o resorte

resorte.o: resorte.cpp
	g++ -c resorte.cpp 

vector.o: vector.cpp
	g++ -c vector.cpp 

clean:
	rm -rf *o resorte
