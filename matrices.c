#include <stdio.h> /* printf scanf gets puts */
#include <stdlib.h> /* rand, srand*/
#include <time.h> 

#define N 30

int menu()
{
	int d;
	printf("Elija una opci�n: \n");
    printf("1 - cargar \n");
    printf("2 - mostrar \n");
    printf("3 - tres \n");
    printf("0 - salir \n");
    scanf("%d",&d);
    return d;
}

void cargar(int xa[])
{
	int i;
	for (i=0; i<N;i++)
		xa[i]=rand () % 11 + 20;
}

void mostrar(int xa[])
{
	int i;
	for (i=0; i<N;i++)
		printf("%d - ",xa[i]);
}

int main()
{
	srand(time(NULL));
	
	/*Declaraciones*/
	int a[N];
	int op;
	/*Inicializaciones*/
	//cerear(a);
	/*Programa*/
	
	do
	{
		op=menu();
		switch(op)
		{
			case 0: break;
			case 1:{
				cargar(a);
				break;
			} 
			break;
			case 2: {
				mostrar(a);
				break;
			} 
			case 3: break;
			case 99: break;
		}
	}
	while(op!=0);
}