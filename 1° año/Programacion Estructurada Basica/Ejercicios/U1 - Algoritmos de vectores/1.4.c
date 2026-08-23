/************************************************************************************************************************
Se ingresan DNI y nota de un parcial de los alumnos de un curso. El ingreso de datos finaliza con un DNI negativo.
Se sabe que como máximo pueden presentarse a rendir 60 alumnos. Tenga en cuenta que no pueden existir 2 o más alumnos
con el mismo DNI.
Mostrar el Listado de alumnos con su correspondiente DNI y la nota obtenida (en forma de listado), ordenado de mayor
a menor por nota.
************************************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int ingresoAleatorio(int[], int, int, int);
int ingresoDatos(int[], int[]);
int ingresoValidado(int, int);
int buscarDuplicado(int[], int, int);
void ordenarListado(int[], int[], int);
void mostrarListado(int[], int[], int);

int main(){
  int dni[60] = {0};
  int nota[60] = {0};
  int ingresos = 0;

  //ingresoAleatorio(dni, 60, 1, 99999999);
  //ingresoAleatorio(nota, 60, 1, 10);
  //ingresos = 60;
  ingresos = ingresoDatos(dni, nota);

  if(ingresos != 0){
    ordenarListado(dni, nota, ingresos);
    mostrarListado(dni, nota, ingresos);
  }else{
    printf("\nNo hubieron ingresos");
  }

  return 0;
}

int ingresoAleatorio(int vec[], int ce, int min, int max){
  int i;

  for(i=0; i < ce; i++){
    vec[i] = rand() % max + min;
  }

  return i;
}

int ingresoDatos(int dnis[], int notas[]){
  int dni, nota, pos, i = 0;

  printf("Ingrese el dni (mayor a 99999999)(dni negativo para finalizar): ");
  dni = ingresoValidado(-99999999, 99999999);
  while(i < 60 && dni > 0){

    printf("Ingrese la nota del alumno (1 a 10): ");
    nota = ingresoValidado(1, 10);

    dnis[i] = dni;
    notas[i] = nota;

    do{
      printf("Ingrese el dni (mayor a 99999999)(dni negativo para finalizar): ");
      dni = ingresoValidado(-99999999, 99999999);
      pos = buscarDuplicado(dnis, i, dni);
      if(pos == -1) printf("\nIngreso duplicado");
    }while(pos != -1);
  }

  return i;
}

int ingresoValidado(int min, int max){
  int num;

  do{
    scanf("%d", &num);
  }while(num < min || num > max);

  return num;
}

int buscarDuplicado(int vec[], int ce, int num){
  int i, pos = -1;

  while(i < ce && pos == -1){
    if(vec[i] == num)
      pos = i;
    else
      i++;
  }

  return i;
}

void ordenarListado(int dnis[], int notas[], int ce){
  int i, aux, cota = ce-1;
  int desordenado = 1;

  while(desordenado){
    desordenado = 0;
    for(i = 0; i < cota; i++)
      if(notas[i] > notas[i+1]){
        aux = notas[i];
        notas[i] = notas[i+1];
        notas[i+1] = aux;

        aux = dnis[i];
        dnis[i] = dnis[i+1];
        dnis[i+1] = aux;

        desordenado = i;
      }
    cota = desordenado;
  }
}

void mostrarListado(int dnis[], int notas[], int ce){
  int i;

  printf("\n\tLISTADO DE NOTAS\n");
  printf("\tDNI\tNOTAS\n");
  for(i=0; i < ce; i++){
    if(dnis[i] != 0) printf("\t%d\t%d\n", dnis[i], notas[i]);
  }
}
