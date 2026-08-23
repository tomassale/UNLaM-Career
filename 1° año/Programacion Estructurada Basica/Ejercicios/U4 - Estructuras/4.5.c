/************************************************************************************************************************
De una persona se conoce los siguientes datos:
  • Número de Legajo (int, entre 1 y 10.000)
  • Apellido (string, 15 caracteres)
  • Nombre (string, 15 caracteres)
  • Altura (float, mayor de 0)
  • Sexo (char, F o M)
  • Día de Nacimiento (int, entre 1 y 31
  • Mes de Nacimiento (int, ente 1 y 12)
  • Año de Nacimiento (int, ente 1950 y 2019)
Se solicita realizar los siguientes procesos:
  a. Con datos ingresados por teclado: Crear una Estructura de Datos con los datos enunciados
  anteriormente y llamarla PERSONA. X
  b. Mostrar los datos de la Estructura de Datos del punto a.
  c. Con datos ingresados por teclado: Modificar la Estructura de Datos del punto a., crear una Estructura
  de Datos que contenga Nombre y Apellido y otra Estructura de Datos que contenga Día/Mes/Año
  utilizarla en una nueva Estructurad de Datos llamada PERSONA2. X
  d. Mostrar los datos de la Estructura de Datos del punto c.
  e. Crear una FUNCION que cargue los datos de la Estructurad de Datos del punto c y que retorne los datos
  al programa principal (main).
  f. Con datos ingresados por teclado: Modificar la Estructurad de Datos llamada PERSONA2 del punto c.
  y agregarle un campo/miembro que contenga los códigos de las Materias Aprobadas (pueden llegar a
  ser hasta 36 materias) y llamarla PERSONA3.
  g. Crear una FUNCION que realice el punto f.
  h. Mostrar los datos de la Lista creada en el punto f.
  i. Crear una FUNCION que realice el punto h.
************************************************************************************************************************/

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
  char nombre[16];
  char apellido[16];
} Datos;

typedef struct{
  int legajo;
  float altura;
  char sexo;
  Datos datos;
  Fecha fecha;
  int codigosAprobados[36];
} Persona;

void inicializarStruct(Persona[], int);
int cargarDatos(Persona[], int);
int esBisiesto(int);
int validacionDia(int, int);
int validacionRango(int, int);
float validacionLimite(float);
char validacionLetra();
void validacionPalabra(char[], int);
int buscarCodigo(Persona[], int, int);
void mostrarDatos(Persona[], int);

int main() {
  Persona vPer[10000];
  int ingresos = 0;

  inicializarStruct(vPer, 10000);
  ingresos = cargarDatos(vPer, 10000);
  if(ingresos != 0)
    mostrarDatos(vPer, ingresos);
  else
    printf("\nNo hubieron ingresos");

  return 0;
}

void inicializarStruct(Persona vec[], int ce){
  int i, j;

  for(i = 0; i < ce; i++){
    vec[i].legajo = 0;
    vec[i].altura = 0.0;
    vec[i].sexo = '\0';
    strcpy(vec[i].datos.nombre, "");
    strcpy(vec[i].datos.apellido, "");
    vec[i].fecha.dia = 0;
    vec[i].fecha.mes = 0;
    vec[i].fecha.anio = 0;
    for(j = 0; j < 36; j++){
      vec[i].codigosAprobados[j] = 0;
    }
  }
}

int esBisiesto(int anio){
  int band;

  if((anio % 4 == 0 && anio % 100 != 0) || anio % 400 == 0)
    band = 1;
  else
    band = 0;

  return band;
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
      diaVal = esBisiesto(anio)? 29 : 28;
      break;
  }

  return diaVal;
}

int validacionRango(int min, int max){
  int num;

  do{
    scanf("%d", &num);
  }while(num < min || num > max);
  getchar();

  return num;
}

float validacionLimite(float min){
  float num;

  do{
    scanf("%f", &num);
  }while(num <= min);
  getchar();

  return num;
}

char validacionLetra(){
  char letra;

  do{
    scanf("%c", &letra);
    letra = toupper(letra);
  }while(letra != 'M' && letra != 'F');
  getchar();

  return letra;
}

void validacionPalabra(char texto[], int ce){
  int ultimo, i;

  scanf("%s", texto);
  ultimo = strlen(texto);
  for(i = 0; i < ultimo; i++)
    texto[i] = tolower(texto[i]);
}

int buscarCodigo(Persona vec[], int num, int ce){
  int i = 0, pos = -1;

  while(i < ce && pos == -1){
    if(vec[i].legajo == num)
      pos = i;
    else
      i++;
  }

  return pos;
}

int cargarDatos(Persona vec[], int ce){
  int i = 0,  j, legajo = -1, pos, codigosAp, dia, mes, anio, diaVal;
  float altura;
  char sexo, nom[16], apell[16];

  while(legajo != 0 && i < ce){
    do{
      printf("Ingrese el numero de legajo (1 a 10000)[0 para fin]: ");
      legajo = validacionRango(0, 10000);
      pos = buscarCodigo(vec, legajo, i);
    }while(pos != -1 && legajo != 0);
    if(legajo != 0){

      printf("Ingrese la altura (mayor a 0): ");
      altura = validacionLimite(0);

      printf("Ingrese el sexo: ");
      sexo = validacionLetra();

      printf("Ingrese el nombre: ");
      validacionPalabra(nom, 16);

      printf("Ingrese el apellido: ");
      validacionPalabra(apell, 16);

      printf("Ingrese el anio: ");
      anio = validacionRango(1950, 2019);

      printf("Ingrese el mes: ");
      mes = validacionRango(1, 12);

      diaVal = validacionDia(mes, anio);
      printf("Ingrese el dia: ");
      dia = validacionRango(1, diaVal);

      j = 0;
      codigosAp = -1;

      while(j < 36 && codigosAp != 0){
        printf("Ingrese el codigo de materia aprobada: ");
        codigosAp = validacionRango(0, 2000);
        if(codigosAp != 0){
          vec[i].codigosAprobados[j] = codigosAp;
          j++;
        }
      }
      vec[i].legajo = legajo;
      vec[i].altura = altura;
      vec[i].sexo = sexo;
      strcpy(vec[i].datos.nombre, nom);
      strcpy(vec[i].datos.apellido, apell);
      vec[i].fecha.dia = dia;
      vec[i].fecha.mes = mes;
      vec[i].fecha.anio = anio;
      i++;
    }
  }
  return i;
}

void mostrarDatos(Persona vec[], int ce){
  int i, j;
  
  printf("\n\n=============== LISTADO DE PERSONAS ===============\n");
  for(i = 0; i < ce; i++){
      printf("\nLegajo: %d", vec[i].legajo);
      printf("\nNombre: %s %s", vec[i].datos.nombre, vec[i].datos.apellido);
      printf("\nSexo: %c | Altura: %.2f", vec[i].sexo, vec[i].altura);
      printf("\nFecha Nac: %02d/%02d/%d", vec[i].fecha.dia, vec[i].fecha.mes, vec[i].fecha.anio);
      
      printf("\nMaterias aprobadas: ");
      j = 0;
      while(j < 36 && vec[i].codigosAprobados[j] != 0){
        printf("%d, ", vec[i].codigosAprobados[j]);
        j++;
      }
      printf("\n---------------------------------------------------\n");
  }
}