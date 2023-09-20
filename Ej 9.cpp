#include <stdio.h>
#include <string.h>
#define A 3
#define B 8
#define C 3

struct tipos{
	
	int tipo_A;
	
	int tipo_B;
	
	int tipo_C;	
};


typedef struct{
	
	char tipo;
	
	char nombre[50];
	
    float precio;
    
}seguros;



typedef struct{
	
  int num_prom;
  
  struct tipos tipos_sector;
  
  int cod;
  
}sectores;



typedef struct{
	
	int sector;
	
}promotores;




void cargaprom (promotores prom[A], sectores sector[B]){
	
	int cod;
	
	int encontrado=0;
	
	for (int i=0; i<A; i++){
	encontrado=0;
	
	while (encontrado==0){
	printf("\nIngrese el codigo de sector donde trabaja el promotor %d\n", i+1);
	printf("\n**30: Moto - 31: Auto - 32: Camioneta**\n");
	printf("**33: Camion - 34: Omnibus de Corta distancia - 35: Omnibus de larga distancia**\n");
	printf("**36: Combis de pasajeros - 37: taxis**");
	printf("\n");
	scanf("%d", &cod);
	
	if (cod>29 && cod<38){
		
		prom[i].sector=cod;
		
		sector[cod-30].cod=cod;
		
		sector[cod-30].num_prom++;
		
		encontrado=1;
		
	}else { 
	printf("\nCodigo fuera de rango.\n");
	}
		
   }	
}
	
	return;
}



void cargaseguros (seguros s[C]){
	
   s[0].tipo='A';  
   s[1].tipo='B';
   s[2].tipo='C';
   
   strcpy(s[0].nombre, "Seguro contra terceros");
   strcpy(s[1].nombre, "Seguro de incendios");
   strcpy(s[2].nombre, "Seguro total");
	
   s[0].precio=3000;
   s[1].precio=4000;
   s[2].precio=2000;
	
}


void cargaventas(promotores prom[A], sectores sector[B], seguros s[C]){
 
 int p=1;
 
 int guarda=0;
 
 char t;
 
 printf("\nIngrese numero de promotor, (entre 1 y 10)\n");
 printf("Finaliza con numero de promotor igual a 0: ");
 scanf("%d", &p);
	
    while (p != 0){
    
	printf("\nIngrese tipo de seguro 'A': Seguro contra terceros, 'B': Seguro de Incendio y 'C': Seguro Total: ");
	scanf(" %c", &t);
	printf("\n");
  
    guarda=prom[p-1].sector;
    
    for (int i=0; i<B; i++) {
       if (guarda==sector[i].cod) {
       	   switch (t) {
        case 'A':
             sector[i].tipos_sector.tipo_A++;
            break;
        case 'B':
             sector[i].tipos_sector.tipo_B++;
            break;
        case 'C':
             sector[i].tipos_sector.tipo_C++;
            break;
        default:
             printf("\nIncorrecto.");
            break;
          }	
	   }
    
   }
   
   printf("\nIngrese numero de promotor, (entre 1 y 10)\n");
   printf("Finaliza con numero de promotor igual a 0: ");
   scanf("%d", &p);
   }
}


void indicar (sectores sector[B], char tipo){
	
 int max=0, codi;	
		
 switch (tipo) {
 	case 'A':
             for (int i=0; i<B; i++){
             	 if (max<sector[i].tipos_sector.tipo_A){
             	 	 max=sector[i].tipos_sector.tipo_A;
             	 	 codi=i;
				  }        	
			 }
            break;
    case 'B':
             for (int i=0; i<B; i++){
             	 if (max<sector[i].tipos_sector.tipo_B){
             	 	 max=sector[i].tipos_sector.tipo_B;
             	 	 codi=i;
				  }        	
			 }
			 
			 
            break;
    case 'C':
             for (int i=0; i<B; i++){
             	 if (max<sector[i].tipos_sector.tipo_C){
             	 	 max=sector[i].tipos_sector.tipo_C;
             	 	 codi=i;
             	 	 
				  }        	
			 }
            break;
    default:
             printf("\nSeguro inexistente.");
            break;
 	
  }
		
 printf("\nEl sector codigo %d, con %d promotores, compra mas, del tipo de seguro %c.\n", sector[codi].cod, sector[codi].num_prom, tipo);	
		
}



main(){
	
	promotores prom[A]={0};
	
	sectores sector[B]={0};
	
	seguros s[C]={0};
	
	int opc=1;
	
	char tipo;

	printf("***CARGA DE PROMOTORES***\n");
	
	cargaprom(prom, sector);
	
	cargaseguros(s);
	
	while (opc != 0){    
	
    	printf("\n/MENU DE OPCIONES/\n");
	    printf("->1.Carga de las ventas\n");
     	printf("->2.Ingresar un tipo de seguro e indicar en que sector se lo vende mas y cuantos promotores tiene ese sector\n");
    	printf("->3.Dar un numero de sector e indicar cual es el seguro que mas se consume\n");
    	printf("->4.Indicar para cada tipo de seguro, el nombre y el importe total de venta\n");
	    printf("->0.Salir\n");
	    printf("\nIngrese opcion:");
	    scanf("%d", &opc);
	    printf("\n");
	    
	    if (opc==1){
		   	
	     printf("\nCARGA DE LAS VENTAS\n");
	     cargaventas(prom, sector, s);
	    	
		}
	    
	    if (opc==2){
	    	
	     printf("\nIngrese un tipo de seguro A': Seguro contra terceros, 'B': Seguro de Incendio y 'C': Seguro Total : ");
		 scanf(" %c", &tipo);	
	    	
	     indicar(sector, tipo);	
	    		
		}
	    
	    
	    
	    
	    
	    
   }
	
}
