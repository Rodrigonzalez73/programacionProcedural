#include <stdio.h>
#define N 3

struct postulantes {
    char nombre[50];
    char sexo;
    int dni;
    int cod;
    int edad;
};

void carga(struct postulantes pos[N]) {
    int i;
    for (i = 0; i < N; i++) {
        printf("Ingrese el nombre del postulante: ");
        scanf("%s", pos[i].nombre);
        printf("Ingrese la edad: ");
        scanf("%d", &pos[i].edad);
        printf("Ingrese el sexo del postulante (F o M): ");
        scanf(" %c", &pos[i].sexo);
        printf("Ingrese el numero de DNI del postulante: ");
        scanf("%d", &pos[i].dni);
        printf("Ingrese el codigo de localidad 1..19: ");
        scanf("%d", &pos[i].cod);
    }
}

void mujeresMenoresA30(struct postulantes pos[N]){
    int i , cont = 0;
    for (i = 0; i < N; i++) {
        if ((pos[i].sexo == 'M' || pos[i].sexo == 'm') && pos[i].edad <= 30){
            cont++;
        }
    }
    printf("Hay %d mujeres menores a 30 años\n", cont); // Agregamos \n al final
}

void promedioVarones(struct postulantes pos[N])
{
    int i, sum = 0, contadorVarones = 0;
    float promedio; // Cambio a float para la división de punto flotante

    for (i = 0; i < N; i++)
    {
        if ((pos[i].sexo == 'M' || pos[i].sexo == 'm') && pos[i].edad > 0)
        {
            sum += pos[i].edad;
            contadorVarones++; // Incrementa el contador de varones
        }
    }

    if (contadorVarones > 0)
    {
        promedio = (float)sum / contadorVarones; // Conversión de int a float para la división
        printf("La edad promedio de los hombres es %.2f\n", promedio); // %.2f para mostrar 2 decimales
    }
    else
    {
        printf("No se encontraron varones para calcular el promedio.\n");
    }
}


int main (){
    struct postulantes pos[N];
    carga(pos);
    mujeresMenoresA30(pos);
    promedioVarones(pos);
    return 0;
}
