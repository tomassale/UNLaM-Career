/************************************************************************************************************************
Dada la siguiente estructura:
    typedef struct
    {
      int codigo;
      char descripcion[31];
      float precio;
    }sProductos
  a. Crear una variable del tipo sProductos
  b. Ingresar por teclado los campos
  c. Crear un puntero a dicha estructura
  d. Mostrar los datos ingresados mediante el puntero utilizando las dos nomenclaturas posibles

************************************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int codigo;
    char descripcion[31];
    float precio;
}sProductos;

int main(){
    //Punto a
    sProductos prod;
    int medida;

    //Punto b
    printf("Ingrese el codigo: ");
    scanf("%d", &prod.codigo);
    getchar();
    printf("Ingrese la descripcion: ");
    fgets(prod.descripcion, 31, stdin);
    medida = strlen(prod.descripcion);
    if(prod.descripcion[medida-1] == '\n')
        prod.descripcion[medida-1] = '\0';
    printf("Ingrese el precio: ");
    scanf("%f", &prod.precio);

    //Punto c
    sProductos *ptr = &prod;

    //Punto d
    printf("\nNomenclatura con flecha\n");
    printf("Codigo: %d\n", ptr->codigo);
    printf("Descripcion: %s\n", ptr->descripcion);
    printf("Precio: %.2f\n", ptr->precio);


    printf("\nAsterisco y punto\n");
    printf("Codigo: %d\n", (*ptr).codigo);
    printf("Descripcion: %s\n", (*ptr).descripcion);
    printf("Precio: %.2f\n", (*ptr).precio);

    free(ptr);
    return 0;
}
