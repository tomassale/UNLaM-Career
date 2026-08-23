#include "factorial.h"

int factorial(int n){
    int res = 1;
    int i = 1;

    for(i; i <= n; i++){
        res *= i;
    }

    return res;
}
