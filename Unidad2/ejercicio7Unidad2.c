#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define filas 5
#define columnas 4

void cargaAleatoria(int x[filas][columnas]) {
    srand(time(NULL));
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            x[i][j] = rand() % 200 - 100; // Números aleatorios entre -100 y 99
        }
    }
}

void mostrarTabla(int x[filas][columnas]) {
    printf("Tabla cargada:\n");
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            printf("%4d ", x[i][j]);
        }
        printf("\n");
    }
}

void sumaDeFilas(int arreglo[filas][columnas]) {
    printf("\nSuma de cada fila:\n");
    for (int i = 0; i < filas; i++) {
        int suma = 0;
        for (int j = 0; j < columnas; j++) {
            suma += arreglo[i][j];
        }
        printf("Fila %d: %d\n", i + 1, suma);
    }
}

double promedioTerceraColumna(int arreglo[filas][columnas]) {
    int suma = 0;
    for (int i = 0; i < filas; i++) {
        suma += arreglo[i][2]; // Suma de la tercera columna
    }
    return (double) suma / filas;
}

int contarMayoresA100(int arreglo[filas][columnas]) {
    int contador = 0;
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            if (arreglo[i][j] > 100) {
                contador++;
            }
        }
    }
    return contador;
}

int main() {
    int arreglo[filas][columnas];

    cargaAleatoria(arreglo);
    mostrarTabla(arreglo);

    sumaDeFilas(arreglo);

    double promedio = promedioTerceraColumna(arreglo);
    printf("\nEl promedio de la tercera columna es: %.2lf\n", promedio);

    int mayoresA100 = contarMayoresA100(arreglo);
    printf("Cantidad de números mayores a 100: %d\n", mayoresA100);

    return 0;
}