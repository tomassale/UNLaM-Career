/************************************************************************************************************************
 Se desea desarrollar un sistema de reservas de entradas para un cine. La sala consta de 12 filas numeradas de
la 1 a la 12 y cada fila tiene 9 butacas numeradas a partir de la columna central, con las butacas impares a la
derecha y las pares a la izquierda, como en el siguiente esquema:

                                              8 6 4 2 1 3 5 7 9

Para la carga, se debe mostrar al usuario un esquema con las butacas disponibles y reservadas, marcando
con la letra D las disponibles y con la letra R las reservadas.

Por cada reserva se debe solicitar la fila y número de butaca a reservar. Cada vez que se realice una
reserva se deberá actualizar el esquema que muestra las butacas. Si la butaca seleccionada ya estaba
ocupada se debe informar al usuario para que seleccione otra. El proceso de reserva finaliza con una fila
con un número negativo.
Al finalizar mostrar:
  a. la cantidad de asientos disponibles y la cantidad de asientos reservados.
  b. los números de filas que quedaron vacías.
  c. la o las filas con mayor cantidad de espectadores.
  d. un listado con la cantidad de personas que se sentaron en los mismos números de butacas en
  todo el cine ordenado de mayor a menor. Por ejemplo:
                                VER FORMATO EN ARCHIVO
************************************************************************************************************************/


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

void inicializarMatriz(char[][9], int, int);
void ingresoReservas(char[][9], int[], int, int);
char ingresoValido();
int ingresoRango(int, int);
int ingresoRangoFin(int, int, int);
int contarDisponibilidad(char[][9], int, int, char);
void sumaFilas(char[][9], int[], int, int);
void sumaColumnas(char[][9], int[], int, int);
void ordenarDescendiente(int[], int[], int);
int maximo(int[], int);
int buscaCodigo(int[], int, int);
void mostrarContadores(int, int);
void mostrarFilas(int[], int, int);
void mostrarListado(int[], int[], int);

int main(){
  char matriz[12][9];
  int asientos[9] = {8, 6, 4, 2, 1, 3, 5, 7, 9};
  int contCol[9] = {0};
  int contFil[12] = {0};
  int contDisp = 0, contRes = 0, max;

  inicializarMatriz(matriz, 12, 9);
  ingresoReservas(matriz, asientos, 12, 9);
  contDisp = contarDisponibilidad(matriz, 12, 9, 'D');
  contRes = contarDisponibilidad(matriz, 12, 9, 'R');

  sumaFilas(matriz, contFil, 12, 9);
  sumaColumnas(matriz, contCol, 12, 9);
  max = maximo(contFil, 12);
  mostrarContadores(contDisp, contRes);
  mostrarFilas(contFil, 12, max);
  ordenarDescendiente(asientos, contCol, 9);
  mostrarListado(asientos, contCol, 9);

  return 0;
}

void inicializarMatriz(char matriz[][9], int cf, int cc){
  int i, j;

  for(i = 0; i < cf; i++){
    for(j = 0; j < cc; j++){
      matriz[i][j] = 'D';
    }
  }
}

int buscaCodigo(int vec[], int ce, int num){
  int i = 0, pos = -1; 

  while(pos == -1 && i < ce){
    if(vec[i] == num)
      pos = i;
    else
      i++;
  }

  return pos;
}

void ingresoReservas(char matriz[][9], int cod[], int cf, int cc){
  int fila, butaca, pos;

  fila = ingresoRangoFin(1, 12, 0);
  while(fila > 0){
      do{
        butaca = ingresoRango(1, 9);
        pos = buscaCodigo(cod, 9, butaca);
      }while(pos == -1);

      if(matriz[fila-1][pos] == 'R'){
        printf("¡Error! La butaca ya esta ocupada. Elija otra.\n");
      }else{
        matriz[fila-1][pos] = ingresoValido();
      }
      fila = ingresoRangoFin(1, 12, 0);
  }
}

int ingresoRango(int min, int max){
  int num;

  do{
    printf("Ingrese el numero (%d a %d): ", min, max);
    scanf("%d", &num);
  }while(num < min || num > max);

  return num;
}

int ingresoRangoFin(int min, int max, int fin){
  int num;

  do{
    printf("Ingrese el numero (%d a %d)(%d para fin): ", min, max, fin);
    scanf("%d", &num);
  }while((num < min || num > max) && num >= fin);

  return num;
}

char ingresoValido(){
  char car;

  do{
    getchar();
    printf("Ingrese el caracter (R para reservar): ");
    scanf("%c", &car);
    car = toupper(car);
  }while(car != 'D' && car != 'R');

  return car;
}

int contarDisponibilidad(char matriz[][9], int cf, int cc, char car){
  int i, j, cont = 0;

  for(i = 0; i < cf; i++){
    for(j = 0; j < cc; j++){
      if(car == matriz[i][j]) cont++;
    }
  }

  return cont;
}

void sumaFilas(char matriz[][9], int suma[], int cf, int cc){
  int i, j;

  for(i = 0; i < cf; i++){
    for(j = 0; j < cc; j++){
      if(matriz[i][j] == 'R')
        suma[i]++;
    }
  }
}

void sumaColumnas(char matriz[][9], int suma[], int cf, int cc){
  int i, j;

  for(i = 0; i < cc; i++){
    for(j = 0; j < cf; j++){
      if(matriz[j][i] == 'R')
        suma[i]++;
    }
  }
}

void ordenarDescendiente(int cod[], int asientos[], int ce){
  int i, aux, cota = ce-1;
  int desordenado = 1;

  while(desordenado){
    desordenado = 0;
    for(i = 0; i < cota; i++){
      if(asientos[i] < asientos[i+1]){
        aux = asientos[i];
        asientos[i] = asientos[i+1];
        asientos[i+1] = aux;

        aux = cod[i];
        cod[i] = cod[i+1];
        cod[i+1] = aux;
        desordenado = i;
      }
    }
    cota = desordenado;
  }
}

int maximo(int vec[], int ce){
  int i, max = vec[0];

  for(i = 0; i < ce; i++){
    if(vec[i] > max) max = vec[i];
  }

  return max;
}

void mostrarContadores(int vacios, int reservados){
  printf("\nHay %d asientos reservados", reservados);
  printf("\nHay %d asientos vacios", vacios);
}

void mostrarFilas(int suma[], int ce, int max){
  int i;

  for(i = 0; i < ce; i++){
    if(suma[i] == 0)
      printf("\nLa fila %d no tiene ingresos", i+1);
    if(suma[i] == max)
      printf("\nLa fila %d tiene los maximos ingresos (%d)", i+1, max);
  }
}

void mostrarListado(int cod[], int sum[], int ce){
  int i;

  printf("\n\tButaca Cantidad\n");
  for(i = 0; i < ce; i++){
    printf("\t%d\t%2d\n", cod[i], sum[i]);
  }
}