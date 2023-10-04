#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

void Carga_Ins(Datos Arre[N],int i){
	Puntero Nuevo;
	int Num, Num_T;
	if(i!=0){
	Nuevo = (Puntero)malloc(sizeof(struct Nodo));
	printf("ingrese DNI a cargar\n");
	scanf("%d",&Nuevo->DNI);
	printf("Ingrese numero de tutoria a la cual quiere asistir de 1 a %d \n",N);
	scanf("%d",&Num_T);
	Nuevo->Num_T = Num_T;
	Nuevo->siguiente =Arre[Num_T-1].Nodo;
	Arre[Num_T-1].Nodo = Nuevo;
	printf("Desea ingresar mas datos 1_Si o 0_No\n");
	scanf("%d",&Num);
		switch(Num){
			case 1: Carga_Ins(Arre,i);
					break;
			case 0: return;
					break;
		}
	}
}
void Mostrar_Ins(Datos Arre[N]){

	for(int i=0;i<N;i++){
		printf("Para la tutoria: %d llamada: %s los inscriptos son:\n",i+1,Arre[i].Titulo);
		Puntero Nuevo = Arre[i].Nodo;
		while(Nuevo != NULL){
			printf("DNI: %d\n",Nuevo->DNI);
			Nuevo = Nuevo->siguiente;
		}
	}
}
