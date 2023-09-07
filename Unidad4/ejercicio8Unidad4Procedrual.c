#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool esPalindromoRecursivo(char *cadena, int inicio, int fin){
    //caso base: si hemos llegado al centro de la cadena es un palindromo
    if (inicio >=fin){
        return true;
    }

    //verificar si los caracteres en los extremos de la cadena son iguales
    if(cadena[inicio] != cadena[fin]){
        return false;
    }

    //llamada recursiva para verificar los caracteres intermedios 
    return esPalindromoRecursivo(cadena,inicio+1,fin-1);

}

bool esPalindromo (char *cadena){
    int longitud = strlen (cadena);
    return esPalindromoRecursivo(cadena,0,longitud-1);
}

int main (){
    char cadena[30];

    printf("Ingrese la palabra a analizar: ");
    scanf("%s",&cadena);

    if (esPalindromo(cadena)){
        printf("'%s'es un palindromo.\n",cadena);
    }else {
        printf("'%s' no es un palindromo.\n",cadena);
    }
    return 0;
}