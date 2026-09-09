#include "encontrar_elemento.h"

int encontrarPrimerAparicion(int *vec, int ce, int num){
    int pos = -1;
    int i = 0;

    while(pos == -1 && i < ce){
        if(num == *(vec+i)){
            pos = i;
        }else{
            i++;
        }
    }

    return pos;
}
