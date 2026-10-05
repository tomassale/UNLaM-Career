#include "sumatoriaDiagonal.h"
#include <stdio.h>

float sumatoriaTriangularSuperior(void *matriz, int N){
    int i, j;
    float *m = (float *)matriz;
    float acumSuma = 0;

    for(i=0; i<N; i++){
        for(j=0; j<N; j++){
            if(j > i) acumSuma += m[i * N + j];
        }
    }
    return acumSuma;
}

float sumatoriaDiagonalSecundaria(void *matriz, int N){
    int i, j;
    float *m = (float *)matriz;
    float acumSuma = 0;

    for(i=0; i<N; i++){
        for(j=0; j<N; j++){
            if((j + i) < N-1) acumSuma += m[i * N + j];
        }
    }
    return acumSuma;
}

float sumatoriaIncluyendoDiagonal(void *matriz, int N){
    int i, j;
    float *m = (float *)matriz;
    float acumSuma = 0;

    for(i=0; i<N; i++){
        for(j=0; j<N; j++){
            if((j + i) <= N-1) acumSuma += m[i * N + j];
        }
    }
    return acumSuma;
}

float sumatoriaTriangularInferior(void *matriz, int N){
    int i, j;
    float *m = (float *)matriz;
    float acumSuma = 0;

    for(i=0; i<N; i++){
        for(j=0; j<N; j++){
            if((j + i) >= N-1) acumSuma += m[i * N + j];
        }
    }
    return acumSuma;
}

void mostrarResultados(float sumatoriaTrianguloSuperior, float sumatoriaTrianguloSuperiorSecundario, float sumatoriaDiagonalSuperiorSecundarioInclusiva, float sumatoriaDebajoDiagonal){
    printf("\n");
    printf("\nSumatoria de triangulo superior: %.2f", sumatoriaTrianguloSuperior);
    printf("\nSumatoria de triangulo superior secundario: %.2f", sumatoriaTrianguloSuperiorSecundario);
    printf("\nSumatoria de diagonal superior secundario (inclusive): %.2f", sumatoriaDiagonalSuperiorSecundarioInclusiva);
    printf("\nSumatoria de triangulo inferior: %.2f", sumatoriaDebajoDiagonal);
}
