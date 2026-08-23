/**************************************************************************************************************************************
Una cadena de 10 tiendas de electrónica necesita un sistema para gestionar su inventario de celulares y registrar sus ventas diarias. 

Al inicio del programa, se carga la siguiente información para cada una de las 10 tiendas:
    * ID de Tienda (entero no correlativo, mayor a cero).
    * Capacidad Máxima de Almacenamiento (entero, mayor a cero).
    * Stock Inicial de celulares: (entero, mayor o igual a cero).

Durante el día, se registran las transacciones de ventas. Por cada venta realizada, se ingresa el siguiente detalle:
    * ID de Tienda
    * Categoría del Producto Vendido (entero, entre 1 y 9)
    * Cantidad de Unidades Vendidas (entero, mayor a cero)
La carga de ventas finaliza cuando se ingresa un ID de tienda igual a cero.

Se requiere que el programa realice lo siguiente: 
    1. Mostrar la cantidad total de unidades vendidas para cada una de las 9 categorías de celulares a nivel de toda la cadena. FUNCIÓN
    2. Mostrar el ID de la Tienda y el stock actualizado de celulares de cada tienda. FUNCIÓN
    3. Identificar y listar los IDs de las tiendas que hayan vendido la menor cantidad total de celulares (puede haber más de una con la misma cantidad mínima). FUNCIÓN
    4. Calcular y mostrar el promedio de unidades vendidas por tienda en toda la cadena.
**************************************************************************************************************************************************************/

#include <stdio.h>

void unidadesVendidas(int[]);
void mostrarStock(int[], int[]);
void identificarMinimo(int[], int[]);
int buscarCodigo(int, int[]);

int main(){
    int idTienda[10] = {0};
    int capacidadMaxima[10] = {0};
    int stock[10] = {0};
    int unidadesVentas[9] = {0};
    int ventasTienda[10] = {0};

    int i, id, capacidad, stockInicial;
    int uniVendida, pos, idEncontrar, categoria, acumVentas = 0;
    float promedio = 0;

    for(i = 0; i<10; i++){
        do{
            printf("Ingrese el id de la tienda: ");
            scanf("%d", &id);
        }while(id <= 0);
        do{
            printf("Ingrese la capacidad maxima de almacenamiento: ");
            scanf("%d", &capacidad);
        }while(capacidad <= 0);
        do{
            printf("Ingrese el stock inicial de celulares: ");
            scanf("%d", &stockInicial);
        }while(stockInicial < 0);

        idTienda[i] = id;
        capacidadMaxima[i] = capacidad;
        stock[i] = stockInicial;
    }

    printf("Ingrese el codigo a buscar: ");
    scanf("%d", &idEncontrar);

    while(idEncontrar != 0){
        pos = buscarCodigo(idEncontrar, idTienda);
        if(pos != -1){
            do{
                printf("Ingrese la categoria: ");
                scanf("%d", &categoria);
            }while(categoria < 1 || categoria > 9);
            
            do{
                printf("Ingrese las unidades vendidas (no mayor al stock %d): ", stock[pos]);
                scanf("%d", &uniVendida);
            }while(uniVendida <= 0 || uniVendida > stock[pos]);

            unidadesVentas[categoria-1] += uniVendida;
            ventasTienda[pos] += uniVendida;
            stock[pos] -= uniVendida;
        }else{
            printf("Codigo no encontrado\n");
        }
        printf("Ingrese el codigo a buscar: ");
        scanf("%d", &idEncontrar);
    }

    unidadesVendidas(unidadesVentas);
    mostrarStock(idTienda, stock);
    identificarMinimo(idTienda, ventasTienda);

    for(i = 0; i < 10; i++){
        acumVentas += ventasTienda[i];
    }
    promedio = (float) acumVentas / 10;
    printf("\nEl promedio de ventas es de %.2f\n", promedio);

    return 0;
}

//1. Mostrar la cantidad total de unidades vendidas para cada una de las 9 categorías de celulares a nivel de toda la cadena. FUNCIÓN
void unidadesVendidas(int ventas[]){
    int i;
    
    printf("\nCATEGORIA VENTAS\n");
    for(i = 0; i < 9; i++){
        printf("%d %d\n", i+1, ventas[i]);
    }
}

//2. Mostrar el ID de la Tienda y el stock actualizado de celulares de cada tienda. FUNCIÓN
void mostrarStock(int ids[], int stock[]){
    int i;

    printf("\nID STOCK\n");
    for(i = 0; i < 10; i++){
        printf("%d %d\n", ids[i], stock[i]);
    }
}

//3. Identificar y listar los IDs de las tiendas que hayan vendido la menor cantidad total de celulares (puede haber más de una con la misma cantidad mínima). FUNCIÓN
void identificarMinimo(int ids[], int ventas[]){
    int i, menorVentas = ventas[0];

    for(i = 0; i < 10; i++){
        if(menorVentas > ventas[i]) menorVentas = ventas[i];
    }

    for(i = 0; i < 10; i++){
        if(ventas[i] == menorVentas)
            printf("Tienda %d con menor ventas (%d)\n", ids[i], menorVentas);
    }
}

int buscarCodigo(int codigo, int codigos[]){
    int i = 0, band = 0;

    while(band != 1 && i < 10){
        if(codigo == codigos[i]){
            band = 1;
        }else{
            i++;
        }
    }
    
    if(band == 0) 
        i = -1;

    return i;
}