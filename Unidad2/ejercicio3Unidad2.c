#include <stdio.h>
#define N 2

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
        printf("Ingrese el apellido del alumno: ");
        scanf("%s",&alu[i].apellido); 
        printf("Ingrese Dni del alumno: ");
        scanf("%d",&alu[i].dni);       
    }
}

void listar (struct alumnos alu[N]){
    int i ;
    for(i=0;i<N;i++){
        printf("Los alumos ingresados son %s %s con dni %d \n",alu[i].nombre,alu[i].apellido,alu[i].dni);
    }

}

void mayoresA40(struct alumnos alu [N]){
    int i , cont=0;
    for (i =0;i<N;i++){
        if(alu[i].dni > 40000000){
            cont++;
        }
    }
    printf("se ingresaron %d alumons con dni mayor a 4000000",cont);    
}

int main (){
   struct alumnos alu[N];
   carga (alu);
   listar(alu);
   mayoresA40(alu);
}