/************************************************************************************************************************
Tomando como base el archivo ALUMNOS.DAT creado en el ejercicio anterior se desea desarrollar un
programa que, basado en la información del archivo, genere 3 archivos:
  • Uno con los alumnos PROMOCIONADOS (ambas notas mayores o igual a 7).
  • Otro archivo con los alumnos en condición CURSADO (ambas notas mayores o igual a 4 pero no
  promocionados).
  • Y un tercer archivo con los REPROBADOS (al menos una nota, menor que 4).
Para comprobar los datos guardados realizar una función que reciba por parámetro el nombre del archivo
a mostrar, lo abre y muestre su contenido. Se debe invocar a la función 3 veces para mostrar todos los
archivos generados.
************************************************************************************************************************/
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int dni;
    char nombre[81];
    int nota1;
    int nota2;
    float notaProm;
}Alumno;

void separarAlumnos(FILE *pf, FILE *pfReprobados, FILE *pfCursado, FILE *pfPromocionados);
void mostrarArchivo(char[]);

int main(){
  FILE *pf, *pfReprobados, *pfCursado, *pfPromocionados;

  pf = fopen("ALUMNOS.dat", "rb");
  pfReprobados = fopen("REPROBADOS.dat", "w+b");
  pfCursado = fopen("CURSADO.dat", "w+b");
  pfPromocionados = fopen("PROMOCIONADOS.dat", "w+b");
  if(pf == NULL || pfReprobados == NULL || pfCursado == NULL || pfPromocionados == NULL){
    printf("Error al abrir el archivo...");
    getch();
    exit(1);
  }

  separarAlumnos(pf, pfReprobados, pfCursado, pfPromocionados);
  fclose(pf);
  fclose(pfReprobados);
  fclose(pfCursado);
  fclose(pfPromocionados);

  printf("\n\t\t\t\tRESULTADOS ARCHIVOS\n");
  mostrarArchivo("REPROBADOS.dat");
  mostrarArchivo("CURSADO.dat");
  mostrarArchivo("PROMOCIONADOS.dat");

  return 0;
}

void separarAlumnos(FILE *pf, FILE *pfReprobados, FILE *pfCursado, FILE *pfPromocionados){
  Alumno alum;

  fread(&alum, sizeof(Alumno), 1, pf);

  while(!feof(pf)){
    if(alum.nota1 < 4 || alum.nota2 < 4){
      fwrite(&alum, sizeof(Alumno), 1, pfReprobados);
    }else if(alum.nota1 >= 7 && alum.nota2 >= 7){
      fwrite(&alum, sizeof(Alumno), 1, pfPromocionados);
    }else{
      fwrite(&alum, sizeof(Alumno), 1, pfCursado);
    }
    fread(&alum, sizeof(Alumno), 1, pf);
  }
}

void mostrarArchivo(char nombreArchivo[]){
  FILE *pf;
  Alumno alum;

  pf = fopen(nombreArchivo, "rb");

  if(pf == NULL){
    printf("Error al abrir el archivo...");
    getch();
    exit(1);
  }

  printf("\n\n\t\t\tARCHIVO %s\n", nombreArchivo);
  fread(&alum, sizeof(Alumno), 1, pf);
  while(!feof(pf)){
    printf("\nDNI: %8d | NOMBRE: %20s | NOTA 1: %d | NOTA 2: %2d | PROMEDIO: %.2f", alum.dni, alum.nombre, alum.nota1, alum.nota2, alum.notaProm);
    fread(&alum, sizeof(Alumno), 1, pf);
  }

  fclose(pf);
}
