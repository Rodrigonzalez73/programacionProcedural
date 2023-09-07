#include <stdio.h>
#define N 5

void carga (int x[N]){
    int i ;
    for(i=0;i<N;i++){
        printf("Ingrese el valor %d del arreglo: ",i+1);
        scanf("%d",&x[i]);
    }

}


void cero (int x[N]){
    int i, cero=0;
    for (i=0;i<N;i++){
        if(x[i] == 0){
            cero++;
        }
    }
    if (cero > 0){
        printf("hubo numeros mayores a cero");
    }
    else{
        printf("no hubo mayores a cero");
    }

}

int main (){
    int x[N];
    carga(x);
    cero(x);
    return 0;
}