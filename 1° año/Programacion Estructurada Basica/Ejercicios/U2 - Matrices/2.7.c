/************************************************************************************************************************
 Una empresa desea registrar las ventas realizadas de cada uno de sus 20 productos a lo lardo del año. Los
productos están identificados por códigos numéricos de 3 cifras. Como primera información se ingresa el
precio unitario de cada uno de los productos y su código. Luego por cada venta se ingresa:
  • Código de producto
  • Día de venta
  • Mes de venta
  • Cantidad de unidades vendidas
El ingreso de datos finaliza con un código de producto igual a 0. Informar:
  a. El detalle de unidades vendidas de cada producto en cada uno de los 12 meses.
  b. El producto con el cual se obtuvo la mayor recaudación.
  c. El trimestre de menor recaudación del año.
************************************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void cargaAleatoriaMatriz(int[][12], int, int, int, int);
void cargaAleatoriaVector(int[], int, int, int);
void cargaProductos(int[], int);
void cargaVentas(int[][12], int[], int[], int[]);
int buscaCodigo(int[], int, int);
int validacionFecha(int);
int validacionRango(int, int);
int validacionRangoFin(int, int, int);
int validacionMinimo(int);
void sumaFilas(int[][12], int[], int, int);
void sumaColumnas(int[][12], int[], int, int);
int minimo(int[]);
int maximo(int[], int);
void mostrarMatriz(int[][12], int[], int, int);
void mayorRecaudacion(int[], int[], int, int);
void minimoTrimestre(int);

int main(){
  int ventas[20][12] = {{0}};
  int sumaF[20] = {0};
  int sumaC[20] = {0};
  int codigos[20] = {0};
  int min, max;

  srand(time(NULL));

  cargaAleatoriaVector(codigos, 20, 100, 999);
  //cargaProductos(codigos, 20);
  cargaAleatoriaMatriz(ventas, 20, 12, 5, 200);
  //cargaVentas(ventas, codigos, sumaF, sumaC);
  sumaFilas(ventas, sumaF, 20, 12);
  sumaColumnas(ventas, sumaC, 20, 12);
  min = minimo(sumaC);
  max = maximo(sumaF, 20);
  mostrarMatriz(ventas, codigos, 20, 12);
  if(max != 0){
    mayorRecaudacion(sumaF, codigos, 20, max);
    minimoTrimestre(min);
  }

}

void cargaAleatoriaVector(int vec[], int ce, int min, int max){
  int i;

  for(i = 0; i < ce; i++){
    vec[i] = (rand() % (max - min + 1)) + min;
  }
}

void cargaAleatoriaMatriz(int matriz[][12], int cf, int cc, int min, int max){
  int i, j;

  for(i = 0; i < cf; i++){
    for(j = 0; j < cc; j++){
      matriz[i][j] = (rand() % (max - min + 1)) + min;
    }
  }
}

void cargaProductos(int vec[], int ce){
  int i, num, pos;

  for(i = 0; i < ce; i++){
    do{
      printf("Ingrese el codigo del producto (3 digitos) (%d de %d): ", i+1, ce);
      num = validacionRango(100, 999);
      pos = buscaCodigo(vec, i, num);
    }while(pos != -1);
    vec[i] = num;
  }
}

void cargaVentas(int ventas[][12], int cod[], int sumF[], int sumC[]){
  int codigo, dia, mes, diaMaximo, cantidad, pos;

  while(codigo != 0){

    do{
      printf("Ingrese el codigo a buscar: ");
      codigo = validacionRangoFin(100, 999, 0);
      pos = buscaCodigo(cod, 20, codigo);
    }while(pos == -1 && codigo != 0);

    if(codigo != 0){
      printf("Ingrese el mes (1 a 12): ");
      mes = validacionRango(1, 12);

      diaMaximo = validacionFecha(mes);
      printf("Ingrese el dia (1 a %d): ", diaMaximo);
      dia = validacionRango(1, diaMaximo);

      printf("Ingrese la cantidad de ventas (mayor a 0): ");
      cantidad = validacionMinimo(0);

      sumF[pos] += cantidad;
      sumC[mes-1] += cantidad;

      ventas[pos][mes-1] += cantidad; 
    }
  }
}

void sumaFilas(int matriz[][12], int sumF[], int cf, int cc){
  int i, j;

  for(i = 0; i < cf; i++){
    for(j = 0; j < cc; j++){
      sumF[i] += matriz[i][j];
    }
  }
}

void sumaColumnas(int matriz[][12], int sumC[], int cf, int cc){
  int i, j;

  for(i = 0; i < cc; i++){
    for(j = 0; j < cf; j++){
      sumC[i] += matriz[j][i];
    }
  }
}

int buscaCodigo(int vec[], int ce, int num){
  int i = 0, pos = -1;

  while(i < ce && pos == -1){
    if(vec[i] == num) 
      pos = i;
    else
      i++;
  }

  return pos;
}

int validacionFecha(int mes){
  int max;

  switch(mes){
    case 1: case 3: case 5: case 7: case 8: case 10: case 12:
      max = 31;
      break;
    case 2:
      max = 29;
      break;
    case 4: case  6: case 9: case 11:
      max = 30;
      break;
  }

  return max;
}

int validacionRango(int min, int max){
  int num;

  do{
    scanf("%d", &num);
  }while(num < min || num > max);

  return num;
}

int validacionRangoFin(int min, int max, int fin){
  int num;

  do{
    scanf("%d", &num);
  }while((num < min || num > max) && num != fin);

  return num;
}

int validacionMinimo(int min){
  int num;

  do{
    scanf("%d", &num);
  }while(num < min);

  return num;
}

int minimo(int vec[]){
  int i, j, maximo = 0, indice = 0;
  int acumTrim[4] = {0};

  for(i = 0; i < 4; i++){
    for(j = i*3; j < (i*3) + 3; j++){
      acumTrim[i] += vec[j];
    }
  }

  for(i = 0; i < 4; i++){
    if(acumTrim[i] > maximo){
      maximo = acumTrim[i];
      indice = i;
    }
  }

  return indice;
}

int maximo(int vec[], int ce){

  int i, min = vec[0];

  for(i = 0; i < ce; i++){
    if(vec[i] < min) min = vec[i];
  }

  return min;
}

void mostrarMatriz(int matriz[][12], int cod[], int cf, int cc){
  int i, j;

  printf("\n\t\t\t\t\t\tPRODUCTOS VENDIDOS\n\n");
  printf("\t\t");
  for(i = 0; i < 12; i++) printf("%d\t", i+1);
  printf("\n\t{\n");

  for(i = 0; i < cf; i++){
    printf("\n%d:\t", cod[i]);
    for(j = 0; j < cc; j++){
      printf("\t%3d,", matriz[i][j]);
    }
    printf("\n");
  }
  printf("\t}");
}

void mayorRecaudacion(int vec[], int cod[], int ce, int max){
  int i;

  for(i = 0; i < ce; i++){
    if(vec[i] == max) printf("\nEl producto con mayor recuadacion fue el %d con %d ventas.", cod[i], max);
  }
}

void minimoTrimestre(int indice){
  printf("\nEl trimestre con menos cantidad de ventas fue el %d", indice+1);
}