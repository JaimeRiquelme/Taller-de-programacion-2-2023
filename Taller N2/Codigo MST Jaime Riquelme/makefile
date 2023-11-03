CXX = g++

CXXFLAGS = -Wall

all: MST testNodo testArista testGrafo testComparador generador 

MST: main.o Nodo.o Grafo.o Arista.o Comparador.o  
	$(CXX) $(CXXFLAGS) -o MST main.o Nodo.o Grafo.o Arista.o Comparador.o  

testNodo: testNodo.o Nodo.o
	$(CXX) $(CXXFLAGS) -o testNodo testNodo.o Nodo.o

testArista: testArista.o Nodo.o Arista.o Comparador.o
	$(CXX) $(CXXFLAGS) -o testArista testArista.o Nodo.o Arista.o Comparador.o

testGrafo: testGrafo.o Nodo.o Arista.o Grafo.o Comparador.o
	$(CXX) $(CXXFLAGS) -o testGrafo testGrafo.o Nodo.o Arista.o Grafo.o Comparador.o

testComparador: testComparador.o Comparador.o Nodo.o Arista.o Grafo.o
	$(CXX) $(CXXFLAGS) -o testComparador testComparador.o Comparador.o Nodo.o Arista.o Grafo.o

generador: generador.o
	$(CXX) $(CXXFLAGS) -o generador generador.o

main.o: main.cpp Nodo.h
	$(CXX) $(CXXFLAGS) -c main.cpp

Nodo.o: Nodo.cpp Nodo.h
	$(CXX) $(CXXFLAGS) -c Nodo.cpp

testNodo.o: testNodo.cpp Nodo.h
	$(CXX) $(CXXFLAGS) -c testNodo.cpp

Arista.o: Arista.cpp Arista.h
	$(CXX) $(CXXFLAGS) -c Arista.cpp

Comparador.o: Comparador.cpp Comparador.h
	$(CXX) $(CXXFLAGS) -c Comparador.cpp

testArista.o: testArista.cpp Arista.h Nodo.h Comparador.h
	$(CXX) $(CXXFLAGS) -c testArista.cpp

Grafo.o: Grafo.cpp Grafo.h Comparador.h
	$(CXX) $(CXXFLAGS) -c Grafo.cpp

testGrafo.o: testGrafo.cpp Grafo.h Nodo.h Arista.h Comparador.h
	$(CXX) $(CXXFLAGS) -c testGrafo.cpp 

generador.o: generador.cpp
	$(CXX) $(CXXFLAGS) -c generador.cpp

testComparador.o: testComparador.cpp Comparador.h Nodo.h Arista.h Grafo.h
	$(CXX) $(CXXFLAGS) -c testComparador.cpp 

clean:
	rm -f *.o MST testNodo testArista testGrafo generador testComparador
