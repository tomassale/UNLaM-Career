/************************************************************************************************************************
Ingresar una frase de hasta 500 caracteres y contar cuántas palabras contiene dicha frase.
  a. Considerar que las palabras están separadas por un único espacio.
  b. Considerar que las palabras pueden estar separadas por más de un espacio consecutivo.
************************************************************************************************************************/

#include <stdio.h>
#include <string.h>

void ingresoTexto(char[]);
int medirAcomodar(char[]);
int contarPalabras(char[], int);

int main() {
  char frases[501]; 
  int medida, contador;

  ingresoTexto(frases);
  medida = medirAcomodar(frases);
  contador = contarPalabras(frases, medida);

  puts(frases);
  printf("\nHay en total %d palabras", contador);

  return 0;
}

void ingresoTexto(char frases[]){
  printf("Ingrese las frases: ");
  fgets(frases, 501, stdin);
}

int medirAcomodar(char frases[]){
  int largo;

  largo = strlen(frases) - 1;

  if(frases[largo]=='\n')
    frases[largo] = '\0';

  return largo;
}

int contarPalabras(char frases[], int largo){

  int contPalabras = 0, i;

  for(i = 0; i < largo; i++)
    if(frases[i] != ' ' && (frases[i+1] == ' ' || frases[i+1] == '\0'))
      contPalabras++;

  return contPalabras;
}