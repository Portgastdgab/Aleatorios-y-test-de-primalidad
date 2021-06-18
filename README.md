## Project Fyle Structure

    Project_name/
    |
    |---- CMakeLists.txt
    |---- main.cpp
    |
    |---- include/
    |       |
    |       |---- Project_name
    |               |
    |               |---- public_headers.hh (C++ only)
    |               |---- public_headers.h (C & C++)
    |---- src/
    |       |
    |       |---- private_headers.hh (C++ only)
    |       |---- private_headers.h  (C & C++)
    |       |---- implementation_files.cc
    |       |---- implementation_files.C (if compiler doesn't accept .cc)
    |       |---- inline_definition_files.icc
    |
    |---- libs/
    |       |
    |       |---- A
    |       |
    |       |---- B
    |
    |---- tests/

## Compile the project

```bash I'm A tab
    take build/
    cmake ..
    make --build .
```

original NTL documentation command
```bash
	g++ -g -O2 -std=c++11 -pthread -march=native foo.cpp -o foo -lntl -lgmp -lm
```

Un algoritmo de generación de número aleatorios debe de tener las siguientes propiedades:
* Periodicidad (repetitibilidad)
* Predicibilidad
* Irreproducibles
* Independencia de valores
* Complejidad
* Propiedades estadísticas
* Número de bits
* Semilla

Primes
* La criba de Eratóstenes
* Test de primalidad de Fermat
* Test de Solovay-Strassen
* Test de Miller-Rabin
* Primality testing using the factorization n-1
* Algoritmos AKS

Para la generación de números aleatorios grandes, deben obtener la semilla usando el hardware como:
* The surrounding light and scene
* The surrounding sound or noise
* The TCP information for the network
* The RTT of a specific network, dependant on the congestion of the network
* System time
* Scheduling delay over core or multicores
* Entre otros


Cree una función que se llame RANDBIGINTEGER y que pueda ejecutarse desde la línea de comandos o main(). Tiene un argumento de entrada, número de bits del número aleatorio (tamaño). Imprimir el número aleatorio.

Cree una función para el test de primalidad llamada PRIMECHECK que recibirá un número positivo grande y retornará verdadero o falso. Ejemplo:
