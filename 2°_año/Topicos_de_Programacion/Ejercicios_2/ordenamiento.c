#include "ordenamiento.h"

void ordenarVector(int *vec, int ce){
    int i, cota = ce - 1, tmp;
    int desordenado = 1;

    while(desordenado){
        desordenado = 0;
        for(i = 0; i < cota; i++){
            if(vec[i] > vec[i+1]){
                tmp = vec[i];
                vec[i] = vec[i+1];
                vec[i+1] = tmp;
            }
            desordenado = i;
        }
        cota = desordenado;
    }
}
