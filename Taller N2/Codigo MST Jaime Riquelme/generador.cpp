#include <iostream>
#include <fstream>
using namespace std;

/*
Este programa crea un grafo aleatorio
*/

// entrada: -
// salida: -
// descripcion: Archivo para crear un grafo aleatorio
int main()
{
  cout << "Ingrese el numero de nodos: ";
  int n;
  cin >> n;
  int **c = new int *[n];
  ofstream archivo("input.txt");

  for (int i = 0; i < n; i++)
  {
    c[i] = new int[n];
  }

  for (int i = 0; i < n; i++)
  {
    c[i][i] = 0;
    for (int j = i + 1; j < n; j++)
    {
      c[i][j] = rand() % 100 + 1;
      c[j][i] = c[i][j];
    }
  }
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      archivo << c[i][j] << " ";
    }
    archivo << endl;
  }
}