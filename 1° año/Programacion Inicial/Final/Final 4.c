/****************************************************************************************************************************
El Teatro Colón de Buenos Aires puso en preventa anticipada las localidades de los espectáculos de la temporada 2025.
Para ello, en una primera instancia se ingresan los siguientes datos de las casi 180 funciones a realizar durante la temporada:

    * Código del espectáculo (entero, mayor a cero)
    * Cantidad de entradas a la venta (entero, entre 1 y 2478 que es la capacidad máxima por función)
    * Precio de la entrada (real, mayor a cero)

El ingreso de estos datos finaliza con un código de espectáculo igual a cero.

A continuación, por cada venta, se piden los siguientes datos:

    * DNI del comprador (entero, entre 1 y 99999999)
    * Código del Concierto (entero, mayor a cero)
    * Cantidad de entradas vendidas (entero, entre 1 y 20)
    * Tipo de espectáculo (carácter, ‘O’: Ópera; ‘C’: Concierto; ‘B’: Ballet; ‘E’: Espectáculos especiales)

La carga finaliza con un DNI de comprador igual a 0.

Se debe tener en cuenta, que en ningún caso la cantidad de entradas vendida para un concierto puede superar la 
capacidad máxima de espectadores sentados, de ser así, rechazar la operación de venta.
Si el espectáculo vendido no se encuentra entre los ofrecidos en el primer lote de datos, informar los datos de 
la venta junto con la leyenda “operación rechazada” y continuar con la siguiente venta.

Se pide:

    a) Al finalizar la preventa de entradas, listar el código de espectáculo, la cantidad de entradas vendidas 
    y el importe recaudado de cada uno (realizar con FUNCIÓN).
    b) Informar el porcentaje de ventas realizadas (en cantidad) por cada tipo de espectáculo.
    c) Mostrar el concierto que tuvo más recaudación que el promedio de importe vendido de los espectáculos. Si 
    hay más de uno, mostrarlos a todos (realizar con FUNCIÓN).
*****************************************************************************************************************************/

#include <stdio.h>
#include <ctype.h>

int buscarEspectaculo(int, int, int[]);
void listarEspectaculo(int, int[], int[], float[]);
void mayorPromedio(int, float, int[], float[]);

int main(){
    int codigosEspectaculo[180] = {0};
    int entradasEspectaculo[180] = {0};
    float precioEntrada[180] = {0};
    int entradasVendidas[180] = {0};
    float recaudacionEspectaculo[180] = {0};

    int ingresos = 0, codigo = -1, entradas, codigoBuscar;
    int dni = -1, pos = -1, entradasV, acumO = 0, acumC = 0, acumB = 0, acumE = 0, acumTotalVentas = 0;
    float precio, promedio;
    char tipoEspectaculo;

    while(codigo != 0 && ingresos < 180){
        do{
            printf("Ingrese el codigo del espectaculo (mayor a 0 y 0 para finalizar): ");
            scanf("%d", &codigo);
        }while(codigo < 0);

        if(codigo != 0){
            do{
                printf("Ingrese la cantidad de entradas (1 a 2478): ");
                scanf("%d", &entradas);
            }while(entradas < 1 || entradas > 2478);

            do{
                printf("Ingrese el precio de cada entrada (mayor a 0): ");
                scanf("%f", &precio);
            }while(precio < 1);

            codigosEspectaculo[ingresos] = codigo;
            entradasEspectaculo[ingresos] = entradas;
            precioEntrada[ingresos] = precio;

            ingresos++;
        }
    }


    while(dni != 0){
        do{
            printf("Ingrese el documento: ");
            scanf("%d", &dni);
        }while(dni < 0 || dni > 99999999);

        if(dni != 0){
            do{
                printf("Ingrese el codigo del espectaculo: ");
                scanf("%d", &codigoBuscar);
            }while(codigoBuscar < 1);

            pos = buscarEspectaculo(ingresos, codigoBuscar, codigosEspectaculo);

            if(pos != -1 && entradasEspectaculo[pos] > 0){
            
                do{
                    printf("Cuantas entradas quiere comprar (max %d): ", entradasEspectaculo[pos]);
                    scanf("%d", &entradasV);
                    if(entradasV > entradasEspectaculo[pos])
                        printf("\nOperacion rechazada");
                }while(entradasV < 1 || entradasV > 20 || entradasV > entradasEspectaculo[pos]);

                do{
                    printf("Ingrese que tipo de espectaculo es: ");
                    scanf(" %c", &tipoEspectaculo);
                    tipoEspectaculo = toupper(tipoEspectaculo);
                }while(tipoEspectaculo != 'O' && tipoEspectaculo != 'C' && tipoEspectaculo != 'B' && tipoEspectaculo != 'E');

                switch(tipoEspectaculo){
                    case 'O': acumO+=precioEntrada[pos] * entradasV; break;
                    case 'C': acumC+=entradasV; break;
                    case 'B': acumB+=entradasV; break;
                    case 'E': acumE+=entradasV; break;
                }
                entradasVendidas[pos] += entradasV;
                entradasEspectaculo[pos] -= entradasV;
                recaudacionEspectaculo[pos] += entradasV * precioEntrada[pos];
                acumTotalVentas += precioEntrada[pos] * entradasV;
            }else{
                printf("\nCodigo no encontrado o no quedan mas entradas");
            }
        }else{
            printf("\nIngreso finalizado");
        }
    }

    if(ingresos != 0){
        promedio = (float) acumTotalVentas / ingresos;
    }else{
        printf("\nNo hubieron ingresos, no hay promedio");
    }

    listarEspectaculo(ingresos, codigosEspectaculo, entradasVendidas, recaudacionEspectaculo);

    printf("\nESPECTACULO PORCENTAJE\n");
    printf("\nO %.2f", (float) (acumO * 100) / acumTotalVentas);
    printf("\nC %.2f", (float) (acumC * 100) / acumTotalVentas);
    printf("\nB %.2f", (float) (acumB * 100) / acumTotalVentas);
    printf("\nE %.2f", (float) (acumE * 100) / acumTotalVentas);

    mayorPromedio(ingresos, promedio, codigosEspectaculo, recaudacionEspectaculo);

    return 0;
}

int buscarEspectaculo(int ingresos, int codigo, int codigos[]){
    int i = 0, band = 0;

    while(band != 1 && i < ingresos){
        if(codigos[i] == codigo){
            band = 1;
        }else{
            i++;
        }
    }
    
    if(band == 0){
        i = -1;
    }

    return i;
}

void listarEspectaculo(int ingresos, int codigos[], int ventas[], float recaudacion[]){
    int i;

    printf("\nCODIGOS VENTAS RECAUDACION\n");
    for(i = 0; i < ingresos; i++){
        printf("\n%d %d %.2f", codigos[i], ventas[i], recaudacion[i]);
    }
}

void mayorPromedio(int ingresos, float promedio, int codigosEspectaculo[], float recaudacion[]){
    int i;

    for(i = 0; i < ingresos; i++){
        if(recaudacion[i] > promedio) 
            printf("\nLa recaudacion de %d supera el promedio (%.2f)", codigosEspectaculo[i], recaudacion[i]);
    }
}