/***********************************************************************************************************
Confeccionar un programa que solicite el ingreso de un número entero positivo de 4 cifras y pueda
calcular e informar la suma de sus dígitos hasta llegar a una sola cifra. Ejemplo: 9929 → 2
***********************************************************************************************************/

#include <stdio.h>

int main(){
    int numero, mil, cien, diez, unidad, suma1, suma2, suma3;

    printf("Ingrese un numero entero de cuatro cifras: ");
    scanf("%d", &numero);

    mil = numero/1000;
    cien = (numero/100) % 10;
    diez = (numero/10) % 10;
    unidad = numero % 10;

    suma1 = mil + cien + diez + unidad;
    suma2 = (suma1/10) + (suma1%10);
    suma3 = (suma2/10) + (suma2%10);

    printf("La suma de las cifras es: %d", suma3);

    return 0;
}
