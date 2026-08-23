/*************************************************************************************************************************
Una cadena de artículos del hogar necesita liquidar comisiones de sus casi 50 vendedores y para ello se deben registrar y 
almacenar con la estructura adecuada:
  * Numero de Vendedor (entero de 2 cifras no correlativo y sin repetidos)
  * Nombre Vendedor (string de 25 caracteres)
  * Sector (E – Electrodomésticos, M – Muebles, V – Vajillas, T – Telefonía)
  * Porcentaje de comisión (entero entre 5 y 15)
  * Comisión a cobrar (real)
La liquidación de comisiones termina con el ingreso de un numero de vendedor igual a cero.
Luego por cada vendedor se ingresarán las ventas que hizo por cada día (real mayor o igual que 0) en los 21 días del mes y 
debe actualizar la comisión a cobrar. También finaliza con un numero de vendedor igual a cero.

Se necesita determinar e informar:
  1. Listado de comisiones cobradas por día y vendedor mostrando su nombre (resolver en una función).
  2. El nombre del vendedor que cobra la menor comisión actualizada, en caso de ser mas de uno mostrarlos a todos.
  3. El importe total a pagar de comisiones por cada sector (resolver en una función).
*************************************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct{
  int codigo;
  char nombre[26];
  char sector;
  int porcentaje;
  float comision;
  float ventas[21];
} Vendedor;

void inicializarStruct(Vendedor[], int);
int ingresoDatos(Vendedor[], int);
void ingresoVentas(Vendedor[], int);

int validacionRangoFin(int, int, int);
int validacionRango(int, int);
int validacionLimite(int);
float validacionValor(float);
char validacionLetra();
void validacionPalabra(char[], int);
int buscarCodigo(Vendedor[], int, int);

void mostrarVentas(Vendedor[], int, int);
float minimo(Vendedor[], int);
void menosCobro(Vendedor[], float, int);
void pagoComisiones(Vendedor[], int);

int main(){
  Vendedor vVend[50];
  int ingresos = 0;
  float min;

  inicializarStruct(vVend, 50);
  ingresos = ingresoDatos(vVend, 50);
  
  if(ingresos > 0){
    ingresoVentas(vVend, ingresos);
    mostrarVentas(vVend, ingresos, 21);
    min = minimo(vVend, ingresos);
    menosCobro(vVend, min, ingresos);
    pagoComisiones(vVend, ingresos);
  }else{
    printf("No hubieron ingresos\n");
  }

  return 0;
}

void inicializarStruct(Vendedor vec[], int ce){
  int i, j;

  for(i = 0; i < ce; i++){
    vec[i].codigo = 0;
    strcpy(vec[i].nombre, " ");
    vec[i].sector = ' ';
    vec[i].porcentaje = 0;
    vec[i].comision = 0;
    for(j = 0; j < 21; j++){
      vec[i].ventas[j] = 0;
    }
  }
}

int ingresoDatos(Vendedor vec[], int ce){
  int i = 0, codigo = -1, pos;
  char nombre[26];

  while(codigo != 0 && i < ce){
    do{
      printf("Ingrese el numero del vendedor (2 cifras)[0 para fin]: ");
      codigo = validacionRangoFin(10, 99, 0);
      pos = buscarCodigo(vec, codigo, i);
    }while(pos != -1 && codigo != 0);

    if(codigo != 0){
      vec[i].codigo = codigo;

      printf("Ingrese el nombre del vendedor (25 caracteres): ");
      validacionPalabra(nombre, 26);
      strcpy(vec[i].nombre, nombre);

      printf("Ingrese el sector (E, M, V o T): ");
      vec[i].sector = validacionLetra();

      printf("Ingrese el porcentaje de la comision (5 a 15): ");
      vec[i].porcentaje = validacionRango(5, 15);
      i++;
    }
  }

  return i;
}

void ingresoVentas(Vendedor vec[], int ce){
  int pos, codigo = -1, dia;
  float venta;

  while(codigo != 0){
    do{
      printf("Ingrese el codigo del vendedor (10 a 99) [0 para fin]: ");
      codigo = validacionRangoFin(10, 99, 0);
      pos = buscarCodigo(vec, codigo, ce);
    }while(codigo != 0 && pos == -1);

    if(codigo != 0){
      printf("Ingrese el dia (1 a 21): ");
      dia = validacionRango(1, 21);

      printf("Ingrese la cantidad de ventas (real mayor a 0): ");
      venta = validacionValor(0);

      vec[pos].ventas[dia-1] += venta;
      
      vec[pos].comision += venta * (vec[pos].porcentaje / 100.0);
    }
  }
}

float minimo(Vendedor vec[], int ce){
  int i; 
  float min = vec[0].comision;

  for(i = 0; i < ce; i++){
    if(vec[i].comision < min)
      min = vec[i].comision;
  }

  return min;
}

int validacionRangoFin(int min, int max, int fin){
  int num;
  do{
    scanf("%d", &num);
  }while((num < min || num > max) && num != fin);
  getchar();
  return num;
}

int validacionRango(int min, int max){
  int num;
  do{
    scanf("%d", &num);
  }while(num < min || num > max);
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

float validacionValor(float min){
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
  }while(letra != 'E' && letra != 'M' && letra != 'V' && letra != 'T');
  getchar();
  return letra;
}

void validacionPalabra(char palabra[], int medida){
  int ultimo, i;
  fgets(palabra, medida, stdin);
  ultimo = strlen(palabra)-1;
  
  if(palabra[ultimo] == '\n') palabra[ultimo] = '\0'; 
  
  for(i = 0; i < ultimo; i++){
    palabra[i] = toupper(palabra[i]);
  }
}

int buscarCodigo(Vendedor vec[], int num, int ce){
  int i = 0, pos = -1;
  while(i < ce && pos == -1){
    if(vec[i].codigo == num)
      pos = i;
    else
      i++;
  }
  return pos;
}

void mostrarVentas(Vendedor vec[], int cf, int cc){
  int i, j;
  float comisionDiaria;

  printf("\n\t\tLISTADO DE COMISIONES\n\t");
  for(i = 0; i < cc; i++)
    printf("\tDIA %d", i+1);
  
  for(i = 0; i < cf; i++){
    printf("\n%s", vec[i].nombre);
    for(j = 0; j < cc; j++){
      comisionDiaria = vec[i].ventas[j] * (vec[i].porcentaje / 100.0);
      printf("\t%.1f", comisionDiaria);
    }
  }
  printf("\n");
}

void menosCobro(Vendedor vec[], float num, int ce){
  int i;
  for(i = 0; i < ce; i++){
    if(vec[i].comision == num)
      printf("\nEl vendedor %s tiene la menor comision ($%.2f).", vec[i].nombre, vec[i].comision);
  }
  printf("\n");
}

void pagoComisiones(Vendedor vec[], int ce){
  int i;
  float ventE = 0, ventM = 0, ventV = 0, ventT = 0;

  for(i = 0; i < ce; i++){
    if(vec[i].sector == 'E') ventE += vec[i].comision;
    if(vec[i].sector == 'M') ventM += vec[i].comision;
    if(vec[i].sector == 'V') ventV += vec[i].comision;
    if(vec[i].sector == 'T') ventT += vec[i].comision;
  }

  printf("\n\t\tIMPORTE POR COMISION SECTOR");
  printf("\nSector E: $%.2f", ventE);
  printf("\nSector M: $%.2f", ventM);
  printf("\nSector V: $%.2f", ventV);
  printf("\nSector T: $%.2f\n", ventT);
}