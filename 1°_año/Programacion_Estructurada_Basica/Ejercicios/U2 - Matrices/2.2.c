
/************************************************************************************************************************
Ingresar una matriz de 5x4 por teclado. Realizar una función que genere un vector con la suma por fila de
dicha matriz y otra función que calcule la suma por columna en otro vector
************************************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void ingresoAleatorio(int[][4], int, int, int, int);
void ingresoMatriz(int[][4], int, int);
void sumaFilas(int[][4], int[], int, int);
void sumaColumnas(int[][4], int[], int, int);
void mostrarListado(int[][4], int, int);
void mostrarVectores(int[], int[]);


int main(){
    int matriz[5][4] = {{0}};
    int sumaFila[5] = {0};
    int sumaColumna[4] = {0};
    
    //ingresoAleatorio(matriz, 5, 4, 1, 10);
    ingresoMatriz(matriz, 5, 4);
    sumaFilas(matriz, sumaFila, 5, 4);
    sumaColumnas(matriz, sumaColumna, 5, 4);
    mostrarListado(matriz, 5, 4);
    mostrarVectores(sumaFila, sumaColumna);

    return 0;
}

void ingresoAleatorio(int matriz[][4], int cc, int cf, int min, int max){
    int i, j;

    for(i = 0; i < cc; i++){
        for(j = 0; j < cf; j++){
            matriz[j][i] = (rand() % max) + min;
        }
    }
}

void ingresoMatriz(int matriz[][4], int cc, int cf){
    int i, j;

    for(i = 0; i < cc; i++){
        for(j = 0; j < cf; j++){
            printf("Ingrese el numero de la matriz (%d - %d): ", i, j);
            scanf("%d", &matriz[j][i]);
        }
    }
}

void sumaFilas(int matriz[][4], int vec[], int cc, int cf){
    int i, j;
    int suma = 0;

    for(i = 0; i < cc; i++){
        suma = 0;
        for(j = 0; j < cf; j++){
            suma += matriz[j][i];
        }
        vec[i] = suma;
    }
}

void sumaColumnas(int matriz[][4], int vec[], int cc, int cf){
    int i, j;
    int suma = 0;

    for(i = 0; i < cf; i++){
        suma = 0;
        for(j = 0; j < cc; j++){
            suma += matriz[i][j];
        }
        vec[i] = suma;
    }
}

void mostrarVectores(int sumaF[], int sumaC[]){
    int i;

    printf("\nSuma Filas: [");
    for(i = 0; i < 5; i++){
        printf("\n\t%d,", sumaF[i]);
    }
    printf("\n]\n");

    printf("Suma Columna: [");
    for(i = 0; i < 4; i++){
        printf("%d, ", sumaC[i]);
    }
    printf("]\n");
}

void mostrarListado(int matriz[][4], int cc, int cf){
    int i, j;

    printf("\t\tMOSTRAR MATRIZ\n");
    printf("{\n");
    for(i = 0; i < cc; i++){
        printf("\t");
        for(j = 0; j < cf; j++){
            printf("%d, ", matriz[j][i]);
        }
        printf("\n");
    }
    printf("}");
}