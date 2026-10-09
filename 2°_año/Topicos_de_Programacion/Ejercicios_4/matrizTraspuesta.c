#include "matrizTraspuesta.h"
#include "utilidades.h"
#include "estructuraMatriz.h"

void* trasponerMatriz(void *matriz, int fil, int col){
    int *pma = Matriz_crear(col, fil, sizeof(int));
    int *pm = (int*)matriz;
    int i, j;

    if(pm == NULL){
        printf("Error al asignar el puntero...");
        exit(1);
    }

    for(i = 0; i < fil; i++){
        for(j = 0; j < col; j++){
             pma[j*fil+i] = pm[i*col+j];
        }
    }

    return pma;
}

void trasponerMatrizCuadrada(void *matriz, int N){
    int *pm = (int*)matriz;
    int i, j;

    for(i = 0; i < N; i++){
        for(j = i+1; j < N; j++){
            intercambiarPosicion(&pm[i*N+j], &pm[j*N+i]);
        }
    }
}
