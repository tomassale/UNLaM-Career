#include "combinatoria.h"
#include "factorial.h"

int combinatoria(int m, int n){

    int resta = m - n;
    int factorialDivisor = factorial(n) * factorial(resta);
    int factorialDividendo = factorial(m);

    int resultado = factorialDividendo / factorialDivisor;

    return resultado;
}
