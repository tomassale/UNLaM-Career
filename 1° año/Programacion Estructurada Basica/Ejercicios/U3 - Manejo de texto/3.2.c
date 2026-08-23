/************************************************************************************************************************
Ingresar dos Strings, uno con el nombre y el otro con el apellido de una persona. Utilizando las funciones de
la biblioteca string.h generar un tercer string formado por: NOMBRE, APELLIDO (nombre coma espacio y
apellido) y mostrarlo
************************************************************************************************************************/

#include <stdio.h>
#include <string.h>

void ingresoDatos(char[], char[], char[]);
void concatenar(char[], char[], char[]);
void acomodar(char[]);

int main(){
  char texto[41];
  char nombre[11];
  char apellido[11];

  ingresoDatos(texto, nombre, apellido);

  printf("\nLos datos son: %s.", texto);

  return 0;
}

void ingresoDatos(char texto[], char nombre[], char apellido[]){
  printf("Ingrese el nombre: ");
  fgets(nombre, 11, stdin);
  acomodar(nombre);
  printf("Ingrese el apellido: ");
  fgets(apellido, 11, stdin);
  acomodar(apellido);

  concatenar(texto, nombre, apellido);
}


void concatenar(char texto[], char nombre[], char apellido[]){
  strcpy(texto, nombre);
  strcat(texto, ", ");    
  strcat(texto, apellido);
}

void acomodar(char texto[]){
  int largo = strlen(texto) - 1;
  
  if(texto[largo]=='\n')
    texto[largo] = '\0';
}