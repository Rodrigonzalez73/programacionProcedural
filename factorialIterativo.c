#include <stdio.h>

#define filas 3
#define columnas 4

void carga (int matriz [filas][columnas],int i, int j){
    if(i<filas){
        if (j<columnas){
            scanf("%d",&matriz[i][j]);
            carga(matriz,i,j+1);
        } else {
            carga(matriz,i+1,j=0);
        }
    }
    else{
        return;
    }
}


int main (){

    int i,j,matriz [filas][columnas];

    printf("Ingrese los elementos de la matriz %d %d: \n", filas, columnas);
    carga(matriz,0,0);

    //Mostrar la matriz cargada

    printf("Matriz cargada:\n");
    for(i=0;i<filas;i++){
        for(j=0;j<columnas;j++){
            printf("%d",matriz[i][j]);
        }
        printf("\n");
    }
    return 0;
    }