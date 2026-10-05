#include "matrizIdentidad.h"

bool esIdentidad(void *matriz, int N){
    int *pm = (int*)matriz;
    bool esIdentidad = true;
    int i = 0, j = 0;

    while(esIdentidad && i < N){
        while(esIdentidad && j < N){
            if(i == j && pm[i*N + j] != 1) esIdentidad = false;
            if(i != j && pm[i*N + j] != 0) esIdentidad = false;
            j++;
        }
        i++;
    }

    return esIdentidad;
}
