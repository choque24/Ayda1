#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

// Definimos un máximo para el tamaño de los arreglos estáticos
const int MAX = 100;

// 1. Función manual para calcular la distancia entre dos puntos (x1,y1) y (x2,y2)
double calcularDistancia(double x1, double y1, double x2, double y2) {
    return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}

// 2. Función que calcula el peso del triángulo formado por los índices i, k, j
double pesoTriangulo(int i, int k, int j, int horizontal[], int vertical[]) {
    // Calculamos los tres lados del triángulo usando los arreglos de coordenadas
    double lado1 = calcularDistancia(horizontal[i], vertical[i], horizontal[k], vertical[k]);
    double lado2 = calcularDistancia(horizontal[k], vertical[k], horizontal[j], vertical[j]);
    double lado3 = calcularDistancia(horizontal[i], vertical[i], horizontal[j], vertical[j]);

    return lado1 + lado2 + lado3;
}

// 3. Función principal de Programación Dinámica
double resolverTriangulacion(int n, int horizontal[], int vertical[]) {
    // Tabla de estados (Matriz de costos mínimos)
    double T[MAX][MAX];

    // Inicializamos la tabla en cero
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            T[i][j] = 0.0;
        }
    }

    // gap es la diferencia entre los índices i y j (el tamaño del trozo de polígono)
    for (int gap = 2; gap < n; gap++) {
        for (int i = 0; i < n - gap; i++) {
            int j = i + gap;

            // Ponemos un valor "infinito" inicial
            T[i][j] = 1e9;

            // Probamos cada vértice k entre i y j para formar un triángulo
            for (int k = i + 1; k < j; k++) {

                // Aplicamos la relación de recurrencia
                double costoCandidato = T[i][k] + T[k][j] + pesoTriangulo(i, k, j, horizontal, vertical);

                // REEMPLAZO MANUAL DE std::min:
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

    // El resultado final para el polígono completo (del vértice 0 al n-1)
    return T[0][n - 1];
}

int main() {
    // Datos de entrada proporcionados
    int n = 7;
    int horizontal[7] = {0, 0, 8, 15, 27, 22, 10};
    int vertical[7] = {10, 20, 26, 26, 21, 12, 0};

    // Resolvemos el problema pasando los arreglos directamente
    double resultado = resolverTriangulacion(n, horizontal, vertical);

    // Salida por pantalla
    cout << fixed << setprecision(2);
    cout << "------------------------------------------" << endl;
    cout << "   TRIANGULACION DE POLIGONO CONVEXO" << endl;
    cout << "------------------------------------------" << endl;
    cout << "Numero de vertices: " << n << endl;
    cout << "Costo minimo total: " << resultado << endl;
    cout << "------------------------------------------" << endl;

    return 0;
}