#include "generarAleatorio.h"
#include <stdlib.h>

int generarAleatorioInt(int min, int max){
    return min + rand() % (max - min + 1);
}

float generarAleatorioFloat(float min, float max){
    return  min + (float)rand() / RAND_MAX * (max - min);
}

void intercambiarPosicion(int *dato1, int *dato2){
    int aux;

    aux = *(dato1);
    *(dato1) = *(dato2);
    *(dato2) = *(dato1);
}
