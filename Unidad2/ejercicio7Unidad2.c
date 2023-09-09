#include <stdio.h>
#define filas 5
#define columnas 4

void cargaArreglo (int x[5][4]){
    int i ,j;
    for (i=0;i<filas;i++){
        for(j=0;j<columnas;j++){
            printf("fila %d, columna %d",i+1,j+1);
            scanf("%d",x[i][j]);
        }
    }
}

int main (){
    int arreglo [filas][columnas];
    cargaArreglo(arreglo);
}