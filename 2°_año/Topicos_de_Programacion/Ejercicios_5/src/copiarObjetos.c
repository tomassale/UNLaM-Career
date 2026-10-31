#include "copiarObjetos.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

char* copiaCadena(const char* origen)
{
    char *copia = calloc((strlen(origen) + 1), sizeof(char));

    if(copia == NULL){
        printf("Error al asignar memoria...");
        exit(1);
    }

    strcpy(copia, origen);

    return copia;
}

void* copiaCosas(void* elemento, unsigned tam)
{
    void* copia = malloc(tam);

    if(copia == NULL){
        printf("Error al asignar puntero copia...");
        exit(1);
    }

    memcpy(copia, elemento, tam);

    return copia;
}
