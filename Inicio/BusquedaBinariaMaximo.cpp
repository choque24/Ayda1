//
// Created by mauri on 22/1/2026.
//
/* En aplicaciones de monitoreo (como salud, clima o rendimiento físico), es común analizar secuencias de datos para identificar comportamientos que alcanzan un pico y luego decrecen, lo que se conoce como una secuencia unimodal. Formalmente, una secuencia A = (a1, a2,. . . , an) de longitud n ≥ 3 se llama unimodal si sus elementos primero aumentan y luego disminuyen, es decir existe un índice p con 1 ≤ p ≤ n tal que a1 < a2 < · · · < ap y ap > ap+1 > · · · > an. Implemente un algoritmo en C++ que dado un arreglo unidimensional que almacena una secuencia unimodal encuentre el índice p. La complejidad temporal del algoritmo debe pertenecer a O(log n).
 */
#include <iostream>

using namespace std;

void verArreglo(int arreglo [], int n) {
    for (int i = 0; i < n; i++) {
        cout << arreglo[i] << " ";
    }
    cout << endl;
}

int recursividad (int arreglo[], int inicio, int fin) {
    if (inicio >= fin) {
        return inicio;
    }

    int mitad = (inicio + fin) / 2;

    if (arreglo[mitad] < arreglo[mitad + 1]) {
        return recursividad(arreglo, mitad + 1, fin);
    }

    return recursividad(arreglo, inicio, mitad);
}

int busquedaBinariaMaximo(int arreglo[],int inicio, int fin) {
    if ((fin - inicio) < 2) {
        return -1;
    }
    return recursividad(arreglo, inicio, fin);
}

int main() {
    const int MAX = 3;
    int arreglo[MAX] = {0, 90, 30};

    verArreglo(arreglo, MAX);

    int indiceMaximo = busquedaBinariaMaximo(arreglo, 0, MAX - 1);
    cout << indiceMaximo << endl;
    cout << "El maximo es: " << arreglo[indiceMaximo] << endl;
    return 0;
}