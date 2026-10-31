#include <stdio.h>
#include <stdlib.h>
#include "main.h"

int main()
{
    char texto[20] = "Hola, mundo!";

    printf("Texto original: %s\n", texto);

    mi_memmove(texto, texto + 6, 6);

    printf("Texto modificado: %s\n", texto);

    return 0;
}
