#include <stdio.h>
#include <stdlib.h>

void carga(int**, int**, int);
void prodEsc(int*, int*, int);
int par(int*, int);
void nArreglo(int*, int**, int, int);

int main() {
    int *a, *b, *c, m, n, s;
    printf("\nIngrese el tamanio que requiere de los arreglos: ");
    scanf("%d", &m);
    carga(&a, &b, m);
    prodEsc(a, b, m);
    printf("\nElija qué arreglo desea enviar (escribir 1 o 2): ");
    scanf("%d", &s);
    if (s == 1) {
        free(b);
        n = par(a, m);
        nArreglo(a, &c, n, m);
        free(a);
    } else {
        free(a);
        n = par(b, m);
        nArreglo(b, &c, n, m);
        free(b);
    }
    printf("\nEl nuevo arreglo tiene los siguientes valores:\n[ ");
    for (int i = 0; i < n; i++) {
        printf("%d, ", c[i]);
    }
    printf("]");
    free(c);
    return 0;
}

void carga(int **a, int **b, int m) {
    *a = (int *)malloc(sizeof(int) * m);
    *b = (int *)malloc(sizeof(int) * m);
    for (int i = 0; i < m; i++) {
        printf("\nIngrese un numero en la posicion %d del primer arreglo: ", i + 1);
        scanf("%d", &(*a)[i]);
        printf("\nIngrese un numero en la posicion %d del segundo arreglo: ", i + 1);
        scanf("%d", &(*b)[i]);
    }
}

void prodEsc(int *a, int *b, int m) {
    int p = 0;
    for (int i = 0; i < m; i++) {
        p += (a[i] * b[i]);
    }
    printf("\nEl producto escalar entre los elementos de ambos arreglos es: %d", p);
}

int par(int *t, int m) {
    int nPar = 0;
    for (int i = 0; i < m; i++) {
        if ((t[i] % 2) == 0)
            nPar++;
    }
    return nPar;
}

void nArreglo(int *a, int **c, int n, int m) {
    int j = 0;
    *c = (int *)malloc(sizeof(int) * n);
    for (int i = 0; i < m; i++) {
        if ((a[i] % 2) == 0) {
            (*c)[j] = a[i];
            j++;
        }
    }
}
