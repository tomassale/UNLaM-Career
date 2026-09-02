#include "seno.h"
#include "factorial.h"
#include "modulo.h"

float potenciaFloat(float num, int pot){
    int i;
    float res = 1;

    for(i = 0; i < pot; i++)
        res *= num;

    return res;
}

float seno(float x, float tol){
    float res = 0, calcTol;
    int signo = 1, i = 1;

    calcTol = potenciaFloat(x, i)/ (float)factorial(i);
    while(modulo(calcTol) > tol){
        res += signo * calcTol;
        signo = -signo;
        i += 2;
        calcTol =  potenciaFloat(x, i) / (float)factorial(i);
    }

    return res;
}
