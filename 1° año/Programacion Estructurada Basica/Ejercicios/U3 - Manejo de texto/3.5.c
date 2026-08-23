/************************************************************************************************************************
 Una empresa de alquiler de autos tiene una flota de 30 autos de alta gama, identificados por su número de
patente, cargado en la memoria principal en un vector de 30 posiciones. Al comenzar el procesamiento de
los alquileres, se ingresa la fecha y la cotización del dólar de ese día. A continuación, se ingresan los
siguientes datos correspondiente a cada alquiler realizado en el día:
  • Patente del auto (alfanumérico, de 6 caracteres)
  • Cantidad de días de alquiler (entero, mayor que 0)
  • Precio diario del alquiles en dólares (real, mayor que 0)
Para finalizar la carga del día, se ingresa una patente de auto igual a “FINDIA”
Determinar e informar:
  a. El porcentaje de autos alquilados durante el día.
  b. Realizar el informe con el formato siguiente:
                                      VER FORMATO EN ARCHIVO
************************************************************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void acomodarPalabra(char[]);
void cargaAutos(char[][8], int);
void cargaAlquileres(char[][8], int[], float[], int);
int buscaCodigo(char[][8], char[], int);
int validacionEnteroPositivo();
float validacionFloatPositivo();
float calcularPorcentaje(int[], int);
void mostrarInforme(char[][8], int[], float[], int, char[], float);

int main() {
    char patentes[30][8] = {{'\0'}};
    int diasAlquiler[30] = {0};
    float precios[30] = {0};
    char fecha[15];
    float cotizacionDolar;
    float porcentaje;

    cargaAutos(patentes, 30);

    printf("--- SISTEMA DE ALQUILER DE AUTOS ---\n");
    printf("Ingrese la fecha de hoy (dd-mm-aaaa): ");
    fgets(fecha, 15, stdin);
    getchar();
    acomodarPalabra(fecha);

    printf("Ingrese la cotizacion del dolar del dia: ");
    cotizacionDolar = validacionFloatPositivo();

    cargaAlquileres(patentes, diasAlquiler, precios, 30);

    porcentaje = calcularPorcentaje(diasAlquiler, 30);

    mostrarInforme(patentes, diasAlquiler, precios, 30, fecha, cotizacionDolar);
    printf("\na. El porcentaje de autos alquilados hoy es: %.2f%%\n\n", porcentaje);

    return 0;
}

void acomodarPalabra(char texto[]) {
    int ultimo = strlen(texto) - 1;
    if (texto[ultimo] == '\n') texto[ultimo] = '\0';
}

void cargaAutos(char patentes[][8], int ce) {
    int i, ultimo, pos;
    char patente[8];

    for (i = 0; i < ce; i++) {
        do{
            printf("Ingrese la patente del auto (%d de %d): ", i+1, ce);
            fgets(patente, 8, stdin);
            ultimo = strlen(patente) -1;
            if(patente[ultimo] == '\n') patente[ultimo] == '\0';
            pos = buscaCodigo(patentes, patente, i);
        }while(pos != -1);
        strcpy(patentes[i], patente);
    }
    printf("[i] Flota de %d autos cargada en memoria correctamente.\n", ce);
}

int buscaCodigo(char patentes[][8], char cod[], int ce) {
  int pos = -1, i = 0;

  while(pos == -1 && i < ce) {
      if (strcmp(patentes[i], cod) == 0)
        pos = i;
      else
        i++;
  }
  if(pos != -1) printf("Patente ya ingresada, intente nuevamente.\n");
  return pos;
}

int validacionEnteroPositivo() {
    int num;
    do {
        scanf("%d", &num);
        if (num <= 0) printf("Error: Debe ser mayor a 0. Intente nuevamente: ");
    } while (num <= 0);
    getchar();
    return num;
}

float validacionFloatPositivo() {
    float num;
    do {
        scanf("%f", &num);
        if (num <= 0) printf("Error: Debe ser mayor a 0. Intente nuevamente: ");
    } while (num <= 0);
    getchar();
    return num;
}

void cargaAlquileres(char patentes[][8], int dias[], float precios[], int ce) {
    char patente[8];
    int pos;

    printf("\n--- INGRESO DE ALQUILERES ---\n");
    while (strcmp(patente, "FINDIA") != 0) {
        printf("Ingrese la patente alquilada (o 'FINDIA' para terminar): ");
        fgets(patente, 8, stdin);
        acomodarPalabra(patente);

        pos = buscaCodigo(patentes, patente, ce);

        if (pos != -1) {
            printf("Ingrese la cantidad de dias de alquiler: ");
            dias[pos] += validacionEnteroPositivo();

            printf("Ingrese el precio diario en dolares: ");
            precios[pos] = validacionFloatPositivo();
            printf("-> Alquiler registrado con exito.\n\n");
        } else {
            printf("-> Error: La patente '%s' no pertenece a la flota.\n\n", patente);
        }
    }
}

float calcularPorcentaje(int dias[], int ce) {
    int cantidadAlquilados = 0, i;
    float porcentaje;

    for (i = 0; i < ce; i++) {
        if (dias[i] > 0) {
            cantidadAlquilados++;
        }
    }

    porcentaje = (float) cantidadAlquilados * 100 / ce;
    return porcentaje;
}

void mostrarInforme(char patentes[][8], int dias[], float precios[], int ce, char fecha[], float dolar) {
    float totalUSD, totalARS;
    int i;

    system("cls");
    system("clear");

    printf("\n=========================================================================\n");
    printf("                       INFORME DE ALQUILERES DEL DIA                     \n");
    printf("=========================================================================\n");
    printf("Fecha de proceso: %s \t\t Cotizacion del Dolar: $%.2f\n", fecha, dolar);
    printf("-------------------------------------------------------------------------\n");
    printf("%-10s | %-6s | %-13s | %-12s | %-12s\n", "PATENTE", "DIAS", "PRECIO/DIA", "TOTAL (U$S)", "TOTAL ($)");
    printf("-------------------------------------------------------------------------\n");

    for (i = 0; i < ce; i++) {
        if (dias[i] > 0) {
            totalUSD = dias[i] * precios[i];
            totalARS = totalUSD * dolar;
            printf("%-10s | %-6d | u$s %-9.2f | u$s %-8.2f | $ %-9.2f\n",
                   patentes[i], dias[i], precios[i], totalUSD, totalARS);
        }
    }
    printf("=========================================================================\n");
}
