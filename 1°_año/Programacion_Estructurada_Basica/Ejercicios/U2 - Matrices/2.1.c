// Ingresar una matriz de 3x3 por teclado y un número entero. Realizar el producto de la matriz por la constante

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void ingresoAleatorio(int[][3], int, int, int);
void ingresoMatriz(int[][3], int, int);
void mostrarMatriz(int[][3], int, int);
void multiplicarMatriz(int[][3], int, int, int);


int main(){
    int matriz[3][3] = {{0}};
    int num;

    srand(time(NULL));
    //ingresoAleatorio(matriz, 3, 1, 5);
    ingresoMatriz(matriz, 3, 3);
    mostrarMatriz(matriz, 3, 3);
    
    printf("\nIngrese el numero a multiplicar: ");
    scanf("%d", &num);
    
    multiplicarMatriz(matriz, 3, 3, num);
    mostrarMatriz(matriz, 3, 3);
    return 0;
}

void ingresoAleatorio(int matriz[][3], int ce, int min, int max){
    int i, j;

    for(i = 0; i < ce; i++){
        for(j = 0; j < ce; j++){
            matriz[i][j] = (rand() % max) + min;
        }
    }
}

void ingresoMatriz(int matriz[][3], int cc, int cf){
    int i, j;

    for(i = 0; i < cc; i++){
        for(j = 0; j < cf; j++){
            printf("Ingrese los datos a la matriz (%d - %d): ", i, j);
            scanf("%d", &matriz[j][i]);
        }
    }
}

void mostrarMatriz(int matriz[][3], int cc, int cf){
    int i, j;

    printf("\n\t\tMOSTRAR MATRIZ\n");
    printf("{\n");
    for(i = 0; i < cc; i++){
        for(j = 0; j < cf; j++){
            printf("\t%2d, ", matriz[i][j]);
        }
        printf("\n");
    }
    printf("}\n");
}

void multiplicarMatriz(int matriz[][3], int cc, int cf, int num){
    int i, j;

    for(i = 0; i < cc; i++){
        for(j = 0; j < cf; j++){
            matriz[i][j] *= num;
        }
    }
}