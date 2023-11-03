FLAGS = -g

all: main testRH testAuto testEstado testVector testOperacion testHeap testVectorString

main: Auto.o Vector.o Tablero.o Operacion.o main.cpp Estado.o Heap.o VectorString.o
	g++ ${FLAGS} Auto.o Vector.o Tablero.o Operacion.o Estado.o Heap.o VectorString.o main.cpp -o main 

testHeap: Auto.o Vector.o Estado.o Heap.o Operacion.o VectorString.o testHeap.cpp
	g++ ${FLAGS} Auto.o Vector.o Estado.o Heap.o Operacion.o VectorString.o testHeap.cpp -o testHeap


Auto.o: Auto.cpp Auto.h
	g++ ${FLAGS} -c Auto.cpp

Vector.o: Vector.cpp Vector.h
	g++ ${FLAGS} -c Vector.cpp

VectorString.o: VectorString.cpp VectorString.h
	g++ ${FLAGS} -c VectorString.cpp

Tablero.o: Tablero.cpp Tablero.h
	g++ ${FLAGS} -c Tablero.cpp

Operacion.o: Operacion.cpp Operacion.h
	g++ ${FLAGS} -c Operacion.cpp

Estado.o : Estado.cpp Estado.h
	g++ ${FLAGS} -c Estado.cpp

Heap.o : Heap.cpp Heap.h
	g++ ${FLAGS} -c Heap.cpp

clean:
	rm -rf *.o main testHeap testRH testAuto testEstado testVector testOperacion testVectorString

testRH: Estado.o Auto.o Tablero.o Vector.o Heap.o Operacion.o VectorString.o testRH.cpp
	g++ ${FLAGS} Estado.o Auto.o Tablero.o Vector.o Heap.o Operacion.o VectorString.o testRH.cpp -o testRH

testOperacion: Estado.o Auto.o Tablero.o Vector.o Heap.o Operacion.o VectorString.o testOperacion.cpp
	g++ ${FLAGS} Estado.o Auto.o Tablero.o Vector.o Heap.o Operacion.o VectorString.o testOperacion.cpp -o testOperacion

testVector: Estado.o Auto.o Tablero.o Vector.o Heap.o Operacion.o VectorString.o testVector.cpp
	g++ ${FLAGS} Estado.o Auto.o Tablero.o Vector.o Heap.o Operacion.o VectorString.o testVector.cpp -o testVector

testAuto: Estado.o Auto.o Tablero.o Vector.o Heap.o Operacion.o VectorString.o testAuto.cpp
	g++ ${FLAGS} Estado.o Auto.o Tablero.o Vector.o Heap.o Operacion.o VectorString.o testAuto.cpp -o testAuto

testEstado: Estado.o Auto.o Tablero.o Vector.o Heap.o Operacion.o VectorString.o testEstado.cpp
	g++ ${FLAGS} Estado.o Auto.o Tablero.o Vector.o Heap.o Operacion.o VectorString.o testEstado.cpp -o testEstado

testVectorString: Estado.o Auto.o Tablero.o Vector.o Heap.o Operacion.o VectorString.o testVectorString.cpp
	g++ ${FLAGS} Estado.o Auto.o Tablero.o Vector.o Heap.o Operacion.o VectorString.o testVectorString.cpp -o testVectorString