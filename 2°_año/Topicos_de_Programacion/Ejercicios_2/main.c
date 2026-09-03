#include <stdio.h>
#include <stdlib.h>
#include "main.h"

int main(){
    int vec[5] = {1, 6, 84, 7, 12};
    int numeroPerdido;
    int *pp;

    pp = &numeroPerdido;

    if(pp == NULL){
        printf("Error al reservar puntero...");
        exit(1);
    }

    mostrarVector(vec, 5);
    insercionPosicion(vec, 5, 1, 5, pp);
    mostrarVector(vec, 5);
    printf("\nEl numero perdido fue: %d", numeroPerdido);

    return 0;
}
