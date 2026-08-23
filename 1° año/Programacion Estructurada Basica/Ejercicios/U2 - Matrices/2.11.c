/************************************************************************************************************************
Realizar el juego del rompecabezas de 8, dicho juego comienza con una matriz de 3x3 de números del 1
al 8 desordenados y un espacio en blanco. Como, por ejemplo:
                                VER FORMATO EN ARCHIVO
El objetivo del juego es lograr que los números queden ordenados de la siguiente forma:
                                VER FORMATO EN ARCHIVO
Para ello, el jugador puede mover un número a la vez al casillero libre, solo puedo mover alguno de los
números adyacentes al casillero en blando y solo en forma horizontal o vertical. Por ejemplo, tomando
como partida la primera matriz desordenada se podría mover el 6 hacia abajo, el 4 hacia la izquierda o el
8 hacia la derecha.

El jugador deberá ingresar el número que quiere mover y automáticamente moverlo, si es posible, al
casillero libre. Luego cada movimiento se debe controlar si se llega al objetivo de ordenar los números e
informar que se ha ganado la partida. Puede ir contando la cantidad de movimientos que se llevó al
jugador lograr llegar a ordenar el rompecabezas y mostrarlos al finalizar para que pueda volver a jugarlo
y superarse.

Complemento: Puede agregar al ejercicio anterior distintos niveles para ir aumentando el nivel de
complejidad partiendo de distintas matrices desordenadas. Los primeros niveles pueden ser matrices
parcialmente desordenadas y luego a medida que avanza de nivel ir jugando con distintas matrices de
inicio.
************************************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>

void mostrarTablero(int matriz[][3]);
int verificarGanador(int matriz[][3]);
int moverFicha(int matriz[][3], int ficha);

int main() {
    
    int tablero[3][3] = {
        {1, 2, 3},
        {4, 5, 0}, 
        {7, 8, 6}
    };
    
    int fichaAJugar;
    int movimientos = 0;
    
    while (verificarGanador(tablero) == 0) {
        mostrarTablero(tablero);
        
        printf("Movimientos: %d\n", movimientos);
        printf("Ingrese el numero que desea mover (1-8): ");
        scanf("%d", &fichaAJugar);
        
        if (moverFicha(tablero, fichaAJugar)) {
            movimientos++; 
        } else {
            printf("\n¡Movimiento invalido! El numero debe estar junto al espacio vacio.\n");
            printf("Presione Enter para continuar...");
            getchar(); 
        }
    }
    
    mostrarTablero(tablero);
    printf("\n=========================================\n");
    printf("¡FELICIDADES! Ordenaste el rompecabezas.\n");
    printf("Te tomo %d movimientos en total.\n", movimientos);
    printf("=========================================\n");
    
    return 0;
}

void mostrarTablero(int matriz[][3]) {
  int i, j;
  
  system("cls");
  system("clear");
    printf("\n\t ROMPECABEZAS DE 8\n\n");
    
    for(i = 0; i < 3; i++) {
        printf("\t");
        for(j = 0; j < 3; j++) {
            if(matriz[i][j] == 0) {
                printf("[   ] "); 
            } else {
                printf("[ %d ] ", matriz[i][j]);
            }
        }
        printf("\n\n");
    }
}

int verificarGanador(int matriz[][3]) {
    int i, j;
    int contador = 1; 
    
    for(i = 0; i < 3; i++) {
        for(j = 0; j < 3; j++) {
            
            if(i == 2 && j == 2) {
                if(matriz[i][j] != 0) return 0; 
            } else {
                if(matriz[i][j] != contador) return 0;
                contador++;
            }
        }
    }
    return 1; 
}

int moverFicha(int matriz[][3], int ficha) {
    int i, j;
    int f_vacio = -1, c_vacio = -1;
    int f_ficha = -1, c_ficha = -1;
    
    
    if (ficha < 1 || ficha > 8) return 0;

    for(i = 0; i < 3; i++) {
        for(j = 0; j < 3; j++) {
            if(matriz[i][j] == 0) {
                f_vacio = i;
                c_vacio = j;
            }
            if(matriz[i][j] == ficha) {
                f_ficha = i;
                c_ficha = j;
            }
        }
    }

    
    
    
    if ((f_ficha == f_vacio && abs(c_ficha - c_vacio) == 1) || 
        (c_ficha == c_vacio && abs(f_ficha - f_vacio) == 1)) {
        
        
        matriz[f_vacio][c_vacio] = ficha;
        matriz[f_ficha][c_ficha] = 0;
        
        return 1; 
    }

    return 0; 
}