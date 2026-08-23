/*******************************************************************************************************************
Una empresa de colectivos posee cerca de 400 unidades distribuidas en 3 tipos.
Por cada unidad se ingresa en único vector:
  * Número de unidad (1 a 999 no correlativo sin repetidos) (ingresado y validado por función)
  * Tipo línea a la que pertenece (“Municipal” “Provincial” “Nacional”) (ingresar sin validar)
  * Kilómetros recorridos (mayor a cero).
  * Fecha Ultima actualización (día mes año - en único campo)
La fecha es un dato fijo correspondiente a la fecha actual 16/5/2024
La carga concluye con una unidad número 0.

Seguidamente se cargan las planillas de control diarias del mes de abril que contienen:
  * día (1 a 30) Ingresar y validar rango por función
  * número de unidad (1 a 999) Ingresar y validar rango por función.
  * kms recorridos (mayor a cero)
las planillas vienen desordenadas y la carga termina con un día 0
Si el número de unidad no existe se informa y se descarta la planilla sin ingresar Kms.

Se pide:
1. Actualizar los kms recorridos de cada unidad ingresada.
2. Listar por cada unidad de tipo de línea Nacional su número y los kms recorridos cada día.
3. Copiar los datos actualizados a otro vector que contenga una estructura de dos campos siendo uno de ellos 
todos los datos del vector copiado y otro el nombre del operador de máximo 30 caracteres que se ingresa previamente 
por teclado (sin validar).
******************************************************************************************************************/
#include <string.h>
#include <stdio.h>

typedef struct{
  int dia;
  int mes;
  int anio;
} Fecha;

typedef struct{
  int codigo;
  char linea[11];
  int km;
  Fecha fecha;
} Colectivo;

typedef struct{
  Colectivo colectivo;
  char operador[31];
} Colectivero;

int cargaDatos(Colectivo[], int);
void cargaRecorrido(Colectivo[], int);

int validacionRango(int, int);
int validacionLimite(int);
int buscarCodigo(Colectivo[], int, int);
void inicializarStruct(Colectivo[], int);


void listarUnidad(Colectivo[], int);
void copiarDatos(Colectivo[], Colectivero[], int);

int main(){
  Colectivo vCol[400];
  Colectivero vCole[400];
  int ingresos = 0;

  inicializarStruct(vCol, 400);
  ingresos = cargaDatos(vCol, 400);
  if(ingresos > 0){
    cargaRecorrido(vCol, ingresos);
    listarUnidad(vCol, ingresos);
    copiarDatos(vCol, vCole, ingresos);
  }else{
    printf("No hubieron ingresos.");
  }

  return 0;
}

int cargaDatos(Colectivo vec[], int ce){
  int i = 0, codigo = -1, pos;
  char linea[11];

  while(i < ce && codigo != 0){
    do{
      printf("Ingrese el numero de linea (1 a 999)[0 para fin]: ");
      codigo = validacionRango(0, 999);
      pos = buscarCodigo(vec, codigo, i);
    }while(pos != -1 && codigo != 0);

    if(codigo != 0){
      printf("Ingrese el tipo de linea (Municipal, Provincial o Nacional): ");
      scanf("%s", linea);

      printf("Ingrese la cantidad de km que tiene la unidad (mayor a 0): ");
      vec[i].km = validacionLimite(0);

      vec[i].codigo = codigo;
      strcpy(vec[i].linea, linea);
      i++;
    }
  }
  return i;
}

void cargaRecorrido(Colectivo vec[], int ce){
  int codigo = -1, dia, km, pos;

  while(dia != 0){
    printf("Ingrese el dia (1 a 30)[0 para fin]: ");
    dia = validacionRango(0, 30);

    if(dia != 0){
      printf("Ingrese el codigo: ");
      codigo = validacionRango(1, 999);
      pos = buscarCodigo(vec, codigo, ce);
  
      if(pos != -1){
        printf("Ingrese la cantidad de kilometros recorridos (mayor a 0): ");
        km = validacionLimite(0);
  
        vec[pos].km += km;
      }else{
        printf("Planilla descartada.");
      }
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

int validacionLimite(int min){
  int num;

  do{
    scanf("%d", &num);
  }while(num < min);

  return num;
}

int buscarCodigo(Colectivo vec[], int num, int ce){
  int i = 0, pos = -1;

  while(i < ce && pos == -1){
    if(vec[i].codigo == num)
      pos = i;
    else
      i++;
  }

  return pos;
}

void inicializarStruct(Colectivo vec[], int ce){
  int i;

  for(i = 0; i < ce; i++){
    vec[i].codigo = 0;
    strcpy(vec[i].linea, " ");
    vec[i].km = 0;
    vec[i].fecha.dia = 16;
    vec[i].fecha.mes = 5;
    vec[i].fecha.anio = 2024;
  }
}

void listarUnidad(Colectivo vec[], int ce){
  int i;

  printf("\n\t\tLISTADO DE UNIDADES");
  printf("\nLINEA | NUMERO | KILOMETROS");
  for(i = 0; i < ce; i++){
    if(strcmp(vec[i].linea, "Nacional") == 0)
      printf("\n%s %d \t%d", vec[i].linea, vec[i].codigo, vec[i].km);
  }
  printf("\n");
}

void copiarDatos(Colectivo vec[], Colectivero vecC[], int ce){
  int i;
  char nombre[31];

  for(i = 0; i < 400; i++){
    if(i < ce){
      printf("Ingrese el nombre del chofer: ");
      scanf("%s", nombre);
      strcpy(vecC[i].operador, nombre);
    }

    vecC[i].colectivo = vec[i];
  }
}