/************************************************************************************************************************
En un curso de la maestría en informática los estudiantes deben exponer en forma grupal sus investigaciones de un tema
dado. El curso está formado por 5 grupos. Se pide realizar un programa para sortear el orden de exposición de dichos
grupos. Cada vez que se ejecute el programa deberá mostrar un orden de exposición distinto para cada uno de los 5 grupos.
************************************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void seleccionAleatoria(int[], int, int, int);
void mostrarSeleccion(int[], int);
int buscarPosicion(int[], int, int);

int main(){
  int orden[5] = {0};

  srand(time(NULL));

  seleccionAleatoria(orden, 5, 1, 5);
  mostrarSeleccion(orden, 5);

  return 0;
}

int buscarPosicion(int vec[], int ce, int num){
  int i = 0, pos = -1;

  while(i < ce && pos == -1){
    if(vec[i] == num)
      pos = i;
    else
      i++;
  }

  return pos;
}

void seleccionAleatoria(int orden[], int ce, int min, int max){
  int i, aux, pos;

  for(i = 0; i < ce; i++){
    do{
      aux = (rand() % max) + min;
      pos = buscarPosicion(orden, ce, aux);
    }while(pos != -1);
    orden[i] = aux;
  }
}

void mostrarSeleccion(int vec[], int ce){
  int i;

  printf("\nORDEN DE GRUPOS");
  for(i = 0; i < ce; i++){
    printf("\n\t%d", vec[i]);
  }
}
