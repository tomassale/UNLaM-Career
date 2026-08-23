/***********************************************************************************************************
Confeccionar un programa que pueda ingresar 2 números enteros y calcule e informe con mensajes
aclaratorios la suma, el producto, el cociente y el resto.
***********************************************************************************************************/

#include <stdio.h>

int main(){
  int num1, num2, suma, producto, resto;
  float cociente;

  printf("Ingrese el numero 1: ");
  scanf(" %d", &num1);
  printf("Ingrese el numero 2: ");
  scanf(" %d", &num2);

  suma = num1 + num2;
  producto = num1 * num2;
  cociente = (float) num1 / num2;
  resto = num1 % num2;

  printf("\nLa suma es %d\n", suma);
  printf("El producto es %d\n", producto);
  printf("El cociente es %.2f\n", cociente);
  printf("El resto es %d\n", resto);

  return 0;
}