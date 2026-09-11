#include <iostream>

/*
* Problema del corte de varillas. Dada una varilla de longitud n y una tabla de precios pi para i=
1, 2, ... n, se desea determinar la máxima ganancia G(n) que se puede obtener cortando la varilla y vendiéndose en partes. Si el precio de la varilla de n metros es suficientemente grande, la solución
podría ser vender la varilla sin cortar.
Ejemplo: supongamos que la empresa compra varillas de 4 metros y conoce los precios para los distintos cortes (note que el precio no depende de la cantidad metros):
ANÁLISIS Y DISEÑO DE ALGORITMOS I PRÁCTICO Nº 6. PROGRAMACIÓN DINÁMICA
Longitud: i 1 2 3 4
Precio: pi 1 5 8 9
Podemos observar que la mayor ganancia se obtiene cortando la varilla en dos partes de 2 metros cada una, p2= 5, entonces ganancia = 10, la cual es óptima
 */
using namespace std;

const int LONGITUD = 6;

void leerArreglo(int arreglo[]) {
    for (int i = 0; i < LONGITUD; i++) {
        cout << arreglo[i] << ", ";
    }
    cout << endl;
}

int getMayorGanancia(int arreglo []) {
    int Ganancia[LONGITUD];

    Ganancia[0] = 0;

    for (int i = 1; i <= LONGITUD; i++) {
        int mayor = -1;

        for (int j = 1; j <= i; j++) {
            int posibleGanancia = arreglo[j] + Ganancia[i - j];

            if (posibleGanancia > mayor) {
                mayor = posibleGanancia;
            }
        }
        Ganancia[i] = mayor;
    }

    leerArreglo(Ganancia);

    return Ganancia[LONGITUD];
}

int main() {

    int arreglo[] = {0,2,7,8,10,11,15};

    leerArreglo(arreglo);

    int mayorGanancia = getMayorGanancia(arreglo);

    cout << "La mayor ganancia del arreglo es: " << mayorGanancia << endl;
    return 0;
}