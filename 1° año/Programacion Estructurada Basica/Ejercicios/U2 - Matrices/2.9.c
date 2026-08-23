/************************************************************************************************************************
Se desea contabilizar los votos recibidos en las elecciones de un club de fútbol. Existen 10 candidatos cada
uno representado por un número de lista diferente (número de 3 cifras no correlativo). La votación se realiza
en 15 sedes distintas codificadas del 1 al 15. Se ingresan los votos registrados en cada una de las sedes
registrando:
  • Número de lista
  • Número de sede
  • Cantidad de votos
(Solo se informan candidatos que recibieron votos).
La carga de votos finaliza con un número de lista igual a 0
Mostrar:
  a. Cantidad de votos recibidos por cada candidato en cada sede. 
                                         VER FORMATO EN ARCHIVO
  b. Listado ordenado por cantidad de votos totales en formar decreciente, con el siguiente formato:
                                         VER FORMATO EN ARCHIVO
  c. Candidatos que NO recibieron votos en la sede 5.
************************************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void cargaAleatoriaVector(int[], int, int, int);
void cargaAleatoriaMatriz(int[][15], int, int, int, int);
void cargaCodigos(int[], int);
void cargaVotos(int[][15], int[], int, int);
int buscaCodigo(int[], int, int);
int ingresoValidadoFin(int, int, int);
int ingresoValidado(int, int);
int ingresoRango(int);
void sumaFilas(int[][15], int[], int, int);
void ordenarDecreciente(int[], int[], int);
void mostrarMatriz(int[][15], int[], int, int);
void mostrarVotosCandidatos(int[], int[], int);
void mostrarSinVotos5(int[][15], int[], int, int);

int main(){
  int votos[10][15] = {{0}};
  int sumaF[10] = {0};
  int codigos[10] = {0};

  srand(time(NULL));

  cargaAleatoriaVector(codigos, 10, 100, 999);
  cargaAleatoriaMatriz(votos, 10, 15, 100, 999);
  //cargaCodigos(codigos, 10);
  //cargaVotos(votos, codigos, 10, 15);
  sumaFilas(votos, sumaF, 10, 15);
  mostrarMatriz(votos, codigos, 10, 15);
  ordenarDecreciente(codigos, sumaF, 10);
  mostrarVotosCandidatos(codigos, sumaF, 10);
  mostrarSinVotos5(votos, codigos, 10, 5);

  return 0;
}

void cargaAleatoriaVector(int vec[], int ce, int min, int max){
  int i;

  for(i = 0; i < ce; i++){
    vec[i] = (rand() % (max-min+1) + min);
  }
}

void cargaAleatoriaMatriz(int matriz[][15], int cf, int cc, int min, int max){
  int i, j;

  for(i = 0; i < cf; i++){
    for(j = 0; j < cc; j++){
      matriz[i][j] = (rand() % (max-min+1)) + min;
    }
  }
}

void cargaCodigos(int vec[], int ce){
  int i, pos, codigo;

  for(i = 0; i < ce; i++){
    do{
      printf("Ingrese el codigo de lista (3 cifras): ");
      codigo = ingresoValidado(100, 999);
      pos = buscaCodigo(vec, codigo, i);
    }while(pos != -1); 
    vec[i] = codigo;
  }
}

void cargaVotos(int matriz[][15], int codigos[], int cf, int cc){
  int votos, lista = -1, sede, pos;

  while(lista != 0){
    do{
      printf("Ingrese el codigo de lista (3 cifras): ");
      lista = ingresoValidadoFin(100, 999, 0);
      pos = buscaCodigo(codigos, lista, 10);
      if(pos == -1)printf("\nError: El codigo de lista no existe. Intenta nuevamente.");
    }while(pos == -1 && lista != 0);

    if(lista != 0){
      printf("Ingrese la sede (1 a 15): ");
      sede = ingresoValidado(1, 15);

      printf("Ingrese la cantidad de votos (mayor a 0): ");
      votos = ingresoRango(0);

      matriz[pos][sede-1] += votos;
    }else{
      printf("\nIngreso finalizado.");
    }
  }
}

int buscaCodigo(int vec[], int num, int ce){
 int i = 0, pos = -1;

 while(pos == -1 && i < ce){
    if(vec[i] == num)
      pos = i;
    else
      i++;
 }

 return pos;
}

int ingresoValidadoFin(int min, int max, int fin){
  int num;

  do{
    scanf("%d", &num);
  }while((num < min || num > max) && num != fin);

  return num;
}

int ingresoValidado(int min, int max){
  int num;

  do{
    scanf("%d", &num);
  }while(num < min || num > max);

  return num;
}

int ingresoRango(int min){
  int num;

  do{
    scanf("%d", &num);
  }while(num < min);

  return num;
}

void sumaFilas(int matriz[][15], int sumaF[], int cf, int cc){
  int i, j, suma = 0;

  for(i = 0; i < cf; i++){
    for(j = 0; j < cc; j++){
      sumaF[i] += matriz[i][j];
    }
  }
}

void ordenarDecreciente(int codigos[], int votos[], int ce){
  int i, aux, cota = ce-1;
  int desordenado = 1;

  while(desordenado){
    desordenado = 0;
    for(i = 0; i < cota; i++){
      if(votos[i] < votos[i+1]){
        aux = votos[i];
        votos[i] = votos[i+1];
        votos[i+1] = aux;

        aux = codigos[i];
        codigos[i] = codigos[i+1];
        codigos[i+1] = aux;

        desordenado = i;
      }
    }
    cota = desordenado;
  }
}

void mostrarMatriz(int matriz[][15], int cod[], int cf, int cc){
  int i, j;

  printf("\nLISTA");
  for(i = 0; i < cc; i++){
    printf("\tSEDE%d", i+1);
  }
  for(i = 0; i < cf; i++){
    printf("\n%d", cod[i]);
    for(j = 0; j < cc; j++){
      printf("\t%d", matriz[i][j]);
    }
    printf("\n");
  }
}

void mostrarVotosCandidatos(int cod[], int votos[], int ce){
  int i;
  int votosTotales = 0;
  float porcentaje;

  for(i = 0; i < ce; i++){
    votosTotales += votos[i];
  }

  printf("\nTOTAL DE VOTOS\t\tPORCENTAJE\t\tLISTA");
  for(i = 0; i < ce; i++){
    porcentaje = (float) votos[i] * 100 / votosTotales;
    printf("\n%d\t\t\t%.2f%%\t\t\t%d", votos[i], porcentaje, cod[i]);
  }
}

void mostrarSinVotos5(int matriz[][15], int cod[], int cf, int col){
  int i;

  for(i = 0; i < cf; i++){
    if(matriz[i][col-1] == 0) 
      printf("\nEl candidato %d no recibio votos en la sede 5.", cod[i]);
  }
}
