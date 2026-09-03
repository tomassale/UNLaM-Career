/************************************************************************************************************************
Crear una variable entera y un puntero a dicha variable
Asignar el valor 10 a la variable mediante el puntero
Mostrar:
  a) la dirección de la variable
  b) la dirección del puntero
  c) el contenido de la variable
  d) el contenido de la variable accediendo mediante el puntero
  e) el contenido del puntero
************************************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>

int main(){
  int num, *puntero;

  puntero = &num;
  *puntero = 10;
  printf("\nDireccion de variable: %p", &num);
  printf("\nDireccion del puntero: %p", &puntero);
  printf("\nContenido de la variable: %d", num);
  printf("\nContenido mediante puntero: %d", *puntero);
  printf("\nContenido del puntero: %d", puntero);

  return 0;
}
