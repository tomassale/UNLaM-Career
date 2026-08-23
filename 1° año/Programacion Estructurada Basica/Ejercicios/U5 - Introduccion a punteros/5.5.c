/************************************************************************************************************************
Al programa anterior agregarle una función que reciba la dirección de inicio del vector y un número a buscar y retorne
un puntero al dato encontrado o NULL sino lo encuentra. En el main agregar un proceso de búsqueda que se repita hasta
ingresar un número negativo o cero a buscar. Si se lo encontró se debe indicar en que posición del vector estaba
(calcular dicha posición utilizando la dirección retornada)
************************************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>

void cargarVector(int*, int);
void mostrarVector(int*, int);
int* buscarDato(int*, int, int);

int main(){
  int *vecInt, cant, num, *pos;

  printf("Ingrese el tamanio del vector: ");
  scanf("%d", &cant);

  vecInt = (int*)calloc(cant,sizeof(int));

  if(vecInt == NULL){
    printf("\nError no se reservo memoria...");
    exit(1);
  }

  cargarVector(vecInt, cant);

  do{
    printf("Ingrese un numero a buscar: ");
    scanf("%d", &num);
    pos = buscarDato(vecInt, num, cant);
    if(pos == NULL ){
        printf("Dato no encontrado\n");
    }else{
        printf("El dato esta en la direccion: %d\n", pos-vecInt+1);
    }
  }while(num > 0);

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

int* buscarDato(int *vec, int num, int ce){
  int i = 0, *pos = NULL;

  while(i < ce && pos == NULL){
    if(num == *(vec+i))
      pos = (vec+i);
    else
      i++;
  }

  return pos;
}
