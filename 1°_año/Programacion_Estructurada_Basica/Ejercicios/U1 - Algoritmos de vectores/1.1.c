/************************************************************************************************************************
Cargar de forma aleatoria un vector de 20 elementos con números de 3 cifras.
  a. Mostrar el menor valor e indicar cuantas veces se repite
  b. Mostrar el mayor valor e indicar en que posición/posiciones se encuentra
************************************************************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void menor(int[]);
void mayor(int[]);
void cargaAleatoria(int[], int);

int main(){
  int vec[20] = {0};

  srand(time(NULL));

  cargaAleatoria(vec, 1000);
  menor(vec);
  mayor(vec);

  return 0;
}

void menor(int vec[]){
  int i, menor = vec[0], cont = 0;

  for(i = 0; i < 20; i++){
    if(menor > vec[i]) menor = vec[i];
  }

  for(i = 0; i < 20; i++){
    if(menor == vec[i]) cont++;
  }

  printf("\nEl valor mas chico es %d y aparece %d veces", menor, cont);
}

void mayor(int vec[]){
  int i, mayor = vec[0];

  for(i = 0; i < 20; i++){
    if(mayor < vec[i]) mayor = vec[i];
  }

  if(mayor != 0) printf("\nEl mayor es %d", mayor);

  for(i = 0; i < 20; i++){
    if(mayor == vec[i]) printf("\nEncontrado en: %d", i);
  }
}

void cargaAleatoria(int vec[], int max){
  int i;

  for(i=0; i<20; i++){
    vec[i] = rand() % max;
  }
}