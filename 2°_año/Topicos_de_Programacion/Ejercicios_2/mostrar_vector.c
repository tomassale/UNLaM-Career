#include "mostrar_vector.h"
#include <stdio.h>

void mostrarVector(int *vec, int ce){
    int i;

    printf("\nVector: [");
    for(i=0; i < ce; i++){
        printf(" %d", *(vec+i));
    }
    printf("]");
}
