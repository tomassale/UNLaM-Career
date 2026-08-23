/********************************************************************************************************************************
Una empresa de mensajería posee cerca de 100 mensajeros divididos en 3 tipos.
Al comenzar se ingresa el nombre y apellido del operador que procesa los datos (máximo 30 caracteres).

Por cada mensajero se ingresa en único vector:
  * Número de mensajero (1 a 999 no correlativo sin repetidos) (ingresado y validado por función y sin repetidos).
  * Tipo vehiculo de reparto ("Moto" "Auto" "Bicicleta") (ingresar sin validar).
  * Kilómetros recorridos (mayor a cero).
  * Fecha última actualización (dia mes año - en único campo).
La fecha es un dato fijo 31/8/2024 que no ingresa por teclado.
La carga concluye con un mensajero número 0.

Luego se cargan las planillas de control diarias del mes de septiembre que contienen:
  * día (1 a 30) Ingresar y validar rango por función.
  * número de unidad (1 a 999) Función c/parámetros que solo ingrese y valide rango.
  * kms recorridos (mayor a cero)
Las planillas vienen desordenadas y la carga termina con un día 0.
Si el número de mensajero no existe se informa y se descarta la planilla sin ingresar Kms.

Se pide:
  1. Actualizar los kms recorridos de cada unidad ingresada.
  2. Listar por cada mensajero su tipo de vehículo su número y los kms recorridos cada día ordenado ascendente por función por
    número de mensajero (No se requiere definir la función ordenamiento, aunque sí prototiparla e invocarla).
******************************************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct{
  int dia;
  int mes;
  int anio;
} Fecha;

typedef struct{
  int codigo;
  char tipo[16];
  int km;
  Fecha fecha;
} Mensajero;

void inicializarStruct(Mensajero[], int); 
void cargaMensajero(Mensajero[], int);
void cargarKm(Mensajero[], int[][30], int, int);
int validacionDia(int, int);
int esBisiesto(int);
int validacionRangoFin(int, int, int);
int validacionRango(int, int);
int validacionLimite(int);
void validacionPalabra();
void ordenarDatos(Mensajero[], int);
void mostrarListado(Mensajero[], int[][30], int, int);

int main(){
  Mensajero vMens[100];
  int matrizKm[100][30] = {{0}};
  int ingresos = 0;
  char nombreApellido[31];

  printf("Ingrese su nombre y apellido: ");


  inicializarStruct(vMens, 100);
  cargaMensajero(vMens, 100);
  if(ingresos){

    ordenarDatos(vMens, ingresos);
    
  }else{
    printf("\nNo hubieron ingresos.");
  }

  return 0;
}

void inicializarStruct(Mensajero vec[], int ce){
  int i;

  for(i = 0; i < ce; i++){
    vec[i].codigo = 0;
    strcpy(vec[i].tipo, "");
    vec[i].km = 0;
    vec[i].fecha.dia = 31;
    vec[i].fecha.mes = 8;
    vec[i].fecha.anio = 2024;
  }
}

int validacionDia(int mes, int anio){
  int diaVal;

  switch(mes){
    case 1: case 3: case 5: case 7: case 8: case 10: case 12:
      diaVal = 31;
      break;
    case 4: case 6: case 9: case 11:
      diaVal = 30;
      break;
    case 2:
      esBisiesto()? diaVal = 29 : diaVal = 28;
      break;
  }

  return diaVal;
}

int esBisiesto(int anio){
  int bis;

  if((anio % 100 == 0 || anio % 4 == 0) && anio % 400 == 0){
    bis = 1;
  }else{
    bis = 0;
  }

  return bis;
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

void validacionPalabra(){
  char nombre[16];  

  scanf("%s", nombre);
  ultimo = strlen(nombre) - 1;
  if(nombre[ultimo] == '\n') nombre[ultimo] == '\0';
  for(i = 0; i < ultimo; i++)
    nombre[i] = toupper(nombre[i]);
}