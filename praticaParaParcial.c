#include <stdio.h>
#define N 2

struct empleados {
    char nombre[25];
    int edad;
    float sueldo;
};

void carga(struct empleados x[N]) {
    int i;
    for (i = 0; i < N; i++) {
        printf("Ingrese el nombre del empleado: ");
        scanf("%s", x[i].nombre);
        printf("Ingrese edad del empleado: ");
        scanf("%d", &x[i].edad);
        printf("Ingrese el sueldo del empleado: ");
        scanf("%f", &x[i].sueldo);
    }
}

void listarRecursiva(struct empleados x[N], int i) {
    if (i != N) {
        if (x[i].sueldo > 150000) {
            printf("El empleado: %s con la edad %d tiene un sueldo de %f\n", x[i].nombre, x[i].edad, x[i].sueldo);
        }
        listarRecursiva(x, i + 1);
    }
}

int empleadoEdad(struct empleados x[N], int *edadABuscar) {
    int i;
    int contMenor = 0;

    for (i = 0; i < N; i++) {
        if (x[i].edad < *edadABuscar) {
            contMenor++;
        }
    }
    
    return contMenor;
}

int main() {
    struct empleados x[N];
    int i = 0;
    int contEdad = 0;
    int edadABuscar;

    carga(x);
    listarRecursiva(x, i);

    printf("Ingrese edad a buscar: ");
    scanf("%d", &edadABuscar);

    contEdad = empleadoEdad(x, &edadABuscar);
    printf("Empleados con edad menor a %d: %d\n", edadABuscar, contEdad);

    return 0;
}
