#include <stdio.h>
#include <stdlib.h>

#include "main.h"

//Resolver ejercicio
int main(){
    float x = 5.2;
    float TOL = 0.002;
    float res;

    if(x > 0){
        res = seno(x, TOL);
        printf("El resultado del seno de %.2f con %.5f de tolerancia es: %.6f\n", x, TOL, res);
    }

    return 0;
}
