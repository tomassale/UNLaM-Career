#include "vectorDinamico.h"
#include <stdlib.h>
#include <stdio.h>

int* reservaMemoria(int *vec, int ce)
{
    return calloc(ce, sizeof(int));
};

void asignarDatos(int *vec, int ce)
{
    int i;

    for(i = 0; i < ce; i++)
        *(vec+i) = i+1;

};

void ingresoDatos(int *vec, int ce)
{
    int i;

    for(i = 0; i < ce; i++){
        printf("Ingrese dato %d: ", i+1);
        scanf("%d", vec+i);
    }

};

void mostrarVector(int *vec, int ce)
{
    int i;

    printf("\nVector: [ ");
    for(i = 0; i < ce; i++)
        printf("%d, ", *(vec+i));
    printf("]");

};

void liberarMemoria(int *vec)
{
    free(vec);
    printf("\nPunteros liberados");
};
