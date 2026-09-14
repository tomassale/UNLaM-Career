#include "valor_cadena.h"

int calcularValor(char *cadena, int ce){
    int numeroProcesado = 0, i = 0;

    while(*(cadena+i) != '\0' && i < ce){
        numeroProcesado *= 10;
        numeroProcesado += *(cadena+i) - '0';
        i++;
    }

    return numeroProcesado;
}
