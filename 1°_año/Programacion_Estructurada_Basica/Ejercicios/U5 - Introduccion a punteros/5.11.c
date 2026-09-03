/************************************************************************************************************************
 Se debe realizar un programa para ingresar los DNI de los asistentes a un evento. Se cargan todos los DNI hasta que se
recibe un DNI igual 0. Al finalizar mostrar el listado de todos los DNI ingresados. Los datos deben almacenarse en un
vector en memoria dinámica al no saber la cantidad comenzar con un vector de 5 elementos y si es necesario y el vector
se llena ir aumentando la capacidad del vector de 5 en 5.
************************************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>


int main(){
  int *vec, capacidad = 5;
  int ingresos, dni, medida, i = 0;

  vec = (int*)malloc(5 * sizeof(int));

  if(vec == NULL){
    printf("Error al reservar memoria...");
    exit(1);
  }

  printf("Ingrese el dni [0 para finalizar] (%d de %d): ", i+1, capacidad);
  scanf("%d", &dni);

  while(dni != 0){
    vec[i] = dni;
    i++;
    if(capacidad == i){
        capacidad += 5;
        vec = (int*)realloc(vec, capacidad * sizeof(int));
        printf("Vector expandido\n");
    }

    if(vec == NULL){
      printf("Error al reservar memoria...");
      exit(1);
    }
    printf("Ingrese el dni [0 para finalizar] (%d de %d): ", i+1, capacidad);
    scanf("%d", &dni);
  };

  free(vec);
  return 0;
}
