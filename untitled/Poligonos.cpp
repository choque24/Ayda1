#include <iostream>
using namespace std;
#include <cmath>

double calcularDistancia(int V1, int V2, int horizontal[], int vertical[]) {
    int X = horizontal[V1] - horizontal[V2];
    int Y = vertical[V2] - vertical[V1];
    return sqrt(X * X + Y * Y);
}

double poligonosRecursividad(int i, int j, int horizontal[], int vertical[]) {
    if (j < 3) return 0;
    if (j == 3) return calcularDistancia(i, i + 2, horizontal, vertical);
    double costoActual = 0;
    double costoMin = INT_MAX;
    for (int k = 1; k <= j - 2; k++) {
        costoActual = poligonosRecursividad(i, k + 1, horizontal, vertical) +
                      poligonosRecursividad(i + k, j - k, horizontal, vertical) +
                      calcularDistancia(i, i + k, horizontal, vertical) + calcularDistancia(
                          i + k, i + j - 1, horizontal, vertical);
        if (costoActual < costoMin) costoMin = costoActual;
    }
    return costoMin;
}

int main() {
    int n = 7;
    double distancias[n][n];
    int horizontal[n] = {0, 0, 8, 15, 27, 22, 10};
    int vertical[n] = {10, 20, 26, 26, 21, 12, 0};

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            distancias[i][j] = 0;
        }
    } //inicializa la matriz en 0

    for (int i = 0; i < n; i++) {
        for (int k = 0; k < n - i; k++) {
            distancias[k][k + i] = calcularDistancia(k, k + i, horizontal, vertical);
        }
    } //carga las distancias de los vertices

    for (int i = 0; i < n; i++) {
        cout << endl;
        for (int k = 0; k < n; k++) {
            cout << distancias[i][k] << " ";
        }
    } //imprime la matriz

    double costoMin = INT_MAX;
    double costoActual = 0;

    for (int i = 0; i < n; i++) {
        costoActual = poligonosRecursividad(i, n, horizontal, vertical);
        if (costoActual < costoMin) costoMin = costoActual;
    }
    cout << endl << costoMin << endl;
    return 0;
}
