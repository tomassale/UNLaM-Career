#include "modulo.h"

float modulo(float num){
    float res;

    if(num < 0)
        res = -num;
    else
        res = num;

    return res;
}
