#include <iostream>
#include <ostream>
using namespace std;
//
// Created by mauri on 4/3/2026.
//
const int cuota1 = 40;
const int cuota2 = 30;
const int cuota3 = 20;
const int cuota4 = 10;

const int cuotas[4] = {cuota1, cuota2, cuota3, cuota4};

int getMeses(int cantidadMeses, int sueldo, int precio) {
    int i = 0;
    while ((precio * cuotas[i]) / 100 >= sueldo) {
        i++;
    }

    if (i < 3) {
        cantidadMeses += getMeses(cantidadMeses, sueldo, precio);
    }

    return cantidadMeses;
}

int getMesesRecursivo(int cantidadMeses, int sueldo, int precio) {
    if (precio * cuotas)
    getMesesRecursivo(cantidadMeses, sueldo, precio);
}

main() {
    int precio = 1000;
    int sueldo = 100;

    int cantidadMeses = getMeses(4, sueldo, precio);
    cout << cantidadMeses << endl;
    return 0;
}
