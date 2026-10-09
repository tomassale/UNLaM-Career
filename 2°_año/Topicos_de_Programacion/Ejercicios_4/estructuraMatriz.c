#include "estructuraMatriz.h"
#include "utilidades.h"

void* Matriz_crear(int fil, int col, size_t tamElem){
    return calloc(fil * col, tamElem);
}

void Matriz_mostrarInt(void *matriz, int fil, int col){
    int *pm = matriz;
    int i, j;

    printf("\nMatriz: {");
    for(i = 0; i < fil; i++){
        printf("\n");
        for(j = 0; j < col; j++){
            printf("\t%d,", pm[i*col+j]);
        }
        printf("\n");
    }
    printf("}\n");
}

void Matriz_mostrarFloat(void *matriz, int fil, int col){
    float *pm = matriz;
    int i, j;

    printf("\nMatriz: {");
    for(i = 0; i < fil; i++){
        printf("\n");
        for(j = 0; j < col; j++){
            printf("\t%2.2f,", pm[i*col+j]);
        }
        printf("\n");
    }
    printf("}\n");
}

void Matriz_llenarAleatorioFloat(void *matriz, int fil, int col, int min, int max){
    float *pm = matriz;
    int i, j;

    for(i = 0; i < fil; i++){
        for(j = 0; j < col; j++){
            pm[i * col + j] = generarAleatorioFloat(min, max);
        }
    }
}

void Matriz_llenarAleatorioInt(void *matriz, int fil, int col, int min, int max){
    int *pm = matriz;
    int i, j;

    for(i = 0; i < fil; i++){
        for(j = 0; j < col; j++){
            pm[i * col + j] = generarAleatorioInt(min, max);
        }
    }
}

void Matriz_generarIdentidad(void *matriz, int fil, int col){
    int *pm = matriz;
    int i, j;

    for(i = 0; i < fil; i++){
        for(j = 0; j < col; j++){
            pm[i * col + j] = (i == j) ? 1 : 0;
        }
    }
}

void Matriz_generarDiagonal(void *matriz, int fil, int col){
    int *m = matriz;
    int i, j;

    for(i = 0; i < fil; i++){
        for(j = 0; j < col; j++){
            m[i * col + j] = (i == j) ? generarAleatorioInt(1, 10) : 0;
        }
    }
}

void Matriz_generarSimetricaInt(void *matriz, int N, int min, int max){
    int *pm = matriz;
    int i, j;

    for(i = 0; i < N; i++){
        for(j = i; j < N; j++){
            pm[i * N + j] = generarAleatorioInt(min, max);
            pm[j * N + i] = pm[i * N + j];
        }
    }
}

void Matriz_generarSimetricaFloat(void *matriz, int N, int min, int max){
    float *pm = matriz;
    int i, j;

    for(i = 0; i < N; i++){
        for(j = i; j < N; j++){
            pm[i * N + j] = generarAleatorioFloat(min, max);
            pm[j * N + i] = pm[i * N + j];
        }
    }
}

void Matriz_destruir(void *matriz){
    free(matriz);
}
