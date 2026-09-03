/**********************************************************************************************************************************
Realizar un programa que genere un archivo llamado “agenda.txt” en el cual se almacene los siguientes datos ingresados por teclado:
  • Apellido
  • Nombre
  • Correo electrónico
  • Teléfono
El ingreso se datos finaliza con apellido y nombre igual a “FINALIZAR”. Utilice el separador ; (punto y coma) entre campos.
**********************************************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char nombre[16];
    char apellido[16];
    char correo[31];
    char telefono[19];
} Agenda;

void ingresarDatos(FILE *pf, Agenda ag);

int main(){
  Agenda ag;
  FILE *pf;

  pf = fopen("AGENDA.txt", "wt");

  if(pf == NULL){
      printf("Error al abrir agenda.txt...");
      exit(1);
  }

  ingresarDatos(pf, ag);

  fclose(pf);
  return 0;
}

void ingresarDatos(FILE *pf, Agenda ag){

  int ultimo;

  printf("Ingrese el nombre: ");
  scanf("%s", ag.nombre);

  printf("Ingrese el apellido: ");
  scanf("%s", ag.apellido);

  while(strcmp(ag.nombre, "FINALIZAR") != 0 || strcmp(ag.apellido, "FINALIZAR") != 0){
    printf("Ingrese el correo: ");
    scanf("%s", ag.correo);

    fflush(stdin);

    printf("Ingrese el telefono: ");
    fgets(ag.telefono,19,stdin);
    ultimo = strlen(ag.telefono) - 1;
    if(ag.telefono[ultimo] == '\n') ag.telefono[ultimo] = '\0';

    fprintf(pf, "%s;%s;%s;%s\n", ag.nombre, ag.apellido, ag.correo, ag.telefono);

    fflush(stdin);

    printf("Ingrese el nombre: ");
    scanf("%s", ag.nombre);

    printf("Ingrese el apellido: ");
    scanf("%s", ag.apellido);
  }
}
