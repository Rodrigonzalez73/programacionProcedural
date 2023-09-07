#include <stdio.h>

// Definir una matriz para almacenar los montos financiados
float montos[3][5] = {
    {2, 7.5, 9, 2.5, 3.5},   // Categoría Micro
    {13, 45.5, 55, 15, 22.5}, // Categoría Pequeña
    {100, 360, 450, 125, 180} // Categoría Mediana
};

// Función para calcular el monto total financiado para una categoría ingresada por teclado
float montoTotalPorCategoria(int categoria) {
    float total = 0;
    for (int i = 0; i < 5; i++) {
        total += montos[categoria][i];
    }
    return total;
}

// Función para calcular el monto total financiado para el sector de Servicios
float montoTotalServicios() {
    float total = 0;
    for (int i = 0; i < 3; i++) {
        total += montos[i][3]; // El sector de Servicios está en la columna 3
    }
    return total;
}

// Función para emitir un listado con el total financiado por categoría y sector
void listarMontos() {
    printf("Montos Financiados:\n");
    printf("Categoria\tSector\t\tMonto (millones de pesos)\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 5; j++) {
            printf("%d\t\t", i + 1); // Categoría
            printf("%d\t\t", j + 1); // Sector
            printf("%.2f\n", montos[i][j]);
        }
    }
}

// Función para emitir un listado con montos superiores e inferiores o iguales al valor ingresado
void listarMontosSuperioresInferiores(float valor) {
    printf("Montos Financiados:\n");
    printf("Categoria\tSector\t\tMonto (millones de pesos)\n");
    
    // Montos superiores
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 5; j++) {
            if (montos[i][j] > valor) {
                printf("%d\t\t", i + 1); // Categoría
                printf("%d\t\t", j + 1); // Sector
                printf("%.2f\n", montos[i][j]);
            }
        }
    }
    
    // Montos inferiores o iguales
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 5; j++) {
            if (montos[i][j] <= valor) {
                printf("%d\t\t", i + 1); // Categoría
                printf("%d\t\t", j + 1); // Sector
                printf("%.2f\n", montos[i][j]);
            }
        }
    }
}

int main() {
    int opcion;
    float valor;

    printf("Seleccione una opción:\n");
    printf("1. Monto total financiado para una categoría\n");
    printf("2. Monto total financiado para el sector de Servicios\n");
    printf("3. Listar montos por categoría y sector\n");
    printf("4. Listar montos superiores e inferiores o iguales a un valor\n");
    scanf("%d", &opcion);

    switch (opcion) {
        case 1:
            printf("Ingrese la categoría (1: Micro, 2: Pequeña, 3: Mediana): ");
            int categoria;
            scanf("%d", &categoria);
            if (categoria >= 1 && categoria <= 3) {
                printf("El monto total financiado para la categoría seleccionada es: %.2f millones de pesos.\n", montoTotalPorCategoria(categoria - 1));
            } else {
                printf("Categoría inválida.\n");
            }
            break;

        case 2:
            printf("El monto total financiado para el sector de Servicios es: %.2f millones de pesos.\n", montoTotalServicios());
            break;

        case 3:
            listarMontos();
            break;

        case 4:
            printf("Ingrese un valor: ");
            scanf("%f", &valor);
            listarMontosSuperioresInferiores(valor);
            break;

        default:
            printf("Opción inválida.\n");
            break;
    }

    return 0;
}
