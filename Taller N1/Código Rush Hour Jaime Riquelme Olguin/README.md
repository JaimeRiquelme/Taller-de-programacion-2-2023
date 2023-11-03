
# Rush Hour Solver

## Autor: [Jaime Riquelme Olguin]

## Fecha: [Miercoles 11 de octubre, 2023]

Este proyecto, desarrollado como parte de la evaluación en el Taller de Programación, implementa el algoritmo A* para resolver instancias del juego "Rush Hour". Se ha implementado en C++, haciendo uso de makefile y siguiendo buenas prácticas de programación orientada a objetos. También se ha construido una estructura de datos para mejorar la eficiencia en la resolución del problema.

### Descripción

El proyecto "Rush Hour Solver" tiene como objetivo proporcionar una solución automatizada para el juego "Rush Hour" mediante la implementación del algoritmo A*. La implementación se ha realizado en C++ y aborda las técnicas de programación orientada a objetos y el uso de makefile para la compilación.

### Compilación y Ejecución

Para poner en marcha el código, es imperativo operar en un entorno con el sistema operativo Linux y asegurarse de que todos los archivos `.h` y `.cpp` correspondientes a la solución desarrollada, así como los archivos `.txt` para pruebas, estén organizados en un mismo directorio. A continuación, se describe el proceso paso a paso:

1. **Preparación del Entorno:**
   - Abra una terminal de Linux y navegue hasta el directorio que contiene todos los archivos mencionados anteriormente.
   
2. **Compilación:**
   - Ejecute el comando `make` en la terminal para compilar todos los archivos necesarios del programa.
   
3. **Ejecución del Programa:**
   - Posteriormente, invoque `./main` para iniciar la ejecución del programa.
   - Al comienzo, el programa solicitará, a través de la consola, el nombre del primer archivo, que debe contener la información sobre cada automóvil en el tablero.
   - A continuación, se le pedirá que proporcione el nombre del segundo archivo, que debe albergar los datos de cada pared en el tablero.
   - Nota: En caso de que alguno de estos archivos no se encuentre en el directorio, o si se introduce un nombre incorrecto, el programa se interrumpirá y emitirá un mensaje de error.
   
4. **Despliegue de Resultados:**
   - Si todo procede sin inconvenientes, el programa se ejecutará y presentará inicialmente el vector de autos y el tablero en su estado inicial, mostrando cada auto en su respectiva posición.
   - Al concluir, se mostrará el vector de autos finales, el tablero final, los pasos seguidos para resolver el tablero introducido y el tiempo que tardó en encontrar la solución óptima para dicho tablero.

### Uso

Una vez compilado, el programa puede ser ejecutado desde la línea de comandos. El usuario deberá proporcionar los nombres de dos archivos: uno con la información de los automóviles y otro con la información de las paredes en el tablero. El programa proporcionará retroalimentación visual en la terminal, mostrando el estado inicial y final del tablero, los pasos realizados para llegar a la solución, y el tiempo de cálculo para encontrar la solución óptima.

### Contacto

Para más información o dudas, por favor contacta a [jaime.riquelme@usach.cl]
