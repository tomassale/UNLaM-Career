#include "factorial.h"

double factorial(int n){
    double res = 1;
    int i;

    for(i=2; i <= n; i++)
        res *= i;

    return res;
}
