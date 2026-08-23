/************************************************************************************************************************
 Cargar un vector de enteros con números aleatorios de 3 cifras máximo.
Realizar una función que retorne un puntero al mayor valor del vector
Mostrar el máximo valor mediante el puntero y la posición en la cual se encuentra
************************************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void ingresoAleatorio(int*, int);
int* mayorValor(int*, int);

int main(){
  int *vecInt, *pos;

  srand(time(NULL));

  vecInt = (int*) malloc(sizeof(int)*3);

  if(vecInt == NULL){
    printf("\nNo se reservo espacio de memoria...");
    exit(1);
  }

  ingresoAleatorio(vecInt, 3);
  pos = mayorValor(vecInt, 3);
  printf("\nEl numero %d es el mayor en la posicion %d", *pos, pos-vecInt+1);

  free(vecInt);

  return 0;
}

void ingresoAleatorio(int *vec, int ce){
  int i;

  for(i = 0; i < ce; i++){
    *(vec+i) = (rand() % 900)+ 100;
  }
}

int* mayorValor(int *vec, int ce){
  int i, *pos = vec;

  for(i = 0; i < ce; i++){
    if(*(vec+i) > *pos){
      pos = vec+i;
    }
  }

  return pos;
}
