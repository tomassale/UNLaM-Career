/*************************************************************************************************************
Se ingresan los códigos de 15 productos de una empresa (números de 3 dígitos). Luego del ingreso se debe ordenar de
forma ascendente la colección con dichos códigos para permitir realizar búsquedas binarias.
Luego se ingresan las ventas realizadas durante el día. Por cada venta se ingresa código de vendedor, código
de artículo y cantidad.
Los vendedores son 5 y están codificados en forma correlativa de 1001 a 1005. Se puede recibir más de una
venta de un mismo vendedor y artículo. El ingreso de datos finaliza con código de vendedor igual a 0. Se desea:
  a. Mostrar un listado ordenado de mayor a menor por cantidad de unidades vendidas de cada producto.
  b. Indicar el/los vendedores que realizaron menor cantidad de ventas (no de unidades).
**************************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void ingresoAleatorio(int[], int, int, int);
void ingresoDatos(int[], int);
void ingresoVentas(int[], int[], int[], int);
int validacionIngresoFinal(int, int, int);
int validacionIngreso(int, int);
int validacionRango(int);
void ordenarAscendente(int[], int);
void ordenarDescendente(int[], int[], int);
int busquedaBinaria(int[], int, int);
int minimo(int[], int);
void mostrarListado(int[], int[], int);
void mostrarMinimos(int[], int, int);

int main(){
  int codigos[15] = {0};
  int ventas[15] = {0};
  int ventasVendedor[5] = {0};
  int min;

  srand(time(NULL));

  //ingresoAleatorio(codigos, 15, 100, 999);
  ingresoDatos(codigos, 15);
  ordenarAscendente(codigos, 15);
  //ingresoAleatorio(ventas, 15, 1, 10);
  //ingresoAleatorio(ventasVendedor, 5, 1, 10);
  ingresoVentas(codigos, ventas, ventasVendedor, 15);
  ordenarDescendente(codigos, ventas, 15);
  min = minimo(ventasVendedor, 5);
  mostrarMinimos(ventasVendedor, 5, min);
  mostrarListado(codigos, ventas, 15);

  return 0;
}

void ingresoAleatorio(int vec[], int ce, int min, int max){
    int i;

    for(i = 0; i < ce; i++){
        vec[i]= (rand() % (max - min + 1)) + min;
    }
}

void ingresoDatos(int vec[], int ce){
    int i, num;

    for(i = 0; i < ce; i++){
        printf("Ingrese el numero (%d de %d): ", i+1, ce);
        num = validacionIngreso(100, 999);
        vec[i] = num;
    }
}

int busquedaBinaria(int vec[], int ce, int num){
    int pos = -1, li = 0, ls = ce-1, med;

    while(pos == -1 && li <= ls){
        med = (li+ls)/2;
        if(vec[med] == num)
            pos = med;
        else
            if(num > vec[med])
                li = med + 1;
            else
                ls = med - 1;
    }

    return pos;
}

void ingresoVentas(int cod[], int vent[], int vend[], int ce){
    int codigo, ventas, vendedor, pos;

    printf("Ingrese el codigo de vendedor (%d a %d): ", 1001, 1005);
    vendedor = validacionIngresoFinal(1001, 1005, 0);
    while(vendedor != 0){
        do{
            printf("Ingrese el codigo de producto (3 digitos): ");
            codigo = validacionIngreso(100, 999);
            pos = busquedaBinaria(cod, ce, codigo);
        }while(pos == -1);
        printf("Ingrese la cantidad de ventas (mayor a 0): ");
        ventas = validacionRango(0);

        vent[pos] += ventas;
        vend[vendedor-1001]++;

        printf("Ingrese el codigo de vendedor (%d a %d): ", 1001, 1005);
        vendedor = validacionIngresoFinal(1001, 1005, 0);
    }
}

int validacionIngresoFinal(int min, int max, int fin){
    int num;

    do{
        scanf("%d", &num);
    }while((num < min || num > max) && num != fin);

    return num;
}

int validacionIngreso(int min, int max){
    int num;

    do{
        scanf("%d", &num);
    }while(num < min || num > max);

    return num;
}

int validacionRango(int min){
    int num;
    do{
        scanf("%d", &num);
    }while(num < min);

    return num;
}

void ordenarAscendente(int vec[], int ce){
    int i, aux, cota = ce-1;
    int desordenado = 1;

    while(desordenado){
        desordenado = 0;
        for(i = 0; i < cota; i++){
            if(vec[i] > vec[i+1]){
                aux = vec[i];
                vec[i] = vec[i+1];
                vec[i+1] = aux;
                desordenado = i;
            }
        }
        cota = desordenado;
    }
}

void ordenarDescendente(int cod[], int vent[], int ce){
    int i, aux, cota = ce-1;
    int desordenado = 1;

    while(desordenado){
        desordenado = 0;
        for(i = 0; i < cota; i++){
            if(vent[i] < vent[i+1]){
                aux = vent[i];
                vent[i] = vent[i+1];
                vent[i+1] = aux;

                aux = cod[i];
                cod[i] = cod[i+1];
                cod[i+1] = aux;
                desordenado = i;
            }
        }
        cota = desordenado;
    }
}

int minimo(int vec[], int ce){
    int i, min = vec[0];

    for(i = 0; i < ce; i++){
        if(min > vec[i])
            min = vec[i];
    }

    return min;
}

void mostrarMinimos(int vec[], int ce, int min){
    int i;

    for(i = 0; i < ce; i++){
        if(vec[i] == min)
            printf("\nEl vendedor con menos ventas es el %d con %d ventas.", i+1001, min);
    }
}

void mostrarListado(int cod[], int vent[], int ce){
    int i;

    printf("\n\t\tVECTOR MAYOR A MENOR VENTAS\n");
    for(i = 0; i < ce; i++){
        printf("Codigo: %2d - Ventas: %2d\n", cod[i], vent[i]);
    }
}