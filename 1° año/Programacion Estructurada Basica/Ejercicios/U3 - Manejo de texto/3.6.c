/************************************************************************************************************************
Realizar el juego del ahorcado. Primero se debe ingresar la palabra a adivinar de hasta 10 caracteres. Luego
se muestra por cada letra un guion bajo para que el jugador sepa la cantidad de letras a adivinar. Se irá
ingresando una a una las letras y si estas se encuentran en la palabra las deberá ir mostrando en el lugar
correspondiente. Por cada letra que no se encuentre en la palabra perderá una vida. El jugador dispondrá de
5 vidas para intentar ganar el juego.
Complemento:
  • Ir completando el dibujo del muñeco del ahorcado cada vez que se comete un error.
************************************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void ingresoPalabra(char[]);
int buscarLetras(char[], char[], char, int);
void mostrarVacio(char[], int);
void mostrarGuiones(char[]);
void mostrarResultado(char[], char[], int);

int main(){
  char palabra[12];
  char mostrado[12];
  char letra;
  int vidas = 5, encontrado = 0, restar, medida;

  ingresoPalabra(palabra);
  medida = strlen(palabra);
  mostrarVacio(mostrado, medida);
  while(vidas > 0 && encontrado == 0){
    mostrarGuiones(mostrado);
    printf("VIDAS RESTANTES: %d", vidas);
    
    printf("\nIngrese una letra: ");
    scanf("%c", &letra);
    getchar();
    restar = buscarLetras(palabra, mostrado, letra, medida);
    if(restar == 0) vidas--;
    if(strcmp(mostrado, palabra) == 0) encontrado = 1;
  }

  mostrarResultado(palabra, mostrado, vidas);

  return 0;
}

void ingresoPalabra(char palabra[]){
  int ultimo;
    
  printf("Ingrese la palabra (hasta 10 caracteres): ");
  fgets(palabra, 12, stdin);
  ultimo = strlen(palabra) - 1;
  if(palabra[ultimo] == '\n') palabra[ultimo] = '\0';
}

int buscarLetras(char palabra[], char encontrado[], char letra, int medida){
  int band = 0, i;

  for(i = 0; i < medida; i++){
    if(palabra[i] == letra){
      encontrado[i] = letra;
      band = 1;
    }
  }

  return band;
}

void mostrarGuiones(char encontrado[]){
  system("cls");
  system("clear");
  printf("\t%s", encontrado);
  printf("\n");
}

void mostrarVacio(char encontrado[], int medida){
  int i;

  for(i = 0; i < medida; i++){
    encontrado[i] = '_';
  }
  encontrado[medida] = '\0';
}

void mostrarResultado(char palabra[], char encontrado[], int vidas){
  system("cls");
  system("clear");
  if(vidas == 0){
    printf("\nPERDISTE, te quedaste sin vidas!!!");
    printf("\nPalabra a buscar: %s", palabra);
    printf("\nResultado: %s", encontrado);
  }else{
    printf("\nGANASTE, encontraste la palabra");
    printf("\nPalabra: %s\nVidas: %d", palabra, vidas);
  }
}