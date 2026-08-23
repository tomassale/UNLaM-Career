/************************************************************************************************************************
Hacer un programa que cargue un vector de 10 enteros y lo muestre usando una función para cargar y otra
mostrar sin utilizar subíndices.
************************************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>

void cargarVector(int*, int);
void mostrarVector(int*, int);

int main(){
  int *vecInt, cant;

  printf("Ingrese el tamanio del vector: ");
  scanf("%d", &cant);

  vecInt = (int*)calloc(cant,sizeof(int));

  if(vecInt == NULL){
    printf("\nError no se reservo memoria...");
    exit(1);
  }

  mostrarVector(vecInt, cant);
  cargarVector(vecInt, cant);
  mostrarVector(vecInt, cant);

  free(vecInt);

  return 0;
}

void cargarVector(int *vec, int ce){
  int i;

  for(i = 0; i < ce; i++){
    printf("Ingrese el numero (%d de %d): ", i+1, ce);
    scanf("%d", vec+i);
  }
}

void mostrarVector(int *vec, int ce){
  int i;

  for(i = 0; i < ce; i++){
    printf("Numero %d: %d\n", i+1, *(vec+i));
  }
}
