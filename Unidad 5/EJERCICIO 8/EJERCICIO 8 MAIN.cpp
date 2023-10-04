#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#define N 3
#include "EJERCICIO A.cpp"
#include "EJERCICIO B.cpp"
#include "EJERCICIO C.cpp"
#include "EJERCICIO D.cpp"
#include "EJERCICIO E.cpp"
int main(){

	Datos Arre[N];
	Puntero Nuevo;
	int i=0,j,DNI,Cont=0,opcion;
	Crear(Arre,i);
	
	do{
		printf("-------------------------------------------------------------------\n");
        printf( "\n   1. Cargar Tutorias.");                                 
        printf( "\n   2. Cargar inscripciones.");    
        printf( "\n   3. Eliminar una inscripcion.");            
        printf( "\n   4. Mostrar una tutoria.");
        printf( "\n   5. Consultar tutoria de cierta persona.");             
		printf( "\n   6. Salir." );                                      
        printf( "\n\n   Introduzca opcion (1-5): \n");                      
        printf("-------------------------------------------------------------------\n");
        scanf( "%d", &opcion );
        /* Inicio del anidamiento */
        switch ( opcion )
        {
            case 1:printf("ACA INICIA EL PUNTO A\n");
				   Carga_Arre(Arre,i);
			       Mostrar_Arre(Arre);
                   break;

            case 2:printf("ACA INICIA EL PUNTO B\n");
           	       Carga_Ins(Arre,1);
				   Mostrar_Ins(Arre);;
                   break;

            case 3: printf("ACA INICIA EL PUNTO C\n");
					printf("Ingrese numero de tutoria de la persona a eliminar\n");
					scanf("%d",&j);
					printf("Ingrese DNI\n");
					scanf("%d",&DNI);
					system("color 04");
					Eliminar(Arre,DNI,j);
					system("color 0f"); 
					printf("ARREGLO CON EL INSCRIPTO ELIMINADO \n");
					Mostrar_Ins(Arre);
					
					break;
					
			case 4:printf("ACA INICIA EL PUNTO D\n");
	               printf("Ingrese numero de tutoria a consultar la cantidad de inscriptos \n");
				   scanf("%d",&j);
				   Nuevo = Arre[j-1].Nodo;
				   Contar(Nuevo,Cont);
				   printf("La tutoria llamada: %s tiene %d inscriptos \n",Arre[j-1].Titulo,Cont);
                   break;

            case 5:printf("ACA INCICIA EL PUNTO E\n");
                   printf("Ingrese DNI de la persona a consultar donde se encuentra \n");
				   scanf("%d",&DNI);
				   while(i<N){
						Nuevo = Arre[i].Nodo;
						Buscar(Arre,i,DNI,Nuevo);
						i++;
				   }
                   break;
         }
         /* Fin del anidamiento */
    } while ( opcion != 5 );	
}
/* LOTE DE PRUEBA
1
1
Lau
2
Lopez
3
Marcos
2
44
1
1
44
2
1
45
2
1
48
3
0
3
2
45
4
3
5
44
*/
