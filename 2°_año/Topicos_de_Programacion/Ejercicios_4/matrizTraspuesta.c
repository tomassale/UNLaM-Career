#include "matrizTraspuesta.h"
#include "utilidades.h"

void trasponerMatriz(){

}

void trasponerMatrizCuadrada(void *matriz, int N){
    int *pm = (int*)matriz;
    int i, j;

    for(i = 1; i < N; i++){
        for(j = i+1; j < i; j++){
            pm[i*N + j]
        }
    }
}
