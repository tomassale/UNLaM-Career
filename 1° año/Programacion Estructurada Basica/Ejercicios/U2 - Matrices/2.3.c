/************************************************************************************************************************
Cargar de forma aleatoria una matriz de 5 x 8 con números de 2 cifras. Determinar el máximo valor almacenado en 
la matriz indicando cuantas veces se repite y en que posiciones.
************************************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void cargaAleatoria(int[][8], int, int, int, int);
int valorMaximo(int[][8], int, int);
void mostrarMaximo(int[][8], int, int, int);
void mostrarMatriz(int[][8], int, int);

int main(){
    int matriz[5][8] = {{0}};
    int maximo;

    srand(time(NULL));
    cargaAleatoria(matriz, 5, 8, 10, 99);
    maximo = valorMaximo(matriz, 5, 8);
    mostrarMatriz(matriz, 5, 8);
    mostrarMaximo(matriz, 5, 8, maximo);

    return 0;
}

void cargaAleatoria(int matriz[][8], int cc, int cf, int min, int max){
    int i, j;

    for(i = 0; i < cc; i++){
        for(j = 0; j < cf; j++){
            matriz[j][i] = (rand() % max) + min;
        }
    }
}

int valorMaximo(int matriz[][8], int cc, int cf){
    int i, j, max = matriz[0][0];

    for(i = 0; i < cc; i++){
        for(j = 0; j < cf; j++){
            if(matriz[j][i] > max)
                max = matriz[j][i];
        }
    }

    return max;
}

void mostrarMaximo(int matriz[][8], int cc, int cf, int max){
    int i, j;

    for(i = 0; i < cc; i++){
        for(j = 0; j < cc; j++){
            if(matriz[j][i] == max)
                printf("\nEl maximo (%d) esta en la posicion %d-%d\n", max, j+1, i+1);
        }
    }
}

void mostrarMatriz(int matriz[][8], int cc, int cf){
    int i, j;

    printf("\n\t\tMOSTRAR MATRIZ\n{\n");
    for(i = 0; i < cc; i++){
        printf("\t");
        for(j = 0; j < cf; j++){
            printf("%d, ", matriz[j][i]);
        }
        printf("\n");
    }
    printf("}");
}