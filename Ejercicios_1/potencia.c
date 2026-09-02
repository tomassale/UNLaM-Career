#include "potencia.h"

int potencia(int num, int pot){
    int i;
    int res = num;

    for(i = 0; i < pot; i++){
        res *= num;
    }

    return res;
}
