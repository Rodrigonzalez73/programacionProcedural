#include <stdio.h>

#define N 3 // Tamaño de las matrices cuadradas (cambia según tus necesidades)

// Definir una estructura para una matriz cuadrada de enteros
struct Matriz {
    int datos[N][N];
};

// Función para cargar una matriz
void cargarMatriz(struct Matriz *matriz, const char *nombre) {
    printf("Ingrese los valores para la matriz %s:\n", nombre);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%s[%d][%d]: ", nombre, i, j);
            scanf("%d", &matriz->datos[i][j]);
        }
    }
}

// Función recursiva para calcular el producto escalar de dos filas
int productoEscalarFilas(const struct Matriz *matrizA, const struct Matriz *matrizB, int filaA, int filaB, int columna, int resultado) {
    if (columna < N) {
        resultado += matrizA->datos[filaA][columna] * matrizB->datos[filaB][columna];
        return productoEscalarFilas(matrizA, matrizB, filaA, filaB, columna + 1, resultado);
    } else {
        return resultado;
    }
}

// Función recursiva para calcular el producto escalar de dos columnas
int productoEscalarColumnas(const struct Matriz *matrizA, const struct Matriz *matrizB, int columnaA, int columnaB, int fila, int resultado) {
    if (fila < N) {
        resultado += matrizA->datos[fila][columnaA] * matrizB->datos[fila][columnaB];
        return productoEscalarColumnas(matrizA, matrizB, columnaA, columnaB, fila + 1, resultado);
    } else {
        return resultado;
    }
}

int main() {
    struct Matriz matrizA, matrizB;
    int filaA, filaB, columnaA, columnaB;

    // Cargar las matrices A y B
    cargarMatriz(&matrizA, "A");
    cargarMatriz(&matrizB, "B");

    // Calcular el producto escalar de filas
    printf("Ingrese el número de la fila de la matriz A: ");
    scanf("%d", &filaA);
    printf("Ingrese el número de la fila de la matriz B: ");
    scanf("%d", &filaB);

    int resultadoFilas = productoEscalarFilas(&matrizA, &matrizB, filaA, filaB, 0, 0);
    printf("El producto escalar de la fila %d de A y la fila %d de B es: %d\n", filaA, filaB, resultadoFilas);

    // Calcular el producto escalar de columnas
    printf("Ingrese el número de la columna de la matriz A: ");
    scanf("%d", &columnaA);
    printf("Ingrese el número de la columna de la matriz B: ");
    scanf("%d", &columnaB);

    int resultadoColumnas = productoEscalarColumnas(&matrizA, &matrizB, columnaA, columnaB, 0, 0);
    printf("El producto escalar de la columna %d de A y la columna %d de B es: %d\n", columnaA, columnaB, resultadoColumnas);

    return 0;
}
