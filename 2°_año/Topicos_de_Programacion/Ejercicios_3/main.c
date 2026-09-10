#include "main.h"

int main()
{
    char vector[21] = {"arriba la birra"};
    char vectorCorregido[21];
    int med, resultado, *punteroMed;

    punteroMed = &med;

    limpiarVector(vector, vectorCorregido, punteroMed);
    resultado = esPalindromo(vectorCorregido, med);

    if(resultado)
        printf("\nLa palabra %s es palindromo.", vector);
    else
        printf("\nLa palabra no es palindromo.");

    return 0;
}
