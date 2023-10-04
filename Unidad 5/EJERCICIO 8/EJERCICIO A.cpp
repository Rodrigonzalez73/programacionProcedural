#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

struct Nodo{
	int DNI;
	int Num_T;
	struct Nodo *siguiente;
};
typedef struct Nodo * Puntero;
typedef struct{
	char Titulo[10];
	Puntero Nodo;
}Datos;

void Crear(Datos Arre[N],int i){
	if(i<N){
		Arre[i].Nodo = NULL;
		Crear(Arre,i+1);
	}
}
void Carga_Arre(Datos Arre[N],int i){
	int T;
	if(i<N){
		printf("Ingrese numero de tutoria entre 1 y %d \n",N);
		scanf("%d",&T);
		if((T<=N)&&(T>0)){
			printf("Ingrese titulo de la tutoria %d\n",T);
			fflush(stdin);
			gets(Arre[T-1].Titulo);
			Carga_Arre(Arre,i+1);
		}
		else if((T<1)||(T>N)){
		printf("El numero ingresado es incorrecto\n");
		Carga_Arre(Arre,i);
		}				
	}
	else{
		return;
	}
}

void Mostrar_Arre(Datos Arre[N]){
	for(int i=0;i<N;i++){
		printf("TUTORIA: %d \n NOMBRE: %s\n",i+1,Arre[i].Titulo);
	}
}
