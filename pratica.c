//carga y muestra recursiva

#include <stdio.h>
#define N 5

void cargaRecursiva(int arreglo[N],int i){
    if(i!=N){
        printf("Ingrese el valor de la posicion %d: ",i);
        scanf("%d",&arreglo[i]);
        cargaRecursiva(arreglo,i+1);
    }
}

void muestraRecursiva (int arreglo[N], int i){
    if(i!=N){
        printf("El valor es %d",arreglo[i]);
        muestraRecursiva(arreglo,i+1);
    }
}

int main (){
    int arrreglo[N], i =0;
    cargaRecursiva(arrreglo,i);
    muestraRecursiva(arrreglo,i);
}