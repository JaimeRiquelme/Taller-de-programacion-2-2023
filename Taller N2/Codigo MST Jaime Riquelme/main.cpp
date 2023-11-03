#include <iostream>
#include <ctime>
#include "Grafo.h"

using namespace std;

int main()
{
    char opcion;
    do {
        // Mostrar la consola de bienvenida
        cout << "\n###########################" << endl;
        cout << "#####   BIENVENIDO   ######" << endl;
        cout << "###########################\n" << endl;

        // Crear el grafo
        Grafo *grafo = new Grafo();

        cout << "Ingrese el nombre del archivo: ";
        char nombreArchivo[100];
        cin >> nombreArchivo;

        // Obtener la matriz de adyacencia
        int validador = grafo->getMatrizAdyacencia(nombreArchivo);
        if(validador == 1){
            return 1;
        }

        cout << "\n--- Información del Grafo ---" << endl;
        cout << "Numero de nodos: " << grafo->getNumeroNodos() << "\n" << endl;

        // Imprimir el arbol de expansion minima 
        cout << "--- Arbol de Expansión Mínima ---" << endl;
        // Ejecutar el algoritmo de Kruskal
        int tiempo = clock();
        grafo->kruskal();
        int tiempo2 = clock();


        cout << "\n--- Resultados ---" << endl;
        cout << "Tiempo de ejecucion: " << (tiempo2 - tiempo) / (double)CLOCKS_PER_SEC << " segundos" << endl;
        cout << "Numero de vertices TOTALES: " << grafo->getNumeroAristas() << endl;
        cout << "Numero de vertices REVISADAS: " << grafo->getNumeroAristasRevisadas() << "\n" << endl;


        // Preguntar al usuario si desea continuar
        cout << "¿Desea probar con otro archivo? (s/n): ";
        cin >> opcion;

    } while (opcion == 's' || opcion == 'S');

    cout << "\n¡Gracias por usar el programa! Hasta luego.\n" << endl;

    return 0;
}
