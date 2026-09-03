#include "insercionPos.h"

void insercionPosicion(int *vec, int ce, int pos, int num, int *pp){
    int i, aux;

    vec[pos] = num;
    for(i = pos; i < ce; i++){
        aux = vec[i+1];
        vec[i+1] = vec[i];
    }

    *(pp) = aux;
}
