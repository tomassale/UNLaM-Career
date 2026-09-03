/************************************************************************************************************************
Se sabe que como máximo en una comisión de Elementos de Programación hay 80 alumnos. De cada
alumno se conoce:
  • Número de DNI (entero).
  • Apellido y Nombre (80 caracteres).
  • Nota1, Nota2 (entero).
  • Nota Promedio (real, calculado según Nota1 y Nota2).
Se solicita:
  a. Declarar un tipo de dato que contenga la información del alumno.
  b. Declarar un vector de estructuras del tipo de dato creado en el punto a.
  c. Cargar en un vector de estructuras, los datos referentes a los alumnos de la comisión, esta
  información termina con DNI igual al 0. Función INGRESO.
  d. Indicar cuántos alumnos aprobaron (ambos parciales con nota >= 4 y cuántos reprobaron la
  materia. Función RESULTADO.
  e. Informar los datos de los alumnos de (DNI – Apellido y Nombre – Nota Promedio) de los alumnos.
  PROMOCIONADOS (ambas notas >= 7). Función INFORME_PROMO
************************************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

typedef struct{
  int dni;
  char apellidoNombre[81];
  int nota1;
  int nota2;
  float promedio;
} Alumno;

int buscaCodigo(Alumno[], int, int);
void pasarMayuscula(char[], int);
void inicializarStruct(Alumno[], int);
int INGRESO(Alumno[], int);
void RESULTADO(Alumno[], int);
void INFORME_PROMO(Alumno[], int);

int main(){
  Alumno vAlum[80];
  int ingreso = 0;

  inicializarStruct(vAlum, 80);
  ingreso = INGRESO(vAlum, 80);
  if(ingreso > 0){
    RESULTADO(vAlum, ingreso);
    INFORME_PROMO(vAlum, ingreso);
  }else{
    printf("\nNo hubieron ingresos en el periodo");
  }

  return 0;
}

void inicializarStruct(Alumno alum[], int ce){
  int i;

  for(i = 0; i < ce; i++){
    alum[i].dni = 0;
    strcpy(alum[i].apellidoNombre, "\0");
    alum[i].nota1 = 0;
    alum[i].nota2 = 0;
    alum[i].promedio = 0;
  }
}

int buscaCodigo(Alumno alum[], int num, int ce){
  int i = 0, pos = -1;

  while(i < ce && pos == -1){
    if(alum[i].dni == num)
      pos = i;
    else
      i++;
  }

  return pos;
}

void pasarMayuscula(char dato[], int medida){
  int i;

  for(i = 0; i < medida; i++){
    dato[i] = toupper(dato[i]);
  }
}

int INGRESO(Alumno alum[], int ce){
  int i = 0, dni = -1, nota1, nota2, medida, pos;
  float promedio;
  char apellNom[81];

  while(dni != 0 && i < ce){
    do{
      printf("Ingrese el dni del alumno: ");
      scanf("%d", &dni);
      pos = buscaCodigo(alum, dni, i);
    }while(dni < 0 || pos != -1);
    
    if(dni != 0){
      getchar();
      printf("Ingrese apellido y nombre: ");
      fgets(apellNom, 81, stdin);
      medida = strlen(apellNom) - 1;
      if(apellNom[medida] == '\n') apellNom[medida] = '\0';
      pasarMayuscula(apellNom, medida);

      do{
        printf("Ingrese la primero nota del alumno: ");
        scanf("%d", &nota1);
      }while(nota1 < 1 || nota1 > 10);


      do{
        printf("Ingrese la segunda nota del alumno: ");
        scanf("%d", &nota2);
      }while(nota2 < 1 || nota2 > 10);
      

      promedio = (float) (nota1 + nota2) / 2;

      alum[i].dni = dni;
      strcpy(alum[i].apellidoNombre, apellNom);
      alum[i].nota1 = nota1;
      alum[i].nota2 = nota2;
      alum[i].promedio = promedio;
      i++;
    }

  }
  return i;
}


void RESULTADO(Alumno alum[], int ce){
  int i, contApr = 0, contDesap = 0;

  for(i = 0; i < ce; i++){
    if(alum[i].nota1 != 0)
      if(alum[i].nota1 < 4 || alum[i].nota2 < 4)
        contDesap++;
      else
        contApr++;
  }

  printf("\n%d alumnos aprobaron.", contApr);
  printf("\n%d alumnos desaprobaron.", contDesap);
}

void INFORME_PROMO(Alumno alum[], int ce){
  int i;

  printf("\n\t\tDNI\tAPELLIDO Y NOMBRE\tNOTA PROMEDIO");
  for(i = 0; i < ce; i++){
    if((alum[i].nota1 >= 7 && alum[i].nota2 >= 7) && alum[i].nota1 != 0)
      printf("\n\t%8d\t\t%s\t\t%.1f", alum[i].dni, alum[i].apellidoNombre, alum[i].promedio);
  }
}