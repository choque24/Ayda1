//
// Created by mauri on 23/1/2026.
//#include <iostream>
#include <iostream>

using namespace std;

void verArreglo(int arreglo [], int n) {
    for (int i = 0; i < n; i++) {
        cout << arreglo[i] << " ";
    }
    cout << endl;
}

bool recursividad (int arreglo[], int i, int inicio, int fin, int x) {
    if (inicio >= fin) {
        return false;
    }
    int mitad = (inicio + fin) / 2;

    if (arreglo[i] + arreglo[mitad] == x) {
        return true;
    }

    if (arreglo[i] + arreglo[mitad] > x) {
        return recursividad(arreglo, i, inicio , mitad, x);
    }
    
    return recursividad(arreglo, i, mitad + 1, fin, x);
}

bool busquedaBinariaMaximo(int arreglo[],int inicio, int fin, int x) {
    bool existe = false;

    while (!existe && inicio <= fin) {
        existe = recursividad(arreglo, inicio, inicio + 1, fin, x);
        inicio++;
    }

    return existe;
}

int main() {
    const int MAX = 6;
    int arreglo[MAX] = {0, 1, 2, 3, 7, 8};

    const int x = 6;
    verArreglo(arreglo, MAX);

    bool existe = false;
    existe = busquedaBinariaMaximo(arreglo, 0, MAX - 1, x);
    cout << existe << endl;
    return 0;
}
