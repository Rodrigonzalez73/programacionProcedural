#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
void Contar(Puntero Lista, int &Cont){
    if(Lista != NULL){
        Cont++;
        Contar(Lista->siguiente, Cont);
    }
}
