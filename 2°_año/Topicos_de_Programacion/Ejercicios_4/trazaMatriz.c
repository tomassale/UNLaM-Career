#include "trazaMatriz.h"
#include <stdio.h>

int Traza_calcularPrincipal(void *matriz, int N){
    int i, j;
    int *pm = (int*)matriz;
    int sumaTraza = 0;

    for(i = 0; i < N; i++)
        for(j = 0; j < N; j++)
            if(i == j)
                sumaTraza += pm[i * N + j];

    return sumaTraza;
}
int Traza_calcularSecundaria(void *matriz, int N){
    int i, j;
    int *pm = (int*)matriz;
    int sumaTraza = 0;

    for(i = 0; i < N; i++)
        for(j = 0; j < N; j++)
            if((i + j) == (N - 1))
                sumaTraza += pm[i * N + j];

    return sumaTraza;
}

void Traza_mostrarResultado(int trazaPrin, int trazaSec){
    printf("\nTraza principal: %d", trazaPrin);
    printf("\nTraza secundaria: %d", trazaSec);
}
