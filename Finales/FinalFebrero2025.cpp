#include <iostream>
//Start : 8:20
// TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
using namespace std;

int recursion(int A[], int i, int inicio, int mitad, int fin, int masRepetido) {
    if (inicio >= fin) {
        return masRepetido;
    }

    if (A[i] < A[mitad]) {
        return recursion(A, i, inicio, (inicio + mitad) / 2, mitad, masRepetido);
    }

    if (A[i] > A[mitad]) {
        return recursion(A, i, mitad + 1, (mitad + fin) / 2, fin, masRepetido);
    }

    return masRepetido + 1;
}

int apareceMasVeces(int A[], int inicio, int mitad, int fin, int & numeroMasRepetido) {
    int actual = numeroMasRepetido;
    for (int i = inicio; i < fin; i++) {
        actual = recursion(A, i, inicio, (i + fin) / 2, fin, numeroMasRepetido);
        if (numeroMasRepetido == actual) {}
    }
    return numeroMasRepetido;
}


int main() {
    // TIP Press <shortcut actionId="RenameElement"/> when your caret is at the <b>lang</b> variable name to see how CLion can help you rename it.
    auto lang = "C++";
    cout << "Hello and welcome to " << lang << "!\n";
    int n = 10;
    int A[n] = {1, 2, 3, 4, 5, 5, 6, 7, 8, 9};

    cout << apareceMasVeces(A, 0, n / 2, n, A[0]);


    return 0;
    // TIP See CLion help at <a href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>. Also, you can try interactive lessons for CLion by selecting 'Help | Learn IDE Features' from the main menu.
}
