/************************************************************************************************************************
La empresa de turismo GUADALAJARA VIAJES comercializa 10 diferentes tours a través de 15 agencias en todo el país. 
Diariamente cada agencia envía la cantidad de ventas efectuadas de cada tour, indicando agencia, tours y la cantidad 
de pasajes. Algunas agencias envían 0 en la cantidad cuando no existen pasajes para un tour determinado, pero no en todas.
La información que se envía tiene los siguientes datos que se ingresan en forma desordenada:
  • Código de agencia (de 1 a 15)
  • Código de tour (1 a 10)
  • Cantidad de pasajes (0 a 20)
Informar:
  a. El total de pasajes vendidos por tour en cada agencia.
  b. El número de agencia que obtuvo la máxima cantidad de pasajes vendidos. (puede repetirse) 
************************************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void ingresoAleatorio(int[][15], int, int, int, int);
int validacionRango(int, int);
void ingresoDatos(int[][15]);
void sumarColumnas(int[][15], int[], int, int);
void informarVendidos(int[][15], int, int);
int maximo(int[], int);
void agenciaMaximosVendidos(int[], int, int);

int main(){
  
  int matriz[10][15] = {{0}};
  int sumaC[15] = {0};
  int max;
  srand(time(NULL));
  
  //ingresoAleatorio(matriz, 10, 15, 0, 20);
  ingresoDatos(matriz);
  sumarColumnas(matriz, sumaC, 10, 15);
  informarVendidos(matriz, 10, 15);
  max = maximo(sumaC, 15);
  if(max != 0) agenciaMaximosVendidos(sumaC, 15, max);

  return 0; 
}

void ingresoAleatorio(int matriz[][15], int cf, int cc, int min, int max){
  int i, j;

  for(i = 0; i < cc; i++){
    for(j = 0; j < cf; j++){
      matriz[j][i] = (rand() % max) + min;
    }
  }
}

int validacionRango(int min, int max){
  int num;

  do{
    scanf("%d", &num);
  }while(num < min || num > max);

  return num;
}

void ingresoDatos(int matriz[][15]){
  int agencia, tour, pasajes;
  
  printf("Ingrese la agencia (1 a 15)(0 para fin): ");
  agencia = validacionRango(0, 15);
  while(agencia != 0){
    printf("Ingrese el codigo del tour (1 a 10): ");
    tour = validacionRango(1, 10);
    printf("Ingrese la cantidad de pasajes: ");
    pasajes = validacionRango(1, 20);
    matriz[tour-1][agencia-1] = pasajes;

    printf("Ingrese la agencia (1 a 15)(0 para fin): ");
    agencia = validacionRango(0, 15);
  }
}

void sumarColumnas(int matriz[][15], int vec[], int cf, int cc){
  int i, j, suma = 0;

  for(i = 0;i < cc; i++){
    suma = 0;
    for(j = 0; j < cf; j++){
      suma += matriz[j][i];
    }
    vec[i] = suma;
  }
}

void informarVendidos(int matriz[][15], int cf, int cc){
  int i, j;

  printf("\n\t\tVENDIDO POR TOUR\n");
  printf("{\n");
  for(i = 0; i < cf; i++){
    for(j = 0; j < cc; j++){
      printf("\t%2d, ", matriz[i][j]);
    }
    printf("\n");
  }
  printf("\n}");
}

int maximo(int vec[], int ce){
  int i, max = vec[0];

  for(i = 0; i < ce; i++){
    if(max < vec[i])
      max = vec[i];
  }

  return max;
}

void agenciaMaximosVendidos(int vec[], int ce, int max){
  int i;

  printf("\n\t\tMAXIMO VENDIDO POR AGENCIAS\n");
  for(i = 0; i < ce; i++){
    if(vec[i] == max)
      printf("La agencia con mayores ventas es la %d con %d ventas\n", i+1, max);
  }
}