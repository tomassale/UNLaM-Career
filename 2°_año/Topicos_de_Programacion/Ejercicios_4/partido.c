#include "partido.h"
#include "utilidades.h"
#include <stdio.h>

void Matriz_llenarResultados(int *matriz, int N){
    int i, j;
    int puntaje, complemento;

    for(i = 0; i < N; i++){
        matriz[i*N + i] = 0;
        for(j = i+1; j < N; j++){
            puntaje = generarAleatorioIntExcepcion(0, 6, 5);
            switch(puntaje){
                case 0: complemento = 6; break;
                case 1: complemento = 4; break;
                case 4: complemento = 1; break;
                case 6: complemento = 0; break;
                default: complemento = puntaje; break;
            }
            matriz[i*N + j] = puntaje;
            matriz[j*N + i] = complemento;
        }
    }
}

void Matriz_mostrarTabla(int *matriz, int N){
    int i, j;

    printf("Matriz Partido: {\n");
    for(i = 0; i < N; i++){
        for(j = 0; j < N; j++){
            printf("\t%d,", matriz[i*N + j]);
        }
        printf("\n");
    }
    printf("}");
}

int Matriz_verificarCreacion(int *matriz, int N){
    int i = 0, j = 0;
    int puntaje, complemento;
    int res = 1;

    while(i < N-1 && res == 1){
        j = i+1;
        while(j < N && res == 1){
            puntaje = matriz[i*N + j];
            complemento = matriz[j*N + i];
            switch(puntaje){
                case 0: if(complemento != 6) res = 0; break;
                case 1: if(complemento != 4) res = 0; break;
                case 2: if(complemento != 2) res = 0; break;
                case 3: if(complemento != 3) res = 0; break;
                case 4: if(complemento != 1) res = 0; break;
                case 6: if(complemento != 0) res = 0; break;
                default: res = 0;
            }
            j++;
        }
        i++;
    }

    return res;
}

void Matriz_mostrarResultado(int *matriz, int *vec, int N){
    int i, j;

    printf("\nPUNTAJE: ");
    for(i = 0; i < N; i++){
        for(j = 0; j < N; j++){
            if(i != j)
                vec[i] += matriz[i*N + j];
        }
        printf("\nEquipo %d: %d\t", i+1, vec[i]);
    }
}
