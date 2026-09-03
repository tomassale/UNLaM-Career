/************************************************************************************************************************
 Desarrolle un programa que solicite el ingreso de un numero entero, que indica a su vez cuantos números enteros
ingresara el usuario. Crear en memoria dinámica el vector para almacenar el tamaño exacto de los datos y leer los
enteros que serán guardados en el vector “dinámico”. Informar el promedio de los datos ingresados.
************************************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>

int main(){
    int *vec;
    int ingresos, i, acum = 0;
    float prom;

    do{
        printf("Ingrese la cantidad de datos a almacenar: ");
        scanf("%d", &ingresos);
    }while(ingresos <= 0);

    vec = (int*)calloc(ingresos, sizeof(int));

    if(vec == NULL){
        printf("Error al asignar memoria...");
        exit(1);
    }

    for(i = 0; i < ingresos; i++){
        printf("Ingrese el numero: ");
        scanf("%d", vec+i);
        acum += *(vec+i);
    }

    prom =(float) acum / ingresos;

    for(i = 0; i < ingresos; i++){
        printf("\nNumeros ingresados: %d", *(vec+i));
    }
    printf("\nEl promedio de los numeros es: %.2f", prom);

    free(vec);
    return 0;
}
