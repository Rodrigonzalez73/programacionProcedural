#include <stdio.h>
#define N 3

struct empleados {
    char nombre[25];
    int edad;
    float sueldo;
};

void carga(struct empleados x[N]) {
    int i;
    for (i = 0; i < N; i++) {
        printf("Ingrese el nombre del empleado: ");
        scanf(" %s", x[i].nombre);
        printf("Ingrese la edad del empleado: ");
        scanf("%d", &x[i].edad);
        printf("Ingrese el sueldo del empleado: ");
        scanf("%f", &x[i].sueldo);
    }
}

void listar(struct empleados x[N], float sueldoLimite, int index) {
    if (index < N) {
        if (x[index].sueldo < sueldoLimite) {
            printf("Nombre: %s, Edad: %d, Sueldo: %.2f\n", x[index].nombre, x[index].edad, x[index].sueldo);
        }
        listar(x, sueldoLimite, index + 1);
    }
}

/*void contarEmpleados (struct empleados x[N]){
    int i,cont45 =0, cont30=0 ;
    for(i=0;i<N;i++){
        if(x[i].edad >45 ){
            cont45 = cont45+1;
        }
        if (x[i].edad == 30){
            cont30 = cont30+1;
        }
    }
    printf("tienen mas de 45: %d\n",cont45);
    printf("Tienen 30 anios: %d",cont30);
}*/

void contarEmpleados (struct empleados x[N],int *mayores45, int *edad30){
    int i ;
    *mayores45 =0;
    *edad30 = 0;

    for (i=0;i<N;i++){
        if(x[i].edad > 45){
            (*mayores45)++;
        }
        if (x[i].edad ==30){
            (*edad30)++;
        }
    }
}

int main() {
    struct empleados x[N];
    float sueldoLimite;
    int mayores45,edad30;
    carga(x);

    printf("Ingrese un sueldo límite: ");
    scanf("%f", &sueldoLimite);

    printf("Empleados con sueldo menor a %.2f:\n", sueldoLimite);
    listar(x, sueldoLimite, 0);

    contarEmpleados(x, &mayores45, &edad30);
    printf("Empleados con mas de 45 años: %d\n ",mayores45);
    printf("Empleados con 30 años: %d\n",edad30);

    return 0;
}
