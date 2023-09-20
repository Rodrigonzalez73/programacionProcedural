#include <stdio.h>
#define empleados 3
#define sueldos 1

void cargaMatriz(float matriz[empleados][sueldos], int filas, int columnas) {
    if (filas < empleados) {
        if (columnas < sueldos) {
            printf("Ingrese el sueldo del empleado %d: ", filas);
            scanf("%f", &matriz[filas][columnas]);
            cargaMatriz(matriz, filas, columnas + 1);
        } else {
            cargaMatriz(matriz, filas + 1, 0);
        }
    }
}

float sueldoEmpleado3(float matriz[empleados][sueldos], int filas) {
    if (filas == 3) {
        return matriz[3][0];
    } else if (filas < empleados) {
        return sueldoEmpleado3(matriz, filas + 1);
    } else {
        // Si no hay al menos 3 empleados, devuelve -1 o algún valor indicativo de error
        return -1.0;
    }
}

float calcularPromedio(float matriz[empleados][sueldos], int filas, int columnas) {
    if (filas < empleados) {
        if (columnas < sueldos) {
            return matriz[filas][columnas] + calcularPromedio(matriz, filas, columnas + 1);
        } else {
            return calcularPromedio(matriz, filas + 1, 0);
        }
    } else {
        return 0.0;
    }
}

int main() {
    float matriz[empleados][sueldos];
    int filas = 0;
    int columnas = 0;

    cargaMatriz(matriz, filas, columnas);

    float promedio = calcularPromedio(matriz, 0, 0);
    promedio /= (empleados * sueldos);

    printf("El promedio de sueldos es: %.2f\n", promedio);

    return 0;
}
