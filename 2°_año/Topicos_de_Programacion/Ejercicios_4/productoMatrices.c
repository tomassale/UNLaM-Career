#include "productoMatrices.h"

void Matriz_producto(int *m1, int *m2, int *matrizRes, int fil, int col, int colRes){
    int i, j, k;
    int acumProd;

    for(i = 0; i < fil; i++){
        for(j = 0; j < colRes; j++){
            acumProd = 0;
            for(k = 0; k < col; k++){
                acumProd += m1[i*col + k] * m2[k*colRes +j];
            }
            matrizRes[i*colRes + j] = acumProd;
        }
    }
}
