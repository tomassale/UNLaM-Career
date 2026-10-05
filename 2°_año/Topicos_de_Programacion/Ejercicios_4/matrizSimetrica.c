#include "matrizSimetrica.h"

bool esSimetrica(void *matriz, int N){
    int *pm = (int*)matriz;
    bool esSimetrica = true;
    int i = 0, j = 0;

    while(i < N && esSimetrica){
        while(j < N && esSimetrica){
            if(pm[i*N + j] != pm[j*N + i])
                esSimetrica = false;
            j++;
        }
        i++;
    }

    return esSimetrica;
}
