/************************************************************************************************************************
Dado un conjunto de 10 números enteros ordenados de menor a mayor, ingresar por teclado 3 números más
no ordenados. Insertarlos donde correspondan. Mostrar en pantalla la serie inicial y la final.
************************************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void ingresoAleatorio(int[], int, int, int);
void ingresoDatos(int[], int);
void ordenarListado(int[], int);
void mostrarResultado(int[], int);

int main(){
    int numeros[13] = {0};

    srand(time(NULL));

    //ingresoAleatorio(numeros, 10, 1, 15);
    ingresoDatos(numeros, 10);
    ordenarListado(numeros, 10);
    mostrarResultado(numeros, 10);
    //ingresoAleatorio(numeros, 3, 1, 15);
    ingresoDatos(numeros, 3);
    ordenarListado(numeros, 13);
    mostrarResultado(numeros, 13);

    return 0;
}

void ingresoAleatorio(int vec[], int ce, int min, int max){
    int i;

    for(i = 0; i < ce; i++){
        vec[i] = (rand() % max) + min;
    }
}

void ingresoDatos(int vec[], int ce){

    int i, num;
    for(i = 0; i < ce; i++){
        printf("Ingrese los datos para el vector (ordenados)(%d de %d): ", i+1, ce);
        scanf("%d", &num);
        vec[i] = num;
    }
}

void ordenarListado(int vec[], int ce){
    int i, aux, cota = ce-1;
    int desordenado = 1;.

    while(desordenado){
        desordenado = 0;
        for(i=0; i < cota; i++){
            if(vec[i] > vec[i+1]){
                aux = vec[i];
                vec[i+1] = vec[i];
                vec[i] = aux;
            }
            desordenado = i;
        }
        cota = desordenado;
    }
}

void mostrarResultado(int vec[], int ce){
    int i;

    printf("\nVECTOR IMPRESO: [");
    for(i = 0; i < ce; i++){
        printf("%d, ", vec[i]);
    }
    printf("]\n");
}