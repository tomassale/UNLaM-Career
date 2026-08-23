#include "mclauren.h"

int potencia(int num, int pot){
    int i;
    int res = num;

    for(i = 0; i < pot; i++){
        res *= num;
    }

    return res;
}

float mclauren(int x, float tol){
    float res = 1;
    float calcTOL;
    int i = 1;

    calcTOL = (float) potencia(x, i) / factorial(i);
    while(calcTOL >= tol){
        res += calcTOL;
        i++;
        calcTOL = (float) potencia(x, i) / factorial(i);
    }

    return res;
}
