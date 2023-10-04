#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

void Eliminar(Datos Arre[N], int DNI, int j){
	Puntero Anterior = NULL; //ya que al principio no tenemos un nodo anterior
	Puntero Actual = Arre[j-1].Nodo; //se inicia con los datos de los nodos
	
	while(Actual !=NULL){ //recorre hasta que llegue al final de la lista o sea NULL
		if(Actual->DNI == DNI){ //Verifica si los datos coiciden con el que quiero eliminar
			if(Anterior == NULL){ //verifica si el nodo actual es el primero de la lista
				Arre[j-1].Nodo = Actual->siguiente; //actualiza el nodo a eliminar al siguiente
			}
			else{ //si no es el primero
				Anterior->siguiente = Actual->siguiente; //al anterior le asignamos el actual (es decir muevo uno a la izquierda)
			}
			free(Actual);
			return;
		}
		Anterior = Actual;
		Actual = Actual->siguiente;
	}
}
