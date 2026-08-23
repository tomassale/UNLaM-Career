#include <stdio.h>
#include <stdlib.h>

#include "main.h"

//Resolver ejercicio
int main(){
    int x = 2;
    float TOL = 0.002;
    float res;

    res = mclauren(x, TOL);
    printf("El resultado de %d y tolerancia %f es: %f\n", x, TOL, res);

    return 0;
}
