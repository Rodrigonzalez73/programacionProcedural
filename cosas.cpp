//Se tienen los sueldos de 60 empleados cobrados en los últimos 12 meses.
//Generar una tabla y guardar esta información, donde las filas representen a los meses.
//Realizar un programa en C, que usando funcione/s para cada item permita: a) Mostrar el sueldo que cobro cada empleado en el mes 7. (genere una función recursiva que reciba la
//fila que contiene los sueldos de ese mes)
#include <stdio.h>

#define E 12
#define M 12


void carga(int datos[M][E],int m,int e){
	if(m==M){
		return;
	}else if(e<E){
		printf("\ningrese el sueldo en el mes %d del empleado %d:",m+1,e+1);
		scanf("%d",&datos[m][e]);
		carga(datos,m,e+1);
	}else{
		carga(datos,m+1,0);
	}
}

void mostrar(int datos[E][M],int m,int e){
	if(m==M){
		return;
	}else if(e<E){
		printf("\nEl sueldo del mes %d del empleado %d fue :%d",m+1,e+1,datos[m][e]);
		mostrar(datos,m,e+1);
	}else{
		mostrar(datos,m+1,0);
	}
}
void mes7(int datos[E],int e){
	if(e==E){
		return;
	}else{
		printf("\nEl sueldo en el mes 7 del empleado %d fue de %d",e+1,datos[e]);
		mes7(datos,e+1);
	}
}
void promedio(int datos[M][E],float &total,int i,int j){
	if(j==E){
		return;
	}else if(i<M){
		total+=datos[i][j];
		promedio(datos,total,i+1,j);
	}else{
		printf("\nel sueldo promedio del empleado %d es de %f",i+1,total/M);
		total=0;
		promedio(datos,total,0,j+1);
	}
}
int main(){
	float total;
	int datos[M][E];
	carga(datos,0,0);
	mostrar(datos,0,0);
	mes7(datos[6],0);
	promedio(datos,total,0,0);
	return 0;
}
