#include <algorithm>
#include <iostream>
//Implemente en C++ los métodos de ordenamiento mergesort y quicksort de forma tal que, dado un arreglo de elementos comparables, ordenen sus elementos ascendentemente
using namespace std;

//FUNCION MERGE-SORT
void merge(int arreglo[], int inicio, int mitad, int fin) {
    int longitudIzquierda = mitad - inicio + 1;
    int longitudDerecha = fin - mitad;

    int izquierda[longitudIzquierda];
    int derecha[longitudDerecha];

    for (int i = 0; i < longitudIzquierda; i++) {
        izquierda[i] = arreglo[inicio + i];
    }
    for (int i = 0; i < longitudDerecha; i++) {
        derecha[i] = arreglo[mitad + i + 1];
    }

    int i = 0, j = 0, k = inicio;

    while (i < longitudIzquierda && j < longitudDerecha) {
        if (izquierda[i] < derecha[j]) {
            arreglo[k] = izquierda[i];
            i++;
        } else {
            arreglo[k] = derecha[j];
            j++;
        }
        k++;
    }
    while (i < longitudIzquierda) {
        arreglo[k] = izquierda[i];
        i++;
        k++;
    }
    while (j < longitudDerecha) {
        arreglo[k] = derecha[j];
        j++;
        k++;
    }
    cout << "Soy un merge" << endl;
}

void mergeRecursivo(int A[], int inicio, int fin) {
    if (inicio >= fin) {
        return;
    }

    int mitad = (inicio + fin) / 2;

    mergeRecursivo(A, inicio, mitad);
    mergeRecursivo(A, mitad + 1, fin);
    merge(A, inicio, mitad, fin);
    cout << "Soy un mergeRecursivo" << endl;
}

//METODO QUICKSORT
void intercambio(int &a, int &b) {
    int aux = a;
    a = b;
    b = aux;
}

int quickRecursivo(int A[], int inicio, int fin) {
    int pivote = A[fin];
    int posicionPivote = inicio;

    for (int i = inicio; i < fin; i++) {
        if (A[i] <= pivote) {
            intercambio(A[posicionPivote], A[i]);
            posicionPivote++;
        }
    }

    intercambio(A[posicionPivote], A[fin]);
    return posicionPivote;
}

//{7, 5, 1 ,9 ,3 }
int quickRecursivo2(int A[], int inicio, int fin) {
    int pivote = A[inicio];
    int posicionPivote = inicio;

    for (int i = inicio + 1; i <= fin; i++) {
        if (A[i] <= pivote) {
            posicionPivote++;
            intercambio(A[posicionPivote], A[i]);
        }
    }

    intercambio(A[posicionPivote], A[inicio]);
    return posicionPivote;
}

void quickSort(int A[], int inicio, int fin) {
    if (inicio >= fin) {
        return;
    }

    int pivote = quickRecursivo2(A, inicio, fin);

    quickSort(A, inicio, pivote - 1);
    quickSort(A, pivote + 1, fin);
}

/*2) Sea T un arreglo ordenado de n enteros diferentes (puede incluir números negativos): a) Implemente un algoritmo en C++ que encuentre el índice i tal que 0 ≤ i < n y T [i] = i, siempre y cuando exista tal índice. La complejidad temporal de la solución propuesta debe pertenecer a O(log n).
b) Explicar por qué una búsqueda binaria es esencial en grandes volúmenes de datos (nube, redes sociales, etc.)*/

bool buscarIrecursivo(int arr[], int i, int inicio, int n) {
    if (arr[i] == i) {
        return true;
    }
    if (i > n || i < inicio){
        return false;
    }
    if (arr[i] < i) {
        return buscarIrecursivo(arr, (i + n) / 2, i + 1, n);
    }
    return buscarIrecursivo(arr, (inicio + i) / 2, inicio, i);
}

void busquedaBinaria(int arr[], int inicio, int n) {
    if (arr[inicio] > n && arr[n] < 0) {
        return;
    }
    if (buscarIrecursivo(arr, n / 2, inicio, n)) {
        cout << "Irecursivo" << endl;
    } else {
        cout << "No recursivo" << endl;
    }
}

int calcularMediana(int arreglo [], int arreglo2[], int longitud) {
    int mediana = 0;

    if (longitud == 1)
        return (arreglo[0] + arreglo2[0]) / 2 ;

    if (longitud == 2) {
        int maxIzq = max(arreglo[0], arreglo2[0]);
        int minDer = min(arreglo[1], arreglo2[1]);
        return (maxIzq + minDer) / 2;
    }

    
    return mediana;
}

int encontrarMaximo (int A[], int inicio, int fin) {
    if (inicio >= fin) return inicio;
    int medio = inicio + (fin - inicio) / 2;

    if (A[medio] < A[medio + 1]) {
        return encontrarMaximo(A, medio + 1, fin);
    }
    return encontrarMaximo(A, inicio, medio);
}

// Diseñe un algoritmo para calcular la potencia a^b, donde a y b son enteros y b≥0
int getPotencia(int a, int b) {
    if (b == 0) return 1;

    if (b == 1) return a;

}

int main() {
    const int MIN = 0;
    const int MAX = 5;
    const int MAX2 = 5;

    int arreglo[MAX] = {0, 15, 10, 9, 8};
    int arreglo2[MAX2] = {1, 3, 5, 10, 9};

    //  Arreglo ordenado por mergeSort
    //    mergeRecursivo(arreglo, 0, MAX - 1);
    // quickSort(arreglo, 0, MAX - 1);
    // for (int i: arreglo) {
    //     cout << i << "" << endl;
    // }

    //busquedaBinaria(arreglo, MIN, MAX);y
    // cout << calcularMediana(arreglo, arreglo2, MAX);
    cout << encontrarMaximo(arreglo, MIN, MAX - 1);
    cout << encontrarMaximo(arreglo2, MIN, MAX - 1);

    cout << "Hola";
    return 0;
}