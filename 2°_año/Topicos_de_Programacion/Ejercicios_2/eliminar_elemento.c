#include "eliminar_elemento.h"

//1.3 y 1.4
void eliminarElemento(int *vec, int *pp, int posElim){
    *(pp) = *(vec+posElim);
    *(vec+posElim) = 0;
}

//1.5
void eliminarRepetido(int *vec, int ce, int num){
    int i;

    for(i = 0; i < ce; i++)
        if(*(vec+i) == num)
            *(vec+i) = 0;
}
