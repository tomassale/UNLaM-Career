#include "vectorDatos.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

tDatos *reservarMemoriaDato(int ce)
{
    return calloc(ce, sizeof(tDatos));
}

void asignarValoresDato(tDatos *self, int ce)
{
    int i;

    for(i=0; i < ce; i++){
        printf("Ingrese el texto: ");
        scanf("%s", (self+i)->texto);

        printf("Ingrese el numero: ");
        scanf("%d", &((self+i)->numT));

        printf("Ingrese el flotante: ");
        scanf("%f", &((self+i)->numF));

        printf("Ingrese la letra: ");
        scanf(" %c", &((self+i)->letra));
    }
}

void mostrarValoresDato(tDatos *self, int ce)
{
    int i;

    for(i=0; i < ce; i++){
        printf("\nDato %d: ", i+1);
        printf("\n%s", (self+i)->texto);
        printf("\n%d", (self+i)->numT);
        printf("\n%.2f", (self+i)->numF);
        printf("\n%c", (self+i)->letra);
        printf("\n");
    }
}

void liberarMemoriaDato(tDatos *vector)
{
    free(vector);
}
