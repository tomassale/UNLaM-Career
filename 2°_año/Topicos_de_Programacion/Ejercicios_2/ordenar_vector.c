#include "ordenar_vector.h"

void intercambiarPosicion(int *posActual, int *posSiguiente){
    int aux;

    aux = *(posActual);
    *(posActual) = *(posSiguiente);
    *(posSiguiente) = aux;
}

void ordenarVector(int *vec, int ce){
    int i, cota = ce-1;
    int desordenado = 1;

    while(desordenado){
        desordenado = 0;
        for(i = 0; i < cota; i++){
            if(*(vec+i) > *((vec+i)+1)){
                intercambiarPosicion(vec+i, (vec+i)+1);
                desordenado = i;
           }
        }
        cota = desordenado;
    }
}
