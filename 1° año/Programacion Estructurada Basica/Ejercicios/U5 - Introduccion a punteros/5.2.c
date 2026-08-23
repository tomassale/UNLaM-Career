/************************************************************************************************************************
Definir dos números enteros y dos punteros a dichos números. Accediendo mediante los punteros sumar
ambos números y mostrar el resultado por pantalla.
************************************************************************************************************************/

#include <stdio.h>

int main(){
  int num1, num2, *p1, *p2, suma;

  num1 = 5;
  num2 = 10;

  p1 = &num1;
  p2 = &num2;

  suma = *p1 + *p2;

  printf("La suma de %d y %d da: %d", *p1, *p2, suma);

  return 0;
}
