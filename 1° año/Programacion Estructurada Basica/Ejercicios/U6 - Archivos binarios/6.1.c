/************************************************************************************************************************
Los datos de los alumnos de una comisión de Computación Transversal son:
  • Número de DNI (entero)
  • Nombre y Apellido (80 caracteres)
  • Nota1, Nota2 (entero)
  • Nota Promedio (real, calculado según Nota1 y Nota2)

  a. Declarar un tipo de dato que contenga la información del alumno.
  b. Con la información indicada para los alumnos. Grabar los datos en el archivo “ALUMNOS.dat”. Esta
  información de grabación finaliza con DNI cero.
  c. Leer los datos del archivo, mediante la Función LECTURA.
************************************************************************************************************************/
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  int dni;
  char nombre[81];
  int nota1;
  int nota2;
  float notaProm;
}alumno;

void LECTURA(FILE *fp);
void INGRESO(FILE *fp);
int validacionInt(int, int);
void validacionTexto(char[], int);

int main(){
  alumno vec;
  FILE *fp;

  fp = fopen("ALUMNOS.dat", "w+b");
  if(fp == NULL){
    printf("ERROR al abrir el archivo de ventas");
    getch();
    exit(1);
  }

  INGRESO(fp);
  rewind(fp);
  LECTURA(fp);
  fclose(fp);
  return 0;
}

void INGRESO(FILE *fp){
  alumno al;

  printf("Ingrese el dni de la persona [0 para fin]: ");
  scanf("%d", &al.dni);

  while(al.dni != 0){
    getchar();
    printf("Ingrese el nombre y apellido: ");
    validacionTexto(al.nombre, 81);

    printf("Ingrese la nota 1 (1 a 10): ");
    al.nota1 = validacionInt(1, 10);

    printf("Ingrese la nota 2 (1 a 10): ");
    al.nota2 = validacionInt(1, 10);

    al.notaProm = (float)(al.nota1 + al.nota2) / 2;

    fwrite(&al, sizeof(alumno), 1, fp);

    printf("Ingrese el dni de la persona [0 para fin]:");
    scanf("%d", &al.dni);

  }
}

void LECTURA(FILE *fp){
  alumno al;

  printf("\n\t\tLISTADO DE ALUMNOS\n");
  fread(&al, sizeof(alumno), 1, fp);
  while(!feof(fp)){
    printf("DNI: %8d | Nombre: %20s | Notas: %2d, %2d | Promedio: %.2f\n", al.dni, al.nombre, al.nota1, al.nota2, al.notaProm);
    fread(&al, sizeof(alumno), 1, fp);
  }
}

int validacionInt(int min, int max){
  int num;

  do{
    scanf("%d", &num);
  }while(num < min || num > max);

  return num;
}

void validacionTexto(char nombre[], int medida){
  int i = 0;

  fgets(nombre, medida, stdin);
  while(nombre[i]!='\0'){
    if(nombre[i] == '\n')
      nombre[i]='\0';
    else
      i++;
  }
}
