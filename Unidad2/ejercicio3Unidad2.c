#include <stdio.h>
#define N 10

struct alumnos
{
    char nombre[20];
    char apellido[20];
    int  dni ;
};

void carga (struct alumnos alu[N]){
    int i ;
    for(i=0;i<N;i++){
        printf("Ingrese nombre del alumno: ");
        scanf("%s",&alu[i].nombre);
    }
}

int main (){
   struct alumnos alu[N];

   carga (alu);
}