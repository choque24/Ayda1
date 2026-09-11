//
// Created by mauri on 12/3/2026.
//

#include <iostream>
using namespace std;

void imprimirMatriz(int a[][7], int n) {
    for (int i=0;i<n;i++) {
        for (int j= 0; j<n;j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}

int robotMatriz(int a[][4], int i, int j) {
    int b[i][j];
     b[0][0] = a[0][0];
    for (int k = 1; k < j; k++) {
        b[0][k] = a[0][k]+b[0][k-1];
    }
    for (int k = 1; k < i; k++) {
        b[k][0] = a[k][0]+b[k-1][0];
    }


    for (int k = 1; k < i; k++) {
        for (int l = 1; l < j; l++) {
            b[k][l] = a[k][l] + min(b[k-1][l], b[k][l-1]);
        }
    }
    return b[i-1][j-1];

}


void matriz (int n, int d[]) {
    int mat[7][7];
    int mejor[7][7];
    for (int i = 1; i <= n; i++) {
        for (int j=1; j<=n;j++) {
            mat[i][j]=100000000;
            mejor[i][j]=0;
        }
    }
    for (int i = 1; i <= n; i++) {
        mat[i][i] = 0;
    }
    int t;
    for (int l=1; l< n; l++) {
        for (int i=1; i<=n-l; i++) {
            int j=i+l;
            for (int k=i; k<j; k++) {
                t = mat[i][k] + mat[k+1][j] + d[i-1 ]*d[k]*d[j];
                if (t < mat[i][j]) {
                    mat[i][j]=t;
                    mejor[i][j]=k;
                }
            }
        }
    }
    imprimirMatriz(mat, n);
    imprimirMatriz(mejor, n);
}

int main() {
    int i = 6;
    int j = 4;
    int matri[6][4] = {
        {1, 2, 3, 4}, // Fila 0
        {5, 6, 7, 8}, // Fila 1
        {9, 1, 2, 3}, // Fila 2
        {4, 5, 6, 7}, // Fila 3
        {8, 9, 1, 2}, // Fila 4
        {3, 4, 5, 6}  // Fila 5
    };
    cout << robotMatriz(matri, i, j);

    int n= 7;
    int d[n]={10,30,5,60,15,10,25};
    matriz(n, d);


    return 0;
}
