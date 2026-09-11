//
// Created by mauri on 21/1/2026.
//#include <iostream>
#include <algorithm>
#include <climits>
#include <iostream>

using namespace std;

float recursion(int inicioX, int finX, int inicioY, int finY, int arrX[], int arrY[]) {
    if (finX - inicioX < 2 && finY - inicioY < 2) {
        return ((max(arrX[inicioX], arrY[inicioX]) + min(arrX[finX], arrY[finY])) / 2.0);
    }
    int n = finX - inicioX+1;
    int mitadX = (inicioX + finX) / 2;
    int mitadY = (inicioY + finY) / 2;
    if (arrX[mitadX] > arrY[mitadY]) {
        if (n%2==0)return recursion(inicioX, mitadX, mitadY+1, finY, arrX, arrY);
        return recursion(inicioX, mitadX, mitadY, finY, arrX, arrY);
    } else {
        if (n%2==0)return recursion(mitadX+1, finX, inicioY, mitadY, arrX, arrY);
        return recursion(mitadX, finX, inicioY, mitadY, arrX, arrY);
    }
}


/*
 * MEDIANA DE DOS VECTORES CON BÚSQUEDA BINARIA
 * Complejidad: O(log n)
 *
 * Idea: Encontrar el "corte" correcto que divide ambos vectores
 * en mitad izquierda y mitad derecha
 */

void printVector(int arr[], int n, string nombre) {
    cout << nombre << ": [";
    for (int i = 0; i < n; i++) {
        cout << arr[i];
        if (i < n - 1) cout << ", ";
    }
    cout << "]" << endl;
}

// Función principal con BÚSQUEDA BINARIA
double calcularMedianaBinaria(int X[], int Y[], int n) {
    // BÚSQUEDA BINARIA sobre X
    int inicio = 0;
    int fin = n;

    cout << "\nIniciando búsqueda binaria..." << endl;
    cout << "Buscamos cortar X entre posición " << inicio << " y " << fin << endl;

    while (inicio <= fin) {
        // DIVIDE: Partimos X en la posición i
        int i = (inicio + fin) / 2;

        // Para que la mitad izquierda tenga n elementos:
        // Si tomamos i de X, tomamos (n - i) de Y
        int j = n - i;

        cout << "\n--- Probando corte ---" << endl;
        cout << "Corte en X: posición " << i << " (tomo " << i << " elementos de X)" << endl;
        cout << "Corte en Y: posición " << j << " (tomo " << j << " elementos de Y)" << endl;

        // Elementos en las fronteras
        // maxIzqX = último elemento de la parte izquierda de X
        // minDerX = primer elemento de la parte derecha de X
        int maxIzqX = (i == 0) ? INT_MIN : X[i - 1];
        int minDerX = (i == n) ? INT_MAX : X[i];

        int maxIzqY = (j == 0) ? INT_MIN : Y[j - 1];
        int minDerY = (j == n) ? INT_MAX : Y[j];

        cout << "Frontera X: maxIzq=" << maxIzqX << ", minDer=" << minDerX << endl;
        cout << "Frontera Y: maxIzq=" << maxIzqY << ", minDer=" << minDerY << endl;

        // VERIFICAR si la partición es válida
        if (maxIzqX <= minDerY && maxIzqY <= minDerX) {
            // ¡Partición correcta encontrada!
            cout << "\n✓ ¡Partición válida encontrada!" << endl;

            // La mediana está entre el max de la izquierda y el min de la derecha
            int maxIzq = max(maxIzqX, maxIzqY);
            int minDer = min(minDerX, minDerY);

            cout << "max(izquierda) = max(" << maxIzqX << ", " << maxIzqY << ") = " << maxIzq << endl;
            cout << "min(derecha) = min(" << minDerX << ", " << minDerY << ") = " << minDer << endl;
            cout << "Mediana = (" << maxIzq << " + " << minDer << ") / 2.0" << endl;

            return (maxIzq + minDer) / 2.0;
        }
        // CONQUISTA: Ajustamos la búsqueda
        else if (maxIzqX > minDerY) {
            // Tomamos demasiado de X, necesitamos menos
            cout << "✗ " << maxIzqX << " > " << minDerY << " → Tomamos demasiado de X" << endl;
            cout << "Buscamos más a la IZQUIERDA en X" << endl;
            fin = i - 1;
        } else {
            // Tomamos muy poco de X, necesitamos más
            cout << "✗ " << maxIzqY << " > " << minDerX << " → Tomamos muy poco de X" << endl;
            cout << "Buscamos más a la DERECHA en X" << endl;
            inicio = i + 1;
        }
    }

    return 0.0; // No debería llegar aquí
}

double calcularMediana(int X[], int Y[], int n) {
    cout << "\n=== Calculando Mediana ===" << endl;
    printVector(X, n, "Vector X");
    printVector(Y, n, "Vector Y");
    cout << "Total de elementos: 2n = " << (2 * n) << endl;

    return calcularMedianaBinaria(X, Y, n);
}

int main() {
    int n = 4;
    int X1[] = {1, 3, 5, 7};
    int Y1[] = {2, 4, 6, 8};

float floa =recursion(0, n - 1, 0, n - 1, X1, Y1);
    cout <<floa;

    /*cout << "\n\n--- EJEMPLO 2 ---" << endl;
    int X2[] = {1,  3,  5,  7,  10, 20, 30};
    int Y2[] = {0,  1,  5,  10, 15, 20 ,25};
    double mediana2 = calcularMediana(X2, Y2, 7);
    cout << "\n*** RESULTADO FINAL: " << mediana2 << " ***" << endl;

    */
    return 0;
}

/*int main() {
    cout << "========================================" << endl;
    cout << "MEDIANA CON BÚSQUEDA BINARIA O(log n)" << endl;
    cout << "========================================" << endl;

    // Ejemplo 1: Caso simple
    cout << "\n--- EJEMPLO 1 ---" << endl;
    int X1[] = {1, 3, 5, 7};
    int Y1[] = {2, 4, 6, 8};
    double mediana1 = calcularMediana(X1, Y1, 4);
    cout << "\n*** RESULTADO FINAL: " << mediana1 << " ***" << endl;
    cout << "Verificación: [1,2,3,4,5,6,7,8] → mediana = (4+5)/2 = 4.5 ✓" << endl;

    // Ejemplo 2: Otro caso
    cout << "\n\n--- EJEMPLO 2 ---" << endl;
    int X2[] = {1,  3,  5,  7,  10, 20, 30};
    int Y2[] = {0,  1,  5,  10, 15, 20 ,25};
    double mediana2 = calcularMediana(X2, Y2, 7);
    cout << "\n*** RESULTADO FINAL: " << mediana2 << " ***" << endl;

    // Ejemplo 3: Vectores pequeños
    cout << "\n\n--- EJEMPLO 3 ---" << endl;
    int X3[] = {1, 5};
    int Y3[] = {3, 7};
    double mediana3 = calcularMediana(X3, Y3, 2);
    cout << "\n*** RESULTADO FINAL: " << mediana3 << " ***" << endl;

    cout << "\n========================================" << endl;
    cout << "COMPLEJIDAD TEMPORAL: O(log n) ✓" << endl;
    cout << "Usamos búsqueda binaria sobre un vector" << endl;
    cout << "de tamaño n, por lo tanto O(log n)" << endl;
    cout << "========================================" << endl;

    return 0;
}*/
