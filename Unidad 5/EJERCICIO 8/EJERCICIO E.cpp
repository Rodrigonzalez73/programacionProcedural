#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

void Buscar(Datos Arre[N], int i,int DNI,Puntero Nuevo){
	if(Nuevo!=NULL){
		if(Nuevo->DNI == DNI){
			printf("El DNI %d esta inscripto en el tutorial %d llamada %s\n",DNI,i+1,Arre[i].Titulo);
		}
		Buscar(Arre,i,DNI,Nuevo->siguiente);
	}
	else if(Nuevo==NULL){
		return;
	}
	
}
