/************************************************************************************************************************
Realizar un programa que permite actualizar una lista de precios en forma masiva, ingresando un porcentaje
de incremento. El archivo se llama precios.dat y fue generado utilizando la siguiente estructura:
  • Código (entero)
  • Precio (float)
  • Descripción (de hasta 50 caracteres)
************************************************************************************************************************/
#include <stdio.h>
#include <stdlib.h>

typedef struct{
  int codigo;
  float precio;
  char descripcion[51];
} Precios;

void leerArchivo(FILE *pf);
void aumentarPrecios(FILE *pf, float);
void ingresoDatos(FILE *pf);

int main(){

  FILE *pf;

  pf = fopen("PRECIOS.dat", "r+b");

  if(pf == NULL){
    printf("Error al abrir el archivo...");
    exit(1);
  }

  leerArchivo(pf);
  ingresoDatos(pf);

  fclose(pf);
  return 0;
}

void leerArchivo(FILE *pf){
  int i = 0;
  Precios pr;

  rewind(pf);
  fread(&pr, sizeof(Precios), 1, pf);
  while(!feof(pf)){
    printf("Codigo: %8d | Precio: %8.2f | Descripcion: %29s\n", pr.codigo, pr.precio, pr.descripcion);
    fread(&pr, sizeof(Precios), 1, pf);
  }
}

void ingresoDatos(FILE *pf){
  float porcentaje;

  printf("Ingrese el aumento de porcentaje: ");
  scanf("%f", &porcentaje);
  while(porcentaje > 0){
    aumentarPrecios(pf, porcentaje);
    leerArchivo(pf);
    printf("Ingrese el aumento de porcentaje: ");
    scanf("%f", &porcentaje);
  }
}

void aumentarPrecios(FILE *pf, float aumentos){
  float incremento;
  Precios pr;

  rewind(pf);
  fread(&pr, sizeof(Precios), 1, pf);
  while(!feof(pf)){
    pr.precio += (pr.precio * aumentos) / 100;
    fseek(pf, -1*sizeof(Precios), SEEK_CUR);
    fwrite(&pr, sizeof(Precios), 1, pf);
    fflush(pf);
    fread(&pr, sizeof(Precios), 1, pf);
  }
}