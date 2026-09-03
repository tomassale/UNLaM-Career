#include "insercion_posicion.h"

void insercionPosicion(int *vec, int ce, int pos, int num, int *pp){
    int i, aux, temp;
    aux = vec[pos];
    vec[pos] = num;

    for(i = pos + 1; i < ce; i++){
        temp = vec[i];   /* Guarda el valor actual antes de sobrescribirlo */
        vec[i] = aux;    /* Inserta el valor desplazado anterior */
        aux = temp;      /* El valor guardado pasa a ser el próximo a mover */
    }

    *(pp) = aux;         /* El último elemento desplazado queda en pp */
}
