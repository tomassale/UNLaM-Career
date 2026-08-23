/**************************************************************************************************
Se dispone de un archivo con nombre Llamadas.dat que contiene llamadas telefónicas realizadas
en una empresa. Por cada llamada se dispone de la siguiente información:
  • Sector (15 caracteres máximo)
  • Duración en segundos (entero)
  • Tipo de llamada (entero: 1 local, 2 larga distancia, 3 celular)
El archivo se encuentra organizado por Sector. Se solicita:
  a. Calcular y mostrar por cada sector, la cantidad de llamadas realizadas de cada tipo.
  b. Determinar cuál es el sector que habló la mayor cantidad de tiempo.
  c. En un archivo llamado costos.dat hay un único registro que contiene los costos por
  segundo de los tres tipos de llamadas (3 float). Se debe generar el archivo gastos.dat que
  totalice los gastos de llamadas de cada sector.
  d. Realizar una función que muestre los datos almacenados en gastos.dat en forma de listado.
  e. Generar un archivo para cada sector con el detalle de llamadas valorizado. El archivo se debe
  generar con nombresector.dat y debe contener:
    • Duración en segundos (entero)
    • Tipo de llamada (entero)
    • Costo de la llamada (float)
**************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char sector[16];
    int duracion;
    int tipo;
} Llamada;

typedef struct {
    float costoLocal;
    float costoDistancia;
    float costoCelular;
} Costos;

typedef struct {
    char sector[16];
    float gastosTotales;
} Gastos;

typedef struct {
    int duracion;
    int tipo;
    float costo;
} Sector;

void procesarLlamadas(FILE *pf, FILE *pfC, FILE *pfG);
void mostrarListadoGastos(FILE *pfG);

int main() {
    FILE *pf, *pfC, *pfG;

    pf = fopen("Llamadas.dat", "rb");
    pfC = fopen("costos.dat", "rb");
    pfG = fopen("gastos.dat", "wb");

    if (pf == NULL || pfC == NULL || pfG == NULL) {
        printf("Error al abrir los archivos principales.\n");
        exit(1);
    }

    procesarLlamadas(pf, pfC, pfG);

    fclose(pfG);

    pfG = fopen("gastos.dat", "rb");
    if (pfG != NULL) {
        mostrarListadoGastos(pfG);
        fclose(pfG);
    }

    fclose(pf);
    fclose(pfC);

    return 0;
}

void procesarLlamadas(FILE *pf, FILE *pfC, FILE *pfG) {
    Llamada ll;
    Costos costos;
    Gastos gt;
    Sector detalleSector;

    char sectorActual[16];
    char sectorMaxTiempo[16];
    int maxTiempo = -1;

    int contLocal, contDistancia, contCelular;
    int tiempoSector;
    float gastoSector;
    float costoActual;

    FILE *pfS;
    char nombreArchivoSector[25];

    fread(&costos, sizeof(Costos), 1, pfC);

    fread(&ll, sizeof(Llamada), 1, pf);

    printf("--- INFORME DE LLAMADAS POR SECTOR ---\n");

    while (!feof(pf)) {
        strcpy(sectorActual, ll.sector);

        contLocal = 0;
        contDistancia = 0;
        contCelular = 0;
        tiempoSector = 0;
        gastoSector = 0;

        strcpy(nombreArchivoSector, sectorActual);
        strcat(nombreArchivoSector, ".dat");
        pfS = fopen(nombreArchivoSector, "wb");

        while (!feof(pf) && strcmp(sectorActual, ll.sector) == 0) {

            if (ll.tipo == 1) contLocal++;
            else if (ll.tipo == 2) contDistancia++;
            else if (ll.tipo == 3) contCelular++;

            tiempoSector += ll.duracion;

            if (ll.tipo == 1) costoActual = ll.duracion * costos.costoLocal;
            else if (ll.tipo == 2) costoActual = ll.duracion * costos.costoDistancia;
            else if (ll.tipo == 3) costoActual = ll.duracion * costos.costoCelular;

            gastoSector += costoActual;

            if (pfS != NULL) {
                detalleSector.duracion = ll.duracion;
                detalleSector.tipo = ll.tipo;
                detalleSector.costo = costoActual;
                fwrite(&detalleSector, sizeof(Sector), 1, pfS);
            }

            fread(&ll, sizeof(Llamada), 1, pf);
        }

        if (pfS != NULL) {
            fclose(pfS);
        }


        printf("Sector: %-15s | Locales: %d | Larga Dist: %d | Celular: %d\n",
               sectorActual, contLocal, contDistancia, contCelular);

        strcpy(gt.sector, sectorActual);
        gt.gastosTotales = gastoSector;
        fwrite(&gt, sizeof(Gastos), 1, pfG);

        if (tiempoSector > maxTiempo) {
            maxTiempo = tiempoSector;
            strcpy(sectorMaxTiempo, sectorActual);
        }
    }

    if (maxTiempo != -1) {
        printf("\n=> El sector con mayor tiempo de llamadas fue: %s (%d seg)\n",
               sectorMaxTiempo, maxTiempo);
    }
}

void mostrarListadoGastos(FILE *pfG) {
    Gastos gt;

    printf("\nLISTADO DE GASTOS TOTALES\n");
    fread(&gt, sizeof(Gastos), 1, pfG);
    while (!feof(pfG)) {
        printf("Sector: %-15s | Gastos Totales: $%8.2f\n", gt.sector, gt.gastosTotales);
        fread(&gt, sizeof(Gastos), 1, pfG);
    }
    printf("---------------------------------\n");
}



