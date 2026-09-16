#include "main.h"

int main()
{
    char texto[51] = {"Hola   soy tomas"};

    printf("Cadena sin normalizar: %s", texto);

    normalizarCadena(texto, 51);

    printf("\nCadena normalizada: %s", texto);

    return 0;
}
