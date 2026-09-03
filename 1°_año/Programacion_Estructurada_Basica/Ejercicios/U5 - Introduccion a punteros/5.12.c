/************************************************************************************************************************
Crear una función que defina en memoria dinámica un vector de 10 elementos cargados de forma aleatoria con números de
2 cifras, la función debe mostrar los datos generados en forma ordenada de mayor a menor. Desde el main invocar la
función 5 veces para visualizar 5 vectores distintos.
************************************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void cargaAleatoria(int);
void ordenarVector(int*, int);
int numeroAleatorio();


int main(){
    int i = 0;
    srand(time(NULL));

    for(i = 0; i < 5; i++){
      printf("\nVector %d\n", i+1);
      cargaAleatoria(10);
    }

    return 0;
}

void cargaAleatoria(int ce){
  int i;
  int *vec;

  vec = (int*)malloc(ce * sizeof(int));

  if(vec == NULL){
    printf("Error al reservar memoria...");
    exit(1);
  }

  for(i = 0; i < ce; i++)
    vec[i] = numeroAleatorio();

  ordenarVector(vec, ce);

  for(i = 0; i < ce; i++)
    printf("\nDato de vector (%d de %d): %d", i+1, ce, vec[i]);
}

void ordenarVector(int *vec, int ce){
    int i, desordenado = 1, aux, cota = ce - 1;

    while(desordenado){
        desordenado = 0;
        for(i = 0; i < cota; i++){
            if(vec[i] > vec[i+1]){
                aux = vec[i];
                vec[i] = vec[i+1];
                vec[i+1] = aux;
                desordenado = i;
            }
        }
        cota = desordenado;
    }
}

int numeroAleatorio(){
    int i, num;
    num = (rand() % 90) + 10;

    return num;
}
