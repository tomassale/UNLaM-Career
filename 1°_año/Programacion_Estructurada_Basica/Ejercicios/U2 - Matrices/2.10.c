/************************************************************************************************************************
Realizar el juego de Tatetí para dos jugadores. EL jugador 1 utilizará la letra X y el jugador 2 la letra O para
marcar sus elecciones. El tablero armarlo con una matriz de 3x3 que debe ser visualizada en pantalla en cada
jugada marcando la ubicación elegida por cada jugador. Luego de cada jugada se debe llamar a una función
para verificar si el jugador ganó o no la partida. Si se llega a la última jugada y nadie gana, se debe informar
del empate.

Complemento: Modificar el juego para que sea de un solo jugador. Deberá programar la inteligencia
artificial para que la computadora elija donde realizar la jugada para intentar ganar la partida y no perder
completando el espacio correspondiente cuando haga falta.
************************************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>

int cargaDatos(char[][3], int, int, char);
int datoValido(int, int);
int evaluarCondicion(char[][3], int, int);
void mostrarResultado(int);
void mostrarMatriz(char[][3], int, int);
//void inteligenciaArtificial(char[][3], int, int);

int main() {
  char matriz[3][3] = {{'\0'}};
  int ganador = 0;
  int jugadas = 0;
  char turno = 'X';

  while (ganador == 0 && jugadas < 9) {
      ganador = cargaDatos(matriz, 3, 3, turno);
      jugadas++;

      if (turno == 'X') 
          turno = 'O';
      else 
          turno = 'X';
      
  }

  mostrarMatriz(matriz, 3, 3);

  if (ganador != 0) {
      printf("\n¡El ganador es el Jugador %d!\n", ganador);
  } else {
      printf("\n¡Es un empate!\n");
  }
  
  return 0;
}

int cargaDatos(char matriz[][3], int cf, int cc, char turno) {
  int x, y, cond;

  mostrarMatriz(matriz, 3, 3);
  printf("\nTurno del jugador %c\n", turno);

  do {
      printf("Ingrese la posicion de fila (1 a 3): ");
      x = datoValido(1, 3);
      printf("Ingrese la posicion de columna (1 a 3): ");
      y = datoValido(1, 3);
      
      if (matriz[x-1][y-1] != '\0') {
          printf("¡Esa posicion ya esta ocupada! Intenta de nuevo.\n");
      }
  } while (matriz[x-1][y-1] != '\0');

  matriz[x-1][y-1] = turno; 
  cond = evaluarCondicion(matriz, cf, cc);

  return cond;
}

int evaluarCondicion(char matriz[][3], int cf, int cc) {
  int i;
  int ganador = 0;

  for(i = 0; i < cf && ganador == 0; i++) {
    if(matriz[i][0] != '\0' && matriz[i][0] == matriz[i][1] && matriz[i][1] == matriz[i][2]) 
        ganador = (matriz[i][0] == 'X') ? 1 : 2;
    else if(matriz[0][i] != '\0' && matriz[0][i] == matriz[1][i] && matriz[1][i] == matriz[2][i]) 
        ganador = (matriz[0][i] == 'X') ? 1 : 2;
  }

  if(ganador == 0) {
    if(matriz[0][0] != '\0' && matriz[0][0] == matriz[1][1] && matriz[1][1] == matriz[2][2]) 
        ganador = (matriz[0][0] == 'X') ? 1 : 2;
    else if(matriz[0][2] != '\0' && matriz[0][2] == matriz[1][1] && matriz[1][1] == matriz[2][0]) {
        ganador = (matriz[0][2] == 'X') ? 1 : 2;
  }

  return ganador; 
}

int datoValido(int min, int max){
  int num;

  do{
    scanf("%d", &num);
  }while(num < min || num > max);

  return num;
}

void mostrarMatriz(char matriz[][3], int cf, int cc){
  int i, j;
  
  system("cls");
  system("clear");
  printf("\t\tTATETÍ\n");
  for(i = 0; i < cf; i++){
    for(j = 0; j < cc; j++){
      printf("\t%c", matriz[i][j]);
    }
    printf("\n\n");
  }
}

//void inteligenciaArtificial(char matriz[][3], int cf, int cc){int i, j;}
