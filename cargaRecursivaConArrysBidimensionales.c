#include <stdio.h>
#define filas 3
#define columnas 2

void carga (int matriz[filas][columnas],int fila,int columna){
    if(fila<filas){
        if(columna<columnas){
            printf("ingrese el valor de la posicion %d %d ",fila,columna);
            scanf("%d",&matriz[fila][columna]);
            carga(matriz,fila,columna+1);
        }else{
            carga(matriz,fila+1,0);
        }
    }

}

void mostrar (int matriz[filas][columnas],int fila, int columna){
    if (fila<filas){
        if(columna<columnas){
            printf("EL valor de %d y %d es: %d\n ",fila,columna,matriz[fila][columna]);
            mostrar(matriz,fila,columna+1);
        }else{
            mostrar(matriz,fila+1,0);
        }
    }
    
}

int main (){
    int matriz[filas][columnas];
    int fila = 0;
    int columna =0;
    int contEdad =0;

    carga(matriz,fila,columna);
    mostrar(matriz,fila,columna);


}