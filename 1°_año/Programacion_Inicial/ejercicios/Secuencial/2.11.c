/***********************************************************************************************************
Se ingresa un número entero que representa una fecha con formato (ddmmaa). Se pide transformarlo a
un número con formato (aammdd).
***********************************************************************************************************/

#include <stdio.h>

int main(){
    int numero, dias, meses, anios, fechaModificada;

    printf("Ingrese los datos: ");
    scanf("%d", &numero);

    dias = numero / 10000;
    meses = ((numero/100) % 100) * 100;
    anios = numero % 100 * 10000;
    fechaModificada = anios + meses + dias;

    printf("La fecha modificada es: %d", fechaModificada);

    return 0;
}
