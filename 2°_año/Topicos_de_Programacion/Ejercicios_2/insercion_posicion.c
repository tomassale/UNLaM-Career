#include "insercion_posicion.h"
#include "ordenamiento.h"

//Corregir uso de subindices, usar aritmetica de punteros
void insercionPosicion(int *vec, int ce, int pos, int num, int *pp){
    int i, aux, temp;
    aux = *(vec+pos);
    *(vec+pos) = num;

    for(i = pos + 1; i < ce; i++){
        temp = *(vec+i);
        *(vec+i) = aux;
        aux = temp;
    }

    ordenarVector(vec, 5);

    *(pp) = aux;
}
