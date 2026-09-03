/************************************************************************************************************************
Dado un vector de 10 enteros, ingresar un entero por teclado, buscarlo y, si se lo encuentra, generar un nuevo
vector con los índices correspondientes a las ubicaciones en el primer vector del entero ingresado. 
************************************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void ingresoDatos(int[], int);
void ingresoAleatorio(int[], int, int, int);
void ingresoBusqueda(int[], int[], int);
void mostrarVector(int[], int);
int buscarNumero(int[], int, int);

int main(){
    int num[10] = {0};
    int indices[10] = {0};

    srand(time(NULL));

    //ingresoAleatorio(num, 10, 1, 10);
    ingresoDatos(num, 10);
    mostrarVector(num, 10);
    ingresoBusqueda(num, indices, 10);

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
        printf("Ingrese el dato (%d de %d): ", i+1, 10);
        scanf("%d", &num);
        vec[i] = num;
    }
}

void ingresoBusqueda(int num[], int ind[], int ce){
    int i = 0, encontrados = 0, pos;

    while(encontrado != 10){
        do{
            printf("Ingrese el numero a buscar: ");
            scanf("%d", &numBuscar);
            pos = buscarNumero(num, numBuscar, 10);
        }while(pos == -1);
        encontrados++;
        ind[pos] = pos;
        mostrarVector(ind, 10);
    }
}

void mostrarVector(int vec[], int ce){
    int i;

    printf("\nVECTOR\n");
    printf("[");
    for(i = 0; i < ce; i++){
        printf("%d, ", vec[i]);
    }
    printf("]");
}

int buscarNumero(int vec[], int num, int ce){
    int i = 0, pos = -1;

    while(pos == -1 && i < ce){
        if(vec[i] == num)
            pos = i;
        else
            i++;
    }

    return pos;
}

