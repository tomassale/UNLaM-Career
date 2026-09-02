#include "mclauren.h"
#include "potencia.h"
#include "factorial.h"

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
