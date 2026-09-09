#include <stdio.h>
#include <stdlib.h>
#include "main.h"

int main(){
    int vec[5] = {1, 7, 16, 7, 84};
    int encontrado, *pp, pos;

    pp = &encontrado;

    if(pp == NULL){
        printf("No se pudo encontrar el puntero...");
        exit(1);
    }

    mostrarVector(vec, 5);
    pos = encontrarPrimerAparicion(vec, 5, 84);
    if(pos != -1){
        eliminarElemento(vec, pp, pos);
        mostrarVector(vec, 5);
        printf("\nElemento eliminado: %d", encontrado);
    }else{
        printf("\nEl numero no existe");
    }

    return 0;
}
