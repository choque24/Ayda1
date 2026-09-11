#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

const int MAX = 100;

// Función para calcular la distancia entre dos puntos (x1,y1) y (x2,y2)
double calcularDistancia(double x1, double y1, double x2, double y2) {
    return sqrt(pow(x1 - x2, 2) + pow(x1 - x2, 2));
}

double costoSiEsCuerda(int i, int j, int n, int horizontal[], int vertical[]) {
    if (j == i + 1 || (i == 0 && j == n - 1)) {
        return 0.0;
    }
    return sqrt(pow((double)horizontal[i] - horizontal[j], 2) +
                pow((double)vertical[i] - vertical[j], 2));
}

double resolverTriangulacion(int n, int horizontal[], int vertical[]) {
    double T[MAX][MAX];

    // Inicializamos la tabla
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            T[i][j] = 0.0;
        }
    }

    for (int vertices = 2; vertices < n; vertices++) {
        for (int i = 0; i < n - vertices; i++) {
            int j = i + vertices;
            T[i][j] = 10000;
            for (int k = i + 1; k < j; k++) {

                double nuevasCuerdas = costoSiEsCuerda(i, k, n, horizontal, vertical) +
                                       costoSiEsCuerda(k, j, n, horizontal, vertical);

                double costoCandidato = T[i][k] + T[k][j] + nuevasCuerdas;

                if (costoCandidato < T[i][j]) {
                    T[i][j] = costoCandidato;
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << T[i][j] << " ";
        }
        cout << endl;
    }

    return T[0][n - 1];
}

int main() {
    // Datos de tu actividad
    int n = 7;
    int horizontal[7] = {0, 0, 8, 15, 27, 22, 10};
    int vertical[7] = {10, 20, 26, 26, 21, 12, 0};

    double resultado = resolverTriangulacion(n, horizontal, vertical);

    cout << "Costo total de las diagonales: " << resultado << endl;

    return 0;
}//
// Created by mauri on 19/2/2026.
//
