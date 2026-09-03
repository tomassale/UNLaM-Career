/************************************************************************************************************************************
Una fábrica de empanadas necesita controlar la venta de sus casi 20 gustos de empanada y para ello se deben registrar y almacenar con 
la estructura adecuada:
  * Código de empanada (entero de 3 cifras no correlativo y sin repetidos)
  * Nombre Gusto (string de 25 caracteres)
  * Cocción (H – Horno, F – Fritas, S – Sin Cocción)
  * Cantidad Vendida (entero mayor a 0)
  * Precio (real mayor que cero)
La registración de gustos termina con el ingreso de un código de empanada igual a cero.
Luego por cada código de empanada se ingresará la venta que hizo por cada día de la semana (real mayor o igual que 0) en los 7 días de 
la semana y debe actualizar la cantidad vendida. La carga de las ventas finaliza con un código de empanada igual a cero.

Se necesita determinar e informar:
  1. Listado de importe total vendido por día y código de empanada mostrando su nombre (resolver en una función).
  2. El nombre del gusto que tuvo la mayor venta, en caso de ser mas de uno mostrarlos a todos.
  3. La cantidad total vendida por Cocción (resolver en una función).
*************************************************************************************************************************************/
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct{
  int codigo;
  char nombre[26];
  char coccion;
  int ventas;
  float precio;
  int ventasDiarias[7];
} Gustos;

int cargarDatos(Gustos[], int);
void cargarVentas(Gustos[], int);
void inicializarStruct(Gustos[], int);

int validacionRango(int, int);
int validacionRangoFin(int, int, int);
int validacionLimite(int);
float validacionPrecio(float);
char validacionLetra();
int buscarCodigo(Gustos[], int, int);

void listarVentas(Gustos[], int);
int maximo(Gustos[], int);
void mayorVenta(Gustos[], int, int);
void ventasCoccion(Gustos[], int);

int main(){
  Gustos vGus[20];
  int ingresos = 0, max;

  inicializarStruct(vGus, 20);
  ingresos = cargarDatos(vGus, 20);
  if(ingresos > 0){
    cargarVentas(vGus, ingresos);
    listarVentas(vGus, ingresos);
    max = maximo(vGus, ingresos);
    mayorVenta(vGus, max, ingresos);
    ventasCoccion(vGus, ingresos);
  }else{
    printf("No hubieron ingresos.");
  }

  return 0;
}

int validacionRango(int min, int max){
  int num;

  do{
    scanf("%d", &num);
  }while(num < min || num > max);
  getchar();
    
  return num;
}

int validacionRangoFin(int min, int max, int fin){
  int num;

  do{
    scanf("%d", &num);
  }while((num < min || num > max) && num != fin);
  getchar();
  
  return num;
}

int validacionLimite(int min){
  int num;

  do{
    scanf("%d", &num);
  }while(num < min);
  getchar();
  
  return num;
}

float validacionPrecio(float min){
  float num;

  do{
    scanf("%f", &num);
  }while(num < min);
  getchar();
  
  return num;
}

char validacionLetra(){
  char letra;

  do{
    scanf("%c", &letra);
    letra = toupper(letra);
  }while(letra != 'H' && letra != 'F' && letra != 'S');
  getchar();

  return letra;
}

int buscarCodigo(Gustos vec[], int num, int ce){
  int i = 0, pos = -1;

  while(i < ce && pos == -1){
    if(vec[i].codigo == num)
      pos = i;
    else
      i++;
  }

  return pos;
}

void inicializarStruct(Gustos vec[], int ce){
  int i, j;

  for(i = 0; i < ce; i++){
    vec[i].codigo = 0;
    strcpy(vec[i].nombre, " ");
    vec[i].coccion = ' ';
    vec[i].ventas = 0;
    vec[i].precio = 0;
    for(j = 0; j < 7; j++)
      vec[i].ventasDiarias[j] = 0;
  }
}

int maximo(Gustos vec[], int ce){
  int i, max = vec[0].ventas;

  for(i = 0; i < ce; i++)
    if(vec[i].ventas > max) max = vec[i].ventas;

  return max;
}

void mayorVenta(Gustos vec[], int max, int ce){
  int i;

  for(i = 0; i < ce; i++){
      if(vec[i].ventas == max)
        printf("\nEl gusto %s tuvo maximo de ventas (%d).", vec[i].nombre, max);
  }
}

int cargarDatos(Gustos vec[], int ce){
  int i = 0, codigo = -1, pos, ultimo;
  char nombre[26];

  while(i < ce && codigo != 0){
    do{
      printf("Ingrese el codigo (3 cifras)[0 para fin]: ");
      codigo = validacionRangoFin(100, 999, 0);
      pos = buscarCodigo(vec, codigo, i);
    }while(pos != -1 && codigo != 0);

    if(codigo != 0){
      printf("Ingrese el nombre del gusto (25 caracteres): ");
      fgets(nombre, 26, stdin);
      ultimo = strlen(nombre) - 1;
      if(nombre[ultimo] == '\n') nombre[ultimo] = '\0';

      printf("Ingrese el tipo de coccion (H, F o S): ");
      vec[i].coccion = validacionLetra();

      printf("Ingrese el precio (mayor a 0): ");
      vec[i].precio = validacionPrecio(0);

      vec[i].codigo = codigo;
      strcpy(vec[i].nombre, nombre);
      i++;
    }
  }
  return i;
}

void cargarVentas(Gustos vec[], int ce){
  int codigo = -1, dia, ventas, pos;

  while(codigo != 0){
    do{
      printf("Ingrese el codigo [0 para fin]: ");
      codigo = validacionRangoFin(100, 999, 0);
      pos = buscarCodigo(vec, codigo, ce);
    }while(pos == -1 && codigo != 0);

    if(codigo != 0){
      printf("Ingrese el dia (1 a 7): ");
      dia = validacionRango(1, 7);

      printf("Ingrese las ventas (mayor a 0): ");
      ventas = validacionLimite(0);

      vec[pos].ventas += ventas;
      vec[pos].ventasDiarias[dia-1] += ventas;
    }
  }
}

void ventasCoccion(Gustos vec[], int ce){
  int i, ventasH = 0, ventasF = 0, ventasS = 0;

  for(i = 0; i < ce; i++){
    if(vec[i].coccion == 'H') ventasH += vec[i].ventas;
    if(vec[i].coccion == 'F') ventasF += vec[i].ventas;
    if(vec[i].coccion == 'S') ventasS += vec[i].ventas;
  }

  printf("\nLa coccion Horno tuvo %d ventas.", ventasH);
  printf("\nLa coccion Fritas tuvo %d ventas.", ventasF);
  printf("\nLa coccion Sin coccion tuvo %d ventas.", ventasS);
}

void listarVentas(Gustos vec[], int ce){
  int i, j;
  float importe;

  printf("\n\t\tLISTADO IMPORTES");
  printf("\n\t");
  for(i = 0; i < 7; i++){
    printf("\tDia %d", i+1);
  }
  for(i = 0; i < ce; i++){
    printf("\n%20s", vec[i].nombre);
    for(j = 0; j < 7; j++){
      importe = vec[i].ventasDiarias[j] * vec[i].precio;
      printf("%.1f\t", importe);
    }
  }
}