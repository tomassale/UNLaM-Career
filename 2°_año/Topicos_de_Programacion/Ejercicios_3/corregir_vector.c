#include "corregir_vector.h"

void limpiarVector(char *vec, char *vecCorr, int *med){
    int i = 0, j = 0;

    while(*(vec+i) != '\0'){
        if(*(vec+i) != ' '){
            *(vecCorr+j) = *(vec+i);
            j++;
        }
        i++;
    }
    *(vecCorr+j) = '\0';
    *(med) = j;
}
