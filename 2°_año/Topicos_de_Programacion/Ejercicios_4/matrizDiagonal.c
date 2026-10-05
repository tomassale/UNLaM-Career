#include "matrizDiagonal.h"

bool esDiagonal(void *matriz, int N){
    int *pm = (int*)matriz;
    bool esDiagonal = true;
    int i = 0, j = 0;

    while(esDiagonal && i < N){
        while(esDiagonal && j < N){
            if(i == j && pm[i*N + j] == 0) esDiagonal = false;
            if(i != j && pm[i*N + j] != 0) esDiagonal = false;
            j++;
        }
        i++;
    }

    return esDiagonal;
}
