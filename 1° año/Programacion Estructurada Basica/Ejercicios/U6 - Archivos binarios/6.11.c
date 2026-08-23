/************************************************************************************************************************
Se dispone de un archivo llamado Rating.dat que guarda la información de los puntos obtenidos de rating
en los distintos programas de canales de cable a lo largo del día. Cada registro contiene:
  • Número de canal (entero)
  • Programa (texto de 35 caracteres máximo)
  • Rating (float)
El archivo se encuentra ordenado por canal.
Se solicita informar:
  a. Aquellos canales que obtengan menos de 15 puntos en total.
  b. El canal más visto.
  c. Generar un archivo con el promedio de rating de cada canal que incluya dos campos:
    • Número de canal.
    • Promedio.
************************************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int canal;
    char programa[36];
    float rating;
}Canal;

typedef struct{
    int canal;
    float promedio;
}Promedio;

void mostrarArchivo(FILE *pf);
void mostrarPromedio(FILE *pfP);
void corteControl(FILE *pf, FILE *pfP);
void generarArchivo(FILE *pfP, int, float);

int main(){
    FILE *pf, *pfP;

    pf = fopen("RATING.dat", "rb");
    pfP = fopen("PROMEDIO.dat", "w+b");

    if(pf == NULL || pfP == NULL){
        printf("Error al abrir el archivo...");
        exit(1);
    }

    mostrarArchivo(pf);
    corteControl(pf, pfP);
    mostrarPromedio(pfP);

    fclose(pf);
    fclose(pfP);
    return 0;
}


void corteControl(FILE *pf, FILE *pfP){
    Canal cn;
    int canalAnterior, canalMayor, contCanales = 0;
    float acumVistas = 0, mayorVistas = 0, promedio;

    rewind(pf);
    fread(&cn, sizeof(Canal), 1, pf);
    while(!feof(pf)){
        acumVistas = 0;
        promedio = 0;
        contCanales = 0;
        canalAnterior = cn.canal;
        while(canalAnterior == cn.canal && !feof(pf)){
            acumVistas += cn.rating;
            contCanales++;
            fread(&cn, sizeof(Canal), 1, pf);
        }

        promedio = (float) acumVistas / contCanales;

        if(acumVistas > mayorVistas){
            mayorVistas = acumVistas;
            canalMayor = canalAnterior;
        }
        if(acumVistas < 15)
            printf("\nEl canal %d tiene menos de 15 vistas.", canalAnterior);

        generarArchivo(pfP, canalAnterior, promedio);
    }
    printf("\nEl canal con mas vistas es el %d con %.0f vistas.", canalMayor, mayorVistas);
}



void generarArchivo(FILE *pfP, int canal, float promedio){
    Promedio pr;

    pr.canal = canal;
    pr.promedio = promedio;
    fwrite(&pr, sizeof(Promedio), 1, pfP);
    fflush(pfP);
}

void mostrarPromedio(FILE *pfP){
    Promedio pr;

    rewind(pfP);
    printf("\nArchivo de Promedios\n");
    fread(&pr, sizeof(Promedio), 1, pfP);
    while(!feof(pfP)){
        printf("\nCanal: %2d | Promedio rating: %10.2f", pr.canal, pr.promedio);
        fread(&pr, sizeof(Promedio), 1, pfP);
    }
}

void mostrarArchivo(FILE *pf){
    Canal cn;

    rewind(pf);
    printf("\nArchivo de programas\n");
    fread(&cn, sizeof(Canal), 1, pf);
    while(!feof(pf)){
        printf("\nCanal: %2d | Programa: %25s | Rating: %10.2f", cn.canal, cn.programa, cn.rating);
        fread(&cn, sizeof(Canal), 1, pf);
    }
}

