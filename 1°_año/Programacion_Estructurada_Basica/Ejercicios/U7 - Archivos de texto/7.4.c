/*******************************************************************************************************************************
Realizar un programa que permita buscar un contacto en el archivo de agenda generado en punto anterior, por apellido o nombre y
mostrar el / los datos coincidentes si los hay
*******************************************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
  char nombre[16];
  char apellido[16];
  char correo[31];
  char telefono[19];
} Agendado;

void ingresarDatos(FILE *pf);
void buscarDatos(FILE *pf, char[], char[]);

int main(){
  FILE *pf;

  pf = fopen("AGENDA.txt", "rt");

  if(pf == NULL){
    printf("Error al abrir la agenda...");
    exit(1);
  }

  ingresarDatos(pf);

  return 0;
}

void ingresarDatos(FILE *pf){
  char nombre[16];
  char apellido[16];

  printf("Ingrese un nombre: ");
  scanf("%s", nombre);

  printf("Ingrese su apellido: ");
  scanf("%s", apellido);

  while(strcmp(nombre, "FINALIZAR") != 0 || strcmp(apellido, "FINALIZAR") != 0){
    buscarDatos(pf, nombre, apellido);

    printf("Ingrese un nombre: ");
    scanf("%s", nombre);

    printf("Ingrese su apellido: ");
    scanf("%s", apellido);
  }
}

void buscarDatos(FILE *pf, char nombre[], char apellido[]){
  Agendado ag;
  int encontrado = 0;

  rewind(pf);
  fread(&ag, sizeof(ag), 1, pf);
  while(!feof(pf)){
    if(strcmp(nombre, ag.nombre) == 0 || strcmp(apellido, ag.apellido) == 0){
      fscanf(pf, "\nNombre: %s | Apellido: %s | Correo: %s | Telefono: %s", ag.nombre, ag.apellido, ag.correo, ag.telefono);
      encontrado = 1;
    }
    fread(&ag, sizeof(ag), 1, pf);
  }

  if(!encontrado) printf("Dato no encontrado\n");
}