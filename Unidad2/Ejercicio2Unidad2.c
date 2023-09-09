#include <stdio.h>
#include <string.h>

int main (){
    char frase[100];
    char nuevaFrase[100];
    int i ,len;
    int contadorVocales = 0;

    printf("ingrese un frase: ");
    gets(frase); //sirve para leer las frases

    //a)reemplazar el 2 por un 0 (solo cambiar ese caracter)
    len = strlen(frase);
    for (i=0;i<len;i++){
        if(frase[i]== '2'){
            frase[i]= '0';
        }
    }

    // copiar la palabra programacion a una nueva cadena de caracteres
    char palabraObjetivo[]="programacion";
    strcpy (nuevaFrase,palabraObjetivo);

    //contar las vocales de las frases
    for(i=0;i<len;i++){
        char c = frase[i];
        if (c == 'a' || c == 'e'|| c=='i' || c == 'o'|| c == 'u'||
            c == 'A' || c == 'E'|| c=='I' || c == 'O'|| c == 'U' ){
            contadorVocales++;
            }
    }

    printf("Frase modificada %s \n",frase);
    printf("Palabra copiada: %s\n",nuevaFrase);
    printf("Cantidad de vocales:%d \n",contadorVocales);

    return 0;

}